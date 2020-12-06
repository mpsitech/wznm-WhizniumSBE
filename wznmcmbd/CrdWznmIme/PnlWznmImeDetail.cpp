/**
	* \file PnlWznmImeDetail.cpp
	* job handler for job PnlWznmImeDetail (implementation)
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

#include "PnlWznmImeDetail.h"

#include "PnlWznmImeDetail_blks.cpp"
#include "PnlWznmImeDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmImeDetail
 ******************************************************************************/

PnlWznmImeDetail::PnlWznmImeDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMIMEDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstIop.tag = "FeedFLstIop";
	VecWznmWMImpexpIop::fillFeed(ixWznmVLocale, feedFLstIop);
	feedFLstRtr.tag = "FeedFLstRtr";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMIME_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMIME_IEXEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFIME, jref);
};

PnlWznmImeDetail::~PnlWznmImeDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmImeDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstIop, &feedFLstRtr, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmImeDetail::refreshTxtIop(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstIop.size(); i++) ix |= feedFLstIop.getIxByNum(contiac.numsFLstIop[i]);
	continf.TxtIop = VecWznmWMImpexpIop::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmImeDetail::refreshLstRtr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRtrActive = evalLstRtrActive(dbswznm);
	statshr.ButRtrViewAvail = evalButRtrViewAvail(dbswznm);
	statshr.ButRtrViewActive = evalButRtrViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmImeDetail::refreshRtr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	vector<string> ss;

	// contiac
	contiac.numFLstRtr = 0;

	// feedFLstRtr
	feedFLstRtr.clear();

	StrMod::stringToVector(contiac.TxfRtr, ss);

	// IP refreshRtr.validate --- INSERT

	// statshr
	statshr.TxfRtrValid = (ss.size() == feedFLstRtr.size());

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmImeDetail::refreshRecIme(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmMImpexp* _recIme = NULL;

	if (dbswznm->tblwznmmimpexp->loadRecByRef(recIme.ref, &_recIme)) {
		recIme = *_recIme;
		delete _recIme;
	} else recIme = WznmMImpexp();

	dirty = false;

	continf.TxtSrf = recIme.sref;
	continf.TxtIex = StubWznm::getStubIexStd(dbswznm, recIme.refWznmMImpexpcplx, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSup = StubWznm::getStubImeStd(dbswznm, recIme.supRefWznmMImpexp, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTbl = StubWznm::getStubTblStd(dbswznm, recIme.refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numsFLstIop.clear();
	VecWznmWMImpexpIop::getIcs(recIme.ixWIop, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstIop.push_back(feedFLstIop.getNumByIx(*it));
	contiac.TxfRtr = recIme.rtrSrefsWznmMImpexpcol;
	contiac.TxfCmt = recIme.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtIexActive = evalTxtIexActive(dbswznm);
	statshr.ButIexViewAvail = evalButIexViewAvail(dbswznm);
	statshr.ButIexViewActive = evalButIexViewActive(dbswznm);
	statshr.TxtSupActive = evalTxtSupActive(dbswznm);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbswznm);
	statshr.ButSupViewActive = evalButSupViewActive(dbswznm);
	statshr.TxtTblActive = evalTxtTblActive(dbswznm);
	statshr.LstIopActive = evalLstIopActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtIop(dbswznm, moditems);
	refreshRtr(dbswznm, moditems);

};

void PnlWznmImeDetail::refresh(
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

void PnlWznmImeDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFIME) {
		recIme.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIME, jref);
		refreshRecIme(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmImeDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIEXVIEWCLICK) {
					handleDpchAppDoButIexViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRTRVIEWCLICK) {
					handleDpchAppDoButRtrViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmImeDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmImeDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMSFLSTIOP)) {
		contiac.numsFLstIop = _contiac->numsFLstIop;
		refreshTxtIop(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFRTR)) {
		contiac.TxfRtr = _contiac->TxfRtr;
		refreshRtr(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFLSTRTR)) {
		contiac.numFLstRtr = _contiac->numFLstRtr;
		refreshLstRtr(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmImeDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmImeDetail::handleDpchAppDoButIexViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButIexViewAvail && statshr.ButIexViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmIex";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recIme.refWznmMImpexpcplx, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmImeDetail::handleDpchAppDoButSupViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFIEX) {
			sref = "CrdWznmIme";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recIme.supRefWznmMImpexp, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmIme";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recIme.supRefWznmMImpexp, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmImeDetail::handleDpchAppDoButRtrViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButRtrViewClick --- INSERT
};

void PnlWznmImeDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMIME_SUPEQ) {
		call->abort = handleCallWznmIme_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIME_IEXEQ) {
		call->abort = handleCallWznmIme_iexEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIMEUPD_REFEQ) {
		call->abort = handleCallWznmImeUpd_refEq(dbswznm, call->jref);
	};
};

bool PnlWznmImeDetail::handleCallWznmIme_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIme.supRefWznmMImpexp == refInv); // IP handleCallWznmIme_supEq --- LINE
	return retval;
};

bool PnlWznmImeDetail::handleCallWznmIme_iexEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIme.refWznmMImpexpcplx == refInv); // IP handleCallWznmIme_iexEq --- LINE
	return retval;
};

bool PnlWznmImeDetail::handleCallWznmImeUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmImeUpd_refEq --- INSERT
	return retval;
};
