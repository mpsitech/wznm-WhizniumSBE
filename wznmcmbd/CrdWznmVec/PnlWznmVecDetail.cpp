/**
	* \file PnlWznmVecDetail.cpp
	* job handler for job PnlWznmVecDetail (implementation)
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

#include "PnlWznmVecDetail.h"

#include "PnlWznmVecDetail_blks.cpp"
#include "PnlWznmVecDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmVecDetail
 ******************************************************************************/

PnlWznmVecDetail::PnlWznmVecDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMVECDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstOpt.tag = "FeedFLstOpt";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMVECTOROPTION, ixWznmVLocale, feedFLstOpt);
	feedFPupHkt.tag = "FeedFPupHkt";
	VecWznmVMVectorHkTbl::fillFeed(ixWznmVLocale, feedFPupHkt);
	feedFPupPstAty.tag = "FeedFPupPstAty";
	VecWznmWArgtype::fillFeed(feedFPupPstAty);
	feedFPupPstJti.tag = "FeedFPupPstJti";
	feedFPupPstSco.tag = "FeedFPupPstSco";
	VecWznmVMPresetScope::fillFeed(ixWznmVLocale, feedFPupPstSco);
	feedFPupTgr.tag = "FeedFPupTgr";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKTAGGRP, ixWznmVLocale, feedFPupTgr);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMVectorBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMPST_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_PSTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKTAGGRP);
	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMVECTOROPTION);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVEC, jref);
};

PnlWznmVecDetail::~PnlWznmVecDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmVecDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstOpt, &feedFPupHkt, &feedFPupPstAty, &feedFPupPstJti, &feedFPupPstSco, &feedFPupTgr, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmVecDetail::refreshPupTgr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupTgr = 0;

	for (unsigned int i = 0; i < feedFPupTgr.size(); i++) {
		if (feedFPupTgr.getSrefByNum(i+1) == contiac.TxfTgr) {
			contiac.numFPupTgr = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfTgrValid = (contiac.numFPupTgr != 0);
	statshr.PupTgrActive = evalPupTgrActive(dbswznm);
	statshr.ButTgrEditAvail = evalButTgrEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmVecDetail::refreshTxfTgr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfTgr = feedFPupTgr.getSrefByNum(contiac.numFPupTgr);

	// statshr
	statshr.TxfTgrValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmVecDetail::refreshTgr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFPupTgr
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKTAGGRP, ixWznmVLocale, feedFPupTgr);

	insert(moditems, DpchEngData::FEEDFPUPTGR);

	refreshPupTgr(dbswznm, moditems);
};

void PnlWznmVecDetail::refreshLstOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	set<uint> nums;

	vector<string> ss;
	string s;

	// contiac
	contiac.numsFLstOpt.clear();

	StrMod::srefsToVector(contiac.TxfOpt, ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		s = ss[i];

		for (unsigned int j = 0; j < feedFLstOpt.size(); j++) {
			if (feedFLstOpt.getSrefByNum(j+1) == s) {
				nums.insert(j+1);
				break;
			};
		};
	};

	for (auto it = nums.begin(); it != nums.end(); it++) contiac.numsFLstOpt.push_back(*it);

	// statshr
	statshr.TxfOptValid = ( (ss.size() == nums.size()) && (nums.size() == contiac.numsFLstOpt.size()) );
	statshr.LstOptActive = evalLstOptActive(dbswznm);
	statshr.ButOptEditAvail = evalButOptEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmVecDetail::refreshTxfOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfOpt = "";

	for (unsigned int i = 0; i < contiac.numsFLstOpt.size(); i++) {
		if (i != 0) contiac.TxfOpt += ";";
		contiac.TxfOpt += feedFLstOpt.getSrefByNum(contiac.numsFLstOpt[i]);
	};

	// statshr
	statshr.TxfOptValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmVecDetail::refreshOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFLstOpt
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMVECTOROPTION, ixWznmVLocale, feedFLstOpt);

	insert(moditems, DpchEngData::FEEDFLSTOPT);

	refreshLstOpt(dbswznm, moditems);
};

