/**
	* \file PnlWznmNavUix.cpp
	* job handler for job PnlWznmNavUix (implementation)
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

#include "PnlWznmNavUix.h"

#include "PnlWznmNavUix_blks.cpp"
#include "PnlWznmNavUix_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmNavUix
 ******************************************************************************/

PnlWznmNavUix::PnlWznmNavUix(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMNAVUIX, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstCar.tag = "FeedFLstCar";
	feedFLstCon.tag = "FeedFLstCon";
	feedFLstDlg.tag = "FeedFLstDlg";
	feedFLstMdl.tag = "FeedFLstMdl";
	feedFLstPnl.tag = "FeedFLstPnl";
	feedFLstPst.tag = "FeedFLstPst";
	feedFLstQco.tag = "FeedFLstQco";
	feedFLstQmd.tag = "FeedFLstQmd";
	feedFLstQry.tag = "FeedFLstQry";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshPst(dbswznm, moditems);
	refreshMdl(dbswznm, moditems);
	refreshCar(dbswznm, moditems);
	refreshDlg(dbswznm, moditems);
	refreshPnl(dbswznm, moditems);
	refreshQry(dbswznm, moditems);
	refreshQco(dbswznm, moditems);
	refreshQmd(dbswznm, moditems);
	refreshCon(dbswznm, moditems);
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMPST, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMMDL, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMCAR, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMDLG, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMPNL, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMQRY, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMQCO, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMQMD, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMCON, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
};

