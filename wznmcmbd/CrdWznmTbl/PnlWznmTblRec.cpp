/**
	* \file PnlWznmTblRec.cpp
	* job handler for job PnlWznmTblRec (implementation)
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

#include "PnlWznmTblRec.h"

#include "PnlWznmTblRec_blks.cpp"
#include "PnlWznmTblRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmTblRec
 ******************************************************************************/

PnlWznmTblRec::PnlWznmTblRec(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMTBLREC, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	pnlmnquery = NULL;
	pnlmnvector = NULL;
	pnlpst1nquerymod = NULL;
	pnlref1ndialog = NULL;
	pnlref1ncall = NULL;
	pnlhk1nvector = NULL;
	pnlref1nquerymod = NULL;
	pnlref1nrtblock = NULL;
	pnlref1npanel = NULL;
	pnlsrc1nfeed = NULL;
	pnlfct1ntablecol = NULL;
	pnl1ncheck = NULL;
	pnl1nimpexp = NULL;
	pnlto1nrelation = NULL;
	pnlfr1nrelation = NULL;
	pnl1nsubset = NULL;
	pnl1nstub = NULL;
	pnltbl1ntablecol = NULL;
	pnlaloadfct = NULL;
	pnlatitle = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_PSTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_CAREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMTBL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMPST_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFTBL, jref);
};

