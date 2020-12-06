/**
	* \file PnlWznmConDetail.cpp
	* job handler for job PnlWznmConDetail (implementation)
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

#include "PnlWznmConDetail.h"

#include "PnlWznmConDetail_blks.cpp"
#include "PnlWznmConDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmConDetail
 ******************************************************************************/

PnlWznmConDetail::PnlWznmConDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMCONDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFLstFedTag.tag = "FeedFLstFedTag";
	feedFLstFedVit.tag = "FeedFLstFedVit";
	feedFLstOpt.tag = "FeedFLstOpt";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMCONTROLOPTION, ixWznmVLocale, feedFLstOpt);
	feedFLstTag.tag = "FeedFLstTag";
	feedFPupFedSrt.tag = "FeedFPupFedSrt";
	VecWznmVMFeedSrcTbl::fillFeed(ixWznmVLocale, feedFPupFedSrt);
	feedFPupHkt.tag = "FeedFPupHkt";
	VecWznmVMControlHkTbl::fillFeed(ixWznmVLocale, feedFPupHkt);
	feedFPupJti.tag = "FeedFPupJti";
	feedFPupRet.tag = "FeedFPupRet";
	VecWznmVMControlRefTbl::fillFeed(ixWznmVLocale, feedFPupRet);
	feedFPupSco.tag = "FeedFPupSco";
	VecWznmVMControlScope::fillFeed(ixWznmVLocale, feedFPupSco);
	feedFPupSty.tag = "FeedFPupSty";
	VecWznmVMControlSubtype::fillFeed(ixWznmVLocale, feedFPupSty);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWznmVMControlBasetype::fillFeed(ixWznmVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMFED_SRUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMFED_SRTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_STSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_SHSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_FEDEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCON_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMCONTROLOPTION);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFCON, jref);
};