PnlWznmNavUix::~PnlWznmNavUix() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmNavUix::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstCar, &feedFLstCon, &feedFLstDlg, &feedFLstMdl, &feedFLstPnl, &feedFLstPst, &feedFLstQco, &feedFLstQmd, &feedFLstQry, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmNavUix::refreshLstPst(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPstAvail = evalLstPstAvail(dbswznm);
	statshr.ButPstViewActive = evalButPstViewActive(dbswznm);
	statshr.ButPstNewcrdActive = evalButPstNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshPst(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPst = 0;

	// feedFLstPst
	feedFLstPst.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMPST, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPst.appendRefTitles(rec->ref, StubWznm::getStubPstStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPST);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPst(dbswznm, moditems);
};

void PnlWznmNavUix::refreshLstMdl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstMdlAvail = evalLstMdlAvail(dbswznm);
	statshr.ButMdlViewActive = evalButMdlViewActive(dbswznm);
	statshr.ButMdlNewcrdActive = evalButMdlNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshMdl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstMdl = 0;

	// feedFLstMdl
	feedFLstMdl.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMMDL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstMdl.appendRefTitles(rec->ref, StubWznm::getStubMdlStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTMDL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstMdl(dbswznm, moditems);
};

void PnlWznmNavUix::refreshLstCar(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCarAvail = evalLstCarAvail(dbswznm);
	statshr.ButCarViewActive = evalButCarViewActive(dbswznm);
	statshr.ButCarNewcrdActive = evalButCarNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshCar(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCar = 0;

	// feedFLstCar
	feedFLstCar.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMCAR, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstCar.appendRefTitles(rec->ref, StubWznm::getStubCarStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCAR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCar(dbswznm, moditems);
};

void PnlWznmNavUix::refreshLstDlg(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstDlgAvail = evalLstDlgAvail(dbswznm);
	statshr.ButDlgViewActive = evalButDlgViewActive(dbswznm);
	statshr.ButDlgNewcrdActive = evalButDlgNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshDlg(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstDlg = 0;

	// feedFLstDlg
	feedFLstDlg.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMDLG, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstDlg.appendRefTitles(rec->ref, StubWznm::getStubDlgStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTDLG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstDlg(dbswznm, moditems);
};

void PnlWznmNavUix::refreshLstPnl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPnlAvail = evalLstPnlAvail(dbswznm);
	statshr.ButPnlViewActive = evalButPnlViewActive(dbswznm);
	statshr.ButPnlNewcrdActive = evalButPnlNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshPnl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPnl = 0;

	// feedFLstPnl
	feedFLstPnl.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMPNL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPnl.appendRefTitles(rec->ref, StubWznm::getStubPnlStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPNL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPnl(dbswznm, moditems);
};

void PnlWznmNavUix::refreshLstQry(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstQryAvail = evalLstQryAvail(dbswznm);
	statshr.ButQryViewActive = evalButQryViewActive(dbswznm);
	statshr.ButQryNewcrdActive = evalButQryNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshQry(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstQry = 0;

	// feedFLstQry
	feedFLstQry.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMQRY, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstQry.appendRefTitles(rec->ref, StubWznm::getStubQryStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTQRY);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstQry(dbswznm, moditems);
};

void PnlWznmNavUix::refreshLstQco(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstQcoAvail = evalLstQcoAvail(dbswznm);
	statshr.ButQcoViewActive = evalButQcoViewActive(dbswznm);
	statshr.ButQcoNewcrdActive = evalButQcoNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshQco(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstQco = 0;

	// feedFLstQco
	feedFLstQco.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMQCO, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstQco.appendRefTitles(rec->ref, StubWznm::getStubQcoStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTQCO);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstQco(dbswznm, moditems);
};

void PnlWznmNavUix::refreshLstQmd(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstQmdAvail = evalLstQmdAvail(dbswznm);
	statshr.ButQmdViewActive = evalButQmdViewActive(dbswznm);
	statshr.ButQmdNewcrdActive = evalButQmdNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshQmd(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstQmd = 0;

	// feedFLstQmd
	feedFLstQmd.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMQMD, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstQmd.appendRefTitles(rec->ref, StubWznm::getStubQmdStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTQMD);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstQmd(dbswznm, moditems);
};

void PnlWznmNavUix::refreshLstCon(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstConAvail = evalLstConAvail(dbswznm);
	statshr.ButConViewActive = evalButConViewActive(dbswznm);
	statshr.ButConNewcrdActive = evalButConNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavUix::refreshCon(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCon = 0;

	// feedFLstCon
	feedFLstCon.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMCON, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstCon.appendRefTitles(rec->ref, StubWznm::getStubConStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCON);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCon(dbswznm, moditems);
};

void PnlWznmNavUix::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWznmNavUix::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswznm, moditems);

	refreshLstPst(dbswznm, moditems);
	refreshLstMdl(dbswznm, moditems);
	refreshLstCar(dbswznm, moditems);
	refreshLstDlg(dbswznm, moditems);
	refreshLstPnl(dbswznm, moditems);
	refreshLstQry(dbswznm, moditems);
	refreshLstQco(dbswznm, moditems);
	refreshLstQmd(dbswznm, moditems);
	refreshLstCon(dbswznm, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWznmNavUix::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVUIXDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVUIXDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTPSTVIEWCLICK) {
					handleDpchAppDoButPstViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTNEWCRDCLICK) {
					handleDpchAppDoButPstNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMDLVIEWCLICK) {
					handleDpchAppDoButMdlViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMDLNEWCRDCLICK) {
					handleDpchAppDoButMdlNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCARVIEWCLICK) {
					handleDpchAppDoButCarViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCARNEWCRDCLICK) {
					handleDpchAppDoButCarNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDLGVIEWCLICK) {
					handleDpchAppDoButDlgViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDLGNEWCRDCLICK) {
					handleDpchAppDoButDlgNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPNLVIEWCLICK) {
					handleDpchAppDoButPnlViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPNLNEWCRDCLICK) {
					handleDpchAppDoButPnlNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTQRYVIEWCLICK) {
					handleDpchAppDoButQryViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTQRYNEWCRDCLICK) {
					handleDpchAppDoButQryNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTQCOVIEWCLICK) {
					handleDpchAppDoButQcoViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTQCONEWCRDCLICK) {
					handleDpchAppDoButQcoNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTQMDVIEWCLICK) {
					handleDpchAppDoButQmdViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTQMDNEWCRDCLICK) {
					handleDpchAppDoButQmdNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCONVIEWCLICK) {
					handleDpchAppDoButConViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCONNEWCRDCLICK) {
					handleDpchAppDoButConNewcrdClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmNavUix::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmNavUix::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTPST)) {
		contiac.numFLstPst = _contiac->numFLstPst;
		refreshLstPst(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTMDL)) {
		contiac.numFLstMdl = _contiac->numFLstMdl;
		refreshLstMdl(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCAR)) {
		contiac.numFLstCar = _contiac->numFLstCar;
		refreshLstCar(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTDLG)) {
		contiac.numFLstDlg = _contiac->numFLstDlg;
		refreshLstDlg(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPNL)) {
		contiac.numFLstPnl = _contiac->numFLstPnl;
		refreshLstPnl(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTQRY)) {
		contiac.numFLstQry = _contiac->numFLstQry;
		refreshLstQry(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTQCO)) {
		contiac.numFLstQco = _contiac->numFLstQco;
		refreshLstQco(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTQMD)) {
		contiac.numFLstQmd = _contiac->numFLstQmd;
		refreshLstQmd(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCON)) {
		contiac.numFLstCon = _contiac->numFLstCon;
		refreshLstCon(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmNavUix::handleDpchAppDoButPstViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPstAvail && statshr.ButPstViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstPst.getRefByNum(contiac.numFLstPst), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmPst", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPst");
	};
};

void PnlWznmNavUix::handleDpchAppDoButPstNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButPstNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmPst", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPst");
	};
};

void PnlWznmNavUix::handleDpchAppDoButMdlViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstMdlAvail && statshr.ButMdlViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstMdl.getRefByNum(contiac.numFLstMdl), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmMdl", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmMdl");
	};
};

