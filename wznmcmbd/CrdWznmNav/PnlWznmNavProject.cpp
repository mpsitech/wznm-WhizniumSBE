/**
	* \file PnlWznmNavProject.cpp
	* job handler for job PnlWznmNavProject (implementation)
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

#include "PnlWznmNavProject.h"

#include "PnlWznmNavProject_blks.cpp"
#include "PnlWznmNavProject_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmNavProject
 ******************************************************************************/

PnlWznmNavProject::PnlWznmNavProject(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMNAVPROJECT, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstCap.tag = "FeedFLstCap";
	feedFLstErr.tag = "FeedFLstErr";
	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstVer.tag = "FeedFLstVer";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshPrj(dbswznm, moditems);
	refreshVer(dbswznm, moditems);
	refreshCap(dbswznm, moditems);
	refreshErr(dbswznm, moditems);
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMPRJ, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMVER, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMCAP, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVCard::CRDWZNMERR, xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref));
};

PnlWznmNavProject::~PnlWznmNavProject() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmNavProject::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstCap, &feedFLstErr, &feedFLstPrj, &feedFLstVer, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmNavProject::refreshLstPrj(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrjAvail = evalLstPrjAvail(dbswznm);
	statshr.ButPrjViewActive = evalButPrjViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavProject::refreshPrj(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrj = 0;

	// feedFLstPrj
	feedFLstPrj.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMPRJ, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPrj.appendRefTitles(rec->ref, StubWznm::getStubPrjStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRJ);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrj(dbswznm, moditems);
};

void PnlWznmNavProject::refreshLstVer(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstVerAvail = evalLstVerAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavProject::refreshVer(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstVer = 0;

	// feedFLstVer
	feedFLstVer.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMVER, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstVer.appendRefTitles(rec->ref, StubWznm::getStubVerStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTVER);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstVer(dbswznm, moditems);
};

void PnlWznmNavProject::refreshLstCap(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCapAvail = evalLstCapAvail(dbswznm);
	statshr.ButCapViewActive = evalButCapViewActive(dbswznm);
	statshr.ButCapNewcrdActive = evalButCapNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavProject::refreshCap(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCap = 0;

	// feedFLstCap
	feedFLstCap.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMCAP, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstCap.appendRefTitles(rec->ref, StubWznm::getStubCapStd(dbswznm, rec->unvUref, ixWznmVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCAP);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCap(dbswznm, moditems);
};

void PnlWznmNavProject::refreshLstErr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstErrAvail = evalLstErrAvail(dbswznm);
	statshr.ButErrViewActive = evalButErrViewActive(dbswznm);
	statshr.ButErrNewcrdActive = evalButErrNewcrdActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmNavProject::refreshErr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWznmHistRMUserUniversal rst;
	WznmHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstErr = 0;

	// feedFLstErr
	feedFLstErr.clear();

	dbswznm->tblwznmhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVCard::CRDWZNMERR, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
	};

	insert(moditems, DpchEngData::FEEDFLSTERR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstErr(dbswznm, moditems);
};

void PnlWznmNavProject::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWznmNavProject::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswznm, moditems);

	refreshLstPrj(dbswznm, moditems);
	refreshLstVer(dbswznm, moditems);
	refreshLstCap(dbswznm, moditems);
	refreshLstErr(dbswznm, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWznmNavProject::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVPROJECTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVPROJECTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTPRJVIEWCLICK) {
					handleDpchAppDoButPrjViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJNEWCRDCLICK) {
					handleDpchAppDoButPrjNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERNEWCRDCLICK) {
					handleDpchAppDoButVerNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCAPVIEWCLICK) {
					handleDpchAppDoButCapViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCAPNEWCRDCLICK) {
					handleDpchAppDoButCapNewcrdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTERRVIEWCLICK) {
					handleDpchAppDoButErrViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTERRNEWCRDCLICK) {
					handleDpchAppDoButErrNewcrdClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmNavProject::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmNavProject::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	ubigint ref;

	if (has(diffitems, ContIac::NUMFLSTPRJ)) {
		contiac.numFLstPrj = _contiac->numFLstPrj;
		refreshLstPrj(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTVER)) {
		contiac.numFLstVer = _contiac->numFLstVer;
		if (dbswznm->tblwznmhistrmuseruniversal->loadUnuByRef(feedFLstVer.getRefByNum(contiac.numFLstVer), ref)) xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFVER, ref);
		refreshLstVer(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCAP)) {
		contiac.numFLstCap = _contiac->numFLstCap;
		refreshLstCap(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTERR)) {
		contiac.numFLstErr = _contiac->numFLstErr;
		refreshLstErr(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmNavProject::handleDpchAppDoButPrjViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrjAvail && statshr.ButPrjViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstPrj.getRefByNum(contiac.numFLstPrj), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmPrj", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPrj");
	};
};

void PnlWznmNavProject::handleDpchAppDoButPrjNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmPrj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPrj");
};

void PnlWznmNavProject::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstVerAvail && statshr.ButVerViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstVer.getRefByNum(contiac.numFLstVer), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmVer", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVer");
	};
};

void PnlWznmNavProject::handleDpchAppDoButVerNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmVer", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVer");
};

void PnlWznmNavProject::handleDpchAppDoButCapViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstCapAvail && statshr.ButCapViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstCap.getRefByNum(contiac.numFLstCap), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmCap", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCap");
	};
};

void PnlWznmNavProject::handleDpchAppDoButCapNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButCapNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCap", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCap");
	};
};

void PnlWznmNavProject::handleDpchAppDoButErrViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	WznmHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstErrAvail && statshr.ButErrViewActive) {
		if (dbswznm->tblwznmhistrmuseruniversal->loadRecByRef(feedFLstErr.getRefByNum(contiac.numFLstErr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, husrRunv->ixWznmVPreset, husrRunv->preUref, "CrdWznmErr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmErr");
	};
};

void PnlWznmNavProject::handleDpchAppDoButErrNewcrdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButErrNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmErr", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmErr");
	};
};

void PnlWznmNavProject::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWznmHusrRunvMod_crdUsrEq(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWznmNavProject::handleCallWznmHusrRunvMod_crdUsrEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVCard::CRDWZNMPRJ) {
		refreshPrj(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMVER) {
		refreshVer(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMCAP) {
		refreshCap(dbswznm, moditems);
	} else if (ixInv == VecWznmVCard::CRDWZNMERR) {
		refreshErr(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};



