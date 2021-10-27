/**
	* \file QryWznmCarList.cpp
	* job handler for job QryWznmCarList (implementation)
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

#include "QryWznmCarList.h"

#include "QryWznmCarList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmCarList
 ******************************************************************************/

QryWznmCarList::QryWznmCarList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMCARLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMCARMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmCarList::~QryWznmCarList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmCarList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMCARUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMCARUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmCarList::rerun(
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
	ubigint preRefVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMCARLIST_SRF, jref);
	ubigint preMdl = xchg->getRefPreset(VecWznmVPreset::PREWZNMCARLIST_MDL, jref);
	uint preRet = xchg->getIxPreset(VecWznmVPreset::PREWZNMCARLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWznmVPreset::PREWZNMCARLIST_REU, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqcarlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMCard.ref)";
		sqlstr += " FROM TblWznmMCard, TblWznmMModule";
		sqlstr += " WHERE TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMCard.ref)";
		sqlstr += " FROM TblWznmMCard";
		rerun_filtSQL(sqlstr, preSrf, preMdl, preRet, preReu, true);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMCard, TblWznmMModule";
		sqlstr += " WHERE TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMCard";
		rerun_filtSQL(sqlstr, preSrf, preMdl, preRet, preReu, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQCarList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmCarList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQCarList(jref, jnum, ref, sref, Title, mdlRefWznmMModule, refIxVTbl, refUref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMCard.ref, TblWznmMCard.sref, TblWznmMCard.Title, TblWznmMCard.mdlRefWznmMModule, TblWznmMCard.refIxVTbl, TblWznmMCard.refUref";
};

void QryWznmCarList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preMdl
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMCard.sref = '" + preSrf + "'";
	};

	if (preMdl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMCard.mdlRefWznmMModule = " + to_string(preMdl) + "";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMCard.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMCard.refUref = " + to_string(preReu) + "";
	};
};

void QryWznmCarList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmCarList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWznmMCard.refUref ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWznmMCard.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::MDL) sqlstr += " ORDER BY TblWznmMCard.mdlRefWznmMModule ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMCard.sref ASC";
};

void QryWznmCarList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQCarList* rec = NULL;

	dbswznm->tblwznmqcarlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMdlRefWznmMModule = StubWznm::getStubMdlStd(dbswznm, rec->mdlRefWznmMModule, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefRefIxVTbl = VecWznmVMCardRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWznmVMCardRefTbl::getTitle(rec->refIxVTbl, ixWznmVLocale);
			rec->stubRefUref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmCarList", "fetch");
	};

	refreshJnum();
};

uint QryWznmCarList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQCarList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmCarList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQCarList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQCarList* QryWznmCarList::getRecByJnum(
			const uint jnum
		) {
	WznmQCarList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmCarList::handleRequest(
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

bool QryWznmCarList::handleRerun(
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

bool QryWznmCarList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQCarList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tmdlRefWznmMModule";
	cout << "\tstubMdlRefWznmMModule";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->mdlRefWznmMModule;
		cout << "\t" << rec->stubMdlRefWznmMModule;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << endl;
	};
	return retval;
};

void QryWznmCarList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMCARMOD) {
		call->abort = handleCallWznmCarMod(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCARUPD_REFEQ) {
		call->abort = handleCallWznmCarUpd_refEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmCarList::handleCallWznmCarMod(
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

bool QryWznmCarList::handleCallWznmCarUpd_refEq(
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

bool QryWznmCarList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
