/**
	* \file PnlWznmRelDetail.cpp
	* job handler for job PnlWznmRelDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmRelDetail.h"

#include "PnlWznmRelDetail_blks.cpp"
#include "PnlWznmRelDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmRelDetail
 ******************************************************************************/

PnlWznmRelDetail::PnlWznmRelDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMRELDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFLstOpt.tag = "FeedFLstOpt";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMRELATIONOPTION, ixWznmVLocale, feedFLstOpt);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMRelationBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_TOSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_FRSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMRELATIONOPTION);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFREL, jref);
};

PnlWznmRelDetail::~PnlWznmRelDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmRelDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFLstOpt, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmRelDetail::refreshLstClu(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCluActive = evalLstCluActive(dbswznm);
	statshr.ButCluViewActive = evalButCluViewActive(dbswznm);
	statshr.ButCluClusterAvail = evalButCluClusterAvail(dbswznm);
	statshr.ButCluUnclusterAvail = evalButCluUnclusterAvail(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmRelDetail::refreshClu(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	vector<ubigint> refs;

	bool first;

	// contiac
	contiac.numFLstClu = 0;

	// feedFLstClu, continf
	feedFLstClu.clear();
	continf.TxtClu = "";

	if (recRel.refWznmCRelation != 0) dbswznm->tblwznmmrelation->loadRefsByClu(recRel.refWznmCRelation, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recRel.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWznm::getStubRelStd(dbswznm, refs[i], ixWznmVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWznm::getStubRelStd(dbswznm, refs[i], ixWznmVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswznm, moditems);
};

void PnlWznmRelDetail::refreshLstOpt(
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

void PnlWznmRelDetail::refreshTxfOpt(
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

void PnlWznmRelDetail::refreshOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFLstOpt
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMRELATIONOPTION, ixWznmVLocale, feedFLstOpt);

	insert(moditems, DpchEngData::FEEDFLSTOPT);

	refreshLstOpt(dbswznm, moditems);
};

void PnlWznmRelDetail::refreshRecRel(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMRelation* _recRel = NULL;

	if (dbswznm->tblwznmmrelation->loadRecByRef(recRel.ref, &_recRel)) {
		recRel = *_recRel;
		delete _recRel;
	} else recRel = WznmMRelation();

	dirty = false;

	if (recRel.refWznmCRelation == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMRELMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMRELMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recRel.refWznmCRelation);

	continf.TxtFrt = StubWznm::getStubTblStd(dbswznm, recRel.frRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtFrs = StubWznm::getStubSbsStd(dbswznm, recRel.frsRefWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTot = StubWznm::getStubTblStd(dbswznm, recRel.toRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTos = StubWznm::getStubSbsStd(dbswznm, recRel.tosRefWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recRel.ixVBasetype);
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recRel.refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSup = StubWznm::getStubRelStd(dbswznm, recRel.supRefWznmMRelation, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTbl = StubWznm::getStubTblStd(dbswznm, recRel.refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfPfx = recRel.Prefix;
	contiac.TxfOpt = recRel.srefsKOption;

	statshr.TxtFrtActive = evalTxtFrtActive(dbswznm);
	statshr.TxtFrsActive = evalTxtFrsActive(dbswznm);
	statshr.ButFrsViewAvail = evalButFrsViewAvail(dbswznm);
	statshr.ButFrsViewActive = evalButFrsViewActive(dbswznm);
	statshr.TxtTotActive = evalTxtTotActive(dbswznm);
	statshr.TxtTosActive = evalTxtTosActive(dbswznm);
	statshr.ButTosViewAvail = evalButTosViewAvail(dbswznm);
	statshr.ButTosViewActive = evalButTosViewActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	statshr.TxtSupActive = evalTxtSupActive(dbswznm);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbswznm);
	statshr.ButSupViewActive = evalButSupViewActive(dbswznm);
	statshr.TxtTblActive = evalTxtTblActive(dbswznm);
	statshr.TxfPfxActive = evalTxfPfxActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbswznm, moditems);
	refreshLstOpt(dbswznm, moditems);

};

void PnlWznmRelDetail::refresh(
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

void PnlWznmRelDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFREL) {
		recRel.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFREL, jref);
		refreshRecRel(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmRelDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFRSVIEWCLICK) {
					handleDpchAppDoButFrsViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTOSVIEWCLICK) {
					handleDpchAppDoButTosViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPTEDITCLICK) {
					handleDpchAppDoButOptEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmRelDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmRelDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFPFX})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFPFX)) contiac.TxfPfx = _contiac->TxfPfx;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbswznm, moditems);
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

void PnlWznmRelDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmRelDetail::handleDpchAppDoButFrsViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButFrsViewAvail && statshr.ButFrsViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmSbs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recRel.frsRefWznmMSubset, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmRelDetail::handleDpchAppDoButTosViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButTosViewAvail && statshr.ButTosViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmSbs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recRel.tosRefWznmMSubset, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmRelDetail::handleDpchAppDoButCluViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWznmRelDetail::handleDpchAppDoButCluClusterClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWznmRelDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWznmRelDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recRel.refWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmRelDetail::handleDpchAppDoButSupViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmRel";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recRel.supRefWznmMRelation, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmRelDetail::handleDpchAppDoButOptEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButOptEditClick --- INSERT
};

void PnlWznmRelDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMRELMOD_CLUEQ) {
		call->abort = handleCallWznmRelMod_cluEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRELUPD_REFEQ) {
		call->abort = handleCallWznmRelUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_TOSEQ) {
		call->abort = handleCallWznmRel_tosEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_FRSEQ) {
		call->abort = handleCallWznmRel_frsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_VEREQ) {
		call->abort = handleCallWznmRel_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_SUPEQ) {
		call->abort = handleCallWznmRel_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_CLUEQ) {
		call->abort = handleCallWznmRel_cluEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmRelDetail::handleCallWznmRelMod_cluEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmRelDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKMRELATIONOPTION) {
		refreshOpt(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmRelDetail::handleCallWznmRelUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmRelUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmRelDetail::handleCallWznmRel_tosEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.tosRefWznmMSubset == refInv); // IP handleCallWznmRel_tosEq --- LINE
	return retval;
};

bool PnlWznmRelDetail::handleCallWznmRel_frsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.frsRefWznmMSubset == refInv); // IP handleCallWznmRel_frsEq --- LINE
	return retval;
};

bool PnlWznmRelDetail::handleCallWznmRel_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.refWznmMVersion == refInv); // IP handleCallWznmRel_verEq --- LINE
	return retval;
};

bool PnlWznmRelDetail::handleCallWznmRel_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.supRefWznmMRelation == refInv); // IP handleCallWznmRel_supEq --- LINE
	return retval;
};

bool PnlWznmRelDetail::handleCallWznmRel_cluEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.refWznmCRelation == refInv); // IP handleCallWznmRel_cluEq --- LINE
	return retval;
};

