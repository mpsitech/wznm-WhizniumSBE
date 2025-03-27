/**
	* \file PnlWznmConRec.cpp
	* job handler for job PnlWznmConRec (implementation)
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

#include "PnlWznmConRec.h"

#include "PnlWznmConRec_blks.cpp"
#include "PnlWznmConRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmConRec
 ******************************************************************************/

PnlWznmConRec::PnlWznmConRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMCONREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlfedref1nrtblock = NULL;
	pnlsup1ncontrol = NULL;
	pnldetail = NULL;
	pnlapar = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMFED_SRUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMFED_SRTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_STSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_SHSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_FEDEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFCON, jref);
};

PnlWznmConRec::~PnlWznmConRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmConRec::getNewDpchEng(
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

void PnlWznmConRec::refresh(
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
	continf.TxtRef = StubWznm::getStubConStd(dbswznm, recCon.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recCon.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlfedref1nrtblockAvail = evalPnlfedref1nrtblockAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlsup1ncontrol) {delete pnlsup1ncontrol; pnlsup1ncontrol = NULL;};
		if (pnlfedref1nrtblock) {delete pnlfedref1nrtblock; pnlfedref1nrtblock = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmConDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlapar) pnlapar = new PnlWznmConAPar(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsup1ncontrol) pnlsup1ncontrol = new PnlWznmConSup1NControl(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlfedref1nrtblock) pnlfedref1nrtblock = new PnlWznmConFedRef1NRtblock(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefSup1NControl = ((pnlsup1ncontrol) ? pnlsup1ncontrol->jref : 0);
	statshr.jrefFedRef1NRtblock = ((pnlfedref1nrtblock) ? pnlfedref1nrtblock->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmConRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCON) {
		WznmMControl* _recCon = NULL;
		WznmMFeed* _recFed = NULL;

		if (dbswznm->tblwznmmcontrol->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCON, jref), &_recCon)) {
			recCon = *_recCon;
			ixWSubsetCon = dbswznm->getIxWSubsetByWznmMControl(_recCon);
			delete _recCon;
		} else {
			recCon = WznmMControl();
			ixWSubsetCon = 0;
		};

		if (dbswznm->tblwznmmfeed->loadRecByRef(recCon.refWznmMFeed, &_recFed)) {
			recFed = *_recFed;
			delete _recFed;
		} else recFed = WznmMFeed();

		if (recCon.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsup1ncontrol) pnlsup1ncontrol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlfedref1nrtblock) pnlfedref1nrtblock->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmConRec::minimize(
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

void PnlWznmConRec::regularize(
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

void PnlWznmConRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONRECDO) {
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

void PnlWznmConRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmConRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmConRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmConRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMFEDUPD_REFEQ) {
		call->abort = handleCallWznmFedUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCONUPD_REFEQ) {
		call->abort = handleCallWznmConUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFED_SRUEQ) {
		call->abort = handleCallWznmFed_sruEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFED_SRTEQ) {
		call->abort = handleCallWznmFed_srtEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_TYPEQ) {
		call->abort = handleCallWznmCon_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_SUPEQ) {
		call->abort = handleCallWznmCon_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_STSEQ) {
		call->abort = handleCallWznmCon_stsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_SHSEQ) {
		call->abort = handleCallWznmCon_shsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_REUEQ) {
		call->abort = handleCallWznmCon_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_RETEQ) {
		call->abort = handleCallWznmCon_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_INSBS) {
		call->abort = handleCallWznmCon_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_HKUEQ) {
		call->abort = handleCallWznmCon_hkuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_HKTEQ) {
		call->abort = handleCallWznmCon_hktEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_FEDEQ) {
		call->abort = handleCallWznmCon_fedEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_CLUEQ) {
		call->abort = handleCallWznmCon_cluEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmConRec::handleCallWznmFedUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmFedUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmConRec::handleCallWznmConUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmConUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmConRec::handleCallWznmFed_sruEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFed.srcUref == refInv); // IP handleCallWznmFed_sruEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmFed_srtEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFed.srcIxVTbl == ixInv); // IP handleCallWznmFed_srtEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.ixVBasetype == ixInv); // IP handleCallWznmCon_typEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.supRefWznmMControl == refInv); // IP handleCallWznmCon_supEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_stsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.stdRefWznmMStub == refInv); // IP handleCallWznmCon_stsEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_shsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.shoRefWznmMStub == refInv); // IP handleCallWznmCon_shsEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.refUref == refInv); // IP handleCallWznmCon_reuEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.refIxVTbl == ixInv); // IP handleCallWznmCon_retEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetCon & ixInv) != 0); // IP handleCallWznmCon_inSbs --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_hkuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.hkUref == refInv); // IP handleCallWznmCon_hkuEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_hktEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.hkIxVTbl == ixInv); // IP handleCallWznmCon_hktEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_fedEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.refWznmMFeed == refInv); // IP handleCallWznmCon_fedEq --- LINE
	return retval;
};

bool PnlWznmConRec::handleCallWznmCon_cluEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.refWznmCControl == refInv); // IP handleCallWznmCon_cluEq --- LINE
	return retval;
};
