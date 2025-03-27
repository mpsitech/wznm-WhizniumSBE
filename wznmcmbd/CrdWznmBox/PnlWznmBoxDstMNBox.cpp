/**
	* \file PnlWznmBoxDstMNBox.cpp
	* job handler for job PnlWznmBoxDstMNBox (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "PnlWznmBoxDstMNBox.h"

#include "PnlWznmBoxDstMNBox_blks.cpp"
#include "PnlWznmBoxDstMNBox_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmBoxDstMNBox
 ******************************************************************************/

PnlWznmBoxDstMNBox::PnlWznmBoxDstMNBox(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMBOXDSTMNBOX, jrefSup, ixWznmVLocale)
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

	qry = new QryWznmBoxDstMNBox(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWznmBoxDstMNBox::~PnlWznmBoxDstMNBox() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmBoxDstMNBox::getNewDpchEng(
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

void PnlWznmBoxDstMNBox::refresh(
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
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixWznmVQrystate);

	// statshr
	statshr.ButViewAvail = evalButViewAvail(dbswznm);
	statshr.ButViewActive = evalButViewActive(dbswznm);
	statshr.ButAddAvail = evalButAddAvail(dbswznm);
	statshr.ButSubAvail = evalButSubAvail(dbswznm);
	statshr.ButSubActive = evalButSubActive(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmBoxDstMNBox::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFBOX) {
		recBoxRbox = WznmRMBoxMBox();

		recBox = WznmMBox();

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

void PnlWznmBoxDstMNBox::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBOXDSTMNBOXDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswznm, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswznm, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBOXDSTMNBOXDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTADDCLICK) {
					handleDpchAppDoButAddClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUBCLICK) {
					handleDpchAppDoButSubClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmBoxDstMNBox::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmBoxDstMNBox::handleDpchAppDataStgiac(
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

void PnlWznmBoxDstMNBox::handleDpchAppDataStgiacqry(
			DbsWznm* dbswznm
			, QryWznmBoxDstMNBox::StgIac* _stgiacqry
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	WznmQBoxDstMNBox* recSelNew = NULL;

	WznmRMBoxMBox* _recBoxRbox = NULL;
	WznmMBox* _recBox = NULL;

	if (!diffitems.empty()) {
		muteRefresh = true;

		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWznmBoxDstMNBox::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWznmBoxDstMNBox::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswznm);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWznmBoxDstMNBox::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recBoxRbox = WznmRMBoxMBox();

			recBox = WznmMBox();

			if (recSelNew) {
				if (dbswznm->tblwznmrmboxmbox->loadRecByRef(recSelNew->ref, &_recBoxRbox)) {
					recBoxRbox = *_recBoxRbox;
					delete _recBoxRbox;
				};
				if (dbswznm->tblwznmmbox->loadRecByRef(recSelNew->mref, &_recBox)) {
					recBox = *_recBox;
					delete _recBox;
				};
			};

			xchg->addRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));
			qry->refreshJnum();
		};

		refresh(dbswznm, moditems, true);
	};

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmBoxDstMNBox::handleDpchAppDoButViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFSHT) {
			sref = "CrdWznmBox";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recBox.ref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref)) if (ixPre == VecWznmVPreset::PREWZNMREFVIS) {
				sref = "CrdWznmBox";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, ixPre, refPre, sref, recBox.ref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmBoxDstMNBox::handleDpchAppDoButAddClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButAddClick --- INSERT
};

void PnlWznmBoxDstMNBox::handleDpchAppDoButSubClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSubClick --- INSERT
};

void PnlWznmBoxDstMNBox::handleDpchAppDoButRefreshClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->rerun(dbswznm, false);

	refresh(dbswznm, moditems, true);

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmBoxDstMNBox::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTATCHG) {
		call->abort = handleCallWznmStatChg(dbswznm, call->jref);
	};
};

bool PnlWznmBoxDstMNBox::handleCallWznmStatChg(
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
