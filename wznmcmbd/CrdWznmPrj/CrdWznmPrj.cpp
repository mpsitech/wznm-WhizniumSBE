/**
	* \file CrdWznmPrj.cpp
	* job handler for job CrdWznmPrj (implementation)
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

#include "CrdWznmPrj.h"

#include "CrdWznmPrj_blks.cpp"
#include "CrdWznmPrj_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWznmPrj
 ******************************************************************************/

CrdWznmPrj::CrdWznmPrj(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
			, const ubigint ref
		) :
			JobWznm(xchg, VecWznmVJob::CRDWZNMPRJ, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	dlgnew = NULL;
	pnlrec = NULL;
	dlgimpex = NULL;

	// IP constructor.cust1 --- INSERT

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFPRJ, ref);

	// initialize according to ref
	changeRef(dbswznm, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWznmPrjList(xchg, dbswznm, jref, ixWznmVLocale);
	pnlheadbar = new PnlWznmPrjHeadbar(xchg, dbswznm, jref, ixWznmVLocale);
	pnlrec = new PnlWznmPrjRec(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswznm, moditems);

	if ((ref + 1) == 0) {
		dlgnew = new DlgWznmPrjNew(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbswznm, VecVSge::IDLE);

	xchg->addClstn(VecWznmVCall::CALLWZNMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWznmPrj::~CrdWznmPrj() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* CrdWznmPrj::getNewDpchEng(
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

void CrdWznmPrj::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWznmPrj/" + VecWznmVLocale::getSref(ixWznmVLocale);
	continf.MtxCrdPrj = StubWznm::getStubPrjStd(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPRJ, jref), ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswznm);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbswznm);
	statshr.MitCrdIpxAvail = evalMitCrdIpxAvail(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWznmPrj::changeRef(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWznmVRecaccess;
	xchg->triggerIxRefToIxCall(dbswznm, VecWznmVCall::CALLWZNMRECACCESS, jref, VecWznmVCard::CRDWZNMPRJ, ref, ixWznmVRecaccess);

	if (ixWznmVRecaccess != VecWznmVRecaccess::NONE) {
		xchg->addIxPreset(VecWznmVPreset::PREWZNMIXRECACC, jref, ixWznmVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswznm, VecWznmVCall::CALLWZNMLOG, jref, VecWznmVPreset::VOID, 0, "CrdWznmPrj", ref);
		xchg->addRefPreset(VecWznmVPreset::PREWZNMREFPRJ, jref, ref);

		if (pnllist) pnllist->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFPRJ, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFPRJ, jrefTrig, notif);

		refresh(dbswznm, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void CrdWznmPrj::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWznmPrj::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIPXCLICK) {
					handleDpchAppDoMitCrdIpxClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWznmPrj::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWznmPrj::handleDpchAppDoClose(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	xchg->triggerIxCall(dbswznm, VecWznmVCall::CALLWZNMCRDCLOSE, jref, VecWznmVCard::CRDWZNMPRJ);
};

void CrdWznmPrj::handleDpchAppDoMitAppAbtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswznm, VecVSge::ALRWZNMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWznmPrj::handleDpchAppDoMitCrdNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgWznmPrjNew(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmPrj::handleDpchAppDoMitCrdIpxClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgimpex) {
		dlgimpex = new DlgWznmPrjImpex(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgimpex = dlgimpex->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmPrj::handleDpchAppWznmAlert(
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

void CrdWznmPrj::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMREFPRESET) {
		call->abort = handleCallWznmRefPreSet(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTATCHG) {
		call->abort = handleCallWznmStatChg(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMDLGCLOSE) {
		call->abort = handleCallWznmDlgClose(dbswznm, call->jref);
	};
};

bool CrdWznmPrj::handleCallWznmRefPreSet(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWznmVPreset::PREWZNMREFPRJ) {
		changeRef(dbswznm, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswznm, true);
		else if ((jrefTrig == statshr.jrefDlgnew) && (refInv != 0)) {
			pnllist->qry->rerun(dbswznm, true);
			pnllist->minimize(dbswznm, true);
			pnlrec->regularize(dbswznm, true);
		};
	};

	return retval;
};

bool CrdWznmPrj::handleCallWznmStatChg(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD) && (pnlrec->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD)) pnllist->minimize(dbswznm, true);
	return retval;
};

bool CrdWznmPrj::handleCallWznmDlgClose(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgimpex) {
		delete dlgimpex;
		dlgimpex = NULL;
		statshr.jrefDlgimpex = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWznmPrj::changeStage(
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
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRWZNMABT: _ixVSge = enterSgeAlrwznmabt(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWznmPrj::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWznmPrj::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWznmPrj::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWznmPrj::enterSgeAlrwznmabt(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWznm::prepareAlrAbt(jref, ixWznmVLocale, feedFMcbAlert)); // IP enterSgeAlrwznmabt --- LINE

	return retval;
};

void CrdWznmPrj::leaveSgeAlrwznmabt(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmabt --- INSERT
};



