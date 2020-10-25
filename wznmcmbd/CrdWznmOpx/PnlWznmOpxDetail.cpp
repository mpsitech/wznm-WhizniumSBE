/**
	* \file PnlWznmOpxDetail.cpp
	* job handler for job PnlWznmOpxDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmOpxDetail.h"

#include "PnlWznmOpxDetail_blks.cpp"
#include "PnlWznmOpxDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmOpxDetail
 ******************************************************************************/

PnlWznmOpxDetail::PnlWznmOpxDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMOPXDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupSqkJti.tag = "FeedFPupSqkJti";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMOPX_SQKEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMOPX_OPKEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFOPX, jref);
};

PnlWznmOpxDetail::~PnlWznmOpxDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmOpxDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupSqkJti, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmOpxDetail::refreshSqkJti(
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

void PnlWznmOpxDetail::refreshRecOpx(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMOp* _recOpx = NULL;

	if (dbswznm->tblwznmmop->loadRecByRef(recOpx.ref, &_recOpx)) {
		recOpx = *_recOpx;
		delete _recOpx;
	} else recOpx = WznmMOp();

	dirty = false;

	recSqk.ref = recOpx.refWznmMSquawk;

	continf.TxtSrf = recOpx.sref;
	continf.TxtOpk = StubWznm::getStubOpkStd(dbswznm, recOpx.refWznmMOppack, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.ChkShd = recOpx.Shrdat;
	contiac.TxfCmt = recOpx.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtOpkActive = evalTxtOpkActive(dbswznm);
	statshr.ButOpkViewAvail = evalButOpkViewAvail(dbswznm);
	statshr.ButOpkViewActive = evalButOpkViewActive(dbswznm);
	statshr.ChkShdActive = evalChkShdActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecSqk(dbswznm, moditems);

};

void PnlWznmOpxDetail::refreshRecSqk(
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

void PnlWznmOpxDetail::refreshRecSqkJtit(
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

void PnlWznmOpxDetail::refresh(
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

void PnlWznmOpxDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFOPX) {
		recOpx.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPX, jref);
		refreshRecOpx(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmOpxDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPKVIEWCLICK) {
					handleDpchAppDoButOpkViewClick(dbswznm, &(req->dpcheng));
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

void PnlWznmOpxDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmOpxDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::CHKSHD, ContIac::TXFCMT, ContIac::TXFSQKEXA})) {
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

void PnlWznmOpxDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmOpxDetail::handleDpchAppDoButOpkViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButOpkViewAvail && statshr.ButOpkViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPK, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmOpk";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recOpx.refWznmMOppack, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmOpxDetail::handleDpchAppDoButSqkNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkNewClick --- INSERT
};

void PnlWznmOpxDetail::handleDpchAppDoButSqkDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkDeleteClick --- INSERT
};

void PnlWznmOpxDetail::handleDpchAppDoButSqkJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkJtiEditClick --- INSERT
};

void PnlWznmOpxDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSQKUPD_REFEQ) {
		call->abort = handleCallWznmSqkUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPXUPD_REFEQ) {
		call->abort = handleCallWznmOpxUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPX_SQKEQ) {
		call->abort = handleCallWznmOpx_sqkEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPX_OPKEQ) {
		call->abort = handleCallWznmOpx_opkEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSQKJTITMOD_SQKEQ) {
		call->abort = handleCallWznmSqkJtitMod_sqkEq(dbswznm, call->jref);
	};
};

bool PnlWznmOpxDetail::handleCallWznmSqkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSqkUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmOpxDetail::handleCallWznmOpxUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmOpxUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmOpxDetail::handleCallWznmOpx_sqkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpx.refWznmMSquawk == refInv); // IP handleCallWznmOpx_sqkEq --- LINE
	return retval;
};

bool PnlWznmOpxDetail::handleCallWznmOpx_opkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpx.refWznmMOppack == refInv); // IP handleCallWznmOpx_opkEq --- LINE
	return retval;
};

bool PnlWznmOpxDetail::handleCallWznmSqkJtitMod_sqkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshSqkJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