PnlWznmConDetail::~PnlWznmConDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmConDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFLstFedTag, &feedFLstFedVit, &feedFLstOpt, &feedFLstTag, &feedFPupFedSrt, &feedFPupHkt, &feedFPupJti, &feedFPupRet, &feedFPupSco, &feedFPupSty, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmConDetail::refreshJti(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMControlTitle conJtits;
	WznmJMControlTitle* conJtit = NULL;

	string s;

	// feedFPupJti
	feedFPupJti.clear();

	dbswznm->tblwznmjmcontroltitle->loadRstByCon(recCon.ref, false, conJtits);

	for (unsigned int i = 0; i < conJtits.nodes.size(); i++) {
		conJtit = conJtits.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, conJtit->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupJti.appendRefTitles(conJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJTI);

	refreshRecConJtit(dbswznm, moditems);

};

void PnlWznmConDetail::refreshLstClu(
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

void PnlWznmConDetail::refreshClu(
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

	if (recCon.refWznmCControl != 0) dbswznm->tblwznmmcontrol->loadRefsByClu(recCon.refWznmCControl, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recCon.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWznm::getStubConStd(dbswznm, refs[i], ixWznmVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWznm::getStubConStd(dbswznm, refs[i], ixWznmVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswznm, moditems);
};

void PnlWznmConDetail::refreshLstTag(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstTagActive = evalLstTagActive(dbswznm);
	statshr.ButTagViewAvail = evalButTagViewAvail(dbswznm);
	statshr.ButTagViewActive = evalButTagViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmConDetail::refreshTag(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	vector<string> ss;

	// contiac
	contiac.numFLstTag = 0;

	// feedFLstTag
	feedFLstTag.clear();

	StrMod::stringToVector(contiac.TxfTag, ss);

	// IP refreshTag.validate --- INSERT

	// statshr
	statshr.TxfTagValid = (ss.size() == feedFLstTag.size());

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmConDetail::refreshLstOpt(
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

void PnlWznmConDetail::refreshTxfOpt(
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

void PnlWznmConDetail::refreshOpt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFLstOpt
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMCONTROLOPTION, ixWznmVLocale, feedFLstOpt);

	insert(moditems, DpchEngData::FEEDFLSTOPT);

	refreshLstOpt(dbswznm, moditems);
};

void PnlWznmConDetail::refreshLstFedVit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFedVitAvail = evalLstFedVitAvail(dbswznm);
	statshr.LstFedVitActive = evalLstFedVitActive(dbswznm);
	statshr.ButFedVitViewAvail = evalButFedVitViewAvail(dbswznm);
	statshr.ButFedVitViewActive = evalButFedVitViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmConDetail::refreshFedVit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	vector<string> ss;

	// contiac
	contiac.numFLstFedVit = 0;

	// feedFLstFedVit
	feedFLstFedVit.clear();

	StrMod::stringToVector(contiac.TxfFedVit, ss);

	// IP refreshFedVit.validate --- INSERT

	// statshr
	statshr.TxfFedVitValid = (ss.size() == feedFLstFedVit.size());

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmConDetail::refreshLstFedTag(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFedTagAvail = evalLstFedTagAvail(dbswznm);
	statshr.LstFedTagActive = evalLstFedTagActive(dbswznm);
	statshr.ButFedTagViewAvail = evalButFedTagViewAvail(dbswznm);
	statshr.ButFedTagViewActive = evalButFedTagViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmConDetail::refreshFedTag(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	vector<string> ss;

	// contiac
	contiac.numFLstFedTag = 0;

	// feedFLstFedTag
	feedFLstFedTag.clear();

	StrMod::stringToVector(contiac.TxfFedTag, ss);

	// IP refreshFedTag.validate --- INSERT

	// statshr
	statshr.TxfFedTagValid = (ss.size() == feedFLstFedTag.size());

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmConDetail::refreshRecCon(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMControl* _recCon = NULL;

	if (dbswznm->tblwznmmcontrol->loadRecByRef(recCon.ref, &_recCon)) {
		recCon = *_recCon;
		ixWSubsetCon = dbswznm->getIxWSubsetByWznmMControl(_recCon);
		delete _recCon;
	} else {
		recCon = WznmMControl();
		ixWSubsetCon = 0;
	};

	dirty = false;

	recFed.ref = recCon.refWznmMFeed;

	recConJ.ref = recCon.refJ;
	if (recCon.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMCONJMOD_CONEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMCONJMOD_CONEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recCon.ref);

	recConJtit.ref = recCon.refJTitle;
	if (recCon.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMCONJTITMOD_CONEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMCONJTITMOD_CONEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recCon.ref);

	if (recCon.refWznmCControl == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMCONMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMCONMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recCon.refWznmCControl);

	continf.TxtSrf = recCon.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recCon.ixVBasetype);
	contiac.numFPupHkt = feedFPupHkt.getNumByIx(recCon.hkIxVTbl);
	if (recCon.hkIxVTbl == VecWznmVMControlHkTbl::CAR) continf.TxtHku = StubWznm::getStubCarStd(dbswznm, recCon.hkUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recCon.hkIxVTbl == VecWznmVMControlHkTbl::DLG) continf.TxtHku = StubWznm::getStubDlgStd(dbswznm, recCon.hkUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recCon.hkIxVTbl == VecWznmVMControlHkTbl::PNL) continf.TxtHku = StubWznm::getStubPnlStd(dbswznm, recCon.hkUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtHku = "-";
	contiac.numFPupRet = feedFPupRet.getNumByIx(recCon.refIxVTbl);
	if (recCon.refIxVTbl == VecWznmVMControlRefTbl::DLG) continf.TxtReu = StubWznm::getStubDlgStd(dbswznm, recCon.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recCon.refIxVTbl == VecWznmVMControlRefTbl::QCO) continf.TxtReu = StubWznm::getStubQcoStd(dbswznm, recCon.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recCon.refIxVTbl == VecWznmVMControlRefTbl::REL) continf.TxtReu = StubWznm::getStubRelStd(dbswznm, recCon.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recCon.refIxVTbl == VecWznmVMControlRefTbl::TCO) continf.TxtReu = StubWznm::getStubTcoStd(dbswznm, recCon.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	continf.TxtSup = StubWznm::getStubConStd(dbswznm, recCon.supRefWznmMControl, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupSco = feedFPupSco.getNumByIx(recCon.ixVScope);
	contiac.numFPupSty = feedFPupSty.getNumByIx(recCon.ixVSubtype);
	contiac.TxfTag = recCon.srefsWznmMTag;
	continf.TxtSts = StubWznm::getStubStbStd(dbswznm, recCon.stdRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtShs = StubWznm::getStubStbStd(dbswznm, recCon.shoRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfAvl = recCon.Avail;
	contiac.TxfAct = recCon.Active;
	contiac.TxfOpt = recCon.srefsKOption;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.PupTypActive = evalPupTypActive(dbswznm);
	statshr.TxtHkuActive = evalTxtHkuActive(dbswznm);
	statshr.ButHkuViewAvail = evalButHkuViewAvail(dbswznm);
	statshr.ButHkuViewActive = evalButHkuViewActive(dbswznm);
	statshr.TxtReuActive = evalTxtReuActive(dbswznm);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswznm);
	statshr.ButReuViewActive = evalButReuViewActive(dbswznm);
	statshr.TxtSupActive = evalTxtSupActive(dbswznm);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbswznm);
	statshr.ButSupViewActive = evalButSupViewActive(dbswznm);
	statshr.PupScoActive = evalPupScoActive(dbswznm);
	statshr.PupStyActive = evalPupStyActive(dbswznm);
	statshr.TxtStsActive = evalTxtStsActive(dbswznm);
	statshr.ButStsViewAvail = evalButStsViewAvail(dbswznm);
	statshr.ButStsViewActive = evalButStsViewActive(dbswznm);
	statshr.TxtShsActive = evalTxtShsActive(dbswznm);
	statshr.ButShsViewAvail = evalButShsViewAvail(dbswznm);
	statshr.ButShsViewActive = evalButShsViewActive(dbswznm);
	statshr.TxfAvlActive = evalTxfAvlActive(dbswznm);
	statshr.TxfActActive = evalTxfActActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecFed(dbswznm, moditems);

	refreshJti(dbswznm, moditems);
	refreshClu(dbswznm, moditems);
	refreshTag(dbswznm, moditems);
	refreshLstOpt(dbswznm, moditems);

};

void PnlWznmConDetail::refreshRecFed(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMFeed* _recFed = NULL;

	if (dbswznm->tblwznmmfeed->loadRecByRef(recFed.ref, &_recFed)) {
		recFed = *_recFed;
		delete _recFed;
	} else recFed = WznmMFeed();

	continf.TxtFedSrf = recFed.sref;
	contiac.numFPupFedSrt = feedFPupFedSrt.getNumByIx(recFed.srcIxVTbl);
	if (recFed.srcIxVTbl == VecWznmVMFeedSrcTbl::VEC) continf.TxtFedSru = StubWznm::getStubVecStd(dbswznm, recFed.srcUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recFed.srcIxVTbl == VecWznmVMFeedSrcTbl::TBL) continf.TxtFedSru = StubWznm::getStubTblStd(dbswznm, recFed.srcUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtFedSru = "-";
	contiac.TxfFedVit = recFed.srefsWznmMVectoritem;
	contiac.TxfFedTag = recFed.srefsWznmMTag;
	contiac.TxfFedCmt = recFed.Comment;

	statshr.SepFedAvail = evalSepFedAvail(dbswznm);
	statshr.HdgFedAvail = evalHdgFedAvail(dbswznm);
	statshr.ButFedNewAvail = evalButFedNewAvail(dbswznm);
	statshr.ButFedDeleteAvail = evalButFedDeleteAvail(dbswznm);
	statshr.TxtFedSrfAvail = evalTxtFedSrfAvail(dbswznm);
	statshr.TxtFedSrfActive = evalTxtFedSrfActive(dbswznm);
	statshr.TxtFedSruAvail = evalTxtFedSruAvail(dbswznm);
	statshr.TxtFedSruActive = evalTxtFedSruActive(dbswznm);
	statshr.ButFedSruViewAvail = evalButFedSruViewAvail(dbswznm);
	statshr.ButFedSruViewActive = evalButFedSruViewActive(dbswznm);
	statshr.TxfFedCmtAvail = evalTxfFedCmtAvail(dbswznm);
	statshr.TxfFedCmtActive = evalTxfFedCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshFedVit(dbswznm, moditems);
	refreshFedTag(dbswznm, moditems);

};

void PnlWznmConDetail::refreshRecConJ(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMControl* _recConJ = NULL;

	if (dbswznm->tblwznmjmcontrol->loadRecByRef(recConJ.ref, &_recConJ)) {
		recConJ = *_recConJ;
		delete _recConJ;
	} else recConJ = WznmJMControl();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmConDetail::refreshRecConJtit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMControlTitle* _recConJtit = NULL;

	if (dbswznm->tblwznmjmcontroltitle->loadRecByRef(recConJtit.ref, &_recConJtit)) {
		recConJtit = *_recConJtit;
		delete _recConJtit;
	} else recConJtit = WznmJMControlTitle();

	contiac.numFPupJti = feedFPupJti.getNumByRef(recConJtit.ref);
	continf.TxtTit = recConJtit.Title;

	statshr.PupJtiActive = evalPupJtiActive(dbswznm);
	statshr.ButJtiEditAvail = evalButJtiEditAvail(dbswznm);
	statshr.TxtTitActive = evalTxtTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmConDetail::refresh(
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

void PnlWznmConDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCON) {
		recCon.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCON, jref);
		refreshRecCon(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmConDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJTIEDITCLICK) {
					handleDpchAppDoButJtiEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHKUVIEWCLICK) {
					handleDpchAppDoButHkuViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTAGVIEWCLICK) {
					handleDpchAppDoButTagViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTSVIEWCLICK) {
					handleDpchAppDoButStsViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSHSVIEWCLICK) {
					handleDpchAppDoButShsViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPTEDITCLICK) {
					handleDpchAppDoButOptEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFEDNEWCLICK) {
					handleDpchAppDoButFedNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFEDDELETECLICK) {
					handleDpchAppDoButFedDeleteClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFEDSRUVIEWCLICK) {
					handleDpchAppDoButFedSruViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFEDVITVIEWCLICK) {
					handleDpchAppDoButFedVitViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFEDTAGVIEWCLICK) {
					handleDpchAppDoButFedTagViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmConDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmConDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::NUMFPUPSCO, ContIac::NUMFPUPSTY, ContIac::TXFAVL, ContIac::TXFACT, ContIac::TXFFEDCMT})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::NUMFPUPSCO)) contiac.numFPupSco = _contiac->numFPupSco;
		if (has(diffitems, ContIac::NUMFPUPSTY)) contiac.numFPupSty = _contiac->numFPupSty;
		if (has(diffitems, ContIac::TXFAVL)) contiac.TxfAvl = _contiac->TxfAvl;
		if (has(diffitems, ContIac::TXFACT)) contiac.TxfAct = _contiac->TxfAct;
		if (has(diffitems, ContIac::TXFFEDCMT)) contiac.TxfFedCmt = _contiac->TxfFedCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJTI)) {
		recConJtit.ref = feedFPupJti.getRefByNum(_contiac->numFPupJti);
		refreshRecConJtit(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFTAG)) {
		contiac.TxfTag = _contiac->TxfTag;
		refreshTag(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFLSTTAG)) {
		contiac.numFLstTag = _contiac->numFLstTag;
		refreshLstTag(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFOPT)) {
		contiac.TxfOpt = _contiac->TxfOpt;
		refreshLstOpt(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMSFLSTOPT)) {
		contiac.numsFLstOpt = _contiac->numsFLstOpt;
		refreshTxfOpt(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFFEDVIT)) {
		contiac.TxfFedVit = _contiac->TxfFedVit;
		refreshFedVit(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFLSTFEDVIT)) {
		contiac.numFLstFedVit = _contiac->numFLstFedVit;
		refreshLstFedVit(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFFEDTAG)) {
		contiac.TxfFedTag = _contiac->TxfFedTag;
		refreshFedTag(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFLSTFEDTAG)) {
		contiac.numFLstFedTag = _contiac->numFLstFedTag;
		refreshLstFedTag(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmConDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJtiEditClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButCluViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButCluClusterClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButHkuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButHkuViewAvail && statshr.ButHkuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref)) if (recCon.hkIxVTbl == VecWznmVMControlHkTbl::CAR) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmCar";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.hkUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref)) if (recCon.hkIxVTbl == VecWznmVMControlHkTbl::DLG) if (ixPre == VecWznmVPreset::PREWZNMREFCAR) {
				sref = "CrdWznmDlg";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.hkUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref)) if (recCon.hkIxVTbl == VecWznmVMControlHkTbl::DLG) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmDlg";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.hkUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref)) if (recCon.hkIxVTbl == VecWznmVMControlHkTbl::PNL) if (ixPre == VecWznmVPreset::PREWZNMREFCAR) {
				sref = "CrdWznmPnl";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.hkUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref)) if (recCon.hkIxVTbl == VecWznmVMControlHkTbl::PNL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmPnl";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.hkUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmConDetail::handleDpchAppDoButReuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref)) if (recCon.refIxVTbl == VecWznmVMControlRefTbl::REL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmRel";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref)) if (recCon.refIxVTbl == VecWznmVMControlRefTbl::QCO) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmQco";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref)) if (recCon.refIxVTbl == VecWznmVMControlRefTbl::DLG) if (ixPre == VecWznmVPreset::PREWZNMREFCAR) {
				sref = "CrdWznmDlg";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref)) if (recCon.refIxVTbl == VecWznmVMControlRefTbl::DLG) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmDlg";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmConDetail::handleDpchAppDoButSupViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFPNL) {
			sref = "CrdWznmCon";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.supRefWznmMControl, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFDLG) {
				sref = "CrdWznmCon";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.supRefWznmMControl, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFCAR) {
				sref = "CrdWznmCon";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.supRefWznmMControl, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmCon";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.supRefWznmMControl, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmConDetail::handleDpchAppDoButTagViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButTagViewClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButStsViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButStsViewAvail && statshr.ButStsViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmStb";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.stdRefWznmMStub, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmConDetail::handleDpchAppDoButShsViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButShsViewAvail && statshr.ButShsViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmStb";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recCon.shoRefWznmMStub, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmConDetail::handleDpchAppDoButOptEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButOptEditClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButFedNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButFedNewClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButFedDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButFedDeleteClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButFedSruViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButFedSruViewAvail && statshr.ButFedSruViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref)) if (recFed.srcIxVTbl == VecWznmVMFeedSrcTbl::VEC) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
			sref = "CrdWznmVec";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recFed.srcUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref)) if (recFed.srcIxVTbl == VecWznmVMFeedSrcTbl::TBL) if (ixPre == VecWznmVPreset::PREWZNMREFVER) {
				sref = "CrdWznmTbl";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recFed.srcUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmConDetail::handleDpchAppDoButFedVitViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButFedVitViewClick --- INSERT
};

