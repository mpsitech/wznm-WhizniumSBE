/**
	* \file PnlWznmPrsDetail.cpp
	* job handler for job PnlWznmPrsDetail (implementation)
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

#include "PnlWznmPrsDetail.h"

#include "PnlWznmPrsDetail_blks.cpp"
#include "PnlWznmPrsDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmPrsDetail
 ******************************************************************************/

PnlWznmPrsDetail::PnlWznmPrsDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMPRSDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstDrv.tag = "FeedFLstDrv";
	VecWznmWMPersonDerivate::fillFeed(ixWznmVLocale, feedFLstDrv);
	feedFPupJln.tag = "FeedFPupJln";
	feedFPupSex.tag = "FeedFPupSex";
	VecWznmVMPersonSex::fillFeed(ixWznmVLocale, feedFPupSex);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFPRS, jref);
};

PnlWznmPrsDetail::~PnlWznmPrsDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmPrsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDrv, &feedFPupJln, &feedFPupSex, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmPrsDetail::refreshJln(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMPersonLastname prsJlnms;
	WznmJMPersonLastname* prsJlnm = NULL;

	string s;

	// feedFPupJln
	feedFPupJln.clear();

	dbswznm->tblwznmjmpersonlastname->loadRstByPrs(recPrs.ref, false, prsJlnms);

	for (unsigned int i = 0; i < prsJlnms.nodes.size(); i++) {
		prsJlnm = prsJlnms.nodes[i];

		s = "";
		if (prsJlnm->x1Startd != 0) {
			s = Ftm::date(prsJlnm->x1Startd) + " -";
			if ((i+2) < prsJlnms.nodes.size()) if (prsJlnms.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(prsJlnms.nodes[i+1]->x1Startd);
		} else s = "(" + VecWznmVTag::getTitle(VecWznmVTag::ALWAYS, ixWznmVLocale) + ")";
		feedFPupJln.appendRefTitles(prsJlnm->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJLN);

	refreshRecPrsJlnm(dbswznm, moditems);

};

void PnlWznmPrsDetail::refreshTxtDrv(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstDrv.size(); i++) ix |= feedFLstDrv.getIxByNum(contiac.numsFLstDrv[i]);
	continf.TxtDrv = VecWznmWMPersonDerivate::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWznmPrsDetail::refreshRecPrs(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmMPerson* _recPrs = NULL;

	if (dbswznm->tblwznmmperson->loadRecByRef(recPrs.ref, &_recPrs)) {
		recPrs = *_recPrs;
		delete _recPrs;
	} else recPrs = WznmMPerson();

	dirty = false;

	recPrsJlnm.ref = recPrs.refJLastname;
	if (recPrs.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMPRSJLNMMOD_PRSEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMPRSJLNMMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPrs.ref);

	contiac.TxfTit = recPrs.Title;
	contiac.TxfFnm = recPrs.Firstname;
	contiac.numsFLstDrv.clear();
	VecWznmWMPersonDerivate::getIcs(recPrs.ixWDerivate, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstDrv.push_back(feedFLstDrv.getNumByIx(*it));
	contiac.numFPupSex = feedFPupSex.getNumByIx(recPrs.ixVSex);
	contiac.TxfTel = recPrs.telVal;
	contiac.TxfEml = recPrs.emlVal;
	contiac.TxfSal = recPrs.Salutation;

	statshr.TxfTitActive = evalTxfTitActive(dbswznm);
	statshr.TxfFnmActive = evalTxfFnmActive(dbswznm);
	statshr.LstDrvActive = evalLstDrvActive(dbswznm);
	statshr.PupSexActive = evalPupSexActive(dbswznm);
	statshr.TxfTelActive = evalTxfTelActive(dbswznm);
	statshr.TxfEmlActive = evalTxfEmlActive(dbswznm);
	statshr.TxfSalActive = evalTxfSalActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJln(dbswznm, moditems);
	refreshTxtDrv(dbswznm, moditems);

};

void PnlWznmPrsDetail::refreshRecPrsJlnm(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WznmJMPersonLastname* _recPrsJlnm = NULL;

	if (dbswznm->tblwznmjmpersonlastname->loadRecByRef(recPrsJlnm.ref, &_recPrsJlnm)) {
		recPrsJlnm = *_recPrsJlnm;
		delete _recPrsJlnm;
	} else recPrsJlnm = WznmJMPersonLastname();

	contiac.numFPupJln = feedFPupJln.getNumByRef(recPrsJlnm.ref);
	continf.TxtLnm = recPrsJlnm.Lastname;

	statshr.PupJlnActive = evalPupJlnActive(dbswznm);
	statshr.ButJlnEditAvail = evalButJlnEditAvail(dbswznm);
	statshr.TxtLnmActive = evalTxtLnmActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmPrsDetail::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswznm);
	statshr.ButSaveActive = evalButSaveActive(dbswznm);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmPrsDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFPRS) {
		recPrs.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPRS, jref);
		refreshRecPrs(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmPrsDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJLNEDITCLICK) {
					handleDpchAppDoButJlnEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmPrsDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmPrsDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFFNM, ContIac::NUMFPUPSEX, ContIac::TXFTEL, ContIac::TXFEML, ContIac::TXFSAL})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::NUMFPUPSEX)) contiac.numFPupSex = _contiac->numFPupSex;
		if (has(diffitems, ContIac::TXFTEL)) contiac.TxfTel = _contiac->TxfTel;
		if (has(diffitems, ContIac::TXFEML)) contiac.TxfEml = _contiac->TxfEml;
		if (has(diffitems, ContIac::TXFSAL)) contiac.TxfSal = _contiac->TxfSal;
	};

	if (has(diffitems, ContIac::NUMFPUPJLN)) {
		recPrsJlnm.ref = feedFPupJln.getRefByNum(_contiac->numFPupJln);
		refreshRecPrsJlnm(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTDRV)) {
		contiac.numsFLstDrv = _contiac->numsFLstDrv;
		refreshTxtDrv(dbswznm, moditems);
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmPrsDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmPrsDetail::handleDpchAppDoButJlnEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJlnEditClick --- INSERT
};

void PnlWznmPrsDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPRSUPD_REFEQ) {
		call->abort = handleCallWznmPrsUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPRSJLNMMOD_PRSEQ) {
		call->abort = handleCallWznmPrsJlnmMod_prsEq(dbswznm, call->jref);
	};
};

bool PnlWznmPrsDetail::handleCallWznmPrsUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmPrsUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmPrsDetail::handleCallWznmPrsJlnmMod_prsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJln(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
