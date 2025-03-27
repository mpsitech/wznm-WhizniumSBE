/**
	* \file WznmWrsrvCrd.cpp
	* Wznm operation processor - write specific job C++ code for card (implementation)
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

#include "WznmWrsrvCrd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsrvCrd
 ******************************************************************************/

DpchRetWznm* WznmWrsrvCrd::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvCrd* dpchinv
		) {
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream cppfile;

	WznmMJob* job = NULL;
	WznmMCard* car = NULL;

	vector<string> bitsEval;
	vector<string> rulesEval;
	vector<string> exprsEval;

	string s;

	dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job);
	dbswznm->tblwznmmcard->loadRecByRef(job->refUref, &car);

	Wznm::getJobevals(dbswznm, job, bitsEval, rulesEval, exprsEval);

	// CrdXxxxYyy.h, CrdXxxxYyy.cpp
	s = xchg->tmppath + "/" + folder + "/" + car->sref + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/" + car->sref + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeCrdH(dbswznm, hfile, job, car, Prjshort);
	writeCrdCpp(dbswznm, cppfile, job, car, bitsEval, rulesEval, exprsEval, Prjshort);

	hfile.close();
	cppfile.close();

	delete job;
	delete car;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvCrd::writeCrdH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMCard* car
			, const string& Prjshort
		) {
	string prjshort = StrMod::lc(Prjshort);

	// --- constructor
	outfile << "// IP constructor --- RBEGIN" << endl;
	outfile << "\t" << car->sref << "(Xchg" << Prjshort << "* xchg, Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::ubigint jrefSup, const Sbecore::uint ix" << Prjshort << "VLocale";
	if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS)) outfile << ", const Sbecore::ubigint ref = 0";
	if (car->Active.length() > 0) outfile << ", const Sbecore::uint ix" << Prjshort << "VPreset = Vec" << Prjshort << "VPreset::VOID, const Sbecore::ubigint preUref = 0";
	outfile << ");" << endl;
	outfile << "// IP constructor --- REND" << endl;

	// -- specVar
	outfile << "// IP vars.spec --- IBEGIN" << endl;
	outfile << "// IP vars.spec --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;
	outfile << "\tDpchEng" << Prjshort << "* getNewDpchEng(std::set<Sbecore::uint> items);" << endl;

	outfile << "\tvoid refresh(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems, const bool unmute = false);" << endl;

	if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS))
				outfile << "\tvoid changeRef(Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::ubigint jrefTrig, const Sbecore::ubigint ref, const bool notif = false);" << endl;

	outfile << "\tvoid updatePreset(Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::uint ix" << Prjshort << "VPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);" << endl;

	if (car->sref.substr(3+4) == "Nav") outfile << "\tvoid warnTerm(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << "// IP spec --- IEND" << endl;
};

