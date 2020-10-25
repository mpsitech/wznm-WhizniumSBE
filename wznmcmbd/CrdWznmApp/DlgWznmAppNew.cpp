/**
	* \file DlgWznmAppNew.cpp
	* job handler for job DlgWznmAppNew (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmAppNew.h"

#include "DlgWznmAppNew_blks.cpp"
#include "DlgWznmAppNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmAppNew
 ******************************************************************************/

DlgWznmAppNew::DlgWznmAppNew(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMAPPNEW, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFDetPupTrg.tag = "FeedFDetPupTrg";
	VecWznmVApptarget::fillFeed(feedFDetPupTrg);
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

DlgWznmAppNew::~DlgWznmAppNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmAppNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFDetPupTrg, &feedFDetPupVer, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWznmAppNew::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButCncActive = evalButCncActive(dbswznm);
	statshr.ButCreActive = evalButCreActive(dbswznm);

	// continf
	continf.numFSge = ixVSge;

	// contiac

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
};

void DlgWznmAppNew::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPNEWDO) {
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

void DlgWznmAppNew::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmAppNew::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	// validate numFDetPupTrg
	valid = (feedFDetPupTrg.getIxByNum(_contiac->numFDetPupTrg) != 0);
	contiac.numFDetPupTrg = _contiac->numFDetPupTrg;

	if (valid) {
		// validate numFDetPupVer
		valid = (feedFDetPupVer.getRefByNum(_contiac->numFDetPupVer) != 0);
		contiac.numFDetPupVer = _contiac->numFDetPupVer;
	};

	if (valid) {
		// validate DetTxfSho
		valid = (_contiac->DetTxfSho.length() == 4);
		if (valid) contiac.DetTxfSho = _contiac->DetTxfSho;
		else contiac.DetTxfSho = "";
	};

	if (valid) {
		// validate DetTxfTit
		valid = (_contiac->DetTxfTit.length() > 0);
		contiac.DetTxfTit = _contiac->DetTxfTit;
	};

	refresh(dbswznm, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmAppNew::handleDpchAppDoButCncClick(
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

void DlgWznmAppNew::handleDpchAppDoButCreClick(
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

void DlgWznmAppNew::changeStage(
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
			if (!muteRefresh) refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmAppNew::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmAppNew::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmAppNew::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmAppNew::enterSgeCreate(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN

	WznmMApp app;

	app.grp = xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref);
	app.own = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	app.ixWznmVApptarget = feedFDetPupTrg.getByNum(contiac.numFDetPupTrg)->ix;
	app.verRefWznmMVersion = feedFDetPupVer.getByNum(contiac.numFDetPupVer)->ref;
	app.verNum = 1;
	if (dbswznm->loadUintBySQL("SELECT verNum FROM TblWznmMApp WHERE verRefWznmMVersion = " + to_string(app.verRefWznmMVersion) + " AND Short = '" + contiac.DetTxfSho + "' ORDER BY verNum DESC LIMIT 1", app.verNum)) app.verNum++;
	app.Short = contiac.DetTxfSho;
	app.Title = contiac.DetTxfTit;

	dbswznm->tblwznmmapp->insertRec(&app);

	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMAPPMOD, jref);
	xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFAPP, app.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWznmAppNew::leaveSgeCreate(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWznmAppNew::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmAppNew::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


