/**
	* \file PnlWznmNavComp.cpp
	* job handler for job PnlWznmNavComp (implementation)
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

#include "PnlWznmNavComp.h"

#include "PnlWznmNavComp_blks.cpp"
#include "PnlWznmNavComp_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmNavComp
 ******************************************************************************/

PnlWznmNavComp::PnlWznmNavComp(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMNAVCOMP, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstOpk.tag = "FeedFLstOpk";
	feedFLstOpx.tag = "FeedFLstOpx";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshOpk(dbswznm, moditems);
	refreshOpx(dbswznm, moditems);
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMOPK, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMOPX, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
};

PnlWznmNavComp::~PnlWznmNavComp() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmNavComp::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstOpk, &feedFLstOpx, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmNavComp::refreshLstOpk(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstOpkAvail = evalLstOpkAvail(dbswznm);
	statshr.ButOpkViewActive = evalButOpkViewActive(dbswznm);
	statshr.ButOpkNewcrdActive = evalButOpkNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavComp::refreshOpk(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstOpk = 0;

	// feedFLstOpk
	feedFLstOpk.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMOPK, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstOpk.appendRefTitles(rec->ref, StubWznm::getStubOpkStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTOPK);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstOpk(dbswznm, moditems);
};

void PnlWznmNavComp::refreshLstOpx(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstOpxAvail = evalLstOpxAvail(dbswznm);
	statshr.ButOpxViewActive = evalButOpxViewActive(dbswznm);
	statshr.ButOpxNewcrdActive = evalButOpxNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavComp::refreshOpx(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstOpx = 0;

	// feedFLstOpx
	feedFLstOpx.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMOPX, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstOpx.appendRefTitles(rec->ref, StubWznm::getStubOpxStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTOPX);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstOpx(dbswznm, moditems);
};

void PnlWznmNavComp::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWznmNavComp::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswznm, moditems);

	refreshLstOpk(dbswznm, moditems);
	refreshLstOpx(dbswznm, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWznmNavComp::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVCOMPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVCOMPDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTOPKVIEWCLICK) {
					handleDpchAppDoButOpkViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPKNEWCRDCLICK) {
					handleDpchAppDoButOpkNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPXVIEWCLICK) {
					handleDpchAppDoButOpxViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPXNEWCRDCLICK) {
					handleDpchAppDoButOpxNewcrdClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmNavComp::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmNavComp::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTOPK)) {
		contiac.numFLstOpk = _contiac->numFLstOpk;
		refreshLstOpk(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTOPX)) {
		contiac.numFLstOpx = _contiac->numFLstOpx;
		refreshLstOpx(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmNavComp::handleDpchAppDoButOpkViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstOpkAvail && statshr.ButOpkViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstOpk.getRefByNum(contiac.numFLstOpk), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmOpk", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmOpk");
	};
};

void PnlWznmNavComp::handleDpchAppDoButOpkNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButOpkNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmOpk", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmOpk");
	};
};

void PnlWznmNavComp::handleDpchAppDoButOpxViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstOpxAvail && statshr.ButOpxViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstOpx.getRefByNum(contiac.numFLstOpx), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmOpx", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmOpx");
	};
};

void PnlWznmNavComp::handleDpchAppDoButOpxNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButOpxNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmOpx", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmOpx");
	};
};

void PnlWznmNavComp::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWznmHusrRunvMod_crdUsrEq(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWznmNavComp::handleCallWznmHusrRunvMod_crdUsrEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVCard::CRDWZNMOPK) {
		refreshOpk(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMOPX) {
		refreshOpx(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};



