/**
	* \file QryWznmRelList.cpp
	* job handler for job QryWznmRelList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmRelList.h"

#include "QryWznmRelList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmRelList
 ******************************************************************************/

QryWznmRelList::QryWznmRelList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMRELLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMRELMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmRelList::~QryWznmRelList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmRelList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMRELUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMRELUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmRelList::rerun(
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
	ubigint preFrt = xchg->getRefPreset(VecWznmVPreset::PREWZNMRELLIST_FRT, jref);
	ubigint preFrs = xchg->getRefPreset(VecWznmVPreset::PREWZNMRELLIST_FRS, jref);
	ubigint preTot = xchg->getRefPreset(VecWznmVPreset::PREWZNMRELLIST_TOT, jref);
	ubigint preTos = xchg->getRefPreset(VecWznmVPreset::PREWZNMRELLIST_TOS, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMRELLIST_TYP, jref);
	ubigint preVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMRELLIST_VER, jref);
	ubigint preSup = xchg->getRefPreset(VecWznmVPreset::PREWZNMRELLIST_SUP, jref);
	uint preSrl = xchg->getIxPreset(VecWznmVPreset::PREWZNMRELLIST_SRL, jref);
	ubigint preTbl = xchg->getRefPreset(VecWznmVPreset::PREWZNMRELLIST_TBL, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqrellist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMRelation.ref)";
		sqlstr += " FROM TblWznmMRelation";
		sqlstr += " WHERE TblWznmMRelation.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preFrt, preFrs, preTot, preTos, preTyp, preVer, preSup, preSrl, preTbl, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMRelation.ref)";
		sqlstr += " FROM TblWznmMRelation";
		rerun_filtSQL(sqlstr, preFrt, preFrs, preTot, preTos, preTyp, preVer, preSup, preSrl, preTbl, true);
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
		sqlstr += " FROM TblWznmMRelation";
		sqlstr += " WHERE TblWznmMRelation.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preFrt, preFrs, preTot, preTos, preTyp, preVer, preSup, preSrl, preTbl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMRelation";
		rerun_filtSQL(sqlstr, preFrt, preFrs, preTot, preTos, preTyp, preVer, preSup, preSrl, preTbl, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQRelList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmRelList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQRelList(jref, jnum, ref, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, ixVBasetype, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, refWznmMTable, Prefix)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMRelation.ref, TblWznmMRelation.frRefWznmMTable, TblWznmMRelation.frsRefWznmMSubset, TblWznmMRelation.toRefWznmMTable, TblWznmMRelation.tosRefWznmMSubset, TblWznmMRelation.ixVBasetype, TblWznmMRelation.refWznmMVersion, TblWznmMRelation.supRefWznmMRelation, TblWznmMRelation.supIxVSubrole, TblWznmMRelation.refWznmMTable, TblWznmMRelation.Prefix";
};

void QryWznmRelList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preFrt
			, const ubigint preFrs
			, const ubigint preTot
			, const ubigint preTos
			, const uint preTyp
			, const ubigint preVer
			, const ubigint preSup
			, const uint preSrl
			, const ubigint preTbl
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preFrt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.frRefWznmMTable = " + to_string(preFrt) + "";
	};

	if (preFrs != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.frsRefWznmMSubset = " + to_string(preFrs) + "";
	};

	if (preTot != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.toRefWznmMTable = " + to_string(preTot) + "";
	};

	if (preTos != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.tosRefWznmMSubset = " + to_string(preTos) + "";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preVer != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.refWznmMVersion = " + to_string(preVer) + "";
	};

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.supRefWznmMRelation = " + to_string(preSup) + "";
	};

	if (preSrl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.supIxVSubrole = " + to_string(preSrl) + "";
	};

	if (preTbl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMRelation.refWznmMTable = " + to_string(preTbl) + "";
	};
};

