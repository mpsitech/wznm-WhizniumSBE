/**
	* \file PnlWznmLocRec.cpp
	* job handler for job PnlWznmLocRec (implementation)
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

#include "PnlWznmLocRec.h"

#include "PnlWznmLocRec_blks.cpp"
#include "PnlWznmLocRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmLocRec
 ******************************************************************************/

PnlWznmLocRec::PnlWznmLocRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMLOCREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnldetail = NULL;
	pnlmnversion = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFLOC, jref);
};

PnlWznmLocRec::~PnlWznmLocRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmLocRec::getNewDpchEng(
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

void PnlWznmLocRec::refresh(
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
	continf.TxtRef = StubWznm::getStubLocStd(dbswznm, recLoc.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recLoc.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlmnversion) {delete pnlmnversion; pnlmnversion = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmLocDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnversion) pnlmnversion = new PnlWznmLocMNVersion(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefMNVersion = ((pnlmnversion) ? pnlmnversion->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmLocRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFLOC) {
		WznmMLocale* _recLoc = NULL;

		if (dbswznm->tblwznmmlocale->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFLOC, jref), &_recLoc)) {
			recLoc = *_recLoc;
			delete _recLoc;
		} else recLoc = WznmMLocale();

		if (recLoc.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnversion) pnlmnversion->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmLocRec::minimize(
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

void PnlWznmLocRec::regularize(
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

void PnlWznmLocRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCRECDO) {
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

void PnlWznmLocRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmLocRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmLocRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmLocRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMLOCUPD_REFEQ) {
		call->abort = handleCallWznmLocUpd_refEq(dbswznm, call->jref);
	};
};

bool PnlWznmLocRec::handleCallWznmLocUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmLocUpd_refEq --- INSERT
	return retval;
};
