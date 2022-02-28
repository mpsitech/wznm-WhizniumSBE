/**
	* \file QryWznmIelList.cpp
	* job handler for job QryWznmIelList (implementation)
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

#include "QryWznmIelList.h"

#include "QryWznmIelList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmIelList
 ******************************************************************************/

QryWznmIelList::QryWznmIelList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMIELLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMIELMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmIelList::~QryWznmIelList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmIelList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMIELUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMIELUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmIelList::rerun(
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
	ubigint preRefIme = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIME, jref);
	ubigint preRefIex = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIEX, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMIELLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMIELLIST_TYP, jref);
	ubigint preIme = xchg->getRefPreset(VecWznmVPreset::PREWZNMIELLIST_IME, jref);
	ubigint preTco = xchg->getRefPreset(VecWznmVPreset::PREWZNMIELLIST_TCO, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqiellist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFIEX) {
		sqlstr = "SELECT COUNT(TblWznmMImpexpcol.ref)";
		sqlstr += " FROM TblWznmMImpexpcol, TblWznmMImpexp";
		sqlstr += " WHERE TblWznmMImpexpcol.imeRefWznmMImpexp = TblWznmMImpexp.ref";
		sqlstr += " AND TblWznmMImpexp.refWznmMImpexpcplx = " + to_string(preRefIex) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preIme, preTco, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFIME) {
		sqlstr = "SELECT COUNT(TblWznmMImpexpcol.ref)";
		sqlstr += " FROM TblWznmMImpexpcol";
		sqlstr += " WHERE TblWznmMImpexpcol.imeRefWznmMImpexp = " + to_string(preRefIme) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preIme, preTco, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMImpexpcol.ref)";
		sqlstr += " FROM TblWznmMImpexpcol";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preIme, preTco, true);
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
		sqlstr += " FROM TblWznmMImpexpcol, TblWznmMImpexp";
		sqlstr += " WHERE TblWznmMImpexpcol.imeRefWznmMImpexp = TblWznmMImpexp.ref";
		sqlstr += " AND TblWznmMImpexp.refWznmMImpexpcplx = " + to_string(preRefIex) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preIme, preTco, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFIME) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMImpexpcol";
		sqlstr += " WHERE TblWznmMImpexpcol.imeRefWznmMImpexp = " + to_string(preRefIme) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preIme, preTco, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMImpexpcol";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preIme, preTco, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQIelList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmIelList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQIelList(jref, jnum, ref, sref, Short, ixVBasetype, imeRefWznmMImpexp, refWznmMTablecol, ixVConvtype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMImpexpcol.ref, TblWznmMImpexpcol.sref, TblWznmMImpexpcol.Short, TblWznmMImpexpcol.ixVBasetype, TblWznmMImpexpcol.imeRefWznmMImpexp, TblWznmMImpexpcol.refWznmMTablecol, TblWznmMImpexpcol.ixVConvtype";
};

void QryWznmIelList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preIme
			, const ubigint preTco
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMImpexpcol.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMImpexpcol.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preIme != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMImpexpcol.imeRefWznmMImpexp = " + to_string(preIme) + "";
	};

	if (preTco != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMImpexpcol.refWznmMTablecol = " + to_string(preTco) + "";
	};
};

void QryWznmIelList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmIelList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMImpexpcol.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMImpexpcol.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::IME) sqlstr += " ORDER BY TblWznmMImpexpcol.imeRefWznmMImpexp ASC";
	else if (preIxOrd == VecVOrd::TCO) sqlstr += " ORDER BY TblWznmMImpexpcol.refWznmMTablecol ASC";
};

void QryWznmIelList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQIelList* rec = NULL;

	dbswznm->tblwznmqiellist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMImpexpcolBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMImpexpcolBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubImeRefWznmMImpexp = StubWznm::getStubImeStd(dbswznm, rec->imeRefWznmMImpexp, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMTablecol = StubWznm::getStubTcoStd(dbswznm, rec->refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVConvtype = VecWznmVMImpexpcolConvtype::getSref(rec->ixVConvtype);
			rec->titIxVConvtype = VecWznmVMImpexpcolConvtype::getTitle(rec->ixVConvtype, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmIelList", "fetch");
	};

	refreshJnum();
};

uint QryWznmIelList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQIelList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmIelList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQIelList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQIelList* QryWznmIelList::getRecByJnum(
			const uint jnum
		) {
	WznmQIelList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmIelList::handleRequest(
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

bool QryWznmIelList::handleRerun(
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

bool QryWznmIelList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQIelList* rec = NULL;

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
	cout << "\timeRefWznmMImpexp";
	cout << "\tstubImeRefWznmMImpexp";
	cout << "\trefWznmMTablecol";
	cout << "\tstubRefWznmMTablecol";
	cout << "\tixVConvtype";
	cout << "\tsrefIxVConvtype";
	cout << "\ttitIxVConvtype";
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
		cout << "\t" << rec->imeRefWznmMImpexp;
		cout << "\t" << rec->stubImeRefWznmMImpexp;
		cout << "\t" << rec->refWznmMTablecol;
		cout << "\t" << rec->stubRefWznmMTablecol;
		cout << "\t" << rec->ixVConvtype;
		cout << "\t" << rec->srefIxVConvtype;
		cout << "\t" << rec->titIxVConvtype;
		cout << endl;
	};
	return retval;
};

void QryWznmIelList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIELMOD) {
		call->abort = handleCallWznmIelMod(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIELUPD_REFEQ) {
		call->abort = handleCallWznmIelUpd_refEq(dbswznm, call->jref);
	};
};

bool QryWznmIelList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmIelList::handleCallWznmIelMod(
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

bool QryWznmIelList::handleCallWznmIelUpd_refEq(
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
