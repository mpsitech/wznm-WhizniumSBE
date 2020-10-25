/**
	* \file PnlWznmCalDetail.cpp
	* job handler for job PnlWznmCalDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmCalDetail.h"

#include "PnlWznmCalDetail_blks.cpp"
#include "PnlWznmCalDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmCalDetail
 ******************************************************************************/

PnlWznmCalDetail::PnlWznmCalDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMCALDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstIat.tag = "FeedFLstIat";
	VecWznmWArgtype::fillFeed(feedFLstIat);
	feedFLstRat.tag = "FeedFLstRat";
	VecWznmWArgtype::fillFeed(feedFLstRat);
	feedFPupRet.tag = "FeedFPupRet";
	VecWznmVMCallRefTbl::fillFeed(ixWznmVLocale, feedFPupRet);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMCallBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMCAL_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCAL_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCAL_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCAL_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFCAL, jref);
};

PnlWznmCalDetail::~PnlWznmCalDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmCalDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstIat, &feedFLstRat, &feedFPupRet, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmCalDetail::refreshTxtIat(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstIat.size(); i++) ix |= feedFLstIat.getIxByNum(contiac.numsFLstIat[i]);
	continf.TxtIat = VecWznmWArgtype::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmCalDetail::refreshTxtRat(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstRat.size(); i++) ix |= feedFLstRat.getIxByNum(contiac.numsFLstRat[i]);
	continf.TxtRat = VecWznmWArgtype::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmCalDetail::refreshRecCal(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmMCall* _recCal = NULL;

	if (dbswznm->tblwznmmcall->loadRecByRef(recCal.ref, &_recCal)) {
		recCal = *_recCal;
		ixWSubsetCal = dbswznm->getIxWSubsetByWznmMCall(_recCal);
		delete _recCal;
	} else {
		recCal = WznmMCall();
		ixWSubsetCal = 0;
	};

	dirty = false;

	continf.TxtSrf = recCal.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recCal.ixVBasetype);
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recCal.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupRet = feedFPupRet.getNumByIx(recCal.refIxVTbl);
	if (recCal.refIxVTbl == VecWznmVMCallRefTbl::CHK) continf.TxtReu = StubWznm::getStubChkStd(dbswznm, recCal.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recCal.refIxVTbl == VecWznmVMCallRefTbl::TBL) continf.TxtReu = StubWznm::getStubTblStd(dbswznm, recCal.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	contiac.numsFLstIat.clear();
	VecWznmWArgtype::getIcs(recCal.invIxWznmWArgtype, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstIat.push_back(feedFLstIat.getNumByIx(*it));
	contiac.numsFLstRat.clear();
	VecWznmWArgtype::getIcs(recCal.retIxWznmWArgtype, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstRat.push_back(feedFLstRat.getNumByIx(*it));
	contiac.TxfCmt = recCal.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	statshr.TxtReuActive = evalTxtReuActive(dbswznm);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswznm);
	statshr.ButReuViewActive = evalButReuViewActive(dbswznm);
	statshr.LstIatActive = evalLstIatActive(dbswznm);
	statshr.LstRatActive = evalLstRatActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtIat(dbswznm, moditems);
	refreshTxtRat(dbswznm, moditems);

};

void PnlWznmCalDetail::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswznm);
	statshr.ButSaveActive = evalButSaveActive(dbswznm);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmCalDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCAL) {
		recCal.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAL, jref);
		refreshRecCal(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmCalDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmCalDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmCalDetail::handleDpchAppDataContiac(
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

	if (has(diffitems, ContIac::NUMSFLSTIAT)) {
		contiac.numsFLstIat = _contiac->numsFLstIat;
		refreshTxtIat(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTRAT)) {
		contiac.numsFLstRat = _contiac->numsFLstRat;
		refreshTxtRat(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmCalDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmCalDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recCal.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmCalDetail::handleDpchAppDoButReuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCHK, jref)) if (recCal.refIxVTbl == VecWznmVMCallRefTbl::CHK) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmChk";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCal.refUref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmCalDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMCALUPD_REFEQ) {
		call->abort = handleCallWznmCalUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCAL_VEREQ) {
		call->abort = handleCallWznmCal_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCAL_TYPEQ) {
		call->abort = handleCallWznmCal_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCAL_REUEQ) {
		call->abort = handleCallWznmCal_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCAL_RETEQ) {
		call->abort = handleCallWznmCal_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWznmCalDetail::handleCallWznmCalUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmCalUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmCalDetail::handleCallWznmCal_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCal.refWznmMVersion == refInv); // IP handleCallWznmCal_verEq --- LINE
	return retval;
};

bool PnlWznmCalDetail::handleCallWznmCal_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCal.ixVBasetype == ixInv); // IP handleCallWznmCal_typEq --- LINE
	return retval;
};

bool PnlWznmCalDetail::handleCallWznmCal_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCal.refUref == refInv); // IP handleCallWznmCal_reuEq --- LINE
	return retval;
};

bool PnlWznmCalDetail::handleCallWznmCal_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCal.refIxVTbl == ixInv); // IP handleCallWznmCal_retEq --- LINE
	return retval;
};

