/**
	* \file PnlWznmTblDetail.cpp
	* job handler for job PnlWznmTblDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmTblDetail.h"

#include "PnlWznmTblDetail_blks.cpp"
#include "PnlWznmTblDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmTblDetail
 ******************************************************************************/

PnlWznmTblDetail::PnlWznmTblDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMTBLDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstUnq.tag = "FeedFLstUnq";
	feedFPupPstAty.tag = "FeedFPupPstAty";
	VecWznmWArgtype::fillFeed(feedFPupPstAty);
	feedFPupPstJti.tag = "FeedFPupPstJti";
	feedFPupPstSco.tag = "FeedFPupPstSco";
	VecWznmVMPresetScope::fillFeed(ixWznmVLocale, feedFPupPstSco);
	feedFPupRet.tag = "FeedFPupRet";
	VecWznmVMTableRefTbl::fillFeed(ixWznmVLocale, feedFPupRet);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMTableBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_CAREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_PSTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFTBL, jref);
};

PnlWznmTblDetail::~PnlWznmTblDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmTblDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstUnq, &feedFPupPstAty, &feedFPupPstJti, &feedFPupPstSco, &feedFPupRet, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmTblDetail::refreshLstUnq(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUnqAvail = evalLstUnqAvail(dbswznm);
	statshr.LstUnqActive = evalLstUnqActive(dbswznm);
	statshr.ButUnqViewAvail = evalButUnqViewAvail(dbswznm);
	statshr.ButUnqViewActive = evalButUnqViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmTblDetail::refreshUnq(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	vector<string> ss;

	// contiac
	contiac.numFLstUnq = 0;

	// feedFLstUnq
	feedFLstUnq.clear();

	StrMod::stringToVector(contiac.TxfUnq, ss);

	// IP refreshUnq.validate --- INSERT

	// statshr
	statshr.TxfUnqValid = (ss.size() == feedFLstUnq.size());

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmTblDetail::refreshPstJti(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMPresetTitle pstJtits;
	WznmJMPresetTitle* pstJtit = NULL;

	string s;

	// feedFPupPstJti
	feedFPupPstJti.clear();

	dbswznm->tblwznmjmpresettitle->loadRstByPst(recPst.ref, false, pstJtits);

	for (unsigned int i = 0; i < pstJtits.nodes.size(); i++) {
		pstJtit = pstJtits.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, pstJtit->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupPstJti.appendRefTitles(pstJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPPSTJTI);

	refreshRecPstJtit(dbswznm, moditems);

};

void PnlWznmTblDetail::refreshRecTbl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMTable* _recTbl = NULL;

	if (dbswznm->tblwznmmtable->loadRecByRef(recTbl.ref, &_recTbl)) {
		recTbl = *_recTbl;
		ixWSubsetTbl = dbswznm->getIxWSubsetByWznmMTable(_recTbl);
		delete _recTbl;
	} else {
		recTbl = WznmMTable();
		ixWSubsetTbl = 0;
	};

	dirty = false;

	recPst.ref = recTbl.refWznmMPreset;

	continf.TxtSrf = recTbl.sref;
	contiac.TxfSho = recTbl.Short;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recTbl.ixVBasetype);
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recTbl.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupRet = feedFPupRet.getNumByIx(recTbl.refIxVTbl);
	continf.TxtCar = StubWznm::getStubCarStd(dbswznm, recTbl.refWznmMCard, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfUnq = recTbl.unqSrefsWznmMTablecol;
	contiac.TxfCmt = recTbl.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxfShoActive = evalTxfShoActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	statshr.TxtReuActive = evalTxtReuActive(dbswznm);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswznm);
	statshr.ButReuViewActive = evalButReuViewActive(dbswznm);
	statshr.TxtCarAvail = evalTxtCarAvail(dbswznm);
	statshr.TxtCarActive = evalTxtCarActive(dbswznm);
	statshr.ButCarViewAvail = evalButCarViewAvail(dbswznm);
	statshr.ButCarViewActive = evalButCarViewActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecPst(dbswznm, moditems);

	refreshUnq(dbswznm, moditems);

};

void PnlWznmTblDetail::refreshRecPst(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMPreset* _recPst = NULL;

	if (dbswznm->tblwznmmpreset->loadRecByRef(recPst.ref, &_recPst)) {
		recPst = *_recPst;
		delete _recPst;
	} else recPst = WznmMPreset();

	recPstJtit.ref = recPst.refJTitle;
	if (recPst.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPst.ref);

	continf.TxtPstSrf = recPst.sref;
	continf.TxtPstVer = StubWznm::getStubVerStd(dbswznm, recPst.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupPstSco = feedFPupPstSco.getNumByIx(recPst.ixVScope);
	contiac.numFPupPstAty = feedFPupPstAty.getNumByIx(recPst.ixWznmWArgtype);

	statshr.SepPstAvail = evalSepPstAvail(dbswznm);
	statshr.HdgPstAvail = evalHdgPstAvail(dbswznm);
	statshr.ButPstNewAvail = evalButPstNewAvail(dbswznm);
	statshr.ButPstDeleteAvail = evalButPstDeleteAvail(dbswznm);
	statshr.TxtPstSrfAvail = evalTxtPstSrfAvail(dbswznm);
	statshr.TxtPstSrfActive = evalTxtPstSrfActive(dbswznm);
	statshr.TxtPstVerAvail = evalTxtPstVerAvail(dbswznm);
	statshr.TxtPstVerActive = evalTxtPstVerActive(dbswznm);
	statshr.ButPstVerViewAvail = evalButPstVerViewAvail(dbswznm);
	statshr.ButPstVerViewActive = evalButPstVerViewActive(dbswznm);
	statshr.PupPstScoAvail = evalPupPstScoAvail(dbswznm);
	statshr.PupPstScoActive = evalPupPstScoActive(dbswznm);
	statshr.PupPstAtyAvail = evalPupPstAtyAvail(dbswznm);
	statshr.PupPstAtyActive = evalPupPstAtyActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPstJti(dbswznm, moditems);

};

void PnlWznmTblDetail::refreshRecPstJtit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMPresetTitle* _recPstJtit = NULL;

	if (dbswznm->tblwznmjmpresettitle->loadRecByRef(recPstJtit.ref, &_recPstJtit)) {
		recPstJtit = *_recPstJtit;
		delete _recPstJtit;
	} else recPstJtit = WznmJMPresetTitle();

	contiac.numFPupPstJti = feedFPupPstJti.getNumByRef(recPstJtit.ref);
	continf.TxtPstTit = recPstJtit.Title;

	statshr.PupPstJtiAvail = evalPupPstJtiAvail(dbswznm);
	statshr.PupPstJtiActive = evalPupPstJtiActive(dbswznm);
	statshr.ButPstJtiEditAvail = evalButPstJtiEditAvail(dbswznm);
	statshr.TxtPstTitAvail = evalTxtPstTitAvail(dbswznm);
	statshr.TxtPstTitActive = evalTxtPstTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmTblDetail::refresh(
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

void PnlWznmTblDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFTBL) {
		recTbl.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref);
		refreshRecTbl(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmTblDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCARVIEWCLICK) {
					handleDpchAppDoButCarViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUNQVIEWCLICK) {
					handleDpchAppDoButUnqViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTNEWCLICK) {
					handleDpchAppDoButPstNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTDELETECLICK) {
					handleDpchAppDoButPstDeleteClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTJTIEDITCLICK) {
					handleDpchAppDoButPstJtiEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTVERVIEWCLICK) {
					handleDpchAppDoButPstVerViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmTblDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmTblDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSHO, ContIac::NUMFPUPTYP, ContIac::TXFCMT, ContIac::NUMFPUPPSTSCO, ContIac::NUMFPUPPSTATY})) {
		if (has(diffitems, ContIac::TXFSHO)) contiac.TxfSho = _contiac->TxfSho;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
		if (has(diffitems, ContIac::NUMFPUPPSTSCO)) contiac.numFPupPstSco = _contiac->numFPupPstSco;
		if (has(diffitems, ContIac::NUMFPUPPSTATY)) contiac.numFPupPstAty = _contiac->numFPupPstAty;
	};

	if (has(diffitems, ContIac::TXFUNQ)) {
		contiac.TxfUnq = _contiac->TxfUnq;
		refreshUnq(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFLSTUNQ)) {
		contiac.numFLstUnq = _contiac->numFLstUnq;
		refreshLstUnq(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFPUPPSTJTI)) {
		recPstJtit.ref = feedFPupPstJti.getRefByNum(_contiac->numFPupPstJti);
		refreshRecPstJtit(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmTblDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmTblDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recTbl.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTblDetail::handleDpchAppDoButReuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref)) if (recTbl.refIxVTbl == VecWznmVMTableRefTbl::QRY) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmQry";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recTbl.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref)) if (recTbl.refIxVTbl == VecWznmVMTableRefTbl::REL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmRel";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recTbl.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTblDetail::handleDpchAppDoButCarViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButCarViewAvail && statshr.ButCarViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmCar";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recTbl.refWznmMCard, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTblDetail::handleDpchAppDoButUnqViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButUnqViewClick --- INSERT
};

