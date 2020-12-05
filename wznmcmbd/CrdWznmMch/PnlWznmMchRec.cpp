/**
	* \file PnlWznmMchRec.cpp
	* job handler for job PnlWznmMchRec (implementation)
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

#include "PnlWznmMchRec.h"

#include "PnlWznmMchRec_blks.cpp"
#include "PnlWznmMchRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmMchRec
 ******************************************************************************/

PnlWznmMchRec::PnlWznmMchRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMMCHREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlsup1nmachine = NULL;
	pnlapar = NULL;
	pnl1nrelease = NULL;
	pnlamakefile = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMMCH_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMMCH_CCHEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFMCH, jref);
};

PnlWznmMchRec::~PnlWznmMchRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmMchRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmMchRec::refresh(
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
	continf.TxtRef = StubWznm::getStubMchStd(dbswznm, recMch.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recMch.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlamakefile) {delete pnlamakefile; pnlamakefile = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnl1nrelease) {delete pnl1nrelease; pnl1nrelease = NULL;};
		if (pnlsup1nmachine) {delete pnlsup1nmachine; pnlsup1nmachine = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmMchDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlamakefile) pnlamakefile = new PnlWznmMchAMakefile(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlapar) pnlapar = new PnlWznmMchAPar(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nrelease) pnl1nrelease = new PnlWznmMch1NRelease(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsup1nmachine) pnlsup1nmachine = new PnlWznmMchSup1NMachine(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAMakefile = ((pnlamakefile) ? pnlamakefile->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jref1NRelease = ((pnl1nrelease) ? pnl1nrelease->jref : 0);
	statshr.jrefSup1NMachine = ((pnlsup1nmachine) ? pnlsup1nmachine->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmMchRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMCH) {
		WznmMMachine* _recMch = NULL;

		if (dbswznm->tblwznmmmachine->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMCH, jref), &_recMch)) {
			recMch = *_recMch;
			delete _recMch;
		} else recMch = WznmMMachine();

		if (recMch.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlamakefile) pnlamakefile->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nrelease) pnl1nrelease->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsup1nmachine) pnlsup1nmachine->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmMchRec::minimize(
			DbsWznm* dbswznm
			, const bool notif
			, DpchEngWznm** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWznmVExpstate != VecWznmVExpstate::MIND) {
		statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswznm, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWznmMchRec::regularize(
			DbsWznm* dbswznm
			, const bool notif
			, DpchEngWznm** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWznmVExpstate != VecWznmVExpstate::REGD) {
		statshr.ixWznmVExpstate = VecWznmVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswznm, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWznmMchRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmMchRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmMchRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmMchRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmMchRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMMCHUPD_REFEQ) {
		call->abort = handleCallWznmMchUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMCH_SUPEQ) {
		call->abort = handleCallWznmMch_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMCH_CCHEQ) {
		call->abort = handleCallWznmMch_cchEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmMchRec::handleCallWznmMchUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmMchUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmMchRec::handleCallWznmMch_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMch.supRefWznmMMachine == refInv); // IP handleCallWznmMch_supEq --- LINE
	return retval;
};

bool PnlWznmMchRec::handleCallWznmMch_cchEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMch.cchRefWznmMMachine == refInv); // IP handleCallWznmMch_cchEq --- LINE
	return retval;
};



