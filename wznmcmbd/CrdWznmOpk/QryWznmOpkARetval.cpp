/**
	* \file QryWznmOpkARetval.cpp
	* job handler for job QryWznmOpkARetval (implementation)
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

#include "QryWznmOpkARetval.h"

#include "QryWznmOpkARetval_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmOpkARetval
 ******************************************************************************/

QryWznmOpkARetval::QryWznmOpkARetval(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMOPKARETVAL, jrefSup, ixWznmVLocale)
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

QryWznmOpkARetval::~QryWznmOpkARetval() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmOpkARetval::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmOpkARetval::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefOpk = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMOPKARETMOD_OPKEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqopkaretval->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMOppackRetval.ref)";
	sqlstr += " FROM TblWznmAMOppackRetval";
	sqlstr += " WHERE TblWznmAMOppackRetval.opkRefWznmMOppack = " + to_string(preRefOpk) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQOpkARetval(jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMOppackRetval.ref, TblWznmAMOppackRetval.opkNum, TblWznmAMOppackRetval.sref, TblWznmAMOppackRetval.ixWznmVVartype, TblWznmAMOppackRetval.refWznmMVector, TblWznmAMOppackRetval.Comment";
	sqlstr += " FROM TblWznmAMOppackRetval";
	sqlstr += " WHERE TblWznmAMOppackRetval.opkRefWznmMOppack = " + to_string(preRefOpk) + "";
	sqlstr += " ORDER BY opkNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQOpkARetval SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMOPKARETMOD_OPKEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefOpk);
};

void QryWznmOpkARetval::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQOpkARetval* rec = NULL;

	dbswznm->tblwznmqopkaretval->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxWznmVVartype = VecWznmVVartype::getSref(rec->ixWznmVVartype);
			rec->titIxWznmVVartype = VecWznmVVartype::getTitle(rec->ixWznmVVartype);
			rec->stubRefWznmMVector = StubWznm::getStubVecStd(dbswznm, rec->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmOpkARetval", "fetch");
	};

	refreshJnum();
};

uint QryWznmOpkARetval::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQOpkARetval* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmOpkARetval::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQOpkARetval* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQOpkARetval* QryWznmOpkARetval::getRecByJnum(
			const uint jnum
		) {
	WznmQOpkARetval* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmOpkARetval::handleRequest(
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

bool QryWznmOpkARetval::handleRerun(
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

bool QryWznmOpkARetval::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQOpkARetval* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\topkNum";
	cout << "\tsref";
	cout << "\tixWznmVVartype";
	cout << "\tsrefIxWznmVVartype";
	cout << "\ttitIxWznmVVartype";
	cout << "\trefWznmMVector";
	cout << "\tstubRefWznmMVector";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->opkNum;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixWznmVVartype;
		cout << "\t" << rec->srefIxWznmVVartype;
		cout << "\t" << rec->titIxWznmVVartype;
		cout << "\t" << rec->refWznmMVector;
		cout << "\t" << rec->stubRefWznmMVector;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWznmOpkARetval::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMOPKARETMOD_OPKEQ) {
		call->abort = handleCallWznmOpkAretMod_opkEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmOpkARetval::handleCallWznmOpkAretMod_opkEq(
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

bool QryWznmOpkARetval::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
