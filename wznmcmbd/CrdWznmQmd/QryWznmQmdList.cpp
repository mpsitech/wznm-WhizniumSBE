/**
	* \file QryWznmQmdList.cpp
	* job handler for job QryWznmQmdList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmQmdList.h"

#include "QryWznmQmdList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmQmdList
 ******************************************************************************/

QryWznmQmdList::QryWznmQmdList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMQMDLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMQMDMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmQmdList::~QryWznmQmdList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmQmdList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMQMDUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMQMDUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmQmdList::rerun(
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
	ubigint preRefQry = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFQRY, jref);
	ubigint preRefVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMQMDLIST_TYP, jref);
	ubigint preQry = xchg->getRefPreset(VecWznmVPreset::PREWZNMQMDLIST_QRY, jref);
	ubigint prePst = xchg->getRefPreset(VecWznmVPreset::PREWZNMQMDLIST_PST, jref);
	uint preRet = xchg->getIxPreset(VecWznmVPreset::PREWZNMQMDLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWznmVPreset::PREWZNMQMDLIST_REU, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqqmdlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFQRY) {
		sqlstr = "SELECT COUNT(TblWznmMQuerymod.ref)";
		sqlstr += " FROM TblWznmMQuerymod";
		sqlstr += " WHERE TblWznmMQuerymod.qryRefWznmMQuery = " + to_string(preRefQry) + "";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMQuerymod.ref)";
		sqlstr += " FROM TblWznmMQuerymod, TblWznmMQuery";
		sqlstr += " WHERE TblWznmMQuerymod.qryRefWznmMQuery = TblWznmMQuery.ref";
		sqlstr += " AND TblWznmMQuery.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMQuerymod.ref)";
		sqlstr += " FROM TblWznmMQuerymod, TblWznmMTable, TblWznmMTablecol";
		sqlstr += " WHERE TblWznmMQuerymod.refIxVTbl = " + to_string(VecWznmVMQuerymodRefTbl::TCO);
		sqlstr += " AND TblWznmMQuerymod.refUref = TblWznmMTablecol.ref";
		sqlstr += " AND TblWznmMTablecol.tblRefWznmMTable = TblWznmMTable.ref";
		sqlstr += " AND TblWznmMTable.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMQuerymod.ref)";
		sqlstr += " FROM TblWznmMQuerymod, TblWznmMTable";
		sqlstr += " WHERE TblWznmMQuerymod.refIxVTbl = " + to_string(VecWznmVMQuerymodRefTbl::TBL);
		sqlstr += " AND TblWznmMQuerymod.refUref = TblWznmMTable.ref";
		sqlstr += " AND TblWznmMTable.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMQuerymod.ref)";
		sqlstr += " FROM TblWznmMQuerymod";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, true);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFQRY) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuerymod";
		sqlstr += " WHERE TblWznmMQuerymod.qryRefWznmMQuery = " + to_string(preRefQry) + "";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuerymod, TblWznmMQuery";
		sqlstr += " WHERE TblWznmMQuerymod.qryRefWznmMQuery = TblWznmMQuery.ref";
		sqlstr += " AND TblWznmMQuery.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuerymod, TblWznmMTable, TblWznmMTablecol";
		sqlstr += " WHERE TblWznmMQuerymod.refIxVTbl = " + to_string(VecWznmVMQuerymodRefTbl::TCO);
		sqlstr += " AND TblWznmMQuerymod.refUref = TblWznmMTablecol.ref";
		sqlstr += " AND TblWznmMTablecol.tblRefWznmMTable = TblWznmMTable.ref";
		sqlstr += " AND TblWznmMTable.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuerymod, TblWznmMTable";
		sqlstr += " WHERE TblWznmMQuerymod.refIxVTbl = " + to_string(VecWznmVMQuerymodRefTbl::TBL);
		sqlstr += " AND TblWznmMQuerymod.refUref = TblWznmMTable.ref";
		sqlstr += " AND TblWznmMTable.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[2]) + " OFFSET " + to_string(ofss[2]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuerymod";
		rerun_filtSQL(sqlstr, preTyp, preQry, prePst, preRet, preReu, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQQmdList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmQmdList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQQmdList(jref, jnum, ref, ixVBasetype, qryRefWznmMQuery, refWznmMPreset, refIxVTbl, refUref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMQuerymod.ref, TblWznmMQuerymod.ixVBasetype, TblWznmMQuerymod.qryRefWznmMQuery, TblWznmMQuerymod.refWznmMPreset, TblWznmMQuerymod.refIxVTbl, TblWznmMQuerymod.refUref";
};

void QryWznmQmdList::rerun_filtSQL(
			string& sqlstr
			, const uint preTyp
			, const ubigint preQry
			, const ubigint prePst
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerymod.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preQry != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerymod.qryRefWznmMQuery = " + to_string(preQry) + "";
	};

	if (prePst != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerymod.refWznmMPreset = " + to_string(prePst) + "";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerymod.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerymod.refUref = " + to_string(preReu) + "";
	};
};

void QryWznmQmdList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmQmdList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWznmMQuerymod.refUref ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWznmMQuerymod.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::PST) sqlstr += " ORDER BY TblWznmMQuerymod.refWznmMPreset ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMQuerymod.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::QRY) sqlstr += " ORDER BY TblWznmMQuerymod.qryRefWznmMQuery ASC";
};

void QryWznmQmdList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQQmdList* rec = NULL;

	dbswznm->tblwznmqqmdlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMQuerymodBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMQuerymodBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubQryRefWznmMQuery = StubWznm::getStubQryStd(dbswznm, rec->qryRefWznmMQuery, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMPreset = StubWznm::getStubPstStd(dbswznm, rec->refWznmMPreset, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefRefIxVTbl = VecWznmVMQuerymodRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWznmVMQuerymodRefTbl::getTitle(rec->refIxVTbl, ixWznmVLocale);
			if (rec->refIxVTbl == VecWznmVMQuerymodRefTbl::TBL) {
				rec->stubRefUref = StubWznm::getStubTblStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMQuerymodRefTbl::TCO) {
				rec->stubRefUref = StubWznm::getStubTcoStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmQmdList", "fetch");
	};

	refreshJnum();
};

uint QryWznmQmdList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQQmdList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmQmdList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQQmdList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQQmdList* QryWznmQmdList::getRecByJnum(
			const uint jnum
		) {
	WznmQQmdList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmQmdList::handleRequest(
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

bool QryWznmQmdList::handleRerun(
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

bool QryWznmQmdList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQQmdList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\tqryRefWznmMQuery";
	cout << "\tstubQryRefWznmMQuery";
	cout << "\trefWznmMPreset";
	cout << "\tstubRefWznmMPreset";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->qryRefWznmMQuery;
		cout << "\t" << rec->stubQryRefWznmMQuery;
		cout << "\t" << rec->refWznmMPreset;
		cout << "\t" << rec->stubRefWznmMPreset;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << endl;
	};
	return retval;
};

void QryWznmQmdList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMQMDUPD_REFEQ) {
		call->abort = handleCallWznmQmdUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQMDMOD) {
		call->abort = handleCallWznmQmdMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmQmdList::handleCallWznmQmdUpd_refEq(
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

bool QryWznmQmdList::handleCallWznmQmdMod(
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

bool QryWznmQmdList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

