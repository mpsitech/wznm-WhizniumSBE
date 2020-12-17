/**
	* \file QryWznmSbsATitle.cpp
	* job handler for job QryWznmSbsATitle (implementation)
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

#include "QryWznmSbsATitle.h"

#include "QryWznmSbsATitle_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmSbsATitle
 ******************************************************************************/

QryWznmSbsATitle::QryWznmSbsATitle(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMSBSATITLE, jrefSup, ixWznmVLocale)
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

QryWznmSbsATitle::~QryWznmSbsATitle() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmSbsATitle::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmSbsATitle::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefSbs = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSBS, jref);
	uint preX1 = xchg->getIxPreset(VecWznmVPreset::PREWZNMSBSATITLE_X1, jref);
	ubigint preX2 = xchg->getRefPreset(VecWznmVPreset::PREWZNMSBSATITLE_X2, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMSBSATITMOD_SBSEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqsbsatitle->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMSubsetTitle.ref)";
	sqlstr += " FROM TblWznmAMSubsetTitle";
	sqlstr += " WHERE TblWznmAMSubsetTitle.refWznmMSubset = " + to_string(preRefSbs) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQSbsATitle(jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMSubsetTitle.ref, TblWznmAMSubsetTitle.x1IxVType, TblWznmAMSubsetTitle.x2RefWznmMLocale, TblWznmAMSubsetTitle.ixWznmVGender, TblWznmAMSubsetTitle.Title";
	sqlstr += " FROM TblWznmAMSubsetTitle";
	sqlstr += " WHERE TblWznmAMSubsetTitle.refWznmMSubset = " + to_string(preRefSbs) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQSbsATitle SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMSBSATITMOD_SBSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefSbs);
};

void QryWznmSbsATitle::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const ubigint preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMSubsetTitle.x1IxVType = " + to_string(preX1) + "";
	};

	if (preX2 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmAMSubsetTitle.x2RefWznmMLocale = " + to_string(preX2) + "";
	};
};

void QryWznmSbsATitle::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmSbsATitle::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQSbsATitle* rec = NULL;

	dbswznm->tblwznmqsbsatitle->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxVType = VecWznmVAMSubsetTitleType::getSref(rec->x1IxVType);
			rec->titX1IxVType = VecWznmVAMSubsetTitleType::getTitle(rec->x1IxVType, ixWznmVLocale);
			rec->stubX2RefWznmMLocale = StubWznm::getStubLocStd(dbswznm, rec->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxWznmVGender = VecWznmVGender::getSref(rec->ixWznmVGender);
			rec->titIxWznmVGender = VecWznmVGender::getTitle(rec->ixWznmVGender);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmSbsATitle", "fetch");
	};

	refreshJnum();
};

uint QryWznmSbsATitle::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQSbsATitle* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmSbsATitle::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQSbsATitle* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQSbsATitle* QryWznmSbsATitle::getRecByJnum(
			const uint jnum
		) {
	WznmQSbsATitle* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmSbsATitle::handleRequest(
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

bool QryWznmSbsATitle::handleRerun(
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

bool QryWznmSbsATitle::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQSbsATitle* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxVType";
	cout << "\tsrefX1IxVType";
	cout << "\ttitX1IxVType";
	cout << "\tx2RefWznmMLocale";
	cout << "\tstubX2RefWznmMLocale";
	cout << "\tixWznmVGender";
	cout << "\tsrefIxWznmVGender";
	cout << "\ttitIxWznmVGender";
	cout << "\tTitle";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxVType;
		cout << "\t" << rec->srefX1IxVType;
		cout << "\t" << rec->titX1IxVType;
		cout << "\t" << rec->x2RefWznmMLocale;
		cout << "\t" << rec->stubX2RefWznmMLocale;
		cout << "\t" << rec->ixWznmVGender;
		cout << "\t" << rec->srefIxWznmVGender;
		cout << "\t" << rec->titIxWznmVGender;
		cout << "\t" << rec->Title;
		cout << endl;
	};
	return retval;
};

void QryWznmSbsATitle::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSBSATITMOD_SBSEQ) {
		call->abort = handleCallWznmSbsAtitMod_sbsEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmSbsATitle::handleCallWznmSbsAtitMod_sbsEq(
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

bool QryWznmSbsATitle::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
