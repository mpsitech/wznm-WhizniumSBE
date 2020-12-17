/**
	* \file DlgWznmFilNew.cpp
	* job handler for job DlgWznmFilNew (implementation)
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

#include "DlgWznmFilNew.h"

#include "DlgWznmFilNew_blks.cpp"
#include "DlgWznmFilNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmFilNew
 ******************************************************************************/

DlgWznmFilNew::DlgWznmFilNew(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMFILNEW, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFDetPupCnt.tag = "FeedFDetPupCnt";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMFILECONTENT, ixWznmVLocale, feedFDetPupCnt);
	feedFDetPupMim.tag = "FeedFDetPupMim";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMFILEMIMETYPE, ixWznmVLocale, feedFDetPupMim);
	feedFDetPupRet.tag = "FeedFDetPupRet";
	VecWznmVMFileRefTbl::fillFeed(ixWznmVLocale, feedFDetPupRet);
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::DET;

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmFilNew::~DlgWznmFilNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
ubigint DlgWznmFilNew::getRefApp(
			DbsWznm* dbswznm
			, const string& s
		) {
	// expect StubWznmAppStd, ex. 'WZNM Quick Access Bar (WhizniumSBE 0.1)'

	ubigint refApp = 0;

	ubigint refWznmMVersion = 0;
	string Title;

	size_t ptr;

	if (s.length() > 0) {
		if (s[s.length()-1] == ')') {
			ptr = s.find(" (");
			if (ptr != string::npos) {
				refWznmMVersion = getRefVer(dbswznm, s.substr(ptr+2, s.length()-ptr-2-1));

				if (refWznmMVersion != 0) {
					Title = s.substr(0, ptr);
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMApp WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND Title = '" + Title + "'", refApp);
				};
			};
		};
	};

	return refApp;
};

ubigint DlgWznmFilNew::getRefVer(
			DbsWznm* dbswznm
			, const string& s
		) {
	// expect StubWznmVerStd, ex. 'BeamRelay 0.1'

	ubigint refVer = 0;

	ubigint refWznmMProject = 0;
	usmallint Major = 0;
	usmallint Minor = 0;
	usmallint Sub = 0;

	vector<string> ss;

	size_t ptr;

	ptr = s.rfind(' ');
	if (ptr != string::npos) {
		dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMProject WHERE Title = '" + s.substr(0, ptr) + "'", refWznmMProject);

		if (refWznmMProject != 0) {
			StrMod::stringToVector(s.substr(ptr+1), ss, '.');

			if (ss.size() >= 1) {
				Major = atoi(ss[0].c_str());
				if (ss.size() >= 2) Minor = atoi(ss[1].c_str());
				if (ss.size() >= 3) Sub = atoi(ss[2].c_str());

				dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVersion WHERE prjRefWznmMProject = " + to_string(refWznmMProject) + " AND Major = " + to_string(Major) + " AND Minor = " + to_string(Minor) + " AND Sub = " + to_string(Sub), refVer);
			};
		};
	};

	return refVer;
};

// IP cust --- IEND

DpchEngWznm* DlgWznmFilNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &feedFDetPupCnt, &feedFDetPupMim, &feedFDetPupRet, &feedFDse, &feedFSge, &statshr, &statshrdet, &statshrfil, items);
	};

	return dpcheng;
};

void DlgWznmFilNew::refreshDet(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrDet oldStatshrdet(statshrdet);
	ContIacDet oldContiacdet(contiacdet);

	// IP refreshDet --- BEGIN
	// statshrdet
	statshrdet.ButCreActive = evalDetButCreActive(dbswznm);

	// contiacdet

	// IP refreshDet --- END
	if (statshrdet.diff(&oldStatshrdet).size() != 0) insert(moditems, DpchEngData::STATSHRDET);
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
};

void DlgWznmFilNew::refreshFil(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrFil oldStatshrfil(statshrfil);

	// IP refreshFil --- BEGIN
	// statshrfil
	statshrfil.UldActive = evalFilUldActive(dbswznm);

	// IP refreshFil --- END
	if (statshrfil.diff(&oldStatshrfil).size() != 0) insert(moditems, DpchEngData::STATSHRFIL);
};

