/**
	* \file PnlWznmMdlDetail.cpp
	* job handler for job PnlWznmMdlDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmMdlDetail.h"

#include "PnlWznmMdlDetail_blks.cpp"
#include "PnlWznmMdlDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmMdlDetail
 ******************************************************************************/

PnlWznmMdlDetail::PnlWznmMdlDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMMDLDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupJ.tag = "FeedFPupJ";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMMDL_VEREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFMDL, jref);
};

PnlWznmMdlDetail::~PnlWznmMdlDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmMdlDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmMdlDetail::refreshJ(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMModule mdlJs;
	WznmJMModule* mdlJ = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbswznm->tblwznmjmmodule->loadRstByMdl(recMdl.ref, false, mdlJs);

	for (unsigned int i = 0; i < mdlJs.nodes.size(); i++) {
		mdlJ = mdlJs.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, mdlJ->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupJ.appendRefTitles(mdlJ->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecMdlJ(dbswznm, moditems);

};

void PnlWznmMdlDetail::refreshRecMdl(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMModule* _recMdl = NULL;

	if (dbswznm->tblwznmmmodule->loadRecByRef(recMdl.ref, &_recMdl)) {
		recMdl = *_recMdl;
		delete _recMdl;
	} else recMdl = WznmMModule();

	dirty = false;

	recMdlJ.ref = recMdl.refJ;
	if (recMdl.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMMDLJMOD_MDLEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMMDLJMOD_MDLEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recMdl.ref);

	continf.TxtSrf = recMdl.sref;
	continf.TxtVer = StubWznm::getStubVerStd(dbswznm, recMdl.verRefWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::FULL);

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtVerActive = evalTxtVerActive(dbswznm);
	statshr.ButVerViewAvail = evalButVerViewAvail(dbswznm);
	statshr.ButVerViewActive = evalButVerViewActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbswznm, moditems);

};

void PnlWznmMdlDetail::refreshRecMdlJ(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMModule* _recMdlJ = NULL;

	if (dbswznm->tblwznmjmmodule->loadRecByRef(recMdlJ.ref, &_recMdlJ)) {
		recMdlJ = *_recMdlJ;
		delete _recMdlJ;
	} else recMdlJ = WznmJMModule();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recMdlJ.ref);
	continf.TxtTit = recMdlJ.Title;
	continf.TxtCmt = recMdlJ.Comment;

	statshr.PupJActive = evalPupJActive(dbswznm);
	statshr.ButJEditAvail = evalButJEditAvail(dbswznm);
	statshr.TxtTitActive = evalTxtTitActive(dbswznm);
	statshr.TxtCmtActive = evalTxtCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmMdlDetail::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswznm);
	statshr.ButSaveActive = evalButSaveActive(dbswznm);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmMdlDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMDL) {
		recMdl.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMDL, jref);
		refreshRecMdl(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmMdlDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmMdlDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmMdlDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recMdlJ.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecMdlJ(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmMdlDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmMdlDetail::handleDpchAppDoButJEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlWznmMdlDetail::handleDpchAppDoButVerViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButVerViewAvail && statshr.ButVerViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) {
			sref = "CrdWznmVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recMdl.verRefWznmMVersion, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmMdlDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMMDLUPD_REFEQ) {
		call->abort = handleCallWznmMdlUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMDL_VEREQ) {
		call->abort = handleCallWznmMdl_verEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMDLJMOD_MDLEQ) {
		call->abort = handleCallWznmMdlJMod_mdlEq(dbswznm, call->jref);
	};
};

bool PnlWznmMdlDetail::handleCallWznmMdlUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmMdlUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmMdlDetail::handleCallWznmMdl_verEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.verRefWznmMVersion == refInv); // IP handleCallWznmMdl_verEq --- LINE
	return retval;
};

bool PnlWznmMdlDetail::handleCallWznmMdlJMod_mdlEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

