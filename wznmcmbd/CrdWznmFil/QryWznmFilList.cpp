/**
	* \file QryWznmFilList.cpp
	* job handler for job QryWznmFilList (implementation)
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

#include "QryWznmFilList.h"

#include "QryWznmFilList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmFilList
 ******************************************************************************/

QryWznmFilList::QryWznmFilList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMFILLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMFILMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmFilList::~QryWznmFilList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmFilList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMFILUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMFILUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmFilList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWznmVPreset::PREWZNMFILLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWznmVPreset::PREWZNMFILLIST_OWN, jref);
	string preFnm = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMFILLIST_FNM, jref);
	uint preRet = xchg->getIxPreset(VecWznmVPreset::PREWZNMFILLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWznmVPreset::PREWZNMFILLIST_REU, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqfillist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmMFile.ref)";
	sqlstr += " FROM TblWznmMFile, TblWznmQSelect";
	sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWznmMFile.grp = TblWznmQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQFilList(jref, jnum, ref, grp, own, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMFile.ref, TblWznmMFile.grp, TblWznmMFile.own, TblWznmMFile.Filename, TblWznmMFile.refIxVTbl, TblWznmMFile.refUref, TblWznmMFile.osrefKContent, TblWznmMFile.srefKMimetype, TblWznmMFile.Size";
	sqlstr += " FROM TblWznmMFile, TblWznmQSelect";
	sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWznmMFile.grp = TblWznmQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQFilList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmFilList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preFnm
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMFile.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMFile.own = " + to_string(preOwn) + "";
	};

	if (preFnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMFile.Filename LIKE '" + preFnm + "'";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMFile.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMFile.refUref = " + to_string(preReu) + "";
	};
};

void QryWznmFilList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmFilList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWznmMFile.refUref ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWznmMFile.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::FNM) sqlstr += " ORDER BY TblWznmMFile.Filename ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWznmMFile.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWznmMFile.grp ASC";
};

void QryWznmFilList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQFilList* rec = NULL;

	dbswznm->tblwznmqfillist->loadRstByJref(jref, false, rst);
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
			rec->srefRefIxVTbl = VecWznmVMFileRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWznmVMFileRefTbl::getTitle(rec->refIxVTbl, ixWznmVLocale);
			if (rec->refIxVTbl == VecWznmVMFileRefTbl::LIB) {
				rec->stubRefUref = StubWznm::getStubLibStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMFileRefTbl::VER) {
				rec->stubRefUref = StubWznm::getStubVerStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMFileRefTbl::APP) {
				rec->stubRefUref = StubWznm::getStubAppStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->titOsrefKContent = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKMFILECONTENT, rec->osrefKContent, ixWznmVLocale);
			rec->titSrefKMimetype = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKMFILEMIMETYPE, rec->srefKMimetype, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmFilList", "fetch");
	};

	refreshJnum();
};

uint QryWznmFilList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQFilList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmFilList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQFilList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQFilList* QryWznmFilList::getRecByJnum(
			const uint jnum
		) {
	WznmQFilList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmFilList::handleRequest(
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

bool QryWznmFilList::handleRerun(
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

bool QryWznmFilList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQFilList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tFilename";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\tosrefKContent";
	cout << "\ttitOsrefKContent";
	cout << "\tsrefKMimetype";
	cout << "\ttitSrefKMimetype";
	cout << "\tSize";
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
		cout << "\t" << rec->Filename;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->osrefKContent;
		cout << "\t" << rec->titOsrefKContent;
		cout << "\t" << rec->srefKMimetype;
		cout << "\t" << rec->titSrefKMimetype;
		cout << "\t" << rec->Size;
		cout << endl;
	};
	return retval;
};

void QryWznmFilList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMFILUPD_REFEQ) {
		call->abort = handleCallWznmFilUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFILMOD) {
		call->abort = handleCallWznmFilMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmFilList::handleCallWznmFilUpd_refEq(
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

bool QryWznmFilList::handleCallWznmFilMod(
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

bool QryWznmFilList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
