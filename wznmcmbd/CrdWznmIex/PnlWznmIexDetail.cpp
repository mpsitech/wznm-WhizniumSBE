/**
	* \file PnlWznmIexDetail.cpp
	* job handler for job PnlWznmIexDetail (implementation)
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

#include "PnlWznmIexDetail.h"

#include "PnlWznmIexDetail_blks.cpp"
#include "PnlWznmIexDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmIexDetail
 ******************************************************************************/

PnlWznmIexDetail::PnlWznmIexDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMIEXDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupJti.tag = "FeedFPupJti";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMIEX_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMIEX_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFIEX, jref);
};

PnlWznmIexDetail::~PnlWznmIexDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmIexDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJti, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmIexDetail::refreshJti(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMImpexpcplxTitle iexJtits;
	WznmJMImpexpcplxTitle* iexJtit = NULL;

	string s;

	// feedFPupJti
	feedFPupJti.clear();

	dbswznm->tblwznmjmimpexpcplxtitle->loadRstByIex(recIex.ref, false, iexJtits);

	for (unsigned int i = 0; i < iexJtits.nodes.size(); i++) {
		iexJtit = iexJtits.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, iexJtit->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupJti.appendRefTitles(iexJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJTI);

	refreshRecIexJtit(dbswznm, moditems);

};

void PnlWznmIexDetail::refreshRecIex(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMImpexpcplx* _recIex = NULL;

	if (dbswznm->tblwznmmimpexpcplx->loadRecByRef(recIex.ref, &_recIex)) {
		recIex = *_recIex;
		delete _recIex;
	} else recIex = WznmMImpexpcplx();

	dirty = false;

	recIexJtit.ref = recIex.refJTitle;
	if (recIex.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMIEXJTITMOD_IEXEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMIEXJTITMOD_IEXEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recIex.ref);

	continf.TxtSrf = recIex.sref;
	contiac.TxfSho = recIex.Short;
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recIex.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtJob = StubWznm::getStubJobStd(dbswznm, recIex.refWznmMJob, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfMiv = recIex.Minversion;
	contiac.TxfCmt = recIex.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxfShoActive = evalTxfShoActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	statshr.TxtJobActive = evalTxtJobActive(dbswznm);
	statshr.ButJobViewAvail = evalButJobViewAvail(dbswznm);
	statshr.ButJobViewActive = evalButJobViewActive(dbswznm);
	statshr.TxfMivActive = evalTxfMivActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJti(dbswznm, moditems);

};

void PnlWznmIexDetail::refreshRecIexJtit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMImpexpcplxTitle* _recIexJtit = NULL;

	if (dbswznm->tblwznmjmimpexpcplxtitle->loadRecByRef(recIexJtit.ref, &_recIexJtit)) {
		recIexJtit = *_recIexJtit;
		delete _recIexJtit;
	} else recIexJtit = WznmJMImpexpcplxTitle();

	contiac.numFPupJti = feedFPupJti.getNumByRef(recIexJtit.ref);
	continf.TxtTit = recIexJtit.Title;

	statshr.PupJtiActive = evalPupJtiActive(dbswznm);
	statshr.ButJtiEditAvail = evalButJtiEditAvail(dbswznm);
	statshr.TxtTitActive = evalTxtTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmIexDetail::refresh(
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

void PnlWznmIexDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFIEX) {
		recIex.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIEX, jref);
		refreshRecIex(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmIexDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJTIEDITCLICK) {
					handleDpchAppDoButJtiEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJOBVIEWCLICK) {
					handleDpchAppDoButJobViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmIexDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmIexDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSHO, ContIac::TXFMIV, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFSHO)) contiac.TxfSho = _contiac->TxfSho;
		if (has(diffitems, ContIac::TXFMIV)) contiac.TxfMiv = _contiac->TxfMiv;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJTI)) {
		recIexJtit.ref = feedFPupJti.getRefByNum(_contiac->numFPupJti);
		refreshRecIexJtit(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmIexDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmIexDetail::handleDpchAppDoButJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJtiEditClick --- INSERT
};

void PnlWznmIexDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recIex.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmIexDetail::handleDpchAppDoButJobViewClick(
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
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recIex.refWznmMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmIexDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMIEXJTITMOD_IEXEQ) {
		call->abort = handleCallWznmIexJtitMod_iexEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEXUPD_REFEQ) {
		call->abort = handleCallWznmIexUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEX_VEREQ) {
		call->abort = handleCallWznmIex_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEX_JOBEQ) {
		call->abort = handleCallWznmIex_jobEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmIexDetail::handleCallWznmIexJtitMod_iexEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmIexDetail::handleCallWznmIexUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmIexUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmIexDetail::handleCallWznmIex_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIex.refWznmMVersion == refInv); // IP handleCallWznmIex_verEq --- LINE
	return retval;
};

bool PnlWznmIexDetail::handleCallWznmIex_jobEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIex.refWznmMJob == refInv); // IP handleCallWznmIex_jobEq --- LINE
	return retval;
};
