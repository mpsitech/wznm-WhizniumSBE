/**
	* \file DlgWznmUtlMrgip.cpp
	* job handler for job DlgWznmUtlMrgip (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmUtlMrgip.h"

#include "DlgWznmUtlMrgip_blks.cpp"
#include "DlgWznmUtlMrgip_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmUtlMrgip
 ******************************************************************************/

DlgWznmUtlMrgip::DlgWznmUtlMrgip(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMUTLMRGIP, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::SRC;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmUtlMrgip::~DlgWznmUtlMrgip() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmUtlMrgip::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continflfi, &continfmrg, &continfres, &feedFDse, &feedFSge, &statshr, &statshrlfi, &statshrmrg, &statshrres, &statshrsrc, &statshrtrg, items);
	};

	return dpcheng;
};

void DlgWznmUtlMrgip::refreshSrc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrSrc oldStatshrsrc(statshrsrc);

	// IP refreshSrc --- BEGIN
	// statshrsrc
	statshrsrc.UldActive = evalSrcUldActive(dbswznm);

	// IP refreshSrc --- END
	if (statshrsrc.diff(&oldStatshrsrc).size() != 0) insert(moditems, DpchEngData::STATSHRSRC);
};

void DlgWznmUtlMrgip::refreshTrg(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrTrg oldStatshrtrg(statshrtrg);

	// IP refreshTrg --- BEGIN
	// statshrtrg
	statshrtrg.UldActive = evalTrgUldActive(dbswznm);

	// IP refreshTrg --- END
	if (statshrtrg.diff(&oldStatshrtrg).size() != 0) insert(moditems, DpchEngData::STATSHRTRG);
};

void DlgWznmUtlMrgip::refreshMrg(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrMrg oldStatshrmrg(statshrmrg);
	ContInfMrg oldContinfmrg(continfmrg);

	// IP refreshMrg --- RBEGIN
	// continfmrg
	continfmrg.TxtPrg = getSquawk(dbswznm);

	// statshrmrg
	statshrmrg.ButRunActive = evalMrgButRunActive(dbswznm);
	statshrmrg.ButStoActive = evalMrgButStoActive(dbswznm);

	// IP refreshMrg --- REND
	if (statshrmrg.diff(&oldStatshrmrg).size() != 0) insert(moditems, DpchEngData::STATSHRMRG);
	if (continfmrg.diff(&oldContinfmrg).size() != 0) insert(moditems, DpchEngData::CONTINFMRG);
};

void DlgWznmUtlMrgip::refreshLfi(
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

void DlgWznmUtlMrgip::refreshRes(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfRes oldContinfres(continfres);
	StatShrRes oldStatshrres(statshrres);

	// IP refreshRes --- RBEGIN
	// statshrres
	statshrres.DldActive = evalResDldActive(dbswznm);

	// continfres
	if (outfolder == "") continfres.Dld = "merged";
	else continfres.Dld = "merged.tgz";

	// IP refreshRes --- REND
	if (continfres.diff(&oldContinfres).size() != 0) insert(moditems, DpchEngData::CONTINFRES);
	if (statshrres.diff(&oldStatshrres).size() != 0) insert(moditems, DpchEngData::STATSHRRES);
};

void DlgWznmUtlMrgip::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
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

	refreshSrc(dbswznm, moditems);
	refreshTrg(dbswznm, moditems);
	refreshMrg(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);
	refreshRes(dbswznm, moditems);
};

void DlgWznmUtlMrgip::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLMRGIPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLMRGIPDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoMrg != 0) {
				if (dpchappdo->ixVDoMrg == VecVDoMrg::BUTRUNCLICK) {
					handleDpchAppDoMrgButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoMrg == VecVDoMrg::BUTSTOCLICK) {
					handleDpchAppDoMrgButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswznm, req->filename);
		else if (ixVSge == VecVSge::SUPDONE) handleUploadInSgeSupdone(dbswznm, req->filename);
		else if (ixVSge == VecVSge::SULDONE) handleUploadInSgeSuldone(dbswznm, req->filename);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswznm);
		else if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNM) {
				handleDpchRetWznm(dbswznm, (DpchRetWznm*) (req->dpchret));
			} else if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNMPRCTREEMERGE) {
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
		if (ixVSge == VecVSge::SUPIDLE) handleTimerInSgeSupidle(dbswznm, req->sref);
		else if (ixVSge == VecVSge::TUPIDLE) handleTimerInSgeTupidle(dbswznm, req->sref);
	};
};