PnlWznmTblRec::~PnlWznmTblRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmTblRec::getNewDpchEng(
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

void PnlWznmTblRec::refresh(
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
	continf.TxtRef = StubWznm::getStubTblStd(dbswznm, recTbl.ref, ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recTbl.ref == 0) statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;

	statshr.pnlatitleAvail = evalPnlatitleAvail(dbswznm);
	statshr.pnlaloadfctAvail = evalPnlaloadfctAvail(dbswznm);
	statshr.pnl1nstubAvail = evalPnl1nstubAvail(dbswznm);
	statshr.pnl1nsubsetAvail = evalPnl1nsubsetAvail(dbswznm);
	statshr.pnlfr1nrelationAvail = evalPnlfr1nrelationAvail(dbswznm);
	statshr.pnlto1nrelationAvail = evalPnlto1nrelationAvail(dbswznm);
	statshr.pnl1nimpexpAvail = evalPnl1nimpexpAvail(dbswznm);
	statshr.pnl1ncheckAvail = evalPnl1ncheckAvail(dbswznm);
	statshr.pnlfct1ntablecolAvail = evalPnlfct1ntablecolAvail(dbswznm);
	statshr.pnlref1ncallAvail = evalPnlref1ncallAvail(dbswznm);
	statshr.pnlref1ndialogAvail = evalPnlref1ndialogAvail(dbswznm);
	statshr.pnlpst1nquerymodAvail = evalPnlpst1nquerymodAvail(dbswznm);
	statshr.pnlmnvectorAvail = evalPnlmnvectorAvail(dbswznm);
	statshr.pnlmnqueryAvail = evalPnlmnqueryAvail(dbswznm);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswznm);

	if (statshr.ixWznmVExpstate == VecWznmVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlatitle) {delete pnlatitle; pnlatitle = NULL;};
		if (pnlaloadfct) {delete pnlaloadfct; pnlaloadfct = NULL;};
		if (pnltbl1ntablecol) {delete pnltbl1ntablecol; pnltbl1ntablecol = NULL;};
		if (pnl1nstub) {delete pnl1nstub; pnl1nstub = NULL;};
		if (pnl1nsubset) {delete pnl1nsubset; pnl1nsubset = NULL;};
		if (pnlfr1nrelation) {delete pnlfr1nrelation; pnlfr1nrelation = NULL;};
		if (pnlto1nrelation) {delete pnlto1nrelation; pnlto1nrelation = NULL;};
		if (pnl1nimpexp) {delete pnl1nimpexp; pnl1nimpexp = NULL;};
		if (pnl1ncheck) {delete pnl1ncheck; pnl1ncheck = NULL;};
		if (pnlfct1ntablecol) {delete pnlfct1ntablecol; pnlfct1ntablecol = NULL;};
		if (pnlsrc1nfeed) {delete pnlsrc1nfeed; pnlsrc1nfeed = NULL;};
		if (pnlref1npanel) {delete pnlref1npanel; pnlref1npanel = NULL;};
		if (pnlref1nrtblock) {delete pnlref1nrtblock; pnlref1nrtblock = NULL;};
		if (pnlref1nquerymod) {delete pnlref1nquerymod; pnlref1nquerymod = NULL;};
		if (pnlhk1nvector) {delete pnlhk1nvector; pnlhk1nvector = NULL;};
		if (pnlref1ncall) {delete pnlref1ncall; pnlref1ncall = NULL;};
		if (pnlref1ndialog) {delete pnlref1ndialog; pnlref1ndialog = NULL;};
		if (pnlpst1nquerymod) {delete pnlpst1nquerymod; pnlpst1nquerymod = NULL;};
		if (pnlmnvector) {delete pnlmnvector; pnlmnvector = NULL;};
		if (pnlmnquery) {delete pnlmnquery; pnlmnquery = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWznmTblDetail(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlatitle) pnlatitle = new PnlWznmTblATitle(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlaloadfct) pnlaloadfct = new PnlWznmTblALoadfct(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnltbl1ntablecol) pnltbl1ntablecol = new PnlWznmTblTbl1NTablecol(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nstub) pnl1nstub = new PnlWznmTbl1NStub(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nsubset) pnl1nsubset = new PnlWznmTbl1NSubset(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlfr1nrelation) pnlfr1nrelation = new PnlWznmTblFr1NRelation(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlto1nrelation) pnlto1nrelation = new PnlWznmTblTo1NRelation(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1nimpexp) pnl1nimpexp = new PnlWznmTbl1NImpexp(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnl1ncheck) pnl1ncheck = new PnlWznmTbl1NCheck(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlfct1ntablecol) pnlfct1ntablecol = new PnlWznmTblFct1NTablecol(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlsrc1nfeed) pnlsrc1nfeed = new PnlWznmTblSrc1NFeed(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1npanel) pnlref1npanel = new PnlWznmTblRef1NPanel(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1nrtblock) pnlref1nrtblock = new PnlWznmTblRef1NRtblock(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1nquerymod) pnlref1nquerymod = new PnlWznmTblRef1NQuerymod(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlhk1nvector) pnlhk1nvector = new PnlWznmTblHk1NVector(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1ncall) pnlref1ncall = new PnlWznmTblRef1NCall(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlref1ndialog) pnlref1ndialog = new PnlWznmTblRef1NDialog(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlpst1nquerymod) pnlpst1nquerymod = new PnlWznmTblPst1NQuerymod(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnvector) pnlmnvector = new PnlWznmTblMNVector(xchg, dbswznm, jref, ixWznmVLocale);
		if (!pnlmnquery) pnlmnquery = new PnlWznmTblMNQuery(xchg, dbswznm, jref, ixWznmVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefATitle = ((pnlatitle) ? pnlatitle->jref : 0);
	statshr.jrefALoadfct = ((pnlaloadfct) ? pnlaloadfct->jref : 0);
	statshr.jrefTbl1NTablecol = ((pnltbl1ntablecol) ? pnltbl1ntablecol->jref : 0);
	statshr.jref1NStub = ((pnl1nstub) ? pnl1nstub->jref : 0);
	statshr.jref1NSubset = ((pnl1nsubset) ? pnl1nsubset->jref : 0);
	statshr.jrefFr1NRelation = ((pnlfr1nrelation) ? pnlfr1nrelation->jref : 0);
	statshr.jrefTo1NRelation = ((pnlto1nrelation) ? pnlto1nrelation->jref : 0);
	statshr.jref1NImpexp = ((pnl1nimpexp) ? pnl1nimpexp->jref : 0);
	statshr.jref1NCheck = ((pnl1ncheck) ? pnl1ncheck->jref : 0);
	statshr.jrefFct1NTablecol = ((pnlfct1ntablecol) ? pnlfct1ntablecol->jref : 0);
	statshr.jrefSrc1NFeed = ((pnlsrc1nfeed) ? pnlsrc1nfeed->jref : 0);
	statshr.jrefRef1NPanel = ((pnlref1npanel) ? pnlref1npanel->jref : 0);
	statshr.jrefRef1NRtblock = ((pnlref1nrtblock) ? pnlref1nrtblock->jref : 0);
	statshr.jrefRef1NQuerymod = ((pnlref1nquerymod) ? pnlref1nquerymod->jref : 0);
	statshr.jrefHk1NVector = ((pnlhk1nvector) ? pnlhk1nvector->jref : 0);
	statshr.jrefRef1NCall = ((pnlref1ncall) ? pnlref1ncall->jref : 0);
	statshr.jrefRef1NDialog = ((pnlref1ndialog) ? pnlref1ndialog->jref : 0);
	statshr.jrefPst1NQuerymod = ((pnlpst1nquerymod) ? pnlpst1nquerymod->jref : 0);
	statshr.jrefMNVector = ((pnlmnvector) ? pnlmnvector->jref : 0);
	statshr.jrefMNQuery = ((pnlmnquery) ? pnlmnquery->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmTblRec::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFTBL) {
		WznmMTable* _recTbl = NULL;
		WznmMPreset* _recPst = NULL;

		if (dbswznm->tblwznmmtable->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref), &_recTbl)) {
			recTbl = *_recTbl;
			ixWSubsetTbl = dbswznm->getIxWSubsetByWznmMTable(_recTbl);
			delete _recTbl;
		} else {
			recTbl = WznmMTable();
			ixWSubsetTbl = 0;
		};

		if (dbswznm->tblwznmmpreset->loadRecByRef(recTbl.refWznmMPreset, &_recPst)) {
			recPst = *_recPst;
			delete _recPst;
		} else recPst = WznmMPreset();

		if (recTbl.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlatitle) pnlatitle->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlaloadfct) pnlaloadfct->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnltbl1ntablecol) pnltbl1ntablecol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nstub) pnl1nstub->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nsubset) pnl1nsubset->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlfr1nrelation) pnlfr1nrelation->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlto1nrelation) pnlto1nrelation->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1nimpexp) pnl1nimpexp->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnl1ncheck) pnl1ncheck->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlfct1ntablecol) pnlfct1ntablecol->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlsrc1nfeed) pnlsrc1nfeed->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1npanel) pnlref1npanel->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1nrtblock) pnlref1nrtblock->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1nquerymod) pnlref1nquerymod->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlhk1nvector) pnlhk1nvector->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1ncall) pnlref1ncall->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlref1ndialog) pnlref1ndialog->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlpst1nquerymod) pnlpst1nquerymod->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnvector) pnlmnvector->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
			if (pnlmnquery) pnlmnquery->updatePreset(dbswznm, ixWznmVPreset, jrefTrig, notif);
		};

		refresh(dbswznm, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmTblRec::minimize(
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

void PnlWznmTblRec::regularize(
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

void PnlWznmTblRec::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLRECDO) {
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

void PnlWznmTblRec::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmTblRec::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmTblRec::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmTblRec::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTBLUPD_REFEQ) {
		call->abort = handleCallWznmTblUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPSTUPD_REFEQ) {
		call->abort = handleCallWznmPstUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_RETEQ) {
		call->abort = handleCallWznmTbl_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_REUEQ) {
		call->abort = handleCallWznmTbl_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_TYPEQ) {
		call->abort = handleCallWznmTbl_typEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_VEREQ) {
		call->abort = handleCallWznmTbl_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_PSTEQ) {
		call->abort = handleCallWznmTbl_pstEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_CAREQ) {
		call->abort = handleCallWznmTbl_carEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBL_INSBS) {
		call->abort = handleCallWznmTbl_inSbs(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_VEREQ) {
		call->abort = handleCallWznmPst_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_REUEQ) {
		call->abort = handleCallWznmPst_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPST_RETEQ) {
		call->abort = handleCallWznmPst_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWznmTblRec::handleCallWznmTblUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmTblUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmTblRec::handleCallWznmPstUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPstUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmTblRec::handleCallWznmTbl_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refIxVTbl == ixInv); // IP handleCallWznmTbl_retEq --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmTbl_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refUref == refInv); // IP handleCallWznmTbl_reuEq --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmTbl_typEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.ixVBasetype == ixInv); // IP handleCallWznmTbl_typEq --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmTbl_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refWznmMVersion == refInv); // IP handleCallWznmTbl_verEq --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmTbl_pstEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refWznmMPreset == refInv); // IP handleCallWznmTbl_pstEq --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmTbl_carEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTbl.refWznmMCard == refInv); // IP handleCallWznmTbl_carEq --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmTbl_inSbs(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetTbl & ixInv) != 0); // IP handleCallWznmTbl_inSbs --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmPst_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refWznmMVersion == refInv); // IP handleCallWznmPst_verEq --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmPst_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refUref == refInv); // IP handleCallWznmPst_reuEq --- LINE
	return retval;
};

bool PnlWznmTblRec::handleCallWznmPst_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refIxVTbl == ixInv); // IP handleCallWznmPst_retEq --- LINE
	return retval;
};



