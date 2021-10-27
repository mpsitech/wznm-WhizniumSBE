/**
	* \file QryWznmStbList.cpp
	* job handler for job QryWznmStbList (implementation)
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

#include "QryWznmStbList.h"

#include "QryWznmStbList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmStbList
 ******************************************************************************/

QryWznmStbList::QryWznmStbList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMSTBLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTBMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmStbList::~QryWznmStbList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmStbList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMSTBUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMSTBUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmStbList::rerun(
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
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMSTBLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMSTBLIST_TYP, jref);
	ubigint preTbl = xchg->getRefPreset(VecWznmVPreset::PREWZNMSTBLIST_TBL, jref);
	ubigint preSbs = xchg->getRefPreset(VecWznmVPreset::PREWZNMSTBLIST_SBS, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqstblist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMStub.ref)";
		sqlstr += " FROM TblWznmMStub, TblWznmMTable";
		sqlstr += " WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref";
		sqlstr += " AND TblWznmMTable.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preSbs, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMStub.ref)";
		sqlstr += " FROM TblWznmMStub";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preSbs, true);
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
		sqlstr += " FROM TblWznmMStub, TblWznmMTable";
		sqlstr += " WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref";
		sqlstr += " AND TblWznmMTable.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preSbs, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMStub";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preSbs, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQStbList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmStbList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQStbList(jref, jnum, ref, sref, ixVBasetype, refWznmMTable, refWznmMSubset, Example)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMStub.ref, TblWznmMStub.sref, TblWznmMStub.ixVBasetype, TblWznmMStub.refWznmMTable, TblWznmMStub.refWznmMSubset, TblWznmMStub.Example";
};

void QryWznmStbList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preTbl
			, const ubigint preSbs
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMStub.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMStub.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preTbl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMStub.refWznmMTable = " + to_string(preTbl) + "";
	};

	if (preSbs != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMStub.refWznmMSubset = " + to_string(preSbs) + "";
	};
};

void QryWznmStbList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmStbList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SBS) sqlstr += " ORDER BY TblWznmMStub.refWznmMSubset ASC";
	else if (preIxOrd == VecVOrd::TBL) sqlstr += " ORDER BY TblWznmMStub.refWznmMTable ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMStub.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMStub.ixVBasetype ASC";
};

void QryWznmStbList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQStbList* rec = NULL;

	dbswznm->tblwznmqstblist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMStubBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMStubBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, rec->refWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmStbList", "fetch");
	};

	refreshJnum();
};

uint QryWznmStbList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQStbList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmStbList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQStbList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQStbList* QryWznmStbList::getRecByJnum(
			const uint jnum
		) {
	WznmQStbList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmStbList::handleRequest(
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

bool QryWznmStbList::handleRerun(
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

bool QryWznmStbList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQStbList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\trefWznmMTable";
	cout << "\tstubRefWznmMTable";
	cout << "\trefWznmMSubset";
	cout << "\tstubRefWznmMSubset";
	cout << "\tExample";
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
		cout << "\t" << rec->refWznmMTable;
		cout << "\t" << rec->stubRefWznmMTable;
		cout << "\t" << rec->refWznmMSubset;
		cout << "\t" << rec->stubRefWznmMSubset;
		cout << "\t" << rec->Example;
		cout << endl;
	};
	return retval;
};

void QryWznmStbList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTBUPD_REFEQ) {
		call->abort = handleCallWznmStbUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTBMOD) {
		call->abort = handleCallWznmStbMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmStbList::handleCallWznmStbUpd_refEq(
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

bool QryWznmStbList::handleCallWznmStbMod(
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

bool QryWznmStbList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
