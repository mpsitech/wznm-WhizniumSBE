/**
	* \file PnlWznmOpkRec.cpp
	* job handler for job PnlWznmOpkRec (implementation)
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

#include "PnlWznmOpkRec.h"

#include "PnlWznmOpkRec_blks.cpp"
#include "PnlWznmOpkRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmOpkRec
 ******************************************************************************/

PnlWznmOpkRec::PnlWznmOpkRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMOPKREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlsqkmnstub = NULL;
	pnlmnlibrary = NULL;
	pnlmncomponent = NULL;
	pnlmnjob = NULL;
	pnl1nop = NULL;
	pnlref1nblock = NULL;
	pnlaretval = NULL;
	pnlainvarg = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMOPK_SQKEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMOPK_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFOPK, jref);
};

PnlWznmOpkRec::~PnlWznmOpkRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmOpkRec::getNewDpchEng(
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

void PnlWznmOpkRec::refresh(
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
	continf.TxtRef = StubWznm::getStubOpkStd(dbswznm, recOpk.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recOpk.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlsqkmnstubAvail = evalPnlsqkmnstubAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlainvarg) {delete pnlainvarg; pnlainvarg = NULL;};
		if (pnlaretval) {delete pnlaretval; pnlaretval = NULL;};
		if (pnl1nop) {delete pnl1nop; pnl1nop = NULL;};
		if (pnlref1nblock) {delete pnlref1nblock; pnlref1nblock = NULL;};
		if (pnlmnjob) {delete pnlmnjob; pnlmnjob = NULL;};
		if (pnlmncomponent) {delete pnlmncomponent; pnlmncomponent = NULL;};
		if (pnlmnlibrary) {delete pnlmnlibrary; pnlmnlibrary = NULL;};
		if (pnlsqkmnstub) {delete pnlsqkmnstub; pnlsqkmnstub = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmOpkDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlainvarg) pnlainvarg = new PnlWznmOpkAInvarg(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlaretval) pnlaretval = new PnlWznmOpkARetval(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nop) pnl1nop = new PnlWznmOpk1NOp(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1nblock) pnlref1nblock = new PnlWznmOpkRef1NBlock(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnjob) pnlmnjob = new PnlWznmOpkMNJob(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmncomponent) pnlmncomponent = new PnlWznmOpkMNComponent(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnlibrary) pnlmnlibrary = new PnlWznmOpkMNLibrary(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsqkmnstub) pnlsqkmnstub = new PnlWznmOpkSqkMNStub(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAInvarg = ((pnlainvarg) ? pnlainvarg->jref : 0);
	statshr.jrefARetval = ((pnlaretval) ? pnlaretval->jref : 0);
	statshr.jref1NOp = ((pnl1nop) ? pnl1nop->jref : 0);
	statshr.jrefRef1NBlock = ((pnlref1nblock) ? pnlref1nblock->jref : 0);
	statshr.jrefMNJob = ((pnlmnjob) ? pnlmnjob->jref : 0);
	statshr.jrefMNComponent = ((pnlmncomponent) ? pnlmncomponent->jref : 0);
	statshr.jrefMNLibrary = ((pnlmnlibrary) ? pnlmnlibrary->jref : 0);
	statshr.jrefSqkMNStub = ((pnlsqkmnstub) ? pnlsqkmnstub->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmOpkRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFOPK) {
		WznmMOppack* _recOpk = NULL;
		WznmMSquawk* _recSqk = NULL;

		if (dbswznm->tblwznmmoppack->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref), &_recOpk)) {
			recOpk = *_recOpk;
			delete _recOpk;
		} else recOpk = WznmMOppack();

		if (dbswznm->tblwznmmsquawk->loadRecByRef(recOpk.refWznmMSquawk, &_recSqk)) {
			recSqk = *_recSqk;
			delete _recSqk;
		} else recSqk = WznmMSquawk();

		if (recOpk.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlainvarg) pnlainvarg->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlaretval) pnlaretval->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nop) pnl1nop->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1nblock) pnlref1nblock->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnjob) pnlmnjob->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmncomponent) pnlmncomponent->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnlibrary) pnlmnlibrary->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsqkmnstub) pnlsqkmnstub->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmOpkRec::minimize(
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

void PnlWznmOpkRec::regularize(
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

void PnlWznmOpkRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKRECDO) {
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

void PnlWznmOpkRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmOpkRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmOpkRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmOpkRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSQKUPD_REFEQ) {
		call->abort = handleCallWznmSqkUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPKUPD_REFEQ) {
		call->abort = handleCallWznmOpkUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPK_SQKEQ) {
		call->abort = handleCallWznmOpk_sqkEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPK_VEREQ) {
		call->abort = handleCallWznmOpk_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmOpkRec::handleCallWznmSqkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSqkUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmOpkRec::handleCallWznmOpkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmOpkUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmOpkRec::handleCallWznmOpk_sqkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpk.refWznmMSquawk == refInv); // IP handleCallWznmOpk_sqkEq --- LINE
	return retval;
};

bool PnlWznmOpkRec::handleCallWznmOpk_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpk.refWznmMVersion == refInv); // IP handleCallWznmOpk_verEq --- LINE
	return retval;
};
