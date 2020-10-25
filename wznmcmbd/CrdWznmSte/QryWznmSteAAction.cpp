/**
	* \file QryWznmSteAAction.cpp
	* job handler for job QryWznmSteAAction (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmSteAAction.h"

#include "QryWznmSteAAction_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmSteAAction
 ******************************************************************************/

QryWznmSteAAction::QryWznmSteAAction(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMSTEAACTION, jrefSup, ixWznmVLocale)
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

QryWznmSteAAction::~QryWznmSteAAction() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmSteAAction::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmSteAAction::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefSte = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSTE, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMSTEAACTMOD_STEEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqsteaaction->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMStateAction.ref)";
	sqlstr += " FROM TblWznmAMStateAction";
	sqlstr += " WHERE TblWznmAMStateAction.steRefWznmMState = " + to_string(preRefSte) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQSteAAction(jref, jnum, ref, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMStateAction.ref, TblWznmAMStateAction.steNum, TblWznmAMStateAction.ixVSection, TblWznmAMStateAction.ixVType, TblWznmAMStateAction.refWznmMRtjob, TblWznmAMStateAction.refWznmMVector, TblWznmAMStateAction.refWznmMVectoritem, TblWznmAMStateAction.snxRefWznmMState, TblWznmAMStateAction.refWznmMSequence, TblWznmAMStateAction.tr1SrefATrig, TblWznmAMStateAction.Ip1, TblWznmAMStateAction.tr2SrefATrig, TblWznmAMStateAction.Ip2, TblWznmAMStateAction.tr3SrefATrig, TblWznmAMStateAction.Ip3, TblWznmAMStateAction.tr4SrefATrig, TblWznmAMStateAction.Ip4";
	sqlstr += " FROM TblWznmAMStateAction";
	sqlstr += " WHERE TblWznmAMStateAction.steRefWznmMState = " + to_string(preRefSte) + "";
	sqlstr += " ORDER BY steNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQSteAAction SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMSTEAACTMOD_STEEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefSte);
};

void QryWznmSteAAction::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQSteAAction* rec = NULL;

	dbswznm->tblwznmqsteaaction->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVSection = VecWznmVAMStateActionSection::getSref(rec->ixVSection);
			rec->titIxVSection = VecWznmVAMStateActionSection::getTitle(rec->ixVSection, ixWznmVLocale);
			rec->srefIxVType = VecWznmVAMStateActionType::getSref(rec->ixVType);
			rec->titIxVType = VecWznmVAMStateActionType::getTitle(rec->ixVType, ixWznmVLocale);
			rec->stubRefWznmMRtjob = StubWznm::getStubRtjStd(dbswznm, rec->refWznmMRtjob, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMVector = StubWznm::getStubVecStd(dbswznm, rec->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMVectoritem = StubWznm::getStubVitStd(dbswznm, rec->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSnxRefWznmMState = StubWznm::getStubSteStd(dbswznm, rec->snxRefWznmMState, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMSequence = StubWznm::getStubSeqStd(dbswznm, rec->refWznmMSequence, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmSteAAction", "fetch");
	};

	refreshJnum();
};

uint QryWznmSteAAction::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQSteAAction* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmSteAAction::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQSteAAction* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQSteAAction* QryWznmSteAAction::getRecByJnum(
			const uint jnum
		) {
	WznmQSteAAction* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmSteAAction::handleRequest(
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

bool QryWznmSteAAction::handleRerun(
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

bool QryWznmSteAAction::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQSteAAction* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsteNum";
	cout << "\tixVSection";
	cout << "\tsrefIxVSection";
	cout << "\ttitIxVSection";
	cout << "\tixVType";
	cout << "\tsrefIxVType";
	cout << "\ttitIxVType";
	cout << "\trefWznmMRtjob";
	cout << "\tstubRefWznmMRtjob";
	cout << "\trefWznmMVector";
	cout << "\tstubRefWznmMVector";
	cout << "\trefWznmMVectoritem";
	cout << "\tstubRefWznmMVectoritem";
	cout << "\tsnxRefWznmMState";
	cout << "\tstubSnxRefWznmMState";
	cout << "\trefWznmMSequence";
	cout << "\tstubRefWznmMSequence";
	cout << "\ttr1SrefATrig";
	cout << "\tIp1";
	cout << "\ttr2SrefATrig";
	cout << "\tIp2";
	cout << "\ttr3SrefATrig";
	cout << "\tIp3";
	cout << "\ttr4SrefATrig";
	cout << "\tIp4";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->steNum;
		cout << "\t" << rec->ixVSection;
		cout << "\t" << rec->srefIxVSection;
		cout << "\t" << rec->titIxVSection;
		cout << "\t" << rec->ixVType;
		cout << "\t" << rec->srefIxVType;
		cout << "\t" << rec->titIxVType;
		cout << "\t" << rec->refWznmMRtjob;
		cout << "\t" << rec->stubRefWznmMRtjob;
		cout << "\t" << rec->refWznmMVector;
		cout << "\t" << rec->stubRefWznmMVector;
		cout << "\t" << rec->refWznmMVectoritem;
		cout << "\t" << rec->stubRefWznmMVectoritem;
		cout << "\t" << rec->snxRefWznmMState;
		cout << "\t" << rec->stubSnxRefWznmMState;
		cout << "\t" << rec->refWznmMSequence;
		cout << "\t" << rec->stubRefWznmMSequence;
		cout << "\t" << rec->tr1SrefATrig;
		cout << "\t" << rec->Ip1;
		cout << "\t" << rec->tr2SrefATrig;
		cout << "\t" << rec->Ip2;
		cout << "\t" << rec->tr3SrefATrig;
		cout << "\t" << rec->Ip3;
		cout << "\t" << rec->tr4SrefATrig;
		cout << "\t" << rec->Ip4;
		cout << endl;
	};
	return retval;
};

void QryWznmSteAAction::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTEAACTMOD_STEEQ) {
		call->abort = handleCallWznmSteAactMod_steEq(dbswznm, call->jref);
	};
};

bool QryWznmSteAAction::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmSteAAction::handleCallWznmSteAactMod_steEq(
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

