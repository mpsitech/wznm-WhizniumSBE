/**
	* \file QryWznmVisLinkctx.cpp
	* job handler for job QryWznmVisLinkctx (implementation)
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

#include "QryWznmVisLinkctx.h"

#include "QryWznmVisLinkctx_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmVisLinkctx
 ******************************************************************************/

QryWznmVisLinkctx::QryWznmVisLinkctx(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMVISLINKCTX, jrefSup, ixWznmVLocale)
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

QryWznmVisLinkctx::~QryWznmVisLinkctx() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmVisLinkctx::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmVisLinkctx::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	ubigint preRefVis = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqvislinkctx->removeRstByJref(jref);

	sqlstr = "INSERT INTO TblWznmQVisLinkctx(qwr, jref, jnum, tref, ref, orgRefWznmMBox, dstRefWznmMBox, orgClk, dstClk, Weight)";
	sqlstr += " SELECT 1, " + to_string(jref) + ", 0, TblWznmMSheet.ref, TblWznmRMBoxMBox.ref, TblWznmRMBoxMBox.orgRefWznmMBox, TblWznmRMBoxMBox.dstRefWznmMBox, TblWznmRMBoxMBox.orgClk, TblWznmRMBoxMBox.dstClk, TblWznmRMBoxMBox.Weight";
	sqlstr += " FROM TblWznmMSheet, TblWznmRMBoxMBox, TblWznmMBox";
	sqlstr += " WHERE TblWznmRMBoxMBox.orgRefWznmMBox = TblWznmMBox.ref";
	sqlstr += " AND TblWznmMBox.refWznmMSheet = TblWznmMSheet.ref";
	sqlstr += " AND TblWznmMSheet.visRefWznmMVisual = " + to_string(preRefVis) + "";
	sqlstr += " ORDER BY TblWznmMSheet.visNum ASC, TblWznmMBox.ref ASC, TblWznmRMBoxMBox.dstRefWznmMBox ASC";
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQVisLinkctx SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmVisLinkctx::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQVisLinkctx* rec = NULL;

	dbswznm->tblwznmqvislinkctx->loadRstByJref(jref, false, rst);

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
		stmgr->unlockAccess("QryWznmVisLinkctx", "fetch");
	};

	refreshJnum();
};

uint QryWznmVisLinkctx::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQVisLinkctx* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmVisLinkctx::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQVisLinkctx* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQVisLinkctx* QryWznmVisLinkctx::getRecByJnum(
			const uint jnum
		) {
	WznmQVisLinkctx* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmVisLinkctx::handleRequest(
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

bool QryWznmVisLinkctx::handleRerun(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	rerun(dbswznm);
	return retval;
};

bool QryWznmVisLinkctx::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQVisLinkctx* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tqwr";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\ttref";
	cout << "\tref";
	cout << "\torgRefWznmMBox";
	cout << "\tdstRefWznmMBox";
	cout << "\torgClk";
	cout << "\tdstClk";
	cout << "\tWeight";
	cout << "\tjnumBoxOrg";
	cout << "\tjnumBoxDst";
	cout << "\tTitle";
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
		cout << "\t" << rec->orgRefWznmMBox;
		cout << "\t" << rec->dstRefWznmMBox;
		cout << "\t" << rec->orgClk;
		cout << "\t" << rec->dstClk;
		cout << "\t" << rec->Weight;
		cout << "\t" << rec->jnumBoxOrg;
		cout << "\t" << rec->jnumBoxDst;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Content1;
		cout << "\t" << rec->Content2;
		cout << endl;
	};
	return retval;
};

void QryWznmVisLinkctx::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmVisLinkctx::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
