/**
	* \file QryWznmLibAPkglist.cpp
	* job handler for job QryWznmLibAPkglist (implementation)
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

#include "QryWznmLibAPkglist.h"

#include "QryWznmLibAPkglist_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmLibAPkglist
 ******************************************************************************/

QryWznmLibAPkglist::QryWznmLibAPkglist(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMLIBAPKGLIST, jrefSup, ixWznmVLocale)
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

QryWznmLibAPkglist::~QryWznmLibAPkglist() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmLibAPkglist::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmLibAPkglist::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefLib = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFLIB, jref);
	ubigint preX1 = xchg->getRefPreset(VecWznmVPreset::PREWZNMLIBAPKGLIST_X1, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMLIBAPKLMOD_LIBEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqlibapkglist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMLibraryPkglist.ref)";
	sqlstr += " FROM TblWznmAMLibraryPkglist";
	sqlstr += " WHERE TblWznmAMLibraryPkglist.refWznmMLibrary = " + to_string(preRefLib) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQLibAPkglist(jref, jnum, ref, x1RefWznmMMachine, Pkglist)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMLibraryPkglist.ref, TblWznmAMLibraryPkglist.x1RefWznmMMachine, TblWznmAMLibraryPkglist.Pkglist";
	sqlstr += " FROM TblWznmAMLibraryPkglist";
	sqlstr += " WHERE TblWznmAMLibraryPkglist.refWznmMLibrary = " + to_string(preRefLib) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQLibAPkglist SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMLIBAPKLMOD_LIBEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefLib);
};

void QryWznmLibAPkglist::rerun_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMLibraryPkglist.x1RefWznmMMachine = " + to_string(preX1) + "";
	};
};

void QryWznmLibAPkglist::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmLibAPkglist::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQLibAPkglist* rec = NULL;

	dbswznm->tblwznmqlibapkglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubX1RefWznmMMachine = StubWznm::getStubMchStd(dbswznm, rec->x1RefWznmMMachine, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmLibAPkglist", "fetch");
	};

	refreshJnum();
};

uint QryWznmLibAPkglist::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQLibAPkglist* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmLibAPkglist::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQLibAPkglist* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQLibAPkglist* QryWznmLibAPkglist::getRecByJnum(
			const uint jnum
		) {
	WznmQLibAPkglist* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmLibAPkglist::handleRequest(
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

bool QryWznmLibAPkglist::handleRerun(
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

bool QryWznmLibAPkglist::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQLibAPkglist* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1RefWznmMMachine";
	cout << "\tstubX1RefWznmMMachine";
	cout << "\tPkglist";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1RefWznmMMachine;
		cout << "\t" << rec->stubX1RefWznmMMachine;
		cout << "\t" << rec->Pkglist;
		cout << endl;
	};
	return retval;
};

void QryWznmLibAPkglist::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMLIBAPKLMOD_LIBEQ) {
		call->abort = handleCallWznmLibApklMod_libEq(dbswznm, call->jref);
	};
};

bool QryWznmLibAPkglist::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmLibAPkglist::handleCallWznmLibApklMod_libEq(
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
