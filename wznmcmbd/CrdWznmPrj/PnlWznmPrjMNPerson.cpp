/**
	* \file PnlWznmPrjMNPerson.cpp
	* job handler for job PnlWznmPrjMNPerson (implementation)
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

#include "PnlWznmPrjMNPerson.h"

#include "PnlWznmPrjMNPerson_blks.cpp"
#include "PnlWznmPrjMNPerson_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmPrjMNPerson
 ******************************************************************************/

PnlWznmPrjMNPerson::PnlWznmPrjMNPerson(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMPRJMNPERSON, jrefSup, ixWznmVLocale)
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

	qry = new QryWznmPrjMNPerson(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWznmPrjMNPerson::~PnlWznmPrjMNPerson() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmPrjMNPerson::getNewDpchEng(
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

void PnlWznmPrjMNPerson::refresh(
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

void PnlWznmPrjMNPerson::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFPRJ) {
		recPrsRprj = WznmRMPersonMProject();

		recPrs = WznmMPerson();

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

void PnlWznmPrjMNPerson::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJMNPERSONDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswznm, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswznm, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJMNPERSONDO) {
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

void PnlWznmPrjMNPerson::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmPrjMNPerson::handleDpchAppDataStgiac(
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

void PnlWznmPrjMNPerson::handleDpchAppDataStgiacqry(
			DbsWznm* dbswznm
			, QryWznmPrjMNPerson::StgIac* _stgiacqry
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	WznmQPrjMNPerson* recSelNew = NULL;

	WznmRMPersonMProject* _recPrsRprj = NULL;
	WznmMPerson* _recPrs = NULL;

	if (!diffitems.empty()) {
		muteRefresh = true;

		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWznmPrjMNPerson::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWznmPrjMNPerson::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswznm);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWznmPrjMNPerson::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recPrsRprj = WznmRMPersonMProject();

			recPrs = WznmMPerson();

			if (recSelNew) {
				if (dbswznm->tblwznmrmpersonmproject->loadRecByRef(recSelNew->ref, &_recPrsRprj)) {
					recPrsRprj = *_recPrsRprj;
					delete _recPrsRprj;
				};
				if (dbswznm->tblwznmmperson->loadRecByRef(recSelNew->mref, &_recPrs)) {
					recPrs = *_recPrs;
					delete _recPrs;
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

void PnlWznmPrjMNPerson::handleDpchAppDoButViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRS, jref)) {
			sref = "CrdWznmPrs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recPrs.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmPrjMNPerson::handleDpchAppDoButAddClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButAddClick --- INSERT
};

void PnlWznmPrjMNPerson::handleDpchAppDoButSubClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSubClick --- INSERT
};

void PnlWznmPrjMNPerson::handleDpchAppDoButRefreshClick(
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

void PnlWznmPrjMNPerson::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTATCHG) {
		call->abort = handleCallWznmStatChg(dbswznm, call->jref);
	};
};

bool PnlWznmPrjMNPerson::handleCallWznmStatChg(
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