void DlgWznmUtlMrgip::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmUtlMrgip::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::SRC) && (_contiac->numFDse <= VecVDit::RES)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmUtlMrgip::handleDpchAppDoButDneClick(
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

void DlgWznmUtlMrgip::handleDpchAppDoMrgButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMrgButRunClick --- BEGIN
	if (statshrmrg.ButRunActive) {
		changeStage(dbswznm, VecVSge::MERGE, dpcheng);
	};
	// IP handleDpchAppDoMrgButRunClick --- END
};

void DlgWznmUtlMrgip::handleDpchAppDoMrgButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMrgButStoClick --- INSERT
};

void DlgWznmUtlMrgip::handleDpchAppWznmAlert(
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

void DlgWznmUtlMrgip::handleDpchRetWznm(
			DbsWznm* dbswznm
			, DpchRetWznm* dpchret
		) {
	// IP handleDpchRetWznm --- INSERT
};

void DlgWznmUtlMrgip::handleDpchRetWznmPrctreeMerge(
			DbsWznm* dbswznm
			, DpchRetWznmPrctreeMerge* dpchret
		) {
	logfile = dpchret->logfile; // IP handleDpchRetWznmPrctreeMerge --- ILINE
};

void DlgWznmUtlMrgip::handleUploadInSgeIdle(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswznm, VecVSge::SUPIDLE);
};

void DlgWznmUtlMrgip::handleUploadInSgeSupdone(
			DbsWznm* dbswznm
			, const string& filename
		) {
	outfilename = filename; // IP handleUploadInSgeSupdone --- ILINE
	changeStage(dbswznm, VecVSge::TUPIDLE);
};

void DlgWznmUtlMrgip::handleUploadInSgeSuldone(
			DbsWznm* dbswznm
			, const string& filename
		) {
	outfilename = filename; // IP handleUploadInSgeSuldone --- ILINE
	changeStage(dbswznm, VecVSge::TUPIDLE);
};

