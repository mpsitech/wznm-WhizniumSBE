/**
	* \file QryWznmPrjMNPerson.cpp
	* job handler for job QryWznmPrjMNPerson (implementation)
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

#include "QryWznmPrjMNPerson.h"

#include "QryWznmPrjMNPerson_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmPrjMNPerson
 ******************************************************************************/

QryWznmPrjMNPerson::QryWznmPrjMNPerson(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMPRJMNPERSON, jrefSup, ixWznmVLocale)
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

QryWznmPrjMNPerson::~QryWznmPrjMNPerson() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmPrjMNPerson::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmPrjMNPerson::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefPrj = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPRJ, jref);
	int preX1 = xchg->getIntvalPreset(VecWznmVPreset::PREWZNMPRJMNPERSON_X1, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMPRSRPRJMOD_PRJEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqprjmnperson->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmRMPersonMProject.ref)";
	sqlstr += " FROM TblWznmMPerson, TblWznmRMPersonMProject";
	sqlstr += " WHERE TblWznmRMPersonMProject.refWznmMPerson = TblWznmMPerson.ref";
	sqlstr += " AND TblWznmRMPersonMProject.refWznmMProject = " + to_string(preRefPrj) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQPrjMNPerson(jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMPerson.ref, TblWznmRMPersonMProject.ref, TblWznmRMPersonMProject.x1Startd, TblWznmRMPersonMProject.x1Stopd, TblWznmRMPersonMProject.srefKFunction";
	sqlstr += " FROM TblWznmMPerson, TblWznmRMPersonMProject";
	sqlstr += " WHERE TblWznmRMPersonMProject.refWznmMPerson = TblWznmMPerson.ref";
	sqlstr += " AND TblWznmRMPersonMProject.refWznmMProject = " + to_string(preRefPrj) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " ORDER BY TblWznmMPerson.Lastname ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQPrjMNPerson SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMPRSRPRJMOD_PRJEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefPrj);
};

void QryWznmPrjMNPerson::rerun_filtSQL(
			string& sqlstr
			, const int preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmRMPersonMProject.x1Startd <= " + to_string(preX1) + "";
	};

	if (preX1 != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmRMPersonMProject.x1Stopd >= " + to_string(preX1) + "";
	};
};

void QryWznmPrjMNPerson::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmPrjMNPerson::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQPrjMNPerson* rec = NULL;

	dbswznm->tblwznmqprjmnperson->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWznm::getStubPrsStd(dbswznm, rec->mref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmX1Startd = Ftm::date(rec->x1Startd);
			rec->ftmX1Stopd = Ftm::date(rec->x1Stopd);
			rec->titSrefKFunction = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKRMPERSONMPROJECTFUNCTION, rec->srefKFunction, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmPrjMNPerson", "fetch");
	};

	refreshJnum();
};

uint QryWznmPrjMNPerson::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQPrjMNPerson* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmPrjMNPerson::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQPrjMNPerson* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQPrjMNPerson* QryWznmPrjMNPerson::getRecByJnum(
			const uint jnum
		) {
	WznmQPrjMNPerson* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmPrjMNPerson::handleRequest(
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

bool QryWznmPrjMNPerson::handleRerun(
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

bool QryWznmPrjMNPerson::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQPrjMNPerson* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1Startd";
	cout << "\tftmX1Startd";
	cout << "\tx1Stopd";
	cout << "\tftmX1Stopd";
	cout << "\tsrefKFunction";
	cout << "\ttitSrefKFunction";
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
		cout << "\t" << rec->x1Startd;
		cout << "\t" << rec->ftmX1Startd;
		cout << "\t" << rec->x1Stopd;
		cout << "\t" << rec->ftmX1Stopd;
		cout << "\t" << rec->srefKFunction;
		cout << "\t" << rec->titSrefKFunction;
		cout << endl;
	};
	return retval;
};

void QryWznmPrjMNPerson::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPRSRPRJMOD_PRJEQ) {
		call->abort = handleCallWznmPrsRprjMod_prjEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmPrjMNPerson::handleCallWznmPrsRprjMod_prjEq(
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

bool QryWznmPrjMNPerson::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};



