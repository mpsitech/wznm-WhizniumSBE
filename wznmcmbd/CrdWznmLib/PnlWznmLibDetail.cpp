/**
	* \file PnlWznmLibDetail.cpp
	* job handler for job PnlWznmLibDetail (implementation)
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

#include "PnlWznmLibDetail.h"

#include "PnlWznmLibDetail_blks.cpp"
#include "PnlWznmLibDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmLibDetail
 ******************************************************************************/

PnlWznmLibDetail::PnlWznmLibDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMLIBDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstDep.tag = "FeedFLstDep";
	feedFPupLty.tag = "FeedFPupLty";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMLIBRARYLICTYPE, ixWznmVLocale, feedFPupLty);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMLIBRARYLICTYPE);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFLIB, jref);
};

PnlWznmLibDetail::~PnlWznmLibDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmLibDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDep, &feedFPupLty, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmLibDetail::refreshPupLty(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupLty = 0;

	for (unsigned int i = 0; i < feedFPupLty.size(); i++) {
		if (feedFPupLty.getSrefByNum(i+1) == contiac.TxfLty) {
			contiac.numFPupLty = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfLtyValid = (contiac.numFPupLty != 0);
	statshr.PupLtyActive = evalPupLtyActive(dbswznm);
	statshr.ButLtyEditAvail = evalButLtyEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmLibDetail::refreshTxfLty(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfLty = feedFPupLty.getSrefByNum(contiac.numFPupLty);

	// statshr
	statshr.TxfLtyValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmLibDetail::refreshLty(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFPupLty
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMLIBRARYLICTYPE, ixWznmVLocale, feedFPupLty);

	insert(moditems, DpchEngData::FEEDFPUPLTY);

	refreshPupLty(dbswznm, moditems);
};

void PnlWznmLibDetail::refreshLstDep(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstDepActive = evalLstDepActive(dbswznm);
	statshr.ButDepViewAvail = evalButDepViewAvail(dbswznm);
	statshr.ButDepViewActive = evalButDepViewActive(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmLibDetail::refreshDep(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	vector<string> ss;

	// contiac
	contiac.numFLstDep = 0;

	// feedFLstDep
	feedFLstDep.clear();

	StrMod::stringToVector(contiac.TxfDep, ss);

	// IP refreshDep.validate --- INSERT

	// statshr
	statshr.TxfDepValid = (ss.size() == feedFLstDep.size());

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmLibDetail::refreshRecLib(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMLibrary* _recLib = NULL;

	if (dbswznm->tblwznmmlibrary->loadRecByRef(recLib.ref, &_recLib)) {
		recLib = *_recLib;
		delete _recLib;
	} else recLib = WznmMLibrary();

	dirty = false;

	continf.TxtSrf = recLib.sref;
	contiac.TxfTit = recLib.Title;
	contiac.TxfVer = recLib.Version;
	contiac.TxfLty = recLib.srefKLictype;
	contiac.TxfDep = recLib.depSrefsWznmMLibrary;
	contiac.TxfCmt = recLib.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	statshr.TxfTitActive = evalTxfTitActive(dbswznm);
	statshr.TxfVerActive = evalTxfVerActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupLty(dbswznm, moditems);
	refreshDep(dbswznm, moditems);

};

void PnlWznmLibDetail::refresh(
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

void PnlWznmLibDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFLIB) {
		recLib.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFLIB, jref);
		refreshRecLib(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmLibDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLTYEDITCLICK) {
					handleDpchAppDoButLtyEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDEPVIEWCLICK) {
					handleDpchAppDoButDepViewClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmLibDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmLibDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFVER, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFVER)) contiac.TxfVer = _contiac->TxfVer;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFLTY)) {
		contiac.TxfLty = _contiac->TxfLty;
		refreshPupLty(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPLTY)) {
		contiac.numFPupLty = _contiac->numFPupLty;
		refreshTxfLty(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFDEP)) {
		contiac.TxfDep = _contiac->TxfDep;
		refreshDep(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFLSTDEP)) {
		contiac.numFLstDep = _contiac->numFLstDep;
		refreshLstDep(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmLibDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmLibDetail::handleDpchAppDoButLtyEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButLtyEditClick --- INSERT
};

void PnlWznmLibDetail::handleDpchAppDoButDepViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButDepViewClick --- INSERT
};

void PnlWznmLibDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMLIBUPD_REFEQ) {
		call->abort = handleCallWznmLibUpd_refEq(dbswznm, call->jref);
	};
};

bool PnlWznmLibDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKMLIBRARYLICTYPE) {
		refreshLty(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmLibDetail::handleCallWznmLibUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmLibUpd_refEq --- INSERT
	return retval;
};



