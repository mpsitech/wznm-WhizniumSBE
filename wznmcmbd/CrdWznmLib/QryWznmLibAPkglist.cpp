/**
	* \file QryWznmLibAPkglist.cpp
	* job handler for job QryWznmLibAPkglist (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

	xchg->removeClstns(VecWznmVCall::CALLWZNMLIBAPKLMOD_LIBEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqlibapkglist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMLibraryPkglist.ref)";
	sqlstr += " FROM TblWznmAMLibraryPkglist";
	sqlstr += " WHERE TblWznmAMLibraryPkglist.refWznmMLibrary = " + to_string(preRefLib) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQLibAPkglist(jref, jnum, ref, x1RefIxVTbl, x1RefUref, Pkglist)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMLibraryPkglist.ref, TblWznmAMLibraryPkglist.x1RefIxVTbl, TblWznmAMLibraryPkglist.x1RefUref, TblWznmAMLibraryPkglist.Pkglist";
	sqlstr += " FROM TblWznmAMLibraryPkglist";
	sqlstr += " WHERE TblWznmAMLibraryPkglist.refWznmMLibrary = " + to_string(preRefLib) + "";
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
			rec->srefX1RefIxVTbl = VecWznmVAMLibraryPkglistRefTbl::getSref(rec->x1RefIxVTbl);
			rec->titX1RefIxVTbl = VecWznmVAMLibraryPkglistRefTbl::getTitle(rec->x1RefIxVTbl, ixWznmVLocale);
			if (rec->x1RefIxVTbl == VecWznmVAMLibraryPkglistRefTbl::MTY) {
				rec->stubX1RefUref = StubWznm::getStubMtyStd(dbswznm, rec->x1RefUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->x1RefIxVTbl == VecWznmVAMLibraryPkglistRefTbl::MCH) {
				rec->stubX1RefUref = StubWznm::getStubMchStd(dbswznm, rec->x1RefUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubX1RefUref = "-";
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
	cout << "\tx1RefIxVTbl";
	cout << "\tsrefX1RefIxVTbl";
	cout << "\ttitX1RefIxVTbl";
	cout << "\tx1RefUref";
	cout << "\tstubX1RefUref";
	cout << "\tPkglist";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1RefIxVTbl;
		cout << "\t" << rec->srefX1RefIxVTbl;
		cout << "\t" << rec->titX1RefIxVTbl;
		cout << "\t" << rec->x1RefUref;
		cout << "\t" << rec->stubX1RefUref;
		cout << "\t" << rec->Pkglist;
		cout << endl;
	};
	return retval;
};

void QryWznmLibAPkglist::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMLIBAPKLMOD_LIBEQ) {
		call->abort = handleCallWznmLibApklMod_libEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
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

bool QryWznmLibAPkglist::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

