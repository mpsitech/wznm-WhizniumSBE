/**
	* \file QryWznmTcoATitle.cpp
	* job handler for job QryWznmTcoATitle (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmTcoATitle.h"

#include "QryWznmTcoATitle_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmTcoATitle
 ******************************************************************************/

QryWznmTcoATitle::QryWznmTcoATitle(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMTCOATITLE, jrefSup, ixWznmVLocale)
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

QryWznmTcoATitle::~QryWznmTcoATitle() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmTcoATitle::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmTcoATitle::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefTco = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTCO, jref);
	uint preX1 = xchg->getIxPreset(VecWznmVPreset::PREWZNMTCOATITLE_X1, jref);
	ubigint preX2 = xchg->getRefPreset(VecWznmVPreset::PREWZNMTCOATITLE_X2, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMTCOATITMOD_TCOEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqtcoatitle->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMTablecolTitle.ref)";
	sqlstr += " FROM TblWznmAMTablecolTitle";
	sqlstr += " WHERE TblWznmAMTablecolTitle.refWznmMTablecol = " + to_string(preRefTco) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQTcoATitle(jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMTablecolTitle.ref, TblWznmAMTablecolTitle.x1IxVType, TblWznmAMTablecolTitle.x2RefWznmMLocale, TblWznmAMTablecolTitle.Title";
	sqlstr += " FROM TblWznmAMTablecolTitle";
	sqlstr += " WHERE TblWznmAMTablecolTitle.refWznmMTablecol = " + to_string(preRefTco) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQTcoATitle SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMTCOATITMOD_TCOEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefTco);
};

void QryWznmTcoATitle::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const ubigint preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMTablecolTitle.x1IxVType = " + to_string(preX1) + "";
	};

	if (preX2 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMTablecolTitle.x2RefWznmMLocale = " + to_string(preX2) + "";
	};
};

void QryWznmTcoATitle::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmTcoATitle::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQTcoATitle* rec = NULL;

	dbswznm->tblwznmqtcoatitle->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxVType = VecWznmVAMTablecolTitleType::getSref(rec->x1IxVType);
			rec->titX1IxVType = VecWznmVAMTablecolTitleType::getTitle(rec->x1IxVType, ixWznmVLocale);
			rec->stubX2RefWznmMLocale = StubWznm::getStubLocStd(dbswznm, rec->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmTcoATitle", "fetch");
	};

	refreshJnum();
};

uint QryWznmTcoATitle::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQTcoATitle* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmTcoATitle::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQTcoATitle* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQTcoATitle* QryWznmTcoATitle::getRecByJnum(
			const uint jnum
		) {
	WznmQTcoATitle* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmTcoATitle::handleRequest(
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

bool QryWznmTcoATitle::handleRerun(
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

bool QryWznmTcoATitle::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQTcoATitle* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxVType";
	cout << "\tsrefX1IxVType";
	cout << "\ttitX1IxVType";
	cout << "\tx2RefWznmMLocale";
	cout << "\tstubX2RefWznmMLocale";
	cout << "\tTitle";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxVType;
		cout << "\t" << rec->srefX1IxVType;
		cout << "\t" << rec->titX1IxVType;
		cout << "\t" << rec->x2RefWznmMLocale;
		cout << "\t" << rec->stubX2RefWznmMLocale;
		cout << "\t" << rec->Title;
		cout << endl;
	};
	return retval;
};

void QryWznmTcoATitle::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTCOATITMOD_TCOEQ) {
		call->abort = handleCallWznmTcoAtitMod_tcoEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmTcoATitle::handleCallWznmTcoAtitMod_tcoEq(
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

bool QryWznmTcoATitle::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

