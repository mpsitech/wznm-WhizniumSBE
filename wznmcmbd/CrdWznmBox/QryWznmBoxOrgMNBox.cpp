/**
	* \file QryWznmBoxOrgMNBox.cpp
	* job handler for job QryWznmBoxOrgMNBox (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmBoxOrgMNBox.h"

#include "QryWznmBoxOrgMNBox_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmBoxOrgMNBox
 ******************************************************************************/

QryWznmBoxOrgMNBox::QryWznmBoxOrgMNBox(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMBOXORGMNBOX, jrefSup, ixWznmVLocale)
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

QryWznmBoxOrgMNBox::~QryWznmBoxOrgMNBox() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmBoxOrgMNBox::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmBoxOrgMNBox::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefBox = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFBOX, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMBOXRBOXMOD_ORGEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqboxorgmnbox->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmRMBoxMBox.ref)";
	sqlstr += " FROM TblWznmMBox, TblWznmRMBoxMBox";
	sqlstr += " WHERE TblWznmRMBoxMBox.dstRefWznmMBox = TblWznmMBox.ref";
	sqlstr += " AND TblWznmRMBoxMBox.orgRefWznmMBox = " + to_string(preRefBox) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQBoxOrgMNBox(jref, jnum, mref, ref, orgClk, dstClk, Weight)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMBox.ref, TblWznmRMBoxMBox.ref, TblWznmRMBoxMBox.orgClk, TblWznmRMBoxMBox.dstClk, TblWznmRMBoxMBox.Weight";
	sqlstr += " FROM TblWznmMBox, TblWznmRMBoxMBox";
	sqlstr += " WHERE TblWznmRMBoxMBox.dstRefWznmMBox = TblWznmMBox.ref";
	sqlstr += " AND TblWznmRMBoxMBox.orgRefWznmMBox = " + to_string(preRefBox) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQBoxOrgMNBox SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMBOXRBOXMOD_ORGEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefBox);
};

void QryWznmBoxOrgMNBox::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQBoxOrgMNBox* rec = NULL;

	dbswznm->tblwznmqboxorgmnbox->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWznm::getStubBoxStd(dbswznm, rec->mref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmBoxOrgMNBox", "fetch");
	};

	refreshJnum();
};

uint QryWznmBoxOrgMNBox::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQBoxOrgMNBox* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmBoxOrgMNBox::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQBoxOrgMNBox* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQBoxOrgMNBox* QryWznmBoxOrgMNBox::getRecByJnum(
			const uint jnum
		) {
	WznmQBoxOrgMNBox* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmBoxOrgMNBox::handleRequest(
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

bool QryWznmBoxOrgMNBox::handleRerun(
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

bool QryWznmBoxOrgMNBox::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQBoxOrgMNBox* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\torgClk";
	cout << "\tdstClk";
	cout << "\tWeight";
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
		cout << "\t" << rec->orgClk;
		cout << "\t" << rec->dstClk;
		cout << "\t" << rec->Weight;
		cout << endl;
	};
	return retval;
};

void QryWznmBoxOrgMNBox::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMBOXRBOXMOD_ORGEQ) {
		call->abort = handleCallWznmBoxRboxMod_orgEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmBoxOrgMNBox::handleCallWznmBoxRboxMod_orgEq(
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

bool QryWznmBoxOrgMNBox::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
