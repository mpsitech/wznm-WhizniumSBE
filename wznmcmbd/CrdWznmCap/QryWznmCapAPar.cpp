/**
	* \file QryWznmCapAPar.cpp
	* job handler for job QryWznmCapAPar (implementation)
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

#include "QryWznmCapAPar.h"

#include "QryWznmCapAPar_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmCapAPar
 ******************************************************************************/

QryWznmCapAPar::QryWznmCapAPar(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMCAPAPAR, jrefSup, ixWznmVLocale)
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

QryWznmCapAPar::~QryWznmCapAPar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmCapAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmCapAPar::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCap = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAP, jref);
	string preX1 = xchg->getSrefPreset(VecWznmVPreset::PREWZNMCAPAPAR_X1, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMCPBAPARMOD_CPBEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqcapapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMCapabilityPar.ref)";
	sqlstr += " FROM TblWznmAMCapabilityPar";
	sqlstr += " WHERE TblWznmAMCapabilityPar.cpbRefWznmMCapability = " + to_string(preRefCap) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQCapAPar(jref, jnum, ref, cpbNum, x1SrefKKey, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMCapabilityPar.ref, TblWznmAMCapabilityPar.cpbNum, TblWznmAMCapabilityPar.x1SrefKKey, TblWznmAMCapabilityPar.Val";
	sqlstr += " FROM TblWznmAMCapabilityPar";
	sqlstr += " WHERE TblWznmAMCapabilityPar.cpbRefWznmMCapability = " + to_string(preRefCap) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " ORDER BY cpbNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQCapAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMCPBAPARMOD_CPBEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCap);
};

void QryWznmCapAPar::rerun_filtSQL(
			string& sqlstr
			, const string& preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMCapabilityPar.x1SrefKKey = '" + preX1 + "'";
	};
};

void QryWznmCapAPar::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmCapAPar::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQCapAPar* rec = NULL;

	dbswznm->tblwznmqcapapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1SrefKKey = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKAMCAPABILITYPARKEY, rec->x1SrefKKey, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmCapAPar", "fetch");
	};

	refreshJnum();
};

uint QryWznmCapAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQCapAPar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmCapAPar::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQCapAPar* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQCapAPar* QryWznmCapAPar::getRecByJnum(
			const uint jnum
		) {
	WznmQCapAPar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmCapAPar::handleRequest(
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

bool QryWznmCapAPar::handleRerun(
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

bool QryWznmCapAPar::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQCapAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tcpbNum";
	cout << "\tx1SrefKKey";
	cout << "\ttitX1SrefKKey";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->cpbNum;
		cout << "\t" << rec->x1SrefKKey;
		cout << "\t" << rec->titX1SrefKKey;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryWznmCapAPar::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMCPBAPARMOD_CPBEQ) {
		call->abort = handleCallWznmCpbAparMod_cpbEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmCapAPar::handleCallWznmCpbAparMod_cpbEq(
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

bool QryWznmCapAPar::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};



