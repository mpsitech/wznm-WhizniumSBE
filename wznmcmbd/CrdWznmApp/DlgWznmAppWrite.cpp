/**
	* \file DlgWznmAppWrite.cpp
	* job handler for job DlgWznmAppWrite (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmAppWrite.h"

#include "DlgWznmAppWrite_blks.cpp"
#include "DlgWznmAppWrite_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmAppWrite
 ******************************************************************************/

DlgWznmAppWrite::DlgWznmAppWrite(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMAPPWRITE, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::DET;

	// IP constructor.cust2 --- IBEGIN
	WznmMApp* app = NULL;

	// find target
	if (dbswznm->tblwznmmapp->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref), &app)) {
		ixApptarget = app->ixWznmVApptarget;

		APPSHORT = StrMod::uc(app->Short);
		Appshort = StrMod::cap(app->Short);
		appshort = StrMod::lc(app->Short);

		// find project short
		Prjshort = Wznm::getPrjshort(dbswznm, app->verRefWznmMVersion);

		PRJSHORT = StrMod::uc(Prjshort);
		prjshort = StrMod::lc(Prjshort);

		delete app;
	};

	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmAppWrite::~DlgWznmAppWrite() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void DlgWznmAppWrite::create(
			DbsWznm* dbswznm
		) {
	ubigint ref;

	WznmMApp* app = NULL;

	string author, created;

	vector<string> keys;
	vector<string> vals;

	set<string> cftpls;
	ubigint refCftpl;

	string s;
	size_t ptr, ptr2;

	dbswznm->tblwznmmapp->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref), &app);

	ipfolder = Tmp::newfolder(xchg->tmppath);
	outfolder = Tmp::newfolder(xchg->tmppath);

	// --- prepare standard key/value pairs

	// -- author
	dbswznm->loadRefBySQL("SELECT refWznmMPerson FROM TblWznmMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref)), ref);

	author = StubWznm::getStubPrsStd(dbswznm, ref);

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// --- all files
	addInv(new DpchInvWznmWrappDom(0, 0, app->ref, ipfolder));
	addInv(new DpchInvWznmWrappMain(0, 0, app->ref, ipfolder, contiacdet.ChkUsf));
	addInv(new DpchInvWznmWrappStdvec(0, 0, app->ref, ipfolder));

	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("APPSHORT"); vals.push_back(APPSHORT);
	keys.push_back("Appshort"); vals.push_back(Appshort);
	keys.push_back("appshort"); vals.push_back(appshort);

	if (ixApptarget == VecWznmVApptarget::COCOA_SWIFT) cftpls = {"AppXxxx.swift", "DOMXxxx.swift", "VecXxxxVEvent.swift", "VecXxxxVState.swift"};
	else if (ixApptarget == VecWznmVApptarget::DOTNET_CS) cftpls = {"AppXxxx.cs", "DOMXxxx.cs", "VecXxxxVEvent.cs", "VecXxxxVState.cs"};
	else if (ixApptarget == VecWznmVApptarget::JAVA) cftpls = {"AppXxxx.java", "DOMXxxx.java", "VecXxxxVEvent.java", "VecXxxxVState.java"};
	else if (ixApptarget == VecWznmVApptarget::POSIX_CPP) cftpls = {"AppXxxx.h", "AppXxxx.cpp", "VecXxxxVEvent.h", "VecXxxxVEvent.cpp", "VecXxxxVState.h", "VecXxxxVState.cpp"};

	for (auto it = cftpls.begin(); it != cftpls.end(); it++) {
		s = (*it);
		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = '" + s + "'", refCftpl)) {
			ptr = s.find("Xxxx");
			if (ptr != string::npos) s = s.replace(ptr, 4, Appshort);

			ptr = s.find('_');
			if (ptr != string::npos) {
				ptr2 = s.find('.', ptr);
				if (ptr2 != string::npos) s = s.replace(ptr, (ptr2-ptr), "");
			};

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCftpl, "", outfolder + "/" + s, keys, vals));
		};
	};

	delete app;
};
// IP cust --- IEND

DpchEngWznm* DlgWznmAppWrite::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continffia, &continflfi, &continfwrc, &feedFDse, &feedFSge, &statshr, &statshrcuc, &statshrfia, &statshrlfi, &statshrwrc, items);
	};

	return dpcheng;
};

void DlgWznmAppWrite::refreshDet(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIacDet oldContiacdet(contiacdet);

	// IP refreshDet --- BEGIN
	// contiacdet

	// IP refreshDet --- END
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
};

void DlgWznmAppWrite::refreshCuc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrCuc oldStatshrcuc(statshrcuc);

	// IP refreshCuc --- BEGIN
	// statshrcuc
	statshrcuc.UldActive = evalCucUldActive(dbswznm);

	// IP refreshCuc --- END
	if (statshrcuc.diff(&oldStatshrcuc).size() != 0) insert(moditems, DpchEngData::STATSHRCUC);
};

