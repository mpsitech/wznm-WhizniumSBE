/**
	* \file QryWznmQryAClause.cpp
	* job handler for job QryWznmQryAClause (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmQryAClause.h"

#include "QryWznmQryAClause_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmQryAClause
 ******************************************************************************/

QryWznmQryAClause::QryWznmQryAClause(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMQRYACLAUSE, jrefSup, ixWznmVLocale)
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

QryWznmQryAClause::~QryWznmQryAClause() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmQryAClause::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmQryAClause::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefQry = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFQRY, jref);
	ubigint preX1 = xchg->getRefPreset(VecWznmVPreset::PREWZNMQRYACLAUSE_X1, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMQRYACSEMOD_QRYEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqqryaclause->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMQueryClause.ref)";
	sqlstr += " FROM TblWznmAMQueryClause";
	sqlstr += " WHERE TblWznmAMQueryClause.qryRefWznmMQuery = " + to_string(preRefQry) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQQryAClause(jref, jnum, ref, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMQueryClause.ref, TblWznmAMQueryClause.qryNum, TblWznmAMQueryClause.x1RefWznmMQuerymod, TblWznmAMQueryClause.ixVBasetype, TblWznmAMQueryClause.Clause, TblWznmAMQueryClause.refWznmMPreset, TblWznmAMQueryClause.refWznmMVector, TblWznmAMQueryClause.refWznmMVectoritem";
	sqlstr += " FROM TblWznmAMQueryClause";
	sqlstr += " WHERE TblWznmAMQueryClause.qryRefWznmMQuery = " + to_string(preRefQry) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " ORDER BY qryNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQQryAClause SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMQRYACSEMOD_QRYEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefQry);
};

void QryWznmQryAClause::rerun_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMQueryClause.x1RefWznmMQuerymod = " + to_string(preX1) + "";
	};
};

void QryWznmQryAClause::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmQryAClause::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQQryAClause* rec = NULL;

	dbswznm->tblwznmqqryaclause->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubX1RefWznmMQuerymod = StubWznm::getStubQmdStd(dbswznm, rec->x1RefWznmMQuerymod, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVBasetype = VecWznmVAMQueryClauseBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVAMQueryClauseBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubRefWznmMPreset = StubWznm::getStubPstStd(dbswznm, rec->refWznmMPreset, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMVector = StubWznm::getStubVecStd(dbswznm, rec->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMVectoritem = StubWznm::getStubVitStd(dbswznm, rec->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmQryAClause", "fetch");
	};

	refreshJnum();
};

uint QryWznmQryAClause::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQQryAClause* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmQryAClause::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQQryAClause* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQQryAClause* QryWznmQryAClause::getRecByJnum(
			const uint jnum
		) {
	WznmQQryAClause* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmQryAClause::handleRequest(
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

bool QryWznmQryAClause::handleRerun(
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

bool QryWznmQryAClause::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQQryAClause* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tqryNum";
	cout << "\tx1RefWznmMQuerymod";
	cout << "\tstubX1RefWznmMQuerymod";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\tClause";
	cout << "\trefWznmMPreset";
	cout << "\tstubRefWznmMPreset";
	cout << "\trefWznmMVector";
	cout << "\tstubRefWznmMVector";
	cout << "\trefWznmMVectoritem";
	cout << "\tstubRefWznmMVectoritem";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->qryNum;
		cout << "\t" << rec->x1RefWznmMQuerymod;
		cout << "\t" << rec->stubX1RefWznmMQuerymod;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->Clause;
		cout << "\t" << rec->refWznmMPreset;
		cout << "\t" << rec->stubRefWznmMPreset;
		cout << "\t" << rec->refWznmMVector;
		cout << "\t" << rec->stubRefWznmMVector;
		cout << "\t" << rec->refWznmMVectoritem;
		cout << "\t" << rec->stubRefWznmMVectoritem;
		cout << endl;
	};
	return retval;
};

void QryWznmQryAClause::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMQRYACSEMOD_QRYEQ) {
		call->abort = handleCallWznmQryAcseMod_qryEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmQryAClause::handleCallWznmQryAcseMod_qryEq(
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

bool QryWznmQryAClause::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

