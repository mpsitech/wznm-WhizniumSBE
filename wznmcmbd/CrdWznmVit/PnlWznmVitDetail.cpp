/**
	* \file PnlWznmVitDetail.cpp
	* job handler for job PnlWznmVitDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmVitDetail.h"

#include "PnlWznmVitDetail_blks.cpp"
#include "PnlWznmVitDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmVitDetail
 ******************************************************************************/

PnlWznmVitDetail::PnlWznmVitDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMVITDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupJ.tag = "FeedFPupJ";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMVIT_VECEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVIT, jref);
};

PnlWznmVitDetail::~PnlWznmVitDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmVitDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmVitDetail::refreshJ(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMVectoritem vitJs;
	WznmJMVectoritem* vitJ = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbswznm->tblwznmjmvectoritem->loadRstByVit(recVit.ref, false, vitJs);

	for (unsigned int i = 0; i < vitJs.nodes.size(); i++) {
		vitJ = vitJs.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, vitJ->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupJ.appendRefTitles(vitJ->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecVitJ(dbswznm, moditems);

};

void PnlWznmVitDetail::refreshRecVit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMVectoritem* _recVit = NULL;

	if (dbswznm->tblwznmmvectoritem->loadRecByRef(recVit.ref, &_recVit)) {
		recVit = *_recVit;
		delete _recVit;
	} else recVit = WznmMVectoritem();

	dirty = false;

	recVitJ.ref = recVit.refJ;
	if (recVit.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMVITJMOD_VITEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMVITJMOD_VITEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recVit.ref);

	continf.TxtSrf = recVit.sref;
	continf.TxtVec = StubWznm::getStubVecStd(dbswznm, recVit.vecRefWznmMVector, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfAvl = recVit.Avail;
	contiac.TxfImp = recVit.Implied;
	contiac.TxfCmt = recVit.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtVecActive = evalTxtVecActive(dbswznm);
	statshr.ButVecViewAvail = evalButVecViewAvail(dbswznm);
	statshr.ButVecViewActive = evalButVecViewActive(dbswznm);
	statshr.TxfAvlActive = evalTxfAvlActive(dbswznm);
	statshr.TxfImpActive = evalTxfImpActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbswznm, moditems);

};

void PnlWznmVitDetail::refreshRecVitJ(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMVectoritem* _recVitJ = NULL;

	if (dbswznm->tblwznmjmvectoritem->loadRecByRef(recVitJ.ref, &_recVitJ)) {
		recVitJ = *_recVitJ;
		delete _recVitJ;
	} else recVitJ = WznmJMVectoritem();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recVitJ.ref);
	continf.TxtTit = recVitJ.Title;

	statshr.PupJActive = evalPupJActive(dbswznm);
	statshr.ButJEditAvail = evalButJEditAvail(dbswznm);
	statshr.TxtTitActive = evalTxtTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmVitDetail::refresh(
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

void PnlWznmVitDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFVIT) {
		recVit.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIT, jref);
		refreshRecVit(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmVitDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVITDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVITDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVECVIEWCLICK) {
					handleDpchAppDoButVecViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmVitDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmVitDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFAVL, ContIac::TXFIMP, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFAVL)) contiac.TxfAvl = _contiac->TxfAvl;
		if (has(diffitems, ContIac::TXFIMP)) contiac.TxfImp = _contiac->TxfImp;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recVitJ.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecVitJ(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmVitDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmVitDetail::handleDpchAppDoButJEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlWznmVitDetail::handleDpchAppDoButVecViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButVecViewAvail && statshr.ButVecViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmVec";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recVit.vecRefWznmMVector, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmVitDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMVITUPD_REFEQ) {
		call->abort = handleCallWznmVitUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVIT_VECEQ) {
		call->abort = handleCallWznmVit_vecEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVITJMOD_VITEQ) {
		call->abort = handleCallWznmVitJMod_vitEq(dbswznm, call->jref);
	};
};

bool PnlWznmVitDetail::handleCallWznmVitUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmVitUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmVitDetail::handleCallWznmVit_vecEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVit.vecRefWznmMVector == refInv); // IP handleCallWznmVit_vecEq --- LINE
	return retval;
};

bool PnlWznmVitDetail::handleCallWznmVitJMod_vitEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

