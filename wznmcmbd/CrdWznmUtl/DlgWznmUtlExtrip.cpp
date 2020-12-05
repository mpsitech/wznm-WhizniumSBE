/**
	* \file DlgWznmUtlExtrip.cpp
	* job handler for job DlgWznmUtlExtrip (implementation)
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

#include "DlgWznmUtlExtrip.h"

#include "DlgWznmUtlExtrip_blks.cpp"
#include "DlgWznmUtlExtrip_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmUtlExtrip
 ******************************************************************************/

DlgWznmUtlExtrip::DlgWznmUtlExtrip(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMUTLEXTRIP, jrefSup, ixWznmVLocale)
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

DlgWznmUtlExtrip::~DlgWznmUtlExtrip() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmUtlExtrip::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfext, &continflfi, &continfres, &feedFDse, &feedFSge, &statshr, &statshrext, &statshrlfi, &statshrres, &statshrsrc, items);
	};

	return dpcheng;
};

void DlgWznmUtlExtrip::refreshSrc(
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

void DlgWznmUtlExtrip::refreshExt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrExt oldStatshrext(statshrext);
	ContInfExt oldContinfext(continfext);

	// IP refreshExt --- RBEGIN
	// continfext
	continfext.TxtPrg = getSquawk(dbswznm);

	// statshrext
	statshrext.ButRunActive = evalExtButRunActive(dbswznm);
	statshrext.ButStoActive = evalExtButStoActive(dbswznm);

	// IP refreshExt --- REND
	if (statshrext.diff(&oldStatshrext).size() != 0) insert(moditems, DpchEngData::STATSHREXT);
	if (continfext.diff(&oldContinfext).size() != 0) insert(moditems, DpchEngData::CONTINFEXT);
};

void DlgWznmUtlExtrip::refreshLfi(
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

void DlgWznmUtlExtrip::refreshRes(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrRes oldStatshrres(statshrres);
	ContInfRes oldContinfres(continfres);

	// IP refreshRes --- RBEGIN
	// statshrres
	statshrres.DldActive = evalResDldActive(dbswznm);

	// continfres
	if (outfolder == "") continfres.Dld = "extracted";
	else continfres.Dld = "extracted.tgz";

	// IP refreshRes --- REND
	if (statshrres.diff(&oldStatshrres).size() != 0) insert(moditems, DpchEngData::STATSHRRES);
	if (continfres.diff(&oldContinfres).size() != 0) insert(moditems, DpchEngData::CONTINFRES);
};

void DlgWznmUtlExtrip::refresh(
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

	refreshSrc(dbswznm, moditems);
	refreshExt(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);
	refreshRes(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmUtlExtrip::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLEXTRIPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLEXTRIPDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoExt != 0) {
				if (dpchappdo->ixVDoExt == VecVDoExt::BUTRUNCLICK) {
					handleDpchAppDoExtButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoExt == VecVDoExt::BUTSTOCLICK) {
					handleDpchAppDoExtButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswznm, req->filename);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);
		else if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNM) {
				handleDpchRetWznm(dbswznm, (DpchRetWznm*) (req->dpchret));
			} else if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNMPRCTREEEXTRACT) {
				handleDpchRetWznmPrctreeExtract(dbswznm, (DpchRetWznmPrctreeExtract*) (req->dpchret));
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
	};
};

void DlgWznmUtlExtrip::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmUtlExtrip::handleDpchAppDataContiac(
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

void DlgWznmUtlExtrip::handleDpchAppDoButDneClick(
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

void DlgWznmUtlExtrip::handleDpchAppDoExtButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoExtButRunClick --- BEGIN
	if (statshrext.ButRunActive) {
		changeStage(dbswznm, VecVSge::EXTRACT, dpcheng);
	};
	// IP handleDpchAppDoExtButRunClick --- END
};

void DlgWznmUtlExtrip::handleDpchAppDoExtButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoExtButStoClick --- INSERT
};

void DlgWznmUtlExtrip::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRXER) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWznmAlert --- IEND
};

void DlgWznmUtlExtrip::handleDpchRetWznm(
			DbsWznm* dbswznm
			, DpchRetWznm* dpchret
		) {
	// IP handleDpchRetWznm --- INSERT
};

void DlgWznmUtlExtrip::handleDpchRetWznmPrctreeExtract(
			DbsWznm* dbswznm
			, DpchRetWznmPrctreeExtract* dpchret
		) {
	logfile = dpchret->logfile; // IP handleDpchRetWznmPrctreeExtract --- ILINE
};

void DlgWznmUtlExtrip::handleUploadInSgeIdle(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswznm, VecVSge::UPKIDLE);
};

string DlgWznmUtlExtrip::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfile); // IP handleDownloadInSgeDone --- RLINE
};

