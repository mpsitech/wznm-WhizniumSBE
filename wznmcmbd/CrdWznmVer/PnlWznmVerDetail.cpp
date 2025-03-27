/**
	* \file PnlWznmVerDetail.cpp
	* job handler for job PnlWznmVerDetail (implementation)
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

#include "PnlWznmVerDetail.h"

#include "PnlWznmVerDetail_blks.cpp"
#include "PnlWznmVerDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmVerDetail
 ******************************************************************************/

PnlWznmVerDetail::PnlWznmVerDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMVERDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstDty.tag = "FeedFLstDty";
	VecWznmWMVersionDbmstype::fillFeed(ixWznmVLocale, feedFLstDty);
	feedFLstOpt.tag = "FeedFLstOpt";
	VecWznmWMVersionOption::fillFeed(ixWznmVLocale, feedFLstOpt);
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupJst.tag = "FeedFPupJst";
	feedFPupSte.tag = "FeedFPupSte";
	VecWznmVMVersionState::fillFeed(ixWznmVLocale, feedFPupSte);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMVER_STEEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVER_BVREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVER_LOCEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVER_PRJEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVER, jref);
};

PnlWznmVerDetail::~PnlWznmVerDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmVerDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDty, &feedFLstOpt, &feedFPupJ, &feedFPupJst, &feedFPupSte, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmVerDetail::refreshJst(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMVersionState verJstes;
	WznmJMVersionState* verJste = NULL;

	string s;

	// feedFPupJst
	feedFPupJst.clear();

	dbswznm->tblwznmjmversionstate->loadRstByVer(recVer.ref, false, verJstes);

	for (unsigned int i = 0; i < verJstes.nodes.size(); i++) {
		verJste = verJstes.nodes[i];

		s = "";
		if (verJste->x1Start != 0) {
			s = Ftm::stamp(verJste->x1Start) + " -";
			if ((i+2) < verJstes.nodes.size()) if (verJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::stamp(verJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecWznmVTag::getTitle(VecWznmVTag::ALWAYS, ixWznmVLocale) + ")";
		feedFPupJst.appendRefTitles(verJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJST);

	refreshRecVerJste(dbswznm, moditems);

};

void PnlWznmVerDetail::refreshTxtDty(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstDty.size(); i++) ix |= feedFLstDty.getIxByNum(contiac.numsFLstDty[i]);
	continf.TxtDty = VecWznmWMVersionDbmstype::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmVerDetail::refreshTxtOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstOpt.size(); i++) ix |= feedFLstOpt.getIxByNum(contiac.numsFLstOpt[i]);
	continf.TxtOpt = VecWznmWMVersionOption::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmVerDetail::refreshJ(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMVersion verJs;
	WznmJMVersion* verJ = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbswznm->tblwznmjmversion->loadRstByVer(recVer.ref, false, verJs);

	for (unsigned int i = 0; i < verJs.nodes.size(); i++) {
		verJ = verJs.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, verJ->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupJ.appendRefTitles(verJ->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecVerJ(dbswznm, moditems);

};

void PnlWznmVerDetail::refreshRecVer(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmMVersion* _recVer = NULL;

	if (dbswznm->tblwznmmversion->loadRecByRef(recVer.ref, &_recVer)) {
		recVer = *_recVer;
		delete _recVer;
	} else recVer = WznmMVersion();

	dirty = false;

	recVerJ.ref = recVer.refJ;
	if (recVer.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMVERJMOD_VEREQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMVERJMOD_VEREQ, jref, Clstn::VecVJobmask::ALL, 0, true, recVer.ref);

	recVerJste.ref = recVer.refJState;
	if (recVer.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMVERJSTEMOD_VEREQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMVERJSTEMOD_VEREQ, jref, Clstn::VecVJobmask::ALL, 0, true, recVer.ref);

	continf.TxtPrj = StubWznm::getStubPrjStd(dbswznm, recVer.prjRefWznmMProject, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfMaj = to_string(recVer.Major);
	contiac.TxfMin = to_string(recVer.Minor);
	contiac.TxfSub = to_string(recVer.Sub);
	continf.TxtBvr = StubWznm::getStubVerStd(dbswznm, recVer.bvrRefWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtLoc = StubWznm::getStubLocStd(dbswznm, recVer.refWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numsFLstDty.clear();
	VecWznmWMVersionDbmstype::getIcs(recVer.ixWDbmstype, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstDty.push_back(feedFLstDty.getNumByIx(*it));
	contiac.numsFLstOpt.clear();
	VecWznmWMVersionOption::getIcs(recVer.ixWOption, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstOpt.push_back(feedFLstOpt.getNumByIx(*it));
	contiac.TxfCmt = recVer.Comment;

	statshr.TxtPrjActive = evalTxtPrjActive(dbswznm);
	statshr.ButPrjViewAvail = evalButPrjViewAvail(dbswznm);
	statshr.ButPrjViewActive = evalButPrjViewActive(dbswznm);
	statshr.TxfMajActive = evalTxfMajActive(dbswznm);
	statshr.TxfMinActive = evalTxfMinActive(dbswznm);
	statshr.TxfSubActive = evalTxfSubActive(dbswznm);
	statshr.TxtBvrActive = evalTxtBvrActive(dbswznm);
	statshr.ButBvrViewAvail = evalButBvrViewAvail(dbswznm);
	statshr.ButBvrViewActive = evalButBvrViewActive(dbswznm);
	statshr.TxtLocActive = evalTxtLocActive(dbswznm);
	statshr.ButLocViewAvail = evalButLocViewAvail(dbswznm);
	statshr.ButLocViewActive = evalButLocViewActive(dbswznm);
	statshr.LstDtyActive = evalLstDtyActive(dbswznm);
	statshr.LstOptActive = evalLstOptActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJst(dbswznm, moditems);
	refreshTxtDty(dbswznm, moditems);
	refreshTxtOpt(dbswznm, moditems);
	refreshJ(dbswznm, moditems);

};

void PnlWznmVerDetail::refreshRecVerJ(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmJMVersion* _recVerJ = NULL;

	if (dbswznm->tblwznmjmversion->loadRecByRef(recVerJ.ref, &_recVerJ)) {
		recVerJ = *_recVerJ;
		delete _recVerJ;
	} else recVerJ = WznmJMVersion();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recVerJ.ref);
	continf.TxtAb1 = recVerJ.About1;
	continf.TxtAb2 = recVerJ.About2;
	continf.TxtAb3 = recVerJ.About3;

	statshr.PupJActive = evalPupJActive(dbswznm);
	statshr.ButJEditAvail = evalButJEditAvail(dbswznm);
	statshr.TxtAb1Active = evalTxtAb1Active(dbswznm);
	statshr.TxtAb2Active = evalTxtAb2Active(dbswznm);
	statshr.TxtAb3Active = evalTxtAb3Active(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmVerDetail::refreshRecVerJste(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmJMVersionState* _recVerJste = NULL;

	if (dbswznm->tblwznmjmversionstate->loadRecByRef(recVerJste.ref, &_recVerJste)) {
		recVerJste = *_recVerJste;
		delete _recVerJste;
	} else recVerJste = WznmJMVersionState();

	contiac.numFPupJst = feedFPupJst.getNumByRef(recVerJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recVerJste.ixVState);

	statshr.PupJstActive = evalPupJstActive(dbswznm);
	statshr.ButJstEditAvail = evalButJstEditAvail(dbswznm);
	statshr.PupSteActive = evalPupSteActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmVerDetail::refresh(
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

void PnlWznmVerDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFVER) {
		recVer.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
		refreshRecVer(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmVerDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJVIEWCLICK) {
					handleDpchAppDoButPrjViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBVRVIEWCLICK) {
					handleDpchAppDoButBvrViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLOCVIEWCLICK) {
					handleDpchAppDoButLocViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJSTEDITCLICK) {
					handleDpchAppDoButJstEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmVerDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmVerDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFMAJ, ContIac::TXFMIN, ContIac::TXFSUB, ContIac::NUMFPUPSTE, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFMAJ)) contiac.TxfMaj = _contiac->TxfMaj;
		if (has(diffitems, ContIac::TXFMIN)) contiac.TxfMin = _contiac->TxfMin;
		if (has(diffitems, ContIac::TXFSUB)) contiac.TxfSub = _contiac->TxfSub;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJST)) {
		recVerJste.ref = feedFPupJst.getRefByNum(_contiac->numFPupJst);
		refreshRecVerJste(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTDTY)) {
		contiac.numsFLstDty = _contiac->numsFLstDty;
		refreshTxtDty(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTOPT)) {
		contiac.numsFLstOpt = _contiac->numsFLstOpt;
		refreshTxtOpt(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recVerJ.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecVerJ(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmVerDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmVerDetail::handleDpchAppDoButPrjViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrjViewAvail && statshr.ButPrjViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref)) {
			sref = "CrdWznmPrj";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recVer.prjRefWznmMProject, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmVerDetail::handleDpchAppDoButBvrViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButBvrViewAvail && statshr.ButBvrViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFPRJ) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recVer.bvrRefWznmMVersion, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
				sref = "CrdWznmVer";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recVer.bvrRefWznmMVersion, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmVerDetail::handleDpchAppDoButLocViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButLocViewAvail && statshr.ButLocViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLOC, jref)) {
			sref = "CrdWznmLoc";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recVer.refWznmMLocale, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmVerDetail::handleDpchAppDoButJstEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJstEditClick --- INSERT
};

void PnlWznmVerDetail::handleDpchAppDoButJEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlWznmVerDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMVERJSTEMOD_VEREQ) {
		call->abort = handleCallWznmVerJsteMod_verEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVERJMOD_VEREQ) {
		call->abort = handleCallWznmVerJMod_verEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVERUPD_REFEQ) {
		call->abort = handleCallWznmVerUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVER_STEEQ) {
		call->abort = handleCallWznmVer_steEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVER_BVREQ) {
		call->abort = handleCallWznmVer_bvrEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVER_LOCEQ) {
		call->abort = handleCallWznmVer_locEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVER_PRJEQ) {
		call->abort = handleCallWznmVer_prjEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmVerDetail::handleCallWznmVerJsteMod_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJst(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmVerDetail::handleCallWznmVerJMod_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmVerDetail::handleCallWznmVerUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmVerUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmVerDetail::handleCallWznmVer_steEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.ixVState == ixInv); // IP handleCallWznmVer_steEq --- LINE
	return retval;
};

bool PnlWznmVerDetail::handleCallWznmVer_bvrEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.bvrRefWznmMVersion == refInv); // IP handleCallWznmVer_bvrEq --- LINE
	return retval;
};

bool PnlWznmVerDetail::handleCallWznmVer_locEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.refWznmMLocale == refInv); // IP handleCallWznmVer_locEq --- LINE
	return retval;
};

bool PnlWznmVerDetail::handleCallWznmVer_prjEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.prjRefWznmMProject == refInv); // IP handleCallWznmVer_prjEq --- LINE
	return retval;
};
