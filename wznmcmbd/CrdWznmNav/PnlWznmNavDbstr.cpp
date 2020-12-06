/**
	* \file PnlWznmNavDbstr.cpp
	* job handler for job PnlWznmNavDbstr (implementation)
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

#include "PnlWznmNavDbstr.h"

#include "PnlWznmNavDbstr_blks.cpp"
#include "PnlWznmNavDbstr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmNavDbstr
 ******************************************************************************/

PnlWznmNavDbstr::PnlWznmNavDbstr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMNAVDBSTR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstChk.tag = "FeedFLstChk";
	feedFLstIel.tag = "FeedFLstIel";
	feedFLstIex.tag = "FeedFLstIex";
	feedFLstIme.tag = "FeedFLstIme";
	feedFLstRel.tag = "FeedFLstRel";
	feedFLstSbs.tag = "FeedFLstSbs";
	feedFLstStb.tag = "FeedFLstStb";
	feedFLstTbl.tag = "FeedFLstTbl";
	feedFLstTco.tag = "FeedFLstTco";
	feedFLstVec.tag = "FeedFLstVec";
	feedFLstVit.tag = "FeedFLstVit";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshTbl(dbswznm, moditems);
	refreshTco(dbswznm, moditems);
	refreshSbs(dbswznm, moditems);
	refreshRel(dbswznm, moditems);
	refreshVec(dbswznm, moditems);
	refreshVit(dbswznm, moditems);
	refreshChk(dbswznm, moditems);
	refreshStb(dbswznm, moditems);
	refreshIex(dbswznm, moditems);
	refreshIme(dbswznm, moditems);
	refreshIel(dbswznm, moditems);
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMTBL, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMTCO, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMSBS, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMREL, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMVEC, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMVIT, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMCHK, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMSTB, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMIEX, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMIME, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMIEL, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
};

