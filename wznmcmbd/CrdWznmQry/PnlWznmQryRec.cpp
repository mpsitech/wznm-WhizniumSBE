/**
	* \file PnlWznmQryRec.cpp
	* job handler for job PnlWznmQryRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmQryRec.h"

#include "PnlWznmQryRec_blks.cpp"
#include "PnlWznmQryRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmQryRec
 ******************************************************************************/

PnlWznmQryRec::PnlWznmQryRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMQRYREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlmnpanel = NULL;
	pnlmndialog = NULL;
	pnlmntable = NULL;
	pnlsup1nquery = NULL;
	pnl1nquerymod = NULL;
	pnlqry1nquerycol = NULL;
	pnlaorder = NULL;
	pnlaclause = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMQRY_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMQRY_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMQRY_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFQRY, jref);
};

PnlWznmQryRec::~PnlWznmQryRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmQryRec::getNewDpchEng(
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

void PnlWznmQryRec::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWznm::getStubQryStd(dbswznm, recQry.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recQry.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlaclause) {delete pnlaclause; pnlaclause = NULL;};
		if (pnlaorder) {delete pnlaorder; pnlaorder = NULL;};
		if (pnlqry1nquerycol) {delete pnlqry1nquerycol; pnlqry1nquerycol = NULL;};
		if (pnl1nquerymod) {delete pnl1nquerymod; pnl1nquerymod = NULL;};
		if (pnlsup1nquery) {delete pnlsup1nquery; pnlsup1nquery = NULL;};
		if (pnlmntable) {delete pnlmntable; pnlmntable = NULL;};
		if (pnlmndialog) {delete pnlmndialog; pnlmndialog = NULL;};
		if (pnlmnpanel) {delete pnlmnpanel; pnlmnpanel = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmQryDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlaclause) pnlaclause = new PnlWznmQryAClause(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlaorder) pnlaorder = new PnlWznmQryAOrder(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlqry1nquerycol) pnlqry1nquerycol = new PnlWznmQryQry1NQuerycol(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nquerymod) pnl1nquerymod = new PnlWznmQry1NQuerymod(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsup1nquery) pnlsup1nquery = new PnlWznmQrySup1NQuery(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmntable) pnlmntable = new PnlWznmQryMNTable(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmndialog) pnlmndialog = new PnlWznmQryMNDialog(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnpanel) pnlmnpanel = new PnlWznmQryMNPanel(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAClause = ((pnlaclause) ? pnlaclause->jref : 0);
	statshr.jrefAOrder = ((pnlaorder) ? pnlaorder->jref : 0);
	statshr.jrefQry1NQuerycol = ((pnlqry1nquerycol) ? pnlqry1nquerycol->jref : 0);
	statshr.jref1NQuerymod = ((pnl1nquerymod) ? pnl1nquerymod->jref : 0);
	statshr.jrefSup1NQuery = ((pnlsup1nquery) ? pnlsup1nquery->jref : 0);
	statshr.jrefMNTable = ((pnlmntable) ? pnlmntable->jref : 0);
	statshr.jrefMNDialog = ((pnlmndialog) ? pnlmndialog->jref : 0);
	statshr.jrefMNPanel = ((pnlmnpanel) ? pnlmnpanel->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmQryRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFQRY) {
		WznmMQuery* _recQry = NULL;

		if (dbswznm->tblwznmmquery->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFQRY, jref), &_recQry)) {
			recQry = *_recQry;
			delete _recQry;
		} else recQry = WznmMQuery();

		if (recQry.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlaclause) pnlaclause->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlaorder) pnlaorder->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlqry1nquerycol) pnlqry1nquerycol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nquerymod) pnl1nquerymod->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsup1nquery) pnlsup1nquery->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmntable) pnlmntable->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmndialog) pnlmndialog->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnpanel) pnlmnpanel->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmQryRec::minimize(
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

void PnlWznmQryRec::regularize(
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

void PnlWznmQryRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYRECDO) {
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

void PnlWznmQryRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmQryRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmQryRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmQryRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMQRYUPD_REFEQ) {
		call->abort = handleCallWznmQryUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQRY_VEREQ) {
		call->abort = handleCallWznmQry_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQRY_SUPEQ) {
		call->abort = handleCallWznmQry_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQRY_JOBEQ) {
		call->abort = handleCallWznmQry_jobEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmQryRec::handleCallWznmQryUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmQryUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmQryRec::handleCallWznmQry_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recQry.refWznmMVersion == refInv); // IP handleCallWznmQry_verEq --- LINE
	return retval;
};

bool PnlWznmQryRec::handleCallWznmQry_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recQry.supRefWznmMQuery == refInv); // IP handleCallWznmQry_supEq --- LINE
	return retval;
};

bool PnlWznmQryRec::handleCallWznmQry_jobEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recQry.refWznmMJob == refInv); // IP handleCallWznmQry_jobEq --- LINE
	return retval;
};

