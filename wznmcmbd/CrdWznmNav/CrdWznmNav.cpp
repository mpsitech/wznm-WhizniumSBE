/**
	* \file CrdWznmNav.cpp
	* job handler for job CrdWznmNav (implementation)
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

#include "CrdWznmNav.h"

#include "CrdWznmNav_blks.cpp"
#include "CrdWznmNav_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWznmNav
 ******************************************************************************/

CrdWznmNav::CrdWznmNav(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::CRDWZNMNAV, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlauxfct = NULL;
	pnlappdev = NULL;
	pnlvisual = NULL;
	pnldeploy = NULL;
	pnlcomp = NULL;
	pnljob = NULL;
	pnldbstr = NULL;
	pnluix = NULL;
	pnlproject = NULL;
	pnlglobal = NULL;
	pnladmin = NULL;
	pnlpre = NULL;
	pnlheadbar = NULL;
	dlgloaini = NULL;
	dlgmnglic = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	pnlauxfct = new PnlWznmNavAuxfct(xchg, dbswznm, jref, ixWznmVLocale);
	pnlappdev = new PnlWznmNavAppdev(xchg, dbswznm, jref, ixWznmVLocale);
	pnlvisual = new PnlWznmNavVisual(xchg, dbswznm, jref, ixWznmVLocale);
	pnldeploy = new PnlWznmNavDeploy(xchg, dbswznm, jref, ixWznmVLocale);
	pnlcomp = new PnlWznmNavComp(xchg, dbswznm, jref, ixWznmVLocale);
	pnljob = new PnlWznmNavJob(xchg, dbswznm, jref, ixWznmVLocale);
	pnldbstr = new PnlWznmNavDbstr(xchg, dbswznm, jref, ixWznmVLocale);
	pnluix = new PnlWznmNavUix(xchg, dbswznm, jref, ixWznmVLocale);
	pnlproject = new PnlWznmNavProject(xchg, dbswznm, jref, ixWznmVLocale);
	pnlglobal = new PnlWznmNavGlobal(xchg, dbswznm, jref, ixWznmVLocale);
	pnladmin = new PnlWznmNavAdmin(xchg, dbswznm, jref, ixWznmVLocale);
	pnlpre = new PnlWznmNavPre(xchg, dbswznm, jref, ixWznmVLocale);
	pnlheadbar = new PnlWznmNavHeadbar(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefPre = pnlpre->jref;
	statshr.jrefAdmin = pnladmin->jref;
	statshr.jrefGlobal = pnlglobal->jref;
	statshr.jrefProject = pnlproject->jref;
	statshr.jrefDbstr = pnldbstr->jref;
	statshr.jrefUix = pnluix->jref;
	statshr.jrefComp = pnlcomp->jref;
	statshr.jrefJob = pnljob->jref;
	statshr.jrefDeploy = pnldeploy->jref;
	statshr.jrefVisual = pnlvisual->jref;
	statshr.jrefAppdev = pnlappdev->jref;
	statshr.jrefAuxfct = pnlauxfct->jref;

	changeStage(dbswznm, VecVSge::IDLE);

	xchg->addClstn(VecWznmVCall::CALLWZNMDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWznmNav::~CrdWznmNav() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* CrdWznmNav::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdWznmNav::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	string s;
	vector<string> ss;

	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWznmNav/" + VecWznmVLocale::getSref(ixWznmVLocale);

	s = StubWznm::getStubSesMenu(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMSESS, jref), ixWznmVLocale, Stub::VecVNonetype::DASH);
	StrMod::stringToVector(s, ss);

	if (ss.size() == 3) {
		continf.MtxSesSes1 = ss[0];
		continf.MtxSesSes2 = ss[1];
		continf.MtxSesSes3 = ss[2];
	};

	// statshr
	statshr.pnlpreAvail = evalPnlpreAvail(dbswznm);
	statshr.pnladminAvail = evalPnladminAvail(dbswznm);
	statshr.pnlglobalAvail = evalPnlglobalAvail(dbswznm);
	statshr.pnlprojectAvail = evalPnlprojectAvail(dbswznm);
	statshr.pnldbstrAvail = evalPnldbstrAvail(dbswznm);
	statshr.pnluixAvail = evalPnluixAvail(dbswznm);
	statshr.pnlcompAvail = evalPnlcompAvail(dbswznm);
	statshr.pnljobAvail = evalPnljobAvail(dbswznm);
	statshr.pnldeployAvail = evalPnldeployAvail(dbswznm);
	statshr.pnlvisualAvail = evalPnlvisualAvail(dbswznm);
	statshr.pnlappdevAvail = evalPnlappdevAvail(dbswznm);
	statshr.pnlauxfctAvail = evalPnlauxfctAvail(dbswznm);
	statshr.MitSesSpsAvail = evalMitSesSpsAvail(dbswznm);
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswznm);
	statshr.MitCrdUsgAvail = evalMitCrdUsgAvail(dbswznm);
	statshr.MitCrdUsrAvail = evalMitCrdUsrAvail(dbswznm);
	statshr.MitCrdPrsAvail = evalMitCrdPrsAvail(dbswznm);
	statshr.MitCrdFilAvail = evalMitCrdFilAvail(dbswznm);
	statshr.MspCrd2Avail = evalMspCrd2Avail(dbswznm);
	statshr.MitCrdLocAvail = evalMitCrdLocAvail(dbswznm);
	statshr.MitCrdTagAvail = evalMitCrdTagAvail(dbswznm);
	statshr.MitCrdCtpAvail = evalMitCrdCtpAvail(dbswznm);
	statshr.MitCrdMchAvail = evalMitCrdMchAvail(dbswznm);
	statshr.MitCrdLibAvail = evalMitCrdLibAvail(dbswznm);
	statshr.MspCrd3Avail = evalMspCrd3Avail(dbswznm);
	statshr.MitCrdPrjAvail = evalMitCrdPrjAvail(dbswznm);
	statshr.MitCrdVerAvail = evalMitCrdVerAvail(dbswznm);
	statshr.MitCrdCapAvail = evalMitCrdCapAvail(dbswznm);
	statshr.MitCrdCapActive = evalMitCrdCapActive(dbswznm);
	statshr.MitCrdErrAvail = evalMitCrdErrAvail(dbswznm);
	statshr.MitCrdErrActive = evalMitCrdErrActive(dbswznm);
	statshr.MspCrd4Avail = evalMspCrd4Avail(dbswznm);
	statshr.MitCrdTblAvail = evalMitCrdTblAvail(dbswznm);
	statshr.MitCrdTblActive = evalMitCrdTblActive(dbswznm);
	statshr.MitCrdTcoAvail = evalMitCrdTcoAvail(dbswznm);
	statshr.MitCrdTcoActive = evalMitCrdTcoActive(dbswznm);
	statshr.MitCrdSbsAvail = evalMitCrdSbsAvail(dbswznm);
	statshr.MitCrdSbsActive = evalMitCrdSbsActive(dbswznm);
	statshr.MitCrdRelAvail = evalMitCrdRelAvail(dbswznm);
	statshr.MitCrdRelActive = evalMitCrdRelActive(dbswznm);
	statshr.MitCrdVecAvail = evalMitCrdVecAvail(dbswznm);
	statshr.MitCrdVecActive = evalMitCrdVecActive(dbswznm);
	statshr.MitCrdVitAvail = evalMitCrdVitAvail(dbswznm);
	statshr.MitCrdVitActive = evalMitCrdVitActive(dbswznm);
	statshr.MitCrdChkAvail = evalMitCrdChkAvail(dbswznm);
	statshr.MitCrdChkActive = evalMitCrdChkActive(dbswznm);
	statshr.MitCrdStbAvail = evalMitCrdStbAvail(dbswznm);
	statshr.MitCrdStbActive = evalMitCrdStbActive(dbswznm);
	statshr.MitCrdIexAvail = evalMitCrdIexAvail(dbswznm);
	statshr.MitCrdIexActive = evalMitCrdIexActive(dbswznm);
	statshr.MitCrdImeAvail = evalMitCrdImeAvail(dbswznm);
	statshr.MitCrdImeActive = evalMitCrdImeActive(dbswznm);
	statshr.MspCrd5Avail = evalMspCrd5Avail(dbswznm);
	statshr.MitCrdPstAvail = evalMitCrdPstAvail(dbswznm);
	statshr.MitCrdPstActive = evalMitCrdPstActive(dbswznm);
	statshr.MitCrdMdlAvail = evalMitCrdMdlAvail(dbswznm);
	statshr.MitCrdMdlActive = evalMitCrdMdlActive(dbswznm);
	statshr.MitCrdCarAvail = evalMitCrdCarAvail(dbswznm);
	statshr.MitCrdCarActive = evalMitCrdCarActive(dbswznm);
	statshr.MitCrdDlgAvail = evalMitCrdDlgAvail(dbswznm);
	statshr.MitCrdDlgActive = evalMitCrdDlgActive(dbswznm);
	statshr.MitCrdPnlAvail = evalMitCrdPnlAvail(dbswznm);
	statshr.MitCrdPnlActive = evalMitCrdPnlActive(dbswznm);
	statshr.MitCrdQryAvail = evalMitCrdQryAvail(dbswznm);
	statshr.MitCrdQryActive = evalMitCrdQryActive(dbswznm);
	statshr.MitCrdQcoAvail = evalMitCrdQcoAvail(dbswznm);
	statshr.MitCrdQcoActive = evalMitCrdQcoActive(dbswznm);
	statshr.MitCrdQmdAvail = evalMitCrdQmdAvail(dbswznm);
	statshr.MitCrdQmdActive = evalMitCrdQmdActive(dbswznm);
	statshr.MitCrdConAvail = evalMitCrdConAvail(dbswznm);
	statshr.MitCrdConActive = evalMitCrdConActive(dbswznm);
	statshr.MspCrd6Avail = evalMspCrd6Avail(dbswznm);
	statshr.MitCrdOpkAvail = evalMitCrdOpkAvail(dbswznm);
	statshr.MitCrdOpkActive = evalMitCrdOpkActive(dbswznm);
	statshr.MitCrdOpxAvail = evalMitCrdOpxAvail(dbswznm);
	statshr.MitCrdOpxActive = evalMitCrdOpxActive(dbswznm);
	statshr.MspCrd7Avail = evalMspCrd7Avail(dbswznm);
	statshr.MitCrdJobAvail = evalMitCrdJobAvail(dbswznm);
	statshr.MitCrdJobActive = evalMitCrdJobActive(dbswznm);
	statshr.MitCrdSgeAvail = evalMitCrdSgeAvail(dbswznm);
	statshr.MitCrdSgeActive = evalMitCrdSgeActive(dbswznm);
	statshr.MitCrdMtdAvail = evalMitCrdMtdAvail(dbswznm);
	statshr.MitCrdMtdActive = evalMitCrdMtdActive(dbswznm);
	statshr.MitCrdBlkAvail = evalMitCrdBlkAvail(dbswznm);
	statshr.MitCrdBlkActive = evalMitCrdBlkActive(dbswznm);
	statshr.MitCrdCalAvail = evalMitCrdCalAvail(dbswznm);
	statshr.MitCrdCalActive = evalMitCrdCalActive(dbswznm);
	statshr.MspCrd8Avail = evalMspCrd8Avail(dbswznm);
	statshr.MitCrdCmpAvail = evalMitCrdCmpAvail(dbswznm);
	statshr.MitCrdRlsAvail = evalMitCrdRlsAvail(dbswznm);
	statshr.MitCrdRlsActive = evalMitCrdRlsActive(dbswznm);
	statshr.MspCrd9Avail = evalMspCrd9Avail(dbswznm);
	statshr.MitCrdVisAvail = evalMitCrdVisAvail(dbswznm);
	statshr.MitCrdShtAvail = evalMitCrdShtAvail(dbswznm);
	statshr.MitCrdShtActive = evalMitCrdShtActive(dbswznm);
	statshr.MitCrdBoxAvail = evalMitCrdBoxAvail(dbswznm);
	statshr.MitCrdBoxActive = evalMitCrdBoxActive(dbswznm);
	statshr.MspCrd10Avail = evalMspCrd10Avail(dbswznm);
	statshr.MitCrdAppAvail = evalMitCrdAppAvail(dbswznm);
	statshr.MitCrdRtjAvail = evalMitCrdRtjAvail(dbswznm);
	statshr.MitCrdRtjActive = evalMitCrdRtjActive(dbswznm);
	statshr.MitCrdEvtAvail = evalMitCrdEvtAvail(dbswznm);
	statshr.MitCrdEvtActive = evalMitCrdEvtActive(dbswznm);
	statshr.MitCrdSeqAvail = evalMitCrdSeqAvail(dbswznm);
	statshr.MitCrdSeqActive = evalMitCrdSeqActive(dbswznm);
	statshr.MitCrdSteAvail = evalMitCrdSteAvail(dbswznm);
	statshr.MitCrdSteActive = evalMitCrdSteActive(dbswznm);
	statshr.MspCrd11Avail = evalMspCrd11Avail(dbswznm);
	statshr.MitCrdUtlAvail = evalMitCrdUtlAvail(dbswznm);
	statshr.MspApp2Avail = evalMspApp2Avail(dbswznm);
	statshr.MitAppMlcAvail = evalMitAppMlcAvail(dbswznm);
	statshr.MitAppLoiAvail = evalMitAppLoiAvail(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWznmNav::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswznm, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnlpre) if (jrefTrig != pnlpre->jref) pnlpre->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnladmin) pnladmin->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnlglobal) pnlglobal->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnlproject) pnlproject->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnldbstr) pnldbstr->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnluix) pnluix->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnlcomp) pnlcomp->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnljob) pnljob->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnldeploy) pnldeploy->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnlvisual) pnlvisual->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnlappdev) pnlappdev->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	if (pnlauxfct) pnlauxfct->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
	// IP updatePreset --- END
};

