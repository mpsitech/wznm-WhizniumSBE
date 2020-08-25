/**
	* \file PnlWznmIelDetail.cpp
	* job handler for job PnlWznmIelDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmIelDetail.h"

#include "PnlWznmIelDetail_blks.cpp"
#include "PnlWznmIelDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmIelDetail
 ******************************************************************************/

PnlWznmIelDetail::PnlWznmIelDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMIELDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstOcc.tag = "FeedFLstOcc";
	VecWznmWMImpexpcolOccurrence::fillFeed(ixWznmVLocale, feedFLstOcc);
	feedFPupCty.tag = "FeedFPupCty";
	VecWznmVMImpexpcolConvtype::fillFeed(ixWznmVLocale, feedFPupCty);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMImpexpcolBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMIEL_VITEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMIEL_STBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMIEL_PSTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMIEL_IMEEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMIEL_IM2EQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFIEL, jref);
};

PnlWznmIelDetail::~PnlWznmIelDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmIelDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstOcc, &feedFPupCty, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmIelDetail::refreshTxtOcc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstOcc.size(); i++) ix |= feedFLstOcc.getIxByNum(contiac.numsFLstOcc[i]);
	continf.TxtOcc = VecWznmWMImpexpcolOccurrence::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmIelDetail::refreshRecIel(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmMImpexpcol* _recIel = NULL;

	if (dbswznm->tblwznmmimpexpcol->loadRecByRef(recIel.ref, &_recIel)) {
		recIel = *_recIel;
		delete _recIel;
	} else recIel = WznmMImpexpcol();

	dirty = false;

	recIelJstb.ref = recIel.refJStub;
	if (recIel.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMIELJSTBMOD_IELEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMIELJSTBMOD_IELEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recIel.ref);

	continf.TxtSrf = recIel.sref;
	contiac.TxfSho = recIel.Short;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recIel.ixVBasetype);
	contiac.numsFLstOcc.clear();
	VecWznmWMImpexpcolOccurrence::getIcs(recIel.ixWOccurrence, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstOcc.push_back(feedFLstOcc.getNumByIx(*it));
	continf.TxtIme = StubWznm::getStubImeStd(dbswznm, recIel.imeRefWznmMImpexp, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTco = StubWznm::getStubTcoStd(dbswznm, recIel.refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtIm2 = StubWznm::getStubImeStd(dbswznm, recIel.refWznmMImpexp, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupCty = feedFPupCty.getNumByIx(recIel.ixVConvtype);
	contiac.TxfDfv = recIel.Defval;
	continf.TxtPst = StubWznm::getStubPstStd(dbswznm, recIel.refWznmMPreset, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtStb = StubWznm::getStubStbStd(dbswznm, recIel.refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtVit = StubWznm::getStubVitStd(dbswznm, recIel.refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::FULL);

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxfShoActive = evalTxfShoActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.LstOccActive = evalLstOccActive(dbswznm);
	statshr.TxtImeActive = evalTxtImeActive(dbswznm);
	statshr.ButImeViewAvail = evalButImeViewAvail(dbswznm);
	statshr.ButImeViewActive = evalButImeViewActive(dbswznm);
	statshr.TxtTcoActive = evalTxtTcoActive(dbswznm);
	statshr.TxtIm2Active = evalTxtIm2Active(dbswznm);
	statshr.ButIm2ViewAvail = evalButIm2ViewAvail(dbswznm);
	statshr.ButIm2ViewActive = evalButIm2ViewActive(dbswznm);
	statshr.PupCtyActive = evalPupCtyActive(dbswznm);
	statshr.TxfDfvActive = evalTxfDfvActive(dbswznm);
	statshr.TxtPstActive = evalTxtPstActive(dbswznm);
	statshr.ButPstViewAvail = evalButPstViewAvail(dbswznm);
	statshr.ButPstViewActive = evalButPstViewActive(dbswznm);
	statshr.TxtStbActive = evalTxtStbActive(dbswznm);
	statshr.ButStbViewAvail = evalButStbViewAvail(dbswznm);
	statshr.ButStbViewActive = evalButStbViewActive(dbswznm);
	statshr.TxtVitActive = evalTxtVitActive(dbswznm);
	statshr.ButVitViewAvail = evalButVitViewAvail(dbswznm);
	statshr.ButVitViewActive = evalButVitViewActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtOcc(dbswznm, moditems);

};

void PnlWznmIelDetail::refreshRecIelJstb(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmJMImpexpcolStub* _recIelJstb = NULL;

	if (dbswznm->tblwznmjmimpexpcolstub->loadRecByRef(recIelJstb.ref, &_recIelJstb)) {
		recIelJstb = *_recIelJstb;
		delete _recIelJstb;
	} else recIelJstb = WznmJMImpexpcolStub();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmIelDetail::refresh(
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

void PnlWznmIelDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFIEL) {
		recIel.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIEL, jref);
		refreshRecIel(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmIelDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIELDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIELDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIMEVIEWCLICK) {
					handleDpchAppDoButImeViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIM2VIEWCLICK) {
					handleDpchAppDoButIm2ViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTVIEWCLICK) {
					handleDpchAppDoButPstViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTBVIEWCLICK) {
					handleDpchAppDoButStbViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVITVIEWCLICK) {
					handleDpchAppDoButVitViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmIelDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmIelDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSHO, ContIac::NUMFPUPTYP, ContIac::NUMFPUPCTY, ContIac::TXFDFV})) {
		if (has(diffitems, ContIac::TXFSHO)) contiac.TxfSho = _contiac->TxfSho;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::NUMFPUPCTY)) contiac.numFPupCty = _contiac->numFPupCty;
		if (has(diffitems, ContIac::TXFDFV)) contiac.TxfDfv = _contiac->TxfDfv;
	};

	if (has(diffitems, ContIac::NUMSFLSTOCC)) {
		contiac.numsFLstOcc = _contiac->numsFLstOcc;
		refreshTxtOcc(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmIelDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmIelDetail::handleDpchAppDoButImeViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	ubigint refVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	if (statshr.ButImeViewAvail && statshr.ButImeViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFIEX) {
			sref = "CrdWznmIme";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recIel.imeRefWznmMImpexp, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref)) if (refVer != 0) {
				sref = "CrdWznmIme";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, recIel.imeRefWznmMImpexp, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmIelDetail::handleDpchAppDoButIm2ViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	ubigint refVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	if (statshr.ButIm2ViewAvail && statshr.ButIm2ViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFIEX) {
			sref = "CrdWznmIme";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recIel.refWznmMImpexp, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref)) if (refVer != 0) {
				sref = "CrdWznmIme";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, recIel.refWznmMImpexp, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmIelDetail::handleDpchAppDoButPstViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	if (statshr.ButPstViewAvail && statshr.ButPstViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref)) if (refVer != 0) {
			sref = "CrdWznmPst";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, recIel.refWznmMPreset, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref)) if (refVer != 0) {
				sref = "CrdWznmTbl";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, [&](){ubigint ref = 0; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMPreset = " + to_string(recIel.refWznmMPreset), ref); return ref;}(), jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref)) if (refVer != 0) {
				sref = "CrdWznmSbs";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, [&](){ubigint ref = 0; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMSubset WHERE refWznmMPreset = " + to_string(recIel.refWznmMPreset), ref); return ref;}(), jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref)) if (refVer != 0) {
				sref = "CrdWznmVec";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, [&](){ubigint ref = 0; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMPreset = " + to_string(recIel.refWznmMPreset), ref); return ref;}(), jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmIelDetail::handleDpchAppDoButStbViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	if (statshr.ButStbViewAvail && statshr.ButStbViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref)) if (refVer != 0) {
			sref = "CrdWznmStb";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, recIel.refWznmMStub, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmIelDetail::handleDpchAppDoButVitViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	if (statshr.ButVitViewAvail && statshr.ButVitViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref)) if (refVer != 0) {
			sref = "CrdWznmVit";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFVER, refVer, sref, recIel.refWznmMVectoritem, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmIelDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMIELJSTBMOD_IELEQ) {
		call->abort = handleCallWznmIelJstbMod_ielEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIELUPD_REFEQ) {
		call->abort = handleCallWznmIelUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEL_VITEQ) {
		call->abort = handleCallWznmIel_vitEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEL_STBEQ) {
		call->abort = handleCallWznmIel_stbEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEL_PSTEQ) {
		call->abort = handleCallWznmIel_pstEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEL_IMEEQ) {
		call->abort = handleCallWznmIel_imeEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEL_IM2EQ) {
		call->abort = handleCallWznmIel_im2Eq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmIelDetail::handleCallWznmIelJstbMod_ielEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmIelJstbMod_ielEq --- INSERT
	return retval;
};

bool PnlWznmIelDetail::handleCallWznmIelUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmIelUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmIelDetail::handleCallWznmIel_vitEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIel.refWznmMVectoritem == refInv); // IP handleCallWznmIel_vitEq --- LINE
	return retval;
};

bool PnlWznmIelDetail::handleCallWznmIel_stbEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIel.refWznmMStub == refInv); // IP handleCallWznmIel_stbEq --- LINE
	return retval;
};

bool PnlWznmIelDetail::handleCallWznmIel_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIel.refWznmMPreset == refInv); // IP handleCallWznmIel_pstEq --- LINE
	return retval;
};

bool PnlWznmIelDetail::handleCallWznmIel_imeEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIel.imeRefWznmMImpexp == refInv); // IP handleCallWznmIel_imeEq --- LINE
	return retval;
};

bool PnlWznmIelDetail::handleCallWznmIel_im2Eq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recIel.refWznmMImpexp == refInv); // IP handleCallWznmIel_im2Eq --- LINE
	return retval;
};

