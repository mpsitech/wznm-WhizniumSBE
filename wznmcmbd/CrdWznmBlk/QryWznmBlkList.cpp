/**
	* \file QryWznmBlkList.cpp
	* job handler for job QryWznmBlkList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "QryWznmBlkList.h"

#include "QryWznmBlkList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWznmBlkList
 ******************************************************************************/

QryWznmBlkList::QryWznmBlkList(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::QRYWZNMBLKLIST, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWznmVQrystate = VecWznmVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswznm);

	xchg->addClstn(VecWznmVCall::CALLWZNMBLKMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWznmBlkList::~QryWznmBlkList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWznmBlkList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMBLKUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMBLKUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWznmBlkList::rerun(
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
	ubigint preRefJob = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref);
	ubigint preRefOpx = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPX, jref);
	ubigint preRefOpk = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref);
	ubigint preRefVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWznmVPreset::PREWZNMBLKLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWznmVPreset::PREWZNMBLKLIST_TYP, jref);
	ubigint preVer = xchg->getRefPreset(VecWznmVPreset::PREWZNMBLKLIST_VER, jref);
	uint preRet = xchg->getIxPreset(VecWznmVPreset::PREWZNMBLKLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWznmVPreset::PREWZNMBLKLIST_REU, jref);

	dbswznm->tblwznmqselect->removeRstByJref(jref);
	dbswznm->tblwznmqblklist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWznmVPreset::PREWZNMREFJOB) {
		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB);
		sqlstr += " AND TblWznmMBlock.refUref = " + to_string(preRefJob) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFOPX) {
		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX);
		sqlstr += " AND TblWznmMBlock.refUref = " + to_string(preRefOpx) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFOPK) {
		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock, TblWznmMOp";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX);
		sqlstr += " AND TblWznmMBlock.refUref = TblWznmMOp.ref";
		sqlstr += " AND TblWznmMOp.refWznmMOppack = " + to_string(preRefOpk) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK);
		sqlstr += " AND TblWznmMBlock.refUref = " + to_string(preRefOpk) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock";
		sqlstr += " WHERE TblWznmMBlock.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock, TblWznmMJob";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB);
		sqlstr += " AND TblWznmMBlock.refUref = TblWznmMJob.ref";
		sqlstr += " AND TblWznmMJob.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock, TblWznmMOp, TblWznmMOppack";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX);
		sqlstr += " AND TblWznmMBlock.refUref = TblWznmMOp.ref";
		sqlstr += " AND TblWznmMOp.refWznmMOppack = TblWznmMOppack.ref";
		sqlstr += " AND TblWznmMOppack.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock, TblWznmMOppack";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK);
		sqlstr += " AND TblWznmMBlock.refUref = TblWznmMOppack.ref";
		sqlstr += " AND TblWznmMOppack.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		dbswznm->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWznmMBlock.ref)";
		sqlstr += " FROM TblWznmMBlock";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, true);
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

	if (preIxPre == VecWznmVPreset::PREWZNMREFJOB) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB);
		sqlstr += " AND TblWznmMBlock.refUref = " + to_string(preRefJob) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFOPX) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX);
		sqlstr += " AND TblWznmMBlock.refUref = " + to_string(preRefOpx) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFOPK) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock, TblWznmMOp";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX);
		sqlstr += " AND TblWznmMBlock.refUref = TblWznmMOp.ref";
		sqlstr += " AND TblWznmMOp.refWznmMOppack = " + to_string(preRefOpk) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK);
		sqlstr += " AND TblWznmMBlock.refUref = " + to_string(preRefOpk) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbswznm->executeQuery(sqlstr);

	} else if (preIxPre == VecWznmVPreset::PREWZNMREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock";
		sqlstr += " WHERE TblWznmMBlock.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock, TblWznmMJob";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB);
		sqlstr += " AND TblWznmMBlock.refUref = TblWznmMJob.ref";
		sqlstr += " AND TblWznmMJob.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock, TblWznmMOp, TblWznmMOppack";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX);
		sqlstr += " AND TblWznmMBlock.refUref = TblWznmMOp.ref";
		sqlstr += " AND TblWznmMOp.refWznmMOppack = TblWznmMOppack.ref";
		sqlstr += " AND TblWznmMOppack.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[2]) + " OFFSET " + to_string(ofss[2]);
		dbswznm->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock, TblWznmMOppack";
		sqlstr += " WHERE TblWznmMBlock.refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK);
		sqlstr += " AND TblWznmMBlock.refUref = TblWznmMOppack.ref";
		sqlstr += " AND TblWznmMOppack.refWznmMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[3]) + " OFFSET " + to_string(ofss[3]);
		dbswznm->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWznmMBlock";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preVer, preRet, preReu, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswznm->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWznmQBlkList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswznm->executeQuery(sqlstr);

	ixWznmVQrystate = VecWznmVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswznm);

	if (call) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTATCHG, jref);

};