void CrdWznmNav::warnTerm(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IDLE) changeStage(dbswznm, VecVSge::ALRWZNMTRM);
};

void CrdWznmNav::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESSPSCLICK) {
					handleDpchAppDoMitSesSpsClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESTRMCLICK) {
					handleDpchAppDoMitSesTrmClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSGCLICK) {
					handleDpchAppDoMitCrdUsgClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSRCLICK) {
					handleDpchAppDoMitCrdUsrClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRSCLICK) {
					handleDpchAppDoMitCrdPrsClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFILCLICK) {
					handleDpchAppDoMitCrdFilClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLOCCLICK) {
					handleDpchAppDoMitCrdLocClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDTAGCLICK) {
					handleDpchAppDoMitCrdTagClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCTPCLICK) {
					handleDpchAppDoMitCrdCtpClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDMCHCLICK) {
					handleDpchAppDoMitCrdMchClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLIBCLICK) {
					handleDpchAppDoMitCrdLibClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRJCLICK) {
					handleDpchAppDoMitCrdPrjClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDVERCLICK) {
					handleDpchAppDoMitCrdVerClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCAPCLICK) {
					handleDpchAppDoMitCrdCapClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDERRCLICK) {
					handleDpchAppDoMitCrdErrClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDTBLCLICK) {
					handleDpchAppDoMitCrdTblClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDTCOCLICK) {
					handleDpchAppDoMitCrdTcoClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSBSCLICK) {
					handleDpchAppDoMitCrdSbsClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDRELCLICK) {
					handleDpchAppDoMitCrdRelClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDVECCLICK) {
					handleDpchAppDoMitCrdVecClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDVITCLICK) {
					handleDpchAppDoMitCrdVitClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCHKCLICK) {
					handleDpchAppDoMitCrdChkClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSTBCLICK) {
					handleDpchAppDoMitCrdStbClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIEXCLICK) {
					handleDpchAppDoMitCrdIexClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIMECLICK) {
					handleDpchAppDoMitCrdImeClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPSTCLICK) {
					handleDpchAppDoMitCrdPstClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDMDLCLICK) {
					handleDpchAppDoMitCrdMdlClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCARCLICK) {
					handleDpchAppDoMitCrdCarClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDDLGCLICK) {
					handleDpchAppDoMitCrdDlgClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPNLCLICK) {
					handleDpchAppDoMitCrdPnlClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDQRYCLICK) {
					handleDpchAppDoMitCrdQryClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDQCOCLICK) {
					handleDpchAppDoMitCrdQcoClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDQMDCLICK) {
					handleDpchAppDoMitCrdQmdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCONCLICK) {
					handleDpchAppDoMitCrdConClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDOPKCLICK) {
					handleDpchAppDoMitCrdOpkClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDOPXCLICK) {
					handleDpchAppDoMitCrdOpxClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDJOBCLICK) {
					handleDpchAppDoMitCrdJobClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSGECLICK) {
					handleDpchAppDoMitCrdSgeClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDMTDCLICK) {
					handleDpchAppDoMitCrdMtdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDBLKCLICK) {
					handleDpchAppDoMitCrdBlkClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCALCLICK) {
					handleDpchAppDoMitCrdCalClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCMPCLICK) {
					handleDpchAppDoMitCrdCmpClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDRLSCLICK) {
					handleDpchAppDoMitCrdRlsClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDVISCLICK) {
					handleDpchAppDoMitCrdVisClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSHTCLICK) {
					handleDpchAppDoMitCrdShtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDBOXCLICK) {
					handleDpchAppDoMitCrdBoxClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDAPPCLICK) {
					handleDpchAppDoMitCrdAppClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDRTJCLICK) {
					handleDpchAppDoMitCrdRtjClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDEVTCLICK) {
					handleDpchAppDoMitCrdEvtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSEQCLICK) {
					handleDpchAppDoMitCrdSeqClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSTECLICK) {
					handleDpchAppDoMitCrdSteClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUTLCLICK) {
					handleDpchAppDoMitCrdUtlClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPMLCCLICK) {
					handleDpchAppDoMitAppMlcClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPLOICLICK) {
					handleDpchAppDoMitAppLoiClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWznmNav::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWznmNav::handleDpchAppDoClose(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");

	if (xchg->stgwznmbehavior.suspsess) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSUSPSESS, xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref));
	else xchg->triggerBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMLOGOUT, xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref), false);
};

