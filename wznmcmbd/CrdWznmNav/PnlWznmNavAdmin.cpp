/**
	* \file PnlWznmNavAdmin.cpp
	* job handler for job PnlWznmNavAdmin (implementation)
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

#include "PnlWznmNavAdmin.h"

#include "PnlWznmNavAdmin_blks.cpp"
#include "PnlWznmNavAdmin_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmNavAdmin
 ******************************************************************************/

PnlWznmNavAdmin::PnlWznmNavAdmin(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMNAVADMIN, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstFil.tag = "FeedFLstFil";
	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshUsg(dbswznm, moditems);
	refreshUsr(dbswznm, moditems);
	refreshPrs(dbswznm, moditems);
	refreshFil(dbswznm, moditems);
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMUSG, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMUSR, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMPRS, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMFIL, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
};

PnlWznmNavAdmin::~PnlWznmNavAdmin() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmNavAdmin::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstFil, &feedFLstPrs, &feedFLstUsg, &feedFLstUsr, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmNavAdmin::refreshLstUsg(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsgAvail = evalLstUsgAvail(dbswznm);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavAdmin::refreshUsg(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsg = 0;

	// feedFLstUsg
	feedFLstUsg.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMUSG, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstUsg.appendRefTitles(rec->ref, StubWznm::getStubUsgStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsg(dbswznm, moditems);
};

void PnlWznmNavAdmin::refreshLstUsr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsrAvail = evalLstUsrAvail(dbswznm);
	statshr.ButUsrViewActive = evalButUsrViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavAdmin::refreshUsr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsr = 0;

	// feedFLstUsr
	feedFLstUsr.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMUSR, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstUsr.appendRefTitles(rec->ref, StubWznm::getStubUsrStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsr(dbswznm, moditems);
};

void PnlWznmNavAdmin::refreshLstPrs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrsAvail = evalLstPrsAvail(dbswznm);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavAdmin::refreshPrs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrs = 0;

	// feedFLstPrs
	feedFLstPrs.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMPRS, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPrs.appendRefTitles(rec->ref, StubWznm::getStubPrsStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrs(dbswznm, moditems);
};

void PnlWznmNavAdmin::refreshLstFil(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFilAvail = evalLstFilAvail(dbswznm);
	statshr.ButFilViewActive = evalButFilViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavAdmin::refreshFil(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFil = 0;

	// feedFLstFil
	feedFLstFil.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMFIL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstFil.appendRefTitles(rec->ref, StubWznm::getStubFilStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFIL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFil(dbswznm, moditems);
};

void PnlWznmNavAdmin::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWznmNavAdmin::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswznm, moditems);

	refreshLstUsg(dbswznm, moditems);
	refreshLstUsr(dbswznm, moditems);
	refreshLstPrs(dbswznm, moditems);
	refreshLstFil(dbswznm, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWznmNavAdmin::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVADMINDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVADMINDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGNEWCRDCLICK) {
					handleDpchAppDoButUsgNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRVIEWCLICK) {
					handleDpchAppDoButUsrViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRNEWCRDCLICK) {
					handleDpchAppDoButUsrNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSNEWCRDCLICK) {
					handleDpchAppDoButPrsNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILNEWCRDCLICK) {
					handleDpchAppDoButFilNewcrdClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmNavAdmin::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmNavAdmin::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTUSG)) {
		contiac.numFLstUsg = _contiac->numFLstUsg;
		refreshLstUsg(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUSR)) {
		contiac.numFLstUsr = _contiac->numFLstUsr;
		refreshLstUsr(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRS)) {
		contiac.numFLstPrs = _contiac->numFLstPrs;
		refreshLstPrs(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFIL)) {
		contiac.numFLstFil = _contiac->numFLstFil;
		refreshLstFil(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmNavAdmin::handleDpchAppDoButUsgViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsgAvail && statshr.ButUsgViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstUsg.getRefByNum(contiac.numFLstUsg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmUsg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmUsg");
	};
};

void PnlWznmNavAdmin::handleDpchAppDoButUsgNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmUsg");
};

void PnlWznmNavAdmin::handleDpchAppDoButUsrViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsrAvail && statshr.ButUsrViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstUsr.getRefByNum(contiac.numFLstUsr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmUsr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmUsr");
	};
};

void PnlWznmNavAdmin::handleDpchAppDoButUsrNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmUsr");
};

void PnlWznmNavAdmin::handleDpchAppDoButPrsViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrsAvail && statshr.ButPrsViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstPrs.getRefByNum(contiac.numFLstPrs), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmPrs", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPrs");
	};
};

void PnlWznmNavAdmin::handleDpchAppDoButPrsNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPrs");
};

void PnlWznmNavAdmin::handleDpchAppDoButFilViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFilAvail && statshr.ButFilViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstFil.getRefByNum(contiac.numFLstFil), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmFil", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmFil");
	};
};

void PnlWznmNavAdmin::handleDpchAppDoButFilNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmFil");
};

void PnlWznmNavAdmin::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWznmHusrRunvMod_crdUsrEq(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWznmNavAdmin::handleCallWznmHusrRunvMod_crdUsrEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVCard::CRDWZNMUSG) {
		refreshUsg(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMUSR) {
		refreshUsr(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMPRS) {
		refreshPrs(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMFIL) {
		refreshFil(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
