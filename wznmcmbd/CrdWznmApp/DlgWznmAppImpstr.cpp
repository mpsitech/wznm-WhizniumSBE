/**
	* \file DlgWznmAppImpstr.cpp
	* job handler for job DlgWznmAppImpstr (implementation)
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

#include "DlgWznmAppImpstr.h"

#include "DlgWznmAppImpstr_blks.cpp"
#include "DlgWznmAppImpstr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmAppImpstr
 ******************************************************************************/

DlgWznmAppImpstr::DlgWznmAppImpstr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMAPPIMPSTR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	iex = new JobWznmIexApp(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmAppImpstr::~DlgWznmAppImpstr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmAppImpstr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continflfi, &feedFDse, &feedFSge, &statshr, &statshrifi, &statshrimp, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWznmAppImpstr::refreshIfi(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrIfi oldStatshrifi(statshrifi);

	// IP refreshIfi --- BEGIN
	// statshrifi
	statshrifi.UldActive = evalIfiUldActive(dbswznm);

	// IP refreshIfi --- END
	if (statshrifi.diff(&oldStatshrifi).size() != 0) insert(moditems, DpchEngData::STATSHRIFI);
};

void DlgWznmAppImpstr::refreshImp(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrImp oldStatshrimp(statshrimp);
	ContInfImp oldContinfimp(continfimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbswznm);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbswznm);
	statshrimp.ButStoActive = evalImpButStoActive(dbswznm);

	// IP refreshImp --- REND
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
};

void DlgWznmAppImpstr::refreshLfi(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfLfi oldContinflfi(continflfi);
	StatShrLfi oldStatshrlfi(statshrlfi);

	// IP refreshLfi --- RBEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswznm);

	// continflfi
	continflfi.Dld = "log.txt";

	// IP refreshLfi --- REND
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgWznmAppImpstr::refresh(
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

	refreshIfi(dbswznm, moditems);
	refreshImp(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmAppImpstr::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPIMPSTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPIMPSTRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswznm, req->filename);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
		if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswznm);
		else if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswznm, req->sref);
		else if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswznm, req->sref);
	};
};

void DlgWznmAppImpstr::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmAppImpstr::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::IFI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmAppImpstr::handleDpchAppDoButDneClick(
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

void DlgWznmAppImpstr::handleDpchAppDoImpButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswznm, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWznmAppImpstr::handleDpchAppDoImpButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWznmAppImpstr::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRWZNMPER) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	} else if (ixVSge == VecVSge::ALRWZNMIER) {
		if (dpchappwznmalert->numFMcb == 2) iex->reverse(dbswznm);
		changeStage(dbswznm, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWznmAlert --- IEND
};

void DlgWznmAppImpstr::handleUploadInSgeIdle(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswznm, VecVSge::PRSIDLE);
};

string DlgWznmAppImpstr::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWznmAppImpstr::handleTimerWithSrefMonInSgeImport(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWznmAppImpstr::handleTimerInSgeImpidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmAppImpstr::handleTimerInSgePrsidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmAppImpstr::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::PRSIDLE: leaveSgePrsidle(dbswznm); break;
				case VecVSge::PARSE: leaveSgeParse(dbswznm); break;
				case VecVSge::ALRWZNMPER: leaveSgeAlrwznmper(dbswznm); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswznm); break;
				case VecVSge::IMPIDLE: leaveSgeImpidle(dbswznm); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswznm); break;
				case VecVSge::ALRWZNMIER: leaveSgeAlrwznmier(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbswznm, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswznm, reenter); break;
			case VecVSge::ALRWZNMPER: _ixVSge = enterSgeAlrwznmper(dbswznm, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswznm, reenter); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbswznm, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswznm, reenter); break;
			case VecVSge::ALRWZNMIER: _ixVSge = enterSgeAlrwznmier(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmAppImpstr::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWZNMPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWZNMIER) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing structure";
			else if (ixVSge == VecVSge::ALRWZNMPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing structure (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWZNMIER) retval = "import error";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWznmAppImpstr::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmAppImpstr::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmAppImpstr::enterSgePrsidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWznmAppImpstr::leaveSgePrsidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWznmAppImpstr::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWZNMPER;

	// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	string rectfile;

	char* buf;
	string s;

	iex->reset(dbswznm);

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("IexWznmApp") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) {
		rectfile = Tmp::newfile(xchg->tmppath, "txt");
		iex->parseFromFile(dbswznm, infilename, false, xchg->tmppath + "/" + rectfile);
		infilename = xchg->tmppath + "/" + rectfile;

	} else if (ifixml) iex->parseFromFile(dbswznm, infilename, true, "");

	if (iex->ixVSge != JobWznmIexApp::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWznmIexApp::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswznm) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWznmAppImpstr::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWznmAppImpstr::enterSgeAlrwznmper(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwznmper --- RBEGIN
	ContInfWznmAlert continf;

	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWznmIexApp::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswznm);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));
	// IP enterSgeAlrwznmper --- REND

	return retval;
};

void DlgWznmAppImpstr::leaveSgeAlrwznmper(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmper --- INSERT
};

uint DlgWznmAppImpstr::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWznmAppImpstr::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWznmAppImpstr::enterSgeImpidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWznmAppImpstr::leaveSgeImpidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWznmAppImpstr::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWZNMIER;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeImport --- IBEGIN

	iex->import(dbswznm);

	if (iex->ixVSge == JobWznmIexApp::VecVSge::IMPERR) retval = nextIxVSgeFailure;

	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWznmAppImpstr::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWznmAppImpstr::enterSgeAlrwznmier(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMIER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwznmier --- RBEGIN

	if (reqCmd) {
		cout << "\t" << iex->getSquawk(dbswznm) << endl;
		retval = nextIxVSgeSuccess;
	} else {
		xchg->submitDpch(AlrWznm::prepareAlrIer(jref, ixWznmVLocale, iex->getSquawk(dbswznm), feedFMcbAlert));
	};

	// IP enterSgeAlrwznmier --- REND

	return retval;
};

void DlgWznmAppImpstr::leaveSgeAlrwznmier(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmier --- INSERT
};

uint DlgWznmAppImpstr::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN

	ubigint refWznmMApp;
	string Appshort, Filename, srefKMimetype;

	refWznmMApp = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref);
	dbswznm->loadStringBySQL("SELECT TblWznmMApp.Short FROM TblWznmMApp WHERE ref = " + to_string(refWznmMApp), Appshort);

	if (ifitxt) {
		Filename = "IexWznmApp_" + StrMod::lc(Appshort) + ".txt";
		srefKMimetype = "txt";
	} else if (ifixml) {
		Filename = "IexWznmApp_" + StrMod::lc(Appshort) + ".xml";
		srefKMimetype = "xml";
	};

	Acv::addfile(dbswznm, xchg->acvpath, infilename, xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref), xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVMFileRefTbl::APP, refWznmMApp, "appstr", Filename, srefKMimetype, "");

	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWznmAppImpstr::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
