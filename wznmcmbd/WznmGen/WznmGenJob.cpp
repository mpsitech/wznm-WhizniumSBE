/**
	* \file WznmGenJob.cpp
	* Wznm operation processor - generate job tree (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmGenJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmGen;

/******************************************************************************
 namespace WznmGenJob
 ******************************************************************************/

DpchRetWznm* WznmGenJob::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmGenJob* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	WznmMVersion* ver = NULL;
	bool hasdds, hasua;

	ubigint refLcl;
	vector<ubigint> refsLcl;

	ubigint refJobRoot;
	ubigint refJobSess;

	ListWznmMCard crds;
	WznmMCard* crd = NULL;

	ubigint refJobCrd;
	string crdroot;

	ubigint refJobPnlrec;

	ListWznmMDialog dlgs;
	WznmMDialog* dlg = NULL;

	ListWznmMPanel pnls;
	WznmMPanel* pnl = NULL;

	ListWznmMQuery qrys;
	WznmMQuery* qry = NULL;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	WznmMControl* con = NULL;

	ListWznmMImpexpcplx iexs;
	WznmMImpexpcplx* iex = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	ubigint refVecExpst = 0;
	ubigint refVitMind = 0;
	ubigint refVitRegd = 0;

	ubigint refVecReqmod = 0;
	ubigint refVitRqidle = 0;

	ubigint refVecKls = 0;
	uint vitnumKls = 1;

	ostringstream str;
	string s;

	// --- load version information
	dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver);

	hasdds = (ver->ixWOption & VecWznmWMVersionOption::DDSPUB);
	hasua = (ver->ixWOption & VecWznmWMVersionOption::UASRV);

	delete ver;

	Wznm::getVerlclrefs(dbswznm, refWznmMVersion, refLcl, refsLcl);

	// --- load vector items and blocks that are referenced frequently
	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VExpstate'", refVecExpst);
	if (refVecExpst != 0) {
		dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refVecExpst) + " AND sref = 'mind'", refVitMind);
		dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refVecExpst) + " AND sref = 'regd'", refVitRegd);
	};

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VReqitmode'", refVecReqmod);
	if (refVecReqmod != 0) dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refVecReqmod) + " AND sref = 'idle'", refVitRqidle);

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VKeylist'", refVecKls);
	if (refVecKls != 0) {
		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refVecKls), vitnumKls);
		vitnumKls++;
	};

	// --- generate jobs and their blocks

	// -- root and session jobs
	refJobRoot = genJobRoot(dbswznm, refWznmMVersion, Prjshort);
	refJobSess = genJobSess(dbswznm, refWznmMVersion, Prjshort, refJobRoot);
	if (hasdds || hasua) genJobM2msess(dbswznm, refWznmMVersion, Prjshort, refJobRoot);

	// -- card jobs
	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, crds);

	for (unsigned int i = 0; i < crds.nodes.size(); i++) {
		crd = crds.nodes[i];
		crdroot = crd->sref.substr(3);

		refJobCrd = genJobCrd(dbswznm, refWznmMVersion, Prjshort, refJobSess, crdroot, crd, refVecReqmod, refVitRqidle);

		// -- dialog jobs
		dbswznm->tblwznmmdialog->loadRstBySQL("SELECT * FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(crd->ref), false, dlgs);
		for (unsigned int j = 0; j < dlgs.nodes.size(); j++) {
			dlg = dlgs.nodes[j];
			genJobDlg(dbswznm, refWznmMVersion, refJobCrd, crdroot, dlg, refLcl, refsLcl);
		};

		// -- panel jobs
		dbswznm->tblwznmmpanel->loadRstBySQL("SELECT * FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(crd->ref) + " ORDER BY carNum ASC", false, pnls);

		refJobPnlrec = 0;
		for (unsigned int j = 0; j < pnls.nodes.size(); j++) {
			pnl = pnls.nodes[j];
			if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) refJobPnlrec = genJobPnl(dbswznm, refWznmMVersion, Prjshort, refJobCrd, 0, crdroot, pnl, refVecExpst, refVitMind, refVitRegd);
		};

		for (unsigned int j = 0; j < pnls.nodes.size(); j++) {
			pnl = pnls.nodes[j];
			if (pnl->ixVBasetype != VecWznmVMPanelBasetype::REC) genJobPnl(dbswznm, refWznmMVersion, Prjshort, refJobCrd, refJobPnlrec, crdroot, pnl, refVecExpst, refVitMind, refVitRegd);
		};
	};

	// -- query jobs
	dbswznm->tblwznmmquery->loadRstBySQL("SELECT * FROM TblWznmMQuery WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND supRefWznmMQuery = 0", false, qrys);

	for (unsigned int i = 0; i < qrys.nodes.size(); i++) {
		qry = qrys.nodes[i];
		genJobQry(dbswznm, Prjshort, qry);
	};

	// - connect UI-related joblin/jobor vectors
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = 0", false, vecs);
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		if (vec->sref.find("VecV") == 0) { // omit global vectors

			if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT TblWznmMControl.* FROM TblWznmMControl, TblWznmMFeed WHERE TblWznmMControl.ref = TblWznmMFeed.refWznmMControl AND TblWznmMFeed.srcIxVTbl = "
						+ to_string(VecWznmVMFeedSrcTbl::VEC) + " AND TblWznmMFeed.srcUref = " + to_string(vec->ref), &con)) {

				ref = 0;

				if (con->hkIxVTbl == VecWznmVMControlHkTbl::CAR) dbswznm->loadRefBySQL("SELECT refWznmMJob FROM TblWznmMCard WHERE ref = " + to_string(con->hkUref), ref);
				else if (con->hkIxVTbl == VecWznmVMControlHkTbl::DLG) dbswznm->loadRefBySQL("SELECT refWznmMJob FROM TblWznmMDialog WHERE ref = " + to_string(con->hkUref), ref);
				else if (con->hkIxVTbl == VecWznmVMControlHkTbl::PNL) {
					if ((vec->sref.rfind("Ord")+3) == vec->sref.length()) {
						dbswznm->loadRefBySQL("SELECT TblWznmMQuery.refWznmMJob FROM TblWznmMQuery, TblWznmRMPanelMQuery WHERE TblWznmMQuery.ref = TblWznmRMPanelMQuery.refWznmMQuery AND TblWznmRMPanelMQuery.refWznmMPanel = "
									+ to_string(con->hkUref), ref);
					} else {
						dbswznm->loadRefBySQL("SELECT refWznmMJob FROM TblWznmMPanel WHERE ref = " + to_string(con->hkUref), ref);
					};
				};

				if (ref != 0) {
					vec->hkUref = ref;
					dbswznm->tblwznmmvector->updateRec(vec);
				};

				delete con;
			};
		};
	};

	// -- import/export complex jobs
	dbswznm->tblwznmmimpexpcplx->loadRstBySQL("SELECT * FROM TblWznmMImpexpcplx WHERE refWznmMVersion = " + to_string(refWznmMVersion), false, iexs);

	for (unsigned int i = 0; i < iexs.nodes.size(); i++) {
		iex = iexs.nodes[i];
		genJobIex(dbswznm, Prjshort, iex, refLcl, refsLcl);
	};

	// --- generate blocks for customizable operation packs and static operation pack operations
	dbswznm->tblwznmmoppack->loadRstByVer(refWznmMVersion, false, opks);
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);

		if (opk->ixVBasetype == VecWznmVMOppackBasetype::CUST) {
			genOpkvecblks(dbswznm, opk, ops, refVecKls, vitnumKls, refLcl);

		} else if (opk->ixVBasetype == VecWznmVMOppackBasetype::STAT) {
			for (unsigned int j = 0; j < ops.nodes.size(); j++) {
				op = ops.nodes[j];
				genOpblks(dbswznm, refWznmMVersion, op);
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
ubigint WznmGenJob::genJobRoot(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string Prjshort
		) {
	ubigint retval;

	WznmMJob* job = NULL;

	ubigint refBlk;
	unsigned int bitnum;

	retval = dbswznm->tblwznmmjob->insertNewRec(&job, VecWznmVMJobBasetype::ROOT, refWznmMVersion, VecWznmVMJobRefTbl::VOID, 0, "Root" + Prjshort, false, false, false, "");

	// - commands
	dbswznm->tblwznmamjobcmd->insertNewRec(NULL, job->ref, "createSess", "");
	dbswznm->tblwznmamjobcmd->insertNewRec(NULL, job->ref, "eraseSess", "");
	dbswznm->tblwznmamjobcmd->insertNewRec(NULL, job->ref, "clearAll", "");

	// - blocks

	// DpchAppLogin {jref, username, password, m2mNotReg, chksuspsess}
	bitnum = 1;
	refBlk = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::CMBENG + VecWznmWScope::ENG, VecWznmWScope::APP, "DpchApp" + job->sref + "Login", "");

	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "username", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "password", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "m2mNotReg", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "chksuspsess", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "", 0, "");

	// DpchEngData {jref, feedFEnsSps}
	bitnum = 1;
	refBlk = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG, "DpchEng" + job->sref + "Data", "");

	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::FEED, "feedFEnsSps", VecWznmVVartype::VOID, 0, 0, 0, 0, 0, 0, "", 0, "");

	delete job;
	return retval;
};

