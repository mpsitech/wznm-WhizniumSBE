/**
	* \file PnlWznmOpkList.cpp
	* job handler for job PnlWznmOpkList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmOpkList.h"

#include "PnlWznmOpkList_blks.cpp"
#include "PnlWznmOpkList_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmOpkList
 ******************************************************************************/

PnlWznmOpkList::PnlWznmOpkList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMOPKLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecWznmVQrystate::MNR, "ong", VecWznmVQrystate::getTitle(VecWznmVQrystate::MNR, ixWznmVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWznmVQrystate::OOD, "red", VecWznmVQrystate::getTitle(VecWznmVQrystate::OOD, ixWznmVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWznmVQrystate::SLM, "yel", VecWznmVQrystate::getTitle(VecWznmVQrystate::SLM, ixWznmVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWznmVQrystate::UTD, "grn", VecWznmVQrystate::getTitle(VecWznmVQrystate::UTD, ixWznmVLocale));
	feedFTos.tag = "FeedFTos";
	QryWznmOpkList::VecVOrd::fillFeed(feedFTos);

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref));
	xchg->addIxPreset(VecWznmVPreset::PREWZNMIXORD, jref, QryWznmOpkList::VecVOrd::SRF);

	qry = new QryWznmOpkList(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	statshr.ixWznmVExpstate = ((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref)) ? VecWznmVExpstate::MIND : VecWznmVExpstate::REGD);
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWznmOpkList::~PnlWznmOpkList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmOpkList::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFCsiQst, &feedFTos, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlWznmOpkList::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixWznmVQrystate);

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	if ((ixPre != 0) && (ixPre != VecWznmVPreset::VOID)) {
		continf.TxtFor = VecWznmVPreset::getTitle(ixPre, ixWznmVLocale);

		if (ixPre == VecWznmVPreset::PREWZNMREFVER) continf.TxtPre = StubWznm::getStubVerStd(dbswznm, xchg->getRefPreset(ixPre, jref), ixWznmVLocale, Stub::VecVNonetype::FULL);

	} else {
		continf.TxtFor = "";
	};

	// contiac
	contiac.numFTos = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
};

void PnlWznmOpkList::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFOPK) {
		xchg->addRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref));
		qry->refreshJnum();
		refresh(dbswznm, moditems);

		insert(moditems, DpchEngData::STGIACQRY);

		if ((jrefTrig != jref) && notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmOpkList::minimize(
			DbsWznm* dbswznm
			, const bool notif
			, DpchEngWznm** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWznmVExpstate != VecWznmVExpstate::MIND) {
		statshr.ixWznmVExpstate = VecWznmVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWznmOpkList::regularize(
			DbsWznm* dbswznm
			, const bool notif
			, DpchEngWznm** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWznmVExpstate != VecWznmVExpstate::REGD) {
		statshr.ixWznmVExpstate = VecWznmVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWznmOpkList::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKLISTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswznm, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswznm, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKLISTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILTERCLICK) {
					handleDpchAppDoButFilterClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmOpkList::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmOpkList::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	muteRefresh = true;

	if (has(diffitems, ContIac::NUMFTOS)) {
		if ((_contiac->numFTos >= QryWznmOpkList::VecVOrd::SRF) && (_contiac->numFTos <= QryWznmOpkList::VecVOrd::VER)) {
			xchg->addIxPreset(VecWznmVPreset::PREWZNMIXORD, jref, _contiac->numFTos);

			qry->rerun(dbswznm);
			refresh(dbswznm, moditems);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
		};
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmOpkList::handleDpchAppDataStgiac(
			DbsWznm* dbswznm
			, StgIac* _stgiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiac->diff(&stgiac);
	// IP handleDpchAppDataStgiac --- INSERT
	insert(moditems, DpchEngData::STGIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmOpkList::handleDpchAppDataStgiacqry(
			DbsWznm* dbswznm
			, QryWznmOpkList::StgIac* _stgiacqry
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	ubigint refSelNew = 0;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWznmOpkList::StgIac::JNUM)) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWznmOpkList::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswznm);
			refresh(dbswznm, moditems);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWznmOpkList::StgIac::JNUM)) {
			if (refSelNew == 0) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);
			xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFOPK, refSelNew);
		};
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmOpkList::handleDpchAppDoButMinimizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	minimize(dbswznm, true, dpcheng);
};

void PnlWznmOpkList::handleDpchAppDoButRegularizeClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	regularize(dbswznm, true, dpcheng);
};

void PnlWznmOpkList::handleDpchAppDoButNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButNewClick --- INSERT
};

void PnlWznmOpkList::handleDpchAppDoButDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlWznmOpkList::handleDpchAppDoButFilterClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButFilterClick --- INSERT
};

void PnlWznmOpkList::handleDpchAppDoButRefreshClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->rerun(dbswznm, false);
	refresh(dbswznm, moditems);

	muteRefresh = false;

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmOpkList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTATCHG) {
		call->abort = handleCallWznmStatChg(dbswznm, call->jref);
	};
};

bool PnlWznmOpkList::handleCallWznmStatChg(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmStatChg --- BEGIN

	set<uint> moditems;

	if (jrefTrig == qry->jref) {
		if (!muteRefresh) {
			refresh(dbswznm, moditems);
			if (qry->ixWznmVQrystate == VecWznmVQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
		};
	};

	// IP handleCallWznmStatChg --- END
	return retval;
};

