/**
	* \file QryWznmTblALoadfct.cpp
	* job handler for job QryWznmTblALoadfct (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmTblALoadfct.h"

#include "QryWznmTblALoadfct_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmTblALoadfct
 ******************************************************************************/

QryWznmTblALoadfct::QryWznmTblALoadfct(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMTBLALOADFCT, jrefSup, ixWznmVLocale)
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

QryWznmTblALoadfct::~QryWznmTblALoadfct() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmTblALoadfct::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmTblALoadfct::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefTbl = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMTBLALFCMOD_TBLEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqtblaloadfct->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMTableLoadfct.ref)";
	sqlstr += " FROM TblWznmAMTableLoadfct";
	sqlstr += " WHERE TblWznmAMTableLoadfct.refWznmMTable = " + to_string(preRefTbl) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQTblALoadfct(jref, jnum, ref, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMTableLoadfct.ref, TblWznmAMTableLoadfct.ixVLoadtype, TblWznmAMTableLoadfct.Fctname, TblWznmAMTableLoadfct.ldSrefWznmMTablecol, TblWznmAMTableLoadfct.lbySrefsWznmMTablecol, TblWznmAMTableLoadfct.ordSrefsWznmMTablecol, TblWznmAMTableLoadfct.ixVLimtype";
	sqlstr += " FROM TblWznmAMTableLoadfct";
	sqlstr += " WHERE TblWznmAMTableLoadfct.refWznmMTable = " + to_string(preRefTbl) + "";
	sqlstr += " ORDER BY Fctname ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQTblALoadfct SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMTBLALFCMOD_TBLEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefTbl);
};

void QryWznmTblALoadfct::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQTblALoadfct* rec = NULL;

	dbswznm->tblwznmqtblaloadfct->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVLoadtype = VecWznmVAMTableLoadfctLoadtype::getSref(rec->ixVLoadtype);
			rec->titIxVLoadtype = VecWznmVAMTableLoadfctLoadtype::getTitle(rec->ixVLoadtype, ixWznmVLocale);
			rec->srefIxVLimtype = VecWznmVAMTableLoadfctLimtype::getSref(rec->ixVLimtype);
			rec->titIxVLimtype = VecWznmVAMTableLoadfctLimtype::getTitle(rec->ixVLimtype, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmTblALoadfct", "fetch");
	};

	refreshJnum();
};

uint QryWznmTblALoadfct::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQTblALoadfct* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmTblALoadfct::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQTblALoadfct* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQTblALoadfct* QryWznmTblALoadfct::getRecByJnum(
			const uint jnum
		) {
	WznmQTblALoadfct* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmTblALoadfct::handleRequest(
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

bool QryWznmTblALoadfct::handleRerun(
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

bool QryWznmTblALoadfct::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQTblALoadfct* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tixVLoadtype";
	cout << "\tsrefIxVLoadtype";
	cout << "\ttitIxVLoadtype";
	cout << "\tFctname";
	cout << "\tldSrefWznmMTablecol";
	cout << "\tlbySrefsWznmMTablecol";
	cout << "\tordSrefsWznmMTablecol";
	cout << "\tixVLimtype";
	cout << "\tsrefIxVLimtype";
	cout << "\ttitIxVLimtype";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixVLoadtype;
		cout << "\t" << rec->srefIxVLoadtype;
		cout << "\t" << rec->titIxVLoadtype;
		cout << "\t" << rec->Fctname;
		cout << "\t" << rec->ldSrefWznmMTablecol;
		cout << "\t" << rec->lbySrefsWznmMTablecol;
		cout << "\t" << rec->ordSrefsWznmMTablecol;
		cout << "\t" << rec->ixVLimtype;
		cout << "\t" << rec->srefIxVLimtype;
		cout << "\t" << rec->titIxVLimtype;
		cout << endl;
	};
	return retval;
};

void QryWznmTblALoadfct::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTBLALFCMOD_TBLEQ) {
		call->abort = handleCallWznmTblAlfcMod_tblEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmTblALoadfct::handleCallWznmTblAlfcMod_tblEq(
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

bool QryWznmTblALoadfct::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