void PnlWznmConDetail::handleDpchAppDoButFedTagViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButFedTagViewClick --- INSERT
};

void PnlWznmConDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMFED_SRUEQ) {
		call->abort = handleCallWznmFed_sruEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFED_SRTEQ) {
		call->abort = handleCallWznmFed_srtEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_TYPEQ) {
		call->abort = handleCallWznmCon_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_SUPEQ) {
		call->abort = handleCallWznmCon_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_STSEQ) {
		call->abort = handleCallWznmCon_stsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_SHSEQ) {
		call->abort = handleCallWznmCon_shsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_REUEQ) {
		call->abort = handleCallWznmCon_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_RETEQ) {
		call->abort = handleCallWznmCon_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_INSBS) {
		call->abort = handleCallWznmCon_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_HKUEQ) {
		call->abort = handleCallWznmCon_hkuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_HKTEQ) {
		call->abort = handleCallWznmCon_hktEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_FEDEQ) {
		call->abort = handleCallWznmCon_fedEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCON_CLUEQ) {
		call->abort = handleCallWznmCon_cluEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCONUPD_REFEQ) {
		call->abort = handleCallWznmConUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFEDUPD_REFEQ) {
		call->abort = handleCallWznmFedUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCONJMOD_CONEQ) {
		call->abort = handleCallWznmConJMod_conEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCONJTITMOD_CONEQ) {
		call->abort = handleCallWznmConJtitMod_conEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCONMOD_CLUEQ) {
		call->abort = handleCallWznmConMod_cluEq(dbswznm, call->jref);
	};
};

