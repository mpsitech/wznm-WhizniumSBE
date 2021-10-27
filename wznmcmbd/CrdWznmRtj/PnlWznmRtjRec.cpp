/**
	* \file PnlWznmRtjRec.cpp
	* job handler for job PnlWznmRtjRec (implementation)
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

#include "PnlWznmRtjRec.h"

#include "PnlWznmRtjRec_blks.cpp"
#include "PnlWznmRtjRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmRtjRec
 ******************************************************************************/

PnlWznmRtjRec::PnlWznmRtjRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMRTJREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnl1nrtblock = NULL;
	pnlsup1nrtjob = NULL;
	pnldetail = NULL;
	pnl1nrtdpch = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMRTJ_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMRTJ_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMRTJ_APPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFRTJ, jref);
};

PnlWznmRtjRec::~PnlWznmRtjRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmRtjRec::getNewDpchEng(
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

void PnlWznmRtjRec::refresh(
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
	continf.TxtRef = StubWznm::getStubRtjStd(dbswznm, recRtj.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recRtj.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nrtdpch) {delete pnl1nrtdpch; pnl1nrtdpch = NULL;};
		if (pnl1nrtblock) {delete pnl1nrtblock; pnl1nrtblock = NULL;};
		if (pnlsup1nrtjob) {delete pnlsup1nrtjob; pnlsup1nrtjob = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmRtjDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nrtdpch) pnl1nrtdpch = new PnlWznmRtj1NRtdpch(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nrtblock) pnl1nrtblock = new PnlWznmRtj1NRtblock(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsup1nrtjob) pnlsup1nrtjob = new PnlWznmRtjSup1NRtjob(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NRtdpch = ((pnl1nrtdpch) ? pnl1nrtdpch->jref : 0);
	statshr.jref1NRtblock = ((pnl1nrtblock) ? pnl1nrtblock->jref : 0);
	statshr.jrefSup1NRtjob = ((pnlsup1nrtjob) ? pnlsup1nrtjob->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmRtjRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFRTJ) {
		WznmMRtjob* _recRtj = NULL;

		if (dbswznm->tblwznmmrtjob->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRTJ, jref), &_recRtj)) {
			recRtj = *_recRtj;
			delete _recRtj;
		} else recRtj = WznmMRtjob();

		if (recRtj.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nrtdpch) pnl1nrtdpch->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nrtblock) pnl1nrtblock->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsup1nrtjob) pnlsup1nrtjob->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmRtjRec::minimize(
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

void PnlWznmRtjRec::regularize(
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

void PnlWznmRtjRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJRECDO) {
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

void PnlWznmRtjRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmRtjRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmRtjRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmRtjRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMRTJUPD_REFEQ) {
		call->abort = handleCallWznmRtjUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRTJ_SUPEQ) {
		call->abort = handleCallWznmRtj_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRTJ_JOBEQ) {
		call->abort = handleCallWznmRtj_jobEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRTJ_APPEQ) {
		call->abort = handleCallWznmRtj_appEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmRtjRec::handleCallWznmRtjUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmRtjUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmRtjRec::handleCallWznmRtj_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRtj.supRefWznmMRtjob == refInv); // IP handleCallWznmRtj_supEq --- LINE
	return retval;
};

bool PnlWznmRtjRec::handleCallWznmRtj_jobEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRtj.refWznmMJob == refInv); // IP handleCallWznmRtj_jobEq --- LINE
	return retval;
};

bool PnlWznmRtjRec::handleCallWznmRtj_appEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRtj.refWznmMApp == refInv); // IP handleCallWznmRtj_appEq --- LINE
	return retval;
};
