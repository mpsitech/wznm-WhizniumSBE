/**
	* \file PnlWznmStbDetail.cpp
	* job handler for job PnlWznmStbDetail (implementation)
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

#include "PnlWznmStbDetail.h"

#include "PnlWznmStbDetail_blks.cpp"
#include "PnlWznmStbDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmStbDetail
 ******************************************************************************/

PnlWznmStbDetail::PnlWznmStbDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMSTBDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMStubBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMSTB_TCOEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTB_SBSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFSTB, jref);
};

PnlWznmStbDetail::~PnlWznmStbDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmStbDetail::getNewDpchEng(
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

void PnlWznmStbDetail::refreshRecStb(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMStub* _recStb = NULL;

	if (dbswznm->tblwznmmstub->loadRecByRef(recStb.ref, &_recStb)) {
		recStb = *_recStb;
		delete _recStb;
	} else recStb = WznmMStub();

	dirty = false;

	continf.TxtSrf = recStb.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recStb.ixVBasetype);
	continf.TxtTbl = StubWznm::getStubTblStd(dbswznm, recStb.refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSbs = StubWznm::getStubSbsStd(dbswznm, recStb.refWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.ChkHrc = recStb.Hierarch;
	continf.TxtTco = StubWznm::getStubTcoStd(dbswznm, recStb.refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.ChkLcl = recStb.Localized;
	contiac.TxfExa = recStb.Example;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtTblActive = evalTxtTblActive(dbswznm);
	statshr.TxtSbsActive = evalTxtSbsActive(dbswznm);
	statshr.ButSbsViewAvail = evalButSbsViewAvail(dbswznm);
	statshr.ButSbsViewActive = evalButSbsViewActive(dbswznm);
	statshr.ChkHrcActive = evalChkHrcActive(dbswznm);
	statshr.TxtTcoActive = evalTxtTcoActive(dbswznm);
	statshr.ButTcoViewAvail = evalButTcoViewAvail(dbswznm);
	statshr.ButTcoViewActive = evalButTcoViewActive(dbswznm);
	statshr.ChkLclActive = evalChkLclActive(dbswznm);
	statshr.TxfExaActive = evalTxfExaActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmStbDetail::refresh(
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

void PnlWznmStbDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSTB) {
		recStb.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSTB, jref);
		refreshRecStb(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmStbDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSBSVIEWCLICK) {
					handleDpchAppDoButSbsViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTCOVIEWCLICK) {
					handleDpchAppDoButTcoViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmStbDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmStbDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::CHKHRC, ContIac::CHKLCL, ContIac::TXFEXA})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::CHKHRC)) contiac.ChkHrc = _contiac->ChkHrc;
		if (has(diffitems, ContIac::CHKLCL)) contiac.ChkLcl = _contiac->ChkLcl;
		if (has(diffitems, ContIac::TXFEXA)) contiac.TxfExa = _contiac->TxfExa;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmStbDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmStbDetail::handleDpchAppDoButSbsViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSbsViewAvail && statshr.ButSbsViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmSbs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recStb.refWznmMSubset, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmStbDetail::handleDpchAppDoButTcoViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButTcoViewAvail && statshr.ButTcoViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmTco";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recStb.refWznmMTablecol, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmStbDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTBUPD_REFEQ) {
		call->abort = handleCallWznmStbUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTB_TCOEQ) {
		call->abort = handleCallWznmStb_tcoEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTB_SBSEQ) {
		call->abort = handleCallWznmStb_sbsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmStbDetail::handleCallWznmStbUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmStbUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmStbDetail::handleCallWznmStb_tcoEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recStb.refWznmMTablecol == refInv); // IP handleCallWznmStb_tcoEq --- LINE
	return retval;
};

bool PnlWznmStbDetail::handleCallWznmStb_sbsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recStb.refWznmMSubset == refInv); // IP handleCallWznmStb_sbsEq --- LINE
	return retval;
};



