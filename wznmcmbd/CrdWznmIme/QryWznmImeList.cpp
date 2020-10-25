/**
	* \file QryWznmImeList.cpp
	* job handler for job QryWznmImeList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmImeList.h"

#include "QryWznmImeList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmImeList
 ******************************************************************************/

QryWznmImeList::QryWznmImeList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMIMELIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMIMEMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmImeList::~QryWznmImeList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmImeList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMIMEUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMIMEUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmImeList::rerun(
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
	ubigint preRefIex = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIEX, jref);
	ubigint preRefVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMIMELIST_SRF, jref);
	ubigint preIex = xchg->getRefPreset(VecWznmVPreset::PREWZNMIMELIST_IEX, jref);
	ubigint preSup = xchg->getRefPreset(VecWznmVPreset::PREWZNMIMELIST_SUP, jref);
	ubigint preTbl = xchg->getRefPreset(VecWznmVPreset::PREWZNMIMELIST_TBL, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqimelist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFIEX) {
		sqlstr = "SELECT COUNT(TblWznmMImpexp.ref)";
		sqlstr += " FROM TblWznmMImpexp";
		sqlstr += " WHERE TblWznmMImpexp.refWznmMImpexpcplx = " + to_string(preRefIex) + "";
		rerun_filtSQL(sqlstr, preSrf, preIex, preSup, preTbl, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMImpexp.ref)";
		sqlstr += " FROM TblWznmMImpexp, TblWznmMImpexpcplx";
		sqlstr += " WHERE TblWznmMImpexp.refWznmMImpexpcplx = TblWznmMImpexpcplx.ref";
		sqlstr += " AND TblWznmMImpexpcplx.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preIex, preSup, preTbl, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMImpexp.ref)";
		sqlstr += " FROM TblWznmMImpexp";
		rerun_filtSQL(sqlstr, preSrf, preIex, preSup, preTbl, true);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFIEX) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMImpexp";
		sqlstr += " WHERE TblWznmMImpexp.refWznmMImpexpcplx = " + to_string(preRefIex) + "";
		rerun_filtSQL(sqlstr, preSrf, preIex, preSup, preTbl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMImpexp, TblWznmMImpexpcplx";
		sqlstr += " WHERE TblWznmMImpexp.refWznmMImpexpcplx = TblWznmMImpexpcplx.ref";
		sqlstr += " AND TblWznmMImpexpcplx.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preIex, preSup, preTbl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMImpexp";
		rerun_filtSQL(sqlstr, preSrf, preIex, preSup, preTbl, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQImeList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmImeList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQImeList(jref, jnum, ref, sref, refWznmMImpexpcplx, supRefWznmMImpexp, refWznmMTable)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMImpexp.ref, TblWznmMImpexp.sref, TblWznmMImpexp.refWznmMImpexpcplx, TblWznmMImpexp.supRefWznmMImpexp, TblWznmMImpexp.refWznmMTable";
};

void QryWznmImeList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preIex
			, const ubigint preSup
			, const ubigint preTbl
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMImpexp.sref = '" + preSrf + "'";
	};

	if (preIex != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMImpexp.refWznmMImpexpcplx = " + to_string(preIex) + "";
	};

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMImpexp.supRefWznmMImpexp = " + to_string(preSup) + "";
	};

	if (preTbl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMImpexp.refWznmMTable = " + to_string(preTbl) + "";
	};
};

void QryWznmImeList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmImeList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TBL) sqlstr += " ORDER BY TblWznmMImpexp.refWznmMTable ASC";
	else if (preIxOrd == VecVOrd::IEX) sqlstr += " ORDER BY TblWznmMImpexp.refWznmMImpexpcplx ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblWznmMImpexp.supRefWznmMImpexp ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMImpexp.sref ASC";
};

void QryWznmImeList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQImeList* rec = NULL;

	dbswznm->tblwznmqimelist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWznmMImpexpcplx = StubWznm::getStubIexStd(dbswznm, rec->refWznmMImpexpcplx, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefWznmMImpexp = StubWznm::getStubImeStd(dbswznm, rec->supRefWznmMImpexp, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmImeList", "fetch");
	};

	refreshJnum();
};

uint QryWznmImeList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQImeList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmImeList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQImeList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQImeList* QryWznmImeList::getRecByJnum(
			const uint jnum
		) {
	WznmQImeList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmImeList::handleRequest(
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

bool QryWznmImeList::handleRerun(
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

bool QryWznmImeList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQImeList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\trefWznmMImpexpcplx";
	cout << "\tstubRefWznmMImpexpcplx";
	cout << "\tsupRefWznmMImpexp";
	cout << "\tstubSupRefWznmMImpexp";
	cout << "\trefWznmMTable";
	cout << "\tstubRefWznmMTable";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refWznmMImpexpcplx;
		cout << "\t" << rec->stubRefWznmMImpexpcplx;
		cout << "\t" << rec->supRefWznmMImpexp;
		cout << "\t" << rec->stubSupRefWznmMImpexp;
		cout << "\t" << rec->refWznmMTable;
		cout << "\t" << rec->stubRefWznmMTable;
		cout << endl;
	};
	return retval;
};

void QryWznmImeList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMIMEMOD) {
		call->abort = handleCallWznmImeMod(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIMEUPD_REFEQ) {
		call->abort = handleCallWznmImeUpd_refEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmImeList::handleCallWznmImeMod(
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

bool QryWznmImeList::handleCallWznmImeUpd_refEq(
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

bool QryWznmImeList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

