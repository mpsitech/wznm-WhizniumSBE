/**
	* \file PnlWznmApp1NRtjob.cpp
	* job handler for job PnlWznmApp1NRtjob (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmApp1NRtjob.h"

#include "PnlWznmApp1NRtjob_blks.cpp"
#include "PnlWznmApp1NRtjob_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmApp1NRtjob
 ******************************************************************************/

PnlWznmApp1NRtjob::PnlWznmApp1NRtjob(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMAPP1NRTJOB, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecWznmVQrystate::MNR, "ong", VecWznmVQrystate::getTitle(VecWznmVQrystate::MNR, ixWznmVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWznmVQrystate::OOD, "red", VecWznmVQrystate::getTitle(VecWznmVQrystate::OOD, ixWznmVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWznmVQrystate::SLM, "yel", VecWznmVQrystate::getTitle(VecWznmVQrystate::SLM, ixWznmVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWznmVQrystate::UTD, "grn", VecWznmVQrystate::getTitle(VecWznmVQrystate::UTD, ixWznmVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref, 0);

	qry = new QryWznmApp1NRtjob(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWznmApp1NRtjob::~PnlWznmApp1NRtjob() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmApp1NRtjob::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlWznmApp1NRtjob::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixWznmVQrystate);

	// statshr
	statshr.ButViewAvail = evalButViewAvail(dbswznm);
	statshr.ButViewActive = evalButViewActive(dbswznm);
	statshr.ButNewAvail = evalButNewAvail(dbswznm);
	statshr.ButDeleteAvail = evalButDeleteAvail(dbswznm);
	statshr.ButDeleteActive = evalButDeleteActive(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmApp1NRtjob::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFAPP) {
		recRtj = WznmMRtjob();

		xchg->addRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref, 0);

		qry->stgiac.jnumFirstload = 1;

		qry->rerun(dbswznm);
		refresh(dbswznm, moditems);

		if (notif) {
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			xchg->submitDpch(getNewDpchEng(moditems));
		};
	};
	// IP updatePreset --- END
};

void PnlWznmApp1NRtjob::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPP1NRTJOBDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswznm, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswznm, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPP1NRTJOBDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmApp1NRtjob::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmApp1NRtjob::handleDpchAppDataStgiac(
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

void PnlWznmApp1NRtjob::handleDpchAppDataStgiacqry(
			DbsWznm* dbswznm
			, QryWznmApp1NRtjob::StgIac* _stgiacqry
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	WznmQApp1NRtjob* recSelNew = NULL;

	WznmMRtjob* _recRtj = NULL;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWznmApp1NRtjob::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWznmApp1NRtjob::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswznm);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWznmApp1NRtjob::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recRtj = WznmMRtjob();

			if (recSelNew) {
				if (dbswznm->tblwznmmrtjob->loadRecByRef(recSelNew->ref, &_recRtj)) {
					recRtj = *_recRtj;
					delete _recRtj;
				};
			};

			xchg->addRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));
			qry->refreshJnum();
		};

		refresh(dbswznm, moditems);
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmApp1NRtjob::handleDpchAppDoButViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refApp = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref);

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref)) if (refApp != 0) {
			sref = "CrdWznmRtj";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFAPP, refApp, sref, recRtj.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmApp1NRtjob::handleDpchAppDoButNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refApp = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref);

	if (statshr.ButNewAvail) {
		if ((xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) & VecWznmWAccess::EDIT) != 0) if (refApp != 0) {
			sref = "CrdWznmRtj";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, VecWznmVPreset::PREWZNMREFAPP, refApp, sref, -1, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmApp1NRtjob::handleDpchAppDoButDeleteClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlWznmApp1NRtjob::handleDpchAppDoButRefreshClick(
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

void PnlWznmApp1NRtjob::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTATCHG) {
		call->abort = handleCallWznmStatChg(dbswznm, call->jref);
	};
};

bool PnlWznmApp1NRtjob::handleCallWznmStatChg(
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