void CrdWznmNav::handleDpchAppDoMitAppAbtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswznm, VecVSge::ALRWZNMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWznmNav::handleDpchAppDoMitSesSpsClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");

	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSUSPSESS, xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref));
};

void CrdWznmNav::handleDpchAppDoMitSesTrmClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");

	xchg->triggerBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMLOGOUT, xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref), false);
};

void CrdWznmNav::handleDpchAppDoMitCrdUsgClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmUsg");
};

void CrdWznmNav::handleDpchAppDoMitCrdUsrClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmUsr");
};

void CrdWznmNav::handleDpchAppDoMitCrdPrsClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPrs");
};

void CrdWznmNav::handleDpchAppDoMitCrdFilClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmFil");
};

void CrdWznmNav::handleDpchAppDoMitCrdLocClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmLoc", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmLoc");
};

void CrdWznmNav::handleDpchAppDoMitCrdTagClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmTag", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmTag");
};

void CrdWznmNav::handleDpchAppDoMitCrdCtpClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCtp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCtp");
};

void CrdWznmNav::handleDpchAppDoMitCrdMchClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmMch", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmMch");
};

void CrdWznmNav::handleDpchAppDoMitCrdLibClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmLib", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmLib");
};

void CrdWznmNav::handleDpchAppDoMitCrdPrjClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmPrj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPrj");
};

