/**
	* \file QryWznmQcoList.cpp
	* job handler for job QryWznmQcoList (implementation)
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

#include "QryWznmQcoList.h"

#include "QryWznmQcoList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmQcoList
 ******************************************************************************/

QryWznmQcoList::QryWznmQcoList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMQCOLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMQCOMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmQcoList::~QryWznmQcoList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmQcoList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMQCOUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMQCOUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmQcoList::rerun(
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
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMQCOLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMQCOLIST_TYP, jref);
	ubigint preQry = xchg->getRefPreset(VecWznmVPreset::PREWZNMQCOLIST_QRY, jref);
	ubigint preTco = xchg->getRefPreset(VecWznmVPreset::PREWZNMQCOLIST_TCO, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqqcolist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFQRY) {
		sqlstr = "SELECT COUNT(TblWznmMQuerycol.ref)";
		sqlstr += " FROM TblWznmMQuerycol";
		sqlstr += " WHERE TblWznmMQuerycol.qryRefWznmMQuery = " + to_string(preRefQry) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preQry, preTco, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMQuerycol.ref)";
		sqlstr += " FROM TblWznmMQuerycol, TblWznmMQuery";
		sqlstr += " WHERE TblWznmMQuerycol.qryRefWznmMQuery = TblWznmMQuery.ref";
		sqlstr += " AND TblWznmMQuery.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preQry, preTco, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMQuerycol.ref)";
		sqlstr += " FROM TblWznmMQuerycol";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preQry, preTco, true);
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
		sqlstr += " FROM TblWznmMQuerycol";
		sqlstr += " WHERE TblWznmMQuerycol.qryRefWznmMQuery = " + to_string(preRefQry) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preQry, preTco, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuerycol, TblWznmMQuery";
		sqlstr += " WHERE TblWznmMQuerycol.qryRefWznmMQuery = TblWznmMQuery.ref";
		sqlstr += " AND TblWznmMQuery.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preQry, preTco, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMQuerycol";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preQry, preTco, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQQcoList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmQcoList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQQcoList(jref, jnum, ref, sref, Short, ixVBasetype, qryRefWznmMQuery, refWznmMTablecol)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMQuerycol.ref, TblWznmMQuerycol.sref, TblWznmMQuerycol.Short, TblWznmMQuerycol.ixVBasetype, TblWznmMQuerycol.qryRefWznmMQuery, TblWznmMQuerycol.refWznmMTablecol";
};

void QryWznmQcoList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preQry
			, const ubigint preTco
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerycol.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerycol.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preQry != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerycol.qryRefWznmMQuery = " + to_string(preQry) + "";
	};

	if (preTco != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMQuerycol.refWznmMTablecol = " + to_string(preTco) + "";
	};
};

void QryWznmQcoList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmQcoList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TCO) sqlstr += " ORDER BY TblWznmMQuerycol.refWznmMTablecol ASC";
	else if (preIxOrd == VecVOrd::QRY) sqlstr += " ORDER BY TblWznmMQuerycol.qryRefWznmMQuery ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMQuerycol.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMQuerycol.sref ASC";
};

void QryWznmQcoList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQQcoList* rec = NULL;

	dbswznm->tblwznmqqcolist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMQuerycolBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMQuerycolBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubQryRefWznmMQuery = StubWznm::getStubQryStd(dbswznm, rec->qryRefWznmMQuery, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMTablecol = StubWznm::getStubTcoStd(dbswznm, rec->refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmQcoList", "fetch");
	};

	refreshJnum();
};

uint QryWznmQcoList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQQcoList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmQcoList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQQcoList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQQcoList* QryWznmQcoList::getRecByJnum(
			const uint jnum
		) {
	WznmQQcoList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmQcoList::handleRequest(
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

bool QryWznmQcoList::handleRerun(
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

bool QryWznmQcoList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQQcoList* rec = NULL;

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
	cout << "\tqryRefWznmMQuery";
	cout << "\tstubQryRefWznmMQuery";
	cout << "\trefWznmMTablecol";
	cout << "\tstubRefWznmMTablecol";
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
		cout << "\t" << rec->qryRefWznmMQuery;
		cout << "\t" << rec->stubQryRefWznmMQuery;
		cout << "\t" << rec->refWznmMTablecol;
		cout << "\t" << rec->stubRefWznmMTablecol;
		cout << endl;
	};
	return retval;
};

void QryWznmQcoList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMQCOUPD_REFEQ) {
		call->abort = handleCallWznmQcoUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQCOMOD) {
		call->abort = handleCallWznmQcoMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmQcoList::handleCallWznmQcoUpd_refEq(
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

bool QryWznmQcoList::handleCallWznmQcoMod(
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

bool QryWznmQcoList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
