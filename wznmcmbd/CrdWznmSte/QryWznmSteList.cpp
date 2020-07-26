/**
	* \file QryWznmSteList.cpp
	* job handler for job QryWznmSteList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmSteList.h"

#include "QryWznmSteList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmSteList
 ******************************************************************************/

QryWznmSteList::QryWznmSteList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMSTELIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMSTEMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmSteList::~QryWznmSteList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmSteList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMSTEUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMSTEUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmSteList::rerun(
			DbsWznm* dbswznm
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXORD, jref);
	ubigint preRefApp = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMSTELIST_SRF, jref);
	ubigint preSeq = xchg->getRefPreset(VecWznmVPreset::PREWZNMSTELIST_SEQ, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqstelist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFAPP) {
		sqlstr = "SELECT COUNT(TblWznmMState.ref)";
		sqlstr += " FROM TblWznmMState, TblWznmMSequence";
		sqlstr += " WHERE TblWznmMState.seqRefWznmMSequence = TblWznmMSequence.ref";
		sqlstr += " AND TblWznmMSequence.appRefWznmMApp = " + to_string(preRefApp) + "";
		rerun_filtSQL(sqlstr, preSrf, preSeq, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMState.ref)";
		sqlstr += " FROM TblWznmMState";
		rerun_filtSQL(sqlstr, preSrf, preSeq, true);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i = 0; i < cnts.size(); i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecWznmVPreset::PREWZNMREFAPP) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMState, TblWznmMSequence";
		sqlstr += " WHERE TblWznmMState.seqRefWznmMSequence = TblWznmMSequence.ref";
		sqlstr += " AND TblWznmMSequence.appRefWznmMApp = " + to_string(preRefApp) + "";
		rerun_filtSQL(sqlstr, preSrf, preSeq, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMState";
		rerun_filtSQL(sqlstr, preSrf, preSeq, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQSteList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmSteList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQSteList(jref, jnum, ref, sref, seqRefWznmMSequence, eacIxVAction, lacIxVAction, Custstep)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMState.ref, TblWznmMState.sref, TblWznmMState.seqRefWznmMSequence, TblWznmMState.eacIxVAction, TblWznmMState.lacIxVAction, TblWznmMState.Custstep";
};

void QryWznmSteList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preSeq
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMState.sref = '" + preSrf + "'";
	};

	if (preSeq != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMState.seqRefWznmMSequence = " + to_string(preSeq) + "";
	};
};

void QryWznmSteList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmSteList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SEQ) sqlstr += " ORDER BY TblWznmMState.seqRefWznmMSequence ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMState.sref ASC";
};

void QryWznmSteList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQSteList* rec = NULL;

	dbswznm->tblwznmqstelist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubSeqRefWznmMSequence = StubWznm::getStubSeqStd(dbswznm, rec->seqRefWznmMSequence, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefEacIxVAction = VecWznmVMStateAction::getSref(rec->eacIxVAction);
			rec->titEacIxVAction = VecWznmVMStateAction::getTitle(rec->eacIxVAction, ixWznmVLocale);
			rec->srefLacIxVAction = VecWznmVMStateAction::getSref(rec->lacIxVAction);
			rec->titLacIxVAction = VecWznmVMStateAction::getTitle(rec->lacIxVAction, ixWznmVLocale);
			if (rec->Custstep) rec->yesnoCuststep = VecWznmVTag::getTitle(VecWznmVTag::YES, ixWznmVLocale); else rec->yesnoCuststep = VecWznmVTag::getTitle(VecWznmVTag::NO, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmSteList", "fetch");
	};

	refreshJnum();
};

uint QryWznmSteList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQSteList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmSteList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQSteList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQSteList* QryWznmSteList::getRecByJnum(
			const uint jnum
		) {
	WznmQSteList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmSteList::handleRequest(
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

bool QryWznmSteList::handleRerun(
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

bool QryWznmSteList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQSteList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tseqRefWznmMSequence";
	cout << "\tstubSeqRefWznmMSequence";
	cout << "\teacIxVAction";
	cout << "\tsrefEacIxVAction";
	cout << "\ttitEacIxVAction";
	cout << "\tlacIxVAction";
	cout << "\tsrefLacIxVAction";
	cout << "\ttitLacIxVAction";
	cout << "\tCuststep";
	cout << "\tyesnoCuststep";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->seqRefWznmMSequence;
		cout << "\t" << rec->stubSeqRefWznmMSequence;
		cout << "\t" << rec->eacIxVAction;
		cout << "\t" << rec->srefEacIxVAction;
		cout << "\t" << rec->titEacIxVAction;
		cout << "\t" << rec->lacIxVAction;
		cout << "\t" << rec->srefLacIxVAction;
		cout << "\t" << rec->titLacIxVAction;
		cout << "\t" << rec->Custstep;
		cout << "\t" << rec->yesnoCuststep;
		cout << endl;
	};
	return retval;
};

void QryWznmSteList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMSTEUPD_REFEQ) {
		call->abort = handleCallWznmSteUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTEMOD) {
		call->abort = handleCallWznmSteMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmSteList::handleCallWznmSteUpd_refEq(
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

bool QryWznmSteList::handleCallWznmSteMod(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixWznmVQrystate == VecWznmVQrystate::UTD) || (ixWznmVQrystate == VecWznmVQrystate::SLM)) {
		ixWznmVQrystate = VecWznmVQrystate::MNR;
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);
	};

	return retval;
};

bool QryWznmSteList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