void WznmWrsrvCrd::writeCrdCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMCard* car
			, vector<string>& bitsEval
			, vector<string>& rulesEval
			, vector<string>& exprsEval
			, const string& Prjshort
		) {
	vector<ubigint> refs;
	ubigint ref;

	ListWznmAMBlockItem dpchengdatabits;
	ListWznmMBlock jobblks;
	ListWznmRMJobMJob jrjs;

	ListWznmMPanel pnls;
	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	WznmMStub* stb = NULL;

	WznmMTable* tbl = NULL;

	ListWznmMTable inctbls;
	WznmMTable* inctbl = NULL;
	map<ubigint,string> incconds;
	map<ubigint,string> incsbsconds;

	WznmMTablecol* tco = NULL;

	ListWznmMDialog dlgs;
	WznmMDialog* dlg = NULL;

	string PRJSHORT = StrMod::uc(Prjshort);
	string prjshort = StrMod::lc(Prjshort);

	string ixCarpst;
	string s, s2;

	bool hasGrpown;

	string pre;

	uint cnt;

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
				+ " AND sref = 'DpchEng" + car->sref.substr(3) + "Data'", ref)) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, dpchengdatabits);

	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref), false, jobblks);

	dbswznm->tblwznmrmjobmjob->loadRstBySup(job->ref, false, jrjs);

	dbswznm->tblwznmmpanel->loadRstByCar(car->ref, false, pnls);

	ixCarpst = "Vec" + Prjshort + "VPreset::PRE" + PRJSHORT + "REF" + StrMod::uc(car->sref.substr(3+4));

	// --- ns.spec
	outfile << "// IP ns.spec --- IBEGIN" << endl;
	outfile << "// IP ns.spec --- IEND" << endl;

	// --- constructor.hdr
	outfile << "// IP constructor.hdr --- RBEGIN" << endl;
	outfile << car->sref << "::" << car->sref << "(" << endl;
	outfile << "\t\t\tXchg" << Prjshort << "* xchg" << endl;
	outfile << "\t\t\t, Dbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const ubigint jrefSup" << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
	if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS)) outfile << "\t\t\t, const ubigint ref" << endl;
	if (car->Active.length() > 0) {
		outfile << "\t\t\t, const uint ix" << Prjshort << "VPreset" << endl;
		outfile << "\t\t\t, const ubigint preUref" << endl;
	};
	outfile << "\t\t) :" << endl;
	outfile << "\t\t\tJob" << Prjshort << "(xchg, Vec" << Prjshort << "VJob::" << StrMod::uc(car->sref) << ", jrefSup, ix" << Prjshort << "VLocale)" << endl;
	outfile << "\t\t{" << endl;
	outfile << "// IP constructor.hdr --- REND" << endl;

	if (car->sref.substr(3+4) == "Nav") {
		// --- constructor.spec1
		outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
		outfile << "\tset<uint> moditems;" << endl;
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
		outfile << "// IP constructor.spec1 --- IEND" << endl;

		// --- constructor.spec2
		outfile << "// IP constructor.spec2 --- IBEGIN" << endl;
		for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
			pnl = pnls.nodes[i];

			if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
				outfile << "\tstatshr.jref" << pnl->sref.substr(3+4+3) << " = pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "->jref;" << endl;
			};
		};
		outfile << endl;

		outfile << "\tchangeStage(dbs" << prjshort << ", VecVSge::IDLE);" << endl;
		outfile << endl;
		outfile << "// IP constructor.spec2 --- IEND" << endl;

	} else if ( (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) ) {
		// --- constructor.spec1
		outfile << "// IP constructor.spec1 --- IBEGIN" << endl;

		if (car->Active.length() > 0) {
			outfile << "\txchg->addIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXPRE, jref, ix" << Prjshort << "VPreset);" << endl;
			outfile << "\tif (ix" << Prjshort << "VPreset != Vec" << Prjshort << "VPreset::VOID) xchg->addRefPreset(ix" << Prjshort << "VPreset, jref, preUref);" << endl;
			outfile << endl;
		};

		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(job->refWznmMVersion) + " AND sref = 'Pre" + Prjshort + "Ref" + car->sref.substr(3+4) + "'", ref)) {
			// session-wide presetting
			outfile << "\tif ((ref + 1) != 0) xchg->triggerIxRefCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "REFPRESET, jref, " << ixCarpst << ", ref);" << endl;
			outfile << endl;
		};

		outfile << "\t// initialize according to ref" << endl;
		outfile << "\tchangeRef(dbs" << prjshort << ", jref, ((ref + 1) == 0) ? 0 : ref, false);" << endl;
		outfile << endl;

		outfile << "// IP constructor.spec1 --- IEND" << endl;

		// --- constructor.spec2
		outfile << "// IP constructor.spec2 --- IBEGIN" << endl;
		for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
			pnl = pnls.nodes[i];

			if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC)) {
				outfile << "\tstatshr.jref" << pnl->sref.substr(3+4+3) << " = pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "->jref;" << endl;
			};
		};
		outfile << endl;

		outfile << "\tset<uint> moditems;" << endl;
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
		outfile << endl;

		if (dbswznm->tblwznmmdialog->loadRecBySQL("SELECT * FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(car->ref) + " AND ixVBasetype = " + to_string(VecWznmVMDialogBasetype::NEW), &dlg)) {
			s2 = StrMod::lc("Dlg" + dlg->sref.substr(3+4+3));

			outfile << "\tif ((ref + 1) == 0) {" << endl;
			outfile << "\t\t" + s2 + " = new " << dlg->sref << "(xchg, dbs" << prjshort << ", jref, ix" << Prjshort << "VLocale);" << endl;
			outfile << "\t\tstatshr.jref" << StrMod::cap(s2) << " = " << s2 << "->jref;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

			delete dlg;
		};

		outfile << "\tchangeStage(dbs" << prjshort << ", VecVSge::IDLE);" << endl;
		outfile << endl;

		outfile << "// IP constructor.spec2 --- IEND" << endl;

	} else {
		// --- constructor.spec1
		outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
		outfile << "\tset<uint> moditems;" << endl;
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
		outfile << "// IP constructor.spec1 --- IEND" << endl;

		// --- constructor.spec2
		outfile << "// IP constructor.spec2 --- IBEGIN" << endl;
		for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
			pnl = pnls.nodes[i];

			if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
				outfile << "\tstatshr.jref" << pnl->sref.substr(3+4+3) << " = pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "->jref;" << endl;
			};
		};
		outfile << endl;

		outfile << "\tchangeStage(dbs" << prjshort << ", VecVSge::IDLE);" << endl;
		outfile << endl;
		outfile << "// IP constructor.spec2 --- IEND" << endl;
	};

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;

	// -- getNewDpchEng
	outfile << "DpchEng" << Prjshort << "* " << car->sref << "::getNewDpchEng(" << endl;
	outfile << "\t\t\tset<uint> items" << endl;
	outfile << "\t\t) {" << endl;
	wrGetnewdpchengCpp(dbswznm, Prjshort, outfile, dpchengdatabits, job, jobblks, jrjs);
	outfile << "};" << endl;
	outfile << endl;

	// -- refresh
	outfile << "void " << car->sref << "::refresh(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, set<uint>& moditems" << endl;
	outfile << "\t\t\t, const bool unmute" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (muteRefresh && !unmute) return;" << endl;
	outfile << "\tmuteRefresh = true;" << endl;
	outfile << endl;

	outfile << "\tContInf oldContinf(continf);" << endl;
	if (bitsEval.size() > 0) outfile << "\tStatShr oldStatshr(statshr);" << endl;
	outfile << endl;

	outfile << "\t// IP refresh --- BEGIN" << endl;

	if (car->sref.substr(3+4) == "Nav") {
		outfile << "\tstring s;" << endl;
		outfile << "\tvector<string> ss;" << endl;
		outfile << endl;

		outfile << "\t// continf" << endl;
		outfile << "\tcontinf.MrlAppHlp = xchg->helpurl + \"/" << car->sref << "/\" + Vec" << Prjshort << "VLocale::getSref(ix" << Prjshort << "VLocale);" << endl;
		outfile << endl;

		outfile << "\ts = Stub" << Prjshort << "::getStubSesMenu(dbs" << prjshort << ", xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SESS, jref), ix" << Prjshort << "VLocale, Stub::VecVNonetype::DASH);" << endl;
		outfile << "\tStrMod::stringToVector(s, ss);" << endl;
		outfile << endl;

		outfile << "\tif (ss.size() == 3) {" << endl;
		outfile << "\t\tcontinf.MtxSesSes1 = ss[0];" << endl;
		outfile << "\t\tcontinf.MtxSesSes2 = ss[1];" << endl;
		outfile << "\t\tcontinf.MtxSesSes3 = ss[2];" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

	} else {
		outfile << "\t// continf" << endl;
		outfile << "\tcontinf.MrlAppHlp = xchg->helpurl + \"/" << car->sref << "/\" + Vec" << Prjshort << "VLocale::getSref(ix" << Prjshort << "VLocale);" << endl;
		if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS)) {
			if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(car->ref)
						+ " AND sref = 'MtxCrd" + StrMod::cap(car->sref.substr(3+4)) + "'", &con)) {
				if (dbswznm->tblwznmmstub->loadRecByRef(con->stdRefWznmMStub, &stb)) {
					outfile << "\tcontinf." << con->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", xchg->getRefPreset(" << ixCarpst << ", jref), ix" << Prjshort << "VLocale, Stub::VecVNonetype::FULL);" << endl;
					delete stb;
				};
				delete con;
			};
		};
		outfile << endl;
	};

	if (bitsEval.size() > 0) {
		outfile << "\t// statshr" << endl;
		for (unsigned int i = 0; i < bitsEval.size(); i++) writeEvalstatshr(outfile, bitsEval[i], rulesEval[i], exprsEval[i], prjshort);
		outfile << endl;
	};

	outfile << "\t// IP refresh --- END" << endl;

	outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
	if (bitsEval.size() > 0) outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;

	outfile << endl;
	outfile << "\tmuteRefresh = false;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	if ( (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) ) {
		// -- changeRef
		outfile << "void " << car->sref << "::changeRef(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t\t, const ubigint jrefTrig" << endl;
		outfile << "\t\t\t, const ubigint ref" << endl;
		outfile << "\t\t\t, const bool notif" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tset<uint> moditems;" << endl;
		outfile << endl;

		// - presets also for inc'ed tables
		if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) dbswznm->tblwznmmtable->loadRecByRef(car->refUref, &tbl);
		else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = TblWznmMSubset.refWznmMTable AND TblWznmMSubset.ref = "
					+ to_string(car->refUref), &tbl);

		if (tbl) {
			Wznm::getCarincs(dbswznm, car, inctbls, incconds, incsbsconds);

			if (inctbls.nodes.size() > 0) {
				outfile << "\t" << tbl->sref.substr(3) << "* rec = NULL;" << endl;
				outfile << endl;
			};

			if (car->Active.length() > 0) {
				outfile << "\tuint ix" << Prjshort << "VPreset = xchg->getIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXPRE, jref);" << endl;
				outfile << endl;
			};

			// - check access in case card's table has access right management
			hasGrpown = false;

			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::GRP), cnt);

			if (cnt > 0) {
				dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::OWN), cnt);
				if (cnt > 0) hasGrpown = true;
			};

			if (hasGrpown) pre = "\t\t"; else pre = "\t";

			if (hasGrpown) {
				outfile << "\tuint ix" << Prjshort << "VRecaccess;" << endl;
				outfile << "\txchg->triggerIxRefToIxCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "RECACCESS, jref, Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref) << ", ref, ix" << Prjshort << "VRecaccess);" << endl;
				outfile << endl;

				outfile << "\tif (ix" << Prjshort << "VRecaccess != Vec" << Prjshort << "VRecaccess::NONE) {" << endl;
				outfile << "\t\txchg->addIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXRECACC, jref, ix" << Prjshort << "VRecaccess);" << endl;
				outfile << endl;
			};

			// - log access
			if (car->Active.length() == 0) {
				outfile << pre << "if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "LOG, jref, Vec" << Prjshort << "VPreset::VOID, 0, \"" << car->sref << "\", ref);" << endl;
			} else {
				outfile << pre << "if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "LOG, jref, ix" << Prjshort << "VPreset, xchg->getRefPreset(ix" << Prjshort << "VPreset, jref), \"" << car->sref << "\", ref);" << endl;
			};

			// - change card's selection
			if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) outfile << pre << "xchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REF" << StrMod::uc(tbl->Short) << ", jref, ref);" << endl;
			outfile << pre << "xchg->addRefPreset(" << ixCarpst << ", jref, ref);" << endl; // ixCarpst concerns subset if available

			if (inctbls.nodes.size() > 0) {
				outfile << endl;
				outfile << pre << "if (dbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRecByRef(ref, &rec)) {" << endl;

				for (unsigned int i = 0; i < inctbls.nodes.size(); i++) {
					inctbl = inctbls.nodes[i];

					if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::TBL)
								+ " AND fctUref = " + to_string(inctbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF), &tco)) {
						outfile << pre << "\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REF" << StrMod::uc(inctbl->Short) << ", jref, rec->" << tco->sref << ");" << endl;
						delete tco;
					};
				};

				outfile << endl;
				outfile << pre << "\tdelete rec;" << endl;
				outfile << pre << "};" << endl;
			};

			outfile << endl;

			outfile << pre << "if (pnllist) pnllist->updatePreset(dbs" << prjshort << ", " << ixCarpst << ", jrefTrig, notif);" << endl;
			outfile << pre << "if (pnlrec) pnlrec->updatePreset(dbs" << prjshort << ", " << ixCarpst << ", jrefTrig, notif);" << endl;
			outfile << endl;

			outfile << pre << "refresh(dbs" << prjshort << ", moditems);" << endl;
			outfile << pre << "if (notif) xchg->submitDpch(getNewDpchEng(moditems));" << endl;

			if (hasGrpown) outfile << "\t};" << endl;

			outfile << "};" << endl;
			outfile << endl;

			delete tbl;
		};
	};

	// -- updatePreset
	outfile << "void " << car->sref << "::updatePreset(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VPreset" << endl;
	outfile << "\t\t\t, const ubigint jrefTrig" << endl;
	outfile << "\t\t\t, const bool notif" << endl;
	outfile << "\t\t) {" << endl;

	if (car->sref.substr(3+4) == "Nav") {
		outfile << "\t// IP updatePreset --- BEGIN" << endl;

		outfile << "\tset<uint> moditems;" << endl;
		outfile << endl;

		// TBD: check for pst's with SESS scope

		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
		outfile << "\tif (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
			pnl = pnls.nodes[i];
			s = "pnl" + StrMod::lc(pnl->sref.substr(3+4+3));

			if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) {
				outfile << "\tif (" << s << ") if (jrefTrig != " << s << "->jref) " << s << "->updatePreset(dbs" << prjshort << ", ix" << Prjshort << "VPreset, jrefTrig, notif);" << endl;
			} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM)  {
				outfile << "\tif (" << s << ") " << s << "->updatePreset(dbs" << prjshort << ", ix" << Prjshort << "VPreset, jrefTrig, notif);" << endl;
			};
		};

		outfile << "\t// IP updatePreset --- END" << endl;

	} else {
		outfile << "\t// IP updatePreset --- INSERT" << endl;
	};

	outfile << "};" << endl;
	outfile << endl;

	if (car->sref.substr(3+4) == "Nav") {
		// -- warnTerm
		outfile << "void " << car->sref << "::warnTerm(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tif (ixVSge == VecVSge::IDLE) changeStage(dbs" << prjshort << ", VecVSge::ALR" << PRJSHORT << "TRM);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	outfile << "// IP spec --- IEND" << endl;

	// --- handleDpchAppXxxxInit
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IBEGIN" << endl;
	outfile << "\t*dpcheng = getNewDpchEng({DpchEngData::ALL});" << endl;
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IEND" << endl;

	// --- handleDpchAppXxxxAlert
	outfile << "// IP handleDpchApp" << Prjshort << "Alert --- IBEGIN" << endl;
	outfile << "\t// IP handleDpchApp" << Prjshort << "Alert --- BEGIN" << endl;
	outfile << "\tif (ixVSge == VecVSge::ALR" << PRJSHORT << "ABT) {" << endl;
	outfile << "\t\tchangeStage(dbs" << prjshort << ", nextIxVSgeSuccess);" << endl;
	if (car->sref.substr(3+4) == "Nav") {
		outfile << "\t} else if (ixVSge == VecVSge::ALR" << PRJSHORT << "TRM) {" << endl;
		outfile << "\t\tchangeStage(dbs" << prjshort << ", nextIxVSgeSuccess);" << endl;
	};
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\t*dpcheng = new DpchEng" << Prjshort << "Confirm(true, jref, \"\");" << endl;

	outfile << "\t// IP handleDpchApp" << Prjshort << "Alert --- END" << endl;
	outfile << "// IP handleDpchApp" << Prjshort << "Alert --- IEND" << endl;

	// --- handleDpchAppDoMitAppAbtClick
	outfile << "// IP handleDpchAppDoMitAppAbtClick --- IBEGIN" << endl;
	outfile << "\tchangeStage(dbs" << prjshort << ", VecVSge::ALR" << PRJSHORT << "ABT);" << endl;
	outfile << "\t*dpcheng = new DpchEng" << Prjshort << "Confirm(true, jref, \"\");" << endl;
	outfile << "// IP handleDpchAppDoMitAppAbtClick --- IEND" << endl;

	if (car->sref.substr(3+4) == "Nav") {
		// --- handleDpchAppDoMitAppLoiClick
		outfile << "// IP handleDpchAppDoMitAppLoiClick --- IBEGIN" << endl;
		outfile << "\tif (!dlgloaini) {" << endl;
		outfile << "\t\tdlgloaini = new Dlg" << Prjshort << "NavLoaini(xchg, dbs" << prjshort << ", jref, ix" << Prjshort << "VLocale);" << endl;
		outfile << "\t\tstatshr.jrefDlgloaini = dlgloaini->jref;" << endl;
		outfile << endl;

		outfile << "\t\t*dpcheng = getNewDpchEng({DpchEngData::STATSHR});" << endl;
		outfile << "\t};" << endl;
		outfile << "// IP handleDpchAppDoMitAppLoiClick --- IEND" << endl;

		// --- handleDpchAppDoMitSesSpsClick
		outfile << "// IP handleDpchAppDoMitSesSpsClick --- IBEGIN" << endl;
		outfile << "\tmuteRefresh = true;" << endl;
		outfile << endl;

		outfile << "\t*dpcheng = new DpchEng" << Prjshort << "Confirm(true, jref, \"\");" << endl;
		outfile << endl;

		outfile << "\txchg->triggerCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "SUSPSESS, xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFSESS, jref));" << endl;
		outfile << "// IP handleDpchAppDoMitSesSpsClick --- IEND" << endl;

		// --- handleDpchAppDoMitSesTrmClick
		outfile << "// IP handleDpchAppDoMitSesTrmClick --- IBEGIN" << endl;
		outfile << "\tmuteRefresh = true;" << endl;
		outfile << endl;

		outfile << "\t*dpcheng = new DpchEng" << Prjshort << "Confirm(true, jref, \"\");" << endl;
		outfile << endl;

		outfile << "\txchg->triggerBoolvalCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "LOGOUT, xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFSESS, jref), false);" << endl;
		outfile << "// IP handleDpchAppDoMitSesTrmClick --- IEND" << endl;
	};

	// --- handleDpchAppDoMitCrdXxxClick
	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(car->ref) + " AND sref LIKE 'MitCrd%'", false, cons);

	if (car->sref.substr(3+4) == "Nav") {
		// all menu items yield a new card
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			outfile << "// IP handleDpchAppDo" << con->sref << "Click --- IBEGIN" << endl;
			outfile << "\tubigint jrefNew = 0;" << endl;
			outfile << endl;

			outfile << "\txchg->triggerIxRefSrefIntvalToRefCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "CRDOPEN, jref, 0, 0, \"Crd" << Prjshort << con->sref.substr(3+3) << "\", 0, jrefNew);" << endl;
			outfile << endl;

			outfile << "\tif (jrefNew == 0) *dpcheng = new DpchEng" << Prjshort << "Confirm(false, 0, \"\");" << endl;
			outfile << "\telse *dpcheng = new DpchEng" << Prjshort << "Confirm(true, jrefNew, \"Crd" << Prjshort << con->sref.substr(3+3) << "\");" << endl;
			outfile << "// IP handleDpchAppDo" << con->sref << "Click --- IEND" << endl;
		};

	} else {
		// handle menu items that open a dialog
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->refIxVTbl == VecWznmVMControlRefTbl::DLG) {
				outfile << "// IP handleDpchAppDo" << con->sref << "Click --- IBEGIN" << endl;

				dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMDialog WHERE ref = " + to_string(con->refUref), s);
				s2 = StrMod::lc("Dlg" + s.substr(3+4+3));

				outfile << "\tif (!" << s2 << ") {" << endl;
				outfile << "\t\t" << s2 << " = new " << s << "(xchg, dbs" << prjshort << ", jref, ix" << Prjshort << "VLocale);" << endl;
				outfile << "\t\tstatshr.jref" << StrMod::cap(s2) << " = " << s2 << "->jref;" << endl;
				outfile << endl;

				outfile << "\t\t*dpcheng = getNewDpchEng({DpchEngData::STATSHR});" << endl;
				outfile << "\t};" << endl;
				outfile << "// IP handleDpchAppDo" << con->sref << "Click --- IEND" << endl;
			};
		};
	};

	// --- handleDpchAppDoClose
	if (car->sref.substr(3+4) == "Nav") {
		outfile << "// IP handleDpchAppDoClose --- IBEGIN" << endl;
		outfile << "\tmuteRefresh = true;" << endl;
		outfile << endl;

		outfile << "\t*dpcheng = new DpchEng" << Prjshort << "Confirm(true, jref, \"\");" << endl;
		outfile << endl;

		outfile << "\tif (xchg->stg" << prjshort << "behavior.suspsess) xchg->triggerCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "SUSPSESS, xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFSESS, jref));" << endl;
		outfile << "\telse xchg->triggerBoolvalCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "LOGOUT, xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFSESS, jref), false);" << endl;
		outfile << "// IP handleDpchAppDoClose --- IEND" << endl;

	} else {
		outfile << "// IP handleDpchAppDoClose --- IBEGIN" << endl;
		outfile << "\tmuteRefresh = true;" << endl;
		outfile << endl;

		outfile << "\t*dpcheng = new DpchEng" << Prjshort << "Confirm(true, jref, \"\");" << endl;
		outfile << "\txchg->triggerIxCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "CRDCLOSE, jref, Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref) << ");" << endl;
		outfile << "// IP handleDpchAppDoClose --- IEND" << endl;
	};

	if ( (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) ) {
		// --- handleCallXxxxRefPreSet
		outfile << "// IP handleCall" << Prjshort << "RefPreSet --- IBEGIN" << endl;
		outfile << endl;

		outfile << "\tif (ixInv == " << ixCarpst << ") {" << endl;
		outfile << "\t\tchangeRef(dbs" << prjshort << ", jrefTrig, refInv, true);" << endl;
		outfile << endl;

		outfile << "\t\tif (refInv == 0) pnlrec->minimize(dbs" << prjshort << ", true);" << endl;

		if (dbswznm->tblwznmmdialog->loadRecBySQL("SELECT * FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(car->ref) + " AND ixVBasetype = " + to_string(VecWznmVMDialogBasetype::NEW), &dlg)) {
			outfile << "\t\telse if ((jrefTrig == statshr.jrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << ") && (refInv != 0)) {" << endl;
			outfile << "\t\t\tpnllist->qry->rerun(dbs" << prjshort << ", true);" << endl;
			outfile << "\t\t\tpnllist->minimize(dbs" << prjshort << ", true);" << endl;
			outfile << "\t\t\tpnlrec->regularize(dbs" << prjshort << ", true);" << endl;
			outfile << "\t\t};" << endl;

			delete dlg;
		};

		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "// IP handleCall" << Prjshort << "RefPreSet --- IEND" << endl;
	};

	// --- handleCallXxxxDlgClose
	dbswznm->tblwznmmdialog->loadRstBySQL("SELECT * FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(car->ref) + " ORDER BY sref ASC", false, dlgs);

	if (dlgs.nodes.size() > 0) {
		outfile << "// IP handleCall" << Prjshort << "DlgClose --- IBEGIN" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < dlgs.nodes.size(); i++) {
			dlg = dlgs.nodes[i];

			s2 = StrMod::lc("Dlg" + dlg->sref.substr(3+4+3));

			outfile << "\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (" << s2 << ") {" << endl;

			outfile << "\t\tdelete " << s2 << ";" << endl;
			outfile << "\t\t" << s2 << " = NULL;" << endl;
			outfile << "\t\tstatshr.jref" << StrMod::cap(s2) << " = 0;" << endl;

			outfile << endl;
			outfile << "\t\txchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));" << endl;
		};
		outfile << "\t};" << endl;

		outfile << endl;
		outfile << "// IP handleCall" << Prjshort << "DlgClose --- IEND" << endl;
	};

	if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS)) {
		// --- handleCallXxxxStatChg
		outfile << "// IP handleCall" << Prjshort << "StatChg --- IBEGIN" << endl;
		outfile << "\tif (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ix" << Prjshort << "VExpstate == Vec" << Prjshort << "VExpstate::REGD) && (pnlrec->statshr.ix" << Prjshort << "VExpstate == Vec" << Prjshort << "VExpstate::REGD)) pnllist->minimize(dbs" << prjshort << ", true);" << endl;
		outfile << "// IP handleCall" << Prjshort << "StatChg --- IEND" << endl;
	};
};
// IP cust --- IEND
