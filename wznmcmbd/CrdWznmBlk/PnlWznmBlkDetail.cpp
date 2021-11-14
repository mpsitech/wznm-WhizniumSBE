/**
	* \file PnlWznmBlkDetail.cpp
	* job handler for job PnlWznmBlkDetail (implementation)
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

#include "PnlWznmBlkDetail.h"

#include "PnlWznmBlkDetail_blks.cpp"
#include "PnlWznmBlkDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmBlkDetail
 ******************************************************************************/

PnlWznmBlkDetail::PnlWznmBlkDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMBLKDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstRea.tag = "FeedFLstRea";
	VecWznmWScope::fillFeed(feedFLstRea);
	feedFLstWri.tag = "FeedFLstWri";
	VecWznmWScope::fillFeed(feedFLstWri);
	feedFPupRet.tag = "FeedFPupRet";
	VecWznmVMBlockRefTbl::fillFeed(ixWznmVLocale, feedFPupRet);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMBlockBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMBLK_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMBLK_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMBLK_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFBLK, jref);
};

PnlWznmBlkDetail::~PnlWznmBlkDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmBlkDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstRea, &feedFLstWri, &feedFPupRet, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmBlkDetail::refreshTxtRea(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstRea.size(); i++) ix |= feedFLstRea.getIxByNum(contiac.numsFLstRea[i]);
	continf.TxtRea = VecWznmWScope::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmBlkDetail::refreshTxtWri(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstWri.size(); i++) ix |= feedFLstWri.getIxByNum(contiac.numsFLstWri[i]);
	continf.TxtWri = VecWznmWScope::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmBlkDetail::refreshRecBlk(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmMBlock* _recBlk = NULL;

	if (dbswznm->tblwznmmblock->loadRecByRef(recBlk.ref, &_recBlk)) {
		recBlk = *_recBlk;
		delete _recBlk;
	} else recBlk = WznmMBlock();

	dirty = false;

	continf.TxtSrf = recBlk.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recBlk.ixVBasetype);
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recBlk.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupRet = feedFPupRet.getNumByIx(recBlk.refIxVTbl);
	if (recBlk.refIxVTbl == VecWznmVMBlockRefTbl::JOB) continf.TxtReu = StubWznm::getStubJobStd(dbswznm, recBlk.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recBlk.refIxVTbl == VecWznmVMBlockRefTbl::OPX) continf.TxtReu = StubWznm::getStubOpxStd(dbswznm, recBlk.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recBlk.refIxVTbl == VecWznmVMBlockRefTbl::OPK) continf.TxtReu = StubWznm::getStubOpkStd(dbswznm, recBlk.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	contiac.numsFLstRea.clear();
	VecWznmWScope::getIcs(recBlk.reaIxWznmWScope, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstRea.push_back(feedFLstRea.getNumByIx(*it));
	contiac.numsFLstWri.clear();
	VecWznmWScope::getIcs(recBlk.wriIxWznmWScope, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstWri.push_back(feedFLstWri.getNumByIx(*it));
	contiac.TxfCmt = recBlk.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	statshr.TxtReuActive = evalTxtReuActive(dbswznm);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswznm);
	statshr.ButReuViewActive = evalButReuViewActive(dbswznm);
	statshr.LstReaActive = evalLstReaActive(dbswznm);
	statshr.LstWriActive = evalLstWriActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtRea(dbswznm, moditems);
	refreshTxtWri(dbswznm, moditems);

};

void PnlWznmBlkDetail::refresh(
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

void PnlWznmBlkDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFBLK) {
		recBlk.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFBLK, jref);
		refreshRecBlk(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmBlkDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmBlkDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmBlkDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMSFLSTREA)) {
		contiac.numsFLstRea = _contiac->numsFLstRea;
		refreshTxtRea(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTWRI)) {
		contiac.numsFLstWri = _contiac->numsFLstWri;
		refreshTxtWri(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmBlkDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmBlkDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recBlk.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmBlkDetail::handleDpchAppDoButReuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPK, jref)) if (recBlk.refIxVTbl == VecWznmVMBlockRefTbl::OPK) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmOpk";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recBlk.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref)) if (recBlk.refIxVTbl == VecWznmVMBlockRefTbl::OPX) if (ixPre == VecWznmVPreset::PREWZNMREFOPK) {
				sref = "CrdWznmOpx";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recBlk.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref)) if (recBlk.refIxVTbl == VecWznmVMBlockRefTbl::OPX) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmOpx";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recBlk.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref)) if (recBlk.refIxVTbl == VecWznmVMBlockRefTbl::JOB) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmJob";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recBlk.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmBlkDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMBLKUPD_REFEQ) {
		call->abort = handleCallWznmBlkUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMBLK_VEREQ) {
		call->abort = handleCallWznmBlk_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMBLK_REUEQ) {
		call->abort = handleCallWznmBlk_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMBLK_RETEQ) {
		call->abort = handleCallWznmBlk_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWznmBlkDetail::handleCallWznmBlkUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmBlkUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmBlkDetail::handleCallWznmBlk_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recBlk.refWznmMVersion == refInv); // IP handleCallWznmBlk_verEq --- LINE
	return retval;
};

bool PnlWznmBlkDetail::handleCallWznmBlk_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recBlk.refUref == refInv); // IP handleCallWznmBlk_reuEq --- LINE
	return retval;
};

bool PnlWznmBlkDetail::handleCallWznmBlk_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recBlk.refIxVTbl == ixInv); // IP handleCallWznmBlk_retEq --- LINE
	return retval;
};