ubigint WznmGenJob::genJobSess(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string Prjshort
			, const ubigint refJobRoot
		) {
	ubigint retval;

	vector<ubigint> refs;

	WznmMJob* job = NULL;

	ListWznmMCard crds;
	WznmMCard* crd = NULL;

	ubigint refStatshr;

	ubigint refBlk;
	unsigned int bitnum;

	retval = dbswznm->tblwznmmjob->insertNewRec(&job, VecWznmVMJobBasetype::SESS, refWznmMVersion, VecWznmVMJobRefTbl::VOID, 0, "Sess" + Prjshort, false, false, false, "");

	dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refJobRoot, job->ref, "sess", true, VecWznmVRMJobMJobConstract::VOID);

	// - commands

	// create/erase for each card except nav
	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, crds);

	for (unsigned int i = 0; i < crds.nodes.size(); i++) {
		crd = crds.nodes[i];

		if (crd->sref.substr(3+4).compare("Nav") != 0) {
			dbswznm->tblwznmamjobcmd->insertNewRec(NULL, job->ref, "createCrd" + StrMod::lc(crd->sref.substr(3+4)), "");
			dbswznm->tblwznmamjobcmd->insertNewRec(NULL, job->ref, "eraseCrd" + StrMod::lc(crd->sref.substr(3+4)), "");
		};
	};

	// - blocks

	// StatShr {jrefCrdnav}
	bitnum = 1;
	refStatshr = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::STAT, refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG, "StatShr" + job->sref, "");

	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatshr, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jrefCrdnav", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");

	// DpchEngData {jref, feedFEnsSec, statahr}
	bitnum = 1;
	refBlk = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG, "DpchEng" + job->sref + "Data", "");

	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::FEED, "feedFEnsSec", VecWznmVVartype::VOID, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::SUB, "statshr", VecWznmVVartype::VOID, 0, 0, 0, 0, refStatshr, 0, "", 0, "");

	delete job;
	return retval;
};

ubigint WznmGenJob::genJobM2msess(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string Prjshort
			, const ubigint refJobRoot
		) {
	ubigint retval;

	WznmMJob* job = NULL;

	ubigint refStatshr;

	ubigint refBlk;
	unsigned int bitnum;

	retval = dbswznm->tblwznmmjob->insertNewRec(&job, VecWznmVMJobBasetype::SESS, refWznmMVersion, VecWznmVMJobRefTbl::VOID, 0, "M2msess" + Prjshort, false, false, false, "");

	dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refJobRoot, job->ref, "m2msess", true, VecWznmVRMJobMJobConstract::VOID);

	// - blocks

	// StatShr (fill in WznmComplJtr)
	refStatshr = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::STAT, refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG, "StatShr" + job->sref, "");

	// DpchEngData {jref, statahr}
	bitnum = 1;
	refBlk = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG, "DpchEng" + job->sref + "Data", "");

	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::SUB, "statshr", VecWznmVVartype::VOID, 0, 0, 0, 0, refStatshr, 0, "", 0, "");

	delete job;
	return retval;
};

ubigint WznmGenJob::genJobCrd(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string Prjshort
			, const ubigint refJobSess
			, const string& crdroot
			, WznmMCard* crd
			, const ubigint refVecReqmod
			, const ubigint refVitRqidle
		) {
	ubigint retval;

	ubigint ref;

	WznmMJob* job = NULL;

	unsigned int sgenum = 1;
	ubigint refSgeIdle, refSgeAlr;

	ListWznmMDialog dlgs;
	WznmMDialog* dlg = NULL;

	ListWznmMPanel pnls;
	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	map<string,ubigint> vecs;
	map<ubigint,unsigned int> vitnums;
	map<string,ubigint> blks;
	map<ubigint,unsigned int> bitnums;
	map<string,ubigint> feds;
	map<string,ubigint> rsts;
	set<ubigint> refsAlr;

	string s;

	retval = dbswznm->tblwznmmjob->insertNewRec(&job, VecWznmVMJobBasetype::CRD, refWznmMVersion, VecWznmVMJobRefTbl::CAR, crd->ref, crd->sref, false, false, false, "");

	crd->refWznmMJob = job->ref;
	dbswznm->tblwznmmcard->updateRec(crd);

	job->sref = job->sref.substr(3);

	if (crd->sref.substr(3+4).compare("Nav") == 0) {
		dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refJobSess, job->ref, "crd" + StrMod::lc(crd->sref.substr(3+4)), false, VecWznmVRMJobMJobConstract::CRE);
	} else {
		dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refJobSess, job->ref, "crd" + StrMod::lc(crd->sref.substr(3+4)), true, VecWznmVRMJobMJobConstract::VOID);
	};

	// - stages {idle, alrxxxxabt, <alr's>}
	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(crd->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::ALR) + " ORDER BY hkNum ASC", false, cons);
	for (unsigned int i = 0; i < cons.nodes.size(); i++) refsAlr.insert(cons.nodes[i]->ref);

	refSgeIdle = dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::OTHER, job->ref, sgenum++, 0, "idle", 0, 0, 0, 0, "");

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(crd->ref) + " AND sref = 'MitAppAbt'", ref)) {
		refSgeAlr = dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::ALR, job->ref, sgenum++, 0, StrMod::lc("Alr" + Prjshort + "Abt"), 0, refSgeIdle, 0, 0, "");

		dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CON, job->ref, refSgeIdle, 0, VecWznmVMSensitivityJactype::LOCK, 0, "", "", ref, "", VecWznmVMSensitivityAction::CHGSGE, refSgeAlr, false);
	};

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::ALR, job->ref, sgenum++, 0, StrMod::lc(con->sref), 0, refSgeIdle, 0, 0, "");
	};

	// - vectors

	// card close
	addVit(dbswznm, job, vecs, vitnums, "VecVDo", "close");

	// VecVSge is taken care of in WznmGenSysvec

	// - blocks

	// basic StatApp block items
	addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "ix" + Prjshort + "VReqitmode", VecWznmVVartype::VECSREF, 0, refVecReqmod, "", refVitRqidle);
	addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "latency", VecWznmVVartype::USMALLINT, 0, 0, "5", 0);
	addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "shortMenu", VecWznmVVartype::STRING, 0, 0, "", 0);
	addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "widthMenu", VecWznmVVartype::UINT, 0, 0, "0", 0);

	// <jref... for each dialog>, <jref... for each subpanel>, <initdone... for each subpanel>, <avail for each subpanel with non-empty Avail rule>
	dbswznm->tblwznmmdialog->loadRstBySQL("SELECT * FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(crd->ref) + " ORDER BY sref ASC", false, dlgs);

	for (unsigned int i = 0; i < dlgs.nodes.size(); i++) {
		dlg = dlgs.nodes[i];

		// short: ex. 'DlgWznmVerDbstr' to 'Dlgdbstr'
		s = StrMod::cap(StrMod::lc("Dlg" + dlg->sref.substr(3 + crdroot.length())));

		addBit(dbswznm, job, blks, bitnums, "StatShr", "", VecWznmVAMBlockItemBasetype::VAR, "jref" + s, VecWznmVVartype::SCRREF, 0, 0, "0", 0);
	};

	dbswznm->tblwznmmpanel->loadRstByCar(crd->ref, false, pnls);

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ( (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECFORM) && (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECLIST) ) {
			addBit(dbswznm, job, blks, bitnums, "StatShr", "", VecWznmVAMBlockItemBasetype::VAR, "jref" + pnl->sref.substr(pnl->sref.find(crdroot) + crdroot.length()), VecWznmVVartype::SCRREF, 0, 0, "0", 0);
			addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "initdone" + pnl->sref.substr(pnl->sref.find(crdroot) + crdroot.length()), VecWznmVVartype::BOOLEAN, 0, 0, "false", 0);
			if (pnl->Avail.length() > 0) addBit(dbswznm, job, blks, bitnums, "StatShr", "", VecWznmVAMBlockItemBasetype::VAR, "pnl" + StrMod::lc(pnl->sref.substr(pnl->sref.find(crdroot) + crdroot.length())) + "Avail", VecWznmVVartype::BOOLEAN, 0, 0, "false", 0);
		};
	};

	// controls
	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::CAR, crd->ref, false, cons);
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		if (con->ixVBasetype != VecWznmVMControlBasetype::MEN) addCon(dbswznm, job, vecs, vitnums, blks, bitnums, feds, refsAlr, con, "");
	};

	genDpchappdo(dbswznm, job, vecs);
	genDpchengdata(dbswznm, job, blks, feds, rsts);

	delete job;
	return retval;
};

