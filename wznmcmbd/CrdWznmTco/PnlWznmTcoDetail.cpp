/**
	* \file PnlWznmTcoDetail.cpp
	* job handler for job PnlWznmTcoDetail (implementation)
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

#include "PnlWznmTcoDetail.h"

#include "PnlWznmTcoDetail_blks.cpp"
#include "PnlWznmTcoDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmTcoDetail
 ******************************************************************************/

PnlWznmTcoDetail::PnlWznmTcoDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMTCODETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstOpt.tag = "FeedFLstOpt";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMTABLECOLOPTION, ixWznmVLocale, feedFLstOpt);
	feedFPupAxf.tag = "FeedFPupAxf";
	VecWznmVMTablecolAxisfct::fillFeed(ixWznmVLocale, feedFPupAxf);
	feedFPupFct.tag = "FeedFPupFct";
	VecWznmVMTablecolFctTbl::fillFeed(ixWznmVLocale, feedFPupFct);
	feedFPupSty.tag = "FeedFPupSty";
	VecWznmVMTablecolSubtype::fillFeed(ixWznmVLocale, feedFPupSty);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMTablecolBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_FCTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_FCUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_RELEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_SBSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_TBL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_TBLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMTABLECOLOPTION);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFTCO, jref);
};

PnlWznmTcoDetail::~PnlWznmTcoDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmTcoDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstOpt, &feedFPupAxf, &feedFPupFct, &feedFPupSty, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmTcoDetail::refreshLstOpt(
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

	StrMod::srefsToVector(contiac.TxfOpt, ss);

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

void PnlWznmTcoDetail::refreshTxfOpt(
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

void PnlWznmTcoDetail::refreshOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFLstOpt
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMTABLECOLOPTION, ixWznmVLocale, feedFLstOpt);

	insert(moditems, DpchEngData::FEEDFLSTOPT);

	refreshLstOpt(dbswznm, moditems);
};

void PnlWznmTcoDetail::refreshRecTco(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMTablecol* _recTco = NULL;

	if (dbswznm->tblwznmmtablecol->loadRecByRef(recTco.ref, &_recTco)) {
		recTco = *_recTco;
		ixWSubsetTco = dbswznm->getIxWSubsetByWznmMTablecol(_recTco);
		delete _recTco;
	} else {
		recTco = WznmMTablecol();
		ixWSubsetTco = 0;
	};

	dirty = false;

	continf.TxtSrf = recTco.sref;
	contiac.TxfSho = recTco.Short;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recTco.ixVBasetype);
	continf.TxtTbl = StubWznm::getStubTblStd(dbswznm, recTco.tblRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSbs = StubWznm::getStubSbsStd(dbswznm, recTco.refWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtRel = StubWznm::getStubRelStd(dbswznm, recTco.refWznmMRelation, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupFct = feedFPupFct.getNumByIx(recTco.fctIxVTbl);
	if (recTco.fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) continf.TxtFcu = StubWznm::getStubTblStd(dbswznm, recTco.fctUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recTco.fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) continf.TxtFcu = StubWznm::getStubVecStd(dbswznm, recTco.fctUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtFcu = "-";
	contiac.numFPupSty = feedFPupSty.getNumByIx(recTco.ixVSubtype);
	contiac.numFPupAxf = feedFPupAxf.getNumByIx(recTco.ixVAxisfct);
	contiac.TxfOpt = recTco.srefsKOption;
	contiac.ChkPnc = recTco.Principal;
	contiac.ChkEpo = recTco.Eponymous;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxfShoActive = evalTxfShoActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtTblActive = evalTxtTblActive(dbswznm);
	statshr.ButTblViewAvail = evalButTblViewAvail(dbswznm);
	statshr.ButTblViewActive = evalButTblViewActive(dbswznm);
	statshr.TxtSbsAvail = evalTxtSbsAvail(dbswznm);
	statshr.TxtSbsActive = evalTxtSbsActive(dbswznm);
	statshr.ButSbsViewAvail = evalButSbsViewAvail(dbswznm);
	statshr.ButSbsViewActive = evalButSbsViewActive(dbswznm);
	statshr.TxtRelAvail = evalTxtRelAvail(dbswznm);
	statshr.TxtRelActive = evalTxtRelActive(dbswznm);
	statshr.ButRelViewAvail = evalButRelViewAvail(dbswznm);
	statshr.ButRelViewActive = evalButRelViewActive(dbswznm);
	statshr.TxtFcuAvail = evalTxtFcuAvail(dbswznm);
	statshr.TxtFcuActive = evalTxtFcuActive(dbswznm);
	statshr.ButFcuViewAvail = evalButFcuViewAvail(dbswznm);
	statshr.ButFcuViewActive = evalButFcuViewActive(dbswznm);
	statshr.PupStyActive = evalPupStyActive(dbswznm);
	statshr.PupAxfActive = evalPupAxfActive(dbswznm);
	statshr.ChkPncActive = evalChkPncActive(dbswznm);
	statshr.ChkEpoActive = evalChkEpoActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshLstOpt(dbswznm, moditems);

};

void PnlWznmTcoDetail::refresh(
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

void PnlWznmTcoDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFTCO) {
		recTco.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTCO, jref);
		refreshRecTco(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmTcoDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCODETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCODETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTBLVIEWCLICK) {
					handleDpchAppDoButTblViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSBSVIEWCLICK) {
					handleDpchAppDoButSbsViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRELVIEWCLICK) {
					handleDpchAppDoButRelViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFCUVIEWCLICK) {
					handleDpchAppDoButFcuViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPTEDITCLICK) {
					handleDpchAppDoButOptEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmTcoDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmTcoDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSHO, ContIac::NUMFPUPTYP, ContIac::NUMFPUPSTY, ContIac::NUMFPUPAXF, ContIac::CHKPNC, ContIac::CHKEPO})) {
		if (has(diffitems, ContIac::TXFSHO)) contiac.TxfSho = _contiac->TxfSho;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::NUMFPUPSTY)) contiac.numFPupSty = _contiac->numFPupSty;
		if (has(diffitems, ContIac::NUMFPUPAXF)) contiac.numFPupAxf = _contiac->numFPupAxf;
		if (has(diffitems, ContIac::CHKPNC)) contiac.ChkPnc = _contiac->ChkPnc;
		if (has(diffitems, ContIac::CHKEPO)) contiac.ChkEpo = _contiac->ChkEpo;
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

void PnlWznmTcoDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmTcoDetail::handleDpchAppDoButTblViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButTblViewAvail && statshr.ButTblViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmTbl";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recTco.tblRefWznmMTable, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTcoDetail::handleDpchAppDoButSbsViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSbsViewAvail && statshr.ButSbsViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFTBL) {
			sref = "CrdWznmSbs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recTco.refWznmMSubset, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmSbs";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recTco.refWznmMSubset, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTcoDetail::handleDpchAppDoButRelViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButRelViewAvail && statshr.ButRelViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmRel";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recTco.refWznmMRelation, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTcoDetail::handleDpchAppDoButFcuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButFcuViewAvail && statshr.ButFcuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref)) if (recTco.fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmVec";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recTco.fctUref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTcoDetail::handleDpchAppDoButOptEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButOptEditClick --- INSERT
};

void PnlWznmTcoDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_FCTEQ) {
		call->abort = handleCallWznmTco_fctEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_FCUEQ) {
		call->abort = handleCallWznmTco_fcuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_INSBS) {
		call->abort = handleCallWznmTco_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_RELEQ) {
		call->abort = handleCallWznmTco_relEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_SBSEQ) {
		call->abort = handleCallWznmTco_sbsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_TBL_INSBS) {
		call->abort = handleCallWznmTco_tbl_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_TBLEQ) {
		call->abort = handleCallWznmTco_tblEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCOUPD_REFEQ) {
		call->abort = handleCallWznmTcoUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	};
};

bool PnlWznmTcoDetail::handleCallWznmTco_fctEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.fctIxVTbl == ixInv); // IP handleCallWznmTco_fctEq --- LINE
	return retval;
};

bool PnlWznmTcoDetail::handleCallWznmTco_fcuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.fctUref == refInv); // IP handleCallWznmTco_fcuEq --- LINE
	return retval;
};

bool PnlWznmTcoDetail::handleCallWznmTco_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetTco & ixInv) != 0); // IP handleCallWznmTco_inSbs --- LINE
	return retval;
};

bool PnlWznmTcoDetail::handleCallWznmTco_relEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.refWznmMRelation == refInv); // IP handleCallWznmTco_relEq --- LINE
	return retval;
};

bool PnlWznmTcoDetail::handleCallWznmTco_sbsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.refWznmMSubset == refInv); // IP handleCallWznmTco_sbsEq --- LINE
	return retval;
};

bool PnlWznmTcoDetail::handleCallWznmTco_tbl_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswznm->getIxWSubsetByRefWznmMTable(recTco.tblRefWznmMTable) & ixInv) != 0); // IP handleCallWznmTco_tbl_inSbs --- LINE
	return retval;
};

bool PnlWznmTcoDetail::handleCallWznmTco_tblEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.tblRefWznmMTable == refInv); // IP handleCallWznmTco_tblEq --- LINE
	return retval;
};

bool PnlWznmTcoDetail::handleCallWznmTcoUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmTcoUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmTcoDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKMTABLECOLOPTION) {
		refreshOpt(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
