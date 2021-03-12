/**
	* \file PnlWznmVerRec.cpp
	* job handler for job PnlWznmVerRec (implementation)
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

#include "PnlWznmVerRec.h"

#include "PnlWznmVerRec_blks.cpp"
#include "PnlWznmVerRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmVerRec
 ******************************************************************************/

PnlWznmVerRec::PnlWznmVerRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMVERREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlmnlocale = NULL;
	pnlref1nfile = NULL;
	pnl1ncall = NULL;
	pnl1ncomponent = NULL;
	pnl1nblock = NULL;
	pnlbvr1nversion = NULL;
	pnl1njob = NULL;
	pnl1nimpexpcplx = NULL;
	pnl1nvector = NULL;
	pnlver1nerror = NULL;
	pnl1ntable = NULL;
	pnl1nrelation = NULL;
	pnl1nquery = NULL;
	pnl1noppack = NULL;
	pnlver1nmodule = NULL;
	pnl1npreset = NULL;
	pnl1ncapability = NULL;
	pnlver1napp = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMVER_STEEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVER_PRJEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVER_LOCEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVER_BVREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVER, jref);
};

PnlWznmVerRec::~PnlWznmVerRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmVerRec::getNewDpchEng(
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

void PnlWznmVerRec::refresh(
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
	continf.TxtRef = StubWznm::getStubVerStd(dbswznm, recVer.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recVer.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1ncapability) {delete pnl1ncapability; pnl1ncapability = NULL;};
		if (pnlver1napp) {delete pnlver1napp; pnlver1napp = NULL;};
		if (pnl1noppack) {delete pnl1noppack; pnl1noppack = NULL;};
		if (pnlver1nmodule) {delete pnlver1nmodule; pnlver1nmodule = NULL;};
		if (pnl1npreset) {delete pnl1npreset; pnl1npreset = NULL;};
		if (pnl1nquery) {delete pnl1nquery; pnl1nquery = NULL;};
		if (pnl1nrelation) {delete pnl1nrelation; pnl1nrelation = NULL;};
		if (pnl1ntable) {delete pnl1ntable; pnl1ntable = NULL;};
		if (pnlver1nerror) {delete pnlver1nerror; pnlver1nerror = NULL;};
		if (pnl1nvector) {delete pnl1nvector; pnl1nvector = NULL;};
		if (pnl1nimpexpcplx) {delete pnl1nimpexpcplx; pnl1nimpexpcplx = NULL;};
		if (pnl1njob) {delete pnl1njob; pnl1njob = NULL;};
		if (pnl1ncall) {delete pnl1ncall; pnl1ncall = NULL;};
		if (pnl1ncomponent) {delete pnl1ncomponent; pnl1ncomponent = NULL;};
		if (pnl1nblock) {delete pnl1nblock; pnl1nblock = NULL;};
		if (pnlbvr1nversion) {delete pnlbvr1nversion; pnlbvr1nversion = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
		if (pnlmnlocale) {delete pnlmnlocale; pnlmnlocale = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmVerDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ncapability) pnl1ncapability = new PnlWznmVer1NCapability(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlver1napp) pnlver1napp = new PnlWznmVerVer1NApp(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1noppack) pnl1noppack = new PnlWznmVer1NOppack(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlver1nmodule) pnlver1nmodule = new PnlWznmVerVer1NModule(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1npreset) pnl1npreset = new PnlWznmVer1NPreset(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nquery) pnl1nquery = new PnlWznmVer1NQuery(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nrelation) pnl1nrelation = new PnlWznmVer1NRelation(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ntable) pnl1ntable = new PnlWznmVer1NTable(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlver1nerror) pnlver1nerror = new PnlWznmVerVer1NError(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nvector) pnl1nvector = new PnlWznmVer1NVector(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nimpexpcplx) pnl1nimpexpcplx = new PnlWznmVer1NImpexpcplx(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1njob) pnl1njob = new PnlWznmVer1NJob(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ncall) pnl1ncall = new PnlWznmVer1NCall(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ncomponent) pnl1ncomponent = new PnlWznmVer1NComponent(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nblock) pnl1nblock = new PnlWznmVer1NBlock(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlbvr1nversion) pnlbvr1nversion = new PnlWznmVerBvr1NVersion(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlWznmVerRef1NFile(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnlocale) pnlmnlocale = new PnlWznmVerMNLocale(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NCapability = ((pnl1ncapability) ? pnl1ncapability->jref : 0);
	statshr.jrefVer1NApp = ((pnlver1napp) ? pnlver1napp->jref : 0);
	statshr.jref1NOppack = ((pnl1noppack) ? pnl1noppack->jref : 0);
	statshr.jrefVer1NModule = ((pnlver1nmodule) ? pnlver1nmodule->jref : 0);
	statshr.jref1NPreset = ((pnl1npreset) ? pnl1npreset->jref : 0);
	statshr.jref1NQuery = ((pnl1nquery) ? pnl1nquery->jref : 0);
	statshr.jref1NRelation = ((pnl1nrelation) ? pnl1nrelation->jref : 0);
	statshr.jref1NTable = ((pnl1ntable) ? pnl1ntable->jref : 0);
	statshr.jrefVer1NError = ((pnlver1nerror) ? pnlver1nerror->jref : 0);
	statshr.jref1NVector = ((pnl1nvector) ? pnl1nvector->jref : 0);
	statshr.jref1NImpexpcplx = ((pnl1nimpexpcplx) ? pnl1nimpexpcplx->jref : 0);
	statshr.jref1NJob = ((pnl1njob) ? pnl1njob->jref : 0);
	statshr.jref1NCall = ((pnl1ncall) ? pnl1ncall->jref : 0);
	statshr.jref1NComponent = ((pnl1ncomponent) ? pnl1ncomponent->jref : 0);
	statshr.jref1NBlock = ((pnl1nblock) ? pnl1nblock->jref : 0);
	statshr.jrefBvr1NVersion = ((pnlbvr1nversion) ? pnlbvr1nversion->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);
	statshr.jrefMNLocale = ((pnlmnlocale) ? pnlmnlocale->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmVerRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFVER) {
		WznmMVersion* _recVer = NULL;

		if (dbswznm->tblwznmmversion->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref), &_recVer)) {
			recVer = *_recVer;
			delete _recVer;
		} else recVer = WznmMVersion();

		if (recVer.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ncapability) pnl1ncapability->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlver1napp) pnlver1napp->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1noppack) pnl1noppack->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlver1nmodule) pnlver1nmodule->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1npreset) pnl1npreset->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nquery) pnl1nquery->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nrelation) pnl1nrelation->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ntable) pnl1ntable->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlver1nerror) pnlver1nerror->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nvector) pnl1nvector->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nimpexpcplx) pnl1nimpexpcplx->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1njob) pnl1njob->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ncall) pnl1ncall->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ncomponent) pnl1ncomponent->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nblock) pnl1nblock->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlbvr1nversion) pnlbvr1nversion->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnlocale) pnlmnlocale->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmVerRec::minimize(
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

void PnlWznmVerRec::regularize(
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

void PnlWznmVerRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERRECDO) {
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

void PnlWznmVerRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmVerRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmVerRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmVerRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMVERUPD_REFEQ) {
		call->abort = handleCallWznmVerUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVER_STEEQ) {
		call->abort = handleCallWznmVer_steEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVER_PRJEQ) {
		call->abort = handleCallWznmVer_prjEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVER_LOCEQ) {
		call->abort = handleCallWznmVer_locEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVER_BVREQ) {
		call->abort = handleCallWznmVer_bvrEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmVerRec::handleCallWznmVerUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmVerUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmVerRec::handleCallWznmVer_steEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.ixVState == ixInv); // IP handleCallWznmVer_steEq --- LINE
	return retval;
};

bool PnlWznmVerRec::handleCallWznmVer_prjEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.prjRefWznmMProject == refInv); // IP handleCallWznmVer_prjEq --- LINE
	return retval;
};

bool PnlWznmVerRec::handleCallWznmVer_locEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.refWznmMLocale == refInv); // IP handleCallWznmVer_locEq --- LINE
	return retval;
};

bool PnlWznmVerRec::handleCallWznmVer_bvrEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.bvrRefWznmMVersion == refInv); // IP handleCallWznmVer_bvrEq --- LINE
	return retval;
};
