/**
	* \file DlgWznmMchWriniscr.cpp
	* job handler for job DlgWznmMchWriniscr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmMchWriniscr.h"

#include "DlgWznmMchWriniscr_blks.cpp"
#include "DlgWznmMchWriniscr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmMchWriniscr
 ******************************************************************************/

DlgWznmMchWriniscr::DlgWznmMchWriniscr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMMCHWRINISCR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::WRI;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmMchWriniscr::~DlgWznmMchWriniscr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmMchWriniscr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continffia, &continfwri, &feedFDse, &feedFSge, &statshr, &statshrfia, &statshrwri, items);
	};

	return dpcheng;
};

void DlgWznmMchWriniscr::refreshWri(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrWri oldStatshrwri(statshrwri);
	ContInfWri oldContinfwri(continfwri);

	// IP refreshWri --- RBEGIN
	// continfwri
	continfwri.TxtPrg = getSquawk(dbswznm);

	// statshrwri
	statshrwri.ButRunActive = evalWriButRunActive(dbswznm);
	statshrwri.ButStoActive = evalWriButStoActive(dbswznm);

	// IP refreshWri --- REND
	if (statshrwri.diff(&oldStatshrwri).size() != 0) insert(moditems, DpchEngData::STATSHRWRI);
	if (continfwri.diff(&oldContinfwri).size() != 0) insert(moditems, DpchEngData::CONTINFWRI);
};

void DlgWznmMchWriniscr::refreshFia(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfFia oldContinffia(continffia);
	StatShrFia oldStatshrfia(statshrfia);

	// IP refreshFia --- RBEGIN

	string mchsref;

	mchsref = StubWznm::getStubMchSref(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMCH, jref));

	// continffia
	continffia.Dld = "init_" + mchsref + ".tgz";

	// statshrfia
	statshrfia.DldActive = evalFiaDldActive(dbswznm);

	// IP refreshFia --- REND
	if (continffia.diff(&oldContinffia).size() != 0) insert(moditems, DpchEngData::CONTINFFIA);
	if (statshrfia.diff(&oldStatshrfia).size() != 0) insert(moditems, DpchEngData::STATSHRFIA);
};

void DlgWznmMchWriniscr::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButDneActive = evalButDneActive(dbswznm);

	// contiac
	contiac.numFDse = ixVDit;

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshWri(dbswznm, moditems);
	refreshFia(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmMchWriniscr::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
	if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMINIT) {
			handleDpchAppWznmInit(dbswznm, (DpchAppWznmInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMMCHWRINISCRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMMCHWRINISCRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoWri != 0) {
				if (dpchappdo->ixVDoWri == VecVDoWri::BUTRUNCLICK) {
					handleDpchAppDoWriButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWri == VecVDoWri::BUTSTOCLICK) {
					handleDpchAppDoWriButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixOpVOpres == VecOpVOpres::SUCCESS) opNSuccess++;
			else if (req->dpchret->ixOpVOpres == VecOpVOpres::FAILURE) opNFailure++;

			if ((opNSuccess + opNFailure) == opN) {
				clearOps();

				opN = 0;
				opNSuccess = 0;

				if (opNFailure > 0) {
					opNFailure = 0;
					changeStage(dbswznm, nextIxVSgeFailure);
				} else changeStage(dbswznm, nextIxVSgeSuccess);
			};
		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
		if ((req->sref == "mon") && (ixVSge == VecVSge::WRITE)) handleTimerWithSrefMonInSgeWrite(dbswznm);
	};
};

void DlgWznmMchWriniscr::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmMchWriniscr::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::WRI) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmMchWriniscr::handleDpchAppDoButDneClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngWznmConfirm(true, jref, "");
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgWznmMchWriniscr::handleDpchAppDoWriButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWriButRunClick --- BEGIN
	if (statshrwri.ButRunActive) {
		changeStage(dbswznm, VecVSge::WRITE, dpcheng);
	};
	// IP handleDpchAppDoWriButRunClick --- END
};

void DlgWznmMchWriniscr::handleDpchAppDoWriButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWriButStoClick --- INSERT
};

string DlgWznmMchWriniscr::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfolder + ".tgz"); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWznmMchWriniscr::handleTimerWithSrefMonInSgeWrite(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeWrite --- ILINE
};

