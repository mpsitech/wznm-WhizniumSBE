/**
	* \file QryWznmVecFct1NTablecol.cpp
	* job handler for job QryWznmVecFct1NTablecol (implementation)
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

#include "QryWznmVecFct1NTablecol.h"

#include "QryWznmVecFct1NTablecol_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmVecFct1NTablecol
 ******************************************************************************/

QryWznmVecFct1NTablecol::QryWznmVecFct1NTablecol(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMVECFCT1NTABLECOL, jrefSup, ixWznmVLocale)
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

QryWznmVecFct1NTablecol::~QryWznmVecFct1NTablecol() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmVecFct1NTablecol::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmVecFct1NTablecol::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefVec = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVEC, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMTCOMOD_FCTFCUEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqvecfct1ntablecol->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmMTablecol.ref)";
	sqlstr += " FROM TblWznmMTablecol";
	sqlstr += " WHERE TblWznmMTablecol.fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::VEC);
	sqlstr += " AND TblWznmMTablecol.fctUref = " + to_string(preRefVec) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQVecFct1NTablecol(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMTablecol.ref";
	sqlstr += " FROM TblWznmMTablecol";
	sqlstr += " WHERE TblWznmMTablecol.fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::VEC);
	sqlstr += " AND TblWznmMTablecol.fctUref = " + to_string(preRefVec) + "";
	sqlstr += " ORDER BY sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQVecFct1NTablecol SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addIxRefClstn(VecWznmVCall::CALLWZNMTCOMOD_FCTFCUEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVMTablecolFctTbl::VEC, preRefVec);
};

void QryWznmVecFct1NTablecol::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQVecFct1NTablecol* rec = NULL;

	dbswznm->tblwznmqvecfct1ntablecol->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWznm::getStubTcoStd(dbswznm, rec->ref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmVecFct1NTablecol", "fetch");
	};

	refreshJnum();
};

uint QryWznmVecFct1NTablecol::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQVecFct1NTablecol* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmVecFct1NTablecol::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQVecFct1NTablecol* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQVecFct1NTablecol* QryWznmVecFct1NTablecol::getRecByJnum(
			const uint jnum
		) {
	WznmQVecFct1NTablecol* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmVecFct1NTablecol::handleRequest(
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

bool QryWznmVecFct1NTablecol::handleRerun(
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

bool QryWznmVecFct1NTablecol::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQVecFct1NTablecol* rec = NULL;

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

void QryWznmVecFct1NTablecol::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTCOMOD_FCTFCUEQ) {
		call->abort = handleCallWznmTcoMod_fctFcuEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmVecFct1NTablecol::handleCallWznmTcoMod_fctFcuEq(
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

bool QryWznmVecFct1NTablecol::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
