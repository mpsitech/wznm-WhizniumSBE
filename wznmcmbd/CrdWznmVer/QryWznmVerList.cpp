/**
	* \file QryWznmVerList.cpp
	* job handler for job QryWznmVerList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmVerList.h"

#include "QryWznmVerList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmVerList
 ******************************************************************************/

QryWznmVerList::QryWznmVerList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMVERLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMVERMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmVerList::~QryWznmVerList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmVerList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMVERUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMVERUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmVerList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	bool preNoadm = xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref);
	uint preIxPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	ubigint preRefPrj = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPRJ, jref);
	ubigint preGrp = xchg->getRefPreset(VecWznmVPreset::PREWZNMVERLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWznmVPreset::PREWZNMVERLIST_OWN, jref);
	ubigint prePrj = xchg->getRefPreset(VecWznmVPreset::PREWZNMVERLIST_PRJ, jref);
	ubigint preBvr = xchg->getRefPreset(VecWznmVPreset::PREWZNMVERLIST_BVR, jref);
	ubigint preLoc = xchg->getRefPreset(VecWznmVPreset::PREWZNMVERLIST_LOC, jref);
	uint preSte = xchg->getIxPreset(VecWznmVPreset::PREWZNMVERLIST_STE, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqverlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFPRJ) {
		sqlstr = "SELECT COUNT(TblWznmMVersion.ref)";
		sqlstr += " FROM TblWznmMVersion, TblWznmQSelect";
		sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWznmMVersion.grp = TblWznmQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMVersion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWznmMVersion.prjRefWznmMProject = " + to_string(preRefPrj) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, prePrj, preBvr, preLoc, preSte, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMVersion.ref)";
		sqlstr += " FROM TblWznmMVersion, TblWznmQSelect";
		sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWznmMVersion.grp = TblWznmQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMVersion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, prePrj, preBvr, preLoc, preSte, false);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFPRJ) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMVersion, TblWznmQSelect";
		sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWznmMVersion.grp = TblWznmQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMVersion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWznmMVersion.prjRefWznmMProject = " + to_string(preRefPrj) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, prePrj, preBvr, preLoc, preSte, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMVersion, TblWznmQSelect";
		sqlstr += " WHERE TblWznmQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWznmMVersion.grp = TblWznmQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWznmMVersion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, prePrj, preBvr, preLoc, preSte, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQVerList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmVerList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQVerList(jref, jnum, ref, grp, own, prjRefWznmMProject, Major, Minor, Sub, bvrRefWznmMVersion, refWznmMLocale, ixVState, ixWDbmstype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMVersion.ref, TblWznmMVersion.grp, TblWznmMVersion.own, TblWznmMVersion.prjRefWznmMProject, TblWznmMVersion.Major, TblWznmMVersion.Minor, TblWznmMVersion.Sub, TblWznmMVersion.bvrRefWznmMVersion, TblWznmMVersion.refWznmMLocale, TblWznmMVersion.ixVState, TblWznmMVersion.ixWDbmstype";
};

void QryWznmVerList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint prePrj
			, const ubigint preBvr
			, const ubigint preLoc
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMVersion.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMVersion.own = " + to_string(preOwn) + "";
	};

	if (prePrj != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMVersion.prjRefWznmMProject = " + to_string(prePrj) + "";
	};

	if (preBvr != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMVersion.bvrRefWznmMVersion = " + to_string(preBvr) + "";
	};

	if (preLoc != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMVersion.refWznmMLocale = " + to_string(preLoc) + "";
	};

	if (preSte != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMVersion.ixVState = " + to_string(preSte) + "";
	};
};

void QryWznmVerList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmVerList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblWznmMVersion.ixVState ASC";
	else if (preIxOrd == VecVOrd::LOC) sqlstr += " ORDER BY TblWznmMVersion.refWznmMLocale ASC";
	else if (preIxOrd == VecVOrd::BVR) sqlstr += " ORDER BY TblWznmMVersion.bvrRefWznmMVersion ASC";
	else if (preIxOrd == VecVOrd::PRJ) sqlstr += " ORDER BY TblWznmMVersion.prjRefWznmMProject ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWznmMVersion.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWznmMVersion.grp ASC";
};

void QryWznmVerList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQVerList* rec = NULL;

	dbswznm->tblwznmqverlist->loadRstByJref(jref, false, rst);
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
			rec->stubPrjRefWznmMProject = StubWznm::getStubPrjStd(dbswznm, rec->prjRefWznmMProject, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubBvrRefWznmMVersion = StubWznm::getStubVerNo(dbswznm, rec->bvrRefWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMLocale = StubWznm::getStubLocStd(dbswznm, rec->refWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecWznmVMVersionState::getSref(rec->ixVState);
			rec->titIxVState = VecWznmVMVersionState::getTitle(rec->ixVState, ixWznmVLocale);
			rec->srefsIxWDbmstype = VecWznmWMVersionDbmstype::getSrefs(rec->ixWDbmstype);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmVerList", "fetch");
	};

	refreshJnum();
};

uint QryWznmVerList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQVerList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmVerList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQVerList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQVerList* QryWznmVerList::getRecByJnum(
			const uint jnum
		) {
	WznmQVerList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmVerList::handleRequest(
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

bool QryWznmVerList::handleRerun(
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

bool QryWznmVerList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQVerList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tprjRefWznmMProject";
	cout << "\tstubPrjRefWznmMProject";
	cout << "\tMajor";
	cout << "\tMinor";
	cout << "\tSub";
	cout << "\tbvrRefWznmMVersion";
	cout << "\tstubBvrRefWznmMVersion";
	cout << "\trefWznmMLocale";
	cout << "\tstubRefWznmMLocale";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixWDbmstype";
	cout << "\tsrefsIxWDbmstype";
	cout << "\ttitsIxWDbmstype";
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
		cout << "\t" << rec->prjRefWznmMProject;
		cout << "\t" << rec->stubPrjRefWznmMProject;
		cout << "\t" << rec->Major;
		cout << "\t" << rec->Minor;
		cout << "\t" << rec->Sub;
		cout << "\t" << rec->bvrRefWznmMVersion;
		cout << "\t" << rec->stubBvrRefWznmMVersion;
		cout << "\t" << rec->refWznmMLocale;
		cout << "\t" << rec->stubRefWznmMLocale;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixWDbmstype;
		cout << "\t" << rec->srefsIxWDbmstype;
		cout << "\t" << rec->titsIxWDbmstype;
		cout << endl;
	};
	return retval;
};

void QryWznmVerList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMVERMOD) {
		call->abort = handleCallWznmVerMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVERUPD_REFEQ) {
		call->abort = handleCallWznmVerUpd_refEq(dbswznm, call->jref);
	};
};

bool QryWznmVerList::handleCallWznmVerMod(
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

bool QryWznmVerList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmVerList::handleCallWznmVerUpd_refEq(
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

