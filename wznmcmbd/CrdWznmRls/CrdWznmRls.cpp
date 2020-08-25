/**
	* \file CrdWznmRls.cpp
	* job handler for job CrdWznmRls (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "CrdWznmRls.h"

#include "CrdWznmRls_blks.cpp"
#include "CrdWznmRls_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWznmRls
 ******************************************************************************/

CrdWznmRls::CrdWznmRls(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
			, const ubigint ref
			, const uint ixWznmVPreset
			, const ubigint preUref
		) :
			JobWznm(xchg, VecWznmVJob::CRDWZNMRLS, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;
	dlgwrite = NULL;
	dlgstareptr = NULL;
	dlgfinreptr = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref, ixWznmVPreset);
	if (ixWznmVPreset != VecWznmVPreset::VOID) xchg->addRefPreset(ixWznmVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFRLS, ref);

	// initialize according to ref
	changeRef(dbswznm, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWznmRlsList(xchg, dbswznm, jref, ixWznmVLocale);
	pnlheadbar = new PnlWznmRlsHeadbar(xchg, dbswznm, jref, ixWznmVLocale);
	pnlrec = new PnlWznmRlsRec(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswznm, moditems);

	changeStage(dbswznm, VecVSge::IDLE);

	xchg->addClstn(VecWznmVCall::CALLWZNMREPTRSTOP, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREPTRSTART, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWznmRls::~CrdWznmRls() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* CrdWznmRls::getNewDpchEng(
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

void CrdWznmRls::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWznmRls/" + VecWznmVLocale::getSref(ixWznmVLocale);
	continf.MtxCrdRls = StubWznm::getStubRlsStd(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref), ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswznm);
	statshr.MitCrdSrtAvail = evalMitCrdSrtAvail(dbswznm);
	statshr.MitCrdSrtActive = evalMitCrdSrtActive(dbswznm);
	statshr.MitCrdCrtAvail = evalMitCrdCrtAvail(dbswznm);
	statshr.MitCrdCrtActive = evalMitCrdCrtActive(dbswznm);
	statshr.MitCrdFrtAvail = evalMitCrdFrtAvail(dbswznm);
	statshr.MitCrdFrtActive = evalMitCrdFrtActive(dbswznm);
	statshr.MitCrdWcoAvail = evalMitCrdWcoAvail(dbswznm);
	statshr.MitCrdWcoActive = evalMitCrdWcoActive(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void CrdWznmRls::changeRef(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWznmVPreset = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswznm, VecWznmVCall::CALLWZNMLOG, jref, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref), "CrdWznmRls", ref);
	xchg->addRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref, ref);

	if (pnllist) pnllist->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFRLS, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFRLS, jrefTrig, notif);

	refresh(dbswznm, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWznmRls::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWznmRls::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSRTCLICK) {
					handleDpchAppDoMitCrdSrtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCRTCLICK) {
					handleDpchAppDoMitCrdCrtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFRTCLICK) {
					handleDpchAppDoMitCrdFrtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDWCOCLICK) {
					handleDpchAppDoMitCrdWcoClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWznmRls::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWznmRls::handleDpchAppDoClose(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	xchg->triggerIxCall(dbswznm, VecWznmVCall::CALLWZNMCRDCLOSE, jref, VecWznmVCard::CRDWZNMRLS);
};

void CrdWznmRls::handleDpchAppDoMitAppAbtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswznm, VecVSge::ALRWZNMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWznmRls::handleDpchAppDoMitCrdSrtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgstareptr) {
		dlgstareptr = new DlgWznmRlsStareptr(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgstareptr = dlgstareptr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmRls::handleDpchAppDoMitCrdCrtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitCrdCrtClick --- IBEGIN
	set<uint> moditems;

	xchg->removePreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref);
	xchg->removePreset(VecWznmVPreset::PREWZNMGITURL, jref);
	xchg->removePreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	xchg->removePreset(VecWznmVPreset::PREWZNMEXTFOLDER, jref);

	refresh(dbswznm, moditems);
	*dpcheng = getNewDpchEng(moditems);
	// IP handleDpchAppDoMitCrdCrtClick --- IEND
};

void CrdWznmRls::handleDpchAppDoMitCrdFrtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgfinreptr) {
		dlgfinreptr = new DlgWznmRlsFinreptr(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgfinreptr = dlgfinreptr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmRls::handleDpchAppDoMitCrdWcoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgwrite) {
		dlgwrite = new DlgWznmRlsWrite(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgwrite = dlgwrite->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmRls::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- BEGIN
	if (ixVSge == VecVSge::ALRWZNMABT) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	// IP handleDpchAppWznmAlert --- END
};

void CrdWznmRls::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMREPTRSTOP) {
		call->abort = handleCallWznmReptrStop(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREPTRSTART) {
		call->abort = handleCallWznmReptrStart(dbswznm, call->jref, call->argInv.ix, call->argInv.txtval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREFPRESET) {
		call->abort = handleCallWznmRefPreSet(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTATCHG) {
		call->abort = handleCallWznmStatChg(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMDLGCLOSE) {
		call->abort = handleCallWznmDlgClose(dbswznm, call->jref);
	};
};

bool CrdWznmRls::handleCallWznmReptrStop(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmReptrStop --- IBEGIN

	xchg->removePreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref);
	xchg->removePreset(VecWznmVPreset::PREWZNMGITURL, jref);
	xchg->removePreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	xchg->removePreset(VecWznmVPreset::PREWZNMEXTFOLDER, jref);

	if (!muteRefresh) refreshWithDpchEng(dbswznm);

	// IP handleCallWznmReptrStop --- IEND
	return retval;
};

bool CrdWznmRls::handleCallWznmReptrStart(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& txtvalInv
		) {
	bool retval = false;
	// IP handleCallWznmReptrStart --- IBEGIN

	xchg->addIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref, ixInv);
	if (txtvalInv != "") xchg->addTxtvalPreset(VecWznmVPreset::PREWZNMGITURL, jref, txtvalInv);

	// generate source code base folders
	xchg->addTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref, Tmp::newfolder(xchg->tmppath));
	xchg->addTxtvalPreset(VecWznmVPreset::PREWZNMEXTFOLDER, jref, Tmp::newfolder(xchg->tmppath));

	if (!muteRefresh) refreshWithDpchEng(dbswznm);

	// IP handleCallWznmReptrStart --- IEND
	return retval;
};

bool CrdWznmRls::handleCallWznmRefPreSet(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWznmVPreset::PREWZNMREFRLS) {
		changeRef(dbswznm, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswznm, true);
	};

	return retval;
};

bool CrdWznmRls::handleCallWznmStatChg(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD) && (pnlrec->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD)) pnllist->minimize(dbswznm, true);
	return retval;
};

bool CrdWznmRls::handleCallWznmDlgClose(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgfinreptr) {
		delete dlgfinreptr;
		dlgfinreptr = NULL;
		statshr.jrefDlgfinreptr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgstareptr) {
		delete dlgstareptr;
		dlgstareptr = NULL;
		statshr.jrefDlgstareptr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgwrite) {
		delete dlgwrite;
		dlgwrite = NULL;
		statshr.jrefDlgwrite = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWznmRls::changeStage(
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
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRWZNMABT: _ixVSge = enterSgeAlrwznmabt(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWznmRls::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWznmRls::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWznmRls::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWznmRls::enterSgeAlrwznmabt(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWznm::prepareAlrAbt(jref, ixWznmVLocale, feedFMcbAlert)); // IP enterSgeAlrwznmabt --- LINE

	return retval;
};

void CrdWznmRls::leaveSgeAlrwznmabt(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmabt --- INSERT
};


