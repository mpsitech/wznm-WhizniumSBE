/**
	* \file WznmComplJtr.cpp
	* Wznm operation processor - complement job tree (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmComplJtr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCompl;

/******************************************************************************
 namespace WznmComplJtr
 ******************************************************************************/

DpchRetWznm* WznmComplJtr::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmComplJtr* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

	// derive sensitivities from immediate callback and non-zero monitoring interval stages
	addImmcbUpdmonSnss(dbswznm, refWznmMVersion);
	addUldDldSnss(dbswznm, refWznmMVersion);

	// add all Clisrv jobs below root
	addRootJrjs(dbswznm, refWznmMVersion, Prjshort);

	// add all Clisrv jobs with features below m2msess and fill statshr block
	addM2msessJrjs(dbswznm, refWznmMVersion, Prjshort);

	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmComplJtr::addImmcbUpdmonSnss(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
		) {
	ListWznmMStage sges;
	WznmMStage* sge = NULL;

	dbswznm->tblwznmmstage->loadRstBySQL("SELECT TblWznmMStage.* FROM TblWznmMJob, TblWznmMStage WHERE TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion) + " AND TblWznmMStage.jobRefWznmMJob = TblWznmMJob.ref", false, sges);

	for (unsigned int i = 0; i < sges.nodes.size(); i++) {
		sge = sges.nodes[i];

		if (sge->Monitvl != 0) dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::TMR, sge->jobRefWznmMJob, sge->ref, 0, VecWznmVMSensitivityJactype::WEAK, VecWznmVMSensitivityJobmask::VOID, "", "", 0, "mon", VecWznmVMSensitivityAction::UPDMON, 0, true);

		if (sge->ixVBasetype == VecWznmVMStageBasetype::IMMCB) {
			dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::TMR, sge->jobRefWznmMJob, sge->ref, 0, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::VOID, "", "", 0, "", VecWznmVMSensitivityAction::CHGSGESNX, 0, false);
		} else if (sge->ixVBasetype == VecWznmVMStageBasetype::OTHWC) {
			dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::TMR, sge->jobRefWznmMJob, sge->ref, 0, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::VOID, "", "", 0, "callback", VecWznmVMSensitivityAction::CHGSGE, sge->ref, false);
		};
	};
};

void WznmComplJtr::addUldDldSnss(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
		) {
	vector<ubigint> refsConUld, refsConDld;

	vector<ubigint> refsSnsUld, refsSnsDld;
	set<ubigint> unqrefsSnsUld, unqrefsSnsDld;

	// find all UI jobs with upload/download controls
	addUldDldSnss_jobrefs(dbswznm, refWznmMVersion, VecWznmVMJobRefTbl::CAR, VecWznmVMControlHkTbl::CAR, VecWznmVMControlBasetype::ULD, false, refsConUld);
	addUldDldSnss_jobrefs(dbswznm, refWznmMVersion, VecWznmVMJobRefTbl::DLG, VecWznmVMControlHkTbl::DLG, VecWznmVMControlBasetype::ULD, true, refsConUld);
	addUldDldSnss_jobrefs(dbswznm, refWznmMVersion, VecWznmVMJobRefTbl::PNL, VecWznmVMControlHkTbl::PNL, VecWznmVMControlBasetype::ULD, true, refsConUld);

	addUldDldSnss_jobrefs(dbswznm, refWznmMVersion, VecWznmVMJobRefTbl::CAR, VecWznmVMControlHkTbl::CAR, VecWznmVMControlBasetype::DLD, false, refsConDld);
	addUldDldSnss_jobrefs(dbswznm, refWznmMVersion, VecWznmVMJobRefTbl::DLG, VecWznmVMControlHkTbl::DLG, VecWznmVMControlBasetype::DLD, true, refsConDld);
	addUldDldSnss_jobrefs(dbswznm, refWznmMVersion, VecWznmVMJobRefTbl::PNL, VecWznmVMControlHkTbl::PNL, VecWznmVMControlBasetype::DLD, true, refsConDld);

	// find all jobs with upload/download sensitivity
	dbswznm->loadRefsBySQL("SELECT DISTINCT TblWznmMJob.ref FROM TblWznmMJob, TblWznmMSensitivity WHERE TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND TblWznmMJob.ref = TblWznmMSensitivity.refWznmMJob AND TblWznmMSensitivity.ixVBasetype = " + to_string(VecWznmVMSensitivityBasetype::ULD), false, refsSnsUld);
	for (unsigned int i = 0; i < refsSnsUld.size(); i++) unqrefsSnsUld.insert(refsSnsUld[i]);

	dbswznm->loadRefsBySQL("SELECT DISTINCT TblWznmMJob.ref FROM TblWznmMJob, TblWznmMSensitivity WHERE TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND TblWznmMJob.ref = TblWznmMSensitivity.refWznmMJob AND TblWznmMSensitivity.ixVBasetype = " + to_string(VecWznmVMSensitivityBasetype::DLD), false, refsSnsDld);
	for (unsigned int i = 0; i < refsSnsDld.size(); i++) unqrefsSnsDld.insert(refsSnsDld[i]);

	// match else create
	for (unsigned int i = 0; i < refsConUld.size(); i++)
		if (unqrefsSnsUld.find(refsConUld[i]) == unqrefsSnsUld.end())
			dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::ULD, refsConUld[i], 0, 0, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::VOID, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

	for (unsigned int i = 0; i < refsConDld.size(); i++)
		if (unqrefsSnsDld.find(refsConDld[i]) == unqrefsSnsDld.end())
			dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::DLD, refsConDld[i], 0, 0, VecWznmVMSensitivityJactype::LOCK, VecWznmVMSensitivityJobmask::VOID, "", "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);
};

