/**
	* \file PnlWznmPnlDetail.cpp
	* job handler for job PnlWznmPnlDetail (implementation)
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

#include "PnlWznmPnlDetail.h"

#include "PnlWznmPnlDetail_blks.cpp"
#include "PnlWznmPnlDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmPnlDetail
 ******************************************************************************/

PnlWznmPnlDetail::PnlWznmPnlDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMPNLDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupRet.tag = "FeedFPupRet";
	VecWznmVMPanelRefTbl::fillFeed(ixWznmVLocale, feedFPupRet);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMPanelBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMPNL_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPNL_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPNL_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPNL_CAREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFPNL, jref);
};

PnlWznmPnlDetail::~PnlWznmPnlDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmPnlDetail::getNewDpchEng(
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

void PnlWznmPnlDetail::refreshRecPnl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMPanel* _recPnl = NULL;

	if (dbswznm->tblwznmmpanel->loadRecByRef(recPnl.ref, &_recPnl)) {
		recPnl = *_recPnl;
		delete _recPnl;
	} else recPnl = WznmMPanel();

	dirty = false;

	continf.TxtSrf = recPnl.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recPnl.ixVBasetype);
	continf.TxtCar = StubWznm::getStubCarStd(dbswznm, recPnl.carRefWznmMCard, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupRet = feedFPupRet.getNumByIx(recPnl.refIxVTbl);
	if (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::MDL) continf.TxtReu = StubWznm::getStubMdlStd(dbswznm, recPnl.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::TBL) continf.TxtReu = StubWznm::getStubTblStd(dbswznm, recPnl.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::REL) continf.TxtReu = StubWznm::getStubRelStd(dbswznm, recPnl.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::VEC) continf.TxtReu = StubWznm::getStubVecStd(dbswznm, recPnl.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	continf.TxtJob = StubWznm::getStubJobStd(dbswznm, recPnl.refWznmMJob, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.ChkDet = recPnl.Detach;
	contiac.TxfAvl = recPnl.Avail;
	contiac.TxfCmt = recPnl.Comment;

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
	statshr.ChkDetActive = evalChkDetActive(dbswznm);
	statshr.TxfAvlActive = evalTxfAvlActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmPnlDetail::refresh(
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

void PnlWznmPnlDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFPNL) {
		recPnl.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPNL, jref);
		refreshRecPnl(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmPnlDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLDETAILDO) {
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

void PnlWznmPnlDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmPnlDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::CHKDET, ContIac::TXFAVL, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::CHKDET)) contiac.ChkDet = _contiac->ChkDet;
		if (has(diffitems, ContIac::TXFAVL)) contiac.TxfAvl = _contiac->TxfAvl;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmPnlDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmPnlDetail::handleDpchAppDoButCarViewClick(
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
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recPnl.carRefWznmMCard, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmPnlDetail::handleDpchAppDoButReuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref)) if (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::MDL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmMdl";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recPnl.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref)) if (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::TBL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmTbl";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recPnl.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref)) if (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::REL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmRel";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recPnl.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref)) if (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::VEC) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmVec";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recPnl.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmPnlDetail::handleDpchAppDoButJobViewClick(
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
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recPnl.refWznmMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmPnlDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPNL_REUEQ) {
		call->abort = handleCallWznmPnl_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPNL_RETEQ) {
		call->abort = handleCallWznmPnl_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPNL_JOBEQ) {
		call->abort = handleCallWznmPnl_jobEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPNL_CAREQ) {
		call->abort = handleCallWznmPnl_carEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPNLUPD_REFEQ) {
		call->abort = handleCallWznmPnlUpd_refEq(dbswznm, call->jref);
	};
};

bool PnlWznmPnlDetail::handleCallWznmPnl_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPnl.refUref == refInv); // IP handleCallWznmPnl_reuEq --- LINE
	return retval;
};

bool PnlWznmPnlDetail::handleCallWznmPnl_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPnl.refIxVTbl == ixInv); // IP handleCallWznmPnl_retEq --- LINE
	return retval;
};

bool PnlWznmPnlDetail::handleCallWznmPnl_jobEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPnl.refWznmMJob == refInv); // IP handleCallWznmPnl_jobEq --- LINE
	return retval;
};

bool PnlWznmPnlDetail::handleCallWznmPnl_carEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPnl.carRefWznmMCard == refInv); // IP handleCallWznmPnl_carEq --- LINE
	return retval;
};

bool PnlWznmPnlDetail::handleCallWznmPnlUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPnlUpd_refEq --- INSERT
	return retval;
};
