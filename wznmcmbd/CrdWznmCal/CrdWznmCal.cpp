/**
	* \file CrdWznmCal.cpp
	* job handler for job CrdWznmCal (implementation)
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

#include "CrdWznmCal.h"

#include "CrdWznmCal_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWznmCal
 ******************************************************************************/

CrdWznmCal::CrdWznmCal(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
			, const ubigint ref
			, const uint ixWznmVPreset
			, const ubigint preUref
		) :
			JobWznm(xchg, VecWznmVJob::CRDWZNMCAL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref, ixWznmVPreset);
	if (ixWznmVPreset != VecWznmVPreset::VOID) xchg->addRefPreset(ixWznmVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFCAL, ref);

	// initialize according to ref
	changeRef(dbswznm, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnlrec = new PnlWznmCalRec(xchg, dbswznm, jref, ixWznmVLocale);
	pnlheadbar = new PnlWznmCalHeadbar(xchg, dbswznm, jref, ixWznmVLocale);
	pnllist = new PnlWznmCalList(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswznm, moditems);

	changeStage(dbswznm, VecVSge::IDLE);

	xchg->addClstn(VecWznmVCall::CALLWZNMDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWznmCal::~CrdWznmCal() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* CrdWznmCal::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdWznmCal::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWznmCal/" + VecWznmVLocale::getSref(ixWznmVLocale);
	continf.MtxCrdCal = StubWznm::getStubCalStd(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAL, jref), ixWznmVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdWznmCal::changeRef(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWznmVPreset = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswznm, VecWznmVCall::CALLWZNMLOG, jref, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref), "CrdWznmCal", ref);
	xchg->addRefPreset(VecWznmVPreset::PREWZNMREFCAL, jref, ref);

	if (pnllist) pnllist->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFCAL, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFCAL, jrefTrig, notif);

	refresh(dbswznm, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWznmCal::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWznmCal::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWznmCal::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWznmCal::handleDpchAppDoClose(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	xchg->triggerIxCall(dbswznm, VecWznmVCall::CALLWZNMCRDCLOSE, jref, VecWznmVCard::CRDWZNMCAL);
};

void CrdWznmCal::handleDpchAppDoMitAppAbtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswznm, VecVSge::ALRWZNMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWznmCal::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- BEGIN
	if (ixVSge == VecVSge::ALRWZNMABT) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	// IP handleDpchAppWznmAlert --- END
};

void CrdWznmCal::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMDLGCLOSE) {
		call->abort = handleCallWznmDlgClose(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTATCHG) {
		call->abort = handleCallWznmStatChg(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREFPRESET) {
		call->abort = handleCallWznmRefPreSet(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool CrdWznmCal::handleCallWznmDlgClose(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmDlgClose --- INSERT
	return retval;
};

bool CrdWznmCal::handleCallWznmStatChg(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD) && (pnlrec->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD)) pnllist->minimize(dbswznm, true);
	return retval;
};

bool CrdWznmCal::handleCallWznmRefPreSet(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWznmVPreset::PREWZNMREFCAL) {
		changeRef(dbswznm, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswznm, true);
	};

	return retval;
};

void CrdWznmCal::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRWZNMABT: leaveSgeAlrwznmabt(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRWZNMABT: _ixVSge = enterSgeAlrwznmabt(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWznmCal::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWznmCal::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWznmCal::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWznmCal::enterSgeAlrwznmabt(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWznm::prepareAlrAbt(jref, ixWznmVLocale, feedFMcbAlert)); // IP enterSgeAlrwznmabt --- LINE

	return retval;
};

void CrdWznmCal::leaveSgeAlrwznmabt(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmabt --- INSERT
};
