/**
	* \file PnlWznmTagDetail.cpp
	* job handler for job PnlWznmTagDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmTagDetail.h"

#include "PnlWznmTagDetail_blks.cpp"
#include "PnlWznmTagDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmTagDetail
 ******************************************************************************/

PnlWznmTagDetail::PnlWznmTagDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMTAGDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupGrp.tag = "FeedFPupGrp";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKTAGGRP, ixWznmVLocale, feedFPupGrp);
	feedFPupJti.tag = "FeedFPupJti";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTAG_CPBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKTAGGRP);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFTAG, jref);
};

PnlWznmTagDetail::~PnlWznmTagDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmTagDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupGrp, &feedFPupJti, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmTagDetail::refreshJti(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMTagTitle tagJtits;
	WznmJMTagTitle* tagJtit = NULL;

	string s;

	// feedFPupJti
	feedFPupJti.clear();

	dbswznm->tblwznmjmtagtitle->loadRstByTag(recTag.ref, false, tagJtits);

	for (unsigned int i = 0; i < tagJtits.nodes.size(); i++) {
		tagJtit = tagJtits.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, tagJtit->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupJti.appendRefTitles(tagJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJTI);

	refreshRecTagJtit(dbswznm, moditems);

};

void PnlWznmTagDetail::refreshPupGrp(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupGrp = 0;

	for (unsigned int i = 0; i < feedFPupGrp.size(); i++) {
		if (feedFPupGrp.getSrefByNum(i+1) == contiac.TxfGrp) {
			contiac.numFPupGrp = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfGrpValid = (contiac.numFPupGrp != 0);
	statshr.PupGrpActive = evalPupGrpActive(dbswznm);
	statshr.ButGrpEditAvail = evalButGrpEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmTagDetail::refreshTxfGrp(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfGrp = feedFPupGrp.getSrefByNum(contiac.numFPupGrp);

	// statshr
	statshr.TxfGrpValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmTagDetail::refreshGrp(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFPupGrp
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKTAGGRP, ixWznmVLocale, feedFPupGrp);

	insert(moditems, DpchEngData::FEEDFPUPGRP);

	refreshPupGrp(dbswznm, moditems);
};

void PnlWznmTagDetail::refreshRecTag(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMTag* _recTag = NULL;

	if (dbswznm->tblwznmmtag->loadRecByRef(recTag.ref, &_recTag)) {
		recTag = *_recTag;
		delete _recTag;
	} else recTag = WznmMTag();

	dirty = false;

	recTagJtit.ref = recTag.refJTitle;
	if (recTag.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMTAGJTITMOD_TAGEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMTAGJTITMOD_TAGEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recTag.ref);

	continf.TxtSrf = recTag.sref;
	continf.TxtCpb = StubWznm::getStubCpbStd(dbswznm, recTag.refWznmMCapability, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfGrp = recTag.osrefWznmKTaggrp;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtCpbActive = evalTxtCpbActive(dbswznm);
	statshr.ButCpbViewAvail = evalButCpbViewAvail(dbswznm);
	statshr.ButCpbViewActive = evalButCpbViewActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJti(dbswznm, moditems);
	refreshPupGrp(dbswznm, moditems);

};

void PnlWznmTagDetail::refreshRecTagJtit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMTagTitle* _recTagJtit = NULL;

	if (dbswznm->tblwznmjmtagtitle->loadRecByRef(recTagJtit.ref, &_recTagJtit)) {
		recTagJtit = *_recTagJtit;
		delete _recTagJtit;
	} else recTagJtit = WznmJMTagTitle();

	contiac.numFPupJti = feedFPupJti.getNumByRef(recTagJtit.ref);
	continf.TxtTit = recTagJtit.Title;

	statshr.PupJtiActive = evalPupJtiActive(dbswznm);
	statshr.ButJtiEditAvail = evalButJtiEditAvail(dbswznm);
	statshr.TxtTitActive = evalTxtTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmTagDetail::refresh(
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

void PnlWznmTagDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFTAG) {
		recTag.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTAG, jref);
		refreshRecTag(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmTagDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTAGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTAGDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJTIEDITCLICK) {
					handleDpchAppDoButJtiEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCPBVIEWCLICK) {
					handleDpchAppDoButCpbViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTGRPEDITCLICK) {
					handleDpchAppDoButGrpEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmTagDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmTagDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFPUPJTI)) {
		recTagJtit.ref = feedFPupJti.getRefByNum(_contiac->numFPupJti);
		refreshRecTagJtit(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFGRP)) {
		contiac.TxfGrp = _contiac->TxfGrp;
		refreshPupGrp(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPGRP)) {
		contiac.numFPupGrp = _contiac->numFPupGrp;
		refreshTxfGrp(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmTagDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmTagDetail::handleDpchAppDoButJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJtiEditClick --- INSERT
};

void PnlWznmTagDetail::handleDpchAppDoButCpbViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButCpbViewAvail && statshr.ButCpbViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCTP, jref)) {
			sref = "CrdWznmCtp";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recTag.refWznmMCapability, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTagDetail::handleDpchAppDoButGrpEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButGrpEditClick --- INSERT
};

void PnlWznmTagDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTAGJTITMOD_TAGEQ) {
		call->abort = handleCallWznmTagJtitMod_tagEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTAGUPD_REFEQ) {
		call->abort = handleCallWznmTagUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTAG_CPBEQ) {
		call->abort = handleCallWznmTag_cpbEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmTagDetail::handleCallWznmTagJtitMod_tagEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmTagDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKTAGGRP) {
		refreshGrp(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmTagDetail::handleCallWznmTagUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmTagUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmTagDetail::handleCallWznmTag_cpbEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTag.refWznmMCapability == refInv); // IP handleCallWznmTag_cpbEq --- LINE
	return retval;
};

