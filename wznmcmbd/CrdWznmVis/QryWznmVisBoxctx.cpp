/**
	* \file QryWznmVisBoxctx.cpp
	* job handler for job QryWznmVisBoxctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmVisBoxctx.h"

#include "QryWznmVisBoxctx_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmVisBoxctx
 ******************************************************************************/

QryWznmVisBoxctx::QryWznmVisBoxctx(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMVISBOXCTX, jrefSup, ixWznmVLocale)
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

QryWznmVisBoxctx::~QryWznmVisBoxctx() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmVisBoxctx::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmVisBoxctx::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	ubigint preRefVis = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqvisboxctx->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblWznmQVisBoxctx(qwr, jref, jnum, tref, ref, unvIxWznmVMaintable, unvUref, x, y)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblWznmMSheet.ref, TblWznmMBox.ref, TblWznmMBox.unvIxWznmVMaintable, TblWznmMBox.unvUref, TblWznmMBox.x, TblWznmMBox.y";
	sqlstr += " FROM TblWznmMSheet, TblWznmMBox";
	sqlstr += " WHERE TblWznmMBox.refWznmMSheet = TblWznmMSheet.ref";
	sqlstr += " AND TblWznmMSheet.visRefWznmMVisual = " + to_string(preRefVis) + "";
	sqlstr += " ORDER BY TblWznmMSheet.visNum ASC, TblWznmMBox.ref ASC";
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQVisBoxctx SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmVisBoxctx::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQVisBoxctx* rec = NULL;

	dbswznm->tblwznmqvisboxctx->loadRstByJref(jref, false, rst);

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = i+1;
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmVisBoxctx", "fetch");
	};

	refreshJnum();
};

uint QryWznmVisBoxctx::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQVisBoxctx* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmVisBoxctx::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQVisBoxctx* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQVisBoxctx* QryWznmVisBoxctx::getRecByJnum(
			const uint jnum
		) {
	WznmQVisBoxctx* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmVisBoxctx::handleRequest(
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

bool QryWznmVisBoxctx::handleRerun(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	rerun(dbswznm);
	return retval;
};

bool QryWznmVisBoxctx::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQVisBoxctx* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\ttref";
	cout << "\tref";
	cout << "\tunvIxWznmVMaintable";
	cout << "\tunvUref";
	cout << "\tstubUnvUref";
	cout << "\tx";
	cout << "\ty";
	cout << "\tjnumsSub";
	cout << "\tjnumsLink";
	cout << "\tw";
	cout << "\th";
	cout << "\tContent1";
	cout << "\tContent2";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->qwr;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->tref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->unvIxWznmVMaintable;
		cout << "\t" << rec->unvUref;
		cout << "\t" << rec->stubUnvUref;
		cout << "\t" << rec->x;
		cout << "\t" << rec->y;
		cout << "\t" << rec->jnumsSub;
		cout << "\t" << rec->jnumsLink;
		cout << "\t" << rec->w;
		cout << "\t" << rec->h;
		cout << "\t" << rec->Content1;
		cout << "\t" << rec->Content2;
		cout << endl;
	};
	return retval;
};

void QryWznmVisBoxctx::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmVisBoxctx::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
