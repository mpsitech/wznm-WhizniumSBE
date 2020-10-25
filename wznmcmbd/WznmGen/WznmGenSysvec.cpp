/**
	* \file WznmGenSysvec.cpp
	* Wznm operation processor - fill system vectors (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmGenSysvec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmGen;

/******************************************************************************
 namespace WznmGenSysvec
 ******************************************************************************/

DpchRetWznm* WznmGenSysvec::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmGenSysvec* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	string sref;

	Wznm::getVerlclrefs(dbswznm, refWznmMVersion, refLcl, refsLcl);

	// generate and fill method vectors
	dbswznm->loadRefsBySQL("SELECT DISTINCT TblWznmMJob.ref FROM TblWznmMJob, TblWznmMMethod WHERE TblWznmMJob.ref = TblWznmMMethod.refWznmMJob AND TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion), false, refs);
	dbswznm->tblwznmmjob->loadRstByRefs(refs, false, jobs);

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		dbswznm->tblwznmmvector->insertNewRec(&vec, VecWznmVMVectorBasetype::LIN, refWznmMVersion, VecWznmVMVectorHkTbl::JOB, job->ref, 0, "VecV" + job->sref + "Method", "", "noloc;notit;filfed");
		fillVecMethod(dbswznm, vec);
	};

	// generate and fill variable vectors
	dbswznm->loadRefsBySQL("SELECT DISTINCT TblWznmMJob.ref FROM TblWznmMJob, TblWznmAMJobVar WHERE TblWznmMJob.ref = TblWznmAMJobVar.jobRefWznmMJob AND TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion), false, refs);
	dbswznm->tblwznmmjob->loadRstByRefs(refs, false, jobs);

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		dbswznm->tblwznmmvector->insertNewRec(&vec, VecWznmVMVectorBasetype::LIN, refWznmMVersion, VecWznmVMVectorHkTbl::JOB, job->ref, 0, "VecV" + job->sref + "Var", "", "noloc;notit;filfed");
		fillVecVar(dbswznm, vec);
	};

	// fill stage vectors, generate if necessary
	dbswznm->loadRefsBySQL("SELECT DISTINCT TblWznmMJob.ref FROM TblWznmMJob, TblWznmMStage WHERE TblWznmMJob.ref = TblWznmMStage.jobRefWznmMJob AND TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion), false, refs);
	dbswznm->tblwznmmjob->loadRstByRefs(refs, false, jobs);

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		if (!dbswznm->tblwznmmvector->loadRecBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = " + to_string(job->ref) + " AND sref LIKE 'Vec%Sge'", &vec)) {
			if ((job->ixVBasetype == VecWznmVMJobBasetype::CRD) || (job->ixVBasetype == VecWznmVMJobBasetype::PNL)) sref = "VecV" + job->sref.substr(3) + "Sge";
			else sref = "VecV" + job->sref + "Sge";

			dbswznm->tblwznmmvector->insertNewRec(&vec, VecWznmVMVectorBasetype::LIN, refWznmMVersion, VecWznmVMVectorHkTbl::JOB, job->ref, 0, sref, "", "noloc;notit;filfed");
		};

		fillVecSge(dbswznm, vec);
		delete vec;
	};

	// fill query order vectors
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMVectorBasetype::LIN)
				+ " AND sref LIKE 'Vec%Ord'", false, vecs);
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		fillVecOrd(dbswznm, vec);
	};

	// fill dialog item vectors
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMVectorBasetype::LIN)
				+ " AND sref LIKE 'Vec%Dit'", false, vecs);
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		fillVecDit(dbswznm, vec, refLcl, refsLcl);
	};

	// fill vectors available to database
	fillVecControl(dbswznm, refWznmMVersion, Prjshort);

	// fill application-wide vectors
	fillVecCall(dbswznm, refWznmMVersion, Prjshort);
	fillVecCard(dbswznm, refWznmMVersion, Prjshort, refLcl);
	fillVecDpch(dbswznm, refWznmMVersion, Prjshort);
	fillVecError(dbswznm, refWznmMVersion, Prjshort, refLcl);
	fillVecFeatgroup(dbswznm, refWznmMVersion, Prjshort, refLcl, refsLcl);
	fillVecJob(dbswznm, refWznmMVersion, Prjshort);
	fillVecOpengtype(dbswznm, refWznmMVersion, Prjshort, refLcl, refsLcl);
	fillVecOppack(dbswznm, refWznmMVersion, Prjshort);
	fillVecPreset(dbswznm, refWznmMVersion, Prjshort, refLcl);
	fillVecStub(dbswznm, refWznmMVersion, Prjshort);
	fillVecTag(dbswznm, refWznmMVersion, Prjshort, refLcl, refsLcl);
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmGenSysvec::fillVecSge(
			DbsWznm* dbswznm
			, WznmMVector* vec
		) {
	ListWznmMStage sges;
	WznmMStage* sge = NULL;

	dbswznm->tblwznmmstage->loadRstBySQL("SELECT * FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(vec->hkUref) + " ORDER BY jobNum ASC", false, sges);

	for (unsigned int i = 0; i < sges.nodes.size(); i++) {
		sge = sges.nodes[i];
		dbswznm->tblwznmmvectoritem->insertNewRec(NULL, vec->ref, (i+1), sge->sref, "", "", 0, "", "");
	};
};

void WznmGenSysvec::fillVecOrd(
			DbsWznm* dbswznm
			, WznmMVector* vec
		) {
	string vecroot;
	ubigint refQry = 0;

	ListWznmAMQueryOrder qaos;
	WznmAMQueryOrder* qao = NULL;

	if ( (vec->sref.find("VecV") == 0) && ((vec->sref.rfind("Ord")+3) == vec->sref.length()) ) {
		// expect query hook
		vecroot = vec->sref.substr(4, vec->sref.length()-4-3);
		dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMQuery WHERE refWznmMVersion = " + to_string(vec->refWznmMVersion) + " AND sref = '" + vecroot + "'", refQry);

		if (refQry != 0) {
			dbswznm->tblwznmamqueryorder->loadRstByQry(refQry, false, qaos);

			for (unsigned int i = 0; i < qaos.nodes.size(); i++) {
				qao = qaos.nodes[i];
				dbswznm->tblwznmmvectoritem->insertNewRec(NULL, vec->ref, (i+1), qao->Short, "", "", 0, "", "");
			};
		};
	};
};

void WznmGenSysvec::fillVecDit(
			DbsWznm* dbswznm
			, WznmMVector* vec
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	string vecroot;
	ubigint refDlg = 0;

	ListWznmMControl ditcons;
	WznmMControl* ditcon = NULL;

	ListWznmJMControlTitle cjts;
	WznmJMControlTitle* cjt = NULL;

	WznmMVectoritem* vit = NULL;

	map<ubigint,string> tagTits;

	string s;

	if ( (vec->sref.find("VecV") == 0) && ((vec->sref.rfind("Dit")+3) == vec->sref.length()) ) {
		// expect dialog hook
		vecroot = vec->sref.substr(4, vec->sref.length()-4-3);
		dbswznm->loadRefBySQL("SELECT refUref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(vec->refWznmMVersion) + " AND sref = '" + vecroot + "'", refDlg);

		if (refDlg != 0) {
			dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(refDlg)
						+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::DIT) + " ORDER BY hkNum ASC", false, ditcons);

			for (unsigned int i = 0; i < ditcons.nodes.size(); i++) {
				ditcon = ditcons.nodes[i];

				dbswznm->tblwznmmvectoritem->insertNewRec(&vit, vec->ref, i+1, ditcon->sref.substr(3), "", "", 0, ditcon->Title, "");

				if (ditcon->srefsWznmMTag.length() > 0) {
					Wznm::getTagtits(dbswznm, ditcon->srefsWznmMTag, "", "", {}, refLcl, refsLcl, tagTits, false);

					if (!tagTits.empty()) {
						for (unsigned int j = 0; j < refsLcl.size(); j++) {
							s = tagTits[refsLcl[j]];

							if (StrMod::srefInSrefs(ditcon->srefsKOption, "cap")) s = StrMod::cap(s);
							if (StrMod::srefInSrefs(ditcon->srefsKOption, "ddd")) s = s + " ...";

							ref = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refsLcl[j], s, "");

							if (refsLcl[j] == refLcl) {
								vit->refJ = ref;
								vit->Title = s;

								dbswznm->tblwznmmvectoritem->updateRec(vit);
							};
						};
					};

				} else {
					dbswznm->tblwznmjmcontroltitle->loadRstByCon(ditcon->ref, false, cjts);
					for (unsigned int j = 0; j < cjts.nodes.size(); j++) {
						cjt = cjts.nodes[j];

						ref = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, cjt->x1RefWznmMLocale, cjt->Title, "");

						if (ditcon->refJTitle == cjt->ref) {
							vit->refJ = ref;
							vit->Title = cjt->Title;
							dbswznm->tblwznmmvectoritem->updateRec(vit);
						};
					};
				};

				delete vit;
			};
		};
	};
};

