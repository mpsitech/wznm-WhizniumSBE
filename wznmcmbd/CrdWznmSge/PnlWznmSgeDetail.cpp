/**
	* \file PnlWznmSgeDetail.cpp
	* job handler for job PnlWznmSgeDetail (implementation)
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

#include "PnlWznmSgeDetail.h"

#include "PnlWznmSgeDetail_blks.cpp"
#include "PnlWznmSgeDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmSgeDetail
 ******************************************************************************/

PnlWznmSgeDetail::PnlWznmSgeDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMSGEDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupSqkJti.tag = "FeedFPupSqkJti";
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMStageBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMSGE_FNXEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSGE_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSGE_SNXEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSGE_SQKEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFSGE, jref);
};

PnlWznmSgeDetail::~PnlWznmSgeDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmSgeDetail::getNewDpchEng(
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

void PnlWznmSgeDetail::refreshSqkJti(
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

void PnlWznmSgeDetail::refreshRecSge(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMStage* _recSge = NULL;

	if (dbswznm->tblwznmmstage->loadRecByRef(recSge.ref, &_recSge)) {
		recSge = *_recSge;
		delete _recSge;
	} else recSge = WznmMStage();

	dirty = false;

	recSqk.ref = recSge.refWznmMSquawk;

	continf.TxtSrf = recSge.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recSge.ixVBasetype);
	continf.TxtJob = StubWznm::getStubJobStd(dbswznm, recSge.jobRefWznmMJob, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfMon = to_string(recSge.Monitvl);
	continf.TxtSnx = StubWznm::getStubSgeStd(dbswznm, recSge.snxRefWznmMStage, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtFnx = StubWznm::getStubSgeStd(dbswznm, recSge.fnxRefWznmMStage, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recSge.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtJobActive = evalTxtJobActive(dbswznm);
	statshr.ButJobViewAvail = evalButJobViewAvail(dbswznm);
	statshr.ButJobViewActive = evalButJobViewActive(dbswznm);
	statshr.TxfMonActive = evalTxfMonActive(dbswznm);
	statshr.TxtSnxActive = evalTxtSnxActive(dbswznm);
	statshr.ButSnxViewAvail = evalButSnxViewAvail(dbswznm);
	statshr.ButSnxViewActive = evalButSnxViewActive(dbswznm);
	statshr.TxtFnxActive = evalTxtFnxActive(dbswznm);
	statshr.ButFnxViewAvail = evalButFnxViewAvail(dbswznm);
	statshr.ButFnxViewActive = evalButFnxViewActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecSqk(dbswznm, moditems);

};

void PnlWznmSgeDetail::refreshRecSqk(
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

void PnlWznmSgeDetail::refreshRecSqkJtit(
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

void PnlWznmSgeDetail::refresh(
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

void PnlWznmSgeDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSGE) {
		recSge.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSGE, jref);
		refreshRecSge(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmSgeDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGEDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGEDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJOBVIEWCLICK) {
					handleDpchAppDoButJobViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSNXVIEWCLICK) {
					handleDpchAppDoButSnxViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFNXVIEWCLICK) {
					handleDpchAppDoButFnxViewClick(dbswznm, &(req->dpcheng));
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

void PnlWznmSgeDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmSgeDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFMON, ContIac::TXFCMT, ContIac::TXFSQKEXA})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFMON)) contiac.TxfMon = _contiac->TxfMon;
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

void PnlWznmSgeDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmSgeDetail::handleDpchAppDoButJobViewClick(
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
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSge.jobRefWznmMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSgeDetail::handleDpchAppDoButSnxViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSnxViewAvail && statshr.ButSnxViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFJOB) {
			sref = "CrdWznmSge";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSge.snxRefWznmMStage, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmSge";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSge.snxRefWznmMStage, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSgeDetail::handleDpchAppDoButFnxViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButFnxViewAvail && statshr.ButFnxViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFJOB) {
			sref = "CrdWznmSge";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSge.fnxRefWznmMStage, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmSge";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSge.fnxRefWznmMStage, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSgeDetail::handleDpchAppDoButSqkNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkNewClick --- INSERT
};

void PnlWznmSgeDetail::handleDpchAppDoButSqkDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkDeleteClick --- INSERT
};

void PnlWznmSgeDetail::handleDpchAppDoButSqkJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSqkJtiEditClick --- INSERT
};

void PnlWznmSgeDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSGE_FNXEQ) {
		call->abort = handleCallWznmSge_fnxEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSGE_JOBEQ) {
		call->abort = handleCallWznmSge_jobEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSGE_SNXEQ) {
		call->abort = handleCallWznmSge_snxEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSGE_SQKEQ) {
		call->abort = handleCallWznmSge_sqkEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSQKUPD_REFEQ) {
		call->abort = handleCallWznmSqkUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSGEUPD_REFEQ) {
		call->abort = handleCallWznmSgeUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSQKJTITMOD_SQKEQ) {
		call->abort = handleCallWznmSqkJtitMod_sqkEq(dbswznm, call->jref);
	};
};

bool PnlWznmSgeDetail::handleCallWznmSge_fnxEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSge.fnxRefWznmMStage == refInv); // IP handleCallWznmSge_fnxEq --- LINE
	return retval;
};

bool PnlWznmSgeDetail::handleCallWznmSge_jobEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSge.jobRefWznmMJob == refInv); // IP handleCallWznmSge_jobEq --- LINE
	return retval;
};

bool PnlWznmSgeDetail::handleCallWznmSge_snxEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSge.snxRefWznmMStage == refInv); // IP handleCallWznmSge_snxEq --- LINE
	return retval;
};

bool PnlWznmSgeDetail::handleCallWznmSge_sqkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSge.refWznmMSquawk == refInv); // IP handleCallWznmSge_sqkEq --- LINE
	return retval;
};

bool PnlWznmSgeDetail::handleCallWznmSqkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSqkUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmSgeDetail::handleCallWznmSgeUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSgeUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmSgeDetail::handleCallWznmSqkJtitMod_sqkEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshSqkJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
