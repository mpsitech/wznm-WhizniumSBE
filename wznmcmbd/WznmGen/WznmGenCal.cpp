/**
	* \file WznmGenCal.cpp
	* Wznm operation processor - generate calls (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmGenCal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmGen;

/******************************************************************************
 namespace WznmGenCal
 ******************************************************************************/

DpchRetWznm* WznmGenCal::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmGenCal* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	set<ubigint> unqrefs;

	ubigint refTbl;

	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;
	WznmMTable* tbl2 = NULL;

	ListWznmMCheck chks;
	WznmMCheck* chk = NULL;

	ubigint refCal;

	ubigint refRoot;
	ubigint refSess;
	ubigint refM2msess;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;
	WznmMTablecol* tco2 = NULL;

	uint invIxWznmWArgtype;

	vector<ubigint> refsTbl;
	vector<ubigint> refsSbs;
	vector<ubigint> refsRel;
	vector<ubigint> refsCar;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	vector<ubigint> refsPnljob;

	vector<ubigint> refsQryjob;
	ubigint refQryjob;

	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;
	WznmMRelation* rel2 = NULL;

	string s;

	ubigint cnt;

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE ixVBasetype = " + to_string(VecWznmVMJobBasetype::ROOT) + " AND refWznmMVersion = " + to_string(refWznmMVersion), refRoot);
	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS) + " AND sref = 'Sess" + Prjshort + "' AND refWznmMVersion = " + to_string(refWznmMVersion), refSess);

	refM2msess = 0;
	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS) + " AND sref = 'M2msess" + Prjshort + "' AND refWznmMVersion = " + to_string(refWznmMVersion), refM2msess);

	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

	// --- standard calls (skip the trigger part, listening jobs only)

	if (refM2msess != 0) {
		// -- CallXxxxAccess (triggered in M2M interface, listened to by M2M session as self ; inv: ix=ixFeatgroup, sref=srefIxFeature ; ret: ix=ixAcc)
		refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, VecWznmWArgtype::IX + VecWznmWArgtype::SREF,
					VecWznmWArgtype::IX, "Call" + Prjshort + "Access", "");

		dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refM2msess, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);
	};

	// -- CallXxxxClaimChg (triggered by Clisrv jobs)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0, 0, "Call" + Prjshort + "ClaimChg", "");

	// -- CallXxxxCrdActive (triggered below session, listened to by session down the job tree ; inv: ix=ixCard ; ret: ix=ixPre/0)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, VecWznmWArgtype::IX,
				VecWznmWArgtype::IX, "Call" + Prjshort + "CrdActive", "");

	dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refSess, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxCrdClose (triggered by cards, listened to by session down the job tree ; inv: ix=ixCrd)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, VecWznmWArgtype::IX,
				0, "Call" + Prjshort + "CrdClose", "");

	dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refSess, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxCrdOpen (triggered below session, listened to by session down the job tree ; inv: ix=ixPre, ref=preUref, sref=srefIxCard, intval=ref ; ret: ref=jref/0)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::REF + VecWznmWArgtype::SREF + VecWznmWArgtype::INTVAL,
				VecWznmWArgtype::REF, "Call" + Prjshort + "CrdOpen", "");

	dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refSess, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxDatChg (custom)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, VecWznmWArgtype::IX + VecWznmWArgtype::SREF,
				0, "Call" + Prjshort + "DatChg", "");

	// -- CallXxxxDlgClose (triggered by dialogs, listened to by card to immediate subs)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0,
				0, "Call" + Prjshort + "DlgClose", "");

	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMJob WHERE ixVBasetype = " + to_string(VecWznmVMJobBasetype::CRD) + " AND refWznmMVersion = " + to_string(refWznmMVersion), false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refs[i], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::IMM, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxLog (triggered below session, listened to by session down the job tree ; inv: ix=ixPre, ref=preUref, sref=srefIxCard, intval=ref)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::REF + VecWznmWArgtype::SREF + VecWznmWArgtype::INTVAL,
				0, "Call" + Prjshort + "Log", "");

	dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refSess, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxLogout (triggered below sessions using respective session jref, listened to by root to immediate subs)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, VecWznmWArgtype::BOOLVAL,
				0, "Call" + Prjshort + "Logout", "");

	dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refRoot, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::IMM, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxMonstatChg (custom)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0,
				0, "Call" + Prjshort + "MonstatChg", "");

	// -- CallXxxxNodeChg (custom)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0,
				0, "Call" + Prjshort + "NodeChg", "");

	// -- CallXxxxRecaccess (triggered below session, listened to by session down the job tree ; inv: ix=ixMtb, ref=ref ; ret: ix=ixAcc)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, VecWznmWArgtype::IX + VecWznmWArgtype::REF,
				VecWznmWArgtype::IX, "Call" + Prjshort + "Recaccess", "");

	dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refSess, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxSgeChg (custom)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0,
				0, "Call" + Prjshort + "SgeChg", "");

	// -- CallXxxxStatChg (generally listened to down the job tree)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0,
				0, "Call" + Prjshort + "StatChg", "");

	// all cards having a pnlrec panel listen to its state change
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMJob WHERE ixVBasetype = " + to_string(VecWznmVMJobBasetype::PNL) + " AND refWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND sref LIKE 'Pnl%Rec'", false, refs);

	for (unsigned int i = 0; i < refs.size(); i++) {
		if (dbswznm->loadRefBySQL("SELECT supRefWznmMJob FROM TblWznmRMJobMJob WHERE subRefWznmMJob = " + to_string(refs[i]), ref))
					dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, ref, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::IMM, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);
	};

	// all panels having a qry listen to its/their state change(s)
	dbswznm->loadRefsBySQL("SELECT DISTINCT TblWznmRMJobMJob.supRefWznmMJob FROM TblWznmRMJobMJob, TblWznmMJob WHERE TblWznmMJob.ref = TblWznmRMJobMJob.subRefWznmMJob AND TblWznmMJob.ixVBasetype = "
				+ to_string(VecWznmVMJobBasetype::QRY) + " AND TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion), false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refs[i], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::IMM, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxShrdatChg (custom)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, VecWznmWArgtype::IX + VecWznmWArgtype::SREF,
				0, "Call" + Prjshort + "ShrdatChg", "");

	// -- CallXxxxStgChg (custom)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0,
				0, "Call" + Prjshort + "StgChg", "");

	// -- CallXxxxStubChg (custom)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0,
				0, "Call" + Prjshort + "StubChg", "");

	// all query jobs
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMJob WHERE ixVBasetype = " + to_string(VecWznmVMJobBasetype::QRY) + " AND refWznmMVersion = " + to_string(refWznmMVersion), false, refs);

	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refs[i], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::SELF, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxSuspsess (triggered below sessions using respective session jref, listened to by root to immediate subs)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::OTHER, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0, 0,
				0, "Call" + Prjshort + "Suspsess", "");

	dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refRoot, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::IMM, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// -- CallXxxxIxPreSet(ix=ix, sref=srefIxPre, boolval=set/unset ; unset by ix=0)
	dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::SREF, 0, "Call" + Prjshort + "IxPreSet", "");

	// -- CallXxxxRefPreSet (listened to by session to immediate subs, and by card down the job tree ; inv: ix=ixPre, ref=ref ; unset by ref=0)
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::REF, 0, "Call" + Prjshort + "RefPreSet", "");

	// preliminary: should be IMM ... used to be SPEC
	dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refSess, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS)) {
			dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, car->refWznmMJob, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);
		};
	};

	// -- CallXxxxRefsPreSet(ix=ixPre, refs=refs ; unset by empty refs)
	dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::REFS, 0, "Call" + Prjshort + "RefsPreSet", "");

	// -- CallXxxxSrefPreSet(ix=ixPre, sref=sref ; unset by sref="")
	dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::SREF, 0, "Call" + Prjshort + "SrefPreSet", "");

	// -- CallXxxxIntvalPreSet(ix=ixPre, intval=intval ; unset by intval=...)
	dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::INTVAL, 0, "Call" + Prjshort + "IntvalPreSet", "");

	// -- CallXxxxDblvalPreSet(ix=ixPre, dblval=dblval ; unset by dblval=...)
	dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::DBLVAL, 0, "Call" + Prjshort + "DblvalPreSet", "");

	// -- CallXxxxBoolvalPreSet(ix=ixPre, boolval=true/false ; unset by boolval=false)
	dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::BOOLVAL, 0, "Call" + Prjshort + "BoolvalPreSet", "");

	// -- CallXxxxTxtvalPreSet(ix=ixPre, txtval=txtval ; unset by txtval="")
	dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::VOID, 0,
				VecWznmWArgtype::IX + VecWznmWArgtype::TXTVAL, 0, "Call" + Prjshort + "TxtvalPreSet", "");

	// --- calls derived from checks
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, tbls);

	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		dbswznm->tblwznmmcheck->loadRstBySQL("SELECT * FROM TblWznmMCheck WHERE refWznmMTable = " + to_string(tbl->ref) + " ORDER BY sref ASC", false, chks);

		if (chks.nodes.size() > 0) {
			refsPnljob.clear();

			if (tbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) {
				getRefsCarByTbl(dbswznm, cars, tbl->ref, refsCar);
				getRefsPnlrecjobByCars(dbswznm, refsCar, refsPnljob);
				getRefsPnldetailjobByCars(dbswznm, refsCar, refsPnljob);

			} else if (tbl->ixVBasetype == VecWznmVMTableBasetype::AUX) {
				// identify the corresponding relations and spec sub-relations
				refsRel.resize(0);
				dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::AUX) + " AND toRefWznmMTable = " + to_string(tbl->ref), true, refsRel);

				for (unsigned int j = 0; j < refsRel.size(); j++) dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(refsRel[j]) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SPEC), true, refsRel);
				for (unsigned int j = 0; j < refsRel.size(); j++) dbswznm->loadRefsBySQL("SELECT refWznmMJob FROM TblWznmMPanel WHERE refIxVTbl = " + to_string(VecWznmVMPanelRefTbl::REL) + " AND refUref = " + to_string(refsRel[j]), true, refsPnljob);

			} else if (tbl->ixVBasetype == VecWznmVMTableBasetype::REL) {
				// identify the corresponding to1n and from1n relations and spec sub-relations
				refsRel.resize(0);

				dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMRelation WHERE supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N) + " AND toRefWznmMTable = " + to_string(tbl->ref), true, refsRel);
				dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMRelation WHERE supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::TO1N) + " AND toRefWznmMTable = " + to_string(tbl->ref), true, refsRel);
				for (unsigned int j = 0; j < refsRel.size(); j++) dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(refsRel[j]) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SPEC), true, refsRel);

				for (unsigned int j = 0; j < refsRel.size(); j++) dbswznm->loadRefsBySQL("SELECT refWznmMJob FROM TblWznmMPanel WHERE refIxVTbl = " + to_string(VecWznmVMPanelRefTbl::REL) + " AND refUref = " + to_string(refsRel[j]), true, refsPnljob);
			};

			for (unsigned int j = 0; j < chks.nodes.size(); j++) {
				chk = chks.nodes[j];

				invIxWznmWArgtype = 0;
				
				if (chk->ixVBasetype == VecWznmVMCheckBasetype::LEAF) {
				} else if (chk->ixVBasetype == VecWznmVMCheckBasetype::SBS) {
					invIxWznmWArgtype = VecWznmWArgtype::IX;
				} else {
					// determine argument type based on table column type
					if (dbswznm->tblwznmmtablecol->loadRecByRef(chk->refWznmMTablecol, &tco)) {
						if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF)) {
							invIxWznmWArgtype = VecWznmWArgtype::REF;
						} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
							invIxWznmWArgtype = VecWznmWArgtype::IX;
						} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF)) {
							invIxWznmWArgtype = VecWznmWArgtype::SREF;
						} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
							invIxWznmWArgtype = VecWznmWArgtype::BOOLVAL;
						};

						delete tco;
					};
				};

				refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::CHK, refWznmMVersion, VecWznmVMCallRefTbl::CHK, chk->ref, invIxWznmWArgtype,
							VecWznmWArgtype::BOOLVAL, "Call" + Prjshort + StrMod::cap(tbl->Short) + "." + chk->sref, "");

				chk->refWznmMCall = refCal;
				dbswznm->tblwznmmcheck->updateRec(chk);

				// make each panel identified before a listener
				for (unsigned int k = 0; k < refsPnljob.size(); k++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsPnljob[k], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);
			};
		};
	};

	// --- calls derived from presettings
