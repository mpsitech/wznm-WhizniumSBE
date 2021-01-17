/**
	* \file PnlWznmChkDetail.cpp
	* job handler for job PnlWznmChkDetail (implementation)
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

#include "PnlWznmChkDetail.h"

#include "PnlWznmChkDetail_blks.cpp"
#include "PnlWznmChkDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmChkDetail
 ******************************************************************************/

PnlWznmChkDetail::PnlWznmChkDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMCHKDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMCheckBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMCHK_CALEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCHK_TCOEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFCHK, jref);
};

PnlWznmChkDetail::~PnlWznmChkDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmChkDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmChkDetail::refreshRecChk(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMCheck* _recChk = NULL;

	if (dbswznm->tblwznmmcheck->loadRecByRef(recChk.ref, &_recChk)) {
		recChk = *_recChk;
		delete _recChk;
	} else recChk = WznmMCheck();

	dirty = false;

	continf.TxtSrf = recChk.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recChk.ixVBasetype);
	continf.TxtTbl = StubWznm::getStubTblStd(dbswznm, recChk.refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTco = StubWznm::getStubTcoStd(dbswznm, recChk.refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtCal = StubWznm::getStubCalStd(dbswznm, recChk.refWznmMCall, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recChk.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtTblActive = evalTxtTblActive(dbswznm);
	statshr.TxtTcoActive = evalTxtTcoActive(dbswznm);
	statshr.ButTcoViewAvail = evalButTcoViewAvail(dbswznm);
	statshr.ButTcoViewActive = evalButTcoViewActive(dbswznm);
	statshr.TxtCalActive = evalTxtCalActive(dbswznm);
	statshr.ButCalViewAvail = evalButCalViewAvail(dbswznm);
	statshr.ButCalViewActive = evalButCalViewActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmChkDetail::refresh(
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

void PnlWznmChkDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCHK) {
		recChk.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCHK, jref);
		refreshRecChk(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmChkDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTCOVIEWCLICK) {
					handleDpchAppDoButTcoViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCALVIEWCLICK) {
					handleDpchAppDoButCalViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmChkDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmChkDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmChkDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmChkDetail::handleDpchAppDoButTcoViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButTcoViewAvail && statshr.ButTcoViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFTBL) {
			sref = "CrdWznmTco";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recChk.refWznmMTablecol, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmTco";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recChk.refWznmMTablecol, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmChkDetail::handleDpchAppDoButCalViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButCalViewAvail && statshr.ButCalViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAL, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmCal";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recChk.refWznmMCall, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmChkDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMCHK_CALEQ) {
		call->abort = handleCallWznmChk_calEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCHK_TCOEQ) {
		call->abort = handleCallWznmChk_tcoEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCHKUPD_REFEQ) {
		call->abort = handleCallWznmChkUpd_refEq(dbswznm, call->jref);
	};
};

bool PnlWznmChkDetail::handleCallWznmChk_calEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recChk.refWznmMCall == refInv); // IP handleCallWznmChk_calEq --- LINE
	return retval;
};

bool PnlWznmChkDetail::handleCallWznmChk_tcoEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recChk.refWznmMTablecol == refInv); // IP handleCallWznmChk_tcoEq --- LINE
	return retval;
};

bool PnlWznmChkDetail::handleCallWznmChkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmChkUpd_refEq --- INSERT
	return retval;
};
