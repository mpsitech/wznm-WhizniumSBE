/**
	* \file QryWznmTcoRef1NQuerymod.cpp
	* job handler for job QryWznmTcoRef1NQuerymod (implementation)
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

#include "QryWznmTcoRef1NQuerymod.h"

#include "QryWznmTcoRef1NQuerymod_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmTcoRef1NQuerymod
 ******************************************************************************/

QryWznmTcoRef1NQuerymod::QryWznmTcoRef1NQuerymod(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMTCOREF1NQUERYMOD, jrefSup, ixWznmVLocale)
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

QryWznmTcoRef1NQuerymod::~QryWznmTcoRef1NQuerymod() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmTcoRef1NQuerymod::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmTcoRef1NQuerymod::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefTco = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTCO, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMQMDMOD_RETREUEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqtcoref1nquerymod->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmMQuerymod.ref)";
	sqlstr += " FROM TblWznmMQuerymod";
	sqlstr += " WHERE TblWznmMQuerymod.refIxVTbl = " + to_string(VecWznmVMQuerymodRefTbl::TCO);
	sqlstr += " AND TblWznmMQuerymod.refUref = " + to_string(preRefTco) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQTcoRef1NQuerymod(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMQuerymod.ref";
	sqlstr += " FROM TblWznmMQuerymod";
	sqlstr += " WHERE TblWznmMQuerymod.refIxVTbl = " + to_string(VecWznmVMQuerymodRefTbl::TCO);
	sqlstr += " AND TblWznmMQuerymod.refUref = " + to_string(preRefTco) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQTcoRef1NQuerymod SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMQMDMOD_RETREUEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVMQuerymodRefTbl::TCO, preRefTco);
};

void QryWznmTcoRef1NQuerymod::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQTcoRef1NQuerymod* rec = NULL;

	dbswznm->tblwznmqtcoref1nquerymod->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWznm::getStubQmdStd(dbswznm, rec->ref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmTcoRef1NQuerymod", "fetch");
	};

	refreshJnum();
};

uint QryWznmTcoRef1NQuerymod::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQTcoRef1NQuerymod* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmTcoRef1NQuerymod::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQTcoRef1NQuerymod* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQTcoRef1NQuerymod* QryWznmTcoRef1NQuerymod::getRecByJnum(
			const uint jnum
		) {
	WznmQTcoRef1NQuerymod* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmTcoRef1NQuerymod::handleRequest(
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

bool QryWznmTcoRef1NQuerymod::handleRerun(
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

bool QryWznmTcoRef1NQuerymod::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQTcoRef1NQuerymod* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryWznmTcoRef1NQuerymod::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMQMDMOD_RETREUEQ) {
		call->abort = handleCallWznmQmdMod_retReuEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmTcoRef1NQuerymod::handleCallWznmQmdMod_retReuEq(
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

bool QryWznmTcoRef1NQuerymod::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
