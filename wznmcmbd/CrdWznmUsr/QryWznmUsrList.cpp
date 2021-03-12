/**
	* \file QryWznmUsrList.cpp
	* job handler for job QryWznmUsrList (implementation)
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

#include "QryWznmUsrList.h"

#include "QryWznmUsrList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmUsrList
 ******************************************************************************/

QryWznmUsrList::QryWznmUsrList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMUSRLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMUSRMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmUsrList::~QryWznmUsrList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmUsrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMUSRUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMUSRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmUsrList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWznmVPreset::PREWZNMUSRLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWznmVPreset::PREWZNMUSRLIST_OWN, jref);
	ubigint prePrs = xchg->getRefPreset(VecWznmVPreset::PREWZNMUSRLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMUSRLIST_SRF, jref);
	ubigint preUsg = xchg->getRefPreset(VecWznmVPreset::PREWZNMUSRLIST_USG, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqusrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmMUser.ref)";
	sqlstr += " FROM TblWznmMUser, TblWznmQSelect";
	sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWznmMUser.grp = TblWznmQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQUsrList(jref, jnum, ref, grp, own, refWznmMPerson, sref, refWznmMUsergroup, ixVState, ixWznmVLocale, ixWznmVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMUser.ref, TblWznmMUser.grp, TblWznmMUser.own, TblWznmMUser.refWznmMPerson, TblWznmMUser.sref, TblWznmMUser.refWznmMUsergroup, TblWznmMUser.ixVState, TblWznmMUser.ixWznmVLocale, TblWznmMUser.ixWznmVUserlevel";
	sqlstr += " FROM TblWznmMUser, TblWznmQSelect";
	sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWznmMUser.grp = TblWznmQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQUsrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmUsrList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preUsg
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMUser.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMUser.own = " + to_string(preOwn) + "";
	};

	if (prePrs != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMUser.refWznmMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMUser.sref = '" + preSrf + "'";
	};

	if (preUsg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMUser.refWznmMUsergroup = " + to_string(preUsg) + "";
	};
};

void QryWznmUsrList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmUsrList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::USG) sqlstr += " ORDER BY TblWznmMUser.refWznmMUsergroup ASC";
	else if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblWznmMUser.refWznmMPerson ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMUser.sref ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWznmMUser.grp ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWznmMUser.own ASC";
};

void QryWznmUsrList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQUsrList* rec = NULL;

	dbswznm->tblwznmqusrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubWznm::getStubGroup(dbswznm, rec->grp, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubWznm::getStubOwner(dbswznm, rec->own, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMPerson = StubWznm::getStubPrsStd(dbswznm, rec->refWznmMPerson, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMUsergroup = StubWznm::getStubUsgStd(dbswznm, rec->refWznmMUsergroup, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecWznmVMUserState::getSref(rec->ixVState);
			rec->titIxVState = VecWznmVMUserState::getTitle(rec->ixVState, ixWznmVLocale);
			rec->srefIxWznmVLocale = VecWznmVLocale::getSref(rec->ixWznmVLocale);
			rec->titIxWznmVLocale = VecWznmVLocale::getTitle(rec->ixWznmVLocale, ixWznmVLocale);
			rec->srefIxWznmVUserlevel = VecWznmVUserlevel::getSref(rec->ixWznmVUserlevel);
			rec->titIxWznmVUserlevel = VecWznmVUserlevel::getTitle(rec->ixWznmVUserlevel, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmUsrList", "fetch");
	};

	refreshJnum();
};

uint QryWznmUsrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmUsrList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQUsrList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQUsrList* QryWznmUsrList::getRecByJnum(
			const uint jnum
		) {
	WznmQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmUsrList::handleRequest(
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

bool QryWznmUsrList::handleRerun(
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

bool QryWznmUsrList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQUsrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\trefWznmMPerson";
	cout << "\tstubRefWznmMPerson";
	cout << "\tsref";
	cout << "\trefWznmMUsergroup";
	cout << "\tstubRefWznmMUsergroup";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixWznmVLocale";
	cout << "\tsrefIxWznmVLocale";
	cout << "\ttitIxWznmVLocale";
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
		cout << "\t" << rec->ref;
		cout << "\t" << rec->grp;
		cout << "\t" << rec->stubGrp;
		cout << "\t" << rec->own;
		cout << "\t" << rec->stubOwn;
		cout << "\t" << rec->refWznmMPerson;
		cout << "\t" << rec->stubRefWznmMPerson;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refWznmMUsergroup;
		cout << "\t" << rec->stubRefWznmMUsergroup;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixWznmVLocale;
		cout << "\t" << rec->srefIxWznmVLocale;
		cout << "\t" << rec->titIxWznmVLocale;
		cout << "\t" << rec->ixWznmVUserlevel;
		cout << "\t" << rec->srefIxWznmVUserlevel;
		cout << "\t" << rec->titIxWznmVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryWznmUsrList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMUSRUPD_REFEQ) {
		call->abort = handleCallWznmUsrUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMUSRMOD) {
		call->abort = handleCallWznmUsrMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmUsrList::handleCallWznmUsrUpd_refEq(
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

bool QryWznmUsrList::handleCallWznmUsrMod(
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

bool QryWznmUsrList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
