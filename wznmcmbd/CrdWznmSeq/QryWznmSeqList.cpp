/**
	* \file QryWznmSeqList.cpp
	* job handler for job QryWznmSeqList (implementation)
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

#include "QryWznmSeqList.h"

#include "QryWznmSeqList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmSeqList
 ******************************************************************************/

QryWznmSeqList::QryWznmSeqList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMSEQLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMSEQMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmSeqList::~QryWznmSeqList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmSeqList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMSEQUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMSEQUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmSeqList::rerun(
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
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMSEQLIST_SRF, jref);
	ubigint preApp = xchg->getRefPreset(VecWznmVPreset::PREWZNMSEQLIST_APP, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqseqlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFAPP) {
		sqlstr = "SELECT COUNT(TblWznmMSequence.ref)";
		sqlstr += " FROM TblWznmMSequence";
		sqlstr += " WHERE TblWznmMSequence.appRefWznmMApp = " + to_string(preRefApp) + "";
		rerun_filtSQL(sqlstr, preSrf, preApp, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMSequence.ref)";
		sqlstr += " FROM TblWznmMSequence";
		rerun_filtSQL(sqlstr, preSrf, preApp, true);
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
		sqlstr += " FROM TblWznmMSequence";
		sqlstr += " WHERE TblWznmMSequence.appRefWznmMApp = " + to_string(preRefApp) + "";
		rerun_filtSQL(sqlstr, preSrf, preApp, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMSequence";
		rerun_filtSQL(sqlstr, preSrf, preApp, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQSeqList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmSeqList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQSeqList(jref, jnum, ref, sref, Title, appRefWznmMApp)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMSequence.ref, TblWznmMSequence.sref, TblWznmMSequence.Title, TblWznmMSequence.appRefWznmMApp";
};

void QryWznmSeqList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preApp
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMSequence.sref = '" + preSrf + "'";
	};

	if (preApp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMSequence.appRefWznmMApp = " + to_string(preApp) + "";
	};
};

void QryWznmSeqList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmSeqList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::APP) sqlstr += " ORDER BY TblWznmMSequence.appRefWznmMApp ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMSequence.sref ASC";
};

void QryWznmSeqList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQSeqList* rec = NULL;

	dbswznm->tblwznmqseqlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubAppRefWznmMApp = StubWznm::getStubAppStd(dbswznm, rec->appRefWznmMApp, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmSeqList", "fetch");
	};

	refreshJnum();
};

uint QryWznmSeqList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQSeqList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmSeqList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQSeqList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQSeqList* QryWznmSeqList::getRecByJnum(
			const uint jnum
		) {
	WznmQSeqList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmSeqList::handleRequest(
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

bool QryWznmSeqList::handleRerun(
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

bool QryWznmSeqList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQSeqList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tappRefWznmMApp";
	cout << "\tstubAppRefWznmMApp";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->appRefWznmMApp;
		cout << "\t" << rec->stubAppRefWznmMApp;
		cout << endl;
	};
	return retval;
};

void QryWznmSeqList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSEQUPD_REFEQ) {
		call->abort = handleCallWznmSeqUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSEQMOD) {
		call->abort = handleCallWznmSeqMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmSeqList::handleCallWznmSeqUpd_refEq(
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

bool QryWznmSeqList::handleCallWznmSeqMod(
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

bool QryWznmSeqList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