void DlgWznmAppWrite::refreshWrc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrWrc oldStatshrwrc(statshrwrc);
	ContInfWrc oldContinfwrc(continfwrc);

	// IP refreshWrc --- RBEGIN
	// continfwrc
	continfwrc.TxtPrg = getSquawk(dbswznm);

	// statshrwrc
	statshrwrc.ButRunActive = evalWrcButRunActive(dbswznm);
	statshrwrc.ButStoActive = evalWrcButStoActive(dbswznm);

	// IP refreshWrc --- REND
	if (statshrwrc.diff(&oldStatshrwrc).size() != 0) insert(moditems, DpchEngData::STATSHRWRC);
	if (continfwrc.diff(&oldContinfwrc).size() != 0) insert(moditems, DpchEngData::CONTINFWRC);
};

void DlgWznmAppWrite::refreshLfi(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);
	ContInfLfi oldContinflfi(continflfi);

	// IP refreshLfi --- RBEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswznm);

	// continflfi
	continflfi.Dld = "log.txt";

	// IP refreshLfi --- REND
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
};

void DlgWznmAppWrite::refreshFia(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfFia oldContinffia(continffia);
	StatShrFia oldStatshrfia(statshrfia);

	// IP refreshFia --- RBEGIN

	string Appshort;

	dbswznm->loadStringBySQL("SELECT Short FROM TblWznmMApp WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref)), Appshort);

	// continffia
	continffia.Dld = StrMod::lc(Appshort) + ".tgz";

	// statshrfia
	statshrfia.DldActive = evalFiaDldActive(dbswznm);

	// IP refreshFia --- REND
	if (continffia.diff(&oldContinffia).size() != 0) insert(moditems, DpchEngData::CONTINFFIA);
	if (statshrfia.diff(&oldStatshrfia).size() != 0) insert(moditems, DpchEngData::STATSHRFIA);
};

void DlgWznmAppWrite::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButDneActive = evalButDneActive(dbswznm);

	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshDet(dbswznm, moditems);
	refreshCuc(dbswznm, moditems);
	refreshWrc(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);
	refreshFia(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmAppWrite::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPWRITEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbswznm, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPWRITEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoWrc != 0) {
				if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTRUNCLICK) {
					handleDpchAppDoWrcButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTSTOCLICK) {
					handleDpchAppDoWrcButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswznm, req->filename);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswznm);
		else if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNMPRCTREEMERGE) {
				handleDpchRetWznmPrctreeMerge(dbswznm, (DpchRetWznmPrctreeMerge*) (req->dpchret));
			};

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
		if (ixVSge == VecVSge::UPKIDLE) handleTimerInSgeUpkidle(dbswznm, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::WRITE)) handleTimerWithSrefMonInSgeWrite(dbswznm);
	};
};

void DlgWznmAppWrite::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmAppWrite::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmAppWrite::handleDpchAppDataContiacdet(
			DbsWznm* dbswznm
			, ContIacDet* _contiacdet
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	contiacdet.ChkUsf = _contiacdet->ChkUsf;

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmAppWrite::handleDpchAppDoButDneClick(
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

void DlgWznmAppWrite::handleDpchAppDoWrcButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWrcButRunClick --- BEGIN
	if (statshrwrc.ButRunActive) {
		changeStage(dbswznm, VecVSge::WRITE, dpcheng);
	};
	// IP handleDpchAppDoWrcButRunClick --- END
};

void DlgWznmAppWrite::handleDpchAppDoWrcButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWrcButStoClick --- INSERT
};

void DlgWznmAppWrite::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRMER) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWznmAlert --- IEND
};

void DlgWznmAppWrite::handleDpchRetWznmPrctreeMerge(
			DbsWznm* dbswznm
			, DpchRetWznmPrctreeMerge* dpchret
		) {
	// IP handleDpchRetWznmPrctreeMerge --- IBEGIN
	logaspect = VecVSge::getSref(ixVSge);
	logfile = dpchret->logfile;
	// IP handleDpchRetWznmPrctreeMerge --- IEND
};

void DlgWznmAppWrite::handleUploadInSgeIdle(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswznm, VecVSge::UPKIDLE);
};

string DlgWznmAppWrite::handleDownloadInSgeFail(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

string DlgWznmAppWrite::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfolder + ".tgz"); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWznmAppWrite::handleTimerInSgeUpkidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmAppWrite::handleTimerWithSrefMonInSgeWrite(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeWrite --- ILINE
};

