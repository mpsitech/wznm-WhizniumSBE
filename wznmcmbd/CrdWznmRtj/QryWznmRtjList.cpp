/**
	* \file QryWznmRtjList.cpp
	* job handler for job QryWznmRtjList (implementation)
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

#include "QryWznmRtjList.h"

#include "QryWznmRtjList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmRtjList
 ******************************************************************************/

QryWznmRtjList::QryWznmRtjList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMRTJLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMRTJMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmRtjList::~QryWznmRtjList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmRtjList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMRTJUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMRTJUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmRtjList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	ubigint preRefApp = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMRTJLIST_SRF, jref);
	ubigint preApp = xchg->getRefPreset(VecWznmVPreset::PREWZNMRTJLIST_APP, jref);
	ubigint preSup = xchg->getRefPreset(VecWznmVPreset::PREWZNMRTJLIST_SUP, jref);
	ubigint preJob = xchg->getRefPreset(VecWznmVPreset::PREWZNMRTJLIST_JOB, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqrtjlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFAPP) {
		sqlstr = "SELECT COUNT(TblWznmMRtjob.ref)";
		sqlstr += " FROM TblWznmMRtjob";
		sqlstr += " WHERE TblWznmMRtjob.refWznmMApp = " + to_string(preRefApp) + "";
		rerun_filtSQL(sqlstr, preSrf, preApp, preSup, preJob, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMRtjob.ref)";
		sqlstr += " FROM TblWznmMRtjob";
		rerun_filtSQL(sqlstr, preSrf, preApp, preSup, preJob, true);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i = 0; i < cnts.size(); i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecWznmVPreset::PREWZNMREFAPP) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMRtjob";
		sqlstr += " WHERE TblWznmMRtjob.refWznmMApp = " + to_string(preRefApp) + "";
		rerun_filtSQL(sqlstr, preSrf, preApp, preSup, preJob, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMRtjob";
		rerun_filtSQL(sqlstr, preSrf, preApp, preSup, preJob, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQRtjList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmRtjList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQRtjList(jref, jnum, ref, sref, refWznmMApp, supRefWznmMRtjob, refWznmMJob)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMRtjob.ref, TblWznmMRtjob.sref, TblWznmMRtjob.refWznmMApp, TblWznmMRtjob.supRefWznmMRtjob, TblWznmMRtjob.refWznmMJob";
};

void QryWznmRtjList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preApp
			, const ubigint preSup
			, const ubigint preJob
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRtjob.sref = '" + preSrf + "'";
	};

	if (preApp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRtjob.refWznmMApp = " + to_string(preApp) + "";
	};

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRtjob.supRefWznmMRtjob = " + to_string(preSup) + "";
	};

	if (preJob != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRtjob.refWznmMJob = " + to_string(preJob) + "";
	};
};

void QryWznmRtjList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmRtjList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::JOB) sqlstr += " ORDER BY TblWznmMRtjob.refWznmMJob ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblWznmMRtjob.supRefWznmMRtjob ASC";
	else if (preIxOrd == VecVOrd::APP) sqlstr += " ORDER BY TblWznmMRtjob.refWznmMApp ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMRtjob.sref ASC";
};

void QryWznmRtjList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQRtjList* rec = NULL;

	dbswznm->tblwznmqrtjlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWznmMApp = StubWznm::getStubAppStd(dbswznm, rec->refWznmMApp, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefWznmMRtjob = StubWznm::getStubRtjStd(dbswznm, rec->supRefWznmMRtjob, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMJob = StubWznm::getStubJobStd(dbswznm, rec->refWznmMJob, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmRtjList", "fetch");
	};

	refreshJnum();
};

uint QryWznmRtjList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQRtjList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmRtjList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQRtjList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQRtjList* QryWznmRtjList::getRecByJnum(
			const uint jnum
		) {
	WznmQRtjList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmRtjList::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
	if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\trerun" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "rerun") {
			req->retain = handleRerun(dbswznm);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbswznm);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool QryWznmRtjList::handleRerun(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	rerun(dbswznm);
	return retval;
};

bool QryWznmRtjList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQRtjList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\trefWznmMApp";
	cout << "\tstubRefWznmMApp";
	cout << "\tsupRefWznmMRtjob";
	cout << "\tstubSupRefWznmMRtjob";
	cout << "\trefWznmMJob";
	cout << "\tstubRefWznmMJob";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refWznmMApp;
		cout << "\t" << rec->stubRefWznmMApp;
		cout << "\t" << rec->supRefWznmMRtjob;
		cout << "\t" << rec->stubSupRefWznmMRtjob;
		cout << "\t" << rec->refWznmMJob;
		cout << "\t" << rec->stubRefWznmMJob;
		cout << endl;
	};
	return retval;
};

void QryWznmRtjList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMRTJUPD_REFEQ) {
		call->abort = handleCallWznmRtjUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRTJMOD) {
		call->abort = handleCallWznmRtjMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmRtjList::handleCallWznmRtjUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixWznmVQrystate != VecWznmVQrystate::OOD) {
		ixWznmVQrystate = VecWznmVQrystate::OOD;
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);
	};

	return retval;
};

bool QryWznmRtjList::handleCallWznmRtjMod(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixWznmVQrystate == VecWznmVQrystate::UTD) || (ixWznmVQrystate == VecWznmVQrystate::SLM)) {
		ixWznmVQrystate = VecWznmVQrystate::MNR;
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);
	};

	return retval;
};

bool QryWznmRtjList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};



