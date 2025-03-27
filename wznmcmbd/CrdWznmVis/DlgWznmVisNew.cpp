/**
	* \file DlgWznmVisNew.cpp
	* job handler for job DlgWznmVisNew (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmVisNew.h"

#include "DlgWznmVisNew_blks.cpp"
#include "DlgWznmVisNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVisNew
 ******************************************************************************/

DlgWznmVisNew::DlgWznmVisNew(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVISNEW, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFDetPupTyp.tag = "FeedFDetPupTyp";
	VecWznmVMVisualBasetype::fillFeed(ixWznmVLocale, feedFDetPupTyp);
	feedFDetPupVer.tag = "FeedFDetPupVer";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	ListWznmMVersion vers;
	WznmMVersion* ver = NULL;

	dbswznm->tblwznmmversion->loadRstBySQL("SELECT TblWznmMVersion.* FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMVersion.prjRefWznmMProject = TblWznmMProject.ref ORDER BY TblWznmMProject.Title ASC, TblWznmMVersion.Major ASC, TblWznmMVersion.Minor ASC, TblWznmMVersion.Sub ASC", false, vers);
	for (unsigned int i = 0; i < vers.nodes.size(); i++) {
		ver = vers.nodes[i];
		feedFDetPupVer.appendRefTitles(ver->ref, StubWznm::getStubVerStd(dbswznm, ver->ref));
	};
	// IP constructor.cust1 --- IEND

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmVisNew::~DlgWznmVisNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmVisNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFDetPupTyp, &feedFDetPupVer, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWznmVisNew::refresh(
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
	statshr.ButCncActive = evalButCncActive(dbswznm);
	statshr.ButCreActive = evalButCreActive(dbswznm);

	// contiac

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void DlgWznmVisNew::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVISNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVISNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void DlgWznmVisNew::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVisNew::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	// validate numFDetPupTyp
	valid = (feedFDetPupTyp.getIxByNum(_contiac->numFDetPupTyp) != 0);
	contiac.numFDetPupTyp = _contiac->numFDetPupTyp;

	if (valid) {
		// validate numFDetPupVer
		valid = (feedFDetPupVer.getRefByNum(_contiac->numFDetPupVer) != 0);
		contiac.numFDetPupVer = _contiac->numFDetPupVer;
	};

	contiac.DetTxfCmt = _contiac->DetTxfCmt;

	refresh(dbswznm, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmVisNew::handleDpchAppDoButCncClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCncClick --- IBEGIN
	if (statshr.ButCncActive) {
		*dpcheng = new DpchEngWznmConfirm(true, jref, "");
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButCncClick --- IEND
};

void DlgWznmVisNew::handleDpchAppDoButCreClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbswznm, VecVSge::CREATE, dpcheng);
		};

		if (ixVSge == VecVSge::DONE) {
			if (!*dpcheng) *dpcheng = new DpchEngWznmConfirm(true, jref, "");
			xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
		};
	};
	// IP handleDpchAppDoButCreClick --- REND
};

void DlgWznmVisNew::changeStage(
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
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmVisNew::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmVisNew::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVisNew::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVisNew::enterSgeCreate(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN

	WznmMVisual vis;

	vis.grp = xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref);
	vis.own = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	vis.ixVBasetype = feedFDetPupTyp.getByNum(contiac.numFDetPupTyp)->ix;
	vis.verRefWznmMVersion = feedFDetPupVer.getByNum(contiac.numFDetPupVer)->ref;
	vis.verNum = 1;
	if (dbswznm->loadUintBySQL("SELECT verNum FROM TblWznmMVisual WHERE verRefWznmMVersion = " + to_string(vis.verRefWznmMVersion) + " ORDER BY verNum DESC LIMIT 1", vis.verNum)) vis.verNum++;
	vis.Comment = contiac.DetTxfCmt;

	dbswznm->tblwznmmvisual->insertRec(&vis);

	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMVISMOD, jref);
	xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFVIS, vis.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWznmVisNew::leaveSgeCreate(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWznmVisNew::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmVisNew::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
