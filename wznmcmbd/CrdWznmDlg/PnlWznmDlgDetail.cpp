/**
	* \file PnlWznmDlgDetail.cpp
	* job handler for job PnlWznmDlgDetail (implementation)
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

#include "PnlWznmDlgDetail.h"

#include "PnlWznmDlgDetail_blks.cpp"
#include "PnlWznmDlgDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmDlgDetail
 ******************************************************************************/

PnlWznmDlgDetail::PnlWznmDlgDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMDLGDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupRet.tag = "FeedFPupRet";
	VecWznmVMDialogRefTbl::fillFeed(ixWznmVLocale, feedFPupRet);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMDialogBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMDLG_CAREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMDLG_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMDLG_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMDLG_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFDLG, jref);
};

PnlWznmDlgDetail::~PnlWznmDlgDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmDlgDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupRet, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmDlgDetail::refreshRecDlg(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMDialog* _recDlg = NULL;

	if (dbswznm->tblwznmmdialog->loadRecByRef(recDlg.ref, &_recDlg)) {
		recDlg = *_recDlg;
		delete _recDlg;
	} else recDlg = WznmMDialog();

	dirty = false;

	continf.TxtSrf = recDlg.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recDlg.ixVBasetype);
	continf.TxtCar = StubWznm::getStubCarStd(dbswznm, recDlg.refWznmMCard, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupRet = feedFPupRet.getNumByIx(recDlg.refIxVTbl);
	if (recDlg.refIxVTbl == VecWznmVMDialogRefTbl::TBL) continf.TxtReu = StubWznm::getStubTblStd(dbswznm, recDlg.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recDlg.refIxVTbl == VecWznmVMDialogRefTbl::REL) continf.TxtReu = StubWznm::getStubRelStd(dbswznm, recDlg.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recDlg.refIxVTbl == VecWznmVMDialogRefTbl::IEX) continf.TxtReu = StubWznm::getStubIexStd(dbswznm, recDlg.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	continf.TxtJob = StubWznm::getStubJobStd(dbswznm, recDlg.refWznmMJob, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recDlg.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtCarActive = evalTxtCarActive(dbswznm);
	statshr.ButCarViewAvail = evalButCarViewAvail(dbswznm);
	statshr.ButCarViewActive = evalButCarViewActive(dbswznm);
	statshr.TxtReuActive = evalTxtReuActive(dbswznm);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswznm);
	statshr.ButReuViewActive = evalButReuViewActive(dbswznm);
	statshr.TxtJobActive = evalTxtJobActive(dbswznm);
	statshr.ButJobViewAvail = evalButJobViewAvail(dbswznm);
	statshr.ButJobViewActive = evalButJobViewActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmDlgDetail::refresh(
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

void PnlWznmDlgDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFDLG) {
		recDlg.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFDLG, jref);
		refreshRecDlg(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmDlgDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCARVIEWCLICK) {
					handleDpchAppDoButCarViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJOBVIEWCLICK) {
					handleDpchAppDoButJobViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmDlgDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmDlgDetail::handleDpchAppDataContiac(
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

void PnlWznmDlgDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmDlgDetail::handleDpchAppDoButCarViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButCarViewAvail && statshr.ButCarViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmCar";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recDlg.refWznmMCard, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmDlgDetail::handleDpchAppDoButReuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref)) if (recDlg.refIxVTbl == VecWznmVMDialogRefTbl::IEX) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmIex";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recDlg.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref)) if (recDlg.refIxVTbl == VecWznmVMDialogRefTbl::REL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmRel";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recDlg.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmDlgDetail::handleDpchAppDoButJobViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButJobViewAvail && statshr.ButJobViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmJob";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recDlg.refWznmMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmDlgDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMDLGUPD_REFEQ) {
		call->abort = handleCallWznmDlgUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMDLG_CAREQ) {
		call->abort = handleCallWznmDlg_carEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMDLG_REUEQ) {
		call->abort = handleCallWznmDlg_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMDLG_RETEQ) {
		call->abort = handleCallWznmDlg_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMDLG_JOBEQ) {
		call->abort = handleCallWznmDlg_jobEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmDlgDetail::handleCallWznmDlgUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmDlgUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmDlgDetail::handleCallWznmDlg_carEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recDlg.refWznmMCard == refInv); // IP handleCallWznmDlg_carEq --- LINE
	return retval;
};

bool PnlWznmDlgDetail::handleCallWznmDlg_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recDlg.refUref == refInv); // IP handleCallWznmDlg_reuEq --- LINE
	return retval;
};

bool PnlWznmDlgDetail::handleCallWznmDlg_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recDlg.refIxVTbl == ixInv); // IP handleCallWznmDlg_retEq --- LINE
	return retval;
};

bool PnlWznmDlgDetail::handleCallWznmDlg_jobEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recDlg.refWznmMJob == refInv); // IP handleCallWznmDlg_jobEq --- LINE
	return retval;
};
