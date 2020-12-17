/**
	* \file PnlWznmOpkDetail.cpp
	* job handler for job PnlWznmOpkDetail (implementation)
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

#include "PnlWznmOpkDetail.h"

#include "PnlWznmOpkDetail_blks.cpp"
#include "PnlWznmOpkDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmOpkDetail
 ******************************************************************************/

PnlWznmOpkDetail::PnlWznmOpkDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMOPKDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupSqkJti.tag = "FeedFPupSqkJti";
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMOppackBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMOPK_SQKEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMOPK_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFOPK, jref);
};

PnlWznmOpkDetail::~PnlWznmOpkDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmOpkDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupSqkJti, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmOpkDetail::refreshSqkJti(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMSquawkTitle sqkJtits;
	WznmJMSquawkTitle* sqkJtit = NULL;

	string s;

	// feedFPupSqkJti
	feedFPupSqkJti.clear();

	dbswznm->tblwznmjmsquawktitle->loadRstBySqk(recSqk.ref, false, sqkJtits);

	for (unsigned int i = 0; i < sqkJtits.nodes.size(); i++) {
		sqkJtit = sqkJtits.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, sqkJtit->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupSqkJti.appendRefTitles(sqkJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPSQKJTI);

	refreshRecSqkJtit(dbswznm, moditems);

};

void PnlWznmOpkDetail::refreshRecOpk(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMOppack* _recOpk = NULL;

	if (dbswznm->tblwznmmoppack->loadRecByRef(recOpk.ref, &_recOpk)) {
		recOpk = *_recOpk;
		delete _recOpk;
	} else recOpk = WznmMOppack();

	dirty = false;

	recSqk.ref = recOpk.refWznmMSquawk;

	continf.TxtSrf = recOpk.sref;
	contiac.TxfTit = recOpk.Title;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recOpk.ixVBasetype);
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recOpk.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.ChkShd = recOpk.Shrdat;
	contiac.TxfCmt = recOpk.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxfTitActive = evalTxfTitActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	statshr.ChkShdActive = evalChkShdActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecSqk(dbswznm, moditems);

};

void PnlWznmOpkDetail::refreshRecSqk(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMSquawk* _recSqk = NULL;

	if (dbswznm->tblwznmmsquawk->loadRecByRef(recSqk.ref, &_recSqk)) {
		recSqk = *_recSqk;
		delete _recSqk;
	} else recSqk = WznmMSquawk();

	recSqkJtit.ref = recSqk.refJTitle;
	if (recSqk.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMSQKJTITMOD_SQKEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMSQKJTITMOD_SQKEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recSqk.ref);

	contiac.TxfSqkExa = recSqk.Example;

	statshr.ButSqkNewAvail = evalButSqkNewAvail(dbswznm);
	statshr.ButSqkDeleteAvail = evalButSqkDeleteAvail(dbswznm);
	statshr.TxfSqkExaAvail = evalTxfSqkExaAvail(dbswznm);
	statshr.TxfSqkExaActive = evalTxfSqkExaActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshSqkJti(dbswznm, moditems);

};

void PnlWznmOpkDetail::refreshRecSqkJtit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMSquawkTitle* _recSqkJtit = NULL;

	if (dbswznm->tblwznmjmsquawktitle->loadRecByRef(recSqkJtit.ref, &_recSqkJtit)) {
		recSqkJtit = *_recSqkJtit;
		delete _recSqkJtit;
	} else recSqkJtit = WznmJMSquawkTitle();

	contiac.numFPupSqkJti = feedFPupSqkJti.getNumByRef(recSqkJtit.ref);
	continf.TxtSqkTit = recSqkJtit.Title;

	statshr.PupSqkJtiAvail = evalPupSqkJtiAvail(dbswznm);
	statshr.PupSqkJtiActive = evalPupSqkJtiActive(dbswznm);
	statshr.ButSqkJtiEditAvail = evalButSqkJtiEditAvail(dbswznm);
	statshr.TxtSqkTitAvail = evalTxtSqkTitAvail(dbswznm);
	statshr.TxtSqkTitActive = evalTxtSqkTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmOpkDetail::refresh(
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

void PnlWznmOpkDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFOPK) {
		recOpk.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref);
		refreshRecOpk(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmOpkDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSQKNEWCLICK) {
					handleDpchAppDoButSqkNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSQKDELETECLICK) {
					handleDpchAppDoButSqkDeleteClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSQKJTIEDITCLICK) {
					handleDpchAppDoButSqkJtiEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmOpkDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmOpkDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::NUMFPUPTYP, ContIac::CHKSHD, ContIac::TXFCMT, ContIac::TXFSQKEXA})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::CHKSHD)) contiac.ChkShd = _contiac->ChkShd;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
		if (has(diffitems, ContIac::TXFSQKEXA)) contiac.TxfSqkExa = _contiac->TxfSqkExa;
	};

	if (has(diffitems, ContIac::NUMFPUPSQKJTI)) {
		recSqkJtit.ref = feedFPupSqkJti.getRefByNum(_contiac->numFPupSqkJti);
		refreshRecSqkJtit(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmOpkDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmOpkDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recOpk.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmOpkDetail::handleDpchAppDoButSqkNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkNewClick --- INSERT
};

void PnlWznmOpkDetail::handleDpchAppDoButSqkDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkDeleteClick --- INSERT
};

void PnlWznmOpkDetail::handleDpchAppDoButSqkJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkJtiEditClick --- INSERT
};

void PnlWznmOpkDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSQKJTITMOD_SQKEQ) {
		call->abort = handleCallWznmSqkJtitMod_sqkEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSQKUPD_REFEQ) {
		call->abort = handleCallWznmSqkUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPKUPD_REFEQ) {
		call->abort = handleCallWznmOpkUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPK_SQKEQ) {
		call->abort = handleCallWznmOpk_sqkEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPK_VEREQ) {
		call->abort = handleCallWznmOpk_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmOpkDetail::handleCallWznmSqkJtitMod_sqkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshSqkJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmOpkDetail::handleCallWznmSqkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSqkUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmOpkDetail::handleCallWznmOpkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmOpkUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmOpkDetail::handleCallWznmOpk_sqkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpk.refWznmMSquawk == refInv); // IP handleCallWznmOpk_sqkEq --- LINE
	return retval;
};

bool PnlWznmOpkDetail::handleCallWznmOpk_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpk.refWznmMVersion == refInv); // IP handleCallWznmOpk_verEq --- LINE
	return retval;
};