void WznmGenSysvec::fillVecMethod(
			DbsWznm* dbswznm
			, WznmMVector* vec
		) {
	ListWznmMMethod mtds;
	WznmMMethod* mtd = NULL;

	dbswznm->tblwznmmmethod->loadRstByJob(vec->hkUref, false, mtds);

	for (unsigned int i = 0; i < mtds.nodes.size(); i++) {
		mtd = mtds.nodes[i];
		dbswznm->tblwznmmvectoritem->insertNewRec(NULL, vec->ref, (i+1), mtd->sref, "", "", 0, "", "");
	};
};

void WznmGenSysvec::fillVecVar(
			DbsWznm* dbswznm
			, WznmMVector* vec
		) {
	ListWznmAMJobVar vars;
	vector<string> varsrefs;
	vector<bool> Shrs;
	vector<unsigned int> Ns;

	Wznm::getJobvars(dbswznm, vec->hkUref, vars, varsrefs, Shrs, Ns);

	for (unsigned int i = 0; i < varsrefs.size(); i++) dbswznm->tblwznmmvectoritem->insertNewRec(NULL, vec->ref, (i+1), varsrefs[i], "", "", 0, "", "");
};

void WznmGenSysvec::fillVecCall(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	ubigint refVec;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmMCall cals;
	WznmMCall* cal = NULL;

	// find VecXxxxVCall
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VCall", refVec)) {
	
		// one vector item for each call
		dbswznm->tblwznmmcall->loadRstByVer(refWznmMVersion, false, cals);
		for (unsigned int i = 0; i < cals.nodes.size(); i++) {
			cal = cals.nodes[i];

			vit = new WznmMVectoritem(0, refVec, (i+1), cal->sref, "", "", 0, "", "");
			
			dbswznm->tblwznmmvectoritem->insertRec(vit);
			vits.nodes.push_back(vit);
		};
	};
};

