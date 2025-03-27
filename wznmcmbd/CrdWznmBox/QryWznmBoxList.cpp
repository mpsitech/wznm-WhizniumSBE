/**
	* \file QryWznmBoxList.cpp
	* job handler for job QryWznmBoxList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP file --- KEEP
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmBoxList.h"

#include "QryWznmBoxList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmBoxList
 ******************************************************************************/

QryWznmBoxList::QryWznmBoxList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMBOXLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMBOXMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmBoxList::~QryWznmBoxList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmBoxList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMBOXUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMBOXUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmBoxList::rerun(
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
	ubigint preRefSht = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSHT, jref);
	ubigint preSht = xchg->getRefPreset(VecWznmVPreset::PREWZNMBOXLIST_SHT, jref);
	uint preMtb = xchg->getIxPreset(VecWznmVPreset::PREWZNMBOXLIST_MTB, jref);
	ubigint preUnv = xchg->getRefPreset(VecWznmVPreset::PREWZNMBOXLIST_UNV, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqboxlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFSHT) {
		sqlstr = "SELECT COUNT(TblWznmMBox.ref)";
		sqlstr += " FROM TblWznmMBox";
		sqlstr += " WHERE TblWznmMBox.refWznmMSheet = " + to_string(preRefSht) + "";
		rerun_filtSQL(sqlstr, preSht, preMtb, preUnv, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMBox.ref)";
		sqlstr += " FROM TblWznmMBox";
		rerun_filtSQL(sqlstr, preSht, preMtb, preUnv, true);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFSHT) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBox";
		sqlstr += " WHERE TblWznmMBox.refWznmMSheet = " + to_string(preRefSht) + "";
		rerun_filtSQL(sqlstr, preSht, preMtb, preUnv, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBox";
		rerun_filtSQL(sqlstr, preSht, preMtb, preUnv, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQBoxList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmBoxList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQBoxList(jref, jnum, ref, refWznmMSheet, unvIxWznmVMaintable, unvUref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMBox.ref, TblWznmMBox.refWznmMSheet, TblWznmMBox.unvIxWznmVMaintable, TblWznmMBox.unvUref";
};

void QryWznmBoxList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preSht
			, const uint preMtb
			, const ubigint preUnv
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSht != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMBox.refWznmMSheet = " + to_string(preSht) + "";
	};

	if (preMtb != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMBox.unvIxWznmVMaintable = " + to_string(preMtb) + "";
	};

	if (preUnv != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMBox.unvUref = " + to_string(preUnv) + "";
	};
};

void QryWznmBoxList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmBoxList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::UNV) sqlstr += " ORDER BY TblWznmMBox.unvUref ASC";
	else if (preIxOrd == VecVOrd::MTB) sqlstr += " ORDER BY TblWznmMBox.unvIxWznmVMaintable ASC";
	else if (preIxOrd == VecVOrd::SHT) sqlstr += " ORDER BY TblWznmMBox.refWznmMSheet ASC";
};

void QryWznmBoxList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQBoxList* rec = NULL;

	dbswznm->tblwznmqboxlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWznmMSheet = StubWznm::getStubShtStd(dbswznm, rec->refWznmMSheet, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefUnvIxWznmVMaintable = VecWznmVMaintable::getSref(rec->unvIxWznmVMaintable);
			rec->titUnvIxWznmVMaintable = VecWznmVMaintable::getTitle(rec->unvIxWznmVMaintable, ixWznmVLocale);

			///
			if (rec->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMIMPEXP) rec->stubUnvUref = StubWznm::getStubImeStd(dbswznm, rec->unvUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			else if (rec->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMTABLE) rec->stubUnvUref = StubWznm::getStubTblStd(dbswznm, rec->unvUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			else if (rec->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMVECTOR) rec->stubUnvUref = StubWznm::getStubVecStd(dbswznm, rec->unvUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmBoxList", "fetch");
	};

	refreshJnum();
};

uint QryWznmBoxList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQBoxList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmBoxList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQBoxList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQBoxList* QryWznmBoxList::getRecByJnum(
			const uint jnum
		) {
	WznmQBoxList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmBoxList::handleRequest(
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

bool QryWznmBoxList::handleRerun(
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

bool QryWznmBoxList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQBoxList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefWznmMSheet";
	cout << "\tstubRefWznmMSheet";
	cout << "\tunvIxWznmVMaintable";
	cout << "\tsrefUnvIxWznmVMaintable";
	cout << "\ttitUnvIxWznmVMaintable";
	cout << "\tunvUref";
	cout << "\tstubUnvUref";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refWznmMSheet;
		cout << "\t" << rec->stubRefWznmMSheet;
		cout << "\t" << rec->unvIxWznmVMaintable;
		cout << "\t" << rec->srefUnvIxWznmVMaintable;
		cout << "\t" << rec->titUnvIxWznmVMaintable;
		cout << "\t" << rec->unvUref;
		cout << "\t" << rec->stubUnvUref;
		cout << endl;
	};
	return retval;
};

void QryWznmBoxList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMBOXUPD_REFEQ) {
		call->abort = handleCallWznmBoxUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMBOXMOD) {
		call->abort = handleCallWznmBoxMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmBoxList::handleCallWznmBoxUpd_refEq(
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

bool QryWznmBoxList::handleCallWznmBoxMod(
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

bool QryWznmBoxList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