void WznmGenJob::genJobDlg(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const ubigint refJobCrd
			, const string& crdroot
			, WznmMDialog* dlg
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	WznmMJob* job = NULL;

	ubigint refSgeIdle = 0;

	unsigned int sgenum = 1;

	ListWznmMControl ditcons;
	WznmMControl* ditcon = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	map<string,ubigint> vecs;
	map<ubigint,unsigned int> vitnums;
	map<string,ubigint> blks;
	map<ubigint,unsigned int> bitnums;
	map<string,ubigint> feds;
	map<string,ubigint> rsts;
	set<ubigint> refsAlr;

	string s;

	dbswznm->tblwznmmjob->insertNewRec(&job, VecWznmVMJobBasetype::DLG, refWznmMVersion, VecWznmVMJobRefTbl::DLG, dlg->ref, dlg->sref, false, false, false, "");

	dlg->refWznmMJob = job->ref;
	dbswznm->tblwznmmdialog->updateRec(dlg);

	// short: ex. 'DlgWznmVerDbstr' to 'dlgdbstr'
	s = StrMod::lc("Dlg" + dlg->sref.substr(3 + crdroot.length()) );
	dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refJobCrd, job->ref, s, false, VecWznmVRMJobMJobConstract::VOID);

	// - stages {idle, <alr's>}
	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::ALR) + " ORDER BY hkNum ASC", false, cons);
	for (unsigned int i = 0; i < cons.nodes.size(); i++) refsAlr.insert(cons.nodes[i]->ref);

	if (StrMod::srefInSrefs(dlg->Comment, "live")) refSgeIdle = dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::OTHWC, job->ref, sgenum++, 0, "idle", 0, 0, 0, 0, "");
	else if (cons.nodes.size() > 0) refSgeIdle = dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::OTHER, job->ref, sgenum++, 0, "idle", 0, 0, 0, 0, "");

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::ALR, job->ref, sgenum++, 0, StrMod::lc(con->sref), 0, refSgeIdle, 0, 0, "");
	};

	// - vectors

	// VecVDit and VecVSge are taken care of in WznmGenSysvec

	// - blocks
	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref)
				+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::DIT) + " ORDER BY hkNum ASC", false, ditcons);

	// basic StatApp block items
	if (ditcons.nodes.size() > 0) addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "initdone", VecWznmVVartype::BOOLEAN, 0, 0, "false", 0);
	addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "shortMenu", VecWznmVVartype::STRING, 0, 0, "", 0);

	// controls by dit
	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, dlg->ref, false, cons);

	if (ditcons.nodes.size() == 0) {
		addBasecons(dbswznm, job, blks, bitnums, cons, 0, "");

	} else {
		for (unsigned int i = 0; i < ditcons.nodes.size(); i++) {
			ditcon = ditcons.nodes[i];
			addBasecons(dbswznm, job, blks, bitnums, cons, ditcon->ref, ditcon->sref.substr(3));
		};
	};

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((ditcons.nodes.size() == 0) || (con->supRefWznmMControl == 0)) addCon(dbswznm, job, vecs, vitnums, blks, bitnums, feds, refsAlr, con, "");
		else addCon(dbswznm, job, vecs, vitnums, blks, bitnums, feds, refsAlr, con, con->sref.substr(0, 3));
	};

	genDpchappdata(dbswznm, job, blks);
	genDpchappdo(dbswznm, job, vecs);
	genDpchengdata(dbswznm, job, blks, feds, rsts);

	delete job;
};

ubigint WznmGenJob::genJobPnl(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string Prjshort
			, const ubigint refJobCrd
			, const ubigint refJobPnlrec
			, const string& crdroot
			, WznmMPanel* pnl
			, const ubigint refVecExpst
			, const ubigint refVitMind
			, const ubigint refVitRegd
		) {
	ubigint retval;

	WznmMJob* job = NULL;

	ubigint refSgeIdle = 0;

	unsigned int sgenum = 1;

	ListWznmMPanel crdpnls;
	WznmMPanel* crdpnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	map<string,ubigint> vecs;
	map<ubigint,unsigned int> vitnums;
	map<string,ubigint> blks;
	map<ubigint,unsigned int> bitnums;
	map<string,ubigint> feds;
	map<string,ubigint> rsts;
	set<ubigint> refsAlr;

	ListWznmMQuery qrys;
	WznmMQuery* qry;

	string qrypostfix;

	string s;

	retval = dbswznm->tblwznmmjob->insertNewRec(&job, VecWznmVMJobBasetype::PNL, refWznmMVersion, VecWznmVMJobRefTbl::PNL, pnl->ref, pnl->sref, false, false, false, "");

	pnl->refWznmMJob = job->ref;
	dbswznm->tblwznmmpanel->updateRec(pnl);

	// --- stages {idle, <alr's>}
	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::ALR) + " ORDER BY hkNum ASC", false, cons);
	for (unsigned int i = 0; i < cons.nodes.size(); i++) refsAlr.insert(cons.nodes[i]->ref);

	if (StrMod::srefInSrefs(pnl->Comment, "live")) refSgeIdle = dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::OTHWC, job->ref, sgenum++, 0, "idle", 0, 0, 0, 0, "");
	else if (cons.nodes.size() > 0) refSgeIdle = dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::OTHER, job->ref, sgenum++, 0, "idle", 0, 0, 0, 0, "");

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		dbswznm->tblwznmmstage->insertNewRec(NULL, VecWznmVMStageBasetype::ALR, job->ref, sgenum++, 0, StrMod::lc(con->sref), 0, refSgeIdle, 0, 0, "");
	};

	// --- vectors

	// VecVOrd and VecVSge are taken care of in WznmGenSysvec

	// --- blocks
	job->sref = job->sref.substr(3); // eliminate "Pnl" ditshort for blocks

	// short: ex. 'PnlBrlyLocHeadbar' to 'pnlheadbar'
	s = StrMod::lc("Pnl" + pnl->sref.substr(3 + crdroot.length()) );

	if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) ) {
		// pnlrec as sup
		dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refJobPnlrec, job->ref, s, false, VecWznmVRMJobMJobConstract::VOID);
	} else {
		// crd as sup
		dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refJobCrd, job->ref, s, false, VecWznmVRMJobMJobConstract::CRE);
	};

	if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) {
		// -- blocks for headbar panel

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) {
		// -- blocks for heading line panel

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
		// -- blocks for list panel

		// ixXxxxVExpstate
		addBit(dbswznm, job, blks, bitnums, "StatShr", "", VecWznmVAMBlockItemBasetype::VAR, "ix" + Prjshort + "VExpstate", VecWznmVVartype::VECSREF, 0, refVecExpst, "", refVitMind);

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
		// -- blocks for rec panel

		// ixXxxxVExpstate
		addBit(dbswznm, job, blks, bitnums, "StatShr", "", VecWznmVAMBlockItemBasetype::VAR, "ix" + Prjshort + "VExpstate", VecWznmVVartype::VECSREF, 0, refVecExpst, "", refVitRegd);

		// <jref... for each subpanel>, <initdone... for each subpanel>, <avail for each subpanel with non-empty Avail rule>
		dbswznm->tblwznmmpanel->loadRstByCar(pnl->carRefWznmMCard, false, crdpnls);

		for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
			crdpnl = crdpnls.nodes[i];

			if ( (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) ) {
				addBit(dbswznm, job, blks, bitnums, "StatShr", "", VecWznmVAMBlockItemBasetype::VAR, "jref" + crdpnl->sref.substr(crdpnl->sref.find(crdroot) + crdroot.length()), VecWznmVVartype::SCRREF, 0, 0, "0", 0);
				addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "initdone" + crdpnl->sref.substr(crdpnl->sref.find(crdroot) + crdroot.length()), VecWznmVVartype::BOOLEAN, 0, 0, "false", 0);
				if (crdpnl->Avail.length() > 0) addBit(dbswznm, job, blks, bitnums, "StatShr", "", VecWznmVAMBlockItemBasetype::VAR, "pnl" + StrMod::lc(crdpnl->sref.substr(crdpnl->sref.find(crdroot) + crdroot.length())) + "Avail", VecWznmVVartype::BOOLEAN, 0, 0, "false", 0);
			};
		};

	} else {
		// -- blocks for panel base types FORM, RECFORM, RECLIST

		// ixXxxxVExpstate
		if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND sref = 'ButRegularize'", &con)) {
			if (con->ixVScope == VecWznmVMControlScope::APP) addBit(dbswznm, job, blks, bitnums, "StatApp", "", VecWznmVAMBlockItemBasetype::VAR, "ix" + Prjshort + "VExpstate", VecWznmVVartype::VECSREF, 0, refVecExpst, "", refVitMind);
			else addBit(dbswznm, job, blks, bitnums, "StatShr", "", VecWznmVAMBlockItemBasetype::VAR, "ix" + Prjshort + "VExpstate", VecWznmVVartype::VECSREF, 0, refVecExpst, "", refVitMind);

			delete con;
		};
	};

	// -- blocks for controls
	if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) {
		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(pnl->carRefWznmMCard)
					+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::MEN) + " ORDER BY hkNum ASC", false, cons);

	} else {
		dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);
	};

	if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) ) {
		addBasecons(dbswznm, job, blks, bitnums, cons, 0, "");
	};

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		addCon(dbswznm, job, vecs, vitnums, blks, bitnums, feds, refsAlr, con, "");
	};

	// query-related blocks
	dbswznm->tblwznmmquery->loadRstBySQL("SELECT TblWznmMQuery.* FROM TblWznmMQuery, TblWznmRMPanelMQuery WHERE TblWznmMQuery.ref = TblWznmRMPanelMQuery.refWznmMQuery AND TblWznmRMPanelMQuery.refWznmMPanel = " + to_string(pnl->ref), false, qrys);

	for (unsigned int i = 0; i < qrys.nodes.size(); i++) {
		qry = qrys.nodes[i];

		qrypostfix = getPnlqryPostfix(pnl->sref, qry->sref);

		// rst
		rsts["rst" + qrypostfix] = qry->qtbRefWznmMTable;

		// statappqry
		if (qry->Limofs) blks["statappqry" + qrypostfix] = 0;
		
		// statshrqry, stgiacqry
		blks["statshrqry" + qrypostfix] = 0;
		blks["stgiacqry" + qrypostfix] = 0;
	};

	// compile dispatches
	genDpchappdata(dbswznm, job, blks);
	genDpchappdo(dbswznm, job, vecs);
	genDpchengdata(dbswznm, job, blks, feds, rsts);

	delete job;
	return retval;
};