void WznmGenSysvec::fillVecControl(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	vector<ubigint> refs;

	ubigint refVec;

	uint vitcnt = 1;

	ListWznmMCard crds;
	WznmMCard* crd = NULL;

	ListWznmMDialog dlgs;
	WznmMDialog* dlg = NULL;

	ListWznmMPanel pnls;
	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	// find VecXxxxVControl
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VControl", refVec)) {

		// cards
		dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
		for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, crds);

		for (unsigned int i = 0; i < crds.nodes.size(); i++) {
			crd = crds.nodes[i];

			// no card controls

			// dialogs
			dbswznm->tblwznmmdialog->loadRstBySQL("SELECT * FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(crd->ref), false, dlgs);

			for (unsigned int j = 0; j < dlgs.nodes.size(); j++) {
				dlg = dlgs.nodes[j];

				// dialog controls
				dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = "
							+ to_string(dlg->ref) + " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::TCO) + " ORDER BY hkNum ASC", false, cons);

				for (unsigned int k = 0; k < cons.nodes.size(); k++) {
					con = cons.nodes[k];
					dbswznm->tblwznmmvectoritem->insertNewRec(NULL, refVec, vitcnt++, dlg->sref + "." + con->sref, "", "", 0, "", "");
				};
			};
			
			// panels
			dbswznm->tblwznmmpanel->loadRstByCar(crd->ref, false, pnls);

			for (unsigned int j = 0; j < pnls.nodes.size(); j++) {
				pnl = pnls.nodes[j];

				// panel controls
				dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = "
							+ to_string(pnl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::TCO) + " ORDER BY hkNum ASC", false, cons);

				for (unsigned int k = 0; k < cons.nodes.size(); k++) {
					con = cons.nodes[k];
					dbswznm->tblwznmmvectoritem->insertNewRec(NULL, refVec, vitcnt++, pnl->sref + "." + con->sref, "", "", 0, "", "");
				};
			};
		};
	};
};

