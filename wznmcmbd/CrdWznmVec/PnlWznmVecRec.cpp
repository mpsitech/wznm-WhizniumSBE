/**
	* \file PnlWznmVecRec.cpp
	* job handler for job PnlWznmVecRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmVecRec.h"

#include "PnlWznmVecRec_blks.cpp"
#include "PnlWznmVecRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmVecRec
 ******************************************************************************/

PnlWznmVecRec::PnlWznmVecRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMVECREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlmntable = NULL;
	pnlpst1nquerymod = NULL;
	pnlref1npanel = NULL;
	pnlsrc1nfeed = NULL;
	pnlfct1ntablecol = NULL;
	pnlvec1nvectoritem = NULL;
	pnlatitle = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_PSTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMVEC_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVEC, jref);
};

PnlWznmVecRec::~PnlWznmVecRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmVecRec::getNewDpchEng(
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

void PnlWznmVecRec::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWznm::getStubVecStd(dbswznm, recVec.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recVec.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlfct1ntablecolAvail = evalPnlfct1ntablecolAvail(dbswznm);
	statshr.pnlpst1nquerymodAvail = evalPnlpst1nquerymodAvail(dbswznm);
	statshr.pnlmntableAvail = evalPnlmntableAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlatitle) {delete pnlatitle; pnlatitle = NULL;};
		if (pnlvec1nvectoritem) {delete pnlvec1nvectoritem; pnlvec1nvectoritem = NULL;};
		if (pnlfct1ntablecol) {delete pnlfct1ntablecol; pnlfct1ntablecol = NULL;};
		if (pnlref1npanel) {delete pnlref1npanel; pnlref1npanel = NULL;};
		if (pnlsrc1nfeed) {delete pnlsrc1nfeed; pnlsrc1nfeed = NULL;};
		if (pnlpst1nquerymod) {delete pnlpst1nquerymod; pnlpst1nquerymod = NULL;};
		if (pnlmntable) {delete pnlmntable; pnlmntable = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmVecDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlatitle) pnlatitle = new PnlWznmVecATitle(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlvec1nvectoritem) pnlvec1nvectoritem = new PnlWznmVecVec1NVectoritem(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlfct1ntablecol) pnlfct1ntablecol = new PnlWznmVecFct1NTablecol(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1npanel) pnlref1npanel = new PnlWznmVecRef1NPanel(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsrc1nfeed) pnlsrc1nfeed = new PnlWznmVecSrc1NFeed(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlpst1nquerymod) pnlpst1nquerymod = new PnlWznmVecPst1NQuerymod(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmntable) pnlmntable = new PnlWznmVecMNTable(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefATitle = ((pnlatitle) ? pnlatitle->jref : 0);
	statshr.jrefVec1NVectoritem = ((pnlvec1nvectoritem) ? pnlvec1nvectoritem->jref : 0);
	statshr.jrefFct1NTablecol = ((pnlfct1ntablecol) ? pnlfct1ntablecol->jref : 0);
	statshr.jrefRef1NPanel = ((pnlref1npanel) ? pnlref1npanel->jref : 0);
	statshr.jrefSrc1NFeed = ((pnlsrc1nfeed) ? pnlsrc1nfeed->jref : 0);
	statshr.jrefPst1NQuerymod = ((pnlpst1nquerymod) ? pnlpst1nquerymod->jref : 0);
	statshr.jrefMNTable = ((pnlmntable) ? pnlmntable->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmVecRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFVEC) {
		WznmMVector* _recVec = NULL;
		WznmMPreset* _recPst = NULL;

		if (dbswznm->tblwznmmvector->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVEC, jref), &_recVec)) {
			recVec = *_recVec;
			ixWSubsetVec = dbswznm->getIxWSubsetByWznmMVector(_recVec);
			delete _recVec;
		} else {
			recVec = WznmMVector();
			ixWSubsetVec = 0;
		};

		if (dbswznm->tblwznmmpreset->loadRecByRef(recVec.refWznmMPreset, &_recPst)) {
			recPst = *_recPst;
			delete _recPst;
		} else recPst = WznmMPreset();

		if (recVec.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlatitle) pnlatitle->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlvec1nvectoritem) pnlvec1nvectoritem->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlfct1ntablecol) pnlfct1ntablecol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1npanel) pnlref1npanel->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsrc1nfeed) pnlsrc1nfeed->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlpst1nquerymod) pnlpst1nquerymod->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmntable) pnlmntable->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmVecRec::minimize(
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

void PnlWznmVecRec::regularize(
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

void PnlWznmVecRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECRECDO) {
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

void PnlWznmVecRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmVecRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmVecRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmVecRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMVECUPD_REFEQ) {
		call->abort = handleCallWznmVecUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPSTUPD_REFEQ) {
		call->abort = handleCallWznmPstUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_VEREQ) {
		call->abort = handleCallWznmVec_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_TYPEQ) {
		call->abort = handleCallWznmVec_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_PSTEQ) {
		call->abort = handleCallWznmVec_pstEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_INSBS) {
		call->abort = handleCallWznmVec_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_HKUEQ) {
		call->abort = handleCallWznmVec_hkuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVEC_HKTEQ) {
		call->abort = handleCallWznmVec_hktEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_VEREQ) {
		call->abort = handleCallWznmPst_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_REUEQ) {
		call->abort = handleCallWznmPst_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_RETEQ) {
		call->abort = handleCallWznmPst_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWznmVecRec::handleCallWznmVecUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmVecUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmVecRec::handleCallWznmPstUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPstUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmVecRec::handleCallWznmVec_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.refWznmMVersion == refInv); // IP handleCallWznmVec_verEq --- LINE
	return retval;
};

bool PnlWznmVecRec::handleCallWznmVec_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.ixVBasetype == ixInv); // IP handleCallWznmVec_typEq --- LINE
	return retval;
};

bool PnlWznmVecRec::handleCallWznmVec_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.refWznmMPreset == refInv); // IP handleCallWznmVec_pstEq --- LINE
	return retval;
};

bool PnlWznmVecRec::handleCallWznmVec_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetVec & ixInv) != 0); // IP handleCallWznmVec_inSbs --- LINE
	return retval;
};

bool PnlWznmVecRec::handleCallWznmVec_hkuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.hkUref == refInv); // IP handleCallWznmVec_hkuEq --- LINE
	return retval;
};

bool PnlWznmVecRec::handleCallWznmVec_hktEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.hkIxVTbl == ixInv); // IP handleCallWznmVec_hktEq --- LINE
	return retval;
};

bool PnlWznmVecRec::handleCallWznmPst_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refWznmMVersion == refInv); // IP handleCallWznmPst_verEq --- LINE
	return retval;
};

bool PnlWznmVecRec::handleCallWznmPst_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refUref == refInv); // IP handleCallWznmPst_reuEq --- LINE
	return retval;
};

bool PnlWznmVecRec::handleCallWznmPst_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refIxVTbl == ixInv); // IP handleCallWznmPst_retEq --- LINE
	return retval;
};

