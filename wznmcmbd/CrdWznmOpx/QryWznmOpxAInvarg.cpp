/**
	* \file QryWznmOpxAInvarg.cpp
	* job handler for job QryWznmOpxAInvarg (implementation)
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

#include "QryWznmOpxAInvarg.h"

#include "QryWznmOpxAInvarg_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmOpxAInvarg
 ******************************************************************************/

QryWznmOpxAInvarg::QryWznmOpxAInvarg(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMOPXAINVARG, jrefSup, ixWznmVLocale)
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

QryWznmOpxAInvarg::~QryWznmOpxAInvarg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmOpxAInvarg::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmOpxAInvarg::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefOpx = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPX, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMOPXAINVMOD_OPXEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqopxainvarg->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMOpInvarg.ref)";
	sqlstr += " FROM TblWznmAMOpInvarg";
	sqlstr += " WHERE TblWznmAMOpInvarg.opxRefWznmMOp = " + to_string(preRefOpx) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQOpxAInvarg(jref, jnum, ref, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMOpInvarg.ref, TblWznmAMOpInvarg.opxNum, TblWznmAMOpInvarg.sref, TblWznmAMOpInvarg.ixWznmVVartype, TblWznmAMOpInvarg.refWznmMVector, TblWznmAMOpInvarg.Defval, TblWznmAMOpInvarg.refWznmMVectoritem, TblWznmAMOpInvarg.Comment";
	sqlstr += " FROM TblWznmAMOpInvarg";
	sqlstr += " WHERE TblWznmAMOpInvarg.opxRefWznmMOp = " + to_string(preRefOpx) + "";
	sqlstr += " ORDER BY opxNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQOpxAInvarg SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMOPXAINVMOD_OPXEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefOpx);
};

void QryWznmOpxAInvarg::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQOpxAInvarg* rec = NULL;

	dbswznm->tblwznmqopxainvarg->loadRstByJref(jref, false, rst);
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
			rec->stubRefWznmMVectoritem = StubWznm::getStubVitStd(dbswznm, rec->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmOpxAInvarg", "fetch");
	};

	refreshJnum();
};

uint QryWznmOpxAInvarg::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQOpxAInvarg* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmOpxAInvarg::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQOpxAInvarg* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQOpxAInvarg* QryWznmOpxAInvarg::getRecByJnum(
			const uint jnum
		) {
	WznmQOpxAInvarg* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmOpxAInvarg::handleRequest(
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

bool QryWznmOpxAInvarg::handleRerun(
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

bool QryWznmOpxAInvarg::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQOpxAInvarg* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\topxNum";
	cout << "\tsref";
	cout << "\tixWznmVVartype";
	cout << "\tsrefIxWznmVVartype";
	cout << "\ttitIxWznmVVartype";
	cout << "\trefWznmMVector";
	cout << "\tstubRefWznmMVector";
	cout << "\tDefval";
	cout << "\trefWznmMVectoritem";
	cout << "\tstubRefWznmMVectoritem";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->opxNum;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixWznmVVartype;
		cout << "\t" << rec->srefIxWznmVVartype;
		cout << "\t" << rec->titIxWznmVVartype;
		cout << "\t" << rec->refWznmMVector;
		cout << "\t" << rec->stubRefWznmMVector;
		cout << "\t" << rec->Defval;
		cout << "\t" << rec->refWznmMVectoritem;
		cout << "\t" << rec->stubRefWznmMVectoritem;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWznmOpxAInvarg::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPXAINVMOD_OPXEQ) {
		call->abort = handleCallWznmOpxAinvMod_opxEq(dbswznm, call->jref);
	};
};

bool QryWznmOpxAInvarg::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmOpxAInvarg::handleCallWznmOpxAinvMod_opxEq(
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