string DlgWznmUtlMrgip::handleDownloadInSgeFail(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

string DlgWznmUtlMrgip::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfile); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWznmUtlMrgip::handleTimerInSgeSupidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmUtlMrgip::handleTimerInSgeTupidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmUtlMrgip::changeStage(
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
				case VecVSge::SUPIDLE: leaveSgeSupidle(dbswznm); break;
				case VecVSge::SRCUNPACK: leaveSgeSrcunpack(dbswznm); break;
				case VecVSge::SUPDONE: leaveSgeSupdone(dbswznm); break;
				case VecVSge::SULDONE: leaveSgeSuldone(dbswznm); break;
				case VecVSge::TUPIDLE: leaveSgeTupidle(dbswznm); break;
				case VecVSge::TRGUNPACK: leaveSgeTrgunpack(dbswznm); break;
				case VecVSge::TUPDONE: leaveSgeTupdone(dbswznm); break;
				case VecVSge::TULDONE: leaveSgeTuldone(dbswznm); break;
				case VecVSge::MERGE: leaveSgeMerge(dbswznm); break;
				case VecVSge::PACK: leaveSgePack(dbswznm); break;
				case VecVSge::FAIL: leaveSgeFail(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRMER: _ixVSge = enterSgeAlrmer(dbswznm, reenter); break;
			case VecVSge::SUPIDLE: _ixVSge = enterSgeSupidle(dbswznm, reenter); break;
			case VecVSge::SRCUNPACK: _ixVSge = enterSgeSrcunpack(dbswznm, reenter); break;
			case VecVSge::SUPDONE: _ixVSge = enterSgeSupdone(dbswznm, reenter); break;
			case VecVSge::SULDONE: _ixVSge = enterSgeSuldone(dbswznm, reenter); break;
			case VecVSge::TUPIDLE: _ixVSge = enterSgeTupidle(dbswznm, reenter); break;
			case VecVSge::TRGUNPACK: _ixVSge = enterSgeTrgunpack(dbswznm, reenter); break;
			case VecVSge::TUPDONE: _ixVSge = enterSgeTupdone(dbswznm, reenter); break;
			case VecVSge::TULDONE: _ixVSge = enterSgeTuldone(dbswznm, reenter); break;
			case VecVSge::MERGE: _ixVSge = enterSgeMerge(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmUtlMrgip::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::SRCUNPACK) || (ixVSge == VecVSge::SUPDONE) || (ixVSge == VecVSge::SULDONE) || (ixVSge == VecVSge::TRGUNPACK) || (ixVSge == VecVSge::TUPDONE) || (ixVSge == VecVSge::TULDONE) || (ixVSge == VecVSge::MERGE) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::SRCUNPACK) retval = "unpacking source";
			else if (ixVSge == VecVSge::SUPDONE) retval = "source unpacked";
			else if (ixVSge == VecVSge::SULDONE) retval = "source uploaded";
			else if (ixVSge == VecVSge::TRGUNPACK) retval = "unpacking target";
			else if (ixVSge == VecVSge::TUPDONE) retval = "target unpacked";
			else if (ixVSge == VecVSge::TULDONE) retval = "target uploaded";
			else if (ixVSge == VecVSge::MERGE) retval = "merging";
			else if (ixVSge == VecVSge::PACK) retval = "packing result";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmUtlMrgip::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeAlrmer(
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
		continf.TxtMsg1 = "Merge error. View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrmer --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeAlrmer(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrmer --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeSupidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::SUPIDLE;
	nextIxVSgeSuccess = VecVSge::SRCUNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeSupidle --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeSupidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSupidle --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeSrcunpack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::SUPDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSrcunpack --- IBEGIN

	// 1st try: assume .tgz input file archive
	infolder = infilename.substr(infilename.rfind("/")+1);
	infile = infolder + ".tgz";

	Wznm::run("mv " + infilename + " " + infilename + ".tgz");

	if (!Wznm::untgz(xchg->tmppath + "/" + infile, xchg->tmppath + "/" + infolder)) {
		// 2nd try: single input file
		infolder = "";
		
		Wznm::run("mv " + infilename + ".tgz " + infilename);
		infile = infilename.substr(infilename.rfind("/")+1);

		retval = VecVSge::SULDONE;
	};

	// IP enterSgeSrcunpack --- IEND

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeSrcunpack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSrcunpack --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeSupdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::SUPDONE;

	// IP enterSgeSupdone --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeSupdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSupdone --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeSuldone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::SULDONE;

	// IP enterSgeSuldone --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeSuldone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSuldone --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeTupidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::TUPIDLE;
	nextIxVSgeSuccess = VecVSge::TRGUNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeTupidle --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeTupidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeTupidle --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeTrgunpack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::TUPDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeTrgunpack --- IBEGIN

	// .tgz target file archive vs. single target file based on file uploaded previously
	if (infolder.length() > 0) {
		outfolder = outfilename.substr(outfilename.rfind("/")+1);
		outfile = outfolder + ".tgz";

		Wznm::run("mv " + outfilename + " " + outfilename + ".tgz");
		Wznm::untgz(xchg->tmppath + "/" + outfile, xchg->tmppath + "/" + outfolder);

	} else {
		outfolder = "";
		outfile = outfilename.substr(outfilename.rfind("/")+1);

		retval = VecVSge::TULDONE;
	};

	// IP enterSgeTrgunpack --- IEND

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeTrgunpack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeTrgunpack --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeTupdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::TUPDONE;

	// IP enterSgeTupdone --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeTupdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeTupdone --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeTuldone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::TULDONE;

	// IP enterSgeTuldone --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeTuldone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeTuldone --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeMerge(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::MERGE;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMerge --- IBEGIN

	// invoke WznmPrctreeMerge

	if (infolder == "") {
		// single file
		addInv(new DpchInvWznmPrctreeMerge(0, 0, infile, "", outfile, "", false, false));
	} else {
		// multiple files
		addInv(new DpchInvWznmPrctreeMerge(0, 0, "", infolder, "", outfolder, false, false));
	};

	// IP enterSgeMerge --- IEND

	submitInvs(dbswznm, VecVSge::IDLE, retval);
	return retval;
};

void DlgWznmUtlMrgip::leaveSgeMerge(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeMerge --- INSERT
};

uint DlgWznmUtlMrgip::enterSgePack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	// .tgz result folder
	if (outfolder != "") Wznm::tgz(xchg->tmppath + "/" + outfolder, xchg->tmppath + "/" + outfile);

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWznmUtlMrgip::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeFail(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeFail(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWznmUtlMrgip::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmUtlMrgip::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