bool PnlWznmConDetail::handleCallWznmFed_sruEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFed.srcUref == refInv); // IP handleCallWznmFed_sruEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmFed_srtEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFed.srcIxVTbl == ixInv); // IP handleCallWznmFed_srtEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.ixVBasetype == ixInv); // IP handleCallWznmCon_typEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.supRefWznmMControl == refInv); // IP handleCallWznmCon_supEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_stsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.stdRefWznmMStub == refInv); // IP handleCallWznmCon_stsEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_shsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.shoRefWznmMStub == refInv); // IP handleCallWznmCon_shsEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.refUref == refInv); // IP handleCallWznmCon_reuEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.refIxVTbl == ixInv); // IP handleCallWznmCon_retEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetCon & ixInv) != 0); // IP handleCallWznmCon_inSbs --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_hkuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.hkUref == refInv); // IP handleCallWznmCon_hkuEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_hktEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.hkIxVTbl == ixInv); // IP handleCallWznmCon_hktEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_fedEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.refWznmMFeed == refInv); // IP handleCallWznmCon_fedEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmCon_cluEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCon.refWznmCControl == refInv); // IP handleCallWznmCon_cluEq --- LINE
	return retval;
};

bool PnlWznmConDetail::handleCallWznmConUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmConUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmConDetail::handleCallWznmFedUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmFedUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmConDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKMCONTROLOPTION) {
		refreshOpt(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmConDetail::handleCallWznmConJMod_conEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmConJMod_conEq --- INSERT
	return retval;
};

bool PnlWznmConDetail::handleCallWznmConJtitMod_conEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmConDetail::handleCallWznmConMod_cluEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