void WznmGenSysvec::fillVecCard(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
		) {
	vector<ubigint> refs;

	ubigint refVec;

	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	ListWznmJMCardTitle carJtits;
	WznmJMCardTitle* carJtit = NULL;

	// find VecXxxxVCard
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VCard", refVec)) {

		dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
		for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

		// one vector item for each card
		for (unsigned int i = 0; i < cars.nodes.size(); i++) {
			car = cars.nodes[i];

			dbswznm->tblwznmmvectoritem->insertNewRec(&vit, refVec, i+1, car->sref, "", "", 0, "", "");

			// cards have localized titles
			dbswznm->tblwznmjmcardtitle->loadRstByCar(car->ref, false, carJtits);
			for (unsigned int j = 0; j < carJtits.nodes.size(); j++) {
				carJtit = carJtits.nodes[j];

				dbswznm->tblwznmjmvectoritem->appendNewRecToRst(vitjs, &vitj, vit->ref, carJtit->x1RefWznmMLocale, carJtit->Title, "");

				if (carJtit->x1RefWznmMLocale == refLcl) {
					vit->refJ = vitj->ref;
					vit->Title = vitj->Title;
					
					dbswznm->tblwznmmvectoritem->updateRec(vit);
				};
			};

			delete vit;
		};
	};
};

void WznmGenSysvec::fillVecDpch(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	ubigint refVec;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	// find VecXxxxVDpch
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VDpch", refVec)) {

		// one vector item for each dispatch block
		dbswznm->tblwznmmblock->loadRstByTypVer(VecWznmVMBlockBasetype::DPCH, refWznmMVersion, false, blks);
		for (unsigned int i = 0; i < blks.nodes.size(); i++) {
			blk = blks.nodes[i];

			vit = new WznmMVectoritem(0, refVec, (i+3), blk->sref, "", "", 0, "", "");
			
			dbswznm->tblwznmmvectoritem->insertRec(vit);
			vits.nodes.push_back(vit);
		};
	};
};

