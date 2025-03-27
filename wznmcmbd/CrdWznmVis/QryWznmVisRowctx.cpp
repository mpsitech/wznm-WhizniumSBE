/**
	* \file QryWznmVisRowctx.cpp
	* job handler for job QryWznmVisRowctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP file --- KEEP
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmVisRowctx.h"

#include "QryWznmVisRowctx_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmVisRowctx
 ******************************************************************************/

QryWznmVisRowctx::QryWznmVisRowctx(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMVISROWCTX, jrefSup, ixWznmVLocale)
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

QryWznmVisRowctx::~QryWznmVisRowctx() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmVisRowctx::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmVisRowctx::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqvisrowctx->removeRstByJref(jref);

	//sqlstr = "INSERT INTO TblWznmQVisRowctx(qwr, jref, jnum)";
	//sqlstr += " SELECT 1, " + to_string(jref) + ", 0";
	//sqlstr += " FROM";
	//dbswznm->executeQuery(sqlstr);

	//sqlstr = "UPDATE TblWznmQVisRowctx SET jnum = qref WHERE jref = " + to_string(jref);
	//dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmVisRowctx::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQVisRowctx* rec = NULL;

	dbswznm->tblwznmqvisrowctx->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmVisRowctx", "fetch");
	};

	refreshJnum();
};

uint QryWznmVisRowctx::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQVisRowctx* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		//if (rec->ref == ref) {
		//	retval = rec->jnum;
		//	break;
		//};
	};

	return retval;
};

ubigint QryWznmVisRowctx::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQVisRowctx* rec = getRecByJnum(jnum);
	//if (rec) ref = rec->ref;
	return ref;
};

WznmQVisRowctx* QryWznmVisRowctx::getRecByJnum(
			const uint jnum
		) {
	WznmQVisRowctx* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmVisRowctx::handleRequest(
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

bool QryWznmVisRowctx::handleRerun(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	rerun(dbswznm);
	return retval;
};

bool QryWznmVisRowctx::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQVisRowctx* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tjnumBox";
	cout << "\tContent1";
	cout << "\tContent2";
	cout << "\tContent3";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->jnumBox;
		cout << "\t" << rec->Content1;
		cout << "\t" << rec->Content2;
		cout << "\t" << rec->Content3;
		cout << endl;
	};
	return retval;
};

void QryWznmVisRowctx::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmVisRowctx::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
