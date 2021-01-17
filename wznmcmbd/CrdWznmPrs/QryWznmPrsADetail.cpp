/**
	* \file QryWznmPrsADetail.cpp
	* job handler for job QryWznmPrsADetail (implementation)
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

#include "QryWznmPrsADetail.h"

#include "QryWznmPrsADetail_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmPrsADetail
 ******************************************************************************/

QryWznmPrsADetail::QryWznmPrsADetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMPRSADETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmPrsADetail::~QryWznmPrsADetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmPrsADetail::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmPrsADetail::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefPrs = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPRS, jref);
	string preX1 = xchg->getSrefPreset(VecWznmVPreset::PREWZNMPRSADETAIL_X1, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMPRSADETMOD_PRSEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqprsadetail->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMPersonDetail.ref)";
	sqlstr += " FROM TblWznmAMPersonDetail";
	sqlstr += " WHERE TblWznmAMPersonDetail.refWznmMPerson = " + to_string(preRefPrs) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQPrsADetail(jref, jnum, ref, x1SrefKType, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMPersonDetail.ref, TblWznmAMPersonDetail.x1SrefKType, TblWznmAMPersonDetail.Val";
	sqlstr += " FROM TblWznmAMPersonDetail";
	sqlstr += " WHERE TblWznmAMPersonDetail.refWznmMPerson = " + to_string(preRefPrs) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQPrsADetail SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMPRSADETMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefPrs);
};

void QryWznmPrsADetail::rerun_filtSQL(
			string& sqlstr
			, const string& preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMPersonDetail.x1SrefKType = '" + preX1 + "'";
	};
};

void QryWznmPrsADetail::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmPrsADetail::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQPrsADetail* rec = NULL;

	dbswznm->tblwznmqprsadetail->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1SrefKType = dbswznm->getKlstTitleBySref(VecWznmVKeylist::KLSTWZNMKAMPERSONDETAILTYPE, rec->x1SrefKType, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmPrsADetail", "fetch");
	};

	refreshJnum();
};

uint QryWznmPrsADetail::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQPrsADetail* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmPrsADetail::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQPrsADetail* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQPrsADetail* QryWznmPrsADetail::getRecByJnum(
			const uint jnum
		) {
	WznmQPrsADetail* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmPrsADetail::handleRequest(
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

bool QryWznmPrsADetail::handleRerun(
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

bool QryWznmPrsADetail::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQPrsADetail* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1SrefKType";
	cout << "\ttitX1SrefKType";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1SrefKType;
		cout << "\t" << rec->titX1SrefKType;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryWznmPrsADetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPRSADETMOD_PRSEQ) {
		call->abort = handleCallWznmPrsAdetMod_prsEq(dbswznm, call->jref);
	};
};

bool QryWznmPrsADetail::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmPrsADetail::handleCallWznmPrsAdetMod_prsEq(
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
