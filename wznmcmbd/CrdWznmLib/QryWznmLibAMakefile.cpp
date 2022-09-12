/**
	* \file QryWznmLibAMakefile.cpp
	* job handler for job QryWznmLibAMakefile (implementation)
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

#include "QryWznmLibAMakefile.h"

#include "QryWznmLibAMakefile_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmLibAMakefile
 ******************************************************************************/

QryWznmLibAMakefile::QryWznmLibAMakefile(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMLIBAMAKEFILE, jrefSup, ixWznmVLocale)
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

QryWznmLibAMakefile::~QryWznmLibAMakefile() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmLibAMakefile::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmLibAMakefile::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefLib = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFLIB, jref);
	ubigint preX1 = xchg->getRefPreset(VecWznmVPreset::PREWZNMLIBAMAKEFILE_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWznmVPreset::PREWZNMLIBAMAKEFILE_X2, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMLIBAMKFMOD_LIBEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqlibamakefile->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMLibraryMakefile.ref)";
	sqlstr += " FROM TblWznmAMLibraryMakefile";
	sqlstr += " WHERE TblWznmAMLibraryMakefile.refWznmMLibrary = " + to_string(preRefLib) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQLibAMakefile(jref, jnum, ref, x1RefWznmMMachine, x2SrefKTag, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMLibraryMakefile.ref, TblWznmAMLibraryMakefile.x1RefWznmMMachine, TblWznmAMLibraryMakefile.x2SrefKTag, TblWznmAMLibraryMakefile.Val";
	sqlstr += " FROM TblWznmAMLibraryMakefile";
	sqlstr += " WHERE TblWznmAMLibraryMakefile.refWznmMLibrary = " + to_string(preRefLib) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQLibAMakefile SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMLIBAMKFMOD_LIBEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefLib);
};

void QryWznmLibAMakefile::rerun_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMLibraryMakefile.x1RefWznmMMachine = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMLibraryMakefile.x2SrefKTag = '" + preX2 + "'";
	};
};

void QryWznmLibAMakefile::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmLibAMakefile::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQLibAMakefile* rec = NULL;

	dbswznm->tblwznmqlibamakefile->loadRstByJref(jref, false, rst);
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
			rec->titX2SrefKTag = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKAMLIBRARYMAKEFILETAG, rec->x2SrefKTag, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmLibAMakefile", "fetch");
	};

	refreshJnum();
};

uint QryWznmLibAMakefile::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQLibAMakefile* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmLibAMakefile::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQLibAMakefile* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQLibAMakefile* QryWznmLibAMakefile::getRecByJnum(
			const uint jnum
		) {
	WznmQLibAMakefile* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmLibAMakefile::handleRequest(
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

bool QryWznmLibAMakefile::handleRerun(
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

bool QryWznmLibAMakefile::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQLibAMakefile* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1RefWznmMMachine";
	cout << "\tstubX1RefWznmMMachine";
	cout << "\tx2SrefKTag";
	cout << "\ttitX2SrefKTag";
	cout << "\tVal";
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
		cout << "\t" << rec->x2SrefKTag;
		cout << "\t" << rec->titX2SrefKTag;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryWznmLibAMakefile::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMLIBAMKFMOD_LIBEQ) {
		call->abort = handleCallWznmLibAmkfMod_libEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmLibAMakefile::handleCallWznmLibAmkfMod_libEq(
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

bool QryWznmLibAMakefile::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
