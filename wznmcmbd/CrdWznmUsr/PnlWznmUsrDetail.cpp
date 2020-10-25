/**
	* \file PnlWznmUsrDetail.cpp
	* job handler for job PnlWznmUsrDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmUsrDetail.h"

#include "PnlWznmUsrDetail_blks.cpp"
#include "PnlWznmUsrDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmUsrDetail
 ******************************************************************************/

PnlWznmUsrDetail::PnlWznmUsrDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMUSRDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupJst.tag = "FeedFPupJst";
	feedFPupLcl.tag = "FeedFPupLcl";
	VecWznmVLocale::fillFeed(ixWznmVLocale, feedFPupLcl);
	feedFPupSte.tag = "FeedFPupSte";
	VecWznmVMUserState::fillFeed(ixWznmVLocale, feedFPupSte);
	feedFPupUlv.tag = "FeedFPupUlv";
	VecWznmVUserlevel::fillFeed(ixWznmVLocale, feedFPupUlv);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMUSR_USGEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMUSR_PRSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFUSR, jref);
};

PnlWznmUsrDetail::~PnlWznmUsrDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmUsrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJst, &feedFPupLcl, &feedFPupSte, &feedFPupUlv, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmUsrDetail::refreshJst(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMUserState usrJstes;
	WznmJMUserState* usrJste = NULL;

	string s;

	// feedFPupJst
	feedFPupJst.clear();

	dbswznm->tblwznmjmuserstate->loadRstByUsr(recUsr.ref, false, usrJstes);

	for (unsigned int i = 0; i < usrJstes.nodes.size(); i++) {
		usrJste = usrJstes.nodes[i];

		s = "";
		if (usrJste->x1Start != 0) {
			s = Ftm::stamp(usrJste->x1Start) + " -";
			if ((i+2) < usrJstes.nodes.size()) if (usrJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::stamp(usrJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecWznmVTag::getTitle(VecWznmVTag::ALWAYS, ixWznmVLocale) + ")";
		feedFPupJst.appendRefTitles(usrJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJST);

	refreshRecUsrJste(dbswznm, moditems);

};

void PnlWznmUsrDetail::refreshRecUsr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMUser* _recUsr = NULL;

	if (dbswznm->tblwznmmuser->loadRecByRef(recUsr.ref, &_recUsr)) {
		recUsr = *_recUsr;
		delete _recUsr;
	} else recUsr = WznmMUser();

	dirty = false;

	recUsrJste.ref = recUsr.refJState;
	if (recUsr.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMUSRJSTEMOD_USREQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMUSRJSTEMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, true, recUsr.ref);

	continf.TxtPrs = StubWznm::getStubPrsStd(dbswznm, recUsr.refWznmMPerson, ixWznmVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSrf = recUsr.sref;
	continf.TxtUsg = StubWznm::getStubUsgStd(dbswznm, recUsr.refWznmMUsergroup, ixWznmVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupLcl = feedFPupLcl.getNumByIx(recUsr.ixWznmVLocale);
	contiac.numFPupUlv = feedFPupUlv.getNumByIx(recUsr.ixWznmVUserlevel);
	contiac.TxfPwd = recUsr.Password;
	contiac.TxfFky = recUsr.Fullkey;
	contiac.TxfCmt = recUsr.Comment;

	statshr.TxtPrsActive = evalTxtPrsActive(dbswznm);
	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbswznm);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbswznm);
	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxtUsgActive = evalTxtUsgActive(dbswznm);
	statshr.ButUsgViewAvail = evalButUsgViewAvail(dbswznm);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbswznm);
	statshr.PupLclActive = evalPupLclActive(dbswznm);
	statshr.PupUlvActive = evalPupUlvActive(dbswznm);
	statshr.TxfPwdActive = evalTxfPwdActive(dbswznm);
	statshr.TxfFkyActive = evalTxfFkyActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJst(dbswznm, moditems);

};

void PnlWznmUsrDetail::refreshRecUsrJste(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMUserState* _recUsrJste = NULL;

	if (dbswznm->tblwznmjmuserstate->loadRecByRef(recUsrJste.ref, &_recUsrJste)) {
		recUsrJste = *_recUsrJste;
		delete _recUsrJste;
	} else recUsrJste = WznmJMUserState();

	contiac.numFPupJst = feedFPupJst.getNumByRef(recUsrJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recUsrJste.ixVState);

	statshr.PupJstActive = evalPupJstActive(dbswznm);
	statshr.ButJstEditAvail = evalButJstEditAvail(dbswznm);
	statshr.PupSteActive = evalPupSteActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmUsrDetail::refresh(
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

void PnlWznmUsrDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFUSR) {
		recUsr.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFUSR, jref);
		refreshRecUsr(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmUsrDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJSTEDITCLICK) {
					handleDpchAppDoButJstEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmUsrDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmUsrDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSTE, ContIac::NUMFPUPLCL, ContIac::NUMFPUPULV, ContIac::TXFPWD, ContIac::TXFFKY, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::NUMFPUPLCL)) contiac.numFPupLcl = _contiac->numFPupLcl;
		if (has(diffitems, ContIac::NUMFPUPULV)) contiac.numFPupUlv = _contiac->numFPupUlv;
		if (has(diffitems, ContIac::TXFPWD)) contiac.TxfPwd = _contiac->TxfPwd;
		if (has(diffitems, ContIac::TXFFKY)) contiac.TxfFky = _contiac->TxfFky;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJST)) {
		recUsrJste.ref = feedFPupJst.getRefByNum(_contiac->numFPupJst);
		refreshRecUsrJste(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmUsrDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmUsrDetail::handleDpchAppDoButPrsViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrsViewAvail && statshr.ButPrsViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRS, jref)) {
			sref = "CrdWznmPrs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recUsr.refWznmMPerson, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmUsrDetail::handleDpchAppDoButUsgViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButUsgViewAvail && statshr.ButUsgViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref)) {
			sref = "CrdWznmUsg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recUsr.refWznmMUsergroup, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmUsrDetail::handleDpchAppDoButJstEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJstEditClick --- INSERT
};

void PnlWznmUsrDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMUSRUPD_REFEQ) {
		call->abort = handleCallWznmUsrUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMUSR_USGEQ) {
		call->abort = handleCallWznmUsr_usgEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMUSR_PRSEQ) {
		call->abort = handleCallWznmUsr_prsEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMUSRJSTEMOD_USREQ) {
		call->abort = handleCallWznmUsrJsteMod_usrEq(dbswznm, call->jref);
	};
};

bool PnlWznmUsrDetail::handleCallWznmUsrUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmUsrDetail::handleCallWznmUsr_usgEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWznmMUsergroup == refInv); // IP handleCallWznmUsr_usgEq --- LINE
	return retval;
};

bool PnlWznmUsrDetail::handleCallWznmUsr_prsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWznmMPerson == refInv); // IP handleCallWznmUsr_prsEq --- LINE
	return retval;
};

bool PnlWznmUsrDetail::handleCallWznmUsrJsteMod_usrEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJst(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

