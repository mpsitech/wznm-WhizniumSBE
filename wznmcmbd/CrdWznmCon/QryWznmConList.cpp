/**
	* \file QryWznmConList.cpp
	* job handler for job QryWznmConList (implementation)
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

#include "QryWznmConList.h"

#include "QryWznmConList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmConList
 ******************************************************************************/

QryWznmConList::QryWznmConList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMCONLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMCONMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmConList::~QryWznmConList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmConList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMCONUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMCONUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmConList::rerun(
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
	ubigint preRefDlg = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFDLG, jref);
	ubigint preRefPnl = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPNL, jref);
	ubigint preRefVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMCONLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMCONLIST_TYP, jref);
	uint preHkt = xchg->getIxPreset(VecWznmVPreset::PREWZNMCONLIST_HKT, jref);
	ubigint preHku = xchg->getRefPreset(VecWznmVPreset::PREWZNMCONLIST_HKU, jref);
	uint preSct = xchg->getIxPreset(VecWznmVPreset::PREWZNMCONLIST_SCT, jref);
	uint preRet = xchg->getIxPreset(VecWznmVPreset::PREWZNMCONLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWznmVPreset::PREWZNMCONLIST_REU, jref);
	ubigint preSup = xchg->getRefPreset(VecWznmVPreset::PREWZNMCONLIST_SUP, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqconlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFPNL) {
		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL);
		sqlstr += " AND TblWznmMControl.hkUref = " + to_string(preRefPnl) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFDLG) {
		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG);
		sqlstr += " AND TblWznmMControl.hkUref = " + to_string(preRefDlg) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFCAR) {
		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR);
		sqlstr += " AND TblWznmMControl.hkUref = " + to_string(preRefCar) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl, TblWznmMDialog";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMDialog.ref";
		sqlstr += " AND TblWznmMDialog.refWznmMCard = " + to_string(preRefCar) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl, TblWznmMPanel";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMPanel.ref";
		sqlstr += " AND TblWznmMPanel.carRefWznmMCard = " + to_string(preRefCar) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl, TblWznmMModule, TblWznmMCard";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMCard.ref";
		sqlstr += " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl, TblWznmMModule, TblWznmMCard, TblWznmMDialog";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMDialog.ref";
		sqlstr += " AND TblWznmMDialog.refWznmMCard = TblWznmMCard.ref";
		sqlstr += " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl, TblWznmMModule, TblWznmMCard, TblWznmMPanel";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMPanel.ref";
		sqlstr += " AND TblWznmMPanel.carRefWznmMCard = TblWznmMCard.ref";
		sqlstr += " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMControl.ref)";
		sqlstr += " FROM TblWznmMControl";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, true);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFPNL) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL);
		sqlstr += " AND TblWznmMControl.hkUref = " + to_string(preRefPnl) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFDLG) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG);
		sqlstr += " AND TblWznmMControl.hkUref = " + to_string(preRefDlg) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFCAR) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR);
		sqlstr += " AND TblWznmMControl.hkUref = " + to_string(preRefCar) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl, TblWznmMDialog";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMDialog.ref";
		sqlstr += " AND TblWznmMDialog.refWznmMCard = " + to_string(preRefCar) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl, TblWznmMPanel";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMPanel.ref";
		sqlstr += " AND TblWznmMPanel.carRefWznmMCard = " + to_string(preRefCar) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[2]) + " OFFSET " + to_string(ofss[2]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl, TblWznmMModule, TblWznmMCard";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMCard.ref";
		sqlstr += " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl, TblWznmMModule, TblWznmMCard, TblWznmMDialog";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMDialog.ref";
		sqlstr += " AND TblWznmMDialog.refWznmMCard = TblWznmMCard.ref";
		sqlstr += " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl, TblWznmMModule, TblWznmMCard, TblWznmMPanel";
		sqlstr += " WHERE TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL);
		sqlstr += " AND TblWznmMControl.hkUref = TblWznmMPanel.ref";
		sqlstr += " AND TblWznmMPanel.carRefWznmMCard = TblWznmMCard.ref";
		sqlstr += " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref";
		sqlstr += " AND TblWznmMModule.verRefWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[2]) + " OFFSET " + to_string(ofss[2]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMControl";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSct, preRet, preReu, preSup, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQConList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmConList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQConList(jref, jnum, ref, sref, Title, ixVBasetype, hkIxVTbl, hkUref, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, ixVSubtype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMControl.ref, TblWznmMControl.sref, TblWznmMControl.Title, TblWznmMControl.ixVBasetype, TblWznmMControl.hkIxVTbl, TblWznmMControl.hkUref, TblWznmMControl.hkIxVSection, TblWznmMControl.refIxVTbl, TblWznmMControl.refUref, TblWznmMControl.supRefWznmMControl, TblWznmMControl.ixVSubtype";
};

void QryWznmConList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const uint preHkt
			, const ubigint preHku
			, const uint preSct
			, const uint preRet
			, const ubigint preReu
			, const ubigint preSup
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMControl.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMControl.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preHkt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMControl.hkIxVTbl = " + to_string(preHkt) + "";
	};

	if (preHku != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMControl.hkUref = " + to_string(preHku) + "";
	};

	if (preSct != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMControl.hkIxVSection = " + to_string(preSct) + "";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMControl.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMControl.refUref = " + to_string(preReu) + "";
	};

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMControl.supRefWznmMControl = " + to_string(preSup) + "";
	};
};

