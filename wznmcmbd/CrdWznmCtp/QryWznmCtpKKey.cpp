/**
	* \file QryWznmCtpKKey.cpp
	* job handler for job QryWznmCtpKKey (implementation)
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

#include "QryWznmCtpKKey.h"

#include "QryWznmCtpKKey_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmCtpKKey
 ******************************************************************************/

QryWznmCtpKKey::QryWznmCtpKKey(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMCTPKKEY, jrefSup, ixWznmVLocale)
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

QryWznmCtpKKey::~QryWznmCtpKKey() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmCtpKKey::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWznmCtpKKey::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCtp = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCTP, jref);

	xchg->removeClstns(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSMTBURFEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqctpkkey->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWznmAVKeylistKey.ref)";
	sqlstr += " FROM TblWznmAVKeylistKey";
	sqlstr += " WHERE klsIxWznmVKeylist = " + to_string(VecWznmVKeylist::KLSTWZNMKRMCAPABILITYUNIVERSALKEY);
	sqlstr += " AND x1IxWznmVMaintable = " + to_string(VecWznmVMaintable::TBLWZNMMCAPABILITY);
	sqlstr += " AND x1Uref = " + to_string(preRefCtp) + "";
	dbswznm->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWznmQCtpKKey(jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmAVKeylistKey.ref, TblWznmAVKeylistKey.klsNum, TblWznmAVKeylistKey.Fixed, TblWznmAVKeylistKey.sref, TblWznmAVKeylistKey.Avail, TblWznmAVKeylistKey.Implied, TblWznmAVKeylistKey.refJ, TblWznmAVKeylistKey.Title, TblWznmAVKeylistKey.Comment";
	sqlstr += " FROM TblWznmAVKeylistKey";
	sqlstr += " WHERE klsIxWznmVKeylist = " + to_string(VecWznmVKeylist::KLSTWZNMKRMCAPABILITYUNIVERSALKEY);
	sqlstr += " AND x1IxWznmVMaintable = " + to_string(VecWznmVMaintable::TBLWZNMMCAPABILITY);
	sqlstr += " AND x1Uref = " + to_string(preRefCtp) + "";
	sqlstr += " ORDER BY TblWznmAVKeylistKey.klsNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswznm->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWznmQCtpKKey SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

	xchg->addIxRefSrefClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVMaintable::TBLWZNMMCAPABILITY, preRefCtp, VecWznmVKeylist::getSref(VecWznmVKeylist::KLSTWZNMKRMCAPABILITYUNIVERSALKEY));
};

void QryWznmCtpKKey::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQCtpKKey* rec = NULL;

	dbswznm->tblwznmqctpkkey->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			if (rec->Fixed) rec->yesnoFixed = VecWznmVTag::getTitle(VecWznmVTag::YES, ixWznmVLocale); else rec->yesnoFixed = VecWznmVTag::getTitle(VecWznmVTag::NO, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmCtpKKey", "fetch");
	};

	refreshJnum();
};

uint QryWznmCtpKKey::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQCtpKKey* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmCtpKKey::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQCtpKKey* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQCtpKKey* QryWznmCtpKKey::getRecByJnum(
			const uint jnum
		) {
	WznmQCtpKKey* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmCtpKKey::handleRequest(
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

bool QryWznmCtpKKey::handleRerun(
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

bool QryWznmCtpKKey::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQCtpKKey* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tklsNum";
	cout << "\tFixed";
	cout << "\tyesnoFixed";
	cout << "\tsref";
	cout << "\tAvail";
	cout << "\tImplied";
	cout << "\trefJ";
	cout << "\tTitle";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->klsNum;
		cout << "\t" << rec->Fixed;
		cout << "\t" << rec->yesnoFixed;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Avail;
		cout << "\t" << rec->Implied;
		cout << "\t" << rec->refJ;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWznmCtpKKey::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsMtbUrfEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmCtpKKey::handleCallWznmKlsAkeyMod_klsMtbUrfEq(
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

bool QryWznmCtpKKey::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
