/**
	* \file PnlWznmSbsRec.cpp
	* job handler for job PnlWznmSbsRec (implementation)
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

#include "PnlWznmSbsRec.h"

#include "PnlWznmSbsRec_blks.cpp"
#include "PnlWznmSbsRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmSbsRec
 ******************************************************************************/

PnlWznmSbsRec::PnlWznmSbsRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMSBSREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlbsbmnsubset = NULL;
	pnlasbmnsubset = NULL;
	pnlpst1nquerymod = NULL;
	pnlfrs1nrelation = NULL;
	pnltos1nrelation = NULL;
	pnl1ntablecol = NULL;
	pnl1nstub = NULL;
	pnlatitle = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMSBS_PSTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSBS_CAREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFSBS, jref);
};

PnlWznmSbsRec::~PnlWznmSbsRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmSbsRec::getNewDpchEng(
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

void PnlWznmSbsRec::refresh(
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
	continf.TxtRef = StubWznm::getStubSbsStd(dbswznm, recSbs.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recSbs.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlpst1nquerymodAvail = evalPnlpst1nquerymodAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlatitle) {delete pnlatitle; pnlatitle = NULL;};
		if (pnl1nstub) {delete pnl1nstub; pnl1nstub = NULL;};
		if (pnl1ntablecol) {delete pnl1ntablecol; pnl1ntablecol = NULL;};
		if (pnltos1nrelation) {delete pnltos1nrelation; pnltos1nrelation = NULL;};
		if (pnlfrs1nrelation) {delete pnlfrs1nrelation; pnlfrs1nrelation = NULL;};
		if (pnlpst1nquerymod) {delete pnlpst1nquerymod; pnlpst1nquerymod = NULL;};
		if (pnlasbmnsubset) {delete pnlasbmnsubset; pnlasbmnsubset = NULL;};
		if (pnlbsbmnsubset) {delete pnlbsbmnsubset; pnlbsbmnsubset = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmSbsDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlatitle) pnlatitle = new PnlWznmSbsATitle(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nstub) pnl1nstub = new PnlWznmSbs1NStub(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ntablecol) pnl1ntablecol = new PnlWznmSbs1NTablecol(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnltos1nrelation) pnltos1nrelation = new PnlWznmSbsTos1NRelation(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlfrs1nrelation) pnlfrs1nrelation = new PnlWznmSbsFrs1NRelation(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlpst1nquerymod) pnlpst1nquerymod = new PnlWznmSbsPst1NQuerymod(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlasbmnsubset) pnlasbmnsubset = new PnlWznmSbsAsbMNSubset(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlbsbmnsubset) pnlbsbmnsubset = new PnlWznmSbsBsbMNSubset(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefATitle = ((pnlatitle) ? pnlatitle->jref : 0);
	statshr.jref1NStub = ((pnl1nstub) ? pnl1nstub->jref : 0);
	statshr.jref1NTablecol = ((pnl1ntablecol) ? pnl1ntablecol->jref : 0);
	statshr.jrefTos1NRelation = ((pnltos1nrelation) ? pnltos1nrelation->jref : 0);
	statshr.jrefFrs1NRelation = ((pnlfrs1nrelation) ? pnlfrs1nrelation->jref : 0);
	statshr.jrefPst1NQuerymod = ((pnlpst1nquerymod) ? pnlpst1nquerymod->jref : 0);
	statshr.jrefAsbMNSubset = ((pnlasbmnsubset) ? pnlasbmnsubset->jref : 0);
	statshr.jrefBsbMNSubset = ((pnlbsbmnsubset) ? pnlbsbmnsubset->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmSbsRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSBS) {
		WznmMSubset* _recSbs = NULL;
		WznmMPreset* _recPst = NULL;

		if (dbswznm->tblwznmmsubset->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSBS, jref), &_recSbs)) {
			recSbs = *_recSbs;
			delete _recSbs;
		} else recSbs = WznmMSubset();

		if (dbswznm->tblwznmmpreset->loadRecByRef(recSbs.refWznmMPreset, &_recPst)) {
			recPst = *_recPst;
			delete _recPst;
		} else recPst = WznmMPreset();

		if (recSbs.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlatitle) pnlatitle->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nstub) pnl1nstub->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ntablecol) pnl1ntablecol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnltos1nrelation) pnltos1nrelation->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlfrs1nrelation) pnlfrs1nrelation->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlpst1nquerymod) pnlpst1nquerymod->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlasbmnsubset) pnlasbmnsubset->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlbsbmnsubset) pnlbsbmnsubset->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmSbsRec::minimize(
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

void PnlWznmSbsRec::regularize(
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

void PnlWznmSbsRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSRECDO) {
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

void PnlWznmSbsRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmSbsRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmSbsRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmSbsRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSBSUPD_REFEQ) {
		call->abort = handleCallWznmSbsUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPSTUPD_REFEQ) {
		call->abort = handleCallWznmPstUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSBS_PSTEQ) {
		call->abort = handleCallWznmSbs_pstEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSBS_CAREQ) {
		call->abort = handleCallWznmSbs_carEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_VEREQ) {
		call->abort = handleCallWznmPst_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_REUEQ) {
		call->abort = handleCallWznmPst_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_RETEQ) {
		call->abort = handleCallWznmPst_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWznmSbsRec::handleCallWznmSbsUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSbsUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmSbsRec::handleCallWznmPstUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPstUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmSbsRec::handleCallWznmSbs_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSbs.refWznmMPreset == refInv); // IP handleCallWznmSbs_pstEq --- LINE
	return retval;
};

bool PnlWznmSbsRec::handleCallWznmSbs_carEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSbs.refWznmMCard == refInv); // IP handleCallWznmSbs_carEq --- LINE
	return retval;
};

bool PnlWznmSbsRec::handleCallWznmPst_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refWznmMVersion == refInv); // IP handleCallWznmPst_verEq --- LINE
	return retval;
};

bool PnlWznmSbsRec::handleCallWznmPst_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refUref == refInv); // IP handleCallWznmPst_reuEq --- LINE
	return retval;
};

bool PnlWznmSbsRec::handleCallWznmPst_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refIxVTbl == ixInv); // IP handleCallWznmPst_retEq --- LINE
	return retval;
};
