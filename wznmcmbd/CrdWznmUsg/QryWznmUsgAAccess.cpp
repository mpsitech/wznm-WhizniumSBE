/**
	* \file QryWznmUsgAAccess.cpp
	* job handler for job QryWznmUsgAAccess (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmUsgAAccess.h"

#include "QryWznmUsgAAccess_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmUsgAAccess
 ******************************************************************************/

QryWznmUsgAAccess::QryWznmUsgAAccess(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMUSGAACCESS, jrefSup, ixWznmVLocale)
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

QryWznmUsgAAccess::~QryWznmUsgAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmUsgAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmUsgAAccess::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFUSG, jref);
	uint preX1 = xchg->getIxPreset(VecWznmVPreset::PREWZNMUSGAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWznmVPreset::PREWZNMUSGAACCESS_X2, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMUSGAACCMOD_USGEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqusgaaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMUsergroupAccess.ref)";
	sqlstr += " FROM TblWznmAMUsergroupAccess";
	sqlstr += " WHERE TblWznmAMUsergroupAccess.refWznmMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQUsgAAccess(jref, jnum, ref, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMUsergroupAccess.ref, TblWznmAMUsergroupAccess.x1IxWznmVFeatgroup, TblWznmAMUsergroupAccess.x2FeaSrefUix, TblWznmAMUsergroupAccess.ixWznmWAccess";
	sqlstr += " FROM TblWznmAMUsergroupAccess";
	sqlstr += " WHERE TblWznmAMUsergroupAccess.refWznmMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQUsgAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMUSGAACCMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsg);
};

void QryWznmUsgAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMUsergroupAccess.x1IxWznmVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMUsergroupAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryWznmUsgAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmUsgAAccess::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQUsgAAccess* rec = NULL;

	dbswznm->tblwznmqusgaaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxWznmVFeatgroup = VecWznmVFeatgroup::getSref(rec->x1IxWznmVFeatgroup);
			rec->titX1IxWznmVFeatgroup = VecWznmVFeatgroup::getTitle(rec->x1IxWznmVFeatgroup, ixWznmVLocale);
			rec->srefsIxWznmWAccess = VecWznmWAccess::getSrefs(rec->ixWznmWAccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmUsgAAccess", "fetch");
	};

	refreshJnum();
};

uint QryWznmUsgAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQUsgAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmUsgAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQUsgAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQUsgAAccess* QryWznmUsgAAccess::getRecByJnum(
			const uint jnum
		) {
	WznmQUsgAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmUsgAAccess::handleRequest(
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

bool QryWznmUsgAAccess::handleRerun(
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

bool QryWznmUsgAAccess::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQUsgAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxWznmVFeatgroup";
	cout << "\tsrefX1IxWznmVFeatgroup";
	cout << "\ttitX1IxWznmVFeatgroup";
	cout << "\tx2FeaSrefUix";
	cout << "\tixWznmWAccess";
	cout << "\tsrefsIxWznmWAccess";
	cout << "\ttitsIxWznmWAccess";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxWznmVFeatgroup;
		cout << "\t" << rec->srefX1IxWznmVFeatgroup;
		cout << "\t" << rec->titX1IxWznmVFeatgroup;
		cout << "\t" << rec->x2FeaSrefUix;
		cout << "\t" << rec->ixWznmWAccess;
		cout << "\t" << rec->srefsIxWznmWAccess;
		cout << "\t" << rec->titsIxWznmWAccess;
		cout << endl;
	};
	return retval;
};

void QryWznmUsgAAccess::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMUSGAACCMOD_USGEQ) {
		call->abort = handleCallWznmUsgAaccMod_usgEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmUsgAAccess::handleCallWznmUsgAaccMod_usgEq(
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

bool QryWznmUsgAAccess::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