void DlgWznmAppWrite::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRMER: leaveSgeAlrmer(dbswznm); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswznm); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswznm); break;
				case VecVSge::UPKDONE: leaveSgeUpkdone(dbswznm); break;
				case VecVSge::WRITE: leaveSgeWrite(dbswznm); break;
				case VecVSge::MRGGNR: leaveSgeMrggnr(dbswznm); break;
				case VecVSge::MRGCUST: leaveSgeMrgcust(dbswznm); break;
				case VecVSge::PACK: leaveSgePack(dbswznm); break;
				case VecVSge::FAIL: leaveSgeFail(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRMER: _ixVSge = enterSgeAlrmer(dbswznm, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswznm, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswznm, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswznm, reenter); break;
			case VecVSge::WRITE: _ixVSge = enterSgeWrite(dbswznm, reenter); break;
			case VecVSge::MRGGNR: _ixVSge = enterSgeMrggnr(dbswznm, reenter); break;
			case VecVSge::MRGCUST: _ixVSge = enterSgeMrgcust(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmAppWrite::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::WRITE) || (ixVSge == VecVSge::MRGGNR) || (ixVSge == VecVSge::MRGCUST) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::UNPACK) retval = "unpacking custom code fragments";
			else if (ixVSge == VecVSge::UPKDONE) retval = "custom code fragments unpacked";
			else if (ixVSge == VecVSge::WRITE) retval = "writing code (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::MRGGNR) retval = "merging generated code fragments";
			else if (ixVSge == VecVSge::MRGCUST) retval = "merging custom code fragments";
			else if (ixVSge == VecVSge::PACK) retval = "packing code tree";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmAppWrite::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmAppWrite::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmAppWrite::enterSgeAlrmer(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrmer --- RBEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Merge error (" + logaspect + "). View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrmer --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmAppWrite::leaveSgeAlrmer(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrmer --- INSERT
};

uint DlgWznmAppWrite::enterSgeUpkidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWznmAppWrite::leaveSgeUpkidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWznmAppWrite::enterSgeUnpack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN

	// unpack archive
	Wznm::run("mv " + infilename + " " + infilename + ".tgz");
	Wznm::untgz(infilename + ".tgz", infilename);

	if (infilename.rfind("/") == string::npos) custfolder = infilename;
	else custfolder = infilename.substr(infilename.rfind("/")+1);

	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWznmAppWrite::leaveSgeUnpack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWznmAppWrite::enterSgeUpkdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWznmAppWrite::leaveSgeUpkdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWznmAppWrite::enterSgeWrite(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::WRITE;
	nextIxVSgeSuccess = VecVSge::MRGGNR;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeWrite --- IBEGIN

	// create -> outfolder
	// IP's -> ipfolder -> outfolder
	// (optional) custom IP's -> custfolder -> outfolder
	create(dbswznm);

	// IP enterSgeWrite --- IEND

	submitInvs(dbswznm, VecVSge::IDLE, retval);
	return retval;
};

void DlgWznmAppWrite::leaveSgeWrite(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeWrite --- INSERT
};

uint DlgWznmAppWrite::enterSgeMrggnr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::MRGGNR;
	nextIxVSgeSuccess = VecVSge::MRGCUST;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrggnr --- IBEGIN

	if ((ixApptarget == VecWznmVApptarget::COCOA_SWIFT) || (ixApptarget == VecWznmVApptarget::DOTNET_CS) || (ixApptarget == VecWznmVApptarget::POSIX_CPP)) {
		// IP's -> ipfolder -> outfolder
		addInv(new DpchInvWznmPrctreeMerge(0, 0, "", ipfolder, "", outfolder, true, true));

	} else if (ixApptarget == VecWznmVApptarget::JAVA) {
		// IP's -> ipfolder -> outfolder
		addInv(new DpchInvWznmPrctreeMerge(0, 0, "", ipfolder, "", outfolder, true, true));
	};

	// IP enterSgeMrggnr --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmAppWrite::leaveSgeMrggnr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeMrggnr --- INSERT
};

uint DlgWznmAppWrite::enterSgeMrgcust(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::MRGCUST;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrgcust --- IBEGIN

	if ((ixApptarget == VecWznmVApptarget::COCOA_SWIFT) || (ixApptarget == VecWznmVApptarget::DOTNET_CS) || (ixApptarget == VecWznmVApptarget::POSIX_CPP)) {
		// (optional) custom IP's -> custfolder -> outfolder
		if (custfolder != "") addInv(new DpchInvWznmPrctreeMerge(0, 0, "", custfolder, "", outfolder, false, false));

	} else if (ixApptarget == VecWznmVApptarget::JAVA) {
		// (optional) custom IP's -> custfolder -> outfolder
		if (custfolder != "") addInv(new DpchInvWznmPrctreeMerge(0, 0, "", custfolder, "", outfolder, false, false));
	};

	// IP enterSgeMrgcust --- IEND

	submitInvs(dbswznm, VecVSge::PACK, retval);
	return retval;
};

void DlgWznmAppWrite::leaveSgeMrgcust(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeMrgcust --- INSERT
};

uint DlgWznmAppWrite::enterSgePack(
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

void DlgWznmAppWrite::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmAppWrite::enterSgeFail(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWznmAppWrite::leaveSgeFail(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWznmAppWrite::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmAppWrite::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
