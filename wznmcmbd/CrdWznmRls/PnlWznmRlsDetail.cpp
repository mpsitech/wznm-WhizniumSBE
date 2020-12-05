/**
	* \file PnlWznmRlsDetail.cpp
	* job handler for job PnlWznmRlsDetail (implementation)
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

#include "PnlWznmRlsDetail.h"

#include "PnlWznmRlsDetail_blks.cpp"
#include "PnlWznmRlsDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmRlsDetail
 ******************************************************************************/

PnlWznmRlsDetail::PnlWznmRlsDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMRLSDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstOpt.tag = "FeedFLstOpt";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMRELEASEOPTION, ixWznmVLocale, feedFLstOpt);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMRLS_MCHEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMRLS_CMPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMRELEASEOPTION);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFRLS, jref);
};

PnlWznmRlsDetail::~PnlWznmRlsDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmRlsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstOpt, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmRlsDetail::refreshLstOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	set<uint> nums;

	vector<string> ss;
	string s;

	// contiac
	contiac.numsFLstOpt.clear();

	StrMod::stringToVector(contiac.TxfOpt, ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		s = ss[i];

		for (unsigned int j = 0; j < feedFLstOpt.size(); j++) {
			if (feedFLstOpt.getSrefByNum(j+1) == s) {
				nums.insert(j+1);
				break;
			};
		};
	};

	for (auto it = nums.begin(); it != nums.end(); it++) contiac.numsFLstOpt.push_back(*it);

	// statshr
	statshr.TxfOptValid = ( (ss.size() == nums.size()) && (nums.size() == contiac.numsFLstOpt.size()) );
	statshr.LstOptActive = evalLstOptActive(dbswznm);
	statshr.ButOptEditAvail = evalButOptEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmRlsDetail::refreshTxfOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfOpt = "";

	for (unsigned int i = 0; i < contiac.numsFLstOpt.size(); i++) {
		if (i != 0) contiac.TxfOpt += ";";
		contiac.TxfOpt += feedFLstOpt.getSrefByNum(contiac.numsFLstOpt[i]);
	};

	// statshr
	statshr.TxfOptValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmRlsDetail::refreshOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFLstOpt
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMRELEASEOPTION, ixWznmVLocale, feedFLstOpt);

	insert(moditems, DpchEngData::FEEDFLSTOPT);

	refreshLstOpt(dbswznm, moditems);
};

void PnlWznmRlsDetail::refreshRecRls(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMRelease* _recRls = NULL;

	if (dbswznm->tblwznmmrelease->loadRecByRef(recRls.ref, &_recRls)) {
		recRls = *_recRls;
		delete _recRls;
	} else recRls = WznmMRelease();

	dirty = false;

	continf.TxtSrf = recRls.sref;
	continf.TxtCmp = StubWznm::getStubCmpStd(dbswznm, recRls.refWznmMComponent, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtMch = StubWznm::getStubMchStd(dbswznm, recRls.refWznmMMachine, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfOpt = recRls.srefsKOption;
	contiac.TxfCmt = recRls.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtCmpActive = evalTxtCmpActive(dbswznm);
	statshr.ButCmpViewAvail = evalButCmpViewAvail(dbswznm);
	statshr.ButCmpViewActive = evalButCmpViewActive(dbswznm);
	statshr.TxtMchActive = evalTxtMchActive(dbswznm);
	statshr.ButMchViewAvail = evalButMchViewAvail(dbswznm);
	statshr.ButMchViewActive = evalButMchViewActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshLstOpt(dbswznm, moditems);

};

void PnlWznmRlsDetail::refresh(
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

void PnlWznmRlsDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFRLS) {
		recRls.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref);
		refreshRecRls(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmRlsDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCMPVIEWCLICK) {
					handleDpchAppDoButCmpViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMCHVIEWCLICK) {
					handleDpchAppDoButMchViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPTEDITCLICK) {
					handleDpchAppDoButOptEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmRlsDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmRlsDetail::handleDpchAppDataContiac(
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

	if (has(diffitems, ContIac::TXFOPT)) {
		contiac.TxfOpt = _contiac->TxfOpt;
		refreshLstOpt(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMSFLSTOPT)) {
		contiac.numsFLstOpt = _contiac->numsFLstOpt;
		refreshTxfOpt(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmRlsDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmRlsDetail::handleDpchAppDoButCmpViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButCmpViewAvail && statshr.ButCmpViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmCmp";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recRls.refWznmMComponent, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref)) {
				sref = "CrdWznmCmp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recRls.refWznmMComponent, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmRlsDetail::handleDpchAppDoButMchViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButMchViewAvail && statshr.ButMchViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref)) {
			sref = "CrdWznmMch";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recRls.refWznmMMachine, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmRlsDetail::handleDpchAppDoButOptEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButOptEditClick --- INSERT
};

void PnlWznmRlsDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRLSUPD_REFEQ) {
		call->abort = handleCallWznmRlsUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRLS_MCHEQ) {
		call->abort = handleCallWznmRls_mchEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRLS_CMPEQ) {
		call->abort = handleCallWznmRls_cmpEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmRlsDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKMRELEASEOPTION) {
		refreshOpt(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmRlsDetail::handleCallWznmRlsUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmRlsUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmRlsDetail::handleCallWznmRls_mchEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRls.refWznmMMachine == refInv); // IP handleCallWznmRls_mchEq --- LINE
	return retval;
};

bool PnlWznmRlsDetail::handleCallWznmRls_cmpEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRls.refWznmMComponent == refInv); // IP handleCallWznmRls_cmpEq --- LINE
	return retval;
};



