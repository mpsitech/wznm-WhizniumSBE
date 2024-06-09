/**
	* \file WznmWrsrvJob.cpp
	* Wznm operation processor - write C++ code for job (implementation)
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

#include "WznmWrsrvJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsrvJob
 ******************************************************************************/

DpchRetWznm* WznmWrsrvJob::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvJob* dpchinv
		) {
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string orgweb = dpchinv->orgweb;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream blkcppfile;
	fstream evalcppfile;
	fstream cppfile;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;

	WznmMJob* job = NULL;

	ListWznmRMJobMJob jrjs;

	ListWznmMVector vecs;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	ListWznmMBlock dpchs;
	ListWznmMBlock rets;

	ListWznmMControl cons;

	ListWznmMFeed feds;

	ListWznmMStage sges;
	map<ubigint,string> srefsSges;

	ListWznmAMJobCmd cmds;

	ListWznmMMethod mtds;
	
	ListWznmAMJobVar vars;

	ListWznmMSensitivity snss;
	WznmMSensitivity* sns = NULL;

	WznmMCard* car = NULL;
	WznmMPanel* pnl = NULL;
	ListWznmMTable rectbls;

	vector<string> bitsEval;
	vector<string> rulesEval;
	vector<string> exprsEval;

	bool hasblks, hasevals, hasstg, hasdpch, hassge, hassgealr, hasuld, hasdld, hasret, hastmr, hascall;

	uint cnt, cnt2;

	string s;

	if (dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job)) {
		Wznm::getVerlcls(dbswznm, job->refWznmMVersion, refLcl, refsLcl, lcls);

		dbswznm->tblwznmrmjobmjob->loadRstBySup(job->ref, false, jrjs);

		dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = " + to_string(job->ref) + " ORDER BY sref ASC", false, vecs);

		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref) + " ORDER BY sref ASC", false, blks);

		// find relevant dispatch blocks
		if ( (job->ixVBasetype == VecWznmVMJobBasetype::SESS) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD) || (job->ixVBasetype == VecWznmVMJobBasetype::DLG)
					|| (job->ixVBasetype == VecWznmVMJobBasetype::PNL) ) {
			// DpchAppXxxxInit
			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(job->refWznmMVersion) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID)
						+ " AND sref = 'DpchApp" + Prjshort + "Init'", false, dpchs);
		};

		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB)
					+ " AND refUref = " + to_string(job->ref) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::ENG) + ") <> 0 ORDER BY sref ASC", true, dpchs);

		// find relevant op return dispatch blocks
		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(job->refWznmMVersion) + " AND sref = 'DpchRet" + Prjshort + "'", false, rets);

		dbswznm->tblwznmmblock->loadRstBySQL("SELECT TblWznmMBlock.* FROM TblWznmMBlock, TblWznmRMJobMOppack WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND TblWznmMBlock.refUref = TblWznmRMJobMOppack.refWznmMOppack AND TblWznmRMJobMOppack.refWznmMJob = " + to_string(job->ref) + " AND TblWznmMBlock.sref LIKE 'DpchRet%' ORDER BY TblWznmMBlock.sref ASC", true, rets);

		dbswznm->tblwznmmblock->loadRstBySQL("SELECT TblWznmMBlock.* FROM TblWznmMBlock, TblWznmRMJobMOp WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX) + " AND TblWznmMBlock.refUref = TblWznmRMJobMOp.refWznmMOp AND TblWznmRMJobMOp.refWznmMJob = " + to_string(job->ref) + " AND TblWznmMBlock.sref LIKE 'DpchRet%' ORDER BY TblWznmMBlock.sref ASC", true, rets);

		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmRMJobMOppack WHERE refWznmMJob = " + to_string(job->ref), cnt);
		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmRMJobMOp WHERE refWznmMJob = " + to_string(job->ref), cnt2);

		if (rets.nodes.size() == (cnt+cnt2+1)) {
			delete rets.nodes[0];
			rets.nodes[0] = NULL;
		};

		// find controls
		if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::CAR, job->refUref, false, cons);
		else if (job->refIxVTbl == VecWznmVMJobRefTbl::DLG) dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, job->refUref, false, cons);
		else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, job->refUref, false, cons);

		// find feeds
		if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) {
			dbswznm->tblwznmmfeed->loadRstBySQL("SELECT TblWznmMFeed.* FROM TblWznmMFeed, TblWznmMControl WHERE TblWznmMFeed.ref = TblWznmMControl.refWznmMFeed AND TblWznmMControl.hkIxVTbl = "
						+ to_string(VecWznmVMControlHkTbl::CAR) + " AND TblWznmMControl.hkUref = " + to_string(job->refUref) + " ORDER BY TblWznmMFeed.sref ASC", false, feds);

		} else if (job->refIxVTbl == VecWznmVMJobRefTbl::DLG) {
			dbswznm->tblwznmmfeed->loadRstBySQL("SELECT TblWznmMFeed.* FROM TblWznmMFeed, TblWznmMControl WHERE TblWznmMFeed.ref = TblWznmMControl.refWznmMFeed AND TblWznmMControl.hkIxVTbl = "
						+ to_string(VecWznmVMControlHkTbl::DLG) + " AND TblWznmMControl.hkUref = " + to_string(job->refUref) + " ORDER BY TblWznmMFeed.sref ASC", false, feds);

		} else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) {
			dbswznm->tblwznmmfeed->loadRstBySQL("SELECT TblWznmMFeed.* FROM TblWznmMFeed, TblWznmMControl WHERE TblWznmMFeed.ref = TblWznmMControl.refWznmMFeed AND TblWznmMControl.hkIxVTbl = "
						+ to_string(VecWznmVMControlHkTbl::PNL) + " AND TblWznmMControl.hkUref = " + to_string(job->refUref) + " ORDER BY TblWznmMFeed.sref ASC", false, feds);
		};

		dbswznm->tblwznmmstage->loadRstBySQL("SELECT * FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(job->ref) + " ORDER BY jobNum ASC", false, sges);
		for (unsigned int i = 0; i < sges.nodes.size(); i++) srefsSges[sges.nodes[i]->ref] = sges.nodes[i]->sref;

		dbswznm->tblwznmamjobcmd->loadRstByJob(job->ref, false, cmds);

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);

		dbswznm->tblwznmamjobvar->loadRstByJob(job->ref, false, vars);

		dbswznm->tblwznmmsensitivity->loadRstBySQL("SELECT * FROM TblWznmMSensitivity WHERE refWznmMJob = " + to_string(job->ref), false, snss);

		if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) {
			if (dbswznm->tblwznmmpanel->loadRecByRef(job->refUref, &pnl)) {
				if (dbswznm->tblwznmmcard->loadRecByRef(pnl->carRefWznmMCard, &car)) {
					Wznm::getPnlrecs(dbswznm, job->refWznmMVersion, Prjshort, car, pnl, rectbls);
					delete car;
				};
				delete pnl;
			};
		};

		Wznm::getJobevals(dbswznm, job, bitsEval, rulesEval, exprsEval);

		// categorize job
		hasblks = ((vecs.nodes.size() > 0) || (blks.nodes.size() > 0));

		hasevals = (rulesEval.size() > 0);

		if (hasevals) {
			hasevals = false;

			for (unsigned int i = 0; i < rulesEval.size(); i++) {
				if (exprsEval[i] != "custom()") {
					hasevals = true;
					break;
				};
			};
		};

		hasstg = false;
		for (unsigned int i = 0; i < blks.nodes.size(); i++) {
			blk = blks.nodes[i];

			if ((blk->ixVBasetype == VecWznmVMBlockBasetype::STG) && ((blk->reaIxWznmWScope & VecWznmWScope::APP) == 0)) {
				hasstg = true;
				break;
			};
		};

		hasdpch = (dpchs.nodes.size() > 0);

		hassge = (sges.nodes.size() > 0);

		hassgealr = false;
		for (unsigned int i = 0; i < sges.nodes.size(); i++) {
			if (sges.nodes[i]->ixVBasetype == VecWznmVMStageBasetype::ALR) {
				hassgealr = true;
				break;
			};
		};

		if (hassgealr) {
			// DpchAppXxxxAlert
			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(job->refWznmMVersion) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID)
						+ " AND sref = 'DpchApp" + Prjshort + "Alert'", true, dpchs);
		};

		hasuld = false;
		hasdld = false;
		hastmr = false;
		hascall = false;

		for (unsigned int i = 0; i < snss.nodes.size(); i++) {
			sns = snss.nodes[i];

			if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::CAL) hascall = true;
			else if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::ULD) hasuld = true;
			else if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::DLD) hasdld = true;
			else if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::TMR) hastmr = true;
		};

		hasret = false;
		for (unsigned int i = 0; i < sges.nodes.size(); i++) {
			if ((sges.nodes[i]->ixVBasetype == VecWznmVMStageBasetype::OPIW) || (sges.nodes[i]->ixVBasetype == VecWznmVMStageBasetype::OPPIW)) {
				hasret = true;
				break;
			};
		};

		// JobXxxxYyyZzzzz.h, JobXxxxYyyZzzzz_blks.cpp, JobXxxxYyyZzzzz_evals.cpp, JobXxxxYyyZzzzz.cpp
		s = xchg->tmppath + "/" + folder + "/" + job->sref + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		if (hasblks) {
			s = xchg->tmppath + "/" + folder + "/" + job->sref + "_blks.cpp.ip";
			blkcppfile.open(s.c_str(), ios::out);
		};
		if (hasevals) {
			s = xchg->tmppath + "/" + folder + "/" + job->sref + "_evals.cpp.ip";
			evalcppfile.open(s.c_str(), ios::out);
		};
		s = xchg->tmppath + "/" + folder + "/" + job->sref + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeJobH(dbswznm, hfile, job, jrjs, vecs, blks, dpchs, rets, cons, feds, sges, srefsSges, cmds, mtds, vars, snss, rulesEval, exprsEval, Prjshort, hasstg, hasdpch, hassge, hassgealr, hasuld, hasdld, hastmr, hascall);
		if (hasblks) writeJobblksCpp(dbswznm, blkcppfile, job, vecs, blks, orgweb, Prjshort, refLcl, refsLcl);
		if (hasevals) writeJobevalsCpp(dbswznm, evalcppfile, job, rectbls, rulesEval, exprsEval, Prjshort);
		writeJobCpp(dbswznm, cppfile, job, jrjs, vecs, blks, dpchs, rets, cons, feds, sges, srefsSges, cmds, mtds, snss, rectbls, Prjshort, lcls, hasblks, hasevals, hasdpch, hassge, hassgealr, hasuld, hasdld, hasret, hastmr, hascall);

		hfile.close();
		if (hasblks) blkcppfile.close();
		if (hasevals) evalcppfile.close();
		cppfile.close();

		delete job;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvJob::writeJobH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, ListWznmRMJobMJob& jrjs
			, ListWznmMVector& vecs
			, ListWznmMBlock& blks
			, ListWznmMBlock& dpchs
			, ListWznmMBlock& rets
			, ListWznmMControl& cons
			, ListWznmMFeed& feds
			, ListWznmMStage& sges
			, map<ubigint,string>& srefsSges
			, ListWznmAMJobCmd& cmds
			, ListWznmMMethod& mtds
			, ListWznmAMJobVar& vars
			, ListWznmMSensitivity& snss
			, vector<string>& rulesEval
			, vector<string>& exprsEval
			, const string& Prjshort
			, const bool hasstg
			, const bool hasdpch
			, const bool hassge
			, const bool hassgealr
			, const bool hasuld
			, const bool hasdld
			, const bool hastmr
			, const bool hascall
		) {
	ubigint refC;

	WznmRMJobMJob* jrj = NULL;

	WznmMJob* subjob = NULL;

	WznmMVector* vec = NULL;

	WznmMBlock* blk = NULL;
	WznmMBlock* blk2 = NULL;

	WznmMFeed* fed = NULL;

	WznmMStage* sge = NULL;

	WznmAMJobCmd* cmd = NULL;

	WznmMMethod* mtd = NULL;

	ListWznmAMMethodInvpar ipas;
	WznmAMMethodInvpar* ipa = NULL;

	ListWznmAMMethodRetpar rpas;
	WznmAMMethodRetpar* rpa = NULL;

	WznmAMJobVar* var = NULL;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	WznmMSensitivity* sns = NULL;

	WznmMCall* cal = NULL;

	string fctname, fctif;
	uint skipInvIxWznmWArgtype;
	bool skipsref, skipsge, nonspecarg;
	Arg arg;

	string prjshort = StrMod::lc(Prjshort);

	string subsref, subsref2;

	size_t ptr;

	bool first;

	// --- include.subs
	outfile << "// IP include.subs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];

		if (dbswznm->tblwznmmjob->loadRecByRef(jrj->subRefWznmMJob, &subjob)) {
			outfile << "#include \"" << subjob->sref << ".h\"" << endl;
			delete subjob;
		};
	};
	outfile << "// IP include.subs --- IEND" << endl;

	// --- fsrs.blks
	outfile << "// IP fsrs.blks --- IBEGIN" << endl;
	// order: vec's, blocks ex. dpch, dpch's, shrdat

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		subsref = Wznm::getSubsref(job, vec->sref);
		outfile << "#define " << vec->sref << " " << job->sref << "::" << subsref << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->ixVBasetype != VecWznmVMBlockBasetype::DPCH) {
			subsref = Wznm::getSubsref(job, blk->sref);
			outfile << "#define " << blk->sref << " " << job->sref << "::" << subsref << endl;
		};
	};
	outfile << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) {
			subsref = Wznm::getSubsref(job, blk->sref);
			outfile << "#define " << blk->sref << " " << job->sref << "::" << subsref << endl;
		};
	};

	if (job->Shrdat) outfile << "#define Shrdat" << job->sref << " " << job->sref << "::Shrdat" << endl;
	outfile << "// IP fsrs.blks --- IEND" << endl;

	// --- blks
	outfile << "// IP blks --- IBEGIN" << endl;
	// order: vec's, blocks ex. dpch, dpch's

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		subsref = Wznm::getSubsref(job, vec->sref);
		writeVecH(dbswznm, Prjshort, outfile, vec, true, subsref);
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
			writeBlkcontH(dbswznm, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STAT) {
			writeBlkstatH(dbswznm, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STG) {
			writeBlkstgH(dbswznm, Prjshort, outfile, job, blk, true, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG) {
			writeBlktagH(Prjshort, outfile, blk, subsref);
		};
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) {
			subsref = Wznm::getSubsref(job, blk->sref);
			writeBlkdpchH(dbswznm, Prjshort, outfile, job, blk, subsref);
		};
	};
	outfile << "// IP blks --- IEND" << endl;

	// --- evals
	outfile << "// IP evals --- IBEGIN" << endl;
	for (unsigned int i = 0; i < rulesEval.size(); i++) {
		if (exprsEval[i] != "cutsom()") outfile << "\tbool eval" << StrMod::cap(rulesEval[i]) << "(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	};
	outfile << "// IP evals --- IEND" << endl;

	// --- Shrdat*
	if (job->Shrdat) outfile << "// IP Shrdat --- AFFIRM" << endl;
	else outfile << "// IP Shrdat --- REMOVE" << endl;

	// --- Shrdat.vars
	outfile << "// IP Shrdat.vars --- IBEGIN" << endl;
	refC = 0;
	first = true;

	for (unsigned int i = 0; i < vars.nodes.size(); i++) {
		var = vars.nodes[i];

		if (var->Shr) {
			if (!first && (var->refWznmCAMJobVar != refC)) outfile << endl;
			wrVarDeclH(outfile, var->ixWznmVVartype, var->sref, var->Comment, 1);

			refC = var->refWznmCAMJobVar;
			first = false;
		};
	};
	outfile << "// IP Shrdat.vars --- IEND" << endl;

	// --- constructor*
	if (!( (job->ixVBasetype == VecWznmVMJobBasetype::ROOT) || (job->ixVBasetype == VecWznmVMJobBasetype::SESS) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD) )) outfile << "// IP constructor --- AFFIRM" << endl;

	// --- vars.stg*
	if (hasstg) outfile << "// IP vars.stg --- AFFIRM" << endl;
	else outfile << "// IP vars.stg --- REMOVE" << endl;

	// --- vars.shrdat*
	if (job->Shrdat) outfile << "// IP vars.shrdat --- AFFIRM" << endl;
	else outfile << "// IP vars.shrdat --- REMOVE" << endl;

	// --- vars.blks
	outfile << "// IP vars.blks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
			outfile << "\t" << subsref << " " << StrMod::lc(subsref) << ";" << endl;
		} else if ((blk->ixVBasetype == VecWznmVMBlockBasetype::STAT) && (blk->sref.find("StatApp") != 0)) {
			outfile << "\t" << subsref << " " << StrMod::lc(subsref) << ";" << endl;
		} else if ((blk->ixVBasetype == VecWznmVMBlockBasetype::STG) && (blk->sref.find("StgInf") != 0) && ((blk->reaIxWznmWScope & VecWznmWScope::APP) != 0)) {
			// StgInf only has writeXML, non-StgIac/StgInf is taken care of with static variable
			outfile << "\t" << subsref << " " << StrMod::lc(subsref) << ";" << endl;
		};
	};

	if ((feds.nodes.size() > 0) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD) || (job->ixVBasetype == VecWznmVMJobBasetype::DLG)
				|| (job->ixVBasetype == VecWznmVMJobBasetype::PNL)) outfile << endl;

	if (hassgealr) outfile << "\tSbecore::Feed feedFMcbAlert;" << endl;

	for (unsigned int i = 0; i < feds.nodes.size(); i++) {
		fed = feds.nodes[i];

		outfile << "\tSbecore::Feed " << StrMod::uncap(fed->sref) << ";" << endl;
	};
	outfile << "// IP vars.blks --- IEND" << endl;

	// --- vars.subs
	outfile << "// IP vars.subs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];

		if (dbswznm->tblwznmmjob->loadRecByRef(jrj->subRefWznmMJob, &subjob)) {
			if (jrj->Multi) {
				outfile << "\tstd::map<Sbecore::ubigint, Job" << Prjshort << "*> " << jrj->Short << "s;" << endl;
			} else {
				outfile << "\t" << subjob->sref << "* " << jrj->Short << ";" << endl;
			};
			delete subjob;
		};
	};
	outfile << "// IP vars.subs --- IEND" << endl;

	// --- vars
	outfile << "// IP vars --- IBEGIN" << endl;
	refC = 0;
	first = true;

	for (unsigned int i = 0; i < vars.nodes.size(); i++) {
		var = vars.nodes[i];

		if (!var->Shr) {
			if (!first && (var->refWznmCAMJobVar != refC)) outfile << endl;
			wrVarDeclH(outfile, var->ixWznmVVartype, var->sref, var->Comment, 0);

			refC = var->refWznmCAMJobVar;
			first = false;
		};
	};
	outfile << "// IP vars --- IEND" << endl;

	// --- methods
	outfile << "// IP methods --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mtds.nodes.size(); i++) {
		mtd = mtds.nodes[i];

		dbswznm->tblwznmammethodinvpar->loadRstByMtd(mtd->ref, false, ipas);
		dbswznm->tblwznmammethodretpar->loadRstByMtd(mtd->ref, false, rpas);

		outfile << "\tbool " << mtd->sref << "(Dbs" << Prjshort << "* dbs" << prjshort;

		for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
			ipa = ipas.nodes[j];
			wrIparpa(outfile, ipa->sref, "", ipa->ixWznmVVartype, false, false, true);
		};

		for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
			rpa = rpas.nodes[j];
			wrIparpa(outfile, rpa->sref, "", rpa->ixWznmVVartype, false, true, true);
		};

		outfile << ");" << endl;
	};
	if (mtds.nodes.size() > 0) outfile << endl;
	outfile << "// IP methods --- IEND" << endl;

	// --- cmds
	outfile << "// IP cmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];
		outfile << "\tbool handle" << StrMod::cap(cmd->sref) << "(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	};
	outfile << "// IP cmds --- IEND" << endl;

	// --- dpchapps
	outfile << "// IP dpchapps --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		blk = dpchs.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		// distinguish special cases
		if (subsref == "DpchAppLogin") {
			outfile << "\tvoid handle" << subsref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", " << subsref << "* " << StrMod::lc(subsref) << ", const std::string ip, DpchEng" << Prjshort << "** dpcheng);" << endl;

		} else if (subsref == "DpchAppData") {
			dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &blk2)) {
						outfile << "\tvoid handleDpchAppData" << StrMod::cap(bit->sref) << "(Dbs" << Prjshort << "* dbs" << prjshort << ", " << getBlkclass(dbswznm, job, blk2) << "* _" << bit->sref << ", DpchEng" << Prjshort << "** dpcheng);" << endl;
						delete blk2;
					};
				};
			};

		} else if (subsref == "DpchAppDo") {
			dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if ((bit->ixWznmVVartype == VecWznmVVartype::VECSREF) && (bit->refWznmMVector != 0)) {
					if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
						subsref2 = Wznm::getSubsref(job, vec->sref);

						ptr = subsref2.find("Do");
						if (ptr != string::npos) {
							dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

							outfile << endl;
							for (unsigned int k = 0; k < vits.nodes.size(); k++) {
								vit = vits.nodes[k];

								outfile << "\tvoid handleDpchApp" << subsref2.substr(ptr) << StrMod::cap(vit->sref) << "(Dbs" << Prjshort << "* dbs" << prjshort << ", DpchEng" << Prjshort << "** dpcheng);" << endl;
							};
						};

						delete vec;
					};
				};
			};

		} else {
			outfile << "\tvoid handle" << subsref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", " << subsref << "* " << StrMod::lc(subsref) << ", DpchEng" << Prjshort << "** dpcheng);" << endl;
		};
	};
	outfile << "// IP dpchapps --- IEND" << endl;

	// --- uploads
	outfile << "// IP uploads --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::ULD) {
			analyzeSns(dbswznm, sns, {}, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);
			if (fctname != "") outfile << "\tvoid " << fctname << "(Dbs" << Prjshort << "* dbs" << prjshort << ", const std::string& filename);" << endl;
		};
	};
	outfile << "// IP uploads --- IEND" << endl;

	// --- downloads
	outfile << "// IP downloads --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::DLD) {
			analyzeSns(dbswznm, sns, {}, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);
			if (fctname != "") outfile << "\tstd::string " << fctname << "(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
		};
	};
	outfile << "// IP downloads --- IEND" << endl;

	// --- dpchrets
	outfile << "// IP dpchrets --- IBEGIN" << endl;
	for (unsigned int i = 0; i < rets.nodes.size(); i++) {
		blk = rets.nodes[i];
		if (blk) outfile << "\tvoid handle" << blk->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", " << blk->sref << "* dpchret);" << endl;
	};
	outfile << "// IP dpchrets --- IEND" << endl;

	// --- timers
	outfile << "// IP timers --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::TMR) {
			analyzeSns(dbswznm, sns, {}, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);
			if (fctname != "") {
				outfile << "\tvoid " << fctname << "(Dbs" << Prjshort << "* dbs" << prjshort;
				if (!skipsref) outfile << ", const std::string& sref";
				outfile << ");" << endl;
			};
		};
	};
	outfile << "// IP timers --- IEND" << endl;

	// --- handleCall*
	if (hascall) outfile << "// IP handleCall --- AFFIRM" << endl;
	else outfile << "// IP handleCall --- REMOVE" << endl;

	// --- calls
	outfile << "// IP calls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->refWznmMCall != 0) if (dbswznm->tblwznmmcall->loadRecByRef(sns->refWznmMCall, &cal)) {
			analyzeSns(dbswznm, sns, {}, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);

			if (fctname != "") {
				outfile << "\tbool " << fctname << "(Dbs" << Prjshort << "* dbs" << prjshort;
				if ((sns->ixVJobmask != VecWznmVMSensitivityJobmask::SELF) && (sns->ixVJobmask != VecWznmVMSensitivityJobmask::SPEC)) outfile << ", const Sbecore::ubigint jrefTrig";

				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::IX) & ~skipInvIxWznmWArgtype) outfile << ", const Sbecore::uint ixInv";
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::REF) & ~skipInvIxWznmWArgtype) outfile << ", const Sbecore::ubigint refInv";
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::SREF) & ~skipInvIxWznmWArgtype) outfile << ", const std::string& srefInv";
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::INTVAL) & ~skipInvIxWznmWArgtype) outfile << ", const int intvalInv";
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::DBLVAL) & ~skipInvIxWznmWArgtype) outfile << ", const double dblvalInv";
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::BOOLVAL) & ~skipInvIxWznmWArgtype) outfile << ", const bool boolvalInv";
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::TXTVAL) & ~skipInvIxWznmWArgtype) outfile << ", const std::string& txtvalInv";

				if (cal->retIxWznmWArgtype & VecWznmWArgtype::IX) outfile << ", Sbecore::uint& ixRet";
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::REF) outfile << ", Sbecore::ubigint& refRet";
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::SREF) outfile << ", std::string& srefRet";
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::INTVAL) outfile << ", int& intvalRet";
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::DBLVAL) outfile << ", double& dblvalRet";
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::BOOLVAL) outfile << ", bool& boolvalRet";
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::TXTVAL) outfile << ", std::string& txtvalRet";

				outfile << ");" << endl;
			};

			delete cal;
		};
	};
	outfile << "// IP calls --- IEND" << endl;

	// --- changeStage*
	if (hassge && !hasdpch) outfile << "// IP changeStage --- AFFIRM" << endl;
	else outfile << "// IP changeStage --- REMOVE" << endl;

	// --- dpchchangeStage*
	if (hassge && hasdpch) outfile << "// IP dpchchangeStage --- AFFIRM" << endl;
	else outfile << "// IP dpchchangeStage --- REMOVE" << endl;

	// --- getSquawk*
	if (hassge) outfile << "// IP getSquawk --- AFFIRM" << endl;
	else outfile << "// IP getSquawk --- REMOVE" << endl;

	// --- sges
	outfile << "// IP sges --- IBEGIN" << endl;
	for (unsigned int i = 0; i < sges.nodes.size(); i++) {
		sge = sges.nodes[i];

		outfile << "\tSbecore::uint enterSge" << StrMod::cap(sge->sref) << "(Dbs" << Prjshort << "* dbs" << prjshort << ", const bool reenter);" << endl;
		outfile << "\tvoid leaveSge" << StrMod::cap(sge->sref) << "(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	};
	outfile << "// IP sges --- IEND" << endl;

	// --- clisrv*
	if (job->Clisrv) outfile << "// IP clisrv --- AFFIRM" << endl;
	else outfile << "// IP clisrv --- REMOVE" << endl;
};

