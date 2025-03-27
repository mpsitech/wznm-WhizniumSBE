/**
	* \file CrdWznmVis.cpp
	* job handler for job CrdWznmVis (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "CrdWznmVis.h"

#include "CrdWznmVis_blks.cpp"
#include "CrdWznmVis_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWznmVis
 ******************************************************************************/

CrdWznmVis::CrdWznmVis(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
			, const ubigint ref
		) :
			JobWznm(xchg, VecWznmVJob::CRDWZNMVIS, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlheadbar = NULL;
	pnllist = NULL;
	pnlrec = NULL;
	dlgwrite = NULL;
	dlgexpstr = NULL;
	dlgmissfeat = NULL;
	dlgnew = NULL;
	dlgimpstr = NULL;

	// IP constructor.cust1 --- INSERT

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFVIS, ref);

	// initialize according to ref
	changeRef(dbswznm, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnlheadbar = new PnlWznmVisHeadbar(xchg, dbswznm, jref, ixWznmVLocale);
	pnllist = new PnlWznmVisList(xchg, dbswznm, jref, ixWznmVLocale);
	pnlrec = new PnlWznmVisRec(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswznm, moditems);

	if ((ref + 1) == 0) {
		dlgnew = new DlgWznmVisNew(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbswznm, VecVSge::IDLE);

	xchg->addClstn(VecWznmVCall::CALLWZNMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWznmVis::~CrdWznmVis() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* CrdWznmVis::getNewDpchEng(
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

void CrdWznmVis::refresh(
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
	continf.MrlAppHlp = xchg->helpurl + "/CrdWznmVis/" + VecWznmVLocale::getSref(ixWznmVLocale);
	continf.MtxCrdVis = StubWznm::getStubVisStd(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref), ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswznm);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbswznm);
	statshr.MitCrdIstAvail = evalMitCrdIstAvail(dbswznm);
	statshr.MitCrdIstActive = evalMitCrdIstActive(dbswznm);
	statshr.MitCrdCmfAvail = evalMitCrdCmfAvail(dbswznm);
	statshr.MitCrdCmfActive = evalMitCrdCmfActive(dbswznm);
	statshr.MitCrdWrcAvail = evalMitCrdWrcAvail(dbswznm);
	statshr.MitCrdWrcActive = evalMitCrdWrcActive(dbswznm);
	statshr.MitCrdEstActive = evalMitCrdEstActive(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWznmVis::changeRef(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWznmVRecaccess;
	xchg->triggerIxRefToIxCall(dbswznm, VecWznmVCall::CALLWZNMRECACCESS, jref, VecWznmVCard::CRDWZNMVIS, ref, ixWznmVRecaccess);

	if (ixWznmVRecaccess != VecWznmVRecaccess::NONE) {
		xchg->addIxPreset(VecWznmVPreset::PREWZNMIXRECACC, jref, ixWznmVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswznm, VecWznmVCall::CALLWZNMLOG, jref, VecWznmVPreset::VOID, 0, "CrdWznmVis", ref);
		xchg->addRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref, ref);

		if (pnllist) pnllist->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVIS, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVIS, jrefTrig, notif);

		refresh(dbswznm, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void CrdWznmVis::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWznmVis::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVISDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDISTCLICK) {
					handleDpchAppDoMitCrdIstClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCMFCLICK) {
					handleDpchAppDoMitCrdCmfClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDWRCCLICK) {
					handleDpchAppDoMitCrdWrcClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDESTCLICK) {
					handleDpchAppDoMitCrdEstClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWznmVis::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWznmVis::handleDpchAppDoClose(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	xchg->triggerIxCall(dbswznm, VecWznmVCall::CALLWZNMCRDCLOSE, jref, VecWznmVCard::CRDWZNMVIS);
};

void CrdWznmVis::handleDpchAppDoMitAppAbtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswznm, VecVSge::ALRWZNMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWznmVis::handleDpchAppDoMitCrdNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgWznmVisNew(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVis::handleDpchAppDoMitCrdIstClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgimpstr) {
		dlgimpstr = new DlgWznmVisImpstr(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgimpstr = dlgimpstr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVis::handleDpchAppDoMitCrdCmfClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgmissfeat) {
		dlgmissfeat = new DlgWznmVisMissfeat(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgmissfeat = dlgmissfeat->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVis::handleDpchAppDoMitCrdWrcClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgwrite) {
		dlgwrite = new DlgWznmVisWrite(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgwrite = dlgwrite->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVis::handleDpchAppDoMitCrdEstClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgexpstr) {
		dlgexpstr = new DlgWznmVisExpstr(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgexpstr = dlgexpstr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVis::handleDpchAppWznmAlert(
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

void CrdWznmVis::handleCall(
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

bool CrdWznmVis::handleCallWznmRefPreSet(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWznmVPreset::PREWZNMREFVIS) {
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

bool CrdWznmVis::handleCallWznmStatChg(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD) && (pnlrec->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD)) pnllist->minimize(dbswznm, true);
	return retval;
};

bool CrdWznmVis::handleCallWznmDlgClose(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgexpstr) {
		delete dlgexpstr;
		dlgexpstr = NULL;
		statshr.jrefDlgexpstr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgimpstr) {
		delete dlgimpstr;
		dlgimpstr = NULL;
		statshr.jrefDlgimpstr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgmissfeat) {
		delete dlgmissfeat;
		dlgmissfeat = NULL;
		statshr.jrefDlgmissfeat = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgwrite) {
		delete dlgwrite;
		dlgwrite = NULL;
		statshr.jrefDlgwrite = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWznmVis::changeStage(
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

string CrdWznmVis::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWznmVis::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWznmVis::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWznmVis::enterSgeAlrwznmabt(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWznm::prepareAlrAbt(jref, ixWznmVLocale, feedFMcbAlert)); // IP enterSgeAlrwznmabt --- LINE

	return retval;
};

void CrdWznmVis::leaveSgeAlrwznmabt(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmabt --- INSERT
};
