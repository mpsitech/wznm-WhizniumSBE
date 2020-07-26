/**
	* \file QryWznmMtyAMakefile.cpp
	* job handler for job QryWznmMtyAMakefile (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmMtyAMakefile.h"

#include "QryWznmMtyAMakefile_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmMtyAMakefile
 ******************************************************************************/

QryWznmMtyAMakefile::QryWznmMtyAMakefile(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMMTYAMAKEFILE, jrefSup, ixWznmVLocale)
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

QryWznmMtyAMakefile::~QryWznmMtyAMakefile() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmMtyAMakefile::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmMtyAMakefile::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefMty = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMTY, jref);
	string preX1 = xchg->getSrefPreset(VecWznmVPreset::PREWZNMMTYAMAKEFILE_X1, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMMTYAMKFMOD_MTYEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqmtyamakefile->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMMachtypeMakefile.ref)";
	sqlstr += " FROM TblWznmAMMachtypeMakefile";
	sqlstr += " WHERE TblWznmAMMachtypeMakefile.refWznmMMachtype = " + to_string(preRefMty) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQMtyAMakefile(jref, jnum, ref, x1SrefKTag, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMMachtypeMakefile.ref, TblWznmAMMachtypeMakefile.x1SrefKTag, TblWznmAMMachtypeMakefile.Val";
	sqlstr += " FROM TblWznmAMMachtypeMakefile";
	sqlstr += " WHERE TblWznmAMMachtypeMakefile.refWznmMMachtype = " + to_string(preRefMty) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQMtyAMakefile SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMMTYAMKFMOD_MTYEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefMty);
};

void QryWznmMtyAMakefile::rerun_filtSQL(
			string& sqlstr
			, const string& preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMMachtypeMakefile.x1SrefKTag = '" + preX1 + "'";
	};
};

void QryWznmMtyAMakefile::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmMtyAMakefile::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQMtyAMakefile* rec = NULL;

	dbswznm->tblwznmqmtyamakefile->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1SrefKTag = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKAMMACHTYPEMAKEFILETAG, rec->x1SrefKTag, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmMtyAMakefile", "fetch");
	};

	refreshJnum();
};

uint QryWznmMtyAMakefile::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQMtyAMakefile* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmMtyAMakefile::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQMtyAMakefile* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQMtyAMakefile* QryWznmMtyAMakefile::getRecByJnum(
			const uint jnum
		) {
	WznmQMtyAMakefile* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmMtyAMakefile::handleRequest(
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

bool QryWznmMtyAMakefile::handleRerun(
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

bool QryWznmMtyAMakefile::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQMtyAMakefile* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1SrefKTag";
	cout << "\ttitX1SrefKTag";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1SrefKTag;
		cout << "\t" << rec->titX1SrefKTag;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryWznmMtyAMakefile::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMMTYAMKFMOD_MTYEQ) {
		call->abort = handleCallWznmMtyAmkfMod_mtyEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmMtyAMakefile::handleCallWznmMtyAmkfMod_mtyEq(
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

bool QryWznmMtyAMakefile::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