void WznmWrsrvJob::writeJobblksCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, ListWznmMVector& vecs
			, ListWznmMBlock& blks
			, const string& orgweb
			, const string& Prjshort
			, ubigint& refLcl
			, vector<ubigint>& refsLcl
		) {
	WznmMVector* vec = NULL;

	WznmMBlock* blk = NULL;

	string subsref;

	outfile << "// IP blks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		subsref = Wznm::getSubsref(job, vec->sref);
		writeVecCpp(dbswznm, Prjshort, outfile, vec, true, job->sref, subsref, refLcl, refsLcl);
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
			writeBlkcontCpp(dbswznm, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STAT) {
			writeBlkstatCpp(dbswznm, Prjshort, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STG) {
			writeBlkstgCpp(dbswznm, Prjshort, outfile, job, blk, true, job->sref, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG) {
			writeBlktagCpp(dbswznm, Prjshort, outfile, job, blk, subsref);
		};
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) {
			subsref = Wznm::getSubsref(job, blk->sref);
			writeBlkdpchCpp(dbswznm, orgweb, Prjshort, outfile, job, blk, subsref);
		};
	};
	outfile << "// IP blks --- IEND" << endl;
};

void WznmWrsrvJob::writeJobevalsCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, ListWznmMTable& rectbls
			, vector<string>& rulesEval
			, vector<string>& exprsEval
			, const string& Prjshort
		) {
	Expr expr;

	string prjshort = StrMod::lc(Prjshort);

	outfile << "// IP evals --- IBEGIN" << endl;
	for (unsigned int i = 0; i < rulesEval.size(); i++) {
		if (exprsEval[i] != "custom()") {
			outfile << "bool " << job->sref << "::eval" << StrMod::cap(rulesEval[i]) << "(" << endl;
			outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\t// " << exprsEval[i] << endl;
			outfile << endl;

			if (expr.tokenize(exprsEval[i])) {
				if (expr.parse()) {
					outfile << "\tvector<bool> args;" << endl;
					if (expr.has(Expr::VecVNodetype::FCT, "and") || expr.has(Expr::VecVNodetype::FCT, "or")) outfile << "\tbool a, b;" << endl;
					else outfile << "\tbool a;" << endl;
					outfile << endl;

					if (job->ixVBasetype == VecWznmVMJobBasetype::CRD) writeBooleval(dbswznm, Prjshort, outfile, job->refWznmMVersion, rectbls, expr.root, "statshr.jrefRec");
					else writeBooleval(dbswznm, Prjshort, outfile, job->refWznmMVersion, rectbls, expr.root);

					outfile << endl;

					outfile << "\treturn(args.back());" << endl;

				} else {
					outfile << "\treturn false;" << endl;
				};
			} else {
				outfile << "\treturn false;" << endl;
			};

			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP evals --- IEND" << endl;
};

void WznmWrsrvJob::writeJobCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, ListWznmRMJobMJob& jrjs
			, ListWznmMVector& vecs
			, ListWznmMBlock& blks
			, ListWznmMBlock& dpchs
			, ListWznmMBlock& rets
			, ListWznmMControl& cons
			, ListWznmMFeed& feds
			, ListWznmMStage& sges
			, map<ubigint,string>& srefsSges
			, ListWznmAMJobCmd& cmds
			, ListWznmMMethod& mtds
			, ListWznmMSensitivity& snss
			, ListWznmMTable& rectbls
			, const string& Prjshort
			, ListWznmMLocale& lcls
			, const bool hasblks
			, const bool hasevals
			, const bool hasdpch
			, const bool hassge
			, const bool hassgealr
			, const bool hasuld
			, const bool hasdld
			, const bool hasret
			, const bool hastmr
			, const bool hascall
		) {
	WznmMLocale* lcl = NULL;

	WznmRMJobMJob* jrj = NULL;
	map<string,uint> csasJrjs; // by Short

	WznmMJob* subjob = NULL;

	WznmMVector* vec = NULL;

	WznmMBlock* blk = NULL;
	WznmMBlock* blk2 = NULL;

	WznmMControl* con = NULL;

	WznmMFeed* fed = NULL;

	WznmMStage* sge = NULL;
	vector<unsigned int> icsSges, icsSges2, icsSges3, icsSges4;

	bool stdalr;
	set<string> plhs;

	WznmMSquawk* sqk = NULL;

	WznmAMJobCmd* cmd = NULL;

	WznmMMethod* mtd = NULL;

	ListWznmAMMethodInvpar ipas;
	WznmAMMethodInvpar* ipa = NULL;

	ListWznmAMMethodRetpar rpas;
	WznmAMMethodRetpar* rpa = NULL;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	WznmMSensitivity* sns = NULL;

	WznmMCall* cal = NULL;

	string fctname, fctif;
	uint skipInvIxWznmWArgtype;
	bool skipsref, skipsge, nonspecarg;
	Arg arg;

	string prjshort = StrMod::lc(Prjshort);

	string subsref, subsref2;

	string ifsrv;

	vector<string> ss;
	string s;

	size_t ptr;
	bool first, found;

	string tab;

	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) csasJrjs[jrjs.nodes[i]->Short] = jrjs.nodes[i]->ixVConstract;

	if (job->Clisrv) ifsrv = "if (srvNotCli) ";

	// --- include.blks*
	if (hasblks) outfile << "// IP include.blks --- AFFIRM" << endl;
	else outfile << "// IP include.blks --- REMOVE" << endl;

	// --- include.evals*
	if (hasevals) outfile << "// IP include.evals --- AFFIRM" << endl;
	else outfile << "// IP include.evals --- REMOVE" << endl;

	// --- Shrdat*
	if (job->Shrdat) outfile << "// IP Shrdat --- AFFIRM" << endl;
	else outfile << "// IP Shrdat --- REMOVE" << endl;

	// --- constructor.hdr*
	if (!( (job->ixVBasetype == VecWznmVMJobBasetype::ROOT) || (job->ixVBasetype == VecWznmVMJobBasetype::SESS) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD) )) outfile << "// IP constructor.hdr --- AFFIRM" << endl;

	// --- constructor.feeds
	outfile << "// IP constructor.feeds --- IBEGIN" << endl;

	if (hassgealr) outfile << "\tfeedFMcbAlert.tag = \"FeedFMcbAlert\";" << endl;

	for (unsigned int i = 0; i < feds.nodes.size(); i++) {
		fed = feds.nodes[i];

		outfile << "\t" << StrMod::uncap(fed->sref) << ".tag = \"" << fed->sref << "\";" << endl;
		if (fed->srcIxVTbl == VecWznmVMFeedSrcTbl::VOID) {
			StrMod::srefsToVector(fed->srefsWznmMTag, ss);
			for (unsigned int j = 0; j < ss.size(); j++) outfile << "\tVec" << Prjshort << "VTag::appendToFeed(Vec" << Prjshort << "VTag::" << StrMod::uc(ss[j]) << ", ix" << Prjshort << "VLocale, " << StrMod::uncap(fed->sref) << ");" << endl;

		} else if (fed->srcIxVTbl == VecWznmVMFeedSrcTbl::VEC) {
			if (dbswznm->tblwznmmvector->loadRecByRef(fed->srcUref, &vec)) {
				if ((vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) || (vec->ixVBasetype == VecWznmVMVectorBasetype::OR)) {

					if (fed->srefsWznmMVectoritem.length() == 0) {
						outfile << "\t" << getVecclass(dbswznm, job, vec) << "::fillFeed(";
						if (!StrMod::srefInSrefs(vec->srefsKOption, "noloc")) outfile << "ix" << Prjshort << "VLocale, ";
						outfile << StrMod::uncap(fed->sref) << ");" << endl;

					} else {
						StrMod::srefsToVector(fed->srefsWznmMVectoritem, ss);

						if (dbswznm->tblwznmmcontrol->loadRecByRef(fed->refWznmMControl, &con)) {

							if (con->ixVBasetype == VecWznmVMControlBasetype::CSI) {
								for (unsigned int j = 0; j < ss.size(); j++) {
									ptr = ss[j].find(".");

									if ((ptr != string::npos) && (ptr != 0)) {
										s = ss[j].substr(ptr+1);
										ss[j] = ss[j].substr(0, ptr);
									};

									outfile << "\t" << StrMod::uncap(fed->sref) << ".appendIxSrefTitles(" << vec->sref << "::" << StrMod::uc(ss[j]) << ", \"" << s << "\", " << vec->sref << "::getTitle(" << vec->sref << "::" << StrMod::uc(ss[j]);
									if (!StrMod::srefInSrefs(vec->srefsKOption, "noloc")) outfile << ", ix" << Prjshort << "VLocale";
									outfile << "));" << endl;
								};

							} else {
								for (unsigned int j = 0; j < ss.size(); j++) {
									outfile << "\t" << vec->sref << "::appendToFeed(" << vec->sref << "::" << StrMod::uc(ss[j]);
									if (!StrMod::srefInSrefs(vec->srefsKOption, "noloc")) outfile << ", ix" << Prjshort << "VLocale";
									outfile << ", " << StrMod::uncap(fed->sref) << ");" << endl;
								};
							};

							delete con;
						};
					};

				} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::KLST) {
					outfile << "\tdbs" << prjshort << "->fillFeedFromKlst(Vec" << Prjshort << "VKeylist::" << StrMod::uc(vec->sref) << ", ix" << Prjshort << "VLocale, " << StrMod::uncap(fed->sref) << ");" << endl;

				} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::VLST) {
					outfile << "\tdbs" << prjshort << "->fillFeedFromVlst(Vec" << Prjshort << "VValuelist::" << StrMod::uc(vec->sref) << ", ix" << Prjshort << "VLocale, " << StrMod::uncap(fed->sref) << ");" << endl;
				};

				delete vec;
			};
		};
	};
	outfile << "// IP constructor.feeds --- IEND" << endl;

	// --- constructor.subs1
	outfile << "// IP constructor.subs1 --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		if (!jrj->Multi) outfile << "\t" << jrj->Short << " = NULL;" << endl;
	};
	outfile << "// IP constructor.subs1 --- IEND" << endl;

	// --- constructor.subs2
	outfile << "// IP constructor.subs2 --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];

		if (!jrj->Multi) {
			if (jrj->ixVConstract == VecWznmVRMJobMJobConstract::CRE) {
				if (dbswznm->tblwznmmjob->loadRecByRef(jrj->subRefWznmMJob, &subjob)) {
					outfile << "\t" << ifsrv << jrj->Short << " = new " << subjob->sref << "(xchg, dbs" << prjshort << ", jref, ix" << Prjshort << "VLocale);" << endl;
					delete subjob;
				};
			};
		};
	};
	outfile << "// IP constructor.subs2 --- IEND" << endl;

	// --- constructor.calls
	outfile << "// IP constructor.calls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->refWznmMCall != 0) if (dbswznm->tblwznmmcall->loadRecByRef(sns->refWznmMCall, &cal)) {
			analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);

			if ((fctname != "") && !nonspecarg) {
				if (sns->ixVJobmask == VecWznmVMSensitivityJobmask::SPEC) if (csasJrjs.find(sns->Jobshort) != csasJrjs.end()) if (csasJrjs[sns->Jobshort] == VecWznmVRMJobMJobConstract::VOID) continue;

				outfile << "\t" << ifsrv;
				if (sns->ixVJobmask == VecWznmVMSensitivityJobmask::SPEC) if (csasJrjs.find(sns->Jobshort) != csasJrjs.end()) if (csasJrjs[sns->Jobshort] == VecWznmVRMJobMJobConstract::CUST) outfile << "if (" << sns->Jobshort << ") ";

				outfile << "xchg->addClstn(Vec" << Prjshort << "VCall::" << StrMod::dotToUsc(StrMod::uc(cal->sref)) << ", jref, Clstn::VecVJobmask::" << StrMod::uc(VecWznmVMSensitivityJobmask::getSref(sns->ixVJobmask));

				if (sns->ixVJobmask == VecWznmVMSensitivityJobmask::SPEC) outfile << ", " << sns->Jobshort << "->jref";
				else outfile << ", 0";

				outfile << ", false";

				if ((arg.mask & (Arg::IX + Arg::REF + Arg::SREF)) == 0) outfile << ", Arg()";
				else {
					outfile << ", Arg(";

					if (arg.mask & Arg::IX) outfile << to_string(arg.ix) << ","; else outfile << "0,";
					if (arg.mask & Arg::REF) outfile << to_string(arg.ref) << ","; else outfile << "0,";
					outfile << "{},"; // refs
					if (arg.mask & Arg::SREF) outfile << "\"" << arg.sref << "\","; else outfile << "\"\",";
					outfile << "0,0.0,false,\"\","; // intval, dblval, boolval, txtval

					first = true;
					if (arg.mask & Arg::IX) {
						first = false;
						outfile << "Arg::IX";
					};
					if (arg.mask & Arg::REF) {
						if (first) first = false;
						else outfile << "+";
						outfile << "Arg::REF";
					};
					if (arg.mask & Arg::SREF) {
						if (first) first = false;
						else outfile << "+";
						outfile << "Arg::SREF";
					};

					outfile << ")";
				};

				if (srefsSges.find(sns->refWznmMStage) != srefsSges.end()) outfile << ", VecVSge::" << StrMod::uc(srefsSges[sns->refWznmMStage]);
				else outfile << ", 0";

				outfile << ", Clstn::VecVJactype::" << StrMod::uc(VecWznmVMSensitivityJactype::getSref(sns->ixVJactype)) << ");" << endl;
			};

			delete cal;
		};
	};

	outfile << "// IP constructor.calls --- IEND" << endl;

	// --- methods
	outfile << "// IP methods --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mtds.nodes.size(); i++) {
		mtd = mtds.nodes[i];

		dbswznm->tblwznmammethodinvpar->loadRstByMtd(mtd->ref, false, ipas);
		dbswznm->tblwznmammethodretpar->loadRstByMtd(mtd->ref, false, rpas);

		outfile << "bool " << job->sref << "::" << mtd->sref << "(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;

		for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
			ipa = ipas.nodes[j];
			wrIparpa(outfile, ipa->sref, ipa->Comment, ipa->ixWznmVVartype, true, false, false);
		};

		for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
			rpa = rpas.nodes[j];
			wrIparpa(outfile, rpa->sref, rpa->Comment, rpa->ixWznmVVartype, true, true, false);
		};

		outfile << "\t\t) {" << endl;
		outfile << "\tbool retval = true;" << endl;
		outfile << endl;

		if (mtd->Execsrv) {
			outfile << "\tif (!srvNotCli) {" << endl;
			outfile << "\t\tif (srv) {" << endl;

			outfile << "\t\t\tretval = ((" << job->sref << "*) srv)->" << mtd->sref << "(dbs" << prjshort;
			for (unsigned int j = 0; j < ipas.nodes.size(); j++) outfile << ", " << ipas.nodes[j]->sref;
			for (unsigned int j = 0; j < rpas.nodes.size(); j++) outfile << ", " << rpas.nodes[j]->sref;
			outfile << ");" << endl;
			outfile << endl;

			outfile << "\t\t} else retval = false;" << endl;
			outfile << endl;

			outfile << "\t\treturn retval;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;
		};

		outfile << "\tlockAccess(\"" << mtd->sref << "\");" << endl;
		outfile << endl;

		outfile << "\t// IP " << mtd->sref << " --- INSERT" << endl;
		outfile << endl;

		outfile << "\tunlockAccess(\"" << mtd->sref <<  "\");" << endl;
		outfile << endl;

		outfile << "\treturn retval;" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP methods --- IEND" << endl;

	// --- handleRequest.cmdset
	outfile << "// IP handleRequest.cmdset --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];
		outfile << "\t\t\tcout << \"\\t" << cmd->sref << "\" << endl;" << endl;
	};
	outfile << "// IP handleRequest.cmdset --- IEND" << endl;

	// --- handleRequest.cmds
	outfile << "// IP handleRequest.cmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		outfile << "\t\t} else if (req->cmd == \"" << cmd->sref << "\") {" << endl;
		outfile << "\t\t\treq->retain = handle" << StrMod::cap(cmd->sref) << "(dbs" << prjshort << ");" << endl;
		outfile << endl;
	};
	outfile << "// IP handleRequest.cmds --- IEND" << endl;

	// --- handleRequest.dpchapp*
	if (dpchs.nodes.size() > 0) outfile << "// IP handleRequest.dpchapp --- AFFIRM" << endl;
	else outfile << "// IP handleRequest.dpchapp --- REMOVE" << endl;

	// --- handleRequest.dpchapps
	outfile << "// IP handleRequest.dpchapps --- IBEGIN" << endl;

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		blk = dpchs.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		outfile << "\t\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (req->dpchapp->ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ") {" << endl;

		// distinguish special cases
		if (subsref == "DpchAppLogin") {
			outfile << "\t\t\thandle" << subsref << "(dbs" << prjshort << ", (" << subsref << "*) (req->dpchapp), req->ip, &(req->dpcheng));" << endl;
			outfile << endl;

		} else if (subsref == "DpchAppData") {
			outfile << "\t\t\tDpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);" << endl;
			outfile << endl;

			dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

			first = true;

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &blk2)) {
						outfile << "\t\t\t";
						if (first) first = false;
						else outfile << "} else ";
						outfile << "if (dpchappdata->has(DpchAppData::" << Wznm::getBitmasksref(bit->sref) + ")) {" << endl;
						outfile << "\t\t\t\thandleDpchAppData" << StrMod::cap(bit->sref) << "(dbs" << prjshort << ", &(dpchappdata->" << bit->sref << "), &(req->dpcheng));" << endl;

						delete blk2;
					};
				};
			};

			if (!first) outfile << "\t\t\t};" << endl;
			outfile << endl;

		} else if (subsref == "DpchAppDo") {
			outfile << "\t\t\tDpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);" << endl;
			outfile << endl;

			dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

			first = true;

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if ((bit->ixWznmVVartype == VecWznmVVartype::VECSREF) && (bit->refWznmMVector != 0)) {
					if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
						subsref2 = Wznm::getSubsref(job, vec->sref);

						ptr = subsref2.find("Do");
						if (ptr != string::npos) {
							outfile << "\t\t\t";
							if (first) first = false;
							else outfile << "} else ";
							outfile << "if (dpchappdo->" << bit->sref << " != 0) {" << endl;

							dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

							for (unsigned int k = 0; k < vits.nodes.size(); k++) {
								vit = vits.nodes[k];

								outfile << "\t\t\t\t";
								if (k != 0) outfile << "} else ";
								outfile << "if (dpchappdo->" << bit->sref << " == " << subsref2 << "::" << StrMod::uc(vit->sref) << ") {" << endl;
								outfile << "\t\t\t\t\thandleDpchApp" << subsref2.substr(ptr) << StrMod::cap(vit->sref) << "(dbs" << prjshort << ", &(req->dpcheng));" << endl;
							};
							if (vits.nodes.size() > 0) outfile << "\t\t\t\t};" << endl;
							outfile << endl;
						};

						delete vec;
					};
				};
			};
			if (!first) outfile << "\t\t\t};" << endl;
			outfile << endl;

		} else {
			outfile << "\t\t\thandle" << subsref << "(dbs" << prjshort << ", (" << subsref << "*) (req->dpchapp), &(req->dpcheng));" << endl;
			outfile << endl;
		};
	};
	if (dpchs.nodes.size() > 0) outfile << "\t\t};" << endl;

	outfile << "// IP handleRequest.dpchapps --- IEND" << endl;

	// --- handleRequest.upload*
	if (hasuld) outfile << "// IP handleRequest.upload --- AFFIRM" << endl;
	else outfile << "// IP handleRequest.upload --- REMOVE" << endl;

	// --- handleRequest.uploads
	outfile << "// IP handleRequest.uploads --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::ULD) {
			analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);
			if (fctname != "") {
				outfile << "\t\t";

				if (first) first = false;
				else outfile << "else ";

				if (fctif != "") outfile << "if " << fctif << " ";

				outfile << fctname << "(dbs" << prjshort << ", req->filename);" << endl;
			};
		};
	};
	outfile << "// IP handleRequest.uploads --- IEND" << endl;

	// --- handleRequest.download*
	if (hasdld) outfile << "// IP handleRequest.download --- AFFIRM" << endl;
	else outfile << "// IP handleRequest.download --- REMOVE" << endl;

	// --- handleRequest.downloads
	outfile << "// IP handleRequest.downloads --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::DLD) {
			analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);
			if (fctname != "") {
				outfile << "\t\t";

				if (first) first = false;
				else outfile << "else ";

				if (fctif != "") outfile << "if " << fctif << " ";

				outfile << "req->filename = " << fctname << "(dbs" << prjshort << ");" << endl;
			};
		};
	};
	outfile << "// IP handleRequest.downloads --- IEND" << endl;

	// --- handleRequest.dpchret*
	if (hasret) outfile << "// IP handleRequest.dpchret --- AFFIRM" << endl;
	else outfile << "// IP handleRequest.dpchret --- REMOVE" << endl;

	// --- handleRequest.dpchrets
	outfile << "// IP handleRequest.dpchrets --- IBEGIN" << endl;

	first = true;
	for (unsigned int i = 0; i < rets.nodes.size(); i++) {
		blk = rets.nodes[i];

		if (blk) {
			outfile << "\t\t\t";
			if (first) first = false;
			else outfile << "} else ";
			
			outfile << "if (req->dpchret->ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ") {" << endl;
			outfile << "\t\t\t\thandle" << blk->sref << "(dbs" << prjshort << ", (" << blk->sref << "*) (req->dpchret));" << endl;
		};
	};

	if (!first) {
		outfile << "\t\t\t};" << endl;
		outfile << endl;
	};
	
	outfile << "// IP handleRequest.dpchrets --- IEND" << endl;

	// --- handleRequest.method*
	if (mtds.nodes.size() > 0) outfile << "// IP handleRequest.method --- AFFIRM" << endl;
	else outfile << "// IP handleRequest.method --- REMOVE" << endl;

	// --- handleRequest.methods
	outfile << "// IP handleRequest.methods --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mtds.nodes.size(); i++) {
		mtd = mtds.nodes[i];

		dbswznm->tblwznmammethodinvpar->loadRstByMtd(mtd->ref, false, ipas);
		dbswznm->tblwznmammethodretpar->loadRstByMtd(mtd->ref, false, rpas);

		outfile << "\t\t";
		if (i != 0) outfile << "} else ";
		outfile << "if ((ixVMethod == VecVMethod::" << StrMod::uc(mtd->sref) << ") && (req->method->parsInv.size() == " << ipas.nodes.size() << ") && (req->method->parsRet.size() == " << (rpas.nodes.size()+1) << ")) {" << endl;

		outfile << "\t\t\t*((bool*) (req->method->parsRet[0])) = " << mtd->sref << "(dbs" << prjshort;

		for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
			ipa = ipas.nodes[j];
			outfile << ", *((const " << getIparpaCppType(ipa->ixWznmVVartype) << "*) (req->method->parsInv[" << j << "]))";
		};

		for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
			rpa = rpas.nodes[j];
			outfile << ", *((" << getIparpaCppType(rpa->ixWznmVVartype) << "*) (req->method->parsRet[" << (j+1) << "]))";
		};

		outfile << ");" << endl;
	};
	if (mtds.nodes.size() > 0) outfile << "\t\t};" << endl;
	outfile << "// IP handleRequest.methods --- IEND" << endl;

	// --- handleRequest.timer*
	if (hastmr) outfile << "// IP handleRequest.timer --- AFFIRM" << endl;
	else outfile << "// IP handleRequest.timer --- REMOVE" << endl;

	// --- handleRequest.timers
	outfile << "// IP handleRequest.timers --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::TMR) {
			analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);
			if (fctname != "") {
				outfile << "\t\t";

				if (first) first = false;
				else outfile << "else ";

				if (fctif != "") outfile << "if " << fctif << " ";

				outfile << fctname << "(dbs" << prjshort;
				if (!skipsref) outfile << ", req->sref";
				outfile << ");" << endl;
			};
		};
	};
	outfile << "// IP handleRequest.timers --- IEND" << endl;

	// --- cmds
	outfile << "// IP cmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		outfile << "bool " << job->sref << "::handle" << StrMod::cap(cmd->sref) << "(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tbool retval = false;" << endl;
		outfile << "\t// IP handle" << StrMod::cap(cmd->sref) << " --- INSERT" << endl;
		outfile << "\treturn retval;" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP cmds --- IEND" << endl;

	// --- dpchapps
	outfile << "// IP dpchapps --- IBEGIN" << endl;

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		blk = dpchs.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		// distinguish special cases
		if (subsref == "DpchAppLogin") {
			outfile << "void " << job->sref << "::handleDpchAppLogin(" << endl;
			outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
			outfile << "\t\t\t, " << subsref << "* " << StrMod::lc(subsref) << endl;
			outfile << "\t\t\t, const string ip" << endl;
			outfile << "\t\t\t, DpchEng" << Prjshort << "** dpcheng" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\t// IP handleDpchAppLogin --- INSERT" << endl;
			outfile << "};" << endl;
			outfile << endl;

		} else if (subsref == "DpchAppData") {
			dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &blk2)) {
						outfile << "void " << job->sref << "::handleDpchAppData" << StrMod::cap(bit->sref) << "(" << endl;
						outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
						outfile << "\t\t\t, " << getBlkclass(dbswznm, job, blk2) << "* _" << bit->sref << endl;
						outfile << "\t\t\t, DpchEng" << Prjshort << "** dpcheng" << endl;
						outfile << "\t\t) {" << endl;
						outfile << "\tset<uint> diffitems;" << endl;
						outfile << "\tset<uint> moditems;" << endl;
						outfile << endl;

						outfile << "\tdiffitems = _" << bit->sref << "->diff(&" << getBlkvar(job, blks, jrjs, bit->sref) << ");" << endl;

						outfile << "\t// IP handleDpchAppData" << StrMod::cap(bit->sref) << " --- INSERT" << endl;

						outfile << "\tinsert(moditems, DpchEngData::" << Wznm::getBitmasksref(bit->sref) << ");" << endl;
						outfile << "\t*dpcheng = getNewDpchEng(moditems);" << endl;
						outfile << "};" << endl;
						outfile << endl;

						delete blk2;
					};
				};
			};

		} else if (subsref == "DpchAppDo") {
			dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if ((bit->ixWznmVVartype == VecWznmVVartype::VECSREF) && (bit->refWznmMVector != 0)) {
					if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
						subsref2 = Wznm::getSubsref(job, vec->sref); // ex. VecVDlgBrlyNavLoainiDoPpr -> VecVDoPpr

						ptr = subsref2.find("Do");
						if (ptr != string::npos) {
							dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

							outfile << endl;
							for (unsigned int k = 0; k < vits.nodes.size(); k++) {
								vit = vits.nodes[k];

								outfile << "void " << job->sref << "::handleDpchApp" << subsref2.substr(ptr) << StrMod::cap(vit->sref) << "(" << endl;
								outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
								outfile << "\t\t\t, DpchEng" << Prjshort << "** dpcheng" << endl;
								outfile << "\t\t) {" << endl;

								// look for stage triggered by click on button
								found = false;
								
								if ((vit->sref.rfind("Click")+5) == vit->sref.length()) {
									s = vit->sref.substr(0, vit->sref.length()-5);

									for (unsigned int l = 0; l < cons.nodes.size(); l++) {
										con = cons.nodes[l];

										if (con->sref == (subsref2.substr(ptr+2) + s)) {
											for (unsigned int m = 0; m < snss.nodes.size(); m++) {
												sns = snss.nodes[m];

												if ((sns->ixVBasetype == VecWznmVMSensitivityBasetype::CON) && (sns->refWznmMControl == con->ref) && (sns->ixVAction == VecWznmVMSensitivityAction::CHGSGE)) {
													if (srefsSges.find(sns->csgRefWznmMStage) != srefsSges.end()) {
														found = true;
														break;
													};
												};

												if (found) break;
											};
										};

										if (found) break;
									};
								};

								if (found) {
									// use s, con and sns as identified above
									outfile << "\t// IP handleDpchApp" << subsref2.substr(ptr) << StrMod::cap(vit->sref) << " --- BEGIN" << endl;

									// current stage requirement should be part of Active rule
									tab = "\t";
									if ((con->Avail.length() > 0) && (con->Active.length() > 0)) {
										outfile << "\tif (statshr" << StrMod::lc(subsref2.substr(ptr+2)) << "." << s << "Avail && statshr" << StrMod::lc(subsref2.substr(ptr+2)) << "." << s << "Active) {" << endl;
									} else if (con->Avail.length() > 0) {
										outfile << "\tif (statshr" << StrMod::lc(subsref2.substr(ptr+2)) << "." << s << "Avail) {" << endl;
									} else if (con->Active.length() > 0) {
										outfile << "\tif (statshr" << StrMod::lc(subsref2.substr(ptr+2)) << "." << s << "Active) {" << endl;
									} else tab = "";

									outfile << tab << "\tchangeStage(dbs" << prjshort << ", VecVSge::" << StrMod::uc(srefsSges[sns->csgRefWznmMStage]) << ", dpcheng);" << endl;

									if ((con->Avail.length() > 0) || (con->Active.length() > 0)) outfile << "\t};" << endl;

									outfile << "\t// IP handleDpchApp" << subsref2.substr(ptr) << StrMod::cap(vit->sref) << " --- END" << endl;

								} else {
									outfile << "\t// IP handleDpchApp" << subsref2.substr(ptr) << StrMod::cap(vit->sref) << " --- INSERT" << endl;
								};

								outfile << "};" << endl;
								outfile << endl;
							};
						};

						delete vec;
					};
				};
			};
		} else {
			outfile << "void " << job->sref << "::handle" << subsref << "(" << endl;
			outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
			outfile << "\t\t\t, " << subsref << "* " << StrMod::lc(subsref) << endl;
			outfile << "\t\t\t, DpchEng" << Prjshort << "** dpcheng" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\t// IP handle" << subsref << " --- INSERT" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};

	outfile << "// IP dpchapps --- IEND" << endl;

	// --- dpchrets
	outfile << "// IP dpchrets --- IBEGIN" << endl;
	for (unsigned int i = 0; i < rets.nodes.size(); i++) {
		blk = rets.nodes[i];

		if (blk) {
			outfile << "void " << job->sref << "::handle" << blk->sref << "(" << endl;
			outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
			outfile << "\t\t\t, " << blk->sref << "* dpchret" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\t// IP handle" << blk->sref << " --- INSERT" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP dpchrets --- IEND" << endl;

	// --- uploads
	outfile << "// IP uploads --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::ULD) {
			analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);

			if (fctname != "") {
				outfile << "void " << job->sref << "::" << fctname << "(" << endl;
				outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
				outfile << "\t\t\t, const string& filename" << endl;
				outfile << "\t\t) {" << endl;

				// upload handler without custom code to pick up file name doesn't make sense
				outfile << "\t// IP " << fctname << " --- INSERT" << endl;
				if ( (sns->ixVAction == VecWznmVMSensitivityAction::CHGSGE) && (srefsSges.find(sns->csgRefWznmMStage) != srefsSges.end()) ) {
					outfile << "\tchangeStage(dbs" << prjshort << ", VecVSge::" << StrMod::uc(srefsSges[sns->csgRefWznmMStage]) << ");" << endl;
				};

				outfile << "};" << endl;
				outfile << endl;
			};
		};
	};
	outfile << "// IP uploads --- IEND" << endl;

	// --- downloads
	outfile << "// IP downloads --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::DLD) {
			analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);

			if (fctname != "") {
				outfile << "string " << job->sref << "::" << fctname << "(" << endl;
				outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
				outfile << "\t\t) {" << endl;

				outfile << "\treturn(\"\"); // IP " << fctname << " --- LINE" << endl;

				outfile << "};" << endl;
				outfile << endl;
			};
		};
	};
	outfile << "// IP downloads --- IEND" << endl;

	// --- timers
	outfile << "// IP timers --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::TMR) {
			analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);

			if (fctname != "") {
				outfile << "void " << job->sref << "::" << fctname << "(" << endl;
				outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
				if (!skipsref) outfile << "\t\t\t, const string& sref" << endl;
				outfile << "\t\t) {" << endl;

				found = false;

				if (sns->refWznmMStage != 0)
					for (unsigned int j = 0; j < sges.nodes.size(); j++) {
						sge = sges.nodes[j];
						if (sge->ref == sns->refWznmMStage) {
							found = true;
							break;
						};
					};

				if (found) {
					if ((sge->Monitvl != 0) && (sns->Srefmask == "mon")) outfile << "\twrefLast = xchg->addWakeup(jref, \"mon\", " << sge->Monitvl << ", true);" << endl;

					// special treatment for IMMCB and OTHWC stages
					if (sge->ixVBasetype == VecWznmVMStageBasetype::IMMCB) {
						outfile << "\tchangeStage(dbs" << prjshort << ", nextIxVSgeSuccess);" << endl;

					} else if (sge->ixVBasetype == VecWznmVMStageBasetype::OTHWC) {
						// re-enter
						if (sns->Custcode) outfile << "\t// IP " << fctname << " --- INSERT" << endl;
						outfile << "\tchangeStage(dbs" << prjshort << ", ixVSge);" << endl;

					} else {
						// proceed in standard fashion
						found = false;
					};
				};

				if (!found) {
					if ( (sns->ixVAction == VecWznmVMSensitivityAction::CHGSGE) && (srefsSges.find(sns->csgRefWznmMStage) != srefsSges.end()) ) {
						if (sns->Custcode) outfile << "\t// IP " << fctname << " --- INSERT" << endl;
						outfile << "\tchangeStage(dbs" << prjshort << ", VecVSge::" << StrMod::uc(srefsSges[sns->csgRefWznmMStage]) << ");" << endl;

					} else outfile << "\t// IP " << fctname << " --- INSERT" << endl;
				};

				outfile << "};" << endl;
				outfile << endl;
			};
		};
	};
	outfile << "// IP timers --- IEND" << endl;

	// --- handleCall
	outfile << "// IP handleCall --- IBEGIN" << endl;
	if (hascall) {
		outfile << "void " << job->sref << "::handleCall(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t\t, Call* call" << endl;
		outfile << "\t\t) {" << endl;

		first = true;

		for (unsigned int i = 0; i < snss.nodes.size(); i++) {
			sns = snss.nodes[i];

			if (sns->refWznmMCall != 0) if (dbswznm->tblwznmmcall->loadRecByRef(sns->refWznmMCall, &cal)) {
				analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);

				if (fctname != "") {
					outfile << "\t";
					if (first) first = false;
					else outfile << "} else ";
					outfile << "if " << fctif << " {" << endl;

					outfile << "\t\tcall->abort = " << fctname << "(dbs" << prjshort;
					if ((sns->ixVJobmask != VecWznmVMSensitivityJobmask::SELF) && (sns->ixVJobmask != VecWznmVMSensitivityJobmask::SPEC)) outfile << ", call->jref";

					if ((cal->invIxWznmWArgtype & VecWznmWArgtype::IX) & ~skipInvIxWznmWArgtype) outfile << ", call->argInv.ix";
					if ((cal->invIxWznmWArgtype & VecWznmWArgtype::REF) & ~skipInvIxWznmWArgtype) outfile << ", call->argInv.ref";
					if ((cal->invIxWznmWArgtype & VecWznmWArgtype::SREF) & ~skipInvIxWznmWArgtype) outfile << ", call->argInv.sref";
					if ((cal->invIxWznmWArgtype & VecWznmWArgtype::INTVAL) & ~skipInvIxWznmWArgtype) outfile << ", call->argInv.intval";
					if ((cal->invIxWznmWArgtype & VecWznmWArgtype::DBLVAL) & ~skipInvIxWznmWArgtype) outfile << ", call->argInv.dblval";
					if ((cal->invIxWznmWArgtype & VecWznmWArgtype::BOOLVAL) & ~skipInvIxWznmWArgtype) outfile << ", call->argInv.boolval";
					if ((cal->invIxWznmWArgtype & VecWznmWArgtype::TXTVAL) & ~skipInvIxWznmWArgtype) outfile << ", call->argInv.txtval";

					if (cal->retIxWznmWArgtype & VecWznmWArgtype::IX) outfile << ", call->argRet.ix";
					if (cal->retIxWznmWArgtype & VecWznmWArgtype::REF) outfile << ", call->argRet.ref";
					if (cal->retIxWznmWArgtype & VecWznmWArgtype::SREF) outfile << ", call->argRet.sref";
					if (cal->retIxWznmWArgtype & VecWznmWArgtype::INTVAL) outfile << ", call->argRet.intval";
					if (cal->retIxWznmWArgtype & VecWznmWArgtype::DBLVAL) outfile << ", call->argRet.dblval";
					if (cal->retIxWznmWArgtype & VecWznmWArgtype::BOOLVAL) outfile << ", call->argRet.boolval";
					if (cal->retIxWznmWArgtype & VecWznmWArgtype::TXTVAL) outfile << ", call->argRet.txtval";

					outfile << ");" << endl;
				};

				delete cal;
			};
		};

		if (!first) outfile << "\t};" << endl;
		outfile << "};" << endl;
	};
	outfile << "// IP handleCall --- IEND" << endl;

	// --- calls
	outfile << "// IP calls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < snss.nodes.size(); i++) {
		sns = snss.nodes[i];

		if (sns->refWznmMCall != 0) if (dbswznm->tblwznmmcall->loadRecByRef(sns->refWznmMCall, &cal)) {
			analyzeSns(dbswznm, sns, csasJrjs, srefsSges, Prjshort, fctname, fctif, skipInvIxWznmWArgtype, skipsref, skipsge, arg, nonspecarg);

			if (fctname != "") {
				outfile << "bool " << job->sref << "::" << fctname << "(" << endl;
				outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
				if ((sns->ixVJobmask != VecWznmVMSensitivityJobmask::SELF) && (sns->ixVJobmask != VecWznmVMSensitivityJobmask::SPEC)) outfile << "\t\t\t, const ubigint jrefTrig" << endl;

				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::IX) & ~skipInvIxWznmWArgtype) outfile << "\t\t\t, const uint ixInv" << endl;
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::REF) & ~skipInvIxWznmWArgtype) outfile << "\t\t\t, const ubigint refInv" << endl;
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::SREF) & ~skipInvIxWznmWArgtype) outfile << "\t\t\t, const string& srefInv" << endl;
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::INTVAL) & ~skipInvIxWznmWArgtype) outfile << "\t\t\t, const int intvalInv" << endl;
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::DBLVAL) & ~skipInvIxWznmWArgtype) outfile << "\t\t\t, const double dblvalInv" << endl;
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::BOOLVAL) & ~skipInvIxWznmWArgtype) outfile << "\t\t\t, const bool boolvalInv" << endl;
				if ((cal->invIxWznmWArgtype & VecWznmWArgtype::TXTVAL) & ~skipInvIxWznmWArgtype) outfile << "\t\t\t, const string& txtvalInv" << endl;

				if (cal->retIxWznmWArgtype & VecWznmWArgtype::IX) outfile << "\t\t\t, uint& ixRet" << endl;
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::REF) outfile << "\t\t\t, ubigint& refRet" << endl;
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::SREF) outfile << "\t\t\t, string& srefRet" << endl;
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::INTVAL) outfile << "\t\t\t, int& intvalRet" << endl;
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::DBLVAL) outfile << "\t\t\t, double& dblvalRet" << endl;
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::BOOLVAL) outfile << "\t\t\t, bool& boolvalRet" << endl;
				if (cal->retIxWznmWArgtype & VecWznmWArgtype::TXTVAL) outfile << "\t\t\t, string& txtvalRet" << endl;

				outfile << "\t\t) {" << endl;
				outfile << "\tbool retval = false;" << endl;

				found = false;

				if (cal->refIxVTbl == VecWznmVMCallRefTbl::CHK) {
					s = getChkeval(dbswznm, job->refWznmMVersion, Prjshort, rectbls, NULL, cal, false);
					found = (s != "");

					if (found) outfile << "\tboolvalRet = " << s << "; // IP " << fctname << " --- LINE" << endl;
				};

				if (!found) outfile << "\t// IP " << fctname << " --- INSERT" << endl;

				outfile << "\treturn retval;" << endl;
				outfile << "};" << endl;
				outfile << endl;
			};

			delete cal;
		};
	};
	outfile << "// IP calls --- IEND" << endl;

	if (hassge) {
		// --- changeStage*
		outfile << "// IP changeStage --- AFFIRM" << endl;

		// --- changeStage.hdr*
		if (!hasdpch) outfile << "// IP changeStage.hdr --- AFFIRM" << endl;
		else outfile << "// IP changeStage.hdr --- REMOVE" << endl;

		// --- dpchchangeStage.hdr*
		if (hasdpch) outfile << "// IP dpchchangeStage.hdr --- AFFIRM" << endl;
		else outfile << "// IP dpchchangeStage.hdr --- REMOVE" << endl;

		// --- changeStage.leave
		outfile << "// IP changeStage.leave --- IBEGIN" << endl;
		for (unsigned int i = 0; i < sges.nodes.size(); i++) {
			sge = sges.nodes[i];
			outfile << "\t\t\t\tcase VecVSge::" << StrMod::uc(sge->sref) << ": leaveSge" << StrMod::cap(sge->sref) << "(dbs" << prjshort << "); break;" << endl;
		};
		outfile << "// IP changeStage.leave --- IEND" << endl;

		// --- changeStage.refresh1
		if (hasdpch) {
			outfile << "// IP changeStage.refresh1 --- IBEGIN" << endl;
			outfile << "\t\t\trefreshWithDpchEng(dbs" << prjshort << ", dpcheng); // IP changeStage.refresh1 --- LINE" << endl;
			outfile << "// IP changeStage.refresh1 --- IEND" << endl;
		};

		// --- changeStage.enter
		outfile << "// IP changeStage.enter --- IBEGIN" << endl;
		for (unsigned int i = 0; i < sges.nodes.size(); i++) {
			sge = sges.nodes[i];
			outfile << "\t\t\tcase VecVSge::" << StrMod::uc(sge->sref) << ": _ixVSge = enterSge" << StrMod::cap(sge->sref) << "(dbs" << prjshort << ", reenter); break;" << endl;
		};
		outfile << "// IP changeStage.enter --- IEND" << endl;

	} else {
		// --- changeStage*
		outfile << "// IP changeStage --- REMOVE" << endl;
	};

	// --- getSquawk
	outfile << "// IP getSquawk --- IBEGIN" << endl;
	if (hassge) {
		outfile << "string " << job->sref << "::getSquawk(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tstring retval;" << endl;
		outfile << "\t// IP getSquawk --- BEGIN" << endl;

		// categorize stages: icsSges - non-empty squawk ; icsSges2 - type opp ; icsSges3 - type oppiw ; icsSges4 - type err
		for (unsigned int i = 0; i < sges.nodes.size(); i++) {
			sge = sges.nodes[i];

			found = false;

			if (sge->ixVBasetype == VecWznmVMStageBasetype::ERR) {
				icsSges4.push_back(i);
				found = true;
			};

			if (!found) {
				if (dbswznm->tblwznmmsquawk->loadRecByRef(sge->refWznmMSquawk, &sqk)) {
					if (sqk->Title.length() != 0) {
						icsSges.push_back(i);
						found = true;
					};
					delete sqk;
				};
			};

			if (!found) {
				if (sge->ixVBasetype == VecWznmVMStageBasetype::OPP) icsSges2.push_back(i);
				else if (sge->ixVBasetype == VecWznmVMStageBasetype::OPPIW) icsSges3.push_back(i);
			};
		};

		if ( (icsSges.size() == 0) && (icsSges2.size() == 0) && (icsSges3.size() == 0) && (icsSges4.size() == 0) ) {
			outfile << "\tretval = VecVSge::getSref(ixVSge);" << endl;

		} else {
			first = true;

			if (icsSges.size() != 0) {
				first = false;

				ss.resize(0);
				for (unsigned int i = 0; i < icsSges.size(); i++) ss.push_back(sges.nodes[icsSges[i]]->sref);
				outfile << "\t" << genSgeif(ss, Prjshort) << " {" << endl;

				for (unsigned int j = 0; j < lcls.nodes.size(); j++) {
					lcl = lcls.nodes[j];

					outfile << "\t\t";
					if (j != 0) outfile << "} else ";
					outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") {" << endl;
					
					for (unsigned int k = 0; k < icsSges.size(); k++) {
						sge = sges.nodes[icsSges[k]];

						outfile << "\t\t\t";
						if (k != 0) outfile << "else ";
						outfile << "if (ixVSge == VecVSge::" << StrMod::uc(sge->sref) << ") ";

						// copy localized squawk
						if (!dbswznm->tblwznmjmsquawktitle->loadTitBySqkLoc(sge->refWznmMSquawk, lcl->ref, s)) {
							dbswznm->loadStringBySQL("SELECT Title FROM TblWznmMSquawk WHERE ref = " + to_string(sge->refWznmMSquawk), s);
						};
						outfile << "retval = \"" << StrMod::esc(rplSqkstr(s)) << "\";" << endl;
					};
				};
				if (lcls.nodes.size() > 0) outfile << "\t\t};" << endl;

				outfile << endl;
			};

			if (icsSges2.size() != 0) {
				ss.resize(0);
				for (unsigned int i = 0; i < icsSges2.size(); i++) ss.push_back(sges.nodes[icsSges2[i]]->sref);

				outfile << "\t";

				if (first) first = false;
				else outfile << "} else ";

				outfile << genSgeif(ss, Prjshort) << " {" << endl;

				outfile << "\t\tretval = VecVSge::getSref(ixVSge) + \" (\" + to_string(opN) + \" \" + Vec" << Prjshort << "VTag::getTitle(ix" << Prjshort << "VLocale, Vec" << Prjshort << "VTag::OPSPREP) + \")\";" << endl;

				outfile << endl;
			};

			if (icsSges3.size() != 0) {
				ss.resize(0);
				for (unsigned int i = 0; i < icsSges3.size(); i++) ss.push_back(sges.nodes[icsSges3[i]]->sref);

				outfile << "\t";

				if (first) first = false;
				else outfile << "} else ";

				outfile << genSgeif(ss, Prjshort) << " {" << endl;

				outfile << "\t\tretval = VecVSge::getSref(ixVSge) + \" (\" + to_string(opNSuccess + opNFailure) + \"/\" + to_string(opN) + \" \" + Vec" << Prjshort << "VTag::getTitle(ix" << Prjshort << "VLocale, Vec" << Prjshort << "VTag::OPSCPLLAST) + \": \" + getOpsqkLast() + \")\";" << endl;

				outfile << endl;
			};

			if (icsSges4.size() != 0) {
				ss.resize(0);
				for (unsigned int i = 0; i < icsSges4.size(); i++) ss.push_back(sges.nodes[icsSges4[i]]->sref);

				outfile << "\t";

				if (first) first = false;
				else outfile << "} else ";

				outfile << genSgeif(ss, Prjshort) << " {" << endl;

				outfile << "\t\tretval = lasterror;" << endl;
				outfile << endl;
			};

			outfile << "\t} else {" << endl;
			outfile << "\t\tretval = VecVSge::getSref(ixVSge);" << endl;
			outfile << "\t};" << endl;
		};

		outfile << "\t// IP getSquawk --- END" << endl;
		outfile << "\treturn retval;" << endl;
		outfile << "};" << endl;
	};
	outfile << "// IP getSquawk --- IEND" << endl;

	// --- sges
	outfile << "// IP sges --- IBEGIN" << endl;
	for (unsigned int i = 0; i < sges.nodes.size(); i++) {
		sge = sges.nodes[i];

		outfile << "uint " << job->sref << "::enterSge" << StrMod::cap(sge->sref) << "(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t\t, const bool reenter" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tuint retval";
		if ((sge->snxRefWznmMStage == 0) || (sge->ixVBasetype == VecWznmVMStageBasetype::ALR) || (sge->ixVBasetype == VecWznmVMStageBasetype::OPIW) || (sge->ixVBasetype == VecWznmVMStageBasetype::OPPIW)
					|| (sge->ixVBasetype == VecWznmVMStageBasetype::IMMCB)) outfile << " = VecVSge::" << StrMod::uc(sge->sref);
		outfile << ";" << endl;

		if (sge->snxRefWznmMStage != 0) {
			outfile << "\tnextIxVSgeSuccess = VecVSge::" << StrMod::uc(srefsSges[sge->snxRefWznmMStage]) << ";" << endl;
			if ((sge->ixVBasetype != VecWznmVMStageBasetype::ALR) && (sge->ixVBasetype != VecWznmVMStageBasetype::OPIW) && (sge->ixVBasetype != VecWznmVMStageBasetype::OPPIW)
						&& (sge->ixVBasetype != VecWznmVMStageBasetype::IMMCB)) outfile << "\tretval = nextIxVSgeSuccess;" << endl;
		};
		if (sge->fnxRefWznmMStage != 0) outfile << "\tnextIxVSgeFailure = VecVSge::" << StrMod::uc(srefsSges[sge->fnxRefWznmMStage]) << ";" << endl;

		outfile << endl;

		if (sge->ixVBasetype == VecWznmVMStageBasetype::ALR) {
			// implementation of alert stage
			stdalr = false;

			s = StrMod::cap(sge->sref);
			if ( (s.find("Alr") == 0) && (s.length() > 3) ) {
				s[3] = toupper(s[3]);
				if ( (s.find(Prjshort) == 3) && (s.length() > 7) ) {
					s[7] = toupper(s[7]);
					stdalr = true;
				};
			};

			con = NULL;

			if (stdalr) {
				dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::VER) + " AND hkUref = "
					+ to_string(job->refWznmMVersion) + " AND sref = '" + s + "'", &con);
			} else {
				if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR)
							+ " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + s + "'", &con);
				else if (job->refIxVTbl == VecWznmVMJobRefTbl::DLG) dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG)
							+ " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + s + "'", &con);
				else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL)
							+ " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + s + "'", &con);
			};

			if (con) {
				getAlrplhs(dbswznm, con->ref, plhs);

				if (stdalr) {
					outfile << "\txchg->submitDpch(Alr" << Prjshort << "::prepareAlr" << s.substr(3+4) << "(jref, ix" << Prjshort << "VLocale";
					for (unsigned int j = 0; j < plhs.size(); j++) outfile << ", \"\"";
					if (con->sref.substr(3+4) == "Trm") outfile << ", xchg->stg" << prjshort << "appearance.sesstterm, xchg->stg" << prjshort << "appearance.sesstwarn";
					outfile << ", feedFMcbAlert)); // IP enterSge" << StrMod::cap(sge->sref) << " --- LINE" << endl;

				} else {
					outfile << "\tContInf" << Prjshort << "Alert continf;" << endl;
					outfile << "\t// IP enterSge" << StrMod::cap(sge->sref) << " --- BEGIN" << endl;

					if (!plhs.empty()) {
						for (auto it = plhs.begin(); it != plhs.end(); it++) outfile << "\tstring " << *it << " = \"\";" << endl;

						outfile << endl;
					};

					wrAlrCpp(dbswznm, "", Prjshort, outfile, job->refWznmMVersion, con, plhs);
					outfile << "\t// IP enterSge" << StrMod::cap(sge->sref) << " --- END" << endl;
					outfile << "\txchg->submitDpch(new DpchEng" << Prjshort << "Alert(jref, &continf, &feedFMcbAlert, {DpchEng" << Prjshort << "Alert::ALL}));" << endl;
				};

				delete con;

			} else {
				outfile << "\t// IP enterSge" << StrMod::cap(sge->sref) << " --- INSERT" << endl;
			};

			outfile << endl;

		} else {
			// implementation of non-alert stages is manual
			if (sge->ixVBasetype == VecWznmVMStageBasetype::OPP) {
				outfile << "\tclearInvs();" << endl;
				outfile << endl;
			} else if (sge->ixVBasetype == VecWznmVMStageBasetype::OPIW) {
			} else if (sge->ixVBasetype == VecWznmVMStageBasetype::OPPIW) {
				outfile << "\tclearInvs();" << endl;
				outfile << endl;
			} else if (sge->ixVBasetype == VecWznmVMStageBasetype::IMMCB) {
				outfile << "\twrefLast = xchg->addWakeup(jref, \"callback\", 0);" << endl;
				outfile << endl;
			} else if (sge->ixVBasetype == VecWznmVMStageBasetype::OTHER) {
			} else if (sge->ixVBasetype == VecWznmVMStageBasetype::OTHWC) {
			};

			if (sge->Monitvl != 0) {
				outfile << "\tif (!reenter) wrefLast = xchg->addWakeup(jref, \"mon\", " << sge->Monitvl << ", true);" << endl;
				outfile << endl;
			};

			outfile << "\t// IP enterSge" << StrMod::cap(sge->sref) << " --- INSERT" << endl;
			outfile << endl;

			if (sge->ixVBasetype == VecWznmVMStageBasetype::OPP) {
			} else if ((sge->ixVBasetype == VecWznmVMStageBasetype::OPIW) || (sge->ixVBasetype == VecWznmVMStageBasetype::OPPIW)) {
				outfile << "\tsubmitInvs(dbs" << prjshort;

				if (sge->enxRefWznmMStage == 0) outfile << ", retval";
				else outfile << ", VecVSge::" << StrMod::uc(srefsSges[sge->enxRefWznmMStage]);

				outfile << ", retval);" << endl;

			} else if (sge->ixVBasetype == VecWznmVMStageBasetype::IMMCB) {
			} else if (sge->ixVBasetype == VecWznmVMStageBasetype::OTHER) {
			} else if (sge->ixVBasetype == VecWznmVMStageBasetype::OTHWC) {
			};
		};

		outfile << "\treturn retval;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "void " << job->sref << "::leaveSge" << StrMod::cap(sge->sref) << "(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t) {" << endl;

		if ((sge->ixVBasetype == VecWznmVMStageBasetype::OTHWC) || (sge->Monitvl != 0)) outfile << "\tinvalidateWakeups();" << endl;

		outfile << "\t// IP leaveSge" << StrMod::cap(sge->sref) << " --- INSERT" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP sges --- IEND" << endl;

	// --- clisrv*
	if (job->Clisrv) outfile << "// IP clisrv --- AFFIRM" << endl;
	else outfile << "// IP clisrv --- REMOVE" << endl;
};

