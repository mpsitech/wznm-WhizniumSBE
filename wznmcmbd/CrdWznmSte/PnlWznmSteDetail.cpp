/**
	* \file PnlWznmSteDetail.cpp
	* job handler for job PnlWznmSteDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmSteDetail.h"

#include "PnlWznmSteDetail_blks.cpp"
#include "PnlWznmSteDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmSteDetail
 ******************************************************************************/

PnlWznmSteDetail::PnlWznmSteDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMSTEDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupEac.tag = "FeedFPupEac";
	VecWznmVMStateAction::fillFeed(ixWznmVLocale, feedFPupEac);
	feedFPupLac.tag = "FeedFPupLac";
	VecWznmVMStateAction::fillFeed(ixWznmVLocale, feedFPupLac);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMSTE_ERJEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTE_ESNEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTE_EVEEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTE_EVIEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTE_SEQEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFSTE, jref);
};

PnlWznmSteDetail::~PnlWznmSteDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmSteDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupEac, &feedFPupLac, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmSteDetail::refreshRecSte(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMState* _recSte = NULL;

	if (dbswznm->tblwznmmstate->loadRecByRef(recSte.ref, &_recSte)) {
		recSte = *_recSte;
		delete _recSte;
	} else recSte = WznmMState();

	dirty = false;

	continf.TxtSrf = recSte.sref;
	continf.TxtSeq = StubWznm::getStubSeqStd(dbswznm, recSte.seqRefWznmMSequence, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupEac = feedFPupEac.getNumByIx(recSte.eacIxVAction);
	continf.TxtErj = StubWznm::getStubRtjStd(dbswznm, recSte.erjRefWznmMRtjob, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtEve = StubWznm::getStubVecStd(dbswznm, recSte.eveRefWznmMVector, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtEvi = StubWznm::getStubVitStd(dbswznm, recSte.eviRefWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtEsn = StubWznm::getStubSteStd(dbswznm, recSte.esnRefWznmMState, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupLac = feedFPupLac.getNumByIx(recSte.lacIxVAction);
	contiac.ChkCst = recSte.Custstep;
	contiac.TxfCmt = recSte.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtSeqActive = evalTxtSeqActive(dbswznm);
	statshr.ButSeqViewAvail = evalButSeqViewAvail(dbswznm);
	statshr.ButSeqViewActive = evalButSeqViewActive(dbswznm);
	statshr.PupEacActive = evalPupEacActive(dbswznm);
	statshr.TxtErjActive = evalTxtErjActive(dbswznm);
	statshr.ButErjViewAvail = evalButErjViewAvail(dbswznm);
	statshr.ButErjViewActive = evalButErjViewActive(dbswznm);
	statshr.TxtEveActive = evalTxtEveActive(dbswznm);
	statshr.ButEveViewAvail = evalButEveViewAvail(dbswznm);
	statshr.ButEveViewActive = evalButEveViewActive(dbswznm);
	statshr.TxtEviActive = evalTxtEviActive(dbswznm);
	statshr.ButEviViewAvail = evalButEviViewAvail(dbswznm);
	statshr.ButEviViewActive = evalButEviViewActive(dbswznm);
	statshr.TxtEsnActive = evalTxtEsnActive(dbswznm);
	statshr.ButEsnViewAvail = evalButEsnViewAvail(dbswznm);
	statshr.ButEsnViewActive = evalButEsnViewActive(dbswznm);
	statshr.PupLacActive = evalPupLacActive(dbswznm);
	statshr.ChkCstActive = evalChkCstActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmSteDetail::refresh(
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

void PnlWznmSteDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSTE) {
		recSte.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSTE, jref);
		refreshRecSte(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmSteDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTEDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTEDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSEQVIEWCLICK) {
					handleDpchAppDoButSeqViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTERJVIEWCLICK) {
					handleDpchAppDoButErjViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEVEVIEWCLICK) {
					handleDpchAppDoButEveViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEVIVIEWCLICK) {
					handleDpchAppDoButEviViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTESNVIEWCLICK) {
					handleDpchAppDoButEsnViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmSteDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmSteDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPEAC, ContIac::NUMFPUPLAC, ContIac::CHKCST, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPEAC)) contiac.numFPupEac = _contiac->numFPupEac;
		if (has(diffitems, ContIac::NUMFPUPLAC)) contiac.numFPupLac = _contiac->numFPupLac;
		if (has(diffitems, ContIac::CHKCST)) contiac.ChkCst = _contiac->ChkCst;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmSteDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmSteDetail::handleDpchAppDoButSeqViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSeqViewAvail && statshr.ButSeqViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFAPP) {
			sref = "CrdWznmSeq";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSte.seqRefWznmMSequence, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSteDetail::handleDpchAppDoButErjViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButErjViewAvail && statshr.ButErjViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFAPP) {
			sref = "CrdWznmRtj";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSte.erjRefWznmMRtjob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSteDetail::handleDpchAppDoButEveViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	if (statshr.ButEveViewAvail && statshr.ButEveViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref)) if (refVer != 0) {
			sref = "CrdWznmVec";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, recSte.eveRefWznmMVector, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSteDetail::handleDpchAppDoButEviViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	if (statshr.ButEviViewAvail && statshr.ButEviViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref)) if (refVer != 0) {
			sref = "CrdWznmVit";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, recSte.eviRefWznmMVectoritem, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSteDetail::handleDpchAppDoButEsnViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButEsnViewAvail && statshr.ButEsnViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFAPP) {
			sref = "CrdWznmSte";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recSte.esnRefWznmMState, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmSteDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTEUPD_REFEQ) {
		call->abort = handleCallWznmSteUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTE_ERJEQ) {
		call->abort = handleCallWznmSte_erjEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTE_ESNEQ) {
		call->abort = handleCallWznmSte_esnEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTE_EVEEQ) {
		call->abort = handleCallWznmSte_eveEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTE_EVIEQ) {
		call->abort = handleCallWznmSte_eviEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTE_SEQEQ) {
		call->abort = handleCallWznmSte_seqEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmSteDetail::handleCallWznmSteUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmSteUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmSteDetail::handleCallWznmSte_erjEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSte.erjRefWznmMRtjob == refInv); // IP handleCallWznmSte_erjEq --- LINE
	return retval;
};

bool PnlWznmSteDetail::handleCallWznmSte_esnEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSte.esnRefWznmMState == refInv); // IP handleCallWznmSte_esnEq --- LINE
	return retval;
};

bool PnlWznmSteDetail::handleCallWznmSte_eveEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSte.eveRefWznmMVector == refInv); // IP handleCallWznmSte_eveEq --- LINE
	return retval;
};

bool PnlWznmSteDetail::handleCallWznmSte_eviEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSte.eviRefWznmMVectoritem == refInv); // IP handleCallWznmSte_eviEq --- LINE
	return retval;
};

bool PnlWznmSteDetail::handleCallWznmSte_seqEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSte.seqRefWznmMSequence == refInv); // IP handleCallWznmSte_seqEq --- LINE
	return retval;
};