void WznmGenJob::addBasecons(
			DbsWznm* dbswznm
			, WznmMJob* job // sref altered for Crd: CrdBrlyNav -> BrlyNav, PnlBrlyNavAdmin -> BrlyNavAdmin
			, map<string,ubigint>& blks
			, map<ubigint,unsigned int>& bitnums
			, ListWznmMControl& cons
			, const ubigint refDit
			, const string& ditshort
		) {
	WznmMControl* basecon;

	vector<unsigned int> icsBasecons;

	unsigned int cplxtype;
	string baseconsref, baseconshort;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT, VecWznmVMControlHkSection::CONTDETD, VecWznmVMControlHkSection::CONTREGD}, refDit, icsBasecons);

	for (unsigned int i = 0; i < icsBasecons.size(); i++) {
		basecon = cons.nodes[icsBasecons[i]];

		Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, ditshort, cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
					icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

		// StatApp
		if ((cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT))
					addBit(dbswznm, job, blks, bitnums, "StatApp", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, baseconsref + "Alt", VecWznmVVartype::BOOLEAN, basecon->ref, 0, "true", 0);
		else if ((cplxtype == Concplxtype::PUP_TXFALT) || (cplxtype == Concplxtype::TXT_TXFALT))
					addBit(dbswznm, job, blks, bitnums, "StatApp", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, baseconsref + "Alt", VecWznmVVartype::BOOLEAN, basecon->ref, 0, "false", 0);

		// StatShr
		if ((cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::PUP_TXFALT) || (cplxtype == Concplxtype::TXT_TXFALT))
					addBit(dbswznm, job, blks, bitnums, "StatShr", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, "Txf" + baseconshort + "Valid", VecWznmVVartype::BOOLEAN, basecon->ref, 0, "false", 0);
	};
};

