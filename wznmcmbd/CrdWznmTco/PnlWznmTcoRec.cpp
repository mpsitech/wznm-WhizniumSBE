/**
	* \file PnlWznmTcoRec.cpp
	* job handler for job PnlWznmTcoRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmTcoRec.h"

#include "PnlWznmTcoRec_blks.cpp"
#include "PnlWznmTcoRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmTcoRec
 ******************************************************************************/

PnlWznmTcoRec::PnlWznmTcoRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMTCOREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnl1ncheck = NULL;
	pnlref1ncontrol = NULL;
	pnlref1nquerymod = NULL;
	pnl1nquerycol = NULL;
	pnl1nimpexpcol = NULL;
	pnlatitle = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_TBLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_TBL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_SBSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_RELEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_FCUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTCO_FCTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFTCO, jref);
};

PnlWznmTcoRec::~PnlWznmTcoRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmTcoRec::getNewDpchEng(
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

void PnlWznmTcoRec::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWznm::getStubTcoStd(dbswznm, recTco.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recTco.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlatitleAvail = evalPnlatitleAvail(dbswznm);
	statshr.pnl1nimpexpcolAvail = evalPnl1nimpexpcolAvail(dbswznm);
	statshr.pnl1nquerycolAvail = evalPnl1nquerycolAvail(dbswznm);
	statshr.pnlref1nquerymodAvail = evalPnlref1nquerymodAvail(dbswznm);
	statshr.pnlref1ncontrolAvail = evalPnlref1ncontrolAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlatitle) {delete pnlatitle; pnlatitle = NULL;};
		if (pnl1nimpexpcol) {delete pnl1nimpexpcol; pnl1nimpexpcol = NULL;};
		if (pnl1nquerycol) {delete pnl1nquerycol; pnl1nquerycol = NULL;};
		if (pnlref1nquerymod) {delete pnlref1nquerymod; pnlref1nquerymod = NULL;};
		if (pnlref1ncontrol) {delete pnlref1ncontrol; pnlref1ncontrol = NULL;};
		if (pnl1ncheck) {delete pnl1ncheck; pnl1ncheck = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmTcoDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlatitle) pnlatitle = new PnlWznmTcoATitle(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nimpexpcol) pnl1nimpexpcol = new PnlWznmTco1NImpexpcol(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nquerycol) pnl1nquerycol = new PnlWznmTco1NQuerycol(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1nquerymod) pnlref1nquerymod = new PnlWznmTcoRef1NQuerymod(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1ncontrol) pnlref1ncontrol = new PnlWznmTcoRef1NControl(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ncheck) pnl1ncheck = new PnlWznmTco1NCheck(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefATitle = ((pnlatitle) ? pnlatitle->jref : 0);
	statshr.jref1NImpexpcol = ((pnl1nimpexpcol) ? pnl1nimpexpcol->jref : 0);
	statshr.jref1NQuerycol = ((pnl1nquerycol) ? pnl1nquerycol->jref : 0);
	statshr.jrefRef1NQuerymod = ((pnlref1nquerymod) ? pnlref1nquerymod->jref : 0);
	statshr.jrefRef1NControl = ((pnlref1ncontrol) ? pnlref1ncontrol->jref : 0);
	statshr.jref1NCheck = ((pnl1ncheck) ? pnl1ncheck->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmTcoRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFTCO) {
		WznmMTablecol* _recTco = NULL;

		if (dbswznm->tblwznmmtablecol->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTCO, jref), &_recTco)) {
			recTco = *_recTco;
			ixWSubsetTco = dbswznm->getIxWSubsetByWznmMTablecol(_recTco);
			delete _recTco;
		} else {
			recTco = WznmMTablecol();
			ixWSubsetTco = 0;
		};

		if (recTco.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlatitle) pnlatitle->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nimpexpcol) pnl1nimpexpcol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nquerycol) pnl1nquerycol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1nquerymod) pnlref1nquerymod->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1ncontrol) pnlref1ncontrol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ncheck) pnl1ncheck->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmTcoRec::minimize(
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

void PnlWznmTcoRec::regularize(
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

void PnlWznmTcoRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCORECDO) {
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

void PnlWznmTcoRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmTcoRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmTcoRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmTcoRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTCOUPD_REFEQ) {
		call->abort = handleCallWznmTcoUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_TBLEQ) {
		call->abort = handleCallWznmTco_tblEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_TBL_INSBS) {
		call->abort = handleCallWznmTco_tbl_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_SBSEQ) {
		call->abort = handleCallWznmTco_sbsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_RELEQ) {
		call->abort = handleCallWznmTco_relEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_INSBS) {
		call->abort = handleCallWznmTco_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_FCUEQ) {
		call->abort = handleCallWznmTco_fcuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCO_FCTEQ) {
		call->abort = handleCallWznmTco_fctEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWznmTcoRec::handleCallWznmTcoUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmTcoUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmTcoRec::handleCallWznmTco_tblEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.tblRefWznmMTable == refInv); // IP handleCallWznmTco_tblEq --- LINE
	return retval;
};

bool PnlWznmTcoRec::handleCallWznmTco_tbl_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswznm->getIxWSubsetByRefWznmMTable(recTco.tblRefWznmMTable) & ixInv) != 0); // IP handleCallWznmTco_tbl_inSbs --- LINE
	return retval;
};

bool PnlWznmTcoRec::handleCallWznmTco_sbsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.refWznmMSubset == refInv); // IP handleCallWznmTco_sbsEq --- LINE
	return retval;
};

bool PnlWznmTcoRec::handleCallWznmTco_relEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.refWznmMRelation == refInv); // IP handleCallWznmTco_relEq --- LINE
	return retval;
};

bool PnlWznmTcoRec::handleCallWznmTco_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetTco & ixInv) != 0); // IP handleCallWznmTco_inSbs --- LINE
	return retval;
};

bool PnlWznmTcoRec::handleCallWznmTco_fcuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.fctUref == refInv); // IP handleCallWznmTco_fcuEq --- LINE
	return retval;
};

bool PnlWznmTcoRec::handleCallWznmTco_fctEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTco.fctIxVTbl == ixInv); // IP handleCallWznmTco_fctEq --- LINE
	return retval;
};

