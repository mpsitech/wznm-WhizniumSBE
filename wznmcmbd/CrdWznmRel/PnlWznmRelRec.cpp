/**
	* \file PnlWznmRelRec.cpp
	* job handler for job PnlWznmRelRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmRelRec.h"

#include "PnlWznmRelRec_blks.cpp"
#include "PnlWznmRelRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmRelRec
 ******************************************************************************/

PnlWznmRelRec::PnlWznmRelRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMRELREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlref1ndialog = NULL;
	pnlref1ncontrol = NULL;
	pnlref1npanel = NULL;
	pnlsup1nrelation = NULL;
	pnl1ntablecol = NULL;
	pnlatitle = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMREL_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_TOSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_FRSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMREL_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFREL, jref);
};

PnlWznmRelRec::~PnlWznmRelRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmRelRec::getNewDpchEng(
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

void PnlWznmRelRec::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWznm::getStubRelStd(dbswznm, recRel.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recRel.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlatitle) {delete pnlatitle; pnlatitle = NULL;};
		if (pnl1ntablecol) {delete pnl1ntablecol; pnl1ntablecol = NULL;};
		if (pnlsup1nrelation) {delete pnlsup1nrelation; pnlsup1nrelation = NULL;};
		if (pnlref1npanel) {delete pnlref1npanel; pnlref1npanel = NULL;};
		if (pnlref1ncontrol) {delete pnlref1ncontrol; pnlref1ncontrol = NULL;};
		if (pnlref1ndialog) {delete pnlref1ndialog; pnlref1ndialog = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmRelDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlatitle) pnlatitle = new PnlWznmRelATitle(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ntablecol) pnl1ntablecol = new PnlWznmRel1NTablecol(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsup1nrelation) pnlsup1nrelation = new PnlWznmRelSup1NRelation(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1npanel) pnlref1npanel = new PnlWznmRelRef1NPanel(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1ncontrol) pnlref1ncontrol = new PnlWznmRelRef1NControl(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1ndialog) pnlref1ndialog = new PnlWznmRelRef1NDialog(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefATitle = ((pnlatitle) ? pnlatitle->jref : 0);
	statshr.jref1NTablecol = ((pnl1ntablecol) ? pnl1ntablecol->jref : 0);
	statshr.jrefSup1NRelation = ((pnlsup1nrelation) ? pnlsup1nrelation->jref : 0);
	statshr.jrefRef1NPanel = ((pnlref1npanel) ? pnlref1npanel->jref : 0);
	statshr.jrefRef1NControl = ((pnlref1ncontrol) ? pnlref1ncontrol->jref : 0);
	statshr.jrefRef1NDialog = ((pnlref1ndialog) ? pnlref1ndialog->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmRelRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFREL) {
		WznmMRelation* _recRel = NULL;

		if (dbswznm->tblwznmmrelation->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFREL, jref), &_recRel)) {
			recRel = *_recRel;
			delete _recRel;
		} else recRel = WznmMRelation();

		if (recRel.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlatitle) pnlatitle->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ntablecol) pnl1ntablecol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsup1nrelation) pnlsup1nrelation->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1npanel) pnlref1npanel->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1ncontrol) pnlref1ncontrol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1ndialog) pnlref1ndialog->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmRelRec::minimize(
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

void PnlWznmRelRec::regularize(
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

void PnlWznmRelRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELRECDO) {
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

void PnlWznmRelRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmRelRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmRelRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmRelRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMRELUPD_REFEQ) {
		call->abort = handleCallWznmRelUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_VEREQ) {
		call->abort = handleCallWznmRel_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_TOSEQ) {
		call->abort = handleCallWznmRel_tosEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_SUPEQ) {
		call->abort = handleCallWznmRel_supEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_FRSEQ) {
		call->abort = handleCallWznmRel_frsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMREL_CLUEQ) {
		call->abort = handleCallWznmRel_cluEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmRelRec::handleCallWznmRelUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmRelUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmRelRec::handleCallWznmRel_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.refWznmMVersion == refInv); // IP handleCallWznmRel_verEq --- LINE
	return retval;
};

bool PnlWznmRelRec::handleCallWznmRel_tosEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.tosRefWznmMSubset == refInv); // IP handleCallWznmRel_tosEq --- LINE
	return retval;
};

bool PnlWznmRelRec::handleCallWznmRel_supEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.supRefWznmMRelation == refInv); // IP handleCallWznmRel_supEq --- LINE
	return retval;
};

bool PnlWznmRelRec::handleCallWznmRel_frsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.frsRefWznmMSubset == refInv); // IP handleCallWznmRel_frsEq --- LINE
	return retval;
};

bool PnlWznmRelRec::handleCallWznmRel_cluEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recRel.refWznmCRelation == refInv); // IP handleCallWznmRel_cluEq --- LINE
	return retval;
};

