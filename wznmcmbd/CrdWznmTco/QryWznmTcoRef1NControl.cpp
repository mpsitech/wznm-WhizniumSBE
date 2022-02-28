/**
	* \file QryWznmTcoRef1NControl.cpp
	* job handler for job QryWznmTcoRef1NControl (implementation)
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

#include "QryWznmTcoRef1NControl.h"

#include "QryWznmTcoRef1NControl_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmTcoRef1NControl
 ******************************************************************************/

QryWznmTcoRef1NControl::QryWznmTcoRef1NControl(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMTCOREF1NCONTROL, jrefSup, ixWznmVLocale)
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

QryWznmTcoRef1NControl::~QryWznmTcoRef1NControl() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmTcoRef1NControl::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmTcoRef1NControl::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefTco = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTCO, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMCONMOD_RETREUEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqtcoref1ncontrol->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
	sqlstr += " FROM TblWznmMControl";
	sqlstr += " WHERE TblWznmMControl.refIxVTbl = " + to_string(VecWznmVMControlRefTbl::TCO);
	sqlstr += " AND TblWznmMControl.refUref = " + to_string(preRefTco) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQTcoRef1NControl(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMControl.ref";
	sqlstr += " FROM TblWznmMControl";
	sqlstr += " WHERE TblWznmMControl.refIxVTbl = " + to_string(VecWznmVMControlRefTbl::TCO);
	sqlstr += " AND TblWznmMControl.refUref = " + to_string(preRefTco) + "";
	sqlstr += " ORDER BY sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQTcoRef1NControl SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMCONMOD_RETREUEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVMControlRefTbl::TCO, preRefTco);
};

void QryWznmTcoRef1NControl::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQTcoRef1NControl* rec = NULL;

	dbswznm->tblwznmqtcoref1ncontrol->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWznm::getStubConStd(dbswznm, rec->ref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmTcoRef1NControl", "fetch");
	};

	refreshJnum();
};

uint QryWznmTcoRef1NControl::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQTcoRef1NControl* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmTcoRef1NControl::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQTcoRef1NControl* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQTcoRef1NControl* QryWznmTcoRef1NControl::getRecByJnum(
			const uint jnum
		) {
	WznmQTcoRef1NControl* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmTcoRef1NControl::handleRequest(
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

bool QryWznmTcoRef1NControl::handleRerun(
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

bool QryWznmTcoRef1NControl::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQTcoRef1NControl* rec = NULL;

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

void QryWznmTcoRef1NControl::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCONMOD_RETREUEQ) {
		call->abort = handleCallWznmConMod_retReuEq(dbswznm, call->jref);
	};
};

bool QryWznmTcoRef1NControl::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmTcoRef1NControl::handleCallWznmConMod_retReuEq(
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
