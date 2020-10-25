/**
	* \file PnlWznmMtyDetail.cpp
	* job handler for job PnlWznmMtyDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmMtyDetail.h"

#include "PnlWznmMtyDetail_blks.cpp"
#include "PnlWznmMtyDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmMtyDetail
 ******************************************************************************/

PnlWznmMtyDetail::PnlWznmMtyDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMMTYDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupAch.tag = "FeedFPupAch";
	VecWznmVMMachtypeArch::fillFeed(ixWznmVLocale, feedFPupAch);
	feedFPupOs.tag = "FeedFPupOs";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMMACHTYPEOS, ixWznmVLocale, feedFPupOs);
	feedFPupPkm.tag = "FeedFPupPkm";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMMACHTYPEPKGMGR, ixWznmVLocale, feedFPupPkm);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMMTY_CCHEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMMACHTYPEOS);
	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMMACHTYPEPKGMGR);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFMTY, jref);
};

PnlWznmMtyDetail::~PnlWznmMtyDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmMtyDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupAch, &feedFPupOs, &feedFPupPkm, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmMtyDetail::refreshPupOs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupOs = 0;

	for (unsigned int i = 0; i < feedFPupOs.size(); i++) {
		if (feedFPupOs.getSrefByNum(i+1) == contiac.TxfOs) {
			contiac.numFPupOs = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfOsValid = (contiac.numFPupOs != 0);
	statshr.PupOsActive = evalPupOsActive(dbswznm);
	statshr.ButOsEditAvail = evalButOsEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmMtyDetail::refreshTxfOs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfOs = feedFPupOs.getSrefByNum(contiac.numFPupOs);

	// statshr
	statshr.TxfOsValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmMtyDetail::refreshOs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFPupOs
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMMACHTYPEOS, ixWznmVLocale, feedFPupOs);

	insert(moditems, DpchEngData::FEEDFPUPOS);

	refreshPupOs(dbswznm, moditems);
};

void PnlWznmMtyDetail::refreshPupPkm(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupPkm = 0;

	for (unsigned int i = 0; i < feedFPupPkm.size(); i++) {
		if (feedFPupPkm.getSrefByNum(i+1) == contiac.TxfPkm) {
			contiac.numFPupPkm = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfPkmValid = (contiac.numFPupPkm != 0);
	statshr.PupPkmActive = evalPupPkmActive(dbswznm);
	statshr.ButPkmEditAvail = evalButPkmEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmMtyDetail::refreshTxfPkm(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfPkm = feedFPupPkm.getSrefByNum(contiac.numFPupPkm);

	// statshr
	statshr.TxfPkmValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmMtyDetail::refreshPkm(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFPupPkm
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMMACHTYPEPKGMGR, ixWznmVLocale, feedFPupPkm);

	insert(moditems, DpchEngData::FEEDFPUPPKM);

	refreshPupPkm(dbswznm, moditems);
};

void PnlWznmMtyDetail::refreshRecMty(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMMachtype* _recMty = NULL;

	if (dbswznm->tblwznmmmachtype->loadRecByRef(recMty.ref, &_recMty)) {
		recMty = *_recMty;
		delete _recMty;
	} else recMty = WznmMMachtype();

	dirty = false;

	continf.TxtSrf = recMty.sref;
	contiac.numFPupAch = feedFPupAch.getNumByIx(recMty.ixVArch);
	contiac.TxfOs = recMty.srefKOs;
	continf.TxtCch = StubWznm::getStubMchStd(dbswznm, recMty.cchRefWznmMMachine, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfPkm = recMty.srefKPkgmgr;
	contiac.TxfCmt = recMty.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupAchActive = evalPupAchActive(dbswznm);
	statshr.TxtCchActive = evalTxtCchActive(dbswznm);
	statshr.ButCchViewAvail = evalButCchViewAvail(dbswznm);
	statshr.ButCchViewActive = evalButCchViewActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupOs(dbswznm, moditems);
	refreshPupPkm(dbswznm, moditems);

};

void PnlWznmMtyDetail::refresh(
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

void PnlWznmMtyDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMTY) {
		recMty.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMTY, jref);
		refreshRecMty(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmMtyDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOSEDITCLICK) {
					handleDpchAppDoButOsEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCCHVIEWCLICK) {
					handleDpchAppDoButCchViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPKMEDITCLICK) {
					handleDpchAppDoButPkmEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmMtyDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmMtyDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPACH, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPACH)) contiac.numFPupAch = _contiac->numFPupAch;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFOS)) {
		contiac.TxfOs = _contiac->TxfOs;
		refreshPupOs(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPOS)) {
		contiac.numFPupOs = _contiac->numFPupOs;
		refreshTxfOs(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFPKM)) {
		contiac.TxfPkm = _contiac->TxfPkm;
		refreshPupPkm(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPPKM)) {
		contiac.numFPupPkm = _contiac->numFPupPkm;
		refreshTxfPkm(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmMtyDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmMtyDetail::handleDpchAppDoButOsEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButOsEditClick --- INSERT
};

void PnlWznmMtyDetail::handleDpchAppDoButCchViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButCchViewAvail && statshr.ButCchViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref)) {
			sref = "CrdWznmMch";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recMty.cchRefWznmMMachine, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmMtyDetail::handleDpchAppDoButPkmEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPkmEditClick --- INSERT
};

void PnlWznmMtyDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMMTYUPD_REFEQ) {
		call->abort = handleCallWznmMtyUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMTY_CCHEQ) {
		call->abort = handleCallWznmMty_cchEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	};
};

bool PnlWznmMtyDetail::handleCallWznmMtyUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmMtyUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmMtyDetail::handleCallWznmMty_cchEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMty.cchRefWznmMMachine == refInv); // IP handleCallWznmMty_cchEq --- LINE
	return retval;
};

bool PnlWznmMtyDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKMMACHTYPEOS) {
		refreshOs(dbswznm, moditems);
	} else if (ixInv == VecWznmVKeylist::KLSTWZNMKMMACHTYPEPKGMGR) {
		refreshPkm(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

