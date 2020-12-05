/**
	* \file QryWznmBlkAItem.cpp
	* job handler for job QryWznmBlkAItem (implementation)
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

#include "QryWznmBlkAItem.h"

#include "QryWznmBlkAItem_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmBlkAItem
 ******************************************************************************/

QryWznmBlkAItem::QryWznmBlkAItem(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMBLKAITEM, jrefSup, ixWznmVLocale)
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

QryWznmBlkAItem::~QryWznmBlkAItem() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmBlkAItem::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmBlkAItem::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefBlk = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFBLK, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMBLKAITMMOD_BLKEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqblkaitem->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAMBlockItem.ref)";
	sqlstr += " FROM TblWznmAMBlockItem";
	sqlstr += " WHERE TblWznmAMBlockItem.blkRefWznmMBlock = " + to_string(preRefBlk) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQBlkAItem(jref, jnum, ref, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAMBlockItem.ref, TblWznmAMBlockItem.blkNum, TblWznmAMBlockItem.ixVBasetype, TblWznmAMBlockItem.sref, TblWznmAMBlockItem.ixWznmVVartype, TblWznmAMBlockItem.refWznmMControl, TblWznmAMBlockItem.refWznmMVector, TblWznmAMBlockItem.refWznmMFeed, TblWznmAMBlockItem.refWznmMTable, TblWznmAMBlockItem.refWznmMBlock, TblWznmAMBlockItem.refJ, TblWznmAMBlockItem.Defval, TblWznmAMBlockItem.refWznmMVectoritem, TblWznmAMBlockItem.Comment";
	sqlstr += " FROM TblWznmAMBlockItem";
	sqlstr += " WHERE TblWznmAMBlockItem.blkRefWznmMBlock = " + to_string(preRefBlk) + "";
	sqlstr += " ORDER BY blkNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQBlkAItem SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addRefClstn(VecWznmVCall::CALLWZNMBLKAITMMOD_BLKEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefBlk);
};

void QryWznmBlkAItem::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQBlkAItem* rec = NULL;

	dbswznm->tblwznmqblkaitem->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVAMBlockItemBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVAMBlockItemBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->srefIxWznmVVartype = VecWznmVVartype::getSref(rec->ixWznmVVartype);
			rec->titIxWznmVVartype = VecWznmVVartype::getTitle(rec->ixWznmVVartype);
			rec->stubRefWznmMControl = StubWznm::getStubConStd(dbswznm, rec->refWznmMControl, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMVector = StubWznm::getStubVecStd(dbswznm, rec->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMFeed = StubWznm::getStubFedStd(dbswznm, rec->refWznmMFeed, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rec->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMBlock = StubWznm::getStubBlkStd(dbswznm, rec->refWznmMBlock, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWznmMVectoritem = StubWznm::getStubVitStd(dbswznm, rec->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmBlkAItem", "fetch");
	};

	refreshJnum();
};

uint QryWznmBlkAItem::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQBlkAItem* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmBlkAItem::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQBlkAItem* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQBlkAItem* QryWznmBlkAItem::getRecByJnum(
			const uint jnum
		) {
	WznmQBlkAItem* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmBlkAItem::handleRequest(
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

bool QryWznmBlkAItem::handleRerun(
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

bool QryWznmBlkAItem::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQBlkAItem* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tblkNum";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\tsref";
	cout << "\tixWznmVVartype";
	cout << "\tsrefIxWznmVVartype";
	cout << "\ttitIxWznmVVartype";
	cout << "\trefWznmMControl";
	cout << "\tstubRefWznmMControl";
	cout << "\trefWznmMVector";
	cout << "\tstubRefWznmMVector";
	cout << "\trefWznmMFeed";
	cout << "\tstubRefWznmMFeed";
	cout << "\trefWznmMTable";
	cout << "\tstubRefWznmMTable";
	cout << "\trefWznmMBlock";
	cout << "\tstubRefWznmMBlock";
	cout << "\trefJ";
	cout << "\tDefval";
	cout << "\trefWznmMVectoritem";
	cout << "\tstubRefWznmMVectoritem";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->blkNum;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixWznmVVartype;
		cout << "\t" << rec->srefIxWznmVVartype;
		cout << "\t" << rec->titIxWznmVVartype;
		cout << "\t" << rec->refWznmMControl;
		cout << "\t" << rec->stubRefWznmMControl;
		cout << "\t" << rec->refWznmMVector;
		cout << "\t" << rec->stubRefWznmMVector;
		cout << "\t" << rec->refWznmMFeed;
		cout << "\t" << rec->stubRefWznmMFeed;
		cout << "\t" << rec->refWznmMTable;
		cout << "\t" << rec->stubRefWznmMTable;
		cout << "\t" << rec->refWznmMBlock;
		cout << "\t" << rec->stubRefWznmMBlock;
		cout << "\t" << rec->refJ;
		cout << "\t" << rec->Defval;
		cout << "\t" << rec->refWznmMVectoritem;
		cout << "\t" << rec->stubRefWznmMVectoritem;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWznmBlkAItem::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMBLKAITMMOD_BLKEQ) {
		call->abort = handleCallWznmBlkAitmMod_blkEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmBlkAItem::handleCallWznmBlkAitmMod_blkEq(
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

bool QryWznmBlkAItem::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};



