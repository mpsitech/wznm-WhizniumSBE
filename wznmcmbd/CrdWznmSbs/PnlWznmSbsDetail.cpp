/**
	* \file PnlWznmSbsDetail.cpp
	* job handler for job PnlWznmSbsDetail (implementation)
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

#include "PnlWznmSbsDetail.h"

#include "PnlWznmSbsDetail_blks.cpp"
#include "PnlWznmSbsDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmSbsDetail
 ******************************************************************************/

PnlWznmSbsDetail::PnlWznmSbsDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMSBSDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupPstAty.tag = "FeedFPupPstAty";
	VecWznmWArgtype::fillFeed(feedFPupPstAty);
	feedFPupPstJti.tag = "FeedFPupPstJti";
	feedFPupPstSco.tag = "FeedFPupPstSco";
	VecWznmVMPresetScope::fillFeed(ixWznmVLocale, feedFPupPstSco);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMSBS_PSTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSBS_CAREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFSBS, jref);
};

PnlWznmSbsDetail::~PnlWznmSbsDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmSbsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupPstAty, &feedFPupPstJti, &feedFPupPstSco, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmSbsDetail::refreshPstJti(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMPresetTitle pstJtits;
	WznmJMPresetTitle* pstJtit = NULL;

	string s;

	// feedFPupPstJti
	feedFPupPstJti.clear();

	dbswznm->tblwznmjmpresettitle->loadRstByPst(recPst.ref, false, pstJtits);

	for (unsigned int i = 0; i < pstJtits.nodes.size(); i++) {
		pstJtit = pstJtits.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, pstJtit->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupPstJti.appendRefTitles(pstJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPPSTJTI);

	refreshRecPstJtit(dbswznm, moditems);

};

void PnlWznmSbsDetail::refreshRecSbs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMSubset* _recSbs = NULL;

	if (dbswznm->tblwznmmsubset->loadRecByRef(recSbs.ref, &_recSbs)) {
		recSbs = *_recSbs;
		delete _recSbs;
	} else recSbs = WznmMSubset();

	dirty = false;

	recPst.ref = recSbs.refWznmMPreset;

	continf.TxtSrf = recSbs.sref;
	contiac.TxfSho = recSbs.Short;
	continf.TxtTbl = StubWznm::getStubTblStd(dbswznm, recSbs.refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtCar = StubWznm::getStubCarStd(dbswznm, recSbs.refWznmMCard, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCnd = recSbs.Cond;
	contiac.TxfCmt = recSbs.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxfShoActive = evalTxfShoActive(dbswznm);
	statshr.TxtTblActive = evalTxtTblActive(dbswznm);
	statshr.TxtCarActive = evalTxtCarActive(dbswznm);
	statshr.ButCarViewAvail = evalButCarViewAvail(dbswznm);
	statshr.ButCarViewActive = evalButCarViewActive(dbswznm);
	statshr.TxfCndActive = evalTxfCndActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecPst(dbswznm, moditems);

};

void PnlWznmSbsDetail::refreshRecPst(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMPreset* _recPst = NULL;

	if (dbswznm->tblwznmmpreset->loadRecByRef(recPst.ref, &_recPst)) {
		recPst = *_recPst;
		delete _recPst;
	} else recPst = WznmMPreset();

	recPstJtit.ref = recPst.refJTitle;
	if (recPst.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPst.ref);

	continf.TxtPstSrf = recPst.sref;
	continf.TxtPstVer = StubWznm::getStubVerStd(dbswznm, recPst.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupPstSco = feedFPupPstSco.getNumByIx(recPst.ixVScope);
	contiac.numFPupPstAty = feedFPupPstAty.getNumByIx(recPst.ixWznmWArgtype);

	statshr.ButPstNewAvail = evalButPstNewAvail(dbswznm);
	statshr.ButPstDeleteAvail = evalButPstDeleteAvail(dbswznm);
	statshr.TxtPstSrfAvail = evalTxtPstSrfAvail(dbswznm);
	statshr.TxtPstSrfActive = evalTxtPstSrfActive(dbswznm);
	statshr.TxtPstVerAvail = evalTxtPstVerAvail(dbswznm);
	statshr.TxtPstVerActive = evalTxtPstVerActive(dbswznm);
	statshr.ButPstVerViewAvail = evalButPstVerViewAvail(dbswznm);
	statshr.ButPstVerViewActive = evalButPstVerViewActive(dbswznm);
	statshr.PupPstScoAvail = evalPupPstScoAvail(dbswznm);
	statshr.PupPstScoActive = evalPupPstScoActive(dbswznm);
	statshr.PupPstAtyAvail = evalPupPstAtyAvail(dbswznm);
	statshr.PupPstAtyActive = evalPupPstAtyActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPstJti(dbswznm, moditems);

};

void PnlWznmSbsDetail::refreshRecPstJtit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMPresetTitle* _recPstJtit = NULL;

	if (dbswznm->tblwznmjmpresettitle->loadRecByRef(recPstJtit.ref, &_recPstJtit)) {
		recPstJtit = *_recPstJtit;
		delete _recPstJtit;
	} else recPstJtit = WznmJMPresetTitle();

	contiac.numFPupPstJti = feedFPupPstJti.getNumByRef(recPstJtit.ref);
	continf.TxtPstTit = recPstJtit.Title;

	statshr.PupPstJtiAvail = evalPupPstJtiAvail(dbswznm);
	statshr.PupPstJtiActive = evalPupPstJtiActive(dbswznm);
	statshr.ButPstJtiEditAvail = evalButPstJtiEditAvail(dbswznm);
	statshr.TxtPstTitAvail = evalTxtPstTitAvail(dbswznm);
	statshr.TxtPstTitActive = evalTxtPstTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmSbsDetail::refresh(
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

void PnlWznmSbsDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSBS) {
		recSbs.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSBS, jref);
		refreshRecSbs(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmSbsDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCARVIEWCLICK) {
					handleDpchAppDoButCarViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTNEWCLICK) {
					handleDpchAppDoButPstNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTDELETECLICK) {
					handleDpchAppDoButPstDeleteClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTJTIEDITCLICK) {
					handleDpchAppDoButPstJtiEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTVERVIEWCLICK) {
					handleDpchAppDoButPstVerViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmSbsDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmSbsDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSHO, ContIac::TXFCND, ContIac::TXFCMT, ContIac::NUMFPUPPSTSCO, ContIac::NUMFPUPPSTATY})) {
		if (has(diffitems, ContIac::TXFSHO)) contiac.TxfSho = _contiac->TxfSho;
		if (has(diffitems, ContIac::TXFCND)) contiac.TxfCnd = _contiac->TxfCnd;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
		if (has(diffitems, ContIac::NUMFPUPPSTSCO)) contiac.numFPupPstSco = _contiac->numFPupPstSco;
		if (has(diffitems, ContIac::NUMFPUPPSTATY)) contiac.numFPupPstAty = _contiac->numFPupPstAty;
	};

	if (has(diffitems, ContIac::NUMFPUPPSTJTI)) {
		recPstJtit.ref = feedFPupPstJti.getRefByNum(_contiac->numFPupPstJti);
		refreshRecPstJtit(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmSbsDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmSbsDetail::handleDpchAppDoButCarViewClick(
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
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSbs.refWznmMCard, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSbsDetail::handleDpchAppDoButPstNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstNewClick --- INSERT
};

void PnlWznmSbsDetail::handleDpchAppDoButPstDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstDeleteClick --- INSERT
};

void PnlWznmSbsDetail::handleDpchAppDoButPstJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstJtiEditClick --- INSERT
};

void PnlWznmSbsDetail::handleDpchAppDoButPstVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPstVerViewAvail && statshr.ButPstVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recPst.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSbsDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ) {
		call->abort = handleCallWznmPstJtitMod_pstEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSBSUPD_REFEQ) {
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

bool PnlWznmSbsDetail::handleCallWznmPstJtitMod_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshPstJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmSbsDetail::handleCallWznmSbsUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSbsUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmSbsDetail::handleCallWznmPstUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPstUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmSbsDetail::handleCallWznmSbs_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSbs.refWznmMPreset == refInv); // IP handleCallWznmSbs_pstEq --- LINE
	return retval;
};

bool PnlWznmSbsDetail::handleCallWznmSbs_carEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSbs.refWznmMCard == refInv); // IP handleCallWznmSbs_carEq --- LINE
	return retval;
};

bool PnlWznmSbsDetail::handleCallWznmPst_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refWznmMVersion == refInv); // IP handleCallWznmPst_verEq --- LINE
	return retval;
};

bool PnlWznmSbsDetail::handleCallWznmPst_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refUref == refInv); // IP handleCallWznmPst_reuEq --- LINE
	return retval;
};

bool PnlWznmSbsDetail::handleCallWznmPst_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refIxVTbl == ixInv); // IP handleCallWznmPst_retEq --- LINE
	return retval;
};



