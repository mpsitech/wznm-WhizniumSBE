/**
	* \file QryWznmQryMNTable.cpp
	* job handler for job QryWznmQryMNTable (implementation)
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

#include "QryWznmQryMNTable.h"

#include "QryWznmQryMNTable_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmQryMNTable
 ******************************************************************************/

QryWznmQryMNTable::QryWznmQryMNTable(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMQRYMNTABLE, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmQryMNTable::~QryWznmQryMNTable() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmQryMNTable::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmQryMNTable::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefQry = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFQRY, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMQRYRTBLMOD_QRYEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqqrymntable->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmRMQueryMTable.ref)";
	sqlstr += " FROM TblWznmMTable, TblWznmRMQueryMTable";
	sqlstr += " WHERE TblWznmRMQueryMTable.refWznmMTable = TblWznmMTable.ref";
	sqlstr += " AND TblWznmRMQueryMTable.refWznmMQuery = " + to_string(preRefQry) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQQryMNTable(jref, jnum, mref, ref, Source, Prefix)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMTable.ref, TblWznmRMQueryMTable.ref, TblWznmRMQueryMTable.Source, TblWznmRMQueryMTable.Prefix";
	sqlstr += " FROM TblWznmMTable, TblWznmRMQueryMTable";
	sqlstr += " WHERE TblWznmRMQueryMTable.refWznmMTable = TblWznmMTable.ref";
	sqlstr += " AND TblWznmRMQueryMTable.refWznmMQuery = " + to_string(preRefQry) + "";
	sqlstr += " ORDER BY TblWznmMTable.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQQryMNTable SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMQRYRTBLMOD_QRYEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefQry);
};

void QryWznmQryMNTable::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQQryMNTable* rec = NULL;

	ListWznmTMQuerymodMQuery qryTqmds;
	WznmTMQuerymodMQuery* qryTqmd = NULL;

	dbswznm->tblwznmqqrymntable->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWznm::getStubTblStd(dbswznm, rec->mref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			dbswznm->tblwznmtmquerymodmquery->loadRstByR(rec->ref, false, qryTqmds);
			for (unsigned int j = 0; j < qryTqmds.nodes.size(); j++) {
				qryTqmd = qryTqmds.nodes[j];
				if (j != 0) rec->stubsTrefWznmMQuerymod += ";";
				rec->stubsTrefWznmMQuerymod += StubWznm::getStubQmdStd(dbswznm, qryTqmd->refWznmMQuerymod, ixWznmVLocale, Stub::VecVNonetype::DASH, stcch);
			};
			if (rec->Source) rec->yesnoSource = VecWznmVTag::getTitle(VecWznmVTag::YES, ixWznmVLocale); else rec->yesnoSource = VecWznmVTag::getTitle(VecWznmVTag::NO, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmQryMNTable", "fetch");
	};

	refreshJnum();
};

uint QryWznmQryMNTable::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQQryMNTable* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmQryMNTable::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQQryMNTable* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQQryMNTable* QryWznmQryMNTable::getRecByJnum(
			const uint jnum
		) {
	WznmQQryMNTable* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmQryMNTable::handleRequest(
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

bool QryWznmQryMNTable::handleRerun(
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

bool QryWznmQryMNTable::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQQryMNTable* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tstubsTrefWznmMQuerymod";
	cout << "\tref";
	cout << "\tSource";
	cout << "\tyesnoSource";
	cout << "\tPrefix";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->stubsTrefWznmMQuerymod;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Source;
		cout << "\t" << rec->yesnoSource;
		cout << "\t" << rec->Prefix;
		cout << endl;
	};
	return retval;
};

void QryWznmQryMNTable::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMQRYRTBLMOD_QRYEQ) {
		call->abort = handleCallWznmQryRtblMod_qryEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmQryMNTable::handleCallWznmQryRtblMod_qryEq(
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

bool QryWznmQryMNTable::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
