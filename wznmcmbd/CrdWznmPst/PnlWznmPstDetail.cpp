/**
	* \file PnlWznmPstDetail.cpp
	* job handler for job PnlWznmPstDetail (implementation)
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

#include "PnlWznmPstDetail.h"

#include "PnlWznmPstDetail_blks.cpp"
#include "PnlWznmPstDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmPstDetail
 ******************************************************************************/

PnlWznmPstDetail::PnlWznmPstDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMPSTDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupAty.tag = "FeedFPupAty";
	VecWznmWArgtype::fillFeed(feedFPupAty);
	feedFPupJti.tag = "FeedFPupJti";
	feedFPupRet.tag = "FeedFPupRet";
	VecWznmVMPresetRefTbl::fillFeed(ixWznmVLocale, feedFPupRet);
	feedFPupSco.tag = "FeedFPupSco";
	VecWznmVMPresetScope::fillFeed(ixWznmVLocale, feedFPupSco);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMPST_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFPST, jref);
};

PnlWznmPstDetail::~PnlWznmPstDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmPstDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupAty, &feedFPupJti, &feedFPupRet, &feedFPupSco, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmPstDetail::refreshJti(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMPresetTitle pstJtits;
	WznmJMPresetTitle* pstJtit = NULL;

	string s;

	// feedFPupJti
	feedFPupJti.clear();

	dbswznm->tblwznmjmpresettitle->loadRstByPst(recPst.ref, false, pstJtits);

	for (unsigned int i = 0; i < pstJtits.nodes.size(); i++) {
		pstJtit = pstJtits.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, pstJtit->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupJti.appendRefTitles(pstJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJTI);

	refreshRecPstJtit(dbswznm, moditems);

};

void PnlWznmPstDetail::refreshRecPst(
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

	dirty = false;

	recPstJtit.ref = recPst.refJTitle;
	if (recPst.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPst.ref);

	continf.TxtSrf = recPst.sref;
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recPst.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupRet = feedFPupRet.getNumByIx(recPst.refIxVTbl);
	contiac.numFPupSco = feedFPupSco.getNumByIx(recPst.ixVScope);
	contiac.numFPupAty = feedFPupAty.getNumByIx(recPst.ixWznmWArgtype);

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	statshr.TxtReuActive = evalTxtReuActive(dbswznm);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswznm);
	statshr.ButReuViewActive = evalButReuViewActive(dbswznm);
	statshr.PupScoActive = evalPupScoActive(dbswznm);
	statshr.PupAtyActive = evalPupAtyActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJti(dbswznm, moditems);

};

void PnlWznmPstDetail::refreshRecPstJtit(
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

	contiac.numFPupJti = feedFPupJti.getNumByRef(recPstJtit.ref);
	continf.TxtTit = recPstJtit.Title;

	statshr.PupJtiActive = evalPupJtiActive(dbswznm);
	statshr.ButJtiEditAvail = evalButJtiEditAvail(dbswznm);
	statshr.TxtTitActive = evalTxtTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmPstDetail::refresh(
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

void PnlWznmPstDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFPST) {
		recPst.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPST, jref);
		refreshRecPst(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmPstDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPSTDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPSTDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJTIEDITCLICK) {
					handleDpchAppDoButJtiEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmPstDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmPstDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSCO, ContIac::NUMFPUPATY})) {
		if (has(diffitems, ContIac::NUMFPUPSCO)) contiac.numFPupSco = _contiac->numFPupSco;
		if (has(diffitems, ContIac::NUMFPUPATY)) contiac.numFPupAty = _contiac->numFPupAty;
	};

	if (has(diffitems, ContIac::NUMFPUPJTI)) {
		recPstJtit.ref = feedFPupJti.getRefByNum(_contiac->numFPupJti);
		refreshRecPstJtit(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmPstDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmPstDetail::handleDpchAppDoButJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJtiEditClick --- INSERT
};

void PnlWznmPstDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recPst.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmPstDetail::handleDpchAppDoButReuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref)) if (recPst.refIxVTbl == VecWznmVMPresetRefTbl::VEC) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmVec";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recPst.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref)) if (recPst.refIxVTbl == VecWznmVMPresetRefTbl::SBS) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmSbs";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recPst.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmPstDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ) {
		call->abort = handleCallWznmPstJtitMod_pstEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPSTUPD_REFEQ) {
		call->abort = handleCallWznmPstUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_RETEQ) {
		call->abort = handleCallWznmPst_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_REUEQ) {
		call->abort = handleCallWznmPst_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_VEREQ) {
		call->abort = handleCallWznmPst_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmPstDetail::handleCallWznmPstJtitMod_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmPstDetail::handleCallWznmPstUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPstUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmPstDetail::handleCallWznmPst_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refIxVTbl == ixInv); // IP handleCallWznmPst_retEq --- LINE
	return retval;
};

bool PnlWznmPstDetail::handleCallWznmPst_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refUref == refInv); // IP handleCallWznmPst_reuEq --- LINE
	return retval;
};

bool PnlWznmPstDetail::handleCallWznmPst_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refWznmMVersion == refInv); // IP handleCallWznmPst_verEq --- LINE
	return retval;
};