PnlWznmNavDbstr::~PnlWznmNavDbstr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmNavDbstr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstChk, &feedFLstIel, &feedFLstIex, &feedFLstIme, &feedFLstRel, &feedFLstSbs, &feedFLstStb, &feedFLstTbl, &feedFLstTco, &feedFLstVec, &feedFLstVit, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmNavDbstr::refreshLstTbl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstTblAvail = evalLstTblAvail(dbswznm);
	statshr.ButTblViewActive = evalButTblViewActive(dbswznm);
	statshr.ButTblNewcrdActive = evalButTblNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshTbl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstTbl = 0;

	// feedFLstTbl
	feedFLstTbl.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMTBL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstTbl.appendRefTitles(rec->ref, StubWznm::getStubTblStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTTBL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstTbl(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstTco(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstTcoAvail = evalLstTcoAvail(dbswznm);
	statshr.ButTcoViewActive = evalButTcoViewActive(dbswznm);
	statshr.ButTcoNewcrdActive = evalButTcoNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshTco(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstTco = 0;

	// feedFLstTco
	feedFLstTco.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMTCO, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstTco.appendRefTitles(rec->ref, StubWznm::getStubTcoStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTTCO);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstTco(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstSbs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSbsAvail = evalLstSbsAvail(dbswznm);
	statshr.ButSbsViewActive = evalButSbsViewActive(dbswznm);
	statshr.ButSbsNewcrdActive = evalButSbsNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshSbs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSbs = 0;

	// feedFLstSbs
	feedFLstSbs.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMSBS, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstSbs.appendRefTitles(rec->ref, StubWznm::getStubSbsStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSBS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSbs(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstRel(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRelAvail = evalLstRelAvail(dbswznm);
	statshr.ButRelViewActive = evalButRelViewActive(dbswznm);
	statshr.ButRelNewcrdActive = evalButRelNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshRel(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstRel = 0;

	// feedFLstRel
	feedFLstRel.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMREL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstRel.appendRefTitles(rec->ref, StubWznm::getStubRelStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTREL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstRel(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstVec(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstVecAvail = evalLstVecAvail(dbswznm);
	statshr.ButVecViewActive = evalButVecViewActive(dbswznm);
	statshr.ButVecNewcrdActive = evalButVecNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshVec(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstVec = 0;

	// feedFLstVec
	feedFLstVec.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMVEC, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstVec.appendRefTitles(rec->ref, StubWznm::getStubVecStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTVEC);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstVec(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstVit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstVitAvail = evalLstVitAvail(dbswznm);
	statshr.ButVitViewActive = evalButVitViewActive(dbswznm);
	statshr.ButVitNewcrdActive = evalButVitNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshVit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstVit = 0;

	// feedFLstVit
	feedFLstVit.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMVIT, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstVit.appendRefTitles(rec->ref, StubWznm::getStubVitStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTVIT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstVit(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstChk(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstChkAvail = evalLstChkAvail(dbswznm);
	statshr.ButChkViewActive = evalButChkViewActive(dbswznm);
	statshr.ButChkNewcrdActive = evalButChkNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshChk(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstChk = 0;

	// feedFLstChk
	feedFLstChk.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMCHK, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstChk.appendRefTitles(rec->ref, StubWznm::getStubChkStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCHK);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstChk(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstStb(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstStbAvail = evalLstStbAvail(dbswznm);
	statshr.ButStbViewActive = evalButStbViewActive(dbswznm);
	statshr.ButStbNewcrdActive = evalButStbNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshStb(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstStb = 0;

	// feedFLstStb
	feedFLstStb.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMSTB, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstStb.appendRefTitles(rec->ref, StubWznm::getStubStbStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSTB);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstStb(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstIex(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstIexAvail = evalLstIexAvail(dbswznm);
	statshr.ButIexViewActive = evalButIexViewActive(dbswznm);
	statshr.ButIexNewcrdActive = evalButIexNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshIex(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstIex = 0;

	// feedFLstIex
	feedFLstIex.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMIEX, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstIex.appendRefTitles(rec->ref, StubWznm::getStubIexStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTIEX);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstIex(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstIme(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstImeAvail = evalLstImeAvail(dbswznm);
	statshr.ButImeViewActive = evalButImeViewActive(dbswznm);
	statshr.ButImeNewcrdActive = evalButImeNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshIme(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstIme = 0;

	// feedFLstIme
	feedFLstIme.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMIME, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstIme.appendRefTitles(rec->ref, StubWznm::getStubImeStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTIME);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstIme(dbswznm, moditems);
};

void PnlWznmNavDbstr::refreshLstIel(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstIelAvail = evalLstIelAvail(dbswznm);
	statshr.ButIelViewActive = evalButIelViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavDbstr::refreshIel(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstIel = 0;

	// feedFLstIel
	feedFLstIel.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMIEL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstIel.appendRefTitles(rec->ref, StubWznm::getStubIelStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTIEL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstIel(dbswznm, moditems);
};

void PnlWznmNavDbstr::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWznmNavDbstr::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswznm, moditems);

	refreshLstTbl(dbswznm, moditems);
	refreshLstTco(dbswznm, moditems);
	refreshLstSbs(dbswznm, moditems);
	refreshLstRel(dbswznm, moditems);
	refreshLstVec(dbswznm, moditems);
	refreshLstVit(dbswznm, moditems);
	refreshLstChk(dbswznm, moditems);
	refreshLstStb(dbswznm, moditems);
	refreshLstIex(dbswznm, moditems);
	refreshLstIme(dbswznm, moditems);
	refreshLstIel(dbswznm, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWznmNavDbstr::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVDBSTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVDBSTRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTTBLVIEWCLICK) {
					handleDpchAppDoButTblViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTBLNEWCRDCLICK) {
					handleDpchAppDoButTblNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTCOVIEWCLICK) {
					handleDpchAppDoButTcoViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTCONEWCRDCLICK) {
					handleDpchAppDoButTcoNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSBSVIEWCLICK) {
					handleDpchAppDoButSbsViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSBSNEWCRDCLICK) {
					handleDpchAppDoButSbsNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRELVIEWCLICK) {
					handleDpchAppDoButRelViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRELNEWCRDCLICK) {
					handleDpchAppDoButRelNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVECVIEWCLICK) {
					handleDpchAppDoButVecViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVECNEWCRDCLICK) {
					handleDpchAppDoButVecNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVITVIEWCLICK) {
					handleDpchAppDoButVitViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVITNEWCRDCLICK) {
					handleDpchAppDoButVitNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCHKVIEWCLICK) {
					handleDpchAppDoButChkViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCHKNEWCRDCLICK) {
					handleDpchAppDoButChkNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTBVIEWCLICK) {
					handleDpchAppDoButStbViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTBNEWCRDCLICK) {
					handleDpchAppDoButStbNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIEXVIEWCLICK) {
					handleDpchAppDoButIexViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIEXNEWCRDCLICK) {
					handleDpchAppDoButIexNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIMEVIEWCLICK) {
					handleDpchAppDoButImeViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIMENEWCRDCLICK) {
					handleDpchAppDoButImeNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIELVIEWCLICK) {
					handleDpchAppDoButIelViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmNavDbstr::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmNavDbstr::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTTBL)) {
		contiac.numFLstTbl = _contiac->numFLstTbl;
		refreshLstTbl(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTTCO)) {
		contiac.numFLstTco = _contiac->numFLstTco;
		refreshLstTco(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSBS)) {
		contiac.numFLstSbs = _contiac->numFLstSbs;
		refreshLstSbs(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTREL)) {
		contiac.numFLstRel = _contiac->numFLstRel;
		refreshLstRel(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTVEC)) {
		contiac.numFLstVec = _contiac->numFLstVec;
		refreshLstVec(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTVIT)) {
		contiac.numFLstVit = _contiac->numFLstVit;
		refreshLstVit(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCHK)) {
		contiac.numFLstChk = _contiac->numFLstChk;
		refreshLstChk(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSTB)) {
		contiac.numFLstStb = _contiac->numFLstStb;
		refreshLstStb(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTIEX)) {
		contiac.numFLstIex = _contiac->numFLstIex;
		refreshLstIex(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTIME)) {
		contiac.numFLstIme = _contiac->numFLstIme;
		refreshLstIme(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTIEL)) {
		contiac.numFLstIel = _contiac->numFLstIel;
		refreshLstIel(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmNavDbstr::handleDpchAppDoButTblViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstTblAvail && statshr.ButTblViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstTbl.getRefByNum(contiac.numFLstTbl), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmTbl", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmTbl");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButTblNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButTblNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmTbl", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmTbl");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButTcoViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstTcoAvail && statshr.ButTcoViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstTco.getRefByNum(contiac.numFLstTco), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmTco", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmTco");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButTcoNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButTcoNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmTco", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmTco");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButSbsViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSbsAvail && statshr.ButSbsViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstSbs.getRefByNum(contiac.numFLstSbs), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmSbs", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmSbs");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButSbsNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButSbsNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmSbs", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmSbs");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButRelViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstRelAvail && statshr.ButRelViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstRel.getRefByNum(contiac.numFLstRel), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmRel", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmRel");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButRelNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButRelNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmRel", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmRel");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButVecViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstVecAvail && statshr.ButVecViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstVec.getRefByNum(contiac.numFLstVec), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmVec", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVec");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButVecNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButVecNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmVec", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVec");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButVitViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstVitAvail && statshr.ButVitViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstVit.getRefByNum(contiac.numFLstVit), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmVit", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVit");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButVitNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButVitNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmVit", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVit");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButChkViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstChkAvail && statshr.ButChkViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstChk.getRefByNum(contiac.numFLstChk), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmChk", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmChk");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButChkNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButChkNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmChk", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmChk");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButStbViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstStbAvail && statshr.ButStbViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstStb.getRefByNum(contiac.numFLstStb), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmStb", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmStb");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButStbNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButStbNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmStb", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmStb");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButIexViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstIexAvail && statshr.ButIexViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstIex.getRefByNum(contiac.numFLstIex), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmIex", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmIex");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButIexNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButIexNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmIex", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmIex");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButImeViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstImeAvail && statshr.ButImeViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstIme.getRefByNum(contiac.numFLstIme), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmIme", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmIme");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButImeNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButImeNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmIme", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmIme");
	};
};

void PnlWznmNavDbstr::handleDpchAppDoButIelViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstIelAvail && statshr.ButIelViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstIel.getRefByNum(contiac.numFLstIel), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmIel", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmIel");
	};
};

void PnlWznmNavDbstr::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWznmHusrRunvMod_crdUsrEq(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWznmNavDbstr::handleCallWznmHusrRunvMod_crdUsrEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVCard::CRDWZNMTBL) {
		refreshTbl(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMTCO) {
		refreshTco(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMSBS) {
		refreshSbs(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMREL) {
		refreshRel(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMVEC) {
		refreshVec(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMVIT) {
		refreshVit(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMCHK) {
		refreshChk(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMSTB) {
		refreshStb(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMIEX) {
		refreshIex(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMIME) {
		refreshIme(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMIEL) {
		refreshIel(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