void QryWznmRelList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmRelList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TBL) sqlstr += " ORDER BY TblWznmMRelation.refWznmMTable ASC";
	else if (preIxOrd == VecVOrd::SRL) sqlstr += " ORDER BY TblWznmMRelation.supIxVSubrole ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblWznmMRelation.supRefWznmMRelation ASC";
	else if (preIxOrd == VecVOrd::VER) sqlstr += " ORDER BY TblWznmMRelation.refWznmMVersion ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMRelation.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::TOT) sqlstr += " ORDER BY TblWznmMRelation.toRefWznmMTable ASC";
	else if (preIxOrd == VecVOrd::TOS) sqlstr += " ORDER BY TblWznmMRelation.tosRefWznmMSubset ASC";
	else if (preIxOrd == VecVOrd::FRS) sqlstr += " ORDER BY TblWznmMRelation.frsRefWznmMSubset ASC";
	else if (preIxOrd == VecVOrd::FRT) sqlstr += " ORDER BY TblWznmMRelation.frRefWznmMTable ASC";
};

void QryWznmRelList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQRelList* rec = NULL;

	dbswznm->tblwznmqrellist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubFrRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->frRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubFrsRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, rec->frsRefWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubToRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->toRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubTosRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, rec->tosRefWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVBasetype = VecWznmVMRelationBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMRelationBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubRefWznmMVersion = StubWznm::getStubVerStd(dbswznm, rec->refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefWznmMRelation = StubWznm::getStubRelStd(dbswznm, rec->supRefWznmMRelation, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefSupIxVSubrole = VecWznmVMRelationSupSubrole::getSref(rec->supIxVSubrole);
			rec->titSupIxVSubrole = VecWznmVMRelationSupSubrole::getTitle(rec->supIxVSubrole, ixWznmVLocale);
			rec->stubRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmRelList", "fetch");
	};

	refreshJnum();
};

uint QryWznmRelList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQRelList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmRelList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQRelList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQRelList* QryWznmRelList::getRecByJnum(
			const uint jnum
		) {
	WznmQRelList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmRelList::handleRequest(
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

bool QryWznmRelList::handleRerun(
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

bool QryWznmRelList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQRelList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tfrRefWznmMTable";
	cout << "\tstubFrRefWznmMTable";
	cout << "\tfrsRefWznmMSubset";
	cout << "\tstubFrsRefWznmMSubset";
	cout << "\ttoRefWznmMTable";
	cout << "\tstubToRefWznmMTable";
	cout << "\ttosRefWznmMSubset";
	cout << "\tstubTosRefWznmMSubset";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\trefWznmMVersion";
	cout << "\tstubRefWznmMVersion";
	cout << "\tsupRefWznmMRelation";
	cout << "\tstubSupRefWznmMRelation";
	cout << "\tsupIxVSubrole";
	cout << "\tsrefSupIxVSubrole";
	cout << "\ttitSupIxVSubrole";
	cout << "\trefWznmMTable";
	cout << "\tstubRefWznmMTable";
	cout << "\tPrefix";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->frRefWznmMTable;
		cout << "\t" << rec->stubFrRefWznmMTable;
		cout << "\t" << rec->frsRefWznmMSubset;
		cout << "\t" << rec->stubFrsRefWznmMSubset;
		cout << "\t" << rec->toRefWznmMTable;
		cout << "\t" << rec->stubToRefWznmMTable;
		cout << "\t" << rec->tosRefWznmMSubset;
		cout << "\t" << rec->stubTosRefWznmMSubset;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->refWznmMVersion;
		cout << "\t" << rec->stubRefWznmMVersion;
		cout << "\t" << rec->supRefWznmMRelation;
		cout << "\t" << rec->stubSupRefWznmMRelation;
		cout << "\t" << rec->supIxVSubrole;
		cout << "\t" << rec->srefSupIxVSubrole;
		cout << "\t" << rec->titSupIxVSubrole;
		cout << "\t" << rec->refWznmMTable;
		cout << "\t" << rec->stubRefWznmMTable;
		cout << "\t" << rec->Prefix;
		cout << endl;
	};
	return retval;
};

void QryWznmRelList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMRELUPD_REFEQ) {
		call->abort = handleCallWznmRelUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRELMOD) {
		call->abort = handleCallWznmRelMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmRelList::handleCallWznmRelUpd_refEq(
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

bool QryWznmRelList::handleCallWznmRelMod(
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

bool QryWznmRelList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

