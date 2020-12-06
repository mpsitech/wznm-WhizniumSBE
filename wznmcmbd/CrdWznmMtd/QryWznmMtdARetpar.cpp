/**
	* \file QryWznmMtdARetpar.cpp
	* job handler for job QryWznmMtdARetpar (implementation)
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

#include "QryWznmMtdARetpar.h"

#include "QryWznmMtdARetpar_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmMtdARetpar
 ******************************************************************************/

QryWznmMtdARetpar::QryWznmMtdARetpar(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMMTDARETPAR, jrefSup, ixWznmVLocale)
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

QryWznmMtdARetpar::~QryWznmMtdARetpar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmMtdARetpar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmMtdARetpar::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefMtd = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMTD, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMMTDARPAMOD_MTDEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqmtdaretpar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMMethodRetpar.ref)";
	sqlstr += " FROM TblWznmAMMethodRetpar";
	sqlstr += " WHERE TblWznmAMMethodRetpar.mtdRefWznmMMethod = " + to_string(preRefMtd) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQMtdARetpar(jref, jnum, ref, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMMethodRetpar.ref, TblWznmAMMethodRetpar.mtdNum, TblWznmAMMethodRetpar.sref, TblWznmAMMethodRetpar.ixWznmVVartype, TblWznmAMMethodRetpar.refWznmMVector, TblWznmAMMethodRetpar.Length, TblWznmAMMethodRetpar.Comment";
	sqlstr += " FROM TblWznmAMMethodRetpar";
	sqlstr += " WHERE TblWznmAMMethodRetpar.mtdRefWznmMMethod = " + to_string(preRefMtd) + "";
	sqlstr += " ORDER BY mtdNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQMtdARetpar SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMMTDARPAMOD_MTDEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefMtd);
};

void QryWznmMtdARetpar::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQMtdARetpar* rec = NULL;

	dbswznm->tblwznmqmtdaretpar->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryWznmMtdARetpar", "fetch");
	};

	refreshJnum();
};

uint QryWznmMtdARetpar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQMtdARetpar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmMtdARetpar::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQMtdARetpar* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQMtdARetpar* QryWznmMtdARetpar::getRecByJnum(
			const uint jnum
		) {
	WznmQMtdARetpar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmMtdARetpar::handleRequest(
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

bool QryWznmMtdARetpar::handleRerun(
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

bool QryWznmMtdARetpar::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQMtdARetpar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tmtdNum";
	cout << "\tsref";
	cout << "\tixWznmVVartype";
	cout << "\tsrefIxWznmVVartype";
	cout << "\ttitIxWznmVVartype";
	cout << "\trefWznmMVector";
	cout << "\tstubRefWznmMVector";
	cout << "\tLength";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->mtdNum;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixWznmVVartype;
		cout << "\t" << rec->srefIxWznmVVartype;
		cout << "\t" << rec->titIxWznmVVartype;
		cout << "\t" << rec->refWznmMVector;
		cout << "\t" << rec->stubRefWznmMVector;
		cout << "\t" << rec->Length;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWznmMtdARetpar::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMTDARPAMOD_MTDEQ) {
		call->abort = handleCallWznmMtdArpaMod_mtdEq(dbswznm, call->jref);
	};
};

bool QryWznmMtdARetpar::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmMtdARetpar::handleCallWznmMtdArpaMod_mtdEq(
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
