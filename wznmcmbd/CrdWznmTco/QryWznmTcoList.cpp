/**
	* \file QryWznmTcoList.cpp
	* job handler for job QryWznmTcoList (implementation)
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

#include "QryWznmTcoList.h"

#include "QryWznmTcoList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmTcoList
 ******************************************************************************/

QryWznmTcoList::QryWznmTcoList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMTCOLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMTCOMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmTcoList::~QryWznmTcoList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmTcoList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMTCOUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMTCOUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmTcoList::rerun(
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
	ubigint preRefTbl = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref);
	ubigint preRefVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMTCOLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMTCOLIST_TYP, jref);
	ubigint preTbl = xchg->getRefPreset(VecWznmVPreset::PREWZNMTCOLIST_TBL, jref);
	uint preFct = xchg->getIxPreset(VecWznmVPreset::PREWZNMTCOLIST_FCT, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqtcolist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFTBL) {
		sqlstr = "SELECT COUNT(TblWznmMTablecol.ref)";
		sqlstr += " FROM TblWznmMTablecol";
		sqlstr += " WHERE TblWznmMTablecol.tblRefWznmMTable = " + to_string(preRefTbl) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preFct, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMTablecol.ref)";
		sqlstr += " FROM TblWznmMTablecol, TblWznmMTable";
		sqlstr += " WHERE TblWznmMTablecol.tblRefWznmMTable = TblWznmMTable.ref";
		sqlstr += " AND TblWznmMTable.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preFct, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMTablecol.ref)";
		sqlstr += " FROM TblWznmMTablecol";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preFct, true);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFTBL) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMTablecol";
		sqlstr += " WHERE TblWznmMTablecol.tblRefWznmMTable = " + to_string(preRefTbl) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preFct, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMTablecol, TblWznmMTable";
		sqlstr += " WHERE TblWznmMTablecol.tblRefWznmMTable = TblWznmMTable.ref";
		sqlstr += " AND TblWznmMTable.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preFct, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMTablecol";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preTbl, preFct, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQTcoList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmTcoList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQTcoList(jref, jnum, ref, sref, Short, ixVBasetype, tblRefWznmMTable, fctIxVTbl, ixVSubtype, ixVAxisfct)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMTablecol.ref, TblWznmMTablecol.sref, TblWznmMTablecol.Short, TblWznmMTablecol.ixVBasetype, TblWznmMTablecol.tblRefWznmMTable, TblWznmMTablecol.fctIxVTbl, TblWznmMTablecol.ixVSubtype, TblWznmMTablecol.ixVAxisfct";
};

void QryWznmTcoList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preTbl
			, const uint preFct
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMTablecol.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMTablecol.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preTbl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMTablecol.tblRefWznmMTable = " + to_string(preTbl) + "";
	};

	if (preFct != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMTablecol.fctIxVTbl = " + to_string(preFct) + "";
	};
};

void QryWznmTcoList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmTcoList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::FCT) sqlstr += " ORDER BY TblWznmMTablecol.fctIxVTbl ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMTablecol.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMTablecol.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::TBL) sqlstr += " ORDER BY TblWznmMTablecol.tblRefWznmMTable ASC";
};

void QryWznmTcoList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQTcoList* rec = NULL;

	dbswznm->tblwznmqtcolist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMTablecolBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMTablecolBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubTblRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->tblRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefFctIxVTbl = VecWznmVMTablecolFctTbl::getSref(rec->fctIxVTbl);
			rec->titFctIxVTbl = VecWznmVMTablecolFctTbl::getTitle(rec->fctIxVTbl, ixWznmVLocale);
			rec->srefIxVSubtype = VecWznmVMTablecolSubtype::getSref(rec->ixVSubtype);
			rec->titIxVSubtype = VecWznmVMTablecolSubtype::getTitle(rec->ixVSubtype, ixWznmVLocale);
			rec->srefIxVAxisfct = VecWznmVMTablecolAxisfct::getSref(rec->ixVAxisfct);
			rec->titIxVAxisfct = VecWznmVMTablecolAxisfct::getTitle(rec->ixVAxisfct, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmTcoList", "fetch");
	};

	refreshJnum();
};

uint QryWznmTcoList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQTcoList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmTcoList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQTcoList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQTcoList* QryWznmTcoList::getRecByJnum(
			const uint jnum
		) {
	WznmQTcoList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmTcoList::handleRequest(
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

bool QryWznmTcoList::handleRerun(
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

bool QryWznmTcoList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQTcoList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tShort";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\ttblRefWznmMTable";
	cout << "\tstubTblRefWznmMTable";
	cout << "\tfctIxVTbl";
	cout << "\tsrefFctIxVTbl";
	cout << "\ttitFctIxVTbl";
	cout << "\tixVSubtype";
	cout << "\tsrefIxVSubtype";
	cout << "\ttitIxVSubtype";
	cout << "\tixVAxisfct";
	cout << "\tsrefIxVAxisfct";
	cout << "\ttitIxVAxisfct";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Short;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->tblRefWznmMTable;
		cout << "\t" << rec->stubTblRefWznmMTable;
		cout << "\t" << rec->fctIxVTbl;
		cout << "\t" << rec->srefFctIxVTbl;
		cout << "\t" << rec->titFctIxVTbl;
		cout << "\t" << rec->ixVSubtype;
		cout << "\t" << rec->srefIxVSubtype;
		cout << "\t" << rec->titIxVSubtype;
		cout << "\t" << rec->ixVAxisfct;
		cout << "\t" << rec->srefIxVAxisfct;
		cout << "\t" << rec->titIxVAxisfct;
		cout << endl;
	};
	return retval;
};

void QryWznmTcoList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMTCOUPD_REFEQ) {
		call->abort = handleCallWznmTcoUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCOMOD) {
		call->abort = handleCallWznmTcoMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmTcoList::handleCallWznmTcoUpd_refEq(
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

bool QryWznmTcoList::handleCallWznmTcoMod(
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

bool QryWznmTcoList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