void WznmGenJob::addCon(
			DbsWznm* dbswznm
			, WznmMJob* job // sref altered for Crd: CrdBrlyNav -> BrlyNav, PnlBrlyNavAdmin -> BrlyNavAdmin
			, map<string,ubigint>& vecs
			, map<ubigint,unsigned int>& vitnums
			, map<string,ubigint>& blks
			, map<ubigint,unsigned int>& bitnums
			, map<string,ubigint>& feds
			, set<ubigint>& refsAlr
			, WznmMControl* con
			, const string& ditshort
		) {
	string consref;

	vector<string> ss;
	string s;

	consref = Wznm::getConsref(con, ditshort);

	// skip alert sub-controls
	if ( (con->supRefWznmMControl != 0) && ((con->ixVBasetype == VecWznmVMControlBasetype::MCB) || (con->ixVBasetype == VecWznmVMControlBasetype::TXT)) ) {
		if (refsAlr.find(con->supRefWznmMControl) != refsAlr.end()) return;
	};

	// all: StatApp/StatShr if avail/active rule present
	if (con->Avail.length() > 0) addBit(dbswznm, job, blks, bitnums, Wznm::getConstatblk(con), ditshort, VecWznmVAMBlockItemBasetype::VAR, consref + "Avail", VecWznmVVartype::BOOLEAN, con->ref, 0, "true", 0);
	if (con->Active.length() > 0) addBit(dbswznm, job, blks, bitnums, Wznm::getConstatblk(con), ditshort, VecWznmVAMBlockItemBasetype::VAR, consref + "Active", VecWznmVVartype::BOOLEAN, con->ref, 0, "true", 0);

	if (con->ixVBasetype == VecWznmVMControlBasetype::ALR) {
		// -

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
		// ContInf, VecVDo, Tag
		if (con->ixVScope == VecWznmVMControlScope::SHR) {
			if (StrMod::srefInSrefs(con->srefsKOption, "onoff"))
						addBit(dbswznm, job, blks, bitnums, "ContInf", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref + "On", VecWznmVVartype::BOOLEAN, con->ref, 0, "false", 0);

			if (StrMod::srefInSrefs(con->srefsKOption, "mdnup")) {
				addVit(dbswznm, job, vecs, vitnums, "VecVDo" + ditshort, consref + "Mdn");
				addVit(dbswznm, job, vecs, vitnums, "VecVDo" + ditshort, consref + "Mup");
			} else addVit(dbswznm, job, vecs, vitnums, "VecVDo" + ditshort, consref + "Click");
		};
		if (!StrMod::srefInSrefs(con->srefsKOption, "icon")) addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::CHK) {
		// ContIac
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref, VecWznmVVartype::BOOLEAN, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) {
		// Tag
		addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::CSI) {
		// Feed, ContInf
		feds["FeedF" + con->sref] = con->refWznmMFeed;
		addBit(dbswznm, job, blks, bitnums, "ContInf", ditshort, VecWznmVAMBlockItemBasetype::VAR, "numF" + consref, VecWznmVVartype::UINT, con->ref, 0, "1", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::CUS) {
		// StatShr
		if (StrMod::srefInSrefs(con->srefsKOption, "varh")) addBit(dbswznm, job, blks, bitnums, "StatShr", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, consref + "Height", VecWznmVVartype::UINT, con->ref, 0, "100", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::DIT) {
		// Feed, ContIac ; no ditshort ; VecVDit goes separately
		if (con->refWznmMFeed != 0) {
			feds["FeedF" + con->sref] = con->refWznmMFeed;
			addBit(dbswznm, job, blks, bitnums, "ContIac", "", VecWznmVAMBlockItemBasetype::VAR, "numF" + con->sref, VecWznmVVartype::UINT, con->ref, 0, "1", 0);
		};

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::DLD) {
		// ContInf, Tag
		addBit(dbswznm, job, blks, bitnums, "ContInf", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref, VecWznmVVartype::STRING, con->ref, 0, "file", 0);
		addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::DSE) {
		// Feed, ContIac ; no ditshort
		feds["FeedF" + con->sref] = con->refWznmMFeed;
		addBit(dbswznm, job, blks, bitnums, "ContIac", "", VecWznmVAMBlockItemBasetype::VAR, "numF" + con->sref, VecWznmVVartype::UINT, con->ref, 0, "1", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::HDG) {
		// Tag
		addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::HSB) {
		// -

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::LSB) {
		// -

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::LST) {
		// Feed, ContIac, StatApp
		feds["FeedF" + con->sref] = con->refWznmMFeed;

		if (StrMod::srefInSrefs(con->srefsKOption, "multsel")) {
			addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, "numsF" + consref, VecWznmVVartype::UINTVEC, con->ref, 0, "", 0);
		} else {
			addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, "numF" + consref, VecWznmVVartype::UINT, con->ref, 0, "1", 0);
		};

		addBit(dbswznm, job, blks, bitnums, "StatApp", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref + "NumFirstdisp", VecWznmVVartype::UINT, con->ref, 0, "1", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::MCB) {
		// VecVDo, Feed
		if (con->ixVScope == VecWznmVMControlScope::SHR) addVit(dbswznm, job, vecs, vitnums, "VecVDo" + ditshort, "numF" + consref);
		if (con->refWznmMFeed != 0) feds["FeedF" + con->sref] = con->refWznmMFeed;

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::MEN) {
		// StgInf (cptwidth and width), Tag ; no ditshort ; exceptionally handled by pnlheadbar despite of being card's controls
		addBit(dbswznm, job, blks, bitnums, "StgInf", "", VecWznmVAMBlockItemBasetype::CONPAR, con->sref + "Cptwidth", VecWznmVVartype::UINT, con->ref, 0, "100", 0);
		addBit(dbswznm, job, blks, bitnums, "StgInf", "", VecWznmVAMBlockItemBasetype::CONPAR, con->sref + "Width", VecWznmVVartype::UINT, con->ref, 0, "100", 0);
		addBit(dbswznm, job, blks, bitnums, "Tag", "", VecWznmVAMBlockItemBasetype::CONTIT, con->sref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::MIT) {
		// VecVDo, Tag ; no ditshort
		if (con->ixVScope == VecWznmVMControlScope::SHR) addVit(dbswznm, job, vecs, vitnums, "VecVDo", con->sref + "Click");
		addBit(dbswznm, job, blks, bitnums, "Tag", "", VecWznmVAMBlockItemBasetype::CONTIT, con->sref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::MSP) {
		// -

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::MRL) {
		// ContInf, Tag
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContInf", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);
		addBit(dbswznm, job, blks, bitnums, "Tag", "", VecWznmVAMBlockItemBasetype::CONTIT, con->sref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::MTX) {
		// ContInf, Tag
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContInf", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);
		else addBit(dbswznm, job, blks, bitnums, "Tag", "", VecWznmVAMBlockItemBasetype::CONTIT, con->sref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::PUP) {
		// Feed, ContIac
		feds["FeedF" + con->sref] = con->refWznmMFeed;
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, "numF" + consref, VecWznmVVartype::UINT, con->ref, 0, "1", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::RBU) {
		// Feed, ContIac
		feds["FeedF" + con->sref] = con->refWznmMFeed;
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, "numF" + consref, VecWznmVVartype::UINT, con->ref, 0, "1", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::SEP) {
		// -

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::SGE) {
		// Feed, ContInf ; no ditshort
		feds["FeedF" + con->sref] = con->refWznmMFeed;
		addBit(dbswznm, job, blks, bitnums, "ContInf", "", VecWznmVAMBlockItemBasetype::VAR, "numF" + con->sref, VecWznmVVartype::UINT, con->ref, 0, "1", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::SLD) {
		// ContIac, StgInf (min/max)
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref, VecWznmVVartype::DOUBLE, con->ref, 0, "0.0", 0);
		addBit(dbswznm, job, blks, bitnums, "StatShr", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, consref + "Min", VecWznmVVartype::DOUBLE, con->ref, 0, "0.0", 0);
		addBit(dbswznm, job, blks, bitnums, "StatShr", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, consref + "Max", VecWznmVVartype::DOUBLE, con->ref, 0, "1.0", 0);
		if (StrMod::srefInSrefs(con->srefsKOption, "rast")) addBit(dbswznm, job, blks, bitnums, "StatShr", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, consref + "Rast", VecWznmVVartype::DOUBLE, con->ref, 0, "0.1", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::SPC) {
		// -

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::TBL) {
		// -

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) {
		// StgIac, Tag
		s = "100";
		dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "width", 0, s);
		addBit(dbswznm, job, blks, bitnums, "StgIac", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, consref + "Width", VecWznmVVartype::UINT, con->ref, 0, s, 0);
		addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::TOS) {
		// Feed, ContIac
		feds["FeedF" + con->sref] = con->refWznmMFeed;
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, "numF" + consref, VecWznmVVartype::UINT, con->ref, 0, "1", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::TRS) {
		// Tag
		addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::TSB) {
		// -

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::TXF) {
		// ContIac
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::TXT) {
		// ContInf, Tag (possibility of multiple tags)
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContInf", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

		StrMod::stringToVector(con->srefsWznmMTag, ss);
		if (ss.size() > 1) {
			for (unsigned int j = 0; j < ss.size(); j++) {
				addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref + to_string(j+1), VecWznmVVartype::STRING, con->ref, 0, "", 0);
			};

		} else if ((ss.size() == 1) || (con->Title.length() > 0)) {
			addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);
		};

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::UPD) {
		// ContIac, StgInf
		if (con->ixVScope == VecWznmVMControlScope::SHR) addBit(dbswznm, job, blks, bitnums, "ContIac", ditshort, VecWznmVAMBlockItemBasetype::VAR, consref, VecWznmVVartype::INT, con->ref, 0, "0", 0);

		addBit(dbswznm, job, blks, bitnums, "StatShr", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, consref + "Min", VecWznmVVartype::INT, con->ref, 0, "0", 0);
		addBit(dbswznm, job, blks, bitnums, "StatShr", ditshort, VecWznmVAMBlockItemBasetype::CONPAR, consref + "Max", VecWznmVVartype::INT, con->ref, 0, "100", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::ULD) {
		// Tag
		addBit(dbswznm, job, blks, bitnums, "Tag", ditshort, VecWznmVAMBlockItemBasetype::CONTIT, consref, VecWznmVVartype::STRING, con->ref, 0, "", 0);

	} else if (con->ixVBasetype == VecWznmVMControlBasetype::VSB) {
		// -
	};
};

void WznmGenJob::addBit(
			DbsWznm* dbswznm
			, WznmMJob* job // sref shortened, e.g. PnlBrlyLocMap -> BrlyLocMap
			, map<string,ubigint>& blks // key: short version, e.g. StatShrDlgBrlyNavLoainiIfi -> StatShrIfi
			, map<ubigint,unsigned int>& bitnums
			, const string& blkSref // e.g. StatShr
			, const string& blkPostfix // e.g. Ifi
			, const uint ixVBasetype
			, const string& sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMControl
			, const ubigint refWznmMVector
			, const string& Defval
			, const ubigint refWznmMVectoritem
		) {
	ubigint ref;

	WznmAMBlockItem* bit = NULL;

	uint blkIxVBasetype;
	uint blkReaIxWznmWScope;
	uint blkWriIxWznmWScope;

	map<string,ubigint>::iterator it;

	it = blks.find(blkSref + blkPostfix);
	if (it == blks.end()) {

		if ((blkSref.find("ContIac") == 0) || (blkSref.find("ContInf") == 0)) blkIxVBasetype = VecWznmVMBlockBasetype::CONT;
		else if ((blkSref.find("StatApp") == 0) || (blkSref.find("StatShr") == 0)) blkIxVBasetype = VecWznmVMBlockBasetype::STAT;
		else if ((blkSref.find("StgIac") == 0) || (blkSref.find("StgInf") == 0)) blkIxVBasetype = VecWznmVMBlockBasetype::STG;
		else if (blkSref.find("Tag") == 0) blkIxVBasetype = VecWznmVMBlockBasetype::TAG;
		else blkIxVBasetype = 0;

		if ((blkSref.find("ContIac") == 0) || (blkSref.find("StgIac") == 0)) {
			blkReaIxWznmWScope = VecWznmWScope::APP + VecWznmWScope::CMBENG + VecWznmWScope::ENG;
			blkWriIxWznmWScope = VecWznmWScope::APP + VecWznmWScope::CMBENG + VecWznmWScope::ENG;
		} else if ((blkSref.find("ContInf") == 0) || (blkSref.find("StatApp") == 0) || (blkSref.find("StatShr") == 0) || (blkSref.find("StgInf") == 0) || (blkSref.find("Tag") == 0)) {
			blkReaIxWznmWScope = VecWznmWScope::APP;
			blkWriIxWznmWScope = VecWznmWScope::CMBENG + VecWznmWScope::ENG;
		} else {
			blkReaIxWznmWScope = 0;
			blkWriIxWznmWScope = 0;
		};

		ref = dbswznm->tblwznmmblock->insertNewRec(NULL, blkIxVBasetype, job->refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, blkReaIxWznmWScope, blkWriIxWznmWScope, blkSref + job->sref + blkPostfix, "");
		blks[blkSref + blkPostfix] = ref;
		bitnums[ref] = 1;

	} else {
		ref = it->second;
	};

	dbswznm->tblwznmamblockitem->insertNewRec(&bit, 0, ref, bitnums[ref]++, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, 0, 0, 0, 0, Defval, refWznmMVectoritem, "");
	if ((Defval != "") || (refWznmMVectoritem != 0)) {
		bit->refJ = dbswznm->tblwznmjamblockitem->insertNewRec(NULL, bit->ref, 0, Defval, refWznmMVectoritem);
		dbswznm->tblwznmamblockitem->updateRec(bit);
	};
	delete bit;
};

void WznmGenJob::addVit(
			DbsWznm* dbswznm
			, WznmMJob* job // sref shortened
			, map<string,ubigint>& vecs // key: short version, e.g. VecVDlgBrlyNavLoainiDoImp -> VecVDoImp
			, map<ubigint,unsigned int>& vitnums
			, const string& vecSref // short version, postfix included
			, const string& sref
		) {
	ubigint ref;

	map<string,ubigint>::iterator it;

	it = vecs.find(vecSref);
	if (it == vecs.end()) {
		ref = dbswznm->tblwznmmvector->insertNewRec(NULL, VecWznmVMVectorBasetype::LIN, job->refWznmMVersion, VecWznmVMVectorHkTbl::JOB, job->ref, 0, "VecV" + job->sref + vecSref.substr(4), "", "noloc;notit");
		vecs[vecSref] = ref;
		vitnums[ref] = 1;
	} else {
		ref = it->second;
	};

	dbswznm->tblwznmmvectoritem->insertNewRec(NULL, ref, vitnums[ref]++, sref, "", "", 0, "", "");
};

void WznmGenJob::genDpchappdata(
			DbsWznm* dbswznm
			, WznmMJob* job
			, map<string,ubigint>& blks
		) {
	map<string,ubigint>::iterator it;

	WznmMBlock* blk = NULL;

	ubigint refDpch;
	unsigned int bitnum = 1;

	bool found = false;

	for (it = blks.begin(); it != blks.end(); it++) {
		if (dbswznm->tblwznmmblock->loadRecByRef(it->second, &blk)) {
			if (blk->wriIxWznmWScope & VecWznmWScope::APP) found = true;
			delete blk;

			if (found) break;

		} else {
			if ((it->first.find("stgiac") == 0) && (it->second == 0)) {
				found = true;
				break;
			};
		};
	};

	if (found) {
		refDpch = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, job->refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::CMBENG + VecWznmWScope::ENG, VecWznmWScope::APP, "DpchApp" + job->sref + "Data", "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");

		for (it = blks.begin(); it != blks.end(); it++) {
			if (dbswznm->tblwznmmblock->loadRecByRef(it->second, &blk)) {
				if (blk->wriIxWznmWScope & VecWznmWScope::APP) dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::SUB, StrMod::lc(it->first), VecWznmVVartype::VOID, 0, 0, 0, 0, it->second, 0, "", 0, "");
				delete blk;

			} else {
				if ((it->first.find("stgiac") == 0) && (it->second == 0)) dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::SUB, StrMod::lc(it->first), VecWznmVVartype::VOID, 0, 0, 0, 0, 0, 0, "", 0, "");
			};
		};
	};
};

void WznmGenJob::genDpchappdo(
			DbsWznm* dbswznm
			, WznmMJob* job
			, map<string,ubigint>& vecs
		) {
	map<string,ubigint>::iterator it;

	ubigint refDpch;
	unsigned int bitnum = 1;

	if (!vecs.empty()) {
		refDpch = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, job->refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::CMBENG + VecWznmWScope::ENG, VecWznmWScope::APP, "DpchApp" + job->sref + "Do", "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");

		for (it = vecs.begin(); it != vecs.end(); it++) dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ix" + it->first.substr(3), VecWznmVVartype::VECSREF, 0, it->second, 0, 0, 0, 0, "", 0, "");
	};
};

void WznmGenJob::genDpchengdata(
			DbsWznm* dbswznm
			, WznmMJob* job
			, map<string,ubigint>& blks
			, map<string,ubigint>& feds
			, map<string,ubigint>& rsts
		) {
	map<string,ubigint>::iterator it;

	ubigint refDpch;
	unsigned int bitnum = 1;

	vector<string> srefs;

	// sort
	for (it = blks.begin(); it != blks.end(); it++) srefs.push_back(it->first);
	for (it = feds.begin(); it != feds.end(); it++) srefs.push_back(it->first);
	for (it = rsts.begin(); it != rsts.end(); it++) srefs.push_back(it->first);

	sort(srefs.begin(), srefs.end());

	refDpch = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, job->refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG, "DpchEng" + job->sref + "Data", "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");

	for (unsigned int i = 0; i < srefs.size(); i++) {
		it = blks.find(srefs[i]);
		if (it != blks.end()) {
			dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::SUB, StrMod::lc(srefs[i]), VecWznmVVartype::VOID, 0, 0, 0, 0, it->second, 0, "", 0, "");
		} else {
			it = feds.find(srefs[i]);
			if (it != feds.end()) {
				dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::FEED, StrMod::uncap(srefs[i]), VecWznmVVartype::VOID, 0, 0, it->second, 0, 0, 0, "", 0, "");
			} else {
				it = rsts.find(srefs[i]);
				if (it != rsts.end()) {
					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refDpch, bitnum++, VecWznmVAMBlockItemBasetype::RST, StrMod::lc(srefs[i]), VecWznmVVartype::VOID, 0, 0, 0, it->second, 0, 0, "", 0, "");
				};
			};
		};
	};
};

