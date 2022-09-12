/**
	* \file QryWznmAppList.cpp
	* job handler for job QryWznmAppList (implementation)
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

#include "QryWznmAppList.h"

#include "QryWznmAppList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmAppList
 ******************************************************************************/

QryWznmAppList::QryWznmAppList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMAPPLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMAPPMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmAppList::~QryWznmAppList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmAppList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMAPPUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMAPPUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmAppList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWznmVPreset::PREWZNMAPPLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWznmVPreset::PREWZNMAPPLIST_OWN, jref);
	string preTit = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMAPPLIST_TIT, jref);
	uint preTrg = xchg->getIxPreset(VecWznmVPreset::PREWZNMAPPLIST_TRG, jref);
	ubigint preVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMAPPLIST_VER, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqapplist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmMApp.ref)";
	sqlstr += " FROM TblWznmMApp, TblWznmQSelect";
	sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWznmMApp.grp = TblWznmQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMApp.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preTit, preTrg, preVer, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQAppList(jref, jnum, ref, grp, own, Short, Title, ixWznmVApptarget, verRefWznmMVersion)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMApp.ref, TblWznmMApp.grp, TblWznmMApp.own, TblWznmMApp.Short, TblWznmMApp.Title, TblWznmMApp.ixWznmVApptarget, TblWznmMApp.verRefWznmMVersion";
	sqlstr += " FROM TblWznmMApp, TblWznmQSelect";
	sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWznmMApp.grp = TblWznmQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMApp.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preTit, preTrg, preVer, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQAppList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmAppList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preTit
			, const uint preTrg
			, const ubigint preVer
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMApp.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMApp.own = " + to_string(preOwn) + "";
	};

	if (preTit.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMApp.Title LIKE '" + preTit + "'";
	};

	if (preTrg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMApp.ixWznmVApptarget = " + to_string(preTrg) + "";
	};

	if (preVer != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMApp.verRefWznmMVersion = " + to_string(preVer) + "";
	};
};

void QryWznmAppList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmAppList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWznmMApp.grp ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWznmMApp.own ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblWznmMApp.Title ASC";
	else if (preIxOrd == VecVOrd::TRG) sqlstr += " ORDER BY TblWznmMApp.ixWznmVApptarget ASC";
	else if (preIxOrd == VecVOrd::VER) sqlstr += " ORDER BY TblWznmMApp.verRefWznmMVersion ASC";
};

void QryWznmAppList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQAppList* rec = NULL;

	dbswznm->tblwznmqapplist->loadRstByJref(jref, false, rst);
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
			rec->srefIxWznmVApptarget = VecWznmVApptarget::getSref(rec->ixWznmVApptarget);
			rec->titIxWznmVApptarget = VecWznmVApptarget::getTitle(rec->ixWznmVApptarget);
			rec->stubVerRefWznmMVersion = StubWznm::getStubVerStd(dbswznm, rec->verRefWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmAppList", "fetch");
	};

	refreshJnum();
};

uint QryWznmAppList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQAppList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmAppList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQAppList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQAppList* QryWznmAppList::getRecByJnum(
			const uint jnum
		) {
	WznmQAppList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmAppList::handleRequest(
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

bool QryWznmAppList::handleRerun(
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

bool QryWznmAppList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQAppList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tShort";
	cout << "\tTitle";
	cout << "\tixWznmVApptarget";
	cout << "\tsrefIxWznmVApptarget";
	cout << "\ttitIxWznmVApptarget";
	cout << "\tverRefWznmMVersion";
	cout << "\tstubVerRefWznmMVersion";
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
		cout << "\t" << rec->Short;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->ixWznmVApptarget;
		cout << "\t" << rec->srefIxWznmVApptarget;
		cout << "\t" << rec->titIxWznmVApptarget;
		cout << "\t" << rec->verRefWznmMVersion;
		cout << "\t" << rec->stubVerRefWznmMVersion;
		cout << endl;
	};
	return retval;
};

void QryWznmAppList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMAPPUPD_REFEQ) {
		call->abort = handleCallWznmAppUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMAPPMOD) {
		call->abort = handleCallWznmAppMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmAppList::handleCallWznmAppUpd_refEq(
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

bool QryWznmAppList::handleCallWznmAppMod(
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

bool QryWznmAppList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