void WznmGenSysvec::fillVecError(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
		) {
	vector<ubigint> refs;

	ubigint refVec;
	uint vecNum;

	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	ListWznmMError errs;
	WznmMError* err = NULL;

	ListWznmJMErrorTitle errJtits;
	WznmJMErrorTitle* errJtit = NULL;

	// find VecXxxxVError
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VError", refVec)) {
		vecNum = 0;
		dbswznm->loadUintBySQL("SELECT vecNum FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refVec) + " ORDER BY vecNum DESC LIMIT 1", vecNum);
		vecNum++;

		dbswznm->tblwznmmerror->loadRstByVer(refWznmMVersion, false, errs);

		// one vector item for each error
		for (unsigned int i = 0; i < errs.nodes.size(); i++) {
			err = errs.nodes[i];

			dbswznm->tblwznmmvectoritem->insertNewRec(&vit, refVec, vecNum++, err->sref, "", "", 0, "", "");

			// errors have localized titles
			dbswznm->tblwznmjmerrortitle->loadRstByErr(err->ref, false, errJtits);
			for (unsigned int j = 0; j < errJtits.nodes.size(); j++) {
				errJtit = errJtits.nodes[j];

				dbswznm->tblwznmjmvectoritem->appendNewRecToRst(vitjs, &vitj, vit->ref, errJtit->x1RefWznmMLocale, errJtit->Title, "");

				if (errJtit->x1RefWznmMLocale == refLcl) {
					vit->refJ = vitj->ref;
					vit->Title = vitj->Title;
					
					dbswznm->tblwznmmvectoritem->updateRec(vit);
				};
			};

			delete vit;
		};
	};
};

void WznmGenSysvec::fillVecFeatgroup(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;
	ubigint refVec;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	map<ubigint,string> methodTits;
	map<ubigint,string> varTits;

	string Jobsref;

	Wznm::getTagtits(dbswznm, "method", "", "", {}, refLcl, refsLcl, methodTits, false);
	Wznm::getTagtits(dbswznm, "var", "", "", {}, refLcl, refsLcl, varTits, false);

	// find VecXxxxVFeatgroup
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VFeatgroup", refVec)) {

		// method and variable vector item for each job where applicable
		dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMVectorBasetype::LIN)
					+ " AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND ((sref LIKE 'VecV%Method') OR (sref LIKE 'VecV%Var')) ORDER BY sref ASC", false, vecs);
		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			Jobsref = vec->sref.substr(4);

			dbswznm->tblwznmmvectoritem->insertNewRec(&vit, refVec, i+2, vec->sref, "", "", 0, "", "");

			if ((vec->sref.rfind("Method")+6) == vec->sref.length()) {
				Jobsref = Jobsref.substr(0, Jobsref.length()-6);

				for (auto it = methodTits.begin(); it != methodTits.end(); it++) {
					// ex. 'JobMsdcAcqLwir method'
					dbswznm->tblwznmjmvectoritem->appendNewRecToRst(vitjs, &vitj, vit->ref, it->first, Jobsref + " " + it->second, "");

					if (it->first == refLcl) {
						vit->refJ = vitj->ref;
						vit->Title = vitj->Title;
						
						dbswznm->tblwznmmvectoritem->updateRec(vit);
					};
				};

			} else if ((vec->sref.rfind("Var")+3) == vec->sref.length()) {
				Jobsref = Jobsref.substr(0, Jobsref.length()-3);

				for (auto it = varTits.begin(); it != varTits.end(); it++) {
					// ex. 'JobMsdcAcqLwir variable'
					dbswznm->tblwznmjmvectoritem->appendNewRecToRst(vitjs, &vitj, vit->ref, it->first, Jobsref + " " + it->second, "");

					if (it->first == refLcl) {
						vit->refJ = vitj->ref;
						vit->Title = vitj->Title;
						
						dbswznm->tblwznmmvectoritem->updateRec(vit);
					};
				};
			};

			delete vit;
		};
	};
};

void WznmGenSysvec::fillVecJob(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	ubigint refVec;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	// find VecXxxxVJob
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VJob", refVec)) {
		
		// one vector item for each job
		dbswznm->tblwznmmjob->loadRstByVer(refWznmMVersion, false, jobs);
		for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
			job = jobs.nodes[i];
			dbswznm->tblwznmmvectoritem->insertNewRec(NULL, refVec, (i+1), job->sref, "", "", 0, "", "");
		};
	};
};