/// CHECK why this is commented out ?!
/*
	dbswznm->tblwznmmpreset->loadRstByVer(refWznmMVersion, false, psts);

	for (unsigned int i = 0; i < psts.nodes.size(); i++) {
		pst = psts.nodes[i];

		if (pst->refIxVTbl != VecWznmVMPresetRefTbl::VOID) {
			// exclude GRP, OWN, SES, JREFSESS presettings

			// ex.: PreXxxxRefLoc -> CallXxxxPreRefLoc
			s = "Call" + Prjshort + "Pre" + pst->sref.substr(pst->sref.find(Prjshort) + Prjshort.length());
			refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::PSTSET, refWznmMVersion, VecWznmVMCallRefTbl::PST, pst->ref, pst->ixWznmWArgtype,
						0, s, "");

			pst->refWznmMCall = refCal;
			dbswznm->tblwznmmpreset->updateRec(pst);

			if ((pst->ixVScope == VecWznmVMPresetScope::SESS) || (pst->ixVScope == VecWznmVMPresetScope::CAR)) {
				if (pst->ixVScope == VecWznmVMPresetScope::SESS) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refSess, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

				refsCarjob.resize(0);

				if ((pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) || (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS)) {
					// identify cards which display the table's/subset's data

					refsTbl.resize(0);
					refsSbs.resize(0);

					if (pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) refsTbl.push_back(pst->refUref);
					else if (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS) refsSbs.push_back(pst->refUref);
					
					// look at the preset's table and look for all frRefWznmMTables where it is a inc/u1nsubinc
					if (pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) {
						sqlstr.str(""); sqlstr << "SELECT frRefWznmMTable FROM TblWznmMRelation WHERE ixVBasetype = " << VecWznmVMRelationBasetype::INC
									<< " AND toRefWznmMTable = " << pst->refUref;
						dbswznm->loadRefsBySQL(sqlstr.str(), true, refsTbl);
						sqlstr.str(""); sqlstr << "SELECT frRefWznmMTable FROM TblWznmMRelation WHERE ixVBasetype = " << VecWznmVMRelationBasetype::U1NSUBINC
									<< " AND toRefWznmMTable = " << pst->refUref;
						dbswznm->loadRefsBySQL(sqlstr.str(), true, refsTbl);
						
					} else if (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS) {
						sqlstr.str(""); sqlstr << "SELECT refWznmMTable FROM TblWznmMSubset WHERE ref = " << pst->refUref;
						if (dbswznm->loadRefBySQL(sqlstr.str(), ref)) {
							sqlstr.str(""); sqlstr << "SELECT frRefWznmMTable FROM TblWznmMRelation WHERE ixVBasetype = " << VecWznmVMRelationBasetype::INC
										<< " AND toRefWznmMTable = " << ref;
							dbswznm->loadRefsBySQL(sqlstr.str(), true, refsTbl);
							sqlstr.str(""); sqlstr << "SELECT frRefWznmMTable FROM TblWznmMRelation WHERE ixVBasetype = " << VecWznmVMRelationBasetype::U1NSUBINC
										<< " AND toRefWznmMTable = " << ref;
							dbswznm->loadRefsBySQL(sqlstr.str(), true, refsTbl);
						};
					};

					for (unsigned int j = 0; j < refsTbl.size(); j++) {
						sqlstr.str(""); sqlstr << "SELECT ref FROM TblWznmMSubset WHERE refWznmMTable = " << refsTbl[j];
						dbswznm->loadRefsBySQL(sqlstr.str(), true, refsSbs);
					};

					for (unsigned int j = 0; j < refsTbl.size(); j++) {
						sqlstr.str(""); sqlstr << "SELECT refWznmMJob FROM TblWznmMCard WHERE refIxVTbl = " << VecWznmVMCardRefTbl::TBL << " AND refUref = "
									<< refsTbl[j];
						dbswznm->loadRefsBySQL(sqlstr.str(), true, refsCarjob);
					};

					for (unsigned int j = 0; j < refsSbs.size(); j++) {
						sqlstr.str(""); sqlstr << "SELECT refWznmMJob FROM TblWznmMCard WHERE refIxVTbl = " << VecWznmVMCardRefTbl::SBS << " AND refUref = "
									<< refsSbs[j];
						dbswznm->loadRefsBySQL(sqlstr.str(), true, refsCarjob);
					};
				};

				// make each card identified before a listener
				for (unsigned int k = 0; k < refsCarjob.size(); k++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsCarjob[k], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::TREE, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

			} else if (pst->ixVScope == VecWznmVMPresetScope::PNL) {
				// ...
			};
		};
	};
*/

	// --- calls for record insert/update/remove

	// -- not relation-based
	
	// - main tables
	dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::MAIN, refWznmMVersion, false, tbls);

	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		getRefsQrylistjobByTbl(dbswznm, tbl->ref, refsQryjob);

		refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl->ref, 0, 0, "Call" + Prjshort + StrMod::cap(tbl->Short) + "Mod", "");

		// queries of list panels are listening
		for (unsigned int j = 0; j < refsQryjob.size(); j++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsQryjob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

		refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::RECUPD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl->ref, VecWznmWArgtype::REF, 0, "Call" + Prjshort + StrMod::cap(tbl->Short) + "Upd.refEq", "");

		// queries of list panels, and all applicable record and detail panels are listening ; in addition, stub's
		for (unsigned int j = 0; j < refsQryjob.size(); j++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsQryjob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

		getRefsCarByTbl(dbswznm, cars, tbl->ref, refsCar);
		refsPnljob.clear();
		getRefsPnlrecjobByCars(dbswznm, refsCar, refsPnljob);
		for (unsigned int j = 0; j < refsPnljob.size(); j++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsPnljob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

		refsPnljob.clear();
		getRefsPnldetailjobByCars(dbswznm, refsCar, refsPnljob);
		for (unsigned int j = 0; j < refsPnljob.size(); j++) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsPnljob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

		dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMStub WHERE refWznmMTable = " + to_string(tbl->ref), false, refs);
		for (unsigned int j = 0; j < refs.size(); j++) dbswznm->tblwznmrmcallmstub->insertNewRec(NULL, refCal, refs[j]);
	};

	// - keylist key
	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "AVKeylistKey'", refTbl);

	// record-specific
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, refTbl, VecWznmWArgtype::IX + VecWznmWArgtype::REF + VecWznmWArgtype::SREF, 0,
				"Call" + Prjshort + "KlsAkeyMod.klsMtbUrfEq", "");

	// queries of klst panels and detail panels containing corresponding controls are listening
	dbswznm->loadRefsBySQL("SELECT refWznmMJob FROM TblWznmMQuery WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND refWznmMTable = " + to_string(refTbl), false, refsQryjob);
	for (unsigned int i = 0; i < refsQryjob.size(); i++)
				dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsQryjob[i], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ix,ref,sref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	refsPnljob.clear();

	dbswznm->tblwznmmtablecol->loadRstBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMTable WHERE TblWznmMTablecol.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::KLREF)
				+ " AND TblWznmMTablecol.tblRefWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion), false, tcos);

	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if ( (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) {
			dbswznm->loadRefBySQL("SELECT COUNT(ref) FROM TblWznmRMTableMVector WHERE refWznmMVector = " + to_string(tco->fctUref), cnt);

			if (cnt > 0) {
				dbswznm->loadRefsBySQL("SELECT TblWznmMPanel.refWznmMJob FROM TblWznmMControl, TblWznmMPanel WHERE TblWznmMControl.refIxVTbl = " + to_string(VecWznmVMControlRefTbl::TCO)
							+ " AND TblWznmMControl.refUref = " + to_string(tco->ref) + " AND TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND TblWznmMControl.hkUref = TblWznmMPanel.ref AND TblWznmMPanel.ixVBasetype = "
							+ to_string(VecWznmVMPanelBasetype::RECFORM) + " AND TblWznmMPanel.sref LIKE '%Detail'", true, refsPnljob);
			};
		};
	};

	unqrefs.clear();
	for (unsigned int i = 0; i < refsPnljob.size(); i++) unqrefs.insert(refsPnljob[i]);
	
	for (set<ubigint>::iterator it = unqrefs.begin(); it != unqrefs.end(); it++)
				dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, *it, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// not record-specific
	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, refTbl, VecWznmWArgtype::IX, 0, "Call" + Prjshort + "KlsAkeyMod.klsEq", "");

	// detail panels containing corresponding controls are listening
	refsPnljob.clear();

	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if ( (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) {
			dbswznm->loadRefBySQL("SELECT COUNT(ref) FROM TblWznmRMTableMVector WHERE refWznmMVector = " + to_string(tco->fctUref), cnt);

			if (cnt == 0) {
				dbswznm->loadRefsBySQL("SELECT TblWznmMPanel.refWznmMJob FROM TblWznmMControl, TblWznmMPanel WHERE TblWznmMControl.refIxVTbl = " + to_string(VecWznmVMControlRefTbl::TCO)
							+ " AND TblWznmMControl.refUref = " + to_string(tco->ref) + " AND TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND TblWznmMControl.hkUref = TblWznmMPanel.ref AND TblWznmMPanel.ixVBasetype = "
							+ to_string(VecWznmVMPanelBasetype::RECFORM) + " AND TblWznmMPanel.sref LIKE '%Detail'", true, refsPnljob);
			};
		};
	};

	unqrefs.clear();
	for (unsigned int i = 0; i < refsPnljob.size(); i++) unqrefs.insert(refsPnljob[i]);
	
	for (set<ubigint>::iterator it = unqrefs.begin(); it != unqrefs.end(); it++)
				dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, *it, 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	// - history
	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "HistRMUserUniversal'", refTbl);

	refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, refTbl, VecWznmWArgtype::IX + VecWznmWArgtype::REF, 0,
				"Call" + Prjshort + "HusrRunvMod.crdUsrEq", "");

	// nav panels referring to at least one crdtbl are listening
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND refIxVTbl = " + to_string(VecWznmVMJobRefTbl::PNL)
				+ " AND sref LIKE 'Pnl" + Prjshort + "Nav%'", false, refsPnljob);

	for (unsigned int i = 0; i < refsPnljob.size(); i++) {
		dbswznm->loadRefBySQL("SELECT COUNT(TblWznmMControl.ref) FROM TblWznmMControl, TblWznmMPanel, TblWznmMJob WHERE TblWznmMControl.ixVBasetype = " + to_string(VecWznmVMControlBasetype::LST)
					+ " AND TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND TblWznmMControl.hkUref = TblWznmMPanel.ref AND TblWznmMPanel.ref = TblWznmMJob.refUref AND TblWznmMJob.ref ="
					+ to_string(refsPnljob[i]), cnt);

		if (cnt > 0) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsPnljob[i], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);
	};

	// -- relation-based
	
	// - aux
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::AUX), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &tbl)) {

			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND tblRefWznmMTable = " + to_string(tbl->ref)
						+ " AND refWznmMRelation = " + to_string(rel->ref), &tco)) {

				// ex. CallBrlyPrsAdetMod.prsEq
				refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl->ref, VecWznmWArgtype::REF, 0,
							"Call" + Prjshort + StrMod::cap(tbl->Short) + "Mod." + tco->Short + "Eq", "");

				// queries of panels corresponding to relation are listening
				getRefsQryjobByRel(dbswznm, tbl->ref, rel->ref, refsQryjob);
				for (unsigned int j = 0; j < refsQryjob.size(); j++)
							dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsQryjob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

				delete tco;
			};

			delete tbl;
		};
	};

	// - jump
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::J), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl)) {
			if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &tbl2)) {
				// ex. CallBrlyRegJMod.regEq
				refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl2->ref, VecWznmWArgtype::REF, 0,
							"Call" + Prjshort + StrMod::cap(tbl2->Short) + "Mod." + tbl->Short + "Eq", "");

				// all applicable detail panels are listening
				refsPnljob.clear();

				getRefsCarByTbl(dbswznm, cars, tbl->ref, refsCar);
				getRefsPnldetailjobByCars(dbswznm, refsCar, refsPnljob);
				for (unsigned int j = 0; j < refsPnljob.size(); j++)
							dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsPnljob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

				delete tbl2;
			};
		
			delete tbl;
		};
	};

	// - cluster
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::CLUST), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &tbl)) {

			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND tblRefWznmMTable = " + to_string(tbl->ref)
						+ " AND refWznmMRelation = " + to_string(rel->ref), &tco)) {

				// ex. CallBrlyLegMod.cluEq
				refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl->ref, VecWznmWArgtype::REF, 0,
							"Call" + Prjshort + StrMod::cap(tbl->Short) + "Mod." + tco->Short + "Eq", "");

				// all applicable detail panels are listening
				refsPnljob.clear();

				getRefsCarByTbl(dbswznm, cars, tbl->ref, refsCar);
				getRefsPnldetailjobByCars(dbswznm, refsCar, refsPnljob);
				for (unsigned int j = 0; j < refsPnljob.size(); j++)
							dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsPnljob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

				delete tco;
			};

			delete tbl;
		};
	};

	// - 1n, h1n, l1n
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1N)
				+ " AND supRefWznmMRelation = 0", false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::H1N)
				+ " AND supRefWznmMRelation = 0", true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::L1N)
				+ " AND supRefWznmMRelation = 0", true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &tbl)) {

			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND tblRefWznmMTable = " + to_string(tbl->ref)
						+ " AND refWznmMRelation = " + to_string(rel->ref), &tco)) {

				// ex. CallBrlyFltMod.ttbEq
				refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl->ref, VecWznmWArgtype::REF, 0,
							"Call" + Prjshort + StrMod::cap(tbl->Short) + "Mod." + tco->Short + "Eq", "");

				// queries of panels corresponding to relation are listening
				getRefsQryjobByRel(dbswznm, tbl->ref, rel->ref, refsQryjob);
				for (unsigned int j = 0; j < refsQryjob.size(); j++)
							dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsQryjob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

				delete tco;
			};

			delete tbl;
		};
	};

	// - u1n, lu1n
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::U1N)
				+ " AND supRefWznmMRelation = 0", false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::LU1N)
				+ " AND supRefWznmMRelation = 0", true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &tbl)) {

			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND tblRefWznmMTable = " + to_string(tbl->ref)
						+ " AND refWznmMRelation = " + to_string(rel->ref) + " AND sref LIKE '%VTbl'", &tco)) {

				if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND tblRefWznmMTable = " + to_string(tbl->ref)
							+ " AND refWznmMRelation = " + to_string(rel->ref), &tco2)) {

					// ex. CallWznmVecMod.hktHkuEq
					refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl->ref, VecWznmWArgtype::IX + VecWznmWArgtype::REF, 0,
								"Call" + Prjshort + StrMod::cap(tbl->Short) + "Mod." + tco->Short + StrMod::cap(tco2->Short) + "Eq", "");

					// queries of panels corresponding so sub-relations are listening
					getRefsQryjobBySuprel(dbswznm, tbl->ref, rel->ref, refsQryjob);
					for (unsigned int j = 0; j < refsQryjob.size(); j++)
								dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsQryjob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ix,ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

					delete tco2;
				};

				delete tco;
			};

			delete tbl;
		};
	};

	// - mn, lmn
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::MN)
				+ " AND supRefWznmMRelation = 0", false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::LMN)
				+ " AND supRefWznmMRelation = 0", true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmtable->loadRecByRef(rel->refWznmMTable, &tbl)) {

			// "from" sub-relation
			if (dbswznm->tblwznmmrelation->loadRecBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N), &rel2)) {

				if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND tblRefWznmMTable = " + to_string(tbl->ref)
							+ " AND refWznmMRelation = " + to_string(rel2->ref), &tco)) {

					// ex. CallBrlyFltRlocMod.fltEq
					refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl->ref, VecWznmWArgtype::REF, 0,
								"Call" + Prjshort + StrMod::cap(tbl->Short) + "Mod." + tco->Short + "Eq", "");

					// queries of panels corresponding to relation are listening
					getRefsQryjobByRel(dbswznm, tbl->ref, rel2->ref, refsQryjob);
					for (unsigned int j = 0; j < refsQryjob.size(); j++)
								dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsQryjob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

					delete tco;
				};

				delete rel2;
			};

			// "to" sub-relation
			if (dbswznm->tblwznmmrelation->loadRecBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::TO1N), &rel2)) {

				if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND tblRefWznmMTable = " + to_string(tbl->ref)
							+ " AND refWznmMRelation = " + to_string(rel2->ref), &tco)) {

					// ex. CallBrlyFltRlocMod.locEq
					refCal = dbswznm->tblwznmmcall->insertNewRec(NULL, VecWznmVMCallBasetype::TBLMOD, refWznmMVersion, VecWznmVMCallRefTbl::TBL, tbl->ref, VecWznmWArgtype::REF, 0,
								"Call" + Prjshort + StrMod::cap(tbl->Short) + "Mod." + tco->Short + "Eq", "");

					// queries of panels corresponding to relation are listening
					getRefsQryjobByRel(dbswznm, tbl->ref, rel2->ref, refsQryjob);
					for (unsigned int j = 0; j < refsQryjob.size(); j++)
								dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refsQryjob[j], 0, refCal, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::ALL, "", "ref", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

					delete tco;
				};

				delete rel2;
			};

			delete tbl;
		};
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmGenCal::getRefsCarByTbl(
			DbsWznm* dbswznm
			, ListWznmMCard& cars
			, const ubigint refTbl
			, vector<ubigint>& refsCar
		) {
	ubigint ref;

	WznmMCard* car = NULL;

	ListWznmMTable inctbls;
	WznmMTable* inctbl = NULL;
	map<ubigint,string> incconds;
	map<ubigint,string> incsbsconds;

	refsCar.clear();

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		// card table and subset
		if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) && (car->refUref == refTbl)) {
			refsCar.push_back(car->ref);
			continue;
		};

		if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
			if (dbswznm->loadRefBySQL("SELECT refWznmMTable FROM TblWznmMSubset WHERE ref = " + to_string(car->refUref), ref)) {
				if (ref == refTbl) {
					refsCar.push_back(car->ref);
					continue;
				};
			};
		};
		
		// via included tables
		Wznm::getCarincs(dbswznm, car, inctbls, incconds, incsbsconds);
		for (unsigned int j = 0; j < inctbls.nodes.size(); j++) {
			inctbl = inctbls.nodes[j];

			if (inctbl->ref == refTbl) {
				refsCar.push_back(car->ref);
				break;
			};
		};
	};
};

