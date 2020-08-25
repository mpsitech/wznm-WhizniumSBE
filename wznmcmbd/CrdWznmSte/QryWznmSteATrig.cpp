/**
	* \file QryWznmSteATrig.cpp
	* job handler for job QryWznmSteATrig (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmSteATrig.h"

#include "QryWznmSteATrig_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmSteATrig
 ******************************************************************************/

QryWznmSteATrig::QryWznmSteATrig(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMSTEATRIG, jrefSup, ixWznmVLocale)
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

QryWznmSteATrig::~QryWznmSteATrig() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmSteATrig::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmSteATrig::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefSte = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSTE, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMSTEATRGMOD_STEEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqsteatrig->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMStateTrig.ref)";
	sqlstr += " FROM TblWznmAMStateTrig";
	sqlstr += " WHERE TblWznmAMStateTrig.refWznmMState = " + to_string(preRefSte) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQSteATrig(jref, jnum, ref, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMStateTrig.ref, TblWznmAMStateTrig.sref, TblWznmAMStateTrig.ixVType, TblWznmAMStateTrig.refWznmMEvent, TblWznmAMStateTrig.refWznmMRtjob, TblWznmAMStateTrig.refWznmMVectoritem, TblWznmAMStateTrig.xsref, TblWznmAMStateTrig.refWznmMRtdpch, TblWznmAMStateTrig.srefsMask, TblWznmAMStateTrig.Cond";
	sqlstr += " FROM TblWznmAMStateTrig";
	sqlstr += " WHERE TblWznmAMStateTrig.refWznmMState = " + to_string(preRefSte) + "";
	sqlstr += " ORDER BY sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQSteATrig SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMSTEATRGMOD_STEEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefSte);
};

void QryWznmSteATrig::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQSteATrig* rec = NULL;

	dbswznm->tblwznmqsteatrig->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVType = VecWznmVAMStateTrigType::getSref(rec->ixVType);
			rec->titIxVType = VecWznmVAMStateTrigType::getTitle(rec->ixVType, ixWznmVLocale);
			rec->stubRefWznmMEvent = StubWznm::getStubEvtStd(dbswznm, rec->refWznmMEvent, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMRtjob = StubWznm::getStubRtjStd(dbswznm, rec->refWznmMRtjob, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMVectoritem = StubWznm::getStubVitStd(dbswznm, rec->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMRtdpch = StubWznm::getStubRtdStd(dbswznm, rec->refWznmMRtdpch, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmSteATrig", "fetch");
	};

	refreshJnum();
};

uint QryWznmSteATrig::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQSteATrig* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmSteATrig::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQSteATrig* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQSteATrig* QryWznmSteATrig::getRecByJnum(
			const uint jnum
		) {
	WznmQSteATrig* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmSteATrig::handleRequest(
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

bool QryWznmSteATrig::handleRerun(
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

bool QryWznmSteATrig::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQSteATrig* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tixVType";
	cout << "\tsrefIxVType";
	cout << "\ttitIxVType";
	cout << "\trefWznmMEvent";
	cout << "\tstubRefWznmMEvent";
	cout << "\trefWznmMRtjob";
	cout << "\tstubRefWznmMRtjob";
	cout << "\trefWznmMVectoritem";
	cout << "\tstubRefWznmMVectoritem";
	cout << "\txsref";
	cout << "\trefWznmMRtdpch";
	cout << "\tstubRefWznmMRtdpch";
	cout << "\tsrefsMask";
	cout << "\tCond";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixVType;
		cout << "\t" << rec->srefIxVType;
		cout << "\t" << rec->titIxVType;
		cout << "\t" << rec->refWznmMEvent;
		cout << "\t" << rec->stubRefWznmMEvent;
		cout << "\t" << rec->refWznmMRtjob;
		cout << "\t" << rec->stubRefWznmMRtjob;
		cout << "\t" << rec->refWznmMVectoritem;
		cout << "\t" << rec->stubRefWznmMVectoritem;
		cout << "\t" << rec->xsref;
		cout << "\t" << rec->refWznmMRtdpch;
		cout << "\t" << rec->stubRefWznmMRtdpch;
		cout << "\t" << rec->srefsMask;
		cout << "\t" << rec->Cond;
		cout << endl;
	};
	return retval;
};

void QryWznmSteATrig::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTEATRGMOD_STEEQ) {
		call->abort = handleCallWznmSteAtrgMod_steEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmSteATrig::handleCallWznmSteAtrgMod_steEq(
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

bool QryWznmSteATrig::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

