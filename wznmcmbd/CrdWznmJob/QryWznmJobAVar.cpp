/**
	* \file QryWznmJobAVar.cpp
	* job handler for job QryWznmJobAVar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmJobAVar.h"

#include "QryWznmJobAVar_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmJobAVar
 ******************************************************************************/

QryWznmJobAVar::QryWznmJobAVar(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMJOBAVAR, jrefSup, ixWznmVLocale)
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

QryWznmJobAVar::~QryWznmJobAVar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmJobAVar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmJobAVar::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefJob = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMJOBAVARMOD_JOBEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqjobavar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMJobVar.ref)";
	sqlstr += " FROM TblWznmAMJobVar";
	sqlstr += " WHERE TblWznmAMJobVar.jobRefWznmMJob = " + to_string(preRefJob) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQJobAVar(jref, jnum, ref, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMJobVar.ref, TblWznmAMJobVar.jobNum, TblWznmAMJobVar.sref, TblWznmAMJobVar.ixWznmVVartype, TblWznmAMJobVar.refWznmMVector, TblWznmAMJobVar.Length, TblWznmAMJobVar.Shr, TblWznmAMJobVar.Comment";
	sqlstr += " FROM TblWznmAMJobVar";
	sqlstr += " WHERE TblWznmAMJobVar.jobRefWznmMJob = " + to_string(preRefJob) + "";
	sqlstr += " ORDER BY jobNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQJobAVar SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMJOBAVARMOD_JOBEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefJob);
};

void QryWznmJobAVar::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQJobAVar* rec = NULL;

	dbswznm->tblwznmqjobavar->loadRstByJref(jref, false, rst);
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
			if (rec->Shr) rec->yesnoShr = VecWznmVTag::getTitle(VecWznmVTag::YES, ixWznmVLocale); else rec->yesnoShr = VecWznmVTag::getTitle(VecWznmVTag::NO, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmJobAVar", "fetch");
	};

	refreshJnum();
};

uint QryWznmJobAVar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQJobAVar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmJobAVar::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQJobAVar* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQJobAVar* QryWznmJobAVar::getRecByJnum(
			const uint jnum
		) {
	WznmQJobAVar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmJobAVar::handleRequest(
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

bool QryWznmJobAVar::handleRerun(
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

bool QryWznmJobAVar::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQJobAVar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tjobNum";
	cout << "\tsref";
	cout << "\tixWznmVVartype";
	cout << "\tsrefIxWznmVVartype";
	cout << "\ttitIxWznmVVartype";
	cout << "\trefWznmMVector";
	cout << "\tstubRefWznmMVector";
	cout << "\tLength";
	cout << "\tShr";
	cout << "\tyesnoShr";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->jobNum;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixWznmVVartype;
		cout << "\t" << rec->srefIxWznmVVartype;
		cout << "\t" << rec->titIxWznmVVartype;
		cout << "\t" << rec->refWznmMVector;
		cout << "\t" << rec->stubRefWznmMVector;
		cout << "\t" << rec->Length;
		cout << "\t" << rec->Shr;
		cout << "\t" << rec->yesnoShr;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWznmJobAVar::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMJOBAVARMOD_JOBEQ) {
		call->abort = handleCallWznmJobAvarMod_jobEq(dbswznm, call->jref);
	};
};

bool QryWznmJobAVar::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmJobAVar::handleCallWznmJobAvarMod_jobEq(
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