void WznmGenJob::genJobQry(
			DbsWznm* dbswznm
			, const string Prjshort
			, WznmMQuery* qry
		) {
	vector<ubigint> refs;
	ubigint ref;

	WznmMJob* job = NULL;
	WznmMJob* supjob = NULL;

	WznmMPanel* pnl = NULL;

	ListWznmAMQueryClause qacs;
	WznmAMQueryClause* qac = NULL;

	ListWznmAMQueryOrder qaos;
	WznmAMQueryOrder* qao = NULL;

	bool listqry = false;

	unsigned int bitnum;

	ubigint refStatshr;
	ubigint refStatapp;
	ubigint refStgiac;

	uint cnt;

	string pnlqrypostfix;

	ostringstream str;
	string s;

	dbswznm->tblwznmmjob->insertNewRec(&job, VecWznmVMJobBasetype::QRY, qry->refWznmMVersion, VecWznmVMJobRefTbl::QRY, qry->ref, qry->sref, false, false, false, "");

	qry->refWznmMJob = job->ref;
	dbswznm->tblwznmmquery->updateRec(qry);

	// - query as source for dialogs
	dbswznm->loadRefsBySQL("SELECT refWznmMDialog FROM TblWznmRMDialogMQuery WHERE refWznmMQuery = " + to_string(qry->ref), false, refs);

	for (unsigned int j = 0; j < refs.size(); j++) {
		if (dbswznm->loadRefBySQL("SELECT refWznmMJob FROM TblWznmMDialog WHERE ref = " + to_string(refs[j]), ref))
					dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, ref, job->ref, "qry", false, VecWznmVRMJobMJobConstract::CRE);
	};

	// - query as source for panels
	dbswznm->loadRefsBySQL("SELECT refWznmMPanel FROM TblWznmRMPanelMQuery WHERE refWznmMQuery = " + to_string(qry->ref), false, refs);

	for (unsigned int j = 0; j < refs.size(); j++) {
		if (dbswznm->tblwznmmpanel->loadRecByRef(refs[j], &pnl)) {
			if (qry->sref.find(pnl->sref.substr(3)) == string::npos) {
				s = StrMod::lc(qry->sref);
			} else {
				s = StrMod::lc(qry->sref.substr(0, qry->sref.find(pnl->sref.substr(3))) + qry->sref.substr(qry->sref.find(pnl->sref.substr(3)) + pnl->sref.length()-3)); 
			};

			dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, pnl->refWznmMJob, job->ref, s, false, VecWznmVRMJobMJobConstract::CRE);
			if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) listqry = true;

			delete pnl;
		};
	};

	// - commands
	dbswznm->tblwznmamjobcmd->insertNewRec(NULL, job->ref, "rerun", "");
	dbswznm->tblwznmamjobcmd->insertNewRec(NULL, job->ref, "show", "");

	// - vectors

	// VecVOrd is taken care of in WznmGenSysvec

	// - blocks

	// StatShr {ntot} + (with Limofs) {jnumFirstload, nload}
	bitnum = 1;
	refStatshr = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::STAT, qry->refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG, "StatShr" + qry->sref, "");

	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatshr, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ntot", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "", 0, "");
	if (qry->Limofs) {
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatshr, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jnumFirstload", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "", 0, "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatshr, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "nload", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "", 0, "");
	};

	if (qry->Limofs) {
		// StatApp {firstcol, jnumFirstdisp, ncol, ndisp}
		bitnum = 1;
		refStatapp = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::STAT, qry->refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG, "StatApp" + qry->sref, "");

		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatapp, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "firstcol", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "1", 0, ""); // !
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatapp, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jnumFirstdisp", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "1", 0, ""); // !

		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMQuerycol WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND (ixWOccurrence & " + to_string(VecWznmWMQuerycolOccurrence::XML) + ") <> 0", cnt);
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatapp, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ncol", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, to_string(cnt), 0, ""); // !

		if (listqry) {
			dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatapp, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ndisp", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "25", 0, ""); // !
		} else {
			dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatapp, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ndisp", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "10", 0, ""); // !
		};
	};

	// StgIac {jnum, jnumFirstload, nload, <one ref/ix for each corr. qac> ; THIS HAS TO GO OUT - ELSE IT WOULD BE VISIBLE TO APP}
	dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND (ixVBasetype = " + to_string(VecWznmVAMQueryClauseBasetype::REF)
				+ " OR ixVBasetype = " + to_string(VecWznmVAMQueryClauseBasetype::IX) + ") ORDER BY qryNum ASC", false, qacs);
	
	bitnum = 1;
	refStgiac = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::STG, qry->refWznmMVersion, VecWznmVMBlockRefTbl::JOB, job->ref, VecWznmWScope::APP + VecWznmWScope::CMBENG + VecWznmWScope::ENG, VecWznmWScope::APP + VecWznmWScope::CMBENG + VecWznmWScope::ENG, "StgIac" + qry->sref, "");

	dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStgiac, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jnum", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "", 0, "");

	if (qry->Limofs) {
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStgiac, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jnumFirstload", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "1", 0, ""); // !
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStgiac, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "nload", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "100", 0, ""); // !
	};

	for (unsigned int i = 0; i < qacs.nodes.size(); i++) {
		qac = qacs.nodes[i];

		s = StrMod::findFirstPlh(qac->Clause, 0);
		if (s.length() > 0) {
			if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::REF) {
				dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStgiac, bitnum++, VecWznmVAMBlockItemBasetype::VAR, s, VecWznmVVartype::UBIGINT, 0, 0, 0, 0, 0, 0, "", 0, "");
			} else if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::IX) {
				dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStgiac, bitnum++, VecWznmVAMBlockItemBasetype::VAR, s, VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "", 0, "");
			};
		};
	};

	// - re-visit EngData dispatches of containing dialogs and panels
	dbswznm->loadRefsBySQL("SELECT supRefWznmMJob FROM TblWznmRMJobMJob WHERE subRefWznmMJob = " + to_string(job->ref), false, refs);

	for (unsigned int j = 0; j < refs.size(); j++) {
		if (dbswznm->tblwznmmjob->loadRecByRef(refs[j], &supjob)) {

			if (supjob->ixVBasetype == VecWznmVMJobBasetype::PNL) {
				pnlqrypostfix = getPnlqryPostfix(supjob->sref, qry->sref);

				// find AppData dispatch
				if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(supjob->ref) + " AND sref = 'DpchApp" + supjob->sref.substr(3) + "Data'", ref)) {
					dbswznm->executeQuery("UPDATE TblWznmAMBlockItem SET refWznmMBlock = " + to_string(refStgiac) + " WHERE blkRefWznmMBlock = " + to_string(ref) + " AND sref = 'stgiacqry" + pnlqrypostfix + "'");
				};

				// find EngData dispatch
				if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(supjob->ref) + " AND sref = 'DpchEng" + supjob->sref.substr(3) + "Data'", ref)) {
					dbswznm->executeQuery("UPDATE TblWznmAMBlockItem SET refWznmMBlock = " + to_string(refStatshr) + " WHERE blkRefWznmMBlock = " + to_string(ref) + " AND sref = 'statshrqry" + pnlqrypostfix + "'");
					dbswznm->executeQuery("UPDATE TblWznmAMBlockItem SET refWznmMBlock = " + to_string(refStgiac) + " WHERE blkRefWznmMBlock = " + to_string(ref) + " AND sref = 'stgiacqry" + pnlqrypostfix + "'");

					if (qry->Limofs) {
						dbswznm->executeQuery("UPDATE TblWznmAMBlockItem SET refWznmMBlock = " + to_string(refStatapp) + " WHERE blkRefWznmMBlock = " + to_string(ref) + " AND sref = 'statappqry" + pnlqrypostfix + "'");
					};
				};

			} else if (supjob->ixVBasetype == VecWznmVMJobBasetype::DLG) {
				// ... to be implemented for dialogs ...
			};

			delete supjob;
		};
	};

	delete job;
};

