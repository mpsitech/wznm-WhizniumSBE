/**
	* \file QryWznmJobSupMNJob.cpp
	* job handler for job QryWznmJobSupMNJob (implementation)
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

#include "QryWznmJobSupMNJob.h"

#include "QryWznmJobSupMNJob_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmJobSupMNJob
 ******************************************************************************/

QryWznmJobSupMNJob::QryWznmJobSupMNJob(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMJOBSUPMNJOB, jrefSup, ixWznmVLocale)
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

QryWznmJobSupMNJob::~QryWznmJobSupMNJob() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmJobSupMNJob::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmJobSupMNJob::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefJob = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMJOBRJOBMOD_SUPEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqjobsupmnjob->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmRMJobMJob.ref)";
	sqlstr += " FROM TblWznmRMJobMJob, TblWznmMJob";
	sqlstr += " WHERE TblWznmRMJobMJob.subRefWznmMJob = TblWznmMJob.ref";
	sqlstr += " AND TblWznmRMJobMJob.supRefWznmMJob = " + to_string(preRefJob) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQJobSupMNJob(jref, jnum, mref, ref, Short, Multi, ixVConstract)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMJob.ref, TblWznmRMJobMJob.ref, TblWznmRMJobMJob.Short, TblWznmRMJobMJob.Multi, TblWznmRMJobMJob.ixVConstract";
	sqlstr += " FROM TblWznmRMJobMJob, TblWznmMJob";
	sqlstr += " WHERE TblWznmRMJobMJob.subRefWznmMJob = TblWznmMJob.ref";
	sqlstr += " AND TblWznmRMJobMJob.supRefWznmMJob = " + to_string(preRefJob) + "";
	sqlstr += " ORDER BY TblWznmMJob.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQJobSupMNJob SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMJOBRJOBMOD_SUPEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefJob);
};

void QryWznmJobSupMNJob::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQJobSupMNJob* rec = NULL;

	dbswznm->tblwznmqjobsupmnjob->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWznm::getStubJobStd(dbswznm, rec->mref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			if (rec->Multi) rec->yesnoMulti = VecWznmVTag::getTitle(VecWznmVTag::YES, ixWznmVLocale); else rec->yesnoMulti = VecWznmVTag::getTitle(VecWznmVTag::NO, ixWznmVLocale);
			rec->srefIxVConstract = VecWznmVRMJobMJobConstract::getSref(rec->ixVConstract);
			rec->titIxVConstract = VecWznmVRMJobMJobConstract::getTitle(rec->ixVConstract, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmJobSupMNJob", "fetch");
	};

	refreshJnum();
};

uint QryWznmJobSupMNJob::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQJobSupMNJob* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmJobSupMNJob::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQJobSupMNJob* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQJobSupMNJob* QryWznmJobSupMNJob::getRecByJnum(
			const uint jnum
		) {
	WznmQJobSupMNJob* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmJobSupMNJob::handleRequest(
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

bool QryWznmJobSupMNJob::handleRerun(
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

bool QryWznmJobSupMNJob::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQJobSupMNJob* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tShort";
	cout << "\tMulti";
	cout << "\tyesnoMulti";
	cout << "\tixVConstract";
	cout << "\tsrefIxVConstract";
	cout << "\ttitIxVConstract";
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
		cout << "\t" << rec->Short;
		cout << "\t" << rec->Multi;
		cout << "\t" << rec->yesnoMulti;
		cout << "\t" << rec->ixVConstract;
		cout << "\t" << rec->srefIxVConstract;
		cout << "\t" << rec->titIxVConstract;
		cout << endl;
	};
	return retval;
};

void QryWznmJobSupMNJob::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMJOBRJOBMOD_SUPEQ) {
		call->abort = handleCallWznmJobRjobMod_supEq(dbswznm, call->jref);
	};
};

bool QryWznmJobSupMNJob::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

bool QryWznmJobSupMNJob::handleCallWznmJobRjobMod_supEq(
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
