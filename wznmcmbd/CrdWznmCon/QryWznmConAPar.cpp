/**
	* \file QryWznmConAPar.cpp
	* job handler for job QryWznmConAPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmConAPar.h"

#include "QryWznmConAPar_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmConAPar
 ******************************************************************************/

QryWznmConAPar::QryWznmConAPar(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMCONAPAR, jrefSup, ixWznmVLocale)
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

QryWznmConAPar::~QryWznmConAPar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmConAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmConAPar::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCon = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCON, jref);
	string preX1 = xchg->getSrefPreset(VecWznmVPreset::PREWZNMCONAPAR_X1, jref);
	ubigint preX2 = xchg->getRefPreset(VecWznmVPreset::PREWZNMCONAPAR_X2, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMCONAPARMOD_CONEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqconapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMControlPar.ref)";
	sqlstr += " FROM TblWznmAMControlPar";
	sqlstr += " WHERE TblWznmAMControlPar.refWznmMControl = " + to_string(preRefCon) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQConAPar(jref, jnum, ref, x1SrefKKey, x2RefWznmMLocale, osrefKVal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMControlPar.ref, TblWznmAMControlPar.x1SrefKKey, TblWznmAMControlPar.x2RefWznmMLocale, TblWznmAMControlPar.osrefKVal";
	sqlstr += " FROM TblWznmAMControlPar";
	sqlstr += " WHERE TblWznmAMControlPar.refWznmMControl = " + to_string(preRefCon) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQConAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMCONAPARMOD_CONEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCon);
};

void QryWznmConAPar::rerun_filtSQL(
			string& sqlstr
			, const string& preX1
			, const ubigint preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMControlPar.x1SrefKKey = '" + preX1 + "'";
	};

	if (preX2 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMControlPar.x2RefWznmMLocale = " + to_string(preX2) + "";
	};
};

void QryWznmConAPar::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmConAPar::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQConAPar* rec = NULL;

	dbswznm->tblwznmqconapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1SrefKKey = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKAMCONTROLPARKEY, rec->x1SrefKKey, ixWznmVLocale);
			rec->stubX2RefWznmMLocale = StubWznm::getStubLocStd(dbswznm, rec->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titOsrefKVal = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKAMCONTROLPARVAL, rec->osrefKVal, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmConAPar", "fetch");
	};

	refreshJnum();
};

uint QryWznmConAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQConAPar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmConAPar::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQConAPar* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQConAPar* QryWznmConAPar::getRecByJnum(
			const uint jnum
		) {
	WznmQConAPar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmConAPar::handleRequest(
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

bool QryWznmConAPar::handleRerun(
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

bool QryWznmConAPar::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQConAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1SrefKKey";
	cout << "\ttitX1SrefKKey";
	cout << "\tx2RefWznmMLocale";
	cout << "\tstubX2RefWznmMLocale";
	cout << "\tosrefKVal";
	cout << "\ttitOsrefKVal";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1SrefKKey;
		cout << "\t" << rec->titX1SrefKKey;
		cout << "\t" << rec->x2RefWznmMLocale;
		cout << "\t" << rec->stubX2RefWznmMLocale;
		cout << "\t" << rec->osrefKVal;
		cout << "\t" << rec->titOsrefKVal;
		cout << endl;
	};
	return retval;
};

void QryWznmConAPar::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMCONAPARMOD_CONEQ) {
		call->abort = handleCallWznmConAparMod_conEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmConAPar::handleCallWznmConAparMod_conEq(
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

bool QryWznmConAPar::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