void CrdWznmNav::handleDpchAppDoMitCrdVerClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmVer", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVer");
};

void CrdWznmNav::handleDpchAppDoMitCrdCapClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCap", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCap");
};

void CrdWznmNav::handleDpchAppDoMitCrdErrClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmErr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmErr");
};

void CrdWznmNav::handleDpchAppDoMitCrdTblClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmTbl", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmTbl");
};

void CrdWznmNav::handleDpchAppDoMitCrdTcoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmTco", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmTco");
};

void CrdWznmNav::handleDpchAppDoMitCrdSbsClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmSbs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmSbs");
};

void CrdWznmNav::handleDpchAppDoMitCrdRelClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmRel", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmRel");
};

void CrdWznmNav::handleDpchAppDoMitCrdVecClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmVec", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVec");
};

void CrdWznmNav::handleDpchAppDoMitCrdVitClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmVit", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVit");
};

void CrdWznmNav::handleDpchAppDoMitCrdChkClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmChk", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmChk");
};

void CrdWznmNav::handleDpchAppDoMitCrdStbClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmStb", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmStb");
};

void CrdWznmNav::handleDpchAppDoMitCrdIexClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmIex", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmIex");
};

void CrdWznmNav::handleDpchAppDoMitCrdImeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmIme", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmIme");
};

