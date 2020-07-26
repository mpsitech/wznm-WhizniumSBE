/**
	* \file PnlWznmQcoDetail.cpp
	* job handler for job PnlWznmQcoDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmQcoDetail.h"

#include "PnlWznmQcoDetail_blks.cpp"
#include "PnlWznmQcoDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmQcoDetail
 ******************************************************************************/

PnlWznmQcoDetail::PnlWznmQcoDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMQCODETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstOcc.tag = "FeedFLstOcc";
	VecWznmWMQuerycolOccurrence::fillFeed(ixWznmVLocale, feedFLstOcc);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMQuerycolBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMQCO_STBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMQCO_QRYEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFQCO, jref);
};

PnlWznmQcoDetail::~PnlWznmQcoDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmQcoDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstOcc, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmQcoDetail::refreshTxtOcc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstOcc.size(); i++) ix |= feedFLstOcc.getIxByNum(contiac.numsFLstOcc[i]);
	continf.TxtOcc = VecWznmWMQuerycolOccurrence::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmQcoDetail::refreshRecQco(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmMQuerycol* _recQco = NULL;

	if (dbswznm->tblwznmmquerycol->loadRecByRef(recQco.ref, &_recQco)) {
		recQco = *_recQco;
		delete _recQco;
	} else recQco = WznmMQuerycol();

	dirty = false;

	continf.TxtSrf = recQco.sref;
	contiac.TxfSho = recQco.Short;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recQco.ixVBasetype);
	contiac.numsFLstOcc.clear();
	VecWznmWMQuerycolOccurrence::getIcs(recQco.ixWOccurrence, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstOcc.push_back(feedFLstOcc.getNumByIx(*it));
	continf.TxtQry = StubWznm::getStubQryStd(dbswznm, recQco.qryRefWznmMQuery, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTco = StubWznm::getStubTcoStd(dbswznm, recQco.refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtStb = StubWznm::getStubStbStd(dbswznm, recQco.refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::FULL);

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxfShoActive = evalTxfShoActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.LstOccActive = evalLstOccActive(dbswznm);
	statshr.TxtQryActive = evalTxtQryActive(dbswznm);
	statshr.ButQryViewAvail = evalButQryViewAvail(dbswznm);
	statshr.ButQryViewActive = evalButQryViewActive(dbswznm);
	statshr.TxtTcoActive = evalTxtTcoActive(dbswznm);
	statshr.TxtStbActive = evalTxtStbActive(dbswznm);
	statshr.ButStbViewAvail = evalButStbViewAvail(dbswznm);
	statshr.ButStbViewActive = evalButStbViewActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtOcc(dbswznm, moditems);

};

void PnlWznmQcoDetail::refreshRecQcoJstb(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmJMQuerycolStub* _recQcoJstb = NULL;

	if (dbswznm->tblwznmjmquerycolstub->loadRecByRef(recQcoJstb.ref, &_recQcoJstb)) {
		recQcoJstb = *_recQcoJstb;
		delete _recQcoJstb;
	} else recQcoJstb = WznmJMQuerycolStub();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmQcoDetail::refresh(
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

void PnlWznmQcoDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFQCO) {
		recQco.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFQCO, jref);
		refreshRecQco(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmQcoDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCODETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCODETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTQRYVIEWCLICK) {
					handleDpchAppDoButQryViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTBVIEWCLICK) {
					handleDpchAppDoButStbViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmQcoDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmQcoDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSHO, ContIac::NUMFPUPTYP})) {
		if (has(diffitems, ContIac::TXFSHO)) contiac.TxfSho = _contiac->TxfSho;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
	};

	if (has(diffitems, ContIac::NUMSFLSTOCC)) {
		contiac.numsFLstOcc = _contiac->numsFLstOcc;
		refreshTxtOcc(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmQcoDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmQcoDetail::handleDpchAppDoButQryViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButQryViewAvail && statshr.ButQryViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmQry";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recQco.qryRefWznmMQuery, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmQcoDetail::handleDpchAppDoButStbViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButStbViewAvail && statshr.ButStbViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmStb";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recQco.refWznmMStub, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmQcoDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMQCOJSTBMOD_QCOEQ) {
		call->abort = handleCallWznmQcoJstbMod_qcoEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQCOUPD_REFEQ) {
		call->abort = handleCallWznmQcoUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQCO_STBEQ) {
		call->abort = handleCallWznmQco_stbEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQCO_QRYEQ) {
		call->abort = handleCallWznmQco_qryEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmQcoDetail::handleCallWznmQcoJstbMod_qcoEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmQcoJstbMod_qcoEq --- INSERT
	return retval;
};

bool PnlWznmQcoDetail::handleCallWznmQcoUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmQcoUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmQcoDetail::handleCallWznmQco_stbEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recQco.refWznmMStub == refInv); // IP handleCallWznmQco_stbEq --- LINE
	return retval;
};

bool PnlWznmQcoDetail::handleCallWznmQco_qryEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recQco.qryRefWznmMQuery == refInv); // IP handleCallWznmQco_qryEq --- LINE
	return retval;
};