void WznmGenSysvec::fillVecOpengtype(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint refVec;

	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	map<ubigint,string> tagTits;

	ListWznmMComponent cmps;
	WznmMComponent* cmp = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	string s;

	// find VecXxxxVOpengtype
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VOpengtype", refVec)) {
		Wznm::getTagtits(dbswznm, "with", "", "", {}, refLcl, refsLcl, tagTits, false);

		// one vector item for each operation engine
		dbswznm->tblwznmmcomponent->loadRstBySQL("SELECT * FROM TblWznmMComponent WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMComponentBasetype::OPENG)
					+ " ORDER BY sref ASC", false, cmps);
		for (unsigned int i = 0; i < cmps.nodes.size(); i++) {
			cmp = cmps.nodes[i];

			dbswznm->tblwznmmvectoritem->insertNewRec(&vit, refVec, i+1, cmp->sref, "", "", 0, "", "");

			s = "";

			dbswznm->tblwznmmoppack->loadRstBySQL("SELECT TblWznmMOppack.* FROM TblWznmRMComponentMOppack, TblWznmMOppack WHERE TblWznmRMComponentMOppack.refWznmMComponent = "
						+ to_string(cmp->ref) + " AND TblWznmMOppack.ref = TblWznmRMComponentMOppack.refWznmMOppack ORDER BY TblWznmMOppack.sref ASC", false, opks);

			for (unsigned int j = 0; j < opks.nodes.size(); j++) {
				opk = opks.nodes[j];

				if (j != 0) s += "/";
				s += opk->sref;
			};

			for (auto it = tagTits.begin(); it != tagTits.end(); it++) {
				// ex. plnropd1 with PlnrExp/PlnrMeep
				dbswznm->tblwznmjmvectoritem->appendNewRecToRst(vitjs, &vitj, vit->ref, it->first, cmp->sref + " " + it->second + " " + s, "");

				if (it->first == refLcl) {
					vit->refJ = vitj->ref;
					vit->Title = vitj->Title;
					
					dbswznm->tblwznmmvectoritem->updateRec(vit);
				};
			};

			delete vit;
		};
	};
};

void WznmGenSysvec::fillVecOppack(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	ubigint refVec;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	// find VecXxxxVOppack
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VOppack", refVec)) {
		
		// one vector item for each op pack
		dbswznm->tblwznmmoppack->loadRstByVer(refWznmMVersion, false, opks);
		for (unsigned int i = 0; i < opks.nodes.size(); i++) {
			opk = opks.nodes[i];
			dbswznm->tblwznmmvectoritem->insertNewRec(NULL, refVec, (i+1), opk->sref, "", "", 0, opk->Title, opk->Comment);
		};
	};
};

void WznmGenSysvec::fillVecPreset(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
		) {
	ubigint refVec;

	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	ListWznmMPreset pres;
	WznmMPreset* pre = NULL;

	ListWznmJMPresetTitle pstJtits;
	WznmJMPresetTitle* pstJtit = NULL;

	// find VecXxxxVPreset
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VPreset", refVec)) {

		// one vector item for each presetting
		dbswznm->tblwznmmpreset->loadRstByVer(refWznmMVersion, false, pres);
		for (unsigned int i = 0; i < pres.nodes.size(); i++) {
			pre = pres.nodes[i];

			// num +2 due to pre-existing "void" item
			dbswznm->tblwznmmvectoritem->insertNewRec(&vit, refVec, i+2, pre->sref, "", "", 0, "", "");

			// presettings have localized titles
			dbswznm->tblwznmjmpresettitle->loadRstByPst(pre->ref, false, pstJtits);
			for (unsigned int j = 0; j < pstJtits.nodes.size(); j++) {
				pstJtit = pstJtits.nodes[j];

				dbswznm->tblwznmjmvectoritem->appendNewRecToRst(vitjs, &vitj, vit->ref, pstJtit->x1RefWznmMLocale, pstJtit->Title, "");

				if (pstJtit->x1RefWznmMLocale == refLcl) {
					vit->refJ = vitj->ref;
					vit->Title = vitj->Title;
					
					dbswznm->tblwznmmvectoritem->updateRec(vit);
				};
			};

			delete vit;
		};
	};
};