void QryWznmBlkList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWznmQBlkList(jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWznmMBlock.ref, TblWznmMBlock.sref, TblWznmMBlock.ixVBasetype, TblWznmMBlock.refWznmMVersion, TblWznmMBlock.refIxVTbl, TblWznmMBlock.refUref";
};

void QryWznmBlkList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preVer
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMBlock.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMBlock.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preVer != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMBlock.refWznmMVersion = " + to_string(preVer) + "";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMBlock.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWznmMBlock.refUref = " + to_string(preReu) + "";
	};
};

void QryWznmBlkList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWznmBlkList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWznmMBlock.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWznmMBlock.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::VER) sqlstr += " ORDER BY TblWznmMBlock.refWznmMVersion ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWznmMBlock.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWznmMBlock.refUref ASC";
};

void QryWznmBlkList::fetch(
			DbsWznm* dbswznm
		) {
	string sqlstr;

	StmgrWznm* stmgr = NULL;
	Stcch* stcch = NULL;

	WznmQBlkList* rec = NULL;

	dbswznm->tblwznmqblklist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWznmVMBlockBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWznmVMBlockBasetype::getTitle(rec->ixVBasetype, ixWznmVLocale);
			rec->stubRefWznmMVersion = StubWznm::getStubVerStd(dbswznm, rec->refWznmMVersion, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefRefIxVTbl = VecWznmVMBlockRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWznmVMBlockRefTbl::getTitle(rec->refIxVTbl, ixWznmVLocale);
			if (rec->refIxVTbl == VecWznmVMBlockRefTbl::JOB) {
				rec->stubRefUref = StubWznm::getStubJobStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMBlockRefTbl::OPX) {
				rec->stubRefUref = StubWznm::getStubOpxStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWznmVMBlockRefTbl::OPK) {
				rec->stubRefUref = StubWznm::getStubOpkStd(dbswznm, rec->refUref, ixWznmVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWznmBlkList", "fetch");
	};

	refreshJnum();
};

uint QryWznmBlkList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WznmQBlkList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWznmBlkList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WznmQBlkList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WznmQBlkList* QryWznmBlkList::getRecByJnum(
			const uint jnum
		) {
	WznmQBlkList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWznmBlkList::handleRequest(
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

bool QryWznmBlkList::handleRerun(
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

bool QryWznmBlkList::handleShow(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	WznmQBlkList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\trefWznmMVersion";
	cout << "\tstubRefWznmMVersion";
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
		cout << "\t" << rec->refWznmMVersion;
		cout << "\t" << rec->stubRefWznmMVersion;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << endl;
	};
	return retval;
};

void QryWznmBlkList::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMBLKMOD) {
		call->abort = handleCallWznmBlkMod(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMBLKUPD_REFEQ) {
		call->abort = handleCallWznmBlkUpd_refEq(dbswznm, call->jref);
	} else if ((call->ixVCall == VecWznmVCall::CALLWZNMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWznmStubChgFromSelf(dbswznm);
	};
};

bool QryWznmBlkList::handleCallWznmBlkMod(
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

bool QryWznmBlkList::handleCallWznmBlkUpd_refEq(
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

bool QryWznmBlkList::handleCallWznmStubChgFromSelf(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleCallWznmStubChgFromSelf --- INSERT
	return retval;
};