void QryWznmConList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmConList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblWznmMControl.supRefWznmMControl ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWznmMControl.refUref ASC";
	else if (preIxOrd == VecVOrd::SCT) sqlstr += " ORDER BY TblWznmMControl.hkIxVSection ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWznmMControl.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::HKU) sqlstr += " ORDER BY TblWznmMControl.hkUref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMControl.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::HKT) sqlstr += " ORDER BY TblWznmMControl.hkIxVTbl ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMControl.sref ASC";
};

void QryWznmConList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQConList* rec = NULL;

	dbswznm->tblwznmqconlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMControlBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMControlBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->srefHkIxVTbl = VecWznmVMControlHkTbl::getSref(rec->hkIxVTbl);
			rec->titHkIxVTbl = VecWznmVMControlHkTbl::getTitle(rec->hkIxVTbl, ixWznmVLocale);
			if (rec->hkIxVTbl == VecWznmVMControlHkTbl::PNL) {
				rec->stubHkUref = StubWznm::getStubPnlStd(dbswznm, rec->hkUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecWznmVMControlHkTbl::DLG) {
				rec->stubHkUref = StubWznm::getStubDlgStd(dbswznm, rec->hkUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecWznmVMControlHkTbl::CAR) {
				rec->stubHkUref = StubWznm::getStubCarStd(dbswznm, rec->hkUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubHkUref = "-";
			rec->srefHkIxVSection = VecWznmVMControlHkSection::getSref(rec->hkIxVSection);
			rec->titHkIxVSection = VecWznmVMControlHkSection::getTitle(rec->hkIxVSection, ixWznmVLocale);
			rec->srefRefIxVTbl = VecWznmVMControlRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWznmVMControlRefTbl::getTitle(rec->refIxVTbl, ixWznmVLocale);
			if (rec->refIxVTbl == VecWznmVMControlRefTbl::DLG) {
				rec->stubRefUref = StubWznm::getStubDlgStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMControlRefTbl::QCO) {
				rec->stubRefUref = StubWznm::getStubQcoStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
				rec->stubRefUref = StubWznm::getStubTcoStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMControlRefTbl::REL) {
				rec->stubRefUref = StubWznm::getStubRelStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->stubSupRefWznmMControl = StubWznm::getStubConStd(dbswznm, rec->supRefWznmMControl, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVSubtype = VecWznmVMControlSubtype::getSref(rec->ixVSubtype);
			rec->titIxVSubtype = VecWznmVMControlSubtype::getTitle(rec->ixVSubtype, ixWznmVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmConList", "fetch");
	};

	refreshJnum();
};

uint QryWznmConList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQConList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmConList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQConList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQConList* QryWznmConList::getRecByJnum(
			const uint jnum
		) {
	WznmQConList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmConList::handleRequest(
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

bool QryWznmConList::handleRerun(
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

bool QryWznmConList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQConList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\thkIxVTbl";
	cout << "\tsrefHkIxVTbl";
	cout << "\ttitHkIxVTbl";
	cout << "\thkUref";
	cout << "\tstubHkUref";
	cout << "\thkIxVSection";
	cout << "\tsrefHkIxVSection";
	cout << "\ttitHkIxVSection";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\tsupRefWznmMControl";
	cout << "\tstubSupRefWznmMControl";
	cout << "\tixVSubtype";
	cout << "\tsrefIxVSubtype";
	cout << "\ttitIxVSubtype";
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
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->hkIxVTbl;
		cout << "\t" << rec->srefHkIxVTbl;
		cout << "\t" << rec->titHkIxVTbl;
		cout << "\t" << rec->hkUref;
		cout << "\t" << rec->stubHkUref;
		cout << "\t" << rec->hkIxVSection;
		cout << "\t" << rec->srefHkIxVSection;
		cout << "\t" << rec->titHkIxVSection;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->supRefWznmMControl;
		cout << "\t" << rec->stubSupRefWznmMControl;
		cout << "\t" << rec->ixVSubtype;
		cout << "\t" << rec->srefIxVSubtype;
		cout << "\t" << rec->titIxVSubtype;
		cout << endl;
	};
	return retval;
};

void QryWznmConList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMCONUPD_REFEQ) {
		call->abort = handleCallWznmConUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCONMOD) {
		call->abort = handleCallWznmConMod(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmConList::handleCallWznmConUpd_refEq(
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

bool QryWznmConList::handleCallWznmConMod(
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

bool QryWznmConList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};