void WznmGenSysvec::fillVecStub(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	vector<ubigint> refs;
	ubigint refVec;

	ListWznmMStub stbs;
	WznmMStub* stb = NULL;

	// find VecXxxxVStub
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VStub", refVec)) {

		dbswznm->tblwznmmtable->loadRefsByVer(refWznmMVersion, false, refs);
		for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmstub->loadRstByTbl(refs[i], true, stbs);

		// one vector item for each stub
		for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
			stb = stbs.nodes[i];
			dbswznm->tblwznmmvectoritem->insertNewRec(NULL, refVec, (i+1), stb->sref, "", "", 0, "", "");
		};
	};
};

void WznmGenSysvec::fillVecTag(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	vector<ubigint> refs;
	vector<ubigint> refs2;

	ubigint ref;

	ubigint refVec;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	unsigned int vitcnt;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	set<string> srefs;

	vector<string> ss;
	string s;

	string prj;

	map<ubigint,string> tagTits;

	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Title FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(refWznmMVersion), prj);

	// find VecXxxxVTag
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VTag", refVec)) {
		vitcnt = 1;

		// - tag "error" as prerequisite for parse/import error alerts
		srefs.insert("error");

		// - tags "opsprep" and "opscpllast" as prerequisite for jobs with multiple stages
		srefs.insert("opsprep");
		srefs.insert("opscpllast");

		// - tags "yes" and "no" as prerequisite for queries
		srefs.insert("yes");
		srefs.insert("no");

		// - tags "general" and "always" as prerequisite for jump overrides
		srefs.insert("general");
		srefs.insert("always");

		// - collect all controls

		dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::VER, refWznmMVersion, false, cons);

		// card refs -> refs
		dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs2);
		for (unsigned int i = 0; i < refs2.size(); i++) {
			dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMCard WHERE mdlRefWznmMModule = " + to_string(refs2[i]), true, refs);
		};

		for (unsigned int i = 0; i < refs.size(); i++) {
			// card controls
			dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::CAR, refs[i], true, cons);

			// panel refs -> refs2
			dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(refs[i]), false, refs2);

			for (unsigned int j = 0; j < refs2.size(); j++) dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, refs2[j], true, cons);

			// dialog refs -> refs2
			dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(refs[i]), false, refs2);

			for (unsigned int j = 0; j < refs2.size(); j++) dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, refs2[j], true, cons);
		};

		// - collect unique tag sref's
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			StrMod::stringToVector(con->srefsWznmMTag, ss);
			for (unsigned int j = 0; j < ss.size(); j++) if (ss[j].length() > 0) srefs.insert(ss[j]);

			if (con->refWznmMFeed != 0) {
				if (dbswznm->loadStringBySQL("SELECT srefsWznmMTag FROM TblWznmMFeed WHERE ref = " + to_string(con->refWznmMFeed), s)) {

					StrMod::stringToVector(s, ss);
					for (unsigned int j = 0; j < ss.size(); j++) if (ss[j].length() > 0) srefs.insert(ss[j]);
				};
			};
		};

		// - copy tags into vector
		for (set<string>::iterator it = srefs.begin() ; it!=srefs.end() ; it++) {
			if ((*it).find('.') == string::npos) {
				dbswznm->tblwznmmvectoritem->appendNewRecToRst(vits, &vit, refVec, vitcnt++, *it, "", "", 0, "", "");

				Wznm::getTagtits(dbswznm, *it, "", prj, {}, refLcl, refsLcl, tagTits, false);

				if (!tagTits.empty()) {
					for (unsigned int j = 0; j < refsLcl.size(); j++) {
						ref = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refsLcl[j], tagTits[refsLcl[j]], "");

						if (refsLcl[j] == refLcl) {
							vit->refJ = ref;
							vit->Title = tagTits[refsLcl[j]];
							dbswznm->tblwznmmvectoritem->updateRec(vit);
						};
					};
				};
			};
		};
	};
};
// IP cust --- IEND


