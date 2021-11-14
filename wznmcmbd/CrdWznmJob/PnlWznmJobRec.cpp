/**
	* \file PnlWznmJobRec.cpp
	* job handler for job PnlWznmJobRec (implementation)
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

#include "PnlWznmJobRec.h"

#include "PnlWznmJobRec_blks.cpp"
#include "PnlWznmJobRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmJobRec
 ******************************************************************************/

PnlWznmJobRec::PnlWznmJobRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMJOBREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlsubmnjob = NULL;
	pnlsupmnjob = NULL;
	pnlmnoppack = NULL;
	pnlmnop = NULL;
	pnlref1nblock = NULL;
	pnlhk1nvector = NULL;
	pnl1nrtjob = NULL;
	pnljob1nstage = NULL;
	pnl1nmethod = NULL;
	pnl1nsensitivity = NULL;
	pnlavar = NULL;
	pnlacmd = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMJOB_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMJOB_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMJOB_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMJOB_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFJOB, jref);
};

PnlWznmJobRec::~PnlWznmJobRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmJobRec::getNewDpchEng(
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

void PnlWznmJobRec::refresh(
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
	continf.TxtRef = StubWznm::getStubJobStd(dbswznm, recJob.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recJob.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlsubmnjobAvail = evalPnlsubmnjobAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlavar) {delete pnlavar; pnlavar = NULL;};
		if (pnlacmd) {delete pnlacmd; pnlacmd = NULL;};
		if (pnl1nmethod) {delete pnl1nmethod; pnl1nmethod = NULL;};
		if (pnl1nsensitivity) {delete pnl1nsensitivity; pnl1nsensitivity = NULL;};
		if (pnljob1nstage) {delete pnljob1nstage; pnljob1nstage = NULL;};
		if (pnl1nrtjob) {delete pnl1nrtjob; pnl1nrtjob = NULL;};
		if (pnlhk1nvector) {delete pnlhk1nvector; pnlhk1nvector = NULL;};
		if (pnlref1nblock) {delete pnlref1nblock; pnlref1nblock = NULL;};
		if (pnlmnoppack) {delete pnlmnoppack; pnlmnoppack = NULL;};
		if (pnlmnop) {delete pnlmnop; pnlmnop = NULL;};
		if (pnlsupmnjob) {delete pnlsupmnjob; pnlsupmnjob = NULL;};
		if (pnlsubmnjob) {delete pnlsubmnjob; pnlsubmnjob = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmJobDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlavar) pnlavar = new PnlWznmJobAVar(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlacmd) pnlacmd = new PnlWznmJobACmd(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nmethod) pnl1nmethod = new PnlWznmJob1NMethod(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nsensitivity) pnl1nsensitivity = new PnlWznmJob1NSensitivity(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnljob1nstage) pnljob1nstage = new PnlWznmJobJob1NStage(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nrtjob) pnl1nrtjob = new PnlWznmJob1NRtjob(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlhk1nvector) pnlhk1nvector = new PnlWznmJobHk1NVector(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1nblock) pnlref1nblock = new PnlWznmJobRef1NBlock(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnoppack) pnlmnoppack = new PnlWznmJobMNOppack(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnop) pnlmnop = new PnlWznmJobMNOp(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsupmnjob) pnlsupmnjob = new PnlWznmJobSupMNJob(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsubmnjob) pnlsubmnjob = new PnlWznmJobSubMNJob(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAVar = ((pnlavar) ? pnlavar->jref : 0);
	statshr.jrefACmd = ((pnlacmd) ? pnlacmd->jref : 0);
	statshr.jref1NMethod = ((pnl1nmethod) ? pnl1nmethod->jref : 0);
	statshr.jref1NSensitivity = ((pnl1nsensitivity) ? pnl1nsensitivity->jref : 0);
	statshr.jrefJob1NStage = ((pnljob1nstage) ? pnljob1nstage->jref : 0);
	statshr.jref1NRtjob = ((pnl1nrtjob) ? pnl1nrtjob->jref : 0);
	statshr.jrefHk1NVector = ((pnlhk1nvector) ? pnlhk1nvector->jref : 0);
	statshr.jrefRef1NBlock = ((pnlref1nblock) ? pnlref1nblock->jref : 0);
	statshr.jrefMNOppack = ((pnlmnoppack) ? pnlmnoppack->jref : 0);
	statshr.jrefMNOp = ((pnlmnop) ? pnlmnop->jref : 0);
	statshr.jrefSupMNJob = ((pnlsupmnjob) ? pnlsupmnjob->jref : 0);
	statshr.jrefSubMNJob = ((pnlsubmnjob) ? pnlsubmnjob->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmJobRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFJOB) {
		WznmMJob* _recJob = NULL;

		if (dbswznm->tblwznmmjob->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref), &_recJob)) {
			recJob = *_recJob;
			delete _recJob;
		} else recJob = WznmMJob();

		if (recJob.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlavar) pnlavar->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlacmd) pnlacmd->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nmethod) pnl1nmethod->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nsensitivity) pnl1nsensitivity->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnljob1nstage) pnljob1nstage->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nrtjob) pnl1nrtjob->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlhk1nvector) pnlhk1nvector->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1nblock) pnlref1nblock->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnoppack) pnlmnoppack->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnop) pnlmnop->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsupmnjob) pnlsupmnjob->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsubmnjob) pnlsubmnjob->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmJobRec::minimize(
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

void PnlWznmJobRec::regularize(
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

void PnlWznmJobRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBRECDO) {
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

void PnlWznmJobRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmJobRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmJobRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmJobRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMJOBUPD_REFEQ) {
		call->abort = handleCallWznmJobUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMJOB_RETEQ) {
		call->abort = handleCallWznmJob_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMJOB_REUEQ) {
		call->abort = handleCallWznmJob_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMJOB_TYPEQ) {
		call->abort = handleCallWznmJob_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMJOB_VEREQ) {
		call->abort = handleCallWznmJob_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmJobRec::handleCallWznmJobUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmJobUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmJobRec::handleCallWznmJob_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recJob.refIxVTbl == ixInv); // IP handleCallWznmJob_retEq --- LINE
	return retval;
};

bool PnlWznmJobRec::handleCallWznmJob_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recJob.refUref == refInv); // IP handleCallWznmJob_reuEq --- LINE
	return retval;
};

bool PnlWznmJobRec::handleCallWznmJob_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recJob.ixVBasetype == ixInv); // IP handleCallWznmJob_typEq --- LINE
	return retval;
};

bool PnlWznmJobRec::handleCallWznmJob_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recJob.refWznmMVersion == refInv); // IP handleCallWznmJob_verEq --- LINE
	return retval;
};