void DlgWznmFilNew::refresh(
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

	refreshDet(dbswznm, moditems);
	refreshFil(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmFilNew::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMFILNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbswznm, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMFILNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoDet != 0) {
				if (dpchappdo->ixVDoDet == VecVDoDet::BUTCRECLICK) {
					handleDpchAppDoDetButCreClick(dbswznm, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::CREDONE) handleUploadInSgeCredone(dbswznm, req->filename);
	};
};

void DlgWznmFilNew::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmFilNew::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::FIL)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmFilNew::handleDpchAppDataContiacdet(
			DbsWznm* dbswznm
			, ContIacDet* _contiacdet
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	string s;

	size_t ptr;

	if (has(diffitems, ContIacDet::TXFFNM)) {
		contiacdet.TxfFnm = _contiacdet->TxfFnm;

		if (!has(diffitems, ContIacDet::NUMFPUPMIM)) {
			ptr = contiacdet.TxfFnm.rfind('.');
			if (ptr != string::npos) {
				_contiacdet->numFPupMim = feedFDetPupMim.getNumBySref(contiacdet.TxfFnm.substr(ptr+1));
				add(diffitems, ContIacDet::NUMFPUPMIM);
			};
		};
	};

	if (has(diffitems, ContIacDet::NUMFPUPRET)) {
		if (feedFDetPupRet.getIxByNum(_contiacdet->numFPupRet) != 0) contiacdet.numFPupRet = _contiacdet->numFPupRet;
		else contiacdet.numFPupRet = 0;

		if (!has(diffitems, ContIacDet::TXFREU)) contiacdet.TxfReu = "";
	};

	if (has(diffitems, ContIacDet::TXFREU)) {
		contiacdet.TxfReu = "";

		if (contiacdet.numFPupRet == VecWznmVMFileRefTbl::APP) {
			if (getRefApp(dbswznm, _contiacdet->TxfReu) != 0) contiacdet.TxfReu = _contiacdet->TxfReu;
		} else if (contiacdet.numFPupRet == VecWznmVMFileRefTbl::VER) {
			if (getRefVer(dbswznm, _contiacdet->TxfReu) != 0) contiacdet.TxfReu = _contiacdet->TxfReu;
		};
	};

	if (has(diffitems, ContIacDet::NUMFPUPCNT)) {
		if (feedFDetPupCnt.getSrefByNum(_contiacdet->numFPupCnt) != "") contiacdet.numFPupCnt = _contiacdet->numFPupCnt;
		else contiacdet.numFPupCnt = 0;
	};

	if (has(diffitems, ContIacDet::NUMFPUPMIM)) {
		if (feedFDetPupMim.getSrefByNum(_contiacdet->numFPupMim) != "") contiacdet.numFPupMim = _contiacdet->numFPupMim;
		else contiacdet.numFPupMim = 0;
	};

	valid = ((contiacdet.TxfFnm != "") && (contiacdet.numFPupRet != 0) && ((contiacdet.numFPupRet == VecWznmVMFileRefTbl::VOID)  || ((contiacdet.numFPupRet > VecWznmVMFileRefTbl::VOID) && (contiacdet.TxfReu != "")))
				&& (contiacdet.numFPupCnt != 0) && (contiacdet.numFPupMim != 0));

	refresh(dbswznm, moditems);

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmFilNew::handleDpchAppDoButDneClick(
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

void DlgWznmFilNew::handleDpchAppDoDetButCreClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoDetButCreClick --- BEGIN
	if (statshrdet.ButCreActive) {
		changeStage(dbswznm, VecVSge::CREATE, dpcheng);
	};
	// IP handleDpchAppDoDetButCreClick --- END
};

void DlgWznmFilNew::handleUploadInSgeCredone(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeCredone --- ILINE
	changeStage(dbswznm, VecVSge::DONE);
};

void DlgWznmFilNew::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswznm); break;
				case VecVSge::CREDONE: leaveSgeCredone(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswznm, reenter); break;
			case VecVSge::CREDONE: _ixVSge = enterSgeCredone(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmFilNew::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if (ixVSge == VecVSge::CREDONE) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::CREDONE) retval = "new file created";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmFilNew::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmFilNew::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmFilNew::enterSgeCreate(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CREDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN

	WznmMFile fil;

	fil.grp = xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref);
	fil.own = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	fil.refIxVTbl = feedFDetPupRet.getIxByNum(contiacdet.numFPupRet);
	if (fil.refIxVTbl == VecWznmVMFileRefTbl::APP) fil.refUref = getRefApp(dbswznm, contiacdet.TxfReu);
	else if (fil.refIxVTbl == VecWznmVMFileRefTbl::VER) fil.refUref = getRefVer(dbswznm, contiacdet.TxfReu);
	fil.osrefKContent = feedFDetPupCnt.getSrefByNum(contiacdet.numFPupCnt);
	fil.Filename = contiacdet.TxfFnm;
	fil.srefKMimetype = feedFDetPupMim.getSrefByNum(contiacdet.numFPupMim);

	dbswznm->tblwznmmfile->insertRec(&fil);

	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMFILMOD, jref);
	xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFFIL, fil.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWznmFilNew::leaveSgeCreate(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWznmFilNew::enterSgeCredone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CREDONE;

	// IP enterSgeCredone --- INSERT

	return retval;
};

void DlgWznmFilNew::leaveSgeCredone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCredone --- INSERT
};

uint DlgWznmFilNew::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN

	Acv::alterfile(dbswznm, xchg->acvpath, infilename, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFFIL, jref));

	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWznmFilNew::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
