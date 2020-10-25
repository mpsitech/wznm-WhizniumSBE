/**
	* \file DlgWznmNavLoaini.cpp
	* job handler for job DlgWznmNavLoaini (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmNavLoaini.h"

#include "DlgWznmNavLoaini_blks.cpp"
#include "DlgWznmNavLoaini_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmNavLoaini
 ******************************************************************************/

DlgWznmNavLoaini::DlgWznmNavLoaini(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMNAVLOAINI, jrefSup, ixWznmVLocale)
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

	iex = new JobWznmIexIni(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmNavLoaini::~DlgWznmNavLoaini() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmNavLoaini::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continflfi, &feedFDse, &feedFSge, &statshr, &statshracv, &statshrifi, &statshrimp, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWznmNavLoaini::refreshIfi(
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

void DlgWznmNavLoaini::refreshImp(
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

void DlgWznmNavLoaini::refreshAcv(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrAcv oldStatshracv(statshracv);

	// IP refreshAcv --- BEGIN
	// statshracv
	statshracv.UldActive = evalAcvUldActive(dbswznm);

	// IP refreshAcv --- END
	if (statshracv.diff(&oldStatshracv).size() != 0) insert(moditems, DpchEngData::STATSHRACV);
};

void DlgWznmNavLoaini::refreshLfi(
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

void DlgWznmNavLoaini::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
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
	refreshAcv(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);
};

void DlgWznmNavLoaini::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMNAVLOAINIDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMNAVLOAINIDO) {
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
		else if (ixVSge == VecVSge::IMPDONE) handleUploadInSgeImpdone(dbswznm, req->filename);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswznm, req->sref);
		else if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswznm, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswznm);
		else if (ixVSge == VecVSge::UPKIDLE) handleTimerInSgeUpkidle(dbswznm, req->sref);
	};
};

void DlgWznmNavLoaini::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmNavLoaini::handleDpchAppDataContiac(
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

void DlgWznmNavLoaini::handleDpchAppDoButDneClick(
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

void DlgWznmNavLoaini::handleDpchAppDoImpButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswznm, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWznmNavLoaini::handleDpchAppDoImpButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWznmNavLoaini::handleDpchAppWznmAlert(
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

void DlgWznmNavLoaini::handleUploadInSgeIdle(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswznm, VecVSge::PRSIDLE);
};

void DlgWznmNavLoaini::handleUploadInSgeImpdone(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeImpdone --- ILINE
	changeStage(dbswznm, VecVSge::UPKIDLE);
};

string DlgWznmNavLoaini::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWznmNavLoaini::handleTimerInSgePrsidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmNavLoaini::handleTimerInSgeImpidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmNavLoaini::handleTimerWithSrefMonInSgeImport(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWznmNavLoaini::handleTimerInSgeUpkidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmNavLoaini::changeStage(
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
				case VecVSge::IMPDONE: leaveSgeImpdone(dbswznm); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswznm); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
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
			case VecVSge::IMPDONE: _ixVSge = enterSgeImpdone(dbswznm, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswznm, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmNavLoaini::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWZNMPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWZNMIER) || (ixVSge == VecVSge::IMPDONE) || (ixVSge == VecVSge::UNPACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::ALRWZNMPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWZNMIER) retval = "import error";
			else if (ixVSge == VecVSge::IMPDONE) retval = "import done";
			else if (ixVSge == VecVSge::UNPACK) retval = "unpacking inizialization files";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWznmNavLoaini::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmNavLoaini::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmNavLoaini::enterSgePrsidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWznmNavLoaini::leaveSgePrsidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWznmNavLoaini::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWZNMPER;

	// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	char* buf;
	string s;

	bool ifitxt;
	bool ifixml;

	iex->reset(dbswznm);

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("- ") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) iex->parseFromFile(dbswznm, infilename, false);
	else if (ifixml) iex->parseFromFile(dbswznm, infilename, true);

	if (iex->ixVSge != JobWznmIexIni::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWznmIexIni::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswznm) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWznmNavLoaini::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWznmNavLoaini::enterSgeAlrwznmper(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwznmper --- RBEGIN
	ContInfWznmAlert continf;

	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWznmIexIni::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswznm);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));
	// IP enterSgeAlrwznmper --- REND

	return retval;
};

void DlgWznmNavLoaini::leaveSgeAlrwznmper(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmper --- INSERT
};

uint DlgWznmNavLoaini::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWznmNavLoaini::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWznmNavLoaini::enterSgeImpidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWznmNavLoaini::leaveSgeImpidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWznmNavLoaini::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IMPDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWZNMIER;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeImport --- IBEGIN

	iex->import(dbswznm);

	if (iex->ixVSge == JobWznmIexIni::VecVSge::IMPERR) retval = nextIxVSgeFailure;

	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWznmNavLoaini::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWznmNavLoaini::enterSgeAlrwznmier(
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

void DlgWznmNavLoaini::leaveSgeAlrwznmier(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmier --- INSERT
};

uint DlgWznmNavLoaini::enterSgeImpdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPDONE;

	// IP enterSgeImpdone --- INSERT

	return retval;
};

void DlgWznmNavLoaini::leaveSgeImpdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImpdone --- INSERT
};

uint DlgWznmNavLoaini::enterSgeUpkidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWznmNavLoaini::leaveSgeUpkidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWznmNavLoaini::enterSgeUnpack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN
	ubigint ref;

	DIR* dir = NULL;
	dirent* diritem = NULL;

	// collect refs of newly imported files
	dbswznm->tblwznmqselect->removeRstByJref(jref);
	for (unsigned int ix0=0;ix0<iex->imeimfile.nodes.size();ix0++) dbswznm->tblwznmqselect->insertNewRec(NULL, jref, 0, 0, iex->imeimfile.nodes[ix0]->ref);

	// handle archive file containing many (or all) files
	Wznm::run("mv " + infilename + " " + infilename + ".tgz");

	// unpack
	Wznm::untgz(infilename + ".tgz", infilename);

	// traverse directory and match each single file to import
	dir = opendir(infilename.c_str());

	if (dir) {
		// traverse directory
		diritem = readdir(dir);
		while (diritem) {

			if (diritem->d_type == DT_REG) {
				// file: try to match
				ref = 0;

				dbswznm->loadRefBySQL("SELECT TblWznmMFile.ref FROM TblWznmQSelect, TblWznmMFile WHERE TblWznmQSelect.jref = " + to_string(jref)
							+ " AND TblWznmMFile.ref = TblWznmQSelect.ref AND TblWznmMFile.Filename = '" + diritem->d_name + "'", ref);

				if (ref != 0) {
					Acv::alterfile(dbswznm, xchg->acvpath, infilename + "/" + diritem->d_name, ref);
					if (reqCmd) cout << "updated file '" << diritem->d_name << "'" << endl;
				};

			} else {
				// something else: do nothing
			};

			diritem = readdir(dir);
		};

		closedir(dir);
	};
	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWznmNavLoaini::leaveSgeUnpack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWznmNavLoaini::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmNavLoaini::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


