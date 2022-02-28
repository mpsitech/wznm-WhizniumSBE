/**
	* \file QryWznmUsrMNUsergroup.cpp
	* job handler for job QryWznmUsrMNUsergroup (implementation)
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

#include "QryWznmUsrMNUsergroup.h"

#include "QryWznmUsrMNUsergroup_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmUsrMNUsergroup
 ******************************************************************************/

QryWznmUsrMNUsergroup::QryWznmUsrMNUsergroup(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMUSRMNUSERGROUP, jrefSup, ixWznmVLocale)
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

QryWznmUsrMNUsergroup::~QryWznmUsrMNUsergroup() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmUsrMNUsergroup::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmUsrMNUsergroup::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFUSR, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMUSRRUSGMOD_USREQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqusrmnusergroup->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmRMUserMUsergroup.ref)";
	sqlstr += " FROM TblWznmRMUserMUsergroup, TblWznmMUsergroup";
	sqlstr += " WHERE TblWznmRMUserMUsergroup.refWznmMUsergroup = TblWznmMUsergroup.ref";
	sqlstr += " AND TblWznmRMUserMUsergroup.refWznmMUser = " + to_string(preRefUsr) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQUsrMNUsergroup(jref, jnum, mref, ref, ixWznmVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMUsergroup.ref, TblWznmRMUserMUsergroup.ref, TblWznmRMUserMUsergroup.ixWznmVUserlevel";
	sqlstr += " FROM TblWznmRMUserMUsergroup, TblWznmMUsergroup";
	sqlstr += " WHERE TblWznmRMUserMUsergroup.refWznmMUsergroup = TblWznmMUsergroup.ref";
	sqlstr += " AND TblWznmRMUserMUsergroup.refWznmMUser = " + to_string(preRefUsr) + "";
	sqlstr += " ORDER BY TblWznmMUsergroup.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQUsrMNUsergroup SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMUSRRUSGMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsr);
};

void QryWznmUsrMNUsergroup::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQUsrMNUsergroup* rec = NULL;

	dbswznm->tblwznmqusrmnusergroup->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWznm::getStubUsgStd(dbswznm, rec->mref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxWznmVUserlevel = VecWznmVUserlevel::getSref(rec->ixWznmVUserlevel);
			rec->titIxWznmVUserlevel = VecWznmVUserlevel::getTitle(rec->ixWznmVUserlevel, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmUsrMNUsergroup", "fetch");
	};

	refreshJnum();
};

uint QryWznmUsrMNUsergroup::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQUsrMNUsergroup* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmUsrMNUsergroup::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQUsrMNUsergroup* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQUsrMNUsergroup* QryWznmUsrMNUsergroup::getRecByJnum(
			const uint jnum
		) {
	WznmQUsrMNUsergroup* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmUsrMNUsergroup::handleRequest(
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

bool QryWznmUsrMNUsergroup::handleRerun(
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

bool QryWznmUsrMNUsergroup::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQUsrMNUsergroup* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tixWznmVUserlevel";
	cout << "\tsrefIxWznmVUserlevel";
	cout << "\ttitIxWznmVUserlevel";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixWznmVUserlevel;
		cout << "\t" << rec->srefIxWznmVUserlevel;
		cout << "\t" << rec->titIxWznmVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryWznmUsrMNUsergroup::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMUSRRUSGMOD_USREQ) {
		call->abort = handleCallWznmUsrRusgMod_usrEq(dbswznm, call->jref);
	};
};

bool QryWznmUsrMNUsergroup::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmUsrMNUsergroup::handleCallWznmUsrRusgMod_usrEq(
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
