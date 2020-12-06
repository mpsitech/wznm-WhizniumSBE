/**
	* \file QryWznmOpkAInvarg.cpp
	* job handler for job QryWznmOpkAInvarg (implementation)
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

#include "QryWznmOpkAInvarg.h"

#include "QryWznmOpkAInvarg_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmOpkAInvarg
 ******************************************************************************/

QryWznmOpkAInvarg::QryWznmOpkAInvarg(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMOPKAINVARG, jrefSup, ixWznmVLocale)
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

QryWznmOpkAInvarg::~QryWznmOpkAInvarg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmOpkAInvarg::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmOpkAInvarg::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefOpk = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMOPKAINVMOD_OPKEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqopkainvarg->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMOppackInvarg.ref)";
	sqlstr += " FROM TblWznmAMOppackInvarg";
	sqlstr += " WHERE TblWznmAMOppackInvarg.opkRefWznmMOppack = " + to_string(preRefOpk) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQOpkAInvarg(jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMOppackInvarg.ref, TblWznmAMOppackInvarg.opkNum, TblWznmAMOppackInvarg.sref, TblWznmAMOppackInvarg.ixWznmVVartype, TblWznmAMOppackInvarg.refWznmMVector, TblWznmAMOppackInvarg.Defval, TblWznmAMOppackInvarg.refWznmMVectoritem, TblWznmAMOppackInvarg.Comment";
	sqlstr += " FROM TblWznmAMOppackInvarg";
	sqlstr += " WHERE TblWznmAMOppackInvarg.opkRefWznmMOppack = " + to_string(preRefOpk) + "";
	sqlstr += " ORDER BY opkNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQOpkAInvarg SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMOPKAINVMOD_OPKEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefOpk);
};

void QryWznmOpkAInvarg::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQOpkAInvarg* rec = NULL;

	dbswznm->tblwznmqopkainvarg->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryWznmOpkAInvarg", "fetch");
	};

	refreshJnum();
};

uint QryWznmOpkAInvarg::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQOpkAInvarg* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmOpkAInvarg::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQOpkAInvarg* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQOpkAInvarg* QryWznmOpkAInvarg::getRecByJnum(
			const uint jnum
		) {
	WznmQOpkAInvarg* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmOpkAInvarg::handleRequest(
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

bool QryWznmOpkAInvarg::handleRerun(
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

bool QryWznmOpkAInvarg::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQOpkAInvarg* rec = NULL;

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
		cout << "\t" << rec->opkNum;
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

void QryWznmOpkAInvarg::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPKAINVMOD_OPKEQ) {
		call->abort = handleCallWznmOpkAinvMod_opkEq(dbswznm, call->jref);
	};
};

bool QryWznmOpkAInvarg::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmOpkAInvarg::handleCallWznmOpkAinvMod_opkEq(
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