void PnlWznmNavUix::handleDpchAppDoButMdlNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButMdlNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmMdl", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmMdl");
	};
};

void PnlWznmNavUix::handleDpchAppDoButCarViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstCarAvail && statshr.ButCarViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstCar.getRefByNum(contiac.numFLstCar), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmCar", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCar");
	};
};

void PnlWznmNavUix::handleDpchAppDoButCarNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButCarNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCar", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCar");
	};
};

void PnlWznmNavUix::handleDpchAppDoButDlgViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstDlgAvail && statshr.ButDlgViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstDlg.getRefByNum(contiac.numFLstDlg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmDlg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmDlg");
	};
};

void PnlWznmNavUix::handleDpchAppDoButDlgNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButDlgNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmDlg", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmDlg");
	};
};

void PnlWznmNavUix::handleDpchAppDoButPnlViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPnlAvail && statshr.ButPnlViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstPnl.getRefByNum(contiac.numFLstPnl), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmPnl", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPnl");
	};
};

void PnlWznmNavUix::handleDpchAppDoButPnlNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButPnlNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmPnl", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPnl");
	};
};

void PnlWznmNavUix::handleDpchAppDoButQryViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstQryAvail && statshr.ButQryViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstQry.getRefByNum(contiac.numFLstQry), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmQry", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQry");
	};
};

void PnlWznmNavUix::handleDpchAppDoButQryNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButQryNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmQry", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQry");
	};
};

void PnlWznmNavUix::handleDpchAppDoButQcoViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstQcoAvail && statshr.ButQcoViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstQco.getRefByNum(contiac.numFLstQco), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmQco", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQco");
	};
};

void PnlWznmNavUix::handleDpchAppDoButQcoNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButQcoNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmQco", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQco");
	};
};

void PnlWznmNavUix::handleDpchAppDoButQmdViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstQmdAvail && statshr.ButQmdViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstQmd.getRefByNum(contiac.numFLstQmd), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmQmd", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQmd");
	};
};

void PnlWznmNavUix::handleDpchAppDoButQmdNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButQmdNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmQmd", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQmd");
	};
};

void PnlWznmNavUix::handleDpchAppDoButConViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstConAvail && statshr.ButConViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstCon.getRefByNum(contiac.numFLstCon), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmCon", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCon");
	};
};

void PnlWznmNavUix::handleDpchAppDoButConNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButConNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCon", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCon");
	};
};

void PnlWznmNavUix::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWznmHusrRunvMod_crdUsrEq(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWznmNavUix::handleCallWznmHusrRunvMod_crdUsrEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVCard::CRDWZNMPST) {
		refreshPst(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMMDL) {
		refreshMdl(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMCAR) {
		refreshCar(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMDLG) {
		refreshDlg(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMPNL) {
		refreshPnl(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMQRY) {
		refreshQry(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMQCO) {
		refreshQco(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMQMD) {
		refreshQmd(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMCON) {
		refreshCon(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
