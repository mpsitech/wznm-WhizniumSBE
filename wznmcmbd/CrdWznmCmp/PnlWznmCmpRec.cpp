/**
	* \file PnlWznmCmpRec.cpp
	* job handler for job PnlWznmCmpRec (implementation)
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

#include "PnlWznmCmpRec.h"

#include "PnlWznmCmpRec_blks.cpp"
#include "PnlWznmCmpRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmCmpRec
 ******************************************************************************/

PnlWznmCmpRec::PnlWznmCmpRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMCMPREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlmnoppack = NULL;
	pnlmnlibrary = NULL;
	pnl1nrelease = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMCMP_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCMP_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCMP_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFCMP, jref);
};

PnlWznmCmpRec::~PnlWznmCmpRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmCmpRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmCmpRec::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWznm::getStubCmpStd(dbswznm, recCmp.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recCmp.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlmnlibraryAvail = evalPnlmnlibraryAvail(dbswznm);
	statshr.pnlmnoppackAvail = evalPnlmnoppackAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nrelease) {delete pnl1nrelease; pnl1nrelease = NULL;};
		if (pnlmnlibrary) {delete pnlmnlibrary; pnlmnlibrary = NULL;};
		if (pnlmnoppack) {delete pnlmnoppack; pnlmnoppack = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmCmpDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nrelease) pnl1nrelease = new PnlWznmCmp1NRelease(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnlibrary) pnlmnlibrary = new PnlWznmCmpMNLibrary(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnoppack) pnlmnoppack = new PnlWznmCmpMNOppack(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NRelease = ((pnl1nrelease) ? pnl1nrelease->jref : 0);
	statshr.jrefMNLibrary = ((pnlmnlibrary) ? pnlmnlibrary->jref : 0);
	statshr.jrefMNOppack = ((pnlmnoppack) ? pnlmnoppack->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmCmpRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCMP) {
		WznmMComponent* _recCmp = NULL;

		if (dbswznm->tblwznmmcomponent->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCMP, jref), &_recCmp)) {
			recCmp = *_recCmp;
			ixWSubsetCmp = dbswznm->getIxWSubsetByWznmMComponent(_recCmp);
			delete _recCmp;
		} else {
			recCmp = WznmMComponent();
			ixWSubsetCmp = 0;
		};

		if (recCmp.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nrelease) pnl1nrelease->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnlibrary) pnlmnlibrary->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnoppack) pnlmnoppack->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmCmpRec::minimize(
			DbsWznm* dbswznm
			, const bool notif
			, DpchEngWznm** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWznmVExpstate != VecWznmVExpstate::MIND) {
		statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswznm, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWznmCmpRec::regularize(
			DbsWznm* dbswznm
			, const bool notif
			, DpchEngWznm** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWznmVExpstate != VecWznmVExpstate::REGD) {
		statshr.ixWznmVExpstate = VecWznmVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswznm, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWznmCmpRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmCmpRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmCmpRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmCmpRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmCmpRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMCMPUPD_REFEQ) {
		call->abort = handleCallWznmCmpUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCMP_VEREQ) {
		call->abort = handleCallWznmCmp_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCMP_TYPEQ) {
		call->abort = handleCallWznmCmp_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCMP_INSBS) {
		call->abort = handleCallWznmCmp_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWznmCmpRec::handleCallWznmCmpUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmCmpUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmCmpRec::handleCallWznmCmp_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCmp.refWznmMVersion == refInv); // IP handleCallWznmCmp_verEq --- LINE
	return retval;
};

bool PnlWznmCmpRec::handleCallWznmCmp_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCmp.ixVBasetype == ixInv); // IP handleCallWznmCmp_typEq --- LINE
	return retval;
};

bool PnlWznmCmpRec::handleCallWznmCmp_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetCmp & ixInv) != 0); // IP handleCallWznmCmp_inSbs --- LINE
	return retval;
};