void CrdWznmNav::handleDpchAppDoMitCrdPstClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmPst", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPst");
};

void CrdWznmNav::handleDpchAppDoMitCrdMdlClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmMdl", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmMdl");
};

void CrdWznmNav::handleDpchAppDoMitCrdCarClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCar", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCar");
};

void CrdWznmNav::handleDpchAppDoMitCrdDlgClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmDlg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmDlg");
};

void CrdWznmNav::handleDpchAppDoMitCrdPnlClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmPnl", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmPnl");
};

void CrdWznmNav::handleDpchAppDoMitCrdQryClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmQry", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQry");
};

void CrdWznmNav::handleDpchAppDoMitCrdQcoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmQco", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQco");
};

void CrdWznmNav::handleDpchAppDoMitCrdQmdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmQmd", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmQmd");
};

void CrdWznmNav::handleDpchAppDoMitCrdConClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCon", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCon");
};

void CrdWznmNav::handleDpchAppDoMitCrdOpkClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmOpk", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmOpk");
};

void CrdWznmNav::handleDpchAppDoMitCrdOpxClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmOpx", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmOpx");
};

void CrdWznmNav::handleDpchAppDoMitCrdJobClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmJob", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmJob");
};

void CrdWznmNav::handleDpchAppDoMitCrdSgeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmSge", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmSge");
};