void PnlWznmTblDetail::handleDpchAppDoButPstNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstNewClick --- INSERT
};

void PnlWznmTblDetail::handleDpchAppDoButPstDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstDeleteClick --- INSERT
};

void PnlWznmTblDetail::handleDpchAppDoButPstJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButPstJtiEditClick --- INSERT
};

void PnlWznmTblDetail::handleDpchAppDoButPstVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPstVerViewAvail && statshr.ButPstVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recPst.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmTblDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPSTJTITMOD_PSTEQ) {
		call->abort = handleCallWznmPstJtitMod_pstEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBLUPD_REFEQ) {
		call->abort = handleCallWznmTblUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPSTUPD_REFEQ) {
		call->abort = handleCallWznmPstUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_CAREQ) {
		call->abort = handleCallWznmTbl_carEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_INSBS) {
		call->abort = handleCallWznmTbl_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_PSTEQ) {
		call->abort = handleCallWznmTbl_pstEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_RETEQ) {
		call->abort = handleCallWznmTbl_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_REUEQ) {
		call->abort = handleCallWznmTbl_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_TYPEQ) {
		call->abort = handleCallWznmTbl_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_VEREQ) {
		call->abort = handleCallWznmTbl_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_VEREQ) {
		call->abort = handleCallWznmPst_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_REUEQ) {
		call->abort = handleCallWznmPst_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_RETEQ) {
		call->abort = handleCallWznmPst_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWznmTblDetail::handleCallWznmPstJtitMod_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshPstJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmTblUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmTblUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmPstUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPstUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmTbl_carEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refWznmMCard == refInv); // IP handleCallWznmTbl_carEq --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmTbl_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetTbl & ixInv) != 0); // IP handleCallWznmTbl_inSbs --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmTbl_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refWznmMPreset == refInv); // IP handleCallWznmTbl_pstEq --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmTbl_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refIxVTbl == ixInv); // IP handleCallWznmTbl_retEq --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmTbl_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refUref == refInv); // IP handleCallWznmTbl_reuEq --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmTbl_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.ixVBasetype == ixInv); // IP handleCallWznmTbl_typEq --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmTbl_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refWznmMVersion == refInv); // IP handleCallWznmTbl_verEq --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmPst_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refWznmMVersion == refInv); // IP handleCallWznmPst_verEq --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmPst_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refUref == refInv); // IP handleCallWznmPst_reuEq --- LINE
	return retval;
};

bool PnlWznmTblDetail::handleCallWznmPst_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refIxVTbl == ixInv); // IP handleCallWznmPst_retEq --- LINE
	return retval;
};