void DlgWznmMchWriniscr::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::WRITE: leaveSgeWrite(dbswznm); break;
				case VecVSge::PACK: leaveSgePack(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::WRITE: _ixVSge = enterSgeWrite(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmMchWriniscr::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::WRITE) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::WRITE) retval = "writing initialization scripts (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::PACK) retval = "packing initialization scripts";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmMchWriniscr::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmMchWriniscr::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmMchWriniscr::enterSgeWrite(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::WRITE;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::IDLE;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeWrite --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	ubigint refWznmMMachine;
	vector<ubigint> hrefsMch;

	string sbeconfig;

	vector<string> keys;
	vector<string> vals;

	set<string> cftpls;
	ubigint refCftpl;

	time_t rawtime;
	time(&rawtime);

	string s;

	outfolder = Tmp::newfolder(xchg->tmppath);

	refWznmMMachine = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMCH, jref);
	dbswznm->tblwznmmmachine->loadHrefsup(refWznmMMachine, hrefsMch);

	Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "sbeconfig", sbeconfig);

	dbswznm->loadRefBySQL("SELECT refWznmMPerson FROM TblWznmMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref)), ref);
	keys.push_back("author"); vals.push_back(StubWznm::getStubPrsStd(dbswznm, ref));

	keys.push_back("created"); vals.push_back(StrMod::timetToString(rawtime));

	keys.push_back("mchsref"); vals.push_back(StubWznm::getStubMchSref(dbswznm, refWznmMMachine));

	// check for cross-compilation
	dbswznm->loadRefBySQL("SELECT cchRefWznmMMachine FROM TblWznmMMachine WHERE ref = " + to_string(refWznmMMachine), ref);

	if (ref == 0) {
		for (unsigned int i = 0; i < hrefsMch.size(); i++) {
			dbswznm->loadRefBySQL("SELECT cchRefWznmMMachine FROM TblWznmMMachine WHERE ref = " + to_string(hrefsMch[i]), ref);
			if (ref != 0) break;
		};
	};

	if (ref == 0) {
		keys.push_back("whizdevroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "whizdevroot", s); vals.push_back(s);
		keys.push_back("ncore"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "ncore", s); vals.push_back(s);
		keys.push_back("cchost"); vals.push_back("");
		keys.push_back("cchinherit"); vals.push_back("");
		keys.push_back("cchrel"); vals.push_back("");
		keys.push_back("inceq"); vals.push_back("");

	} else {
		// cross-compilation
		dbswznm->tblwznmmmachine->loadHrefsup(ref, refs);

		keys.push_back("whizdevroot"); Wznm::getMchpar(dbswznm, ref, refs, "whizdevroot", s); vals.push_back(s);
		keys.push_back("ncore"); Wznm::getMchpar(dbswznm, ref, refs, "ncore", s); vals.push_back(s);
		keys.push_back("cchost"); vals.push_back(" (" + StubWznm::getStubMchSref(dbswznm, ref) + " cross-compilation)");
		keys.push_back("cchinherit"); vals.push_back(" (inherited from cross-compile host)");
		keys.push_back("cchrel"); vals.push_back(" on the cross-compile host");
		keys.push_back("inceq"); vals.push_back("=");
	};

	keys.push_back("mar");
	keys.push_back("defmar");
	if (StrMod::srefInSrefs(sbeconfig, "mar")) {
		vals.push_back("1");
		vals.push_back("");
	} else {
		vals.push_back("0");
		vals.push_back("//");
	};

	keys.push_back("my");
	keys.push_back("defmy");
	if (StrMod::srefInSrefs(sbeconfig, "my")) {
		vals.push_back("1");
		vals.push_back("");
	} else {
		vals.push_back("0");
		vals.push_back("//");
	};

	keys.push_back("pg");
	keys.push_back("defpg");
	if (StrMod::srefInSrefs(sbeconfig, "pg")) {
		vals.push_back("1");
		vals.push_back("");
	} else {
		vals.push_back("0");
		vals.push_back("//");
	};

	keys.push_back("lite");
	keys.push_back("deflite");
	if (StrMod::srefInSrefs(sbeconfig, "lite")) {
		vals.push_back("1");
		vals.push_back("");
	} else {
		vals.push_back("0");
		vals.push_back("//");
	};

	keys.push_back("defdds"); if (StrMod::srefInSrefs(sbeconfig, "dds")) vals.push_back(""); else vals.push_back("//");
	keys.push_back("defua"); if (StrMod::srefInSrefs(sbeconfig, "ua")) vals.push_back(""); else vals.push_back("//");

	keys.push_back("buildroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "buildroot", s); vals.push_back(s);
	keys.push_back("libroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "libroot", s); vals.push_back(s);
	keys.push_back("whizroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "whizroot", s); vals.push_back(s);
	keys.push_back("whizsdkroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "whizsdkroot", s); vals.push_back(s);
	keys.push_back("sysroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "sysroot", s); vals.push_back(s);
	keys.push_back("tchroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "tchroot", s); vals.push_back(s);
	keys.push_back("fpgaroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "fpgaroot", s); vals.push_back(s);
	keys.push_back("javaroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "javaroot", s); vals.push_back(s);
	keys.push_back("mcuroot"); Wznm::getMchpar(dbswznm, refWznmMMachine, hrefsMch, "mcuroot", s); vals.push_back(s);
	keys.push_back("cpp"); Wznm::getMchmkf(dbswznm, refWznmMMachine, hrefsMch, "cpp", s); vals.push_back(s);
	keys.push_back("cppflags"); Wznm::getMchmkf(dbswznm, refWznmMMachine, hrefsMch, "cppflags", s); vals.push_back(s);
	keys.push_back("statlib"); Wznm::getMchmkf(dbswznm, refWznmMMachine, hrefsMch, "statlib", s); vals.push_back(s);
	keys.push_back("statlibflags"); Wznm::getMchmkf(dbswznm, refWznmMMachine, hrefsMch, "statlibflags", s); vals.push_back(s);
	keys.push_back("dynlib"); Wznm::getMchmkf(dbswznm, refWznmMMachine, hrefsMch, "dynlib", s); vals.push_back(s);
	keys.push_back("dynlibflags"); Wznm::getMchmkf(dbswznm, refWznmMMachine, hrefsMch, "dynlibflags", s); vals.push_back(s);
	keys.push_back("dynlibext"); Wznm::getMchmkf(dbswznm, refWznmMMachine, hrefsMch, "dynlibext", s); vals.push_back(s);

	s = ""; if (dbswznm->tblwznmmlibrary->loadRefBySrf("xml2", ref)) Wznm::getLibmkf(dbswznm, ref, refWznmMMachine, hrefsMch, "incpath", s); if (s == "") s = "."; keys.push_back("libxmlinc"); vals.push_back(s);
	s = ""; if (dbswznm->tblwznmmlibrary->loadRefBySrf("mariadbclient", ref)) Wznm::getLibmkf(dbswznm, ref, refWznmMMachine, hrefsMch, "incpath", s); if (s == "") s = "."; keys.push_back("libmariadbinc"); vals.push_back(s);
	s = ""; if (dbswznm->tblwznmmlibrary->loadRefBySrf("mysqlclient", ref)) Wznm::getLibmkf(dbswznm, ref, refWznmMMachine, hrefsMch, "incpath", s); if (s == "") s = "."; keys.push_back("libmysqlinc"); vals.push_back(s);
	s = ""; if (dbswznm->tblwznmmlibrary->loadRefBySrf("postgresql", ref)) Wznm::getLibmkf(dbswznm, ref, refWznmMMachine, hrefsMch, "incpath", s); if (s == "") s = "."; keys.push_back("libpqinc"); vals.push_back(s);
	s = ""; if (dbswznm->tblwznmmlibrary->loadRefBySrf("sqlite3", ref)) Wznm::getLibmkf(dbswznm, ref, refWznmMMachine, hrefsMch, "incpath", s); if (s == "") s = "."; keys.push_back("libsqliteinc"); vals.push_back(s);

	cftpls = {"config.h", "init.sh", "Makefile_dbecore", "Makefile_sbecore"};

	for (auto it = cftpls.begin(); it != cftpls.end(); it++)
		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = '" + (*it) + "'", refCftpl))
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCftpl, "", outfolder + "/" + (*it), keys, vals));
	// IP enterSgeWrite --- IEND

	submitInvs(dbswznm, VecVSge::DONE, retval);
	return retval;
};

void DlgWznmMchWriniscr::leaveSgeWrite(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeWrite --- INSERT
};

uint DlgWznmMchWriniscr::enterSgePack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	// .tgz result folder
	Wznm::tgz(xchg->tmppath + "/" + outfolder, xchg->tmppath + "/" + outfolder + ".tgz");

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWznmMchWriniscr::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmMchWriniscr::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmMchWriniscr::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
