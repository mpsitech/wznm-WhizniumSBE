/**
	* \file PnlWznmMchDetail.cpp
	* job handler for job PnlWznmMchDetail (implementation)
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

#include "PnlWznmMchDetail.h"

#include "PnlWznmMchDetail_blks.cpp"
#include "PnlWznmMchDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmMchDetail
 ******************************************************************************/

PnlWznmMchDetail::PnlWznmMchDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMMCHDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupPkm.tag = "FeedFPupPkm";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMMACHINEPKGMGR, ixWznmVLocale, feedFPupPkm);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMMCH_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMMCH_CCHEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMMACHINEPKGMGR);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFMCH, jref);
};

PnlWznmMchDetail::~PnlWznmMchDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmMchDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupPkm, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmMchDetail::refreshPupPkm(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupPkm = 0;

	for (unsigned int i = 0; i < feedFPupPkm.size(); i++) {
		if (feedFPupPkm.getSrefByNum(i+1) == contiac.TxfPkm) {
			contiac.numFPupPkm = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfPkmValid = (contiac.numFPupPkm != 0);
	statshr.PupPkmActive = evalPupPkmActive(dbswznm);
	statshr.ButPkmEditAvail = evalButPkmEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmMchDetail::refreshTxfPkm(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfPkm = feedFPupPkm.getSrefByNum(contiac.numFPupPkm);

	// statshr
	statshr.TxfPkmValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmMchDetail::refreshPkm(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFPupPkm
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMMACHINEPKGMGR, ixWznmVLocale, feedFPupPkm);

	insert(moditems, DpchEngData::FEEDFPUPPKM);

	refreshPupPkm(dbswznm, moditems);
};

void PnlWznmMchDetail::refreshRecMch(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMMachine* _recMch = NULL;

	if (dbswznm->tblwznmmmachine->loadRecByRef(recMch.ref, &_recMch)) {
		recMch = *_recMch;
		delete _recMch;
	} else recMch = WznmMMachine();

	dirty = false;

	continf.TxtSrf = recMch.sref;
	continf.TxtSup = StubWznm::getStubMchStd(dbswznm, recMch.supRefWznmMMachine, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtCch = StubWznm::getStubMchStd(dbswznm, recMch.cchRefWznmMMachine, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfPkm = recMch.srefKPkgmgr;
	contiac.TxfCmt = recMch.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtSupActive = evalTxtSupActive(dbswznm);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbswznm);
	statshr.ButSupViewActive = evalButSupViewActive(dbswznm);
	statshr.TxtCchActive = evalTxtCchActive(dbswznm);
	statshr.ButCchViewAvail = evalButCchViewAvail(dbswznm);
	statshr.ButCchViewActive = evalButCchViewActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupPkm(dbswznm, moditems);

};

void PnlWznmMchDetail::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswznm);
	statshr.ButSaveActive = evalButSaveActive(dbswznm);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmMchDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMCH) {
		recMch.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMCH, jref);
		refreshRecMch(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmMchDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCCHVIEWCLICK) {
					handleDpchAppDoButCchViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPKMEDITCLICK) {
					handleDpchAppDoButPkmEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmMchDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmMchDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFPKM)) {
		contiac.TxfPkm = _contiac->TxfPkm;
		refreshPupPkm(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPPKM)) {
		contiac.numFPupPkm = _contiac->numFPupPkm;
		refreshTxfPkm(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmMchDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmMchDetail::handleDpchAppDoButSupViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref)) {
			sref = "CrdWznmMch";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recMch.supRefWznmMMachine, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmMchDetail::handleDpchAppDoButCchViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButCchViewAvail && statshr.ButCchViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref)) {
			sref = "CrdWznmMch";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recMch.cchRefWznmMMachine, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmMchDetail::handleDpchAppDoButPkmEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPkmEditClick --- INSERT
};

void PnlWznmMchDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMMCH_SUPEQ) {
		call->abort = handleCallWznmMch_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMCH_CCHEQ) {
		call->abort = handleCallWznmMch_cchEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMCHUPD_REFEQ) {
		call->abort = handleCallWznmMchUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	};
};

bool PnlWznmMchDetail::handleCallWznmMch_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMch.supRefWznmMMachine == refInv); // IP handleCallWznmMch_supEq --- LINE
	return retval;
};

bool PnlWznmMchDetail::handleCallWznmMch_cchEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMch.cchRefWznmMMachine == refInv); // IP handleCallWznmMch_cchEq --- LINE
	return retval;
};

bool PnlWznmMchDetail::handleCallWznmMchUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmMchUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmMchDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKMMACHINEPKGMGR) {
		refreshPkm(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