string DlgWznmUtlExtrip::handleDownloadInSgeFail(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

void DlgWznmUtlExtrip::handleTimerInSgeUpkidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmUtlExtrip::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRXER: leaveSgeAlrxer(dbswznm); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswznm); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswznm); break;
				case VecVSge::UPKDONE: leaveSgeUpkdone(dbswznm); break;
				case VecVSge::ULDDONE: leaveSgeUlddone(dbswznm); break;
				case VecVSge::SRCVLD: leaveSgeSrcvld(dbswznm); break;
				case VecVSge::ALRVER: leaveSgeAlrver(dbswznm); break;
				case VecVSge::VLDDONE: leaveSgeVlddone(dbswznm); break;
				case VecVSge::EXTRACT: leaveSgeExtract(dbswznm); break;
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
			case VecVSge::ALRXER: _ixVSge = enterSgeAlrxer(dbswznm, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswznm, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswznm, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswznm, reenter); break;
			case VecVSge::ULDDONE: _ixVSge = enterSgeUlddone(dbswznm, reenter); break;
			case VecVSge::SRCVLD: _ixVSge = enterSgeSrcvld(dbswznm, reenter); break;
			case VecVSge::ALRVER: _ixVSge = enterSgeAlrver(dbswznm, reenter); break;
			case VecVSge::VLDDONE: _ixVSge = enterSgeVlddone(dbswznm, reenter); break;
			case VecVSge::EXTRACT: _ixVSge = enterSgeExtract(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmUtlExtrip::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::ULDDONE) || (ixVSge == VecVSge::SRCVLD) || (ixVSge == VecVSge::ALRVER) || (ixVSge == VecVSge::VLDDONE) || (ixVSge == VecVSge::EXTRACT) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::UNPACK) retval = "unpacking source";
			else if (ixVSge == VecVSge::UPKDONE) retval = "source unpacked";
			else if (ixVSge == VecVSge::ULDDONE) retval = "source uploaded";
			else if (ixVSge == VecVSge::SRCVLD) retval = "validating source";
			else if (ixVSge == VecVSge::ALRVER) retval = "validation error";
			else if (ixVSge == VecVSge::VLDDONE) retval = "validation done";
			else if (ixVSge == VecVSge::EXTRACT) retval = "extracting insertion points";
			else if (ixVSge == VecVSge::PACK) retval = "packing result";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmUtlExtrip::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeAlrxer(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRXER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrxer --- RBEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Extraction error. View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrxer --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeAlrxer(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrxer --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeUpkidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeUpkidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeUnpack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN

	// 1st try: assume .tgz input file archive
	infolder = infilename.substr(infilename.rfind("/")+1);
	infile = infolder + ".tgz";

	Wznm::run("mv " + infilename + " " + infilename + ".tgz");

	outfolder = Tmp::newfolder(xchg->tmppath);
	outfile = Tmp::newfile(xchg->tmppath, "tgz");

	if (!Wznm::untgz(xchg->tmppath + "/" + infile, xchg->tmppath + "/" + infolder)) {
		// 2nd try: single input file
		infolder = "";

		Wznm::run("mv " + infilename + ".tgz " + infilename);
		infile = infilename.substr(infilename.rfind("/")+1);

		outfolder = "";
		outfile = Tmp::newfile(xchg->tmppath, "");

		retval = VecVSge::ULDDONE;
	};

	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeUnpack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeUpkdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeUpkdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeUlddone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ULDDONE;

	// IP enterSgeUlddone --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeUlddone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUlddone --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeSrcvld(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::VLDDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRVER;

	// IP enterSgeSrcvld --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeSrcvld(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSrcvld --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeAlrver(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRVER;
	nextIxVSgeSuccess = VecVSge::VLDDONE;

	// IP enterSgeAlrver --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeAlrver(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrver --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeVlddone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::VLDDONE;

	// IP enterSgeVlddone --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeVlddone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeVlddone --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeExtract(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::EXTRACT;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRXER;

	clearInvs();

	// IP enterSgeExtract --- IBEGIN

	// invoke WznmPrctreeExtract

	if (infolder == "") {
		// single file
		addInv(new DpchInvWznmPrctreeExtract(0, 0, infile, "", outfile, ""));
	} else {
		// multiple files
		addInv(new DpchInvWznmPrctreeExtract(0, 0, "", infolder, "", outfolder));
	};

	// IP enterSgeExtract --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmUtlExtrip::leaveSgeExtract(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExtract --- INSERT
};

uint DlgWznmUtlExtrip::enterSgePack(
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

void DlgWznmUtlExtrip::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeFail(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeFail(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWznmUtlExtrip::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmUtlExtrip::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};