void WznmGenJob::genJobIex(
			DbsWznm* dbswznm
			, const string Prjshort
			, WznmMImpexpcplx* iex
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	vector<ubigint> refs;

	map<ubigint,string> iextits;

	WznmMJob* job = NULL;

	ListWznmMStage sges;
	WznmMStage* sge = NULL;

	ubigint refSgeIdle, refSgePrserr, refSgePrsdone, refSgeImperr, refSgeCltdone, refSgeDone;

	unsigned int sgenum = 1;

	string s;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (dbswznm->tblwznmjmimpexpcplxtitle->loadTitByIexLoc(iex->ref, refsLcl[i], s)) iextits[refsLcl[i]] = s;
		else iextits[refsLcl[i]] = iex->Title;
	};

	dbswznm->tblwznmmjob->insertNewRec(&job, VecWznmVMJobBasetype::IEX, iex->refWznmMVersion, VecWznmVMJobRefTbl::IEX, iex->ref, "Job" + Prjshort + "Iex" + StrMod::cap(iex->Short), false, false, false, "");

	iex->refWznmMJob = job->ref;
	dbswznm->tblwznmmimpexpcplx->updateRec(iex);

	// - jrj to dialogs
	dbswznm->loadRefsBySQL("SELECT refWznmMJob FROM TblWznmMDialog WHERE refIxVTbl = " + to_string(VecWznmVMDialogRefTbl::IEX) + " AND refUref = " + to_string(iex->ref), false, refs);

	for (unsigned int j = 0; j < refs.size(); j++) dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refs[j], job->ref, "iex", false, VecWznmVRMJobMJobConstract::CRE);

	// - stages {idle, parse, prserr, prsdone, import, imperr, reverse, collect, cltdone, export, done}
	refSgeIdle = dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum++, 0, "idle", 0, 0, 0, 0, "");

	// reverse order from here to allow for snx/fnx/enx
	sgenum = 11;

	refSgeDone = dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum--, 0, "done", 0, 0, 0, 0, "");

	dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum--, 0, "export", 0, refSgeDone, 0, 0, "");
	genJobIex_addSqk(dbswznm, sge, iextits, refLcl, refsLcl);

	refSgeCltdone = dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum--, 0, "cltdone", 0, 0, 0, 0, "");
	genJobIex_addSqk(dbswznm, sge, iextits, refLcl, refsLcl);

	dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum--, 0, "collect", 0, refSgeCltdone, 0, 0, "");
	genJobIex_addSqk(dbswznm, sge, iextits, refLcl, refsLcl);

	dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum--, 0, "reverse", 0, refSgeIdle, 0, 0, "");
	genJobIex_addSqk(dbswznm, sge, iextits, refLcl, refsLcl);

	refSgeImperr = dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::ERR, job->ref, sgenum--, 0, "imperr", 0, 0, 0, 0, "");

	dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum--, 0, "import", 0, refSgeDone, refSgeImperr, 0 , "");
	genJobIex_addSqk(dbswznm, sge, iextits, refLcl, refsLcl);

	refSgePrsdone = dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum--, 0, "prsdone", 0, 0, 0, 0, "");
	genJobIex_addSqk(dbswznm, sge, iextits, refLcl, refsLcl);

	refSgePrserr = dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::ERR, job->ref, sgenum--, 0, "prserr", 0, 0, 0, 0, "");

	dbswznm->tblwznmmstage->appendNewRecToRst(sges, &sge, VecWznmVMStageBasetype::OTHER, job->ref, sgenum--, 0, "parse", 0, refSgePrsdone, refSgePrserr, 0, "");
	genJobIex_addSqk(dbswznm, sge, iextits, refLcl, refsLcl);

	delete job;
};

