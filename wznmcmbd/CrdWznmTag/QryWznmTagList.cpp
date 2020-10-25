/**
	* \file QryWznmTagList.cpp
	* job handler for job QryWznmTagList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmTagList.h"

#include "QryWznmTagList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmTagList
 ******************************************************************************/

QryWznmTagList::QryWznmTagList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMTAGLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMTAGMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmTagList::~QryWznmTagList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmTagList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMTAGUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMTAGUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmTagList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMTAGLIST_SRF, jref);
	ubigint preCpb = xchg->getRefPreset(VecWznmVPreset::PREWZNMTAGLIST_CPB, jref);
	string preGrp = xchg->getSrefPreset(VecWznmVPreset::PREWZNMTAGLIST_GRP, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqtaglist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmMTag.ref)";
	sqlstr += " FROM TblWznmMTag";
	rerun_filtSQL(sqlstr, preSrf, preCpb, preGrp, true);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQTagList(jref, jnum, ref, sref, Title, refWznmMCapability, osrefWznmKTaggrp)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMTag.ref, TblWznmMTag.sref, TblWznmMTag.Title, TblWznmMTag.refWznmMCapability, TblWznmMTag.osrefWznmKTaggrp";
	sqlstr += " FROM TblWznmMTag";
	rerun_filtSQL(sqlstr, preSrf, preCpb, preGrp, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQTagList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmTagList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preCpb
			, const string& preGrp
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMTag.sref = '" + preSrf + "'";
	};

	if (preCpb != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMTag.refWznmMCapability = " + to_string(preCpb) + "";
	};

	if (preGrp.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMTag.osrefWznmKTaggrp = '" + preGrp + "'";
	};
};

void QryWznmTagList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmTagList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWznmMTag.osrefWznmKTaggrp ASC";
	else if (preIxOrd == VecVOrd::CPB) sqlstr += " ORDER BY TblWznmMTag.refWznmMCapability ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMTag.sref ASC";
};

void QryWznmTagList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQTagList* rec = NULL;

	dbswznm->tblwznmqtaglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWznmMCapability = StubWznm::getStubCpbStd(dbswznm, rec->refWznmMCapability, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titOsrefWznmKTaggrp = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKTAGGRP, rec->osrefWznmKTaggrp, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmTagList", "fetch");
	};

	refreshJnum();
};

uint QryWznmTagList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQTagList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmTagList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQTagList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQTagList* QryWznmTagList::getRecByJnum(
			const uint jnum
		) {
	WznmQTagList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmTagList::handleRequest(
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

bool QryWznmTagList::handleRerun(
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

bool QryWznmTagList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQTagList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\trefWznmMCapability";
	cout << "\tstubRefWznmMCapability";
	cout << "\tosrefWznmKTaggrp";
	cout << "\ttitOsrefWznmKTaggrp";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->refWznmMCapability;
		cout << "\t" << rec->stubRefWznmMCapability;
		cout << "\t" << rec->osrefWznmKTaggrp;
		cout << "\t" << rec->titOsrefWznmKTaggrp;
		cout << endl;
	};
	return retval;
};

void QryWznmTagList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTAGUPD_REFEQ) {
		call->abort = handleCallWznmTagUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTAGMOD) {
		call->abort = handleCallWznmTagMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmTagList::handleCallWznmTagUpd_refEq(
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

bool QryWznmTagList::handleCallWznmTagMod(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixWznmVQrystate == VecWznmVQrystate::UTD) || (ixWznmVQrystate == VecWznmVQrystate::SLM)) {
		ixWznmVQrystate = VecWznmVQrystate::MNR;
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);
	};

	return retval;
};

bool QryWznmTagList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

