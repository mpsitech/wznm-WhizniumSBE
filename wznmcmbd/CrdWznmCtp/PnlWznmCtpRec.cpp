/**
	* \file PnlWznmCtpRec.cpp
	* job handler for job PnlWznmCtpRec (implementation)
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

#include "PnlWznmCtpRec.h"

#include "PnlWznmCtpRec_blks.cpp"
#include "PnlWznmCtpRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmCtpRec
 ******************************************************************************/

PnlWznmCtpRec::PnlWznmCtpRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMCTPREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnldetail = NULL;
	pnlkparkey = NULL;
	pnlkkey = NULL;
	pnlapar = NULL;
	pnl1ntag = NULL;
	pnltpl1ncapability = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMCPB_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCPB_TPLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCPB_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFCTP, jref);
};

PnlWznmCtpRec::~PnlWznmCtpRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmCtpRec::getNewDpchEng(
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

void PnlWznmCtpRec::refresh(
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
	continf.TxtRef = StubWznm::getStubCtpStd(dbswznm, recCpb.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recCpb.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlkparkey) {delete pnlkparkey; pnlkparkey = NULL;};
		if (pnlkkey) {delete pnlkkey; pnlkkey = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnl1ntag) {delete pnl1ntag; pnl1ntag = NULL;};
		if (pnltpl1ncapability) {delete pnltpl1ncapability; pnltpl1ncapability = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmCtpDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlkparkey) pnlkparkey = new PnlWznmCtpKParKey(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlkkey) pnlkkey = new PnlWznmCtpKKey(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlapar) pnlapar = new PnlWznmCtpAPar(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ntag) pnl1ntag = new PnlWznmCtp1NTag(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnltpl1ncapability) pnltpl1ncapability = new PnlWznmCtpTpl1NCapability(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKParKey = ((pnlkparkey) ? pnlkparkey->jref : 0);
	statshr.jrefKKey = ((pnlkkey) ? pnlkkey->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jref1NTag = ((pnl1ntag) ? pnl1ntag->jref : 0);
	statshr.jrefTpl1NCapability = ((pnltpl1ncapability) ? pnltpl1ncapability->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmCtpRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCTP) {
		WznmMCapability* _recCpb = NULL;

		if (dbswznm->tblwznmmcapability->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCTP, jref), &_recCpb)) {
			recCpb = *_recCpb;
			ixWSubsetCpb = dbswznm->getIxWSubsetByWznmMCapability(_recCpb);
			delete _recCpb;
		} else {
			recCpb = WznmMCapability();
			ixWSubsetCpb = 0;
		};

		if (recCpb.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlkparkey) pnlkparkey->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlkkey) pnlkkey->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ntag) pnl1ntag->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnltpl1ncapability) pnltpl1ncapability->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmCtpRec::minimize(
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

void PnlWznmCtpRec::regularize(
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

void PnlWznmCtpRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPRECDO) {
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

void PnlWznmCtpRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmCtpRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmCtpRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmCtpRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMCPB_INSBS) {
		call->abort = handleCallWznmCpb_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCPB_TPLEQ) {
		call->abort = handleCallWznmCpb_tplEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCPB_VEREQ) {
		call->abort = handleCallWznmCpb_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCPBUPD_REFEQ) {
		call->abort = handleCallWznmCpbUpd_refEq(dbswznm, call->jref);
	};
};

bool PnlWznmCtpRec::handleCallWznmCpb_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetCpb & ixInv) != 0); // IP handleCallWznmCpb_inSbs --- LINE
	return retval;
};

bool PnlWznmCtpRec::handleCallWznmCpb_tplEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCpb.tplRefWznmMCapability == refInv); // IP handleCallWznmCpb_tplEq --- LINE
	return retval;
};

bool PnlWznmCtpRec::handleCallWznmCpb_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCpb.refWznmMVersion == refInv); // IP handleCallWznmCpb_verEq --- LINE
	return retval;
};

bool PnlWznmCtpRec::handleCallWznmCpbUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmCpbUpd_refEq --- INSERT
	return retval;
};
