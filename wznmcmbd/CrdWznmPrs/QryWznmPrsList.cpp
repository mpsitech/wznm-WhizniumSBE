/**
	* \file QryWznmPrsList.cpp
	* job handler for job QryWznmPrsList (implementation)
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

#include "QryWznmPrsList.h"

#include "QryWznmPrsList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmPrsList
 ******************************************************************************/

QryWznmPrsList::QryWznmPrsList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMPRSLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMPRSMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmPrsList::~QryWznmPrsList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmPrsList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMPRSUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMPRSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmPrsList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWznmVPreset::PREWZNMPRSLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWznmVPreset::PREWZNMPRSLIST_OWN, jref);
	string preLnm = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMPRSLIST_LNM, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqprslist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmMPerson.ref)";
	sqlstr += " FROM TblWznmMPerson, TblWznmQSelect";
	sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWznmMPerson.grp = TblWznmQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMPerson.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preLnm, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQPrsList(jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMPerson.ref, TblWznmMPerson.grp, TblWznmMPerson.own, TblWznmMPerson.Title, TblWznmMPerson.Firstname, TblWznmMPerson.Lastname, TblWznmMPerson.ixVSex, TblWznmMPerson.telVal, TblWznmMPerson.emlVal";
	sqlstr += " FROM TblWznmMPerson, TblWznmQSelect";
	sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWznmMPerson.grp = TblWznmQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMPerson.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preLnm, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQPrsList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmPrsList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preLnm
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMPerson.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMPerson.own = " + to_string(preOwn) + "";
	};

	if (preLnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMPerson.Lastname LIKE '" + preLnm + "'";
	};
};

void QryWznmPrsList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmPrsList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWznmMPerson.own ASC";
	else if (preIxOrd == VecVOrd::LNM) sqlstr += " ORDER BY TblWznmMPerson.Lastname ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWznmMPerson.grp ASC";
};

void QryWznmPrsList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQPrsList* rec = NULL;

	dbswznm->tblwznmqprslist->loadRstByJref(jref, false, rst);
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
			rec->srefIxVSex = VecWznmVMPersonSex::getSref(rec->ixVSex);
			rec->titIxVSex = VecWznmVMPersonSex::getTitle(rec->ixVSex, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmPrsList", "fetch");
	};

	refreshJnum();
};

uint QryWznmPrsList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQPrsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmPrsList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQPrsList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQPrsList* QryWznmPrsList::getRecByJnum(
			const uint jnum
		) {
	WznmQPrsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmPrsList::handleRequest(
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

bool QryWznmPrsList::handleRerun(
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

bool QryWznmPrsList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQPrsList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tTitle";
	cout << "\tFirstname";
	cout << "\tLastname";
	cout << "\tixVSex";
	cout << "\tsrefIxVSex";
	cout << "\ttitIxVSex";
	cout << "\ttelVal";
	cout << "\temlVal";
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
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Firstname;
		cout << "\t" << rec->Lastname;
		cout << "\t" << rec->ixVSex;
		cout << "\t" << rec->srefIxVSex;
		cout << "\t" << rec->titIxVSex;
		cout << "\t" << rec->telVal;
		cout << "\t" << rec->emlVal;
		cout << endl;
	};
	return retval;
};

void QryWznmPrsList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPRSUPD_REFEQ) {
		call->abort = handleCallWznmPrsUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPRSMOD) {
		call->abort = handleCallWznmPrsMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmPrsList::handleCallWznmPrsUpd_refEq(
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

bool QryWznmPrsList::handleCallWznmPrsMod(
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

bool QryWznmPrsList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
