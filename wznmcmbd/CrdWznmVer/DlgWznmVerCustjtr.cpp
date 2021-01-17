/**
	* \file DlgWznmVerCustjtr.cpp
	* job handler for job DlgWznmVerCustjtr (implementation)
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

#include "DlgWznmVerCustjtr.h"

#include "DlgWznmVerCustjtr_blks.cpp"
#include "DlgWznmVerCustjtr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVerCustjtr
 ******************************************************************************/

DlgWznmVerCustjtr::DlgWznmVerCustjtr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVERCUSTJTR, jrefSup, ixWznmVLocale)
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

	iex = new JobWznmIexJtr(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmVerCustjtr::~DlgWznmVerCustjtr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmVerCustjtr::getNewDpchEng(
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

void DlgWznmVerCustjtr::refreshIfi(
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

void DlgWznmVerCustjtr::refreshImp(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfImp oldContinfimp(continfimp);
	StatShrImp oldStatshrimp(statshrimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbswznm);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbswznm);
	statshrimp.ButStoActive = evalImpButStoActive(dbswznm);

	// IP refreshImp --- REND
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
};

void DlgWznmVerCustjtr::refreshLfi(
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

void DlgWznmVerCustjtr::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshIfi(dbswznm, moditems);
	refreshImp(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmVerCustjtr::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTJTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTJTRDO) {
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
		if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswznm, req->sref);
		else if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswznm, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswznm);
	};
};

void DlgWznmVerCustjtr::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVerCustjtr::handleDpchAppDataContiac(
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

void DlgWznmVerCustjtr::handleDpchAppDoButDneClick(
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

void DlgWznmVerCustjtr::handleDpchAppDoImpButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswznm, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWznmVerCustjtr::handleDpchAppDoImpButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWznmVerCustjtr::handleDpchAppWznmAlert(
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

void DlgWznmVerCustjtr::handleUploadInSgeIdle(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswznm, VecVSge::PRSIDLE);
};

string DlgWznmVerCustjtr::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWznmVerCustjtr::handleTimerInSgePrsidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmVerCustjtr::handleTimerInSgeImpidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmVerCustjtr::handleTimerWithSrefMonInSgeImport(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWznmVerCustjtr::changeStage(
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

string DlgWznmVerCustjtr::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWZNMPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWZNMIER) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing custom job tree features";
			else if (ixVSge == VecVSge::ALRWZNMPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "custom job tree features parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "applying custom job tree features (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWZNMIER) retval = "import error";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWznmVerCustjtr::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVerCustjtr::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVerCustjtr::enterSgePrsidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWznmVerCustjtr::leaveSgePrsidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWznmVerCustjtr::enterSgeParse(
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

	ifitxt = (s.find("IexWznmJtr") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) {
		rectfile = Tmp::newfile(xchg->tmppath, "txt");
		iex->parseFromFile(dbswznm, infilename, false, xchg->tmppath + "/" + rectfile);
		infilename = xchg->tmppath + "/" + rectfile;

	} else if (ifixml) iex->parseFromFile(dbswznm, infilename, true);

	if (iex->ixVSge != JobWznmIexJtr::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWznmIexJtr::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswznm) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWznmVerCustjtr::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWznmVerCustjtr::enterSgeAlrwznmper(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwznmper --- RBEGIN
	ContInfWznmAlert continf;

	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWznmIexJtr::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswznm);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));
	// IP enterSgeAlrwznmper --- REND

	return retval;
};

void DlgWznmVerCustjtr::leaveSgeAlrwznmper(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmper --- INSERT
};

uint DlgWznmVerCustjtr::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWznmVerCustjtr::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWznmVerCustjtr::enterSgeImpidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWznmVerCustjtr::leaveSgeImpidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWznmVerCustjtr::enterSgeImport(
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

	if (iex->ixVSge == JobWznmIexJtr::VecVSge::IMPERR) retval = nextIxVSgeFailure;

	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWznmVerCustjtr::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- IBEGIN
	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	Wznm::updateVerste(dbswznm, refWznmMVersion, VecWznmVMVersionState::DSNCUSTJTR);
	// IP leaveSgeImport --- IEND
};

uint DlgWznmVerCustjtr::enterSgeAlrwznmier(
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

void DlgWznmVerCustjtr::leaveSgeAlrwznmier(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmier --- INSERT
};

uint DlgWznmVerCustjtr::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN

	ubigint refWznmMVersion;
	string Prjshort, Filename, srefKMimetype;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	Prjshort = Wznm::getPrjshort(dbswznm, refWznmMVersion);

	if (ifitxt) {
		Filename = "IexWznmJtr_" + StrMod::lc(Prjshort) + ".txt";
		srefKMimetype = "txt";
	} else if (ifixml) {
		Filename = "IexWznmJtr_" + StrMod::lc(Prjshort) + ".xml";
		srefKMimetype = "xml";
	};

	Acv::addfile(dbswznm, xchg->acvpath, infilename, xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref), xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVMFileRefTbl::VER, refWznmMVersion, "mod", Filename, srefKMimetype, "");

	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWznmVerCustjtr::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