void WznmComplJtr::addUldDldSnss_jobrefs(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const uint hkIxVTbl
			, const uint ixVBasetype
			, const bool append
			, vector<ubigint>& refs
		) {
	dbswznm->loadRefsBySQL("SELECT DISTINCT TblWznmMJob.ref FROM TblWznmMJob, TblWznmMControl WHERE TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion) + " AND TblWznmMJob.refIxVTbl = " + to_string(refIxVTbl)
				+ " AND TblWznmMJob.refUref = TblWznmMControl.hkUref AND TblWznmMControl.hkIxVTbl = " + to_string(hkIxVTbl) + " AND TblWznmMControl.ixVBasetype = " + to_string(ixVBasetype), append, refs);
};

void WznmComplJtr::addRootJrjs(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	ubigint refRoot;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	string s;

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::ROOT) + " AND sref = 'Root" + Prjshort + "'", refRoot)) {
		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND Clisrv = 1 ORDER BY sref ASC", false, jobs);

		for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
			job = jobs.nodes[i];

			s = job->sref;
			if (s.find("Job") == 0) s = s.substr(3);
			if (s.find(Prjshort) == 0) s = s.substr(Prjshort.length());
			s = StrMod::lc(s);

			dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refRoot, job->ref, s, false, VecWznmVRMJobMJobConstract::CRE);
		};
	};
};

void WznmComplJtr::addM2msessJrjs(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	ubigint refM2msess;

	ubigint refStatshr;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	uint bitnum;

	bool hasfeat;
	uint cnt;

	string s;

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS) + " AND sref = 'M2msess" + Prjshort + "'", refM2msess)) {
		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(refM2msess) + " AND sref LIKE 'StatShr%'", refStatshr)) {
			bitnum = 1;

			dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND Clisrv = 1 ORDER BY sref ASC", false, jobs);

			for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
				job = jobs.nodes[i];

				dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMMethod WHERE refWznmMJob = " + to_string(job->ref), cnt);
				hasfeat = (cnt > 0);

				if (!hasfeat) {
					dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMJobVar WHERE jobRefWznmMJob = " + to_string(job->ref), cnt);
					hasfeat = (cnt > 0);
				};
				
				if (hasfeat) {
					s = job->sref;
					if (s.find("Job") == 0) s = s.substr(3);
					if (s.find(Prjshort) == 0) s = s.substr(Prjshort.length());
					s = StrMod::lc(s);

					dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refM2msess, job->ref, s, false, VecWznmVRMJobMJobConstract::CUST);
					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, refStatshr, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jref" + StrMod::cap(s), VecWznmVVartype::SCRREF, 0, 0, 0, 0, 0, 0, "", 0, "");
				};
			};
		};
	};
};
// IP cust --- IEND


