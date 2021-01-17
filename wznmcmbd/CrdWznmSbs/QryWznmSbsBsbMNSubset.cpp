/**
	* \file QryWznmSbsBsbMNSubset.cpp
	* job handler for job QryWznmSbsBsbMNSubset (implementation)
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

#include "QryWznmSbsBsbMNSubset.h"

#include "QryWznmSbsBsbMNSubset_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmSbsBsbMNSubset
 ******************************************************************************/

QryWznmSbsBsbMNSubset::QryWznmSbsBsbMNSubset(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMSBSBSBMNSUBSET, jrefSup, ixWznmVLocale)
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

QryWznmSbsBsbMNSubset::~QryWznmSbsBsbMNSubset() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmSbsBsbMNSubset::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmSbsBsbMNSubset::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefSbs = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSBS, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMSBSRSBSMOD_BSBEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqsbsbsbmnsubset->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmRMSubsetMSubset.ref)";
	sqlstr += " FROM TblWznmRMSubsetMSubset, TblWznmMSubset";
	sqlstr += " WHERE TblWznmRMSubsetMSubset.asbRefWznmMSubset = TblWznmMSubset.ref";
	sqlstr += " AND TblWznmRMSubsetMSubset.bsbRefWznmMSubset = " + to_string(preRefSbs) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQSbsBsbMNSubset(jref, jnum, mref, ref, ixVReltype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMSubset.ref, TblWznmRMSubsetMSubset.ref, TblWznmRMSubsetMSubset.ixVReltype";
	sqlstr += " FROM TblWznmRMSubsetMSubset, TblWznmMSubset";
	sqlstr += " WHERE TblWznmRMSubsetMSubset.asbRefWznmMSubset = TblWznmMSubset.ref";
	sqlstr += " AND TblWznmRMSubsetMSubset.bsbRefWznmMSubset = " + to_string(preRefSbs) + "";
	sqlstr += " ORDER BY TblWznmMSubset.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQSbsBsbMNSubset SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMSBSRSBSMOD_BSBEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefSbs);
};

void QryWznmSbsBsbMNSubset::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQSbsBsbMNSubset* rec = NULL;

	dbswznm->tblwznmqsbsbsbmnsubset->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWznm::getStubSbsStd(dbswznm, rec->mref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVReltype = VecWznmVRMSubsetMSubsetReltype::getSref(rec->ixVReltype);
			rec->titIxVReltype = VecWznmVRMSubsetMSubsetReltype::getTitle(rec->ixVReltype, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmSbsBsbMNSubset", "fetch");
	};

	refreshJnum();
};

uint QryWznmSbsBsbMNSubset::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQSbsBsbMNSubset* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmSbsBsbMNSubset::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQSbsBsbMNSubset* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQSbsBsbMNSubset* QryWznmSbsBsbMNSubset::getRecByJnum(
			const uint jnum
		) {
	WznmQSbsBsbMNSubset* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmSbsBsbMNSubset::handleRequest(
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

bool QryWznmSbsBsbMNSubset::handleRerun(
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

bool QryWznmSbsBsbMNSubset::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQSbsBsbMNSubset* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tixVReltype";
	cout << "\tsrefIxVReltype";
	cout << "\ttitIxVReltype";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixVReltype;
		cout << "\t" << rec->srefIxVReltype;
		cout << "\t" << rec->titIxVReltype;
		cout << endl;
	};
	return retval;
};

void QryWznmSbsBsbMNSubset::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSBSRSBSMOD_BSBEQ) {
		call->abort = handleCallWznmSbsRsbsMod_bsbEq(dbswznm, call->jref);
	};
};

bool QryWznmSbsBsbMNSubset::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmSbsBsbMNSubset::handleCallWznmSbsRsbsMod_bsbEq(
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