void PnlWznmVecDetail::refreshPstJti(
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

void PnlWznmVecDetail::refreshRecVec(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMVector* _recVec = NULL;

	if (dbswznm->tblwznmmvector->loadRecByRef(recVec.ref, &_recVec)) {
		recVec = *_recVec;
		ixWSubsetVec = dbswznm->getIxWSubsetByWznmMVector(_recVec);
		delete _recVec;
	} else {
		recVec = WznmMVector();
		ixWSubsetVec = 0;
	};

	dirty = false;

	recPst.ref = recVec.refWznmMPreset;

	continf.TxtSrf = recVec.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recVec.ixVBasetype);
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recVec.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupHkt = feedFPupHkt.getNumByIx(recVec.hkIxVTbl);
	if (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::IEX) continf.TxtHku = StubWznm::getStubIexStd(dbswznm, recVec.hkUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::IME) continf.TxtHku = StubWznm::getStubImeStd(dbswznm, recVec.hkUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::JOB) continf.TxtHku = StubWznm::getStubJobStd(dbswznm, recVec.hkUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::TBL) continf.TxtHku = StubWznm::getStubTblStd(dbswznm, recVec.hkUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtHku = "-";
	contiac.TxfTgr = recVec.osrefWznmKTaggrp;
	contiac.TxfOpt = recVec.srefsKOption;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	statshr.TxtHkuActive = evalTxtHkuActive(dbswznm);
	statshr.ButHkuViewAvail = evalButHkuViewAvail(dbswznm);
	statshr.ButHkuViewActive = evalButHkuViewActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecPst(dbswznm, moditems);

	refreshPupTgr(dbswznm, moditems);
	refreshLstOpt(dbswznm, moditems);

};

void PnlWznmVecDetail::refreshRecPst(
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

void PnlWznmVecDetail::refreshRecPstJtit(
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

void PnlWznmVecDetail::refresh(
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

void PnlWznmVecDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFVEC) {
		recVec.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVEC, jref);
		refreshRecVec(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmVecDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHKUVIEWCLICK) {
					handleDpchAppDoButHkuViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTGREDITCLICK) {
					handleDpchAppDoButTgrEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPTEDITCLICK) {
					handleDpchAppDoButOptEditClick(dbswznm, &(req->dpcheng));
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

void PnlWznmVecDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmVecDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::NUMFPUPPSTSCO, ContIac::NUMFPUPPSTATY})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::NUMFPUPPSTSCO)) contiac.numFPupPstSco = _contiac->numFPupPstSco;
		if (has(diffitems, ContIac::NUMFPUPPSTATY)) contiac.numFPupPstAty = _contiac->numFPupPstAty;
	};

	if (has(diffitems, ContIac::TXFTGR)) {
		contiac.TxfTgr = _contiac->TxfTgr;
		refreshPupTgr(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPTGR)) {
		contiac.numFPupTgr = _contiac->numFPupTgr;
		refreshTxfTgr(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFOPT)) {
		contiac.TxfOpt = _contiac->TxfOpt;
		refreshLstOpt(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMSFLSTOPT)) {
		contiac.numsFLstOpt = _contiac->numsFLstOpt;
		refreshTxfOpt(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFPUPPSTJTI)) {
		recPstJtit.ref = feedFPupPstJti.getRefByNum(_contiac->numFPupPstJti);
		refreshRecPstJtit(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmVecDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmVecDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recVec.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmVecDetail::handleDpchAppDoButHkuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButHkuViewAvail && statshr.ButHkuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref)) if (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::JOB) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmJob";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recVec.hkUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref)) if (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::TBL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmTbl";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recVec.hkUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref)) if (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::IEX) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmIex";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recVec.hkUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref)) if (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::IME) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmIme";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recVec.hkUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmVecDetail::handleDpchAppDoButTgrEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButTgrEditClick --- INSERT
};

void PnlWznmVecDetail::handleDpchAppDoButOptEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButOptEditClick --- INSERT
};

void PnlWznmVecDetail::handleDpchAppDoButPstNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstNewClick --- INSERT
};

void PnlWznmVecDetail::handleDpchAppDoButPstDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstDeleteClick --- INSERT
};

void PnlWznmVecDetail::handleDpchAppDoButPstJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstJtiEditClick --- INSERT
};

void PnlWznmVecDetail::handleDpchAppDoButPstVerViewClick(
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

void PnlWznmVecDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPST_RETEQ) {
		call->abort = handleCallWznmPst_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_REUEQ) {
		call->abort = handleCallWznmPst_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_VEREQ) {
		call->abort = handleCallWznmPst_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_HKTEQ) {
		call->abort = handleCallWznmVec_hktEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_HKUEQ) {
		call->abort = handleCallWznmVec_hkuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_INSBS) {
		call->abort = handleCallWznmVec_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_PSTEQ) {
		call->abort = handleCallWznmVec_pstEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_TYPEQ) {
		call->abort = handleCallWznmVec_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_VEREQ) {
		call->abort = handleCallWznmVec_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPSTUPD_REFEQ) {
		call->abort = handleCallWznmPstUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVECUPD_REFEQ) {
		call->abort = handleCallWznmVecUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ) {
		call->abort = handleCallWznmPstJtitMod_pstEq(dbswznm, call->jref);
	};
};

bool PnlWznmVecDetail::handleCallWznmPst_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refIxVTbl == ixInv); // IP handleCallWznmPst_retEq --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmPst_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refUref == refInv); // IP handleCallWznmPst_reuEq --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmPst_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refWznmMVersion == refInv); // IP handleCallWznmPst_verEq --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmVec_hktEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.hkIxVTbl == ixInv); // IP handleCallWznmVec_hktEq --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmVec_hkuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.hkUref == refInv); // IP handleCallWznmVec_hkuEq --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmVec_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetVec & ixInv) != 0); // IP handleCallWznmVec_inSbs --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmVec_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.refWznmMPreset == refInv); // IP handleCallWznmVec_pstEq --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmVec_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.ixVBasetype == ixInv); // IP handleCallWznmVec_typEq --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmVec_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.refWznmMVersion == refInv); // IP handleCallWznmVec_verEq --- LINE
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmPstUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPstUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmVecUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmVecUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKTAGGRP) {
		refreshTgr(dbswznm, moditems);
	} else if (ixInv == VecWznmVKeylist::KLSTWZNMKMVECTOROPTION) {
		refreshOpt(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmVecDetail::handleCallWznmPstJtitMod_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshPstJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
