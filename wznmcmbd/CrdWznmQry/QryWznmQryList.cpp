/**
	* \file QryWznmQryList.cpp
	* job handler for job QryWznmQryList (implementation)
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

#include "QryWznmQryList.h"

#include "QryWznmQryList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmQryList
 ******************************************************************************/

QryWznmQryList::QryWznmQryList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMQRYLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMQRYMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmQryList::~QryWznmQryList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmQryList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMQRYUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMQRYUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmQryList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	ubigint preRefVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMQRYLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMQRYLIST_TYP, jref);
	ubigint preVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMQRYLIST_VER, jref);
	ubigint preSup = xchg->getRefPreset(VecWznmVPreset::PREWZNMQRYLIST_SUP, jref);
	uint preSrl = xchg->getIxPreset(VecWznmVPreset::PREWZNMQRYLIST_SRL, jref);
	ubigint preTbl = xchg->getRefPreset(VecWznmVPreset::PREWZNMQRYLIST_TBL, jref);
	ubigint preQtb = xchg->getRefPreset(VecWznmVPreset::PREWZNMQRYLIST_QTB, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqqrylist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMQuery.ref)";
		sqlstr += " FROM TblWznmMQuery";
		sqlstr += " WHERE TblWznmMQuery.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preSup, preSrl, preTbl, preQtb, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMQuery.ref)";
		sqlstr += " FROM TblWznmMQuery";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preSup, preSrl, preTbl, preQtb, true);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i = 0; i < cnts.size(); i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuery";
		sqlstr += " WHERE TblWznmMQuery.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preSup, preSrl, preTbl, preQtb, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuery";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preSup, preSrl, preTbl, preQtb, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQQryList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmQryList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQQryList(jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refWznmMTable, qtbRefWznmMTable)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMQuery.ref, TblWznmMQuery.sref, TblWznmMQuery.ixVBasetype, TblWznmMQuery.refWznmMVersion, TblWznmMQuery.supRefWznmMQuery, TblWznmMQuery.supIxVSubrole, TblWznmMQuery.refWznmMTable, TblWznmMQuery.qtbRefWznmMTable";
};

void QryWznmQryList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preVer
			, const ubigint preSup
			, const uint preSrl
			, const ubigint preTbl
			, const ubigint preQtb
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuery.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuery.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preVer != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuery.refWznmMVersion = " + to_string(preVer) + "";
	};

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuery.supRefWznmMQuery = " + to_string(preSup) + "";
	};

	if (preSrl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuery.supIxVSubrole = " + to_string(preSrl) + "";
	};

	if (preTbl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuery.refWznmMTable = " + to_string(preTbl) + "";
	};

	if (preQtb != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuery.qtbRefWznmMTable = " + to_string(preQtb) + "";
	};
};

void QryWznmQryList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmQryList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMQuery.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMQuery.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::VER) sqlstr += " ORDER BY TblWznmMQuery.refWznmMVersion ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblWznmMQuery.supRefWznmMQuery ASC";
	else if (preIxOrd == VecVOrd::SRL) sqlstr += " ORDER BY TblWznmMQuery.supIxVSubrole ASC";
	else if (preIxOrd == VecVOrd::TBL) sqlstr += " ORDER BY TblWznmMQuery.refWznmMTable ASC";
	else if (preIxOrd == VecVOrd::QTB) sqlstr += " ORDER BY TblWznmMQuery.qtbRefWznmMTable ASC";
};

void QryWznmQryList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQQryList* rec = NULL;

	dbswznm->tblwznmqqrylist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMQueryBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMQueryBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubRefWznmMVersion = StubWznm::getStubVerStd(dbswznm, rec->refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefWznmMQuery = StubWznm::getStubQryStd(dbswznm, rec->supRefWznmMQuery, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefSupIxVSubrole = VecWznmVMQuerySupSubrole::getSref(rec->supIxVSubrole);
			rec->titSupIxVSubrole = VecWznmVMQuerySupSubrole::getTitle(rec->supIxVSubrole, ixWznmVLocale);
			rec->stubRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubQtbRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->qtbRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmQryList", "fetch");
	};

	refreshJnum();
};

uint QryWznmQryList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQQryList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmQryList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQQryList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQQryList* QryWznmQryList::getRecByJnum(
			const uint jnum
		) {
	WznmQQryList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmQryList::handleRequest(
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

bool QryWznmQryList::handleRerun(
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

bool QryWznmQryList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQQryList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\trefWznmMVersion";
	cout << "\tstubRefWznmMVersion";
	cout << "\tsupRefWznmMQuery";
	cout << "\tstubSupRefWznmMQuery";
	cout << "\tsupIxVSubrole";
	cout << "\tsrefSupIxVSubrole";
	cout << "\ttitSupIxVSubrole";
	cout << "\trefWznmMTable";
	cout << "\tstubRefWznmMTable";
	cout << "\tqtbRefWznmMTable";
	cout << "\tstubQtbRefWznmMTable";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->refWznmMVersion;
		cout << "\t" << rec->stubRefWznmMVersion;
		cout << "\t" << rec->supRefWznmMQuery;
		cout << "\t" << rec->stubSupRefWznmMQuery;
		cout << "\t" << rec->supIxVSubrole;
		cout << "\t" << rec->srefSupIxVSubrole;
		cout << "\t" << rec->titSupIxVSubrole;
		cout << "\t" << rec->refWznmMTable;
		cout << "\t" << rec->stubRefWznmMTable;
		cout << "\t" << rec->qtbRefWznmMTable;
		cout << "\t" << rec->stubQtbRefWznmMTable;
		cout << endl;
	};
	return retval;
};

void QryWznmQryList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQRYMOD) {
		call->abort = handleCallWznmQryMod(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQRYUPD_REFEQ) {
		call->abort = handleCallWznmQryUpd_refEq(dbswznm, call->jref);
	};
};

bool QryWznmQryList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmQryList::handleCallWznmQryMod(
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

bool QryWznmQryList::handleCallWznmQryUpd_refEq(
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