void WznmGenJob::genJobIex_addSqk(
			DbsWznm* dbswznm
			, WznmMStage* sge
			, const map<ubigint,string>& iextits
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	WznmMSquawk* sqk = NULL;

	map<ubigint,string> tagTits;

	sge->refWznmMSquawk = dbswznm->tblwznmmsquawk->insertNewRec(&sqk, VecWznmVMSquawkRefTbl::SGE, sge->ref, 0, "", "");
	dbswznm->tblwznmmstage->updateRec(sge);

	Wznm::getTagtits(dbswznm, sge->sref, "iexsge", "", iextits, refLcl, refsLcl, tagTits, false);
	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		ref = dbswznm->tblwznmjmsquawktitle->insertNewRec(NULL, sge->refWznmMSquawk, refsLcl[i], tagTits[refsLcl[i]]);

		if (refsLcl[i] == refLcl) {
			sqk->refJTitle = ref;
			sqk->Title = tagTits[refsLcl[i]];

			dbswznm->tblwznmmsquawk->updateRec(sqk);
		};
	};
};

void WznmGenJob::genOpkvecblks(
			DbsWznm* dbswznm
			, WznmMOppack* opk
			, ListWznmMOp& ops
			, const ubigint refVecKls
			, uint& vitnumKls
			, const ubigint refLcl
		) {
	ubigint refVec;
	unsigned int vitnum;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	WznmMOp* op = NULL;

	ListWznmAMOppackInvarg invs;
	WznmAMOppackInvarg* inv = NULL;

	ListWznmAMOppackRetval rets;
	WznmAMOppackRetval* ret = NULL;

	map<ubigint,ubigint> convRefCs;

	ubigint refC;

	ubigint refBlk;
	unsigned int bitnum;

	// -- custom operation key list KlstKXxxxYyyyyZzzzzCustop
	refVec = dbswznm->tblwznmmvector->insertNewRec(NULL, VecWznmVMVectorBasetype::KLST, opk->refWznmMVersion, VecWznmVMVectorHkTbl::VOID, 0, 0, "KlstK" + opk->sref + "Custop", "", "noloc");
	dbswznm->tblwznmamvectortitle->insertNewRec(NULL, refVec, VecWznmVAMVectorTitleType::FULL, refLcl, opk->sref + " custom operations");

	// VecXxxxVKeylist entry
	dbswznm->tblwznmmvectoritem->insertNewRec(&vit, refVecKls, vitnumKls++, "KlstK" + opk->sref + "Custop", "", "", 0, opk->sref + " custom operations", "");
	vit->refJ = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refLcl, opk->sref + " custom operations", "");
	dbswznm->tblwznmmvectoritem->updateRec(vit);
	delete vit;

	vitnum = 1;

	for (unsigned int i = 0; i < ops.nodes.size(); i++) {
		op = ops.nodes[i];

		dbswznm->tblwznmmvectoritem->appendNewRecToRst(vits, &vit, refVec, vitnum++, op->sref, "", "", 0, op->Comment, "");
		
		if (op->Comment != "") {
			vit->refJ = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refLcl, op->Comment, "");
			dbswznm->tblwznmmvectoritem->updateRec(vit);
		};
	};

	// -- invocation dispatch
	dbswznm->tblwznmamoppackinvarg->loadRstByOpk(opk->ref, false, invs);

	refBlk = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, opk->refWznmMVersion, VecWznmVMBlockRefTbl::OPK, opk->ref, VecWznmWScope::OPENG,
				VecWznmWScope::ENG, "DpchInv" + opk->sref, "");
	bitnum = 1;

	// - default arguments
	refC = dbswznm->tblwznmcamblockitem->getNewRef();
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "oref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "srefKCustop", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");

	// - custom arguments
	convRefCs.clear();
	for (unsigned int j = 0; j < invs.nodes.size(); j++) {
		inv = invs.nodes[j];
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, convRefC(dbswznm, inv->refWznmCAMOppackInvarg, convRefCs), refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, inv->sref, inv->ixWznmVVartype, inv->refWznmMVector, 0, 0, 0, 0, 0, inv->Defval, inv->refWznmMVectoritem, ""); // !
	};

	// -- return dispatch
	dbswznm->tblwznmamoppackretval->loadRstByOpk(opk->ref, false, rets);
	if (rets.nodes.size() > 0) {
		bitnum = 1;
		refBlk = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, opk->refWznmMVersion, VecWznmVMBlockRefTbl::OPK, opk->ref, VecWznmWScope::ENG,
				VecWznmWScope::OPENG, "DpchRet" + opk->sref, "");

		// - default arguments
		refC = dbswznm->tblwznmcamblockitem->getNewRef();
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "oref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ixOpVOpres", VecWznmVVartype::VECSREF, 0, 0, 0, 0, 0, 0, "", 0, "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "pdone", VecWznmVVartype::UTINYINT, 0, 0, 0, 0, 0, 0, "", 0, "");

		// - custom arguments
		convRefCs.clear();
		for (unsigned int j = 0; j < rets.nodes.size(); j++) {
			ret = rets.nodes[j];
			dbswznm->tblwznmamblockitem->insertNewRec(NULL, convRefC(dbswznm, ret->refWznmCAMOppackRetval, convRefCs), refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, ret->sref, ret->ixWznmVVartype, ret->refWznmMVector, 0, 0, 0, 0, 0, "", 0, "");
		};
	};
};

void WznmGenJob::genOpblks(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, WznmMOp* op
		) {
	ListWznmAMOpInvarg invs;
	WznmAMOpInvarg* inv = NULL;

	ListWznmAMOpRetval rets;
	WznmAMOpRetval* ret = NULL;

	map<ubigint,ubigint> convRefCs;

	ubigint refC;

	ubigint refBlk;

	unsigned int bitnum;

	// -- invocation dispatch
	dbswznm->tblwznmamopinvarg->loadRstByOpx(op->ref, false, invs);

	bitnum = 1;
	refBlk = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, refWznmMVersion, VecWznmVMBlockRefTbl::OPX, op->ref, VecWznmWScope::OPENG,
				VecWznmWScope::ENG, "DpchInv" + op->sref, "");

	// - default arguments
	refC = dbswznm->tblwznmcamblockitem->getNewRef();
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "oref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
	dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");

	// - custom arguments
	convRefCs.clear();
	for (unsigned int j = 0; j < invs.nodes.size(); j++) {
		inv = invs.nodes[j];
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, convRefC(dbswznm, inv->refWznmCAMOpInvarg, convRefCs), refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, inv->sref, inv->ixWznmVVartype, inv->refWznmMVector, 0, 0, 0, 0, 0, inv->Defval, inv->refWznmMVectoritem, ""); // !
	};

	// -- return dispatch
	dbswznm->tblwznmamopretval->loadRstByOpx(op->ref, false, rets);
	if (rets.nodes.size() > 0) {
		bitnum = 1;
		refBlk = dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, refWznmMVersion, VecWznmVMBlockRefTbl::OPX, op->ref, VecWznmWScope::ENG,
				VecWznmWScope::OPENG, "DpchRet" + op->sref, "");

		// - default arguments
		refC = dbswznm->tblwznmcamblockitem->getNewRef();
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "oref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref", VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ixOpVOpres", VecWznmVVartype::VECSREF, 0, 0, 0, 0, 0, 0, "", 0, "");
		dbswznm->tblwznmamblockitem->insertNewRec(NULL, refC, refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "pdone", VecWznmVVartype::UTINYINT, 0, 0, 0, 0, 0, 0, "", 0, "");

		// - custom arguments
		convRefCs.clear();
		for (unsigned int j = 0; j < rets.nodes.size(); j++) {
			ret = rets.nodes[j];
			dbswznm->tblwznmamblockitem->insertNewRec(NULL, convRefC(dbswznm, ret->refWznmCAMOpRetval, convRefCs), refBlk, bitnum++, VecWznmVAMBlockItemBasetype::VAR, ret->sref, ret->ixWznmVVartype, ret->refWznmMVector, 0, 0, 0, 0, 0, "", 0, "");
		};
	};
};

string WznmGenJob::getPnlqryPostfix(
			const string& pnlsref
			, const string& qrysref
		) {
	string retval;

	if (qrysref.substr(3).compare(pnlsref.substr(3)) == 0) {
		retval = "";
	} else if (qrysref.find(pnlsref.substr(3)) != string::npos) {
		retval = StrMod::lc(qrysref.substr(qrysref.find(pnlsref.substr(3)) + pnlsref.length() - 3));
	} else {
		retval = StrMod::lc(qrysref.substr(3+4));
	};

	return retval;
};

ubigint WznmGenJob::convRefC(
			DbsWznm* dbswznm
			, const ubigint refC
			, map<ubigint,ubigint>& convRefCs
		) {
	// {op/opk}A{inv/ret} -> blkAitm
	if (refC == 0) return 0;

	auto it = convRefCs.find(refC);
	if (it != convRefCs.end()) return it->second;

	return(convRefCs[refC] = dbswznm->tblwznmcamblockitem->getNewRef());
};
// IP cust --- IEND