void WznmWrsrvJob::wrIparpa(
			fstream& outfile
			, const string& sref
			, const string& Comment
			, const uint ixWznmVVartype
			, const bool newline
			, const bool refNotConst
			, const bool ns
		) {
	string amp;
	if (refNotConst) amp = "&";

	if (newline) outfile << "\t\t\t";
	outfile << ", ";
	if (!refNotConst) outfile << "const ";

	string stdns, sbens;
	if (ns) {
		stdns = "std::";
		sbens = "Sbecore::";
	};

	if (ixWznmVVartype == VecWznmVVartype::VOID) outfile << "void" << amp;
	else if (ixWznmVVartype == VecWznmVVartype::BOOLEAN) outfile << "bool" << amp;
	else if (ixWznmVVartype == VecWznmVVartype::INT) outfile << "int" << amp;
	else if (ixWznmVVartype == VecWznmVVartype::FLOAT) outfile << "float" << amp;
	else if (ixWznmVVartype == VecWznmVVartype::DOUBLE) outfile << "double" << amp;
	else if (ixWznmVVartype == VecWznmVVartype::STRING) outfile << stdns << "string&";
	else if (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) outfile << stdns << "vector<bool>&";
	else if (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) outfile << stdns << "vector<" << sbens << "utinyint>&";
	else if (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) outfile << stdns << "vector<" << sbens << "usmallint>&";
	else if (ixWznmVVartype == VecWznmVVartype::INTVEC) outfile << stdns << "vector<int>&";
	else if (ixWznmVVartype == VecWznmVVartype::UINTVEC) outfile << stdns << "vector<" << sbens << "uint>&";
	else if (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) outfile << stdns << "vector<" << sbens << "ubigint>&";
	else if (ixWznmVVartype == VecWznmVVartype::FLOATVEC) outfile << stdns << "vector<float>&";
	else if (ixWznmVVartype == VecWznmVVartype::FLOATMAT) outfile << sbens << "Floatmat&";
	else if (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) outfile << stdns << "vector<double>&";
	else if (ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) outfile << sbens << "Doublemat&";
	else if (ixWznmVVartype == VecWznmVVartype::STRINGVEC) outfile << stdns << "vector<" << stdns << "string>&";
	else if (ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << sbens << "uint" << amp;
	else if (ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << sbens << "ubigint" << amp;
	else {
		// TINYINT, UTINYINT, SMALLINT, USMALLINT, UINT, BIGINT, UBIGINT
		outfile << sbens << VecWznmVVartype::getSref(ixWznmVVartype) << amp;
	};

	outfile << " " << sref;

	if (newline) {
		if (Comment != "") outfile << " // " << Comment;
		outfile << endl;
	};
};

void WznmWrsrvJob::analyzeSns(
			DbsWznm* dbswznm
			, WznmMSensitivity* sns
			, const map<string,uint>& csasJrjs
			, const map<ubigint,string>& srefsSges
			, const string& Prjshort
			, string& fctname
			, string& fctif
			, uint& skipInvIxWznmWArgtype
			, bool& skipsref
			, bool& skipsge
			, Arg& arg
			, bool& nonspecarg
		) {
	// ex. handle {CallWznmStatchg/Upload/Download/Timer} FromSrcfpga WithSref{Test} InSgeIdle
	WznmMCall* cal = NULL;

	vector<string> ss, ss2;
	string s;

	uint ixWznmWArgtype;

	bool first, found;

	fctname = "";
	fctif = "";
	skipInvIxWznmWArgtype = 0;
	skipsref = false;
	skipsge = false;
	arg = Arg();
	nonspecarg = false;

	if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::CAL) {
		if (dbswznm->tblwznmmcall->loadRecByRef(sns->refWznmMCall, &cal)) {
			fctname = "handle" + StrMod::dotToUsc(cal->sref);
			fctif = "(call->ixVCall == Vec" + Prjshort + "VCall::" + StrMod::dotToUsc(StrMod::uc(cal->sref)) + ")";

			if (sns->ixVJobmask == VecWznmVMSensitivityJobmask::SELF) {
				fctname += "FromSelf";
				fctif += " && (call->jref == jref)";

			} else if (sns->ixVJobmask == VecWznmVMSensitivityJobmask::SPEC) {
				fctname += "From" + StrMod::cap(sns->Jobshort);

				found = false;

				if (csasJrjs.find(sns->Jobshort) != csasJrjs.end())
					if ((csasJrjs.at(sns->Jobshort) == VecWznmVRMJobMJobConstract::VOID) || (csasJrjs.at(sns->Jobshort) == VecWznmVRMJobMJobConstract::CUST)) {
						fctif += " && ([&](){bool match = false; if (" + sns->Jobshort + ") if (call->jref == " + sns->Jobshort + "->jref) match = true; return match;}())";
						found = true;
					};

				if (!found) fctif += " && (call->jref == " + sns->Jobshort + "->jref)";
			};

			if (sns->Argpatt != "") {
				first = true;

				StrMod::stringToVector(sns->Argpatt, ss, ',', true);

				for (unsigned int i = 0; i < ss.size(); i++) {
					StrMod::stringToVector(ss[i], ss2, '=', true);

					if (ss2.size() == 2) {
						// fixed argument, e.g. sref=test
						ixWznmWArgtype = VecWznmWArgtype::getIx(ss2[0]);

						if (ixWznmWArgtype != 0) {
							arg.mask |= ixWznmWArgtype;

							if (ixWznmWArgtype == Arg::IX) arg.ix = atol(ss2[1].c_str());
							else if (ixWznmWArgtype == Arg::REF) arg.ix = atoll(ss2[1].c_str());
							else if (ixWznmWArgtype == Arg::REFS) arg.refs = {}; // not supported
							else if (ixWznmWArgtype == Arg::SREF) arg.sref = ss2[1];
							else if (ixWznmWArgtype == Arg::INTVAL) arg.intval = atol(ss2[1].c_str());
							else if (ixWznmWArgtype == Arg::BOOLVAL) arg.boolval = (ss2[1] == "true");
							else if (ixWznmWArgtype == Arg::DBLVAL) arg.dblval = atof(ss2[1].c_str());
							else if (ixWznmWArgtype == Arg::TXTVAL) arg.txtval = ss2[1];

							if (first) {
								fctname += "With";
								first = false;
							};
							fctname += StrMod::cap(VecWznmWArgtype::getSrefs(ixWznmWArgtype)) + StrMod::cap(ss2[1]);

							fctif += " && (call->argInv." + VecWznmWArgtype::getSrefs(ixWznmWArgtype) + " == ";
							if ((ixWznmWArgtype == VecWznmWArgtype::SREF) || (ixWznmWArgtype == VecWznmWArgtype::TXTVAL)) fctif += "\"" + ss2[1] + "\"";
							else fctif += ss2[1];
							fctif += ")";

							skipInvIxWznmWArgtype |= ixWznmWArgtype;
						};

					} else {
						ixWznmWArgtype = VecWznmWArgtype::getIx(ss[i]);

						if (ixWznmWArgtype != 0) {
							// fixed argument type, e.g. sref
							arg.mask |= ixWznmWArgtype;

							nonspecarg = true;

							skipInvIxWznmWArgtype |= ixWznmWArgtype;
						};
					};
				};
			};

			delete cal;
		};

	} else if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::ULD) {
		fctname = "handleUpload";

	} else if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::DLD) {
		fctname = "handleDownload";

	} else if (sns->ixVBasetype == VecWznmVMSensitivityBasetype::TMR) {
		fctname = "handleTimer";
		
		if (sns->Srefmask != "") {
			fctname += "WithSref" + StrMod::cap(sns->Srefmask);

			if (fctif != "") fctif += " && ";
			fctif += "(req->sref == \"" + sns->Srefmask + "\")";

			skipsref = true;
		};
	};

	if ((fctname != "") && (srefsSges.find(sns->refWznmMStage) != srefsSges.end())) {
		fctname += "InSge" + StrMod::cap(srefsSges.at(sns->refWznmMStage));

		if (fctif != "") fctif += " && ";
		fctif += "(ixVSge == VecVSge::" + StrMod::uc(srefsSges.at(sns->refWznmMStage)) + ")";

		skipsge = true;
	};

	if (fctif.find("&&") != string::npos) fctif = "(" + fctif + ")";
};

string WznmWrsrvJob::genSgeif(
			vector<string>& ss
			, const string& Prjshort
		) {
	string retval;

	if (ss.size() == 1) {
		retval = "if (ixVSge == VecVSge::" + StrMod::uc(ss[0]) + ")";

	} else if (ss.size() > 1) {
		retval = "if (";
		for (unsigned int i = 0; i < ss.size(); i++) {
			if (i != 0) retval = retval + "||";
			retval = retval + " (ixVSge == VecVSge::" + StrMod::uc(ss[i]) + ") ";
		};
		retval = retval + ")";
	};

	return retval;
};

string WznmWrsrvJob::rplSqkstr(
			const string& sqkstr
		) {
	string s;

	s = StrMod::replacePlh(sqkstr, "N", "\" + to_string(opN) + \"");
	s = StrMod::replacePlh(s, "Ndone", "\" + to_string(opNSuccess + opNFailure) + \"");
	s = StrMod::replacePlh(s, "sqklast", "\" + getOpsqkLast() + \"");

	return s;
};
// IP cust --- IEND
