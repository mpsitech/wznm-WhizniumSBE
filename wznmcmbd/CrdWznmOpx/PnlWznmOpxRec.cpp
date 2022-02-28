/**
	* \file PnlWznmOpxRec.cpp
	* job handler for job PnlWznmOpxRec (implementation)
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

#include "PnlWznmOpxRec.h"

#include "PnlWznmOpxRec_blks.cpp"
#include "PnlWznmOpxRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmOpxRec
 ******************************************************************************/

PnlWznmOpxRec::PnlWznmOpxRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMOPXREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnldetail = NULL;
	pnlainvarg = NULL;
	pnlaretval = NULL;
	pnlref1nblock = NULL;
	pnlmnjob = NULL;
	pnlsqkmnstub = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMOPX_OPKEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMOPX_SQKEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFOPX, jref);
};

PnlWznmOpxRec::~PnlWznmOpxRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmOpxRec::getNewDpchEng(
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

void PnlWznmOpxRec::refresh(
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
	continf.TxtRef = StubWznm::getStubOpxStd(dbswznm, recOpx.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recOpx.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlsqkmnstubAvail = evalPnlsqkmnstubAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlainvarg) {delete pnlainvarg; pnlainvarg = NULL;};
		if (pnlaretval) {delete pnlaretval; pnlaretval = NULL;};
		if (pnlref1nblock) {delete pnlref1nblock; pnlref1nblock = NULL;};
		if (pnlmnjob) {delete pnlmnjob; pnlmnjob = NULL;};
		if (pnlsqkmnstub) {delete pnlsqkmnstub; pnlsqkmnstub = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmOpxDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlainvarg) pnlainvarg = new PnlWznmOpxAInvarg(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlaretval) pnlaretval = new PnlWznmOpxARetval(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1nblock) pnlref1nblock = new PnlWznmOpxRef1NBlock(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnjob) pnlmnjob = new PnlWznmOpxMNJob(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsqkmnstub) pnlsqkmnstub = new PnlWznmOpxSqkMNStub(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAInvarg = ((pnlainvarg) ? pnlainvarg->jref : 0);
	statshr.jrefARetval = ((pnlaretval) ? pnlaretval->jref : 0);
	statshr.jrefRef1NBlock = ((pnlref1nblock) ? pnlref1nblock->jref : 0);
	statshr.jrefMNJob = ((pnlmnjob) ? pnlmnjob->jref : 0);
	statshr.jrefSqkMNStub = ((pnlsqkmnstub) ? pnlsqkmnstub->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmOpxRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFOPX) {
		WznmMOp* _recOpx = NULL;
		WznmMSquawk* _recSqk = NULL;

		if (dbswznm->tblwznmmop->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPX, jref), &_recOpx)) {
			recOpx = *_recOpx;
			delete _recOpx;
		} else recOpx = WznmMOp();

		if (dbswznm->tblwznmmsquawk->loadRecByRef(recOpx.refWznmMSquawk, &_recSqk)) {
			recSqk = *_recSqk;
			delete _recSqk;
		} else recSqk = WznmMSquawk();

		if (recOpx.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlainvarg) pnlainvarg->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlaretval) pnlaretval->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1nblock) pnlref1nblock->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnjob) pnlmnjob->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsqkmnstub) pnlsqkmnstub->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmOpxRec::minimize(
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

void PnlWznmOpxRec::regularize(
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

void PnlWznmOpxRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXRECDO) {
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

void PnlWznmOpxRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmOpxRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmOpxRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmOpxRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMOPX_OPKEQ) {
		call->abort = handleCallWznmOpx_opkEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPX_SQKEQ) {
		call->abort = handleCallWznmOpx_sqkEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPXUPD_REFEQ) {
		call->abort = handleCallWznmOpxUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSQKUPD_REFEQ) {
		call->abort = handleCallWznmSqkUpd_refEq(dbswznm, call->jref);
	};
};

bool PnlWznmOpxRec::handleCallWznmOpx_opkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpx.refWznmMOppack == refInv); // IP handleCallWznmOpx_opkEq --- LINE
	return retval;
};

bool PnlWznmOpxRec::handleCallWznmOpx_sqkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpx.refWznmMSquawk == refInv); // IP handleCallWznmOpx_sqkEq --- LINE
	return retval;
};

bool PnlWznmOpxRec::handleCallWznmOpxUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmOpxUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmOpxRec::handleCallWznmSqkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSqkUpd_refEq --- INSERT
	return retval;
};