void WznmGenCal::getRefsQrylistjobByTbl(
			DbsWznm* dbswznm
			, const ubigint refTbl
			, vector<ubigint>& refsQryjob
		) {
	dbswznm->loadRefsBySQL("SELECT TblWznmMQuery.refWznmMJob FROM TblWznmMQuery, TblWznmRMPanelMQuery, TblWznmMPanel WHERE TblWznmMQuery.refWznmMTable = " + to_string(refTbl)
				+ " AND TblWznmMQuery.ref = TblWznmRMPanelMQuery.refWznmMQuery AND TblWznmMPanel.ref = TblWznmRMPanelMQuery.refWznmMPanel AND TblWznmMPanel.ixVBasetype = "
				+ to_string(VecWznmVMPanelBasetype::LIST), false, refsQryjob);
};

void WznmGenCal::getRefsPnlrecjobByCars(
			DbsWznm* dbswznm
			, vector<ubigint>& refsCar
			, vector<ubigint>& refsPnljob
		) {
	for (unsigned int i = 0; i < refsCar.size(); i++) dbswznm->loadRefsBySQL("SELECT refWznmMJob FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(refsCar[i]) + " AND ixVBasetype = "
				+ to_string(VecWznmVMPanelBasetype::REC), true, refsPnljob);
};