void CrdWznmNav::handleDpchAppDoMitCrdMtdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmMtd", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmMtd");
};

void CrdWznmNav::handleDpchAppDoMitCrdBlkClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmBlk", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmBlk");
};

void CrdWznmNav::handleDpchAppDoMitCrdCalClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCal", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCal");
};

void CrdWznmNav::handleDpchAppDoMitCrdCmpClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmCmp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmCmp");
};

void CrdWznmNav::handleDpchAppDoMitCrdRlsClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmRls", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmRls");
};

void CrdWznmNav::handleDpchAppDoMitCrdVisClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmVis", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmVis");
};

void CrdWznmNav::handleDpchAppDoMitCrdShtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmSht", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmSht");
};

void CrdWznmNav::handleDpchAppDoMitCrdBoxClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmBox", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmBox");
};

void CrdWznmNav::handleDpchAppDoMitCrdAppClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmApp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmApp");
};

void CrdWznmNav::handleDpchAppDoMitCrdRtjClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmRtj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmRtj");
};

void CrdWznmNav::handleDpchAppDoMitCrdEvtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmEvt", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmEvt");
};

void CrdWznmNav::handleDpchAppDoMitCrdSeqClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmSeq", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmSeq");
};

void CrdWznmNav::handleDpchAppDoMitCrdSteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmSte", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmSte");
};

void CrdWznmNav::handleDpchAppDoMitCrdUtlClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, "CrdWznmUtl", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
	else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, "CrdWznmUtl");
};

void CrdWznmNav::handleDpchAppDoMitAppMlcClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitAppMlcClick --- INSERT
};

void CrdWznmNav::handleDpchAppDoMitAppLoiClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgloaini) {
		dlgloaini = new DlgWznmNavLoaini(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgloaini = dlgloaini->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmNav::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- BEGIN
	if (ixVSge == VecVSge::ALRWZNMABT) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	} else if (ixVSge == VecVSge::ALRWZNMTRM) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	// IP handleDpchAppWznmAlert --- END
};

void CrdWznmNav::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMDLGCLOSE) {
		call->abort = handleCallWznmDlgClose(dbswznm, call->jref);
	};
};

bool CrdWznmNav::handleCallWznmDlgClose(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgloaini) {
		delete dlgloaini;
		dlgloaini = NULL;
		statshr.jrefDlgloaini = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgmnglic) {
		delete dlgmnglic;
		dlgmnglic = NULL;
		statshr.jrefDlgmnglic = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWznmNav::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRWZNMABT: leaveSgeAlrwznmabt(dbswznm); break;
				case VecVSge::ALRWZNMTRM: leaveSgeAlrwznmtrm(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRWZNMABT: _ixVSge = enterSgeAlrwznmabt(dbswznm, reenter); break;
			case VecVSge::ALRWZNMTRM: _ixVSge = enterSgeAlrwznmtrm(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWznmNav::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWznmNav::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWznmNav::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWznmNav::enterSgeAlrwznmabt(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWznm::prepareAlrAbt(jref, ixWznmVLocale, feedFMcbAlert)); // IP enterSgeAlrwznmabt --- LINE

	return retval;
};

void CrdWznmNav::leaveSgeAlrwznmabt(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmabt --- INSERT
};

uint CrdWznmNav::enterSgeAlrwznmtrm(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMTRM;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWznm::prepareAlrTrm(jref, ixWznmVLocale, xchg->stgwznmbehavior.sesstterm, xchg->stgwznmbehavior.sesstwarn, feedFMcbAlert)); // IP enterSgeAlrwznmtrm --- LINE

	return retval;
};

void CrdWznmNav::leaveSgeAlrwznmtrm(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmtrm --- INSERT
};
