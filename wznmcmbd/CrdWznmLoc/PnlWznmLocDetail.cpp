/**
	* \file PnlWznmLocDetail.cpp
	* job handler for job PnlWznmLocDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmLocDetail.h"

#include "PnlWznmLocDetail_blks.cpp"
#include "PnlWznmLocDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmLocDetail
 ******************************************************************************/

PnlWznmLocDetail::PnlWznmLocDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMLOCDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFPupJti.tag = "FeedFPupJti";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFLOC, jref);
};

PnlWznmLocDetail::~PnlWznmLocDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmLocDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJti, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmLocDetail::refreshJti(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ListWznmJMLocaleTitle locJtits;
	WznmJMLocaleTitle* locJtit = NULL;

	string s;

	// feedFPupJti
	feedFPupJti.clear();

	dbswznm->tblwznmjmlocaletitle->loadRstByLoc(recLoc.ref, false, locJtits);

	for (unsigned int i = 0; i < locJtits.nodes.size(); i++) {
		locJtit = locJtits.nodes[i];

		s = "";
		s = StubWznm::getStubLocStd(dbswznm, locJtit->x1RefWznmMLocale, ixWznmVLocale);
		if (s == "-") s = "(" + VecWznmVTag::getTitle(VecWznmVTag::GENERAL, ixWznmVLocale) + ")";
		feedFPupJti.appendRefTitles(locJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJTI);

	refreshRecLocJtit(dbswznm, moditems);

};

void PnlWznmLocDetail::refreshRecLoc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMLocale* _recLoc = NULL;

	if (dbswznm->tblwznmmlocale->loadRecByRef(recLoc.ref, &_recLoc)) {
		recLoc = *_recLoc;
		delete _recLoc;
	} else recLoc = WznmMLocale();

	dirty = false;

	recLocJtit.ref = recLoc.refJTitle;
	if (recLoc.ref == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMLOCJTITMOD_LOCEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMLOCJTITMOD_LOCEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recLoc.ref);

	continf.TxtSrf = recLoc.sref;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJti(dbswznm, moditems);

};

void PnlWznmLocDetail::refreshRecLocJtit(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmJMLocaleTitle* _recLocJtit = NULL;

	if (dbswznm->tblwznmjmlocaletitle->loadRecByRef(recLocJtit.ref, &_recLocJtit)) {
		recLocJtit = *_recLocJtit;
		delete _recLocJtit;
	} else recLocJtit = WznmJMLocaleTitle();

	contiac.numFPupJti = feedFPupJti.getNumByRef(recLocJtit.ref);
	continf.TxtTit = recLocJtit.Title;

	statshr.PupJtiActive = evalPupJtiActive(dbswznm);
	statshr.ButJtiEditAvail = evalButJtiEditAvail(dbswznm);
	statshr.TxtTitActive = evalTxtTitActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWznmLocDetail::refresh(
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

void PnlWznmLocDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFLOC) {
		recLoc.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFLOC, jref);
		refreshRecLoc(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmLocDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJTIEDITCLICK) {
					handleDpchAppDoButJtiEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmLocDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmLocDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFPUPJTI)) {
		recLocJtit.ref = feedFPupJti.getRefByNum(_contiac->numFPupJti);
		refreshRecLocJtit(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmLocDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmLocDetail::handleDpchAppDoButJtiEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButJtiEditClick --- INSERT
};

void PnlWznmLocDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMLOCUPD_REFEQ) {
		call->abort = handleCallWznmLocUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMLOCJTITMOD_LOCEQ) {
		call->abort = handleCallWznmLocJtitMod_locEq(dbswznm, call->jref);
	};
};

bool PnlWznmLocDetail::handleCallWznmLocUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmLocUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmLocDetail::handleCallWznmLocJtitMod_locEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJti(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