void WznmGenCal::getRefsPnldetailjobByCars(
			DbsWznm* dbswznm
			, vector<ubigint>& refsCar
			, vector<ubigint>& refsPnljob
		) {
	for (unsigned int i = 0; i < refsCar.size(); i++) dbswznm->loadRefsBySQL("SELECT refWznmMJob FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(refsCar[i]) + " AND ixVBasetype = "
				+ to_string(VecWznmVMPanelBasetype::RECFORM) + " AND sref LIKE '%Detail'", true, refsPnljob);
};

void WznmGenCal::getRefsQryjobByRel(
			DbsWznm* dbswznm
			, const ubigint refTbl
			, const ubigint refRel
			, vector<ubigint>& refsQryjob
		) {
	dbswznm->loadRefsBySQL("SELECT TblWznmMQuery.refWznmMJob FROM TblWznmMQuery, TblWznmRMPanelMQuery, TblWznmMPanel WHERE TblWznmMQuery.refWznmMTable = " + to_string(refTbl)
				+ " AND TblWznmMQuery.ref = TblWznmRMPanelMQuery.refWznmMQuery AND TblWznmMPanel.ref = TblWznmRMPanelMQuery.refWznmMPanel AND TblWznmMPanel.refIxVTbl = " + to_string(VecWznmVMPanelRefTbl::REL)
				+ " AND TblWznmMPanel.refUref = " + to_string(refRel), false, refsQryjob);
};

void WznmGenCal::getRefsQryjobBySuprel(
			DbsWznm* dbswznm
			, const ubigint refTbl
			, const ubigint refSuprel
			, vector<ubigint>& refsQryjob
		) {
	dbswznm->loadRefsBySQL("SELECT TblWznmMQuery.refWznmMJob FROM TblWznmMQuery, TblWznmRMPanelMQuery, TblWznmMPanel, TblWznmMRelation WHERE TblWznmMQuery.refWznmMTable = " + to_string(refTbl)
				+ " AND TblWznmMQuery.ref = TblWznmRMPanelMQuery.refWznmMQuery AND TblWznmMPanel.ref = TblWznmRMPanelMQuery.refWznmMPanel AND TblWznmMPanel.refIxVTbl = " + to_string(VecWznmVMPanelRefTbl::REL)
				+ " AND TblWznmMPanel.refUref = TblWznmMRelation.ref AND TblWznmMRelation.supRefWznmMRelation = " + to_string(refSuprel), false, refsQryjob);
};
// IP cust --- IEND


