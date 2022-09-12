/**
	* \file QryWznmPnlList.cpp
	* job handler for job QryWznmPnlList (implementation)
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

#include "QryWznmPnlList.h"

#include "QryWznmPnlList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmPnlList
 ******************************************************************************/

QryWznmPnlList::QryWznmPnlList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMPNLLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMPNLMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmPnlList::~QryWznmPnlList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmPnlList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMPNLUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMPNLUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmPnlList::rerun(
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
	ubigint preRefCar = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref);
	ubigint preRefVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMPNLLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMPNLLIST_TYP, jref);
	ubigint preCar = xchg->getRefPreset(VecWznmVPreset::PREWZNMPNLLIST_CAR, jref);
	uint preRet = xchg->getIxPreset(VecWznmVPreset::PREWZNMPNLLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWznmVPreset::PREWZNMPNLLIST_REU, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqpnllist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFCAR) {
		sqlstr = "SELECT COUNT(TblWznmMPanel.ref)";
		sqlstr += " FROM TblWznmMPanel";
		sqlstr += " WHERE TblWznmMPanel.carRefWznmMCard = " + to_string(preRefCar) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preCar, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMPanel.ref)";
		sqlstr += " FROM TblWznmMPanel, TblWznmMModule, TblWznmMCard";
		sqlstr += " WHERE TblWznmMPanel.carRefWznmMCard = TblWznmMCard.ref";
		sqlstr += " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preCar, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMPanel.ref)";
		sqlstr += " FROM TblWznmMPanel";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preCar, preRet, preReu, true);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFCAR) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMPanel";
		sqlstr += " WHERE TblWznmMPanel.carRefWznmMCard = " + to_string(preRefCar) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preCar, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMPanel, TblWznmMModule, TblWznmMCard";
		sqlstr += " WHERE TblWznmMPanel.carRefWznmMCard = TblWznmMCard.ref";
		sqlstr += " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preCar, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMPanel";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preCar, preRet, preReu, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQPnlList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmPnlList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQPnlList(jref, jnum, ref, sref, ixVBasetype, carRefWznmMCard, refIxVTbl, refUref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMPanel.ref, TblWznmMPanel.sref, TblWznmMPanel.ixVBasetype, TblWznmMPanel.carRefWznmMCard, TblWznmMPanel.refIxVTbl, TblWznmMPanel.refUref";
};

void QryWznmPnlList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preCar
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMPanel.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMPanel.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preCar != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMPanel.carRefWznmMCard = " + to_string(preCar) + "";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMPanel.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMPanel.refUref = " + to_string(preReu) + "";
	};
};

void QryWznmPnlList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmPnlList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWznmMPanel.refUref ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWznmMPanel.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::CAR) sqlstr += " ORDER BY TblWznmMPanel.carRefWznmMCard ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMPanel.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMPanel.sref ASC";
};

void QryWznmPnlList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQPnlList* rec = NULL;

	dbswznm->tblwznmqpnllist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMPanelBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMPanelBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubCarRefWznmMCard = StubWznm::getStubCarStd(dbswznm, rec->carRefWznmMCard, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefRefIxVTbl = VecWznmVMPanelRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWznmVMPanelRefTbl::getTitle(rec->refIxVTbl, ixWznmVLocale);
			if (rec->refIxVTbl == VecWznmVMPanelRefTbl::MDL) {
				rec->stubRefUref = StubWznm::getStubMdlStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMPanelRefTbl::TBL) {
				rec->stubRefUref = StubWznm::getStubTblStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMPanelRefTbl::REL) {
				rec->stubRefUref = StubWznm::getStubRelStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMPanelRefTbl::VEC) {
				rec->stubRefUref = StubWznm::getStubVecStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmPnlList", "fetch");
	};

	refreshJnum();
};

uint QryWznmPnlList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQPnlList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmPnlList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQPnlList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQPnlList* QryWznmPnlList::getRecByJnum(
			const uint jnum
		) {
	WznmQPnlList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmPnlList::handleRequest(
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

bool QryWznmPnlList::handleRerun(
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

bool QryWznmPnlList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQPnlList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\tcarRefWznmMCard";
	cout << "\tstubCarRefWznmMCard";
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
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->carRefWznmMCard;
		cout << "\t" << rec->stubCarRefWznmMCard;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << endl;
	};
	return retval;
};

void QryWznmPnlList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMPNLUPD_REFEQ) {
		call->abort = handleCallWznmPnlUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPNLMOD) {
		call->abort = handleCallWznmPnlMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmPnlList::handleCallWznmPnlUpd_refEq(
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

bool QryWznmPnlList::handleCallWznmPnlMod(
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

bool QryWznmPnlList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};
