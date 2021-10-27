/**
	* \file WznmGenDetui.cpp
	* Wznm operation processor - generate detailed user interface (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmGenDetui.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmGen;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmGenDetui
 ******************************************************************************/

DpchRetWznm* WznmGenDetui::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmGenDetui* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	vector<string> sesspsts;

	ListWznmMModule mdls;
	WznmMModule* mdl = NULL;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	ListWznmMControl cons;
	unsigned int connum;

	ubigint refWznmMPreset;

	WznmMTable* tbl = NULL;

	WznmMSubset* sbs = NULL;
	ubigint refSbs;

	ListWznmMTable inctbls;
	WznmMTable* inctbl = NULL;

	map<ubigint,string> incconds;
	map<ubigint,string> incsbsconds;

	vector<string> carrecpsts;
	vector<string> carsesspsts;
	vector<string> carpsts;
	bool always;
	bool never;

	map<ubigint,WznmMTable*> mtbs;
	map<ubigint,ubigint> refsPst;
	map<ubigint,string> sbsconds;

	uint pnlnum;
	string pnlsref;

	vector<ubigint> refsVec;
	WznmMVector* vec = NULL;

	vector<ubigint> refsRel;
	WznmMRelation* rel = NULL;

	WznmMTable* reltbl = NULL;
	WznmMTable* opptbl = NULL;

	WznmMRelation* suprel = NULL;
	WznmMRelation* opprel = NULL;

	bool toNotFr;

	bool relenum;

	Wznm::getVerlclrefs(dbswznm, refWznmMVersion, refLcl, refsLcl);

	Wznm::getSesspsts(dbswznm, refWznmMVersion, sesspsts);

	// --- standard panels for each card (and more for navigator card)
	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		pnlnum = 1;

		// -- headbar panel
		dbswznm->tblwznmmpanel->insertNewRec(NULL, VecWznmVMPanelBasetype::HEADBAR, car->ref, pnlnum++, VecWznmVMPanelRefTbl::VOID, 0, 0, "Pnl" + car->sref.substr(3) + "Headbar", false, "", "");

		// -- empty card basics (stage control, application menu)
		run_genCarbase(dbswznm, refWznmMVersion, car, cons, connum, refLcl, refsLcl);

		if ( (car->refIxVTbl == VecWznmVMCardRefTbl::VOID) && (car->sref.substr(3+4).compare("Nav") == 0) ) {
			dbswznm->tblwznmmmodule->loadRstBySQL("SELECT * FROM TblWznmMModule WHERE verRefWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY verNum ASC", false, mdls);

			// -- navigator card basics (application, session and card menus ; session termination alert)
			genCarnav(dbswznm, refWznmMVersion, Prjshort, sesspsts, car, cons, connum, mdls, refLcl, refsLcl);

			// -- navigator preset panel
			if (!sesspsts.empty()) genPnlprenav(dbswznm, refWznmMVersion, Prjshort, car, sesspsts, pnlnum++, refLcl, refsLcl);

			// -- navigator panels
			for (unsigned int j = 0; j < mdls.nodes.size(); j++) {
				mdl = mdls.nodes[j];
				if (mdl->sref.compare("Mdl" + Prjshort + "Nav") != 0) genPnlnav(dbswznm, refWznmMVersion, Prjshort, sesspsts, car, mdl, pnlnum++, refLcl, refsLcl);
			};

		} else if ( (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) ) {
			refSbs = 0;

			refWznmMPreset = 0;

			if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) {
				dbswznm->tblwznmmtable->loadRecByRef(car->refUref, &tbl);

				dbswznm->loadRefBySQL("SELECT refWznmMPreset FROM TblWznmMTable WHERE ref = " + to_string(tbl->ref), refWznmMPreset);

			} else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
				dbswznm->tblwznmmsubset->loadRecByRef(car->refUref, &sbs);
				refSbs = sbs->ref;

				dbswznm->tblwznmmtable->loadRecBySQL("SELECT * FROM TblWznmMTable WHERE ref = " + to_string(sbs->refWznmMTable), &tbl);

				dbswznm->loadRefBySQL("SELECT refWznmMPreset FROM TblWznmMSubset WHERE ref = " + to_string(sbs->ref), refWznmMPreset);
			};

			// -- find additional main tables which have inc or u1nsubinc relations ; ignore order for now ; also assume that the inc is not a subset - however the from part can have a subset condition
			Wznm::getCarincs(dbswznm, car, inctbls, incconds, incsbsconds);

			// -- find applicable refXxx presets
			Wznm::getCarrecpsts(dbswznm, car, carrecpsts);
			Wznm::getCarpsts(sesspsts, car, carsesspsts, carpsts, always, never);

			// -- table/subset-backed card basics (card menu)
			genCartbl(dbswznm, refWznmMVersion, Prjshort, car, cons, connum, refLcl, refsLcl);

			// -- list panel
			genPnllist(dbswznm, refWznmMVersion, Prjshort, car, tbl, refSbs, pnlnum++, refLcl, refsLcl);

			// -- record panel
			genPnlrec(dbswznm, refWznmMVersion, Prjshort, car, tbl, sbs, pnlnum++, refLcl, refsLcl);

			// -- detail panel
			genPnldetail(dbswznm, refWznmMVersion, Prjshort, sesspsts, car, tbl, refSbs, inctbls, incconds, incsbsconds, carrecpsts, carpsts, pnlnum++, refLcl, refsLcl);

			// -- klst panels
			refsVec.clear();
			mtbs.clear();
			refsPst.clear();
			sbsconds.clear();

			run_addKlsts(dbswznm, tbl, refSbs, refWznmMPreset, "", refsVec, mtbs, refsPst, sbsconds);

			// add klsts of inc'ed tables
			for (unsigned int j = 0; j < inctbls.nodes.size(); j++) {
				inctbl = inctbls.nodes[j];
				run_addKlsts(dbswznm, inctbl, 0, inctbl->refWznmMPreset, incconds[inctbl->ref], refsVec, mtbs, refsPst, sbsconds);
			};

			for (unsigned int j = 0; j < refsVec.size(); j++) {
				if (dbswznm->tblwznmmvector->loadRecByRef(refsVec[j], &vec)) {
					pnlsref = run_pnlsrefklst(dbswznm, car->sref, tbl, vec, mtbs);
					genPnlklst(dbswznm, refWznmMVersion, Prjshort, car, mtbs[vec->ref], refsPst[vec->ref], sbsconds[vec->ref], pnlnum++, pnlsref, vec, refLcl, refsLcl);

					delete vec;
				};
			};

			// -- aux panels
			refsRel.clear();
			mtbs.clear();
			refsPst.clear();
			sbsconds.clear();

			run_addRelauxs(dbswznm, tbl, refSbs, refWznmMPreset, "", refsRel, mtbs, refsPst, sbsconds);

			// add aux relations of inc'ed tables (spec as well)
			for (unsigned int j = 0; j < inctbls.nodes.size(); j++) {
				inctbl = inctbls.nodes[j];
				run_addRelauxs(dbswznm, inctbl, 0, inctbl->refWznmMPreset, incconds[inctbl->ref], refsRel, mtbs, refsPst, sbsconds);
			};

			for (unsigned int j = 0; j < refsRel.size(); j++) {
				if (dbswznm->tblwznmmrelation->loadRecByRef(refsRel[j], &rel)) {
					if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &reltbl)) {
						relenum = StrMod::srefInSrefs(rel->srefsKOption, "enum");

						// - generate valid panel sref depending on hook table

						// standard aux ex.: TblBrlyAMFlightWaypoint -> PnlBrlyFltAWaypoint
						// aux of inc ex.: TblBrlyAMFlightWaypoint -> PnlBrlyItnFltAWaypoint (Itn: itinerary)
						// aux of sup spec ex.: TblPlnrAMCalcPar -> PnlPlnrCliCalAPar (Cli: calculation item)

						pnlsref = "Pnl" + car->sref.substr(3);
						if (mtbs[rel->ref] != tbl) pnlsref += StrMod::cap(mtbs[rel->ref]->Short); // inc and sup spec
						pnlsref += "A" + reltbl->sref.substr(reltbl->sref.find(mtbs[rel->ref]->sref.substr(3+4+1)) + mtbs[rel->ref]->sref.substr(3+4+1).length());

						if (rel->ixVBasetype == VecWznmVMRelationBasetype::_1N) delete mtbs[rel->ref]; // sup spec

						genPnlaux(dbswznm, refWznmMVersion, Prjshort, car, refsPst[rel->ref], sbsconds[rel->ref], pnlnum++, pnlsref, rel, reltbl, relenum, refLcl, refsLcl);

						delete reltbl;
					};
					delete rel;
				};
			};

			// -- 1n panels
			refsRel.clear();
			mtbs.clear();
			refsPst.clear();
			sbsconds.clear();

			run_addRel1ns(dbswznm, tbl, refSbs, refWznmMPreset, "", refsRel, mtbs, refsPst, sbsconds);

			// add relations of inc'ed tables (spec as well)
			for (unsigned int j = 0; j < inctbls.nodes.size(); j++) {
				inctbl = inctbls.nodes[j];
				run_addRel1ns(dbswznm, inctbl, 0, inctbl->refWznmMPreset, incconds[inctbl->ref], refsRel, mtbs, refsPst, sbsconds);
			};

			for (unsigned int j = 0; j < refsRel.size(); j++) {
				if (dbswznm->tblwznmmrelation->loadRecByRef(refsRel[j], &rel)) {
					// load rel (1n/main) table ; only main tables result in a panel
					if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &reltbl)) {
						if (reltbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) {
							if ((rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1NSUB) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1NLSUB)) {
								// load super relation (no spec for universal types for now)
								if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &suprel)) {
									relenum = StrMod::srefInSrefs(suprel->srefsKOption, "enum");

									pnlsref = "Pnl" + car->sref.substr(3);
									if (mtbs[rel->ref] != tbl) pnlsref += StrMod::cap(mtbs[rel->ref]->Short);
									pnlsref += StrMod::cap(suprel->Prefix) + "1N" + reltbl->sref.substr(3+4+1);

									genPnl1n(dbswznm, refWznmMVersion, Prjshort, sesspsts, car, carrecpsts, carpsts, pnlnum++, rel, pnlsref, refsPst[rel->ref], sbsconds[rel->ref], reltbl, relenum, refLcl, refsLcl);
									delete suprel;
								};

							} else {
								relenum = StrMod::srefInSrefs(rel->srefsKOption, "enum");

								pnlsref = "Pnl" + car->sref.substr(3);
								if (mtbs[rel->ref] != tbl) pnlsref += StrMod::cap(mtbs[rel->ref]->Short);
								pnlsref += StrMod::cap(rel->Prefix) + "1N" + reltbl->sref.substr(3+4+1);

								genPnl1n(dbswznm, refWznmMVersion, Prjshort, sesspsts, car, carrecpsts, carpsts, pnlnum++, rel, pnlsref, refsPst[rel->ref], sbsconds[rel->ref], reltbl, relenum, refLcl, refsLcl);
							};
						};

						delete reltbl;
					};
					delete rel;
				};
			};

			// -- mn panels
			refsRel.clear();
			mtbs.clear();
			refsPst.clear();
			sbsconds.clear();

			run_addRelmns(dbswznm, tbl, refSbs, refWznmMPreset, "", refsRel, mtbs, refsPst, sbsconds);

			// add mn relations of inc'ed tables (no spec's for now)
			for (unsigned int j = 0; j < inctbls.nodes.size(); j++) {
				inctbl = inctbls.nodes[j];
				run_addRelmns(dbswznm, inctbl, 0, inctbl->refWznmMPreset, incconds[inctbl->ref], refsRel, mtbs, refsPst, sbsconds);
			};

			for (unsigned int j = 0; j < refsRel.size(); j++) {
				if (dbswznm->tblwznmmrelation->loadRecByRef(refsRel[j], &rel)) {
					toNotFr = (rel->supIxVSubrole	== VecWznmVMRelationSupSubrole::TO1N);

					if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &suprel)) {
						if (dbswznm->tblwznmmtable->loadRecByRef(suprel->refWznmMTable, &reltbl)) {
							opprel = NULL;
							if (toNotFr) dbswznm->tblwznmmrelation->loadRecBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(suprel->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N), &opprel);
							else dbswznm->tblwznmmrelation->loadRecBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(suprel->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::TO1N), &opprel);

							if (opprel) {
								if (dbswznm->tblwznmmtable->loadRecByRef(opprel->frRefWznmMTable, &opptbl)) {
									relenum = StrMod::srefInSrefs(rel->srefsKOption, "enum");

									pnlsref = "Pnl" + car->sref.substr(3);
									if (mtbs[rel->ref] != tbl) pnlsref += StrMod::cap(mtbs[rel->ref]->Short);
									pnlsref += StrMod::cap(suprel->Prefix) + StrMod::cap(rel->Prefix) + "MN" + opptbl->sref.substr(3+4+1);

									genPnlmn(dbswznm, refWznmMVersion, Prjshort, sesspsts, car, carrecpsts, carpsts, pnlnum++, rel, pnlsref, refsPst[rel->ref], sbsconds[rel->ref], opprel, reltbl, opptbl, relenum, refLcl, refsLcl);

									delete opptbl;
								};
								delete opprel;
							};
							delete reltbl;
						};
						delete suprel;
					};
					delete rel;
				};
			};

			if (tbl) {
				delete tbl;
				tbl = NULL;
			};
			if (sbs) {
				delete sbs;
				sbs = NULL;
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
WznmGenDetui::Ap::Ap() {
	success = false;
};

void WznmGenDetui::Ap::step(
			DbsWznm* dbswznm
			, const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const ubigint refPsttbl
			, vector<Ap*>& aps
		) {
	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;

	vector<unsigned int> icsRels;

	WznmMRelation* suprel = NULL;

	vector<unsigned int> icsAps;
	Ap* ap = NULL;

	// pursue affil relations
	step_collect(dbswznm, refWznmMTable, 0, VecWznmVMRelationBasetype::_1N, true, rels);
	step_collect(dbswznm, refWznmMTable, 0, VecWznmVMRelationBasetype::U1NSUB, false, rels);
	step_collect(dbswznm, refWznmMTable, 0, VecWznmVMRelationBasetype::L1N, true, rels);
	step_collect(dbswznm, refWznmMTable, 0, VecWznmVMRelationBasetype::LU1NSUB, false, rels);
	step_collect(dbswznm, refWznmMTable, 0, VecWznmVMRelationBasetype::LU1NLSUB, false, rels);
	step_collect(dbswznm, refWznmMTable, 0, VecWznmVMRelationBasetype::INC, false, rels);
	step_collect(dbswznm, refWznmMTable, 0, VecWznmVMRelationBasetype::U1NSUBINC, false, rels);

	if (refWznmMSubset != 0) {
		step_collect(dbswznm, refWznmMTable, refWznmMSubset, VecWznmVMRelationBasetype::_1N, true, rels);
		step_collect(dbswznm, refWznmMTable, refWznmMSubset, VecWznmVMRelationBasetype::U1NSUB, false, rels);
		step_collect(dbswznm, refWznmMTable, refWznmMSubset, VecWznmVMRelationBasetype::L1N, true, rels);
		step_collect(dbswznm, refWznmMTable, refWznmMSubset, VecWznmVMRelationBasetype::LU1NSUB, false, rels);
		step_collect(dbswznm, refWznmMTable, refWznmMSubset, VecWznmVMRelationBasetype::LU1NLSUB, false, rels);
		step_collect(dbswznm, refWznmMTable, refWznmMSubset, VecWznmVMRelationBasetype::INC, false, rels);
		step_collect(dbswznm, refWznmMTable, refWznmMSubset, VecWznmVMRelationBasetype::U1NSUBINC, false, rels);
	};

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (rel->frRefWznmMTable != rel->toRefWznmMTable) {
			if ((rel->ixVBasetype == VecWznmVMRelationBasetype::_1N) || (rel->ixVBasetype == VecWznmVMRelationBasetype::L1N)) {
				if (StrMod::srefInSrefs(rel->srefsKOption, "affil")) icsRels.push_back(i);
			} else {
				if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &suprel)) {
					if (StrMod::srefInSrefs(suprel->srefsKOption, "affil")) icsRels.push_back(i);
					delete suprel;
				};
			};
		};
	};

	// clone (icsRels.size()-1) times
	for (unsigned int i=1;i<icsRels.size(); i++) {
		ap = new Ap();
		*ap = *this;

		icsAps.push_back(aps.size());
		aps.push_back(ap);
	};

	// recurse through affil relations
	for (unsigned int i = 0; i < icsRels.size(); i++) {
		rel = rels.nodes[icsRels[i]];

		if (i == 0) ap = this;
		else ap = aps[icsAps[i-1]];

		ap->rels.nodes.push_back(new WznmMRelation(*rel));

		if (rel->frRefWznmMTable == refPsttbl) ap->success = true;
		else ap->step(dbswznm, rel->frRefWznmMTable, rel->frsRefWznmMSubset, refPsttbl, aps);
	};
};

void WznmGenDetui::Ap::step_collect(
			DbsWznm* dbswznm
			, const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const uint ixVBasetype
			, const bool supzero
			, ListWznmMRelation& rels
		) {
	string sqlstr;

	sqlstr = "SELECT TblWznmMRelation.* FROM TblWznmMRelation, TblWznmMTable WHERE TblWznmMTable.ref = TblWznmMRelation.frRefWznmMTable AND TblWznmMTable.ixVBasetype = " + to_string(VecWznmVMTableBasetype::MAIN)
				+ " AND TblWznmMRelation.ixVBasetype = " + to_string(ixVBasetype) + " AND TblWznmMRelation.toRefWznmMTable = " + to_string(refWznmMTable) + " AND TblWznmMRelation.tosRefWznmMSubset = " + to_string(refWznmMSubset);
	if (supzero) sqlstr += " AND TblWznmMRelation.supRefWznmMRelation = 0";

	dbswznm->tblwznmmrelation->loadRstBySQL(sqlstr, true, rels);
};

void WznmGenDetui::run_genCarbase(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, WznmMCard* car
			, ListWznmMControl& cons
			, unsigned int& connum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	WznmMControl* con = NULL;

	WznmMFeed* fed = NULL;
	WznmMVector* vec = NULL;

	ubigint supref;
	unsigned int supnum;

	vector<unsigned int> mitlens;

	string prjtit;
	unsigned int prjtitlen;

	unsigned int len;

	cons.clear();
	connum = 1;

	// -- stage control, associated feed and vector
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SGE, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::VOID,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Sge", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmfeed->insertNewRec(&fed, con->ref, VecWznmVMFeedSrcTbl::VEC, 0, "FeedF" + con->sref, "", "", "");

	con->refWznmMFeed = fed->ref;
	dbswznm->tblwznmmcontrol->updateRec(con);

	dbswznm->tblwznmmvector->insertNewRec(&vec, VecWznmVMVectorBasetype::LIN, refWznmMVersion, VecWznmVMVectorHkTbl::JOB, 0, 0, "VecV" + car->sref.substr(3) + "Sge", "", "noloc;notit;filfed");

	fed->srcUref = vec->ref;
	dbswznm->tblwznmmfeed->updateRec(fed);

	delete vec;
	delete fed;

	// -- application menu
	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Title FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(refWznmMVersion), prjtit);
	prjtitlen = StrMod::getCharcnt(prjtit);

	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MEN, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "MenApp", VecWznmVMControlSubtype::VOID, "", 0, prjtit, 0, 0, 0, "", "", "");
	supnum = 1;

	// menu caption width (corresponds to project title)
	dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "cptwidth", 0, to_string(prjtitlen*10+10));

	// - MenApp menu items
	mitlens.resize(refsLcl.size(), 0);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "MspApp1", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MIT, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MitAppAbt", VecWznmVMControlSubtype::VOID, "about", 0, "", 0, 0, 0, "", "", "cap;ddd");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		len = getTaglen(dbswznm, "about", "", refsLcl[i]) + prjtitlen + 4;
		if (len > mitlens[i]) mitlens[i] = len;
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MRL, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MrlAppHlp", VecWznmVMControlSubtype::VOID, "help", 0, "", 0, 0, 0, "", "", "cap;ddd");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		len = getTaglen(dbswznm, "help", "", refsLcl[i]) + prjtitlen + 4;
		if (len > mitlens[i]) mitlens[i] = len;
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "MspApp3", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, supref, "width", refsLcl[i], to_string(mitlens[i]*7+8));
};

string WznmGenDetui::run_pnlsrefklst(
			DbsWznm* dbswznm
			, const string& carsref
			, WznmMTable* tbl
			, WznmMVector* vec
			, map<ubigint, WznmMTable*>& mtbs
		) {
	string pnlsref;

	vector<unsigned int> caps;
	WznmMTable* tbl2 = NULL;

	// - example sref's:
	// no hook reference: KlstPlnrKCalcvar -> PnlPlnrCtpKCalcvar

	// non-aux hook reference: KlstFoodKMBakeryJam => PnlFoodBkrKJam
	// non-aux hook reference of inc: KlstFoodKMGroceryCat => PnlFoodBkrGrcKCat
	
	// aux hook reference: KlstFoodKAMBakeryIngrQty => PnlFoodBkrKIngrQty
	// aux hook reference of inc: KlstFoodKAMGroceryPackUnit => PnlFoodBkrGrcKPackUnit

	pnlsref = "Pnl" + carsref.substr(3);
	if (mtbs[vec->ref] != tbl) pnlsref += StrMod::cap(mtbs[vec->ref]->Short);
	pnlsref += "K";

	for (unsigned int k = 0; k < vec->sref.length();k++) if ((vec->sref[k] >= 0x41) && (vec->sref[k] <= 0x5A)) caps.push_back(k);

	if (caps.size() >= 2) {
		if (vec->hkUref == 0) {
			pnlsref += vec->sref.substr(caps[caps.size()-1]);

		} else {
			if (dbswznm->tblwznmmtable->loadRecByRef(vec->hkUref, &tbl2)) {
				if (tbl2->ixVBasetype == VecWznmVMTableBasetype::AUX) {
					pnlsref += vec->sref.substr(caps[caps.size()-2]);
				} else {
					pnlsref += vec->sref.substr(caps[caps.size()-1]);
				};

				delete tbl2;
			};
		};
	};

	return pnlsref;
};

void WznmGenDetui::run_addKlsts(
			DbsWznm* dbswznm
			, WznmMTable* tbl
			, const ubigint refSbs
			, const ubigint refPst
			, const string& cond
			, vector<ubigint>& refsVec
			, map<ubigint,WznmMTable*>& mtbs
			, map<ubigint,ubigint>& refsPst
			, map<ubigint,string>& sbsconds
		) {
	ListWznmRMTableMVector trvs;
	WznmRMTableMVector* trv = NULL;

	set<ubigint> refsSbsainb;
	set<ubigint> refsSbsbina;
	set<ubigint> refsSbsxsec;

	string sbscond;

	Wznm::getSbsrels(dbswznm, tbl->ref, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec);

	dbswznm->tblwznmrmtablemvector->loadRstBySQL("SELECT TblWznmRMTableMVector.* FROM TblWznmRMTableMVector, TblWznmMVector WHERE TblWznmRMTableMVector.refWznmMTable = " + to_string(tbl->ref)
				+ " AND TblWznmMVector.ref = TblWznmRMTableMVector.refWznmMVector ORDER BY TblWznmMVector.sref ASC", false, trvs);

	for (unsigned int i = 0; i < trvs.nodes.size(); i++) {
		trv = trvs.nodes[i];

		if (Wznm::getPnlconAvail(dbswznm, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec, tbl, trv->refWznmMSubset, sbscond)) {
			refsVec.push_back(trv->refWznmMVector);
			mtbs[trv->refWznmMVector] = tbl;
			refsPst[trv->refWznmMVector] = refPst;
			sbsconds[trv->refWznmMVector] = andConds(cond, sbscond);
		};
	};
};

void WznmGenDetui::run_addRelauxs(
			DbsWznm* dbswznm
			, WznmMTable* tbl
			, const ubigint refSbs
			, const ubigint refPst
			, const string& cond
			, vector<ubigint>& refsRel
			, map<ubigint,WznmMTable*>& mtbs
			, map<ubigint,ubigint>& refsPst
			, map<ubigint,string>& sbsconds
		) {
	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;

	WznmMTable* mtb = NULL;

	set<ubigint> refsSbsainb;
	set<ubigint> refsSbsbina;
	set<ubigint> refsSbsxsec;

	string sbscond;

	Wznm::getSbsrels(dbswznm, tbl->ref, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec);

	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::AUX) + " AND frRefWznmMTable = " + to_string(tbl->ref), false, rels);

	// add aux relations based on spec (basetype _1n, supIxVSubrole spec, super relation aux)
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT rel.* FROM TblWznmMRelation AS rel, TblWznmMRelation AS rel2 WHERE rel.supRefWznmMRelation = rel2.ref AND rel.frRefWznmMTable = "
				+ to_string(tbl->ref) + " AND rel.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1N) + " AND rel.supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SPEC)
				+ " AND rel2.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::AUX), true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (Wznm::getPnlconAvail(dbswznm, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec, tbl, rel->frsRefWznmMSubset, sbscond)) {
			refsRel.push_back(rel->ref);

			if (rel->ixVBasetype == VecWznmVMRelationBasetype::_1N) {
				dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMRelation WHERE TblWznmMTable.ref = TblWznmMRelation.frRefWznmMTable AND TblWznmMRelation.ref = "
							+ to_string(rel->supRefWznmMRelation), &mtb);
				mtbs[rel->ref] = mtb; // to be deleted in calling method

			} else mtbs[rel->ref] = tbl;

			refsPst[rel->ref] = refPst;
			sbsconds[rel->ref] = andConds(cond, sbscond);
		};
	};
};

void WznmGenDetui::run_addRel1ns(
			DbsWznm* dbswznm
			, WznmMTable* tbl
			, const ubigint refSbs
			, const ubigint refPst
			, const string& cond
			, vector<ubigint>& refsRel
			, map<ubigint,WznmMTable*>& mtbs
			, map<ubigint,ubigint>& refsPst
			, map<ubigint,string>& sbsconds
		) {
	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;

	set<ubigint> refsSbsainb;
	set<ubigint> refsSbsbina;
	set<ubigint> refsSbsxsec;

	string sbscond;

	Wznm::getSbsrels(dbswznm, tbl->ref, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec);

	// note that U1NSUBINC / U1NSUB11 do not yield a panel (1:1 relation)
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1N) + " AND supRefWznmMRelation = 0 AND frRefWznmMTable = " + to_string(tbl->ref), false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::H1N) + " AND frRefWznmMTable = " + to_string(tbl->ref), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::U1NSUB) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUB)
				+ " AND frRefWznmMTable = " + to_string(tbl->ref), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::L1N) + " AND supRefWznmMRelation = 0 AND frRefWznmMTable = " + to_string(tbl->ref), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::LU1NSUB) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUB)
				+ " AND frRefWznmMTable = " + to_string(tbl->ref), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::LU1NLSUB) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUBL)
				+ " AND frRefWznmMTable = " + to_string(tbl->ref), true, rels);

	// add relations based on spec (basetype _1n, supIxVSubrole spec, super relation _1n or l1n ; "to" table needs to be a main table - this constraint is handled on panel generation)
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT rel.* FROM TblWznmMRelation AS rel, TblWznmMRelation AS rel2 WHERE rel.supRefWznmMRelation = rel2.ref AND rel.frRefWznmMTable = "
				+ to_string(tbl->ref) + " AND rel.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1N) + " AND rel.supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SPEC)
				+ " AND rel2.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1N), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT rel.* FROM TblWznmMRelation AS rel, TblWznmMRelation AS rel2 WHERE rel.supRefWznmMRelation = rel2.ref AND rel.frRefWznmMTable = "
				+ to_string(tbl->ref) + " AND rel.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1N) + " AND rel.supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SPEC)
				+ " AND rel2.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::L1N), true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (Wznm::getPnlconAvail(dbswznm, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec, tbl, rel->frsRefWznmMSubset, sbscond)) {
			refsRel.push_back(rel->ref);
			mtbs[rel->ref] = tbl;
			refsPst[rel->ref] = refPst;
			sbsconds[rel->ref] = andConds(cond, sbscond);
		};
	};
};

void WznmGenDetui::run_addRelmns(
			DbsWznm* dbswznm
			, WznmMTable* tbl
			, const ubigint refSbs
			, const ubigint refPst
			, const string& cond
			, vector<ubigint>& refsRel
			, map<ubigint,WznmMTable*>& mtbs
			, map<ubigint,ubigint>& refsPst
			, map<ubigint,string>& sbsconds
		) {
	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;

	WznmMRelation* suprel = NULL;

	set<ubigint> refsSbsainb;
	set<ubigint> refsSbsbina;
	set<ubigint> refsSbsxsec;

	string sbscond;

	bool toNotFr;

	Wznm::getSbsrels(dbswznm, tbl->ref, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec);

	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N) + " AND frRefWznmMTable = " + to_string(tbl->ref), false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::TO1N) + " AND frRefWznmMTable = " + to_string(tbl->ref), true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &suprel)) {
			toNotFr = (suprel->toRefWznmMTable == tbl->ref);

			if (Wznm::getPnlconAvail(dbswznm, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec, tbl, (toNotFr) ? suprel->tosRefWznmMSubset : suprel->frsRefWznmMSubset, sbscond)) {
				refsRel.push_back(rel->ref);
				mtbs[rel->ref] = tbl;
				refsPst[rel->ref] = refPst;
				sbsconds[rel->ref] = andConds(cond, sbscond);
			};

			delete suprel;
		};
	};
};

void WznmGenDetui::genCarnav(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const vector<string>& sesspsts
			, WznmMCard* car
			, ListWznmMControl& cons
			, unsigned int& connum
			, ListWznmMModule& mdls
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	WznmMControl* con = NULL;

	WznmAMControlPar* cpa = NULL;

	WznmMControl* men = NULL;

	WznmMModule* mdl = NULL;

	ListWznmMCard mdlcars;
	WznmMCard* mdlcar = NULL;

	vector<string> carsesspsts;
	vector<string> carpsts;
	bool always, never;

	ubigint ref, supref;

	unsigned int supnum, mdlnum;

	unsigned int connummsp, supnummsp;

	vector<unsigned int> mitlens;

	string s, s2;

	unsigned int len;

	mitlens.resize(refsLcl.size(), 0);

	// -- anticipate loaini to be added to application menu lateron
	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		len = getTaglen(dbswznm, "loaini", "", refsLcl[i]) + 4;
		mitlens[i] = len*7+8;
	};

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->sref.compare("MenApp") == 0) {

			for (unsigned int j = 0; j < refsLcl.size(); j++) {
				if (dbswznm->tblwznmamcontrolpar->loadRecBySQL("SELECT * FROM TblWznmAMControlPar WHERE refWznmMControl = " + to_string(con->ref) + " AND x1SrefKKey = 'width' AND x2RefWznmMLocale = " + to_string(refsLcl[j]), &cpa)) {
					if (atoi(cpa->osrefKVal.c_str()) < ((int) mitlens[j])) {
						// update menu width
						cpa->osrefKVal = to_string(mitlens[j]);
						dbswznm->tblwznmamcontrolpar->updateRec(cpa);
					};

					delete cpa;
				};
			};

			break;
		};
	};

	// -- session menu
	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MEN, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "MenSes", VecWznmVMControlSubtype::VOID, "sess", 0, "", 0, 0, 0, "", "", "cap");
	supnum = 1;

	// menu caption width
	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "cptwidth", refsLcl[i], to_string(getTaglen(dbswznm, "sess", "", refsLcl[i])*8+10));
	};

	// - MenSes menu items

	// assume length 45 for distributed session stub
	for (unsigned int i = 0; i < mitlens.size(); i++) mitlens[i] = 45;

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "MspSes1", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MTX, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MtxSesSes1", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MTX, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MtxSesSes2", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MTX, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MtxSesSes3", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "MspSes2", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MIT, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MitSesSps", VecWznmVMControlSubtype::VOID, "suspsess", 0, "", 0, 0, 0, "stg" + StrMod::lc(Prjshort) + "appearance.suspsessEq(true)", "", "cap");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		len = getTaglen(dbswznm, "suspsess", "", refsLcl[i]);
		if (len > mitlens[i]) mitlens[i] = len;
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MIT, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MitSesTrm", VecWznmVMControlSubtype::VOID, "clsess", 0, "", 0, 0, 0, "", "", "cap");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		len = getTaglen(dbswznm, "clsess", "", refsLcl[i]);
		if (len > mitlens[i]) mitlens[i] = len;
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "MspSes3", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	// menu width
	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, supref, "width", refsLcl[i], to_string(mitlens[i]*7+8));
	};

	// -- card (navigation) menu
	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &men, VecWznmVMControlBasetype::MEN, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "MenCrd", VecWznmVMControlSubtype::VOID, "nav", 0, "", 0, 0, 0, "", "", "cap");
	supnum = 1;

	// menu caption width
	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "cptwidth", refsLcl[i], to_string(getTaglen(dbswznm, "nav", "", refsLcl[i])*9+10));
	};

	// - MenCrd menu items
	mdlnum = 1;
	for (unsigned int i = 0; i < mitlens.size(); i++) mitlens[i] = 0;

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		if (mdl->sref.compare("Mdl" + Prjshort + "Nav") != 0) {
			dbswznm->tblwznmmcard->loadRstByMdl(mdl->ref, false, mdlcars);

			// reserve spot for menu separator
			connummsp = connum++;
			supnummsp = supnum++;

			// not all module cards are accessible by menu
			s2 = "";

			for (unsigned int j = 0; j < mdlcars.nodes.size(); j++) {
				mdlcar = mdlcars.nodes[j];

				Wznm::getCarpsts(sesspsts, mdlcar, carsesspsts, carpsts, always, never);

				if (!never) {
					// menu item activation rule
					s = "";
					if (!always) {
						for (unsigned int k = 0; k < carsesspsts.size(); k++) {
							if (k != 0) s = s + "|";
							s = s + "pre." + carsesspsts[k] + "()";
						};
					};

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MIT, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
								VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MitCrd" + mdlcar->sref.substr(3+4), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "pre.ixCrdacc" + mdlcar->sref.substr(3+4) + "()", s, "");
					dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");

					// add to menu separator availability rule
					if (s2.length() != 0) s2 = s2 + "|";
					s2 = s2 + "MitCrd" + mdlcar->sref.substr(3+4) + "Avail()";

					for (unsigned int k = 0; k < refsLcl.size(); k++) {
						s = mdlcar->sref;

						if (dbswznm->tblwznmjmcardtitle->loadTitByCarLoc(mdlcar->ref, refsLcl[k], s) || (refsLcl[k] == refLcl)) {
							s = StrMod::cap(s) + " ...";

							ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[k], s);

							if (refsLcl[k] == refLcl) {
								con->refJTitle = ref;
								con->Title = s;
								dbswznm->tblwznmmcontrol->updateRec(con);
							};

							len = StrMod::getCharcnt(s);
							if (len > mitlens[k]) mitlens[k] = len;
						};
					};
				};
			};

			if (s2.length() == 0) {
				// menu separator not needed
				connum--;
				supnum--;

			} else {
				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connummsp, VecWznmVMControlHkSection::MBAR,
							VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnummsp, VecWznmVMControlScope::APP, 0, "MspCrd" + to_string(mdlnum++), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, s2, "", "");

				if (men->Avail.length() != 0) men->Avail = men->Avail + "|";
				men->Avail = men->Avail + con->sref + "Avail()";
			};
		};
	};

	if (men->Avail.length() != 0) dbswznm->tblwznmmcontrol->updateRec(men);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "MspCrd" + to_string(mdlnum), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	// menu width
	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, supref, "width", refsLcl[i], to_string(mitlens[i]*7+8));
	};
};

void WznmGenDetui::genPnlprenav(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, WznmMCard* car
			, const vector<string>& sesspsts
			, const uint pnlnum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	unsigned int connum = 1;

	ubigint supref;
	unsigned int supnum;

	WznmMPreset* pst;

	string s;

	// --- generate panel
	for (unsigned int i = 0; i < sesspsts.size(); i++) {
		if (i != 0) s = s + "|";
		s = s + "pre." + sesspsts[i] + "()";
	};

	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::HEADLINE, car->ref, pnlnum, VecWznmVMPanelRefTbl::VOID, 0, 0, "Pnl" + Prjshort + "NavPre", false, s, "");

	// -- controls per preset
	for (unsigned int i = 0; i < sesspsts.size(); i++) {
		if (dbswznm->tblwznmmpreset->loadRecBySQL("SELECT * FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Pre" + Prjshort + StrMod::cap(sesspsts[i]) + "'", &pst)) {
			ref = 0;

			if (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS) ref = getStbByReftblsbs(dbswznm, Prjshort, 0, pst->refUref, "Std");
			else if (pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) ref = getStbByReftblsbs(dbswznm, Prjshort, pst->refUref, 0, "Std");

			supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Txt" + sesspsts[i].substr(3), VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, ref, 0, "pre." + sesspsts[i] + "()", "", "");
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++,
						VecWznmVMControlScope::APP, 0, "Cpt" + sesspsts[i].substr(3), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "cap");

			for (unsigned int j = 0; j < refsLcl.size(); j++) {
				s = sesspsts[i];

				if (dbswznm->tblwznmjmpresettitle->loadTitByPstLoc(pst->ref, refsLcl[j], s) || (refsLcl[j] == refLcl)) {
					ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[j], s);

					if (refsLcl[j] == refLcl) {
						con->refJTitle = ref;
						con->Title = s;
						dbswznm->tblwznmmcontrol->updateRec(con);
					};
				};
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + sesspsts[i].substr(3) + "Remove", VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "icon");
			dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "stdicon", 0, "close");

			delete pst;
		};
	};
};

void WznmGenDetui::genPnlnav(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const vector<string>& sesspsts
			, WznmMCard* car
			, WznmMModule* mdl
			, const uint pnlnum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	unsigned int connum = 1;

	ubigint supref, supref2;
	unsigned int supnum, supnum2;

	ListWznmMCard mdlcars;
	WznmMCard* mdlcar = NULL;

	WznmJMModule* mdj = NULL;

	vector<string> carsesspsts;
	vector<string> carpsts;
	bool always, never;

	string s;

	dbswznm->tblwznmmcard->loadRstByMdl(mdl->ref, false, mdlcars);

	// --- generate panel
	s = "";
	for (unsigned int j = 0; j < mdlcars.nodes.size(); j++) {
		mdlcar = mdlcars.nodes[j];

		if (j != 0) s = s + "|";
		s = s + "pre.ixCrdacc" + mdlcar->sref.substr(3+4) + "()";
	};

	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::FORM, car->ref, pnlnum, VecWznmVMPanelRefTbl::VOID, 0, 0, "Pnl" + Prjshort + "Nav" + mdl->sref.substr(3+4), false, s, "");

	// -- basic controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		mdj = NULL;
		s = mdl->sref;

		if (dbswznm->tblwznmjmmodule->loadRecByMdlLoc(mdl->ref, refsLcl[i], &mdj) || (refsLcl[i] == refLcl)) {
			if (mdj) s = StrMod::cap(mdj->Title);

			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};

			if (mdj) delete mdj;
		};
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	// -- controls per card
	for (unsigned int i = 0; i < mdlcars.nodes.size(); i++) {
		mdlcar = mdlcars.nodes[i];

		Wznm::getCarpsts(sesspsts, mdlcar, carsesspsts, carpsts, always, never);

		s = "";
		if (!always) {
			for (unsigned int j = 0; j < carsesspsts.size(); j++) {
				if (j != 0) s = s + "|";
				s = s + "pre." + carsesspsts[j] + "()";
			};
		};

		if ((mdlcar->refIxVTbl == VecWznmVMCardRefTbl::VOID) && !never) {
			// BUT_CLUST: ButNewcrd {Cpt}
			supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "But" + mdlcar->sref.substr(3+4) + "Newcrd", VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "pre.ixCrdacc" + mdlcar->sref.substr(3+4) + "()", s, "icon");
			supnum = 1;

			dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + mdlcar->sref.substr(3+4), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnlnav_cjtcar(dbswznm, con, mdlcar, refLcl, refsLcl);

		} else if ( (mdlcar->refIxVTbl == VecWznmVMCardRefTbl::SBS) || (mdlcar->refIxVTbl == VecWznmVMCardRefTbl::TBL) ) {
			// LST_NOALT: Lst {Lsb, Cpt {ButExpand, ButCollapse}, (alt: none), ButView, ButNewcrd}
			ref = 0;

			if (mdlcar->refIxVTbl == VecWznmVMCardRefTbl::SBS) ref = getStbByReftblsbs(dbswznm, Prjshort, 0, mdlcar->refUref, "Std");
			else if (mdlcar->refIxVTbl == VecWznmVMCardRefTbl::TBL) ref = getStbByReftblsbs(dbswznm, Prjshort, mdlcar->refUref, 0, "Std");

			supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::LST, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Lst" + mdlcar->sref.substr(3+4), VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, ref, 0, "pre.ixCrdacc" + mdlcar->sref.substr(3+4) + "()", "", "");
			supnum = 1;

			ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, con->ref, VecWznmVMFeedSrcTbl::VOID, 0, "FeedF" + con->sref, "", "", "");
			con->refWznmMFeed = ref;
			dbswznm->tblwznmmcontrol->updateRec(con);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::LSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Lsb" + mdlcar->sref.substr(3+4), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			supref2 = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + mdlcar->sref.substr(3+4), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			supnum2 = 1;

			genPnlnav_cjtcar(dbswznm, con, mdlcar, refLcl, refsLcl);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supref2, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + mdlcar->sref.substr(3+4) + "Expand", VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "icon");

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supref2, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + mdlcar->sref.substr(3+4) + "Collapse", VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "icon");

			// ButView
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + mdlcar->sref.substr(3+4) + "View", VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "Lst" + mdlcar->sref.substr(3+4) + ".sel()", "icon");
			dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");

			if (!never) {
				// ButNewcrd
				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
							VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + mdlcar->sref.substr(3+4) + "Newcrd", VecWznmVMControlSubtype::VOID,
							"", 0, "", 0, 0, 0, "", s, "icon");
				dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");
			};
		};
	};

	delete pnl;
};

void WznmGenDetui::genPnlnav_cjtcar(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMCard* car
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		s = car->sref;

		if (dbswznm->tblwznmjmcardtitle->loadTitByCarLoc(car->ref, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

void WznmGenDetui::genCartbl(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, WznmMCard* car
			, ListWznmMControl& cons
			, unsigned int& connum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	WznmMControl* con = NULL;

	ubigint supref;
	unsigned int supnum;

	vector<unsigned int> mitlens;

	ostringstream str;
	string s;

	unsigned int len;

	mitlens.resize(refsLcl.size(), 0);

	// -- card menu
	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MEN, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "MenCrd", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
	supnum = 1;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (getCarstrSng(dbswznm, car, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};

			// menu caption width
			dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "cptwidth", refsLcl[i], to_string(StrMod::getCharcnt(s)*9+10));
		};
	};

	// - MenCrd menu items

	// assume length 45 for stub
	for (unsigned int i = 0; i < mitlens.size(); i++) mitlens[i] = 45;

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "MspCrd2", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	ref = 0;

	if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) ref = getStbByReftblsbs(dbswznm, Prjshort, 0, car->refUref, "Std");
	else if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) ref = getStbByReftblsbs(dbswznm, Prjshort, car->refUref, 0, "Std");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MTX, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::MBAR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "MtxCrd" + car->sref.substr(3+4), VecWznmVMControlSubtype::VOID, "", 0, "", 0, ref, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (getCarstrSng(dbswznm, car, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = "(" + s + ")";
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};

			len = StrMod::getCharcnt(s);
			if (len > mitlens[i]) mitlens[i] = len;
		};
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, car->ref, connum++, VecWznmVMControlHkSection::CONT,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "MspCrd3", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	// menu width
	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, supref, "width", refsLcl[i], to_string(mitlens[i]*7+8));
	};
};

void WznmGenDetui::genPnllist(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, WznmMCard* car
			, WznmMTable* cartbl
			, const ubigint refCarsbs
			, const uint pnlnum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	// A all routes to card's possible preset's (distinct branches)
	// B filter for each filter'able tco (implying panel preset's)
	// C QSelect if grp/own present in main table
	// D jovr for each of the main table's jump tables (added manually in IexWznmUix)

	string sqlstr;
	ubigint ref;

	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	ubigint supref;
	unsigned int supnum;

	WznmMFeed* fed = NULL;
	WznmMVector* vec = NULL;

	WznmMQuery* qry = NULL;

	ListWznmRMQueryMTable qryRtbls;
	WznmRMQueryMTable* qryRtbl = NULL;

	WznmMSubset* sbs = NULL;

	ListWznmMTablecol tcos;
	map<string,WznmMTablecol*> shortsTcos;
	WznmMTablecol* tco = NULL;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	Expr expr;

	vector<ubigint> refsPst;
	ubigint refPst;

	vector<ubigint> refsPsttbl;
	ubigint refPsttbl;

	vector<Ap*> aps;
	Ap* ap = NULL;

	set<ubigint> refsSbsainb;
	set<ubigint> refsSbsbina;
	set<ubigint> refsSbsxsec;

	string sbscond;

	uint ixWznmWArgtype;

	ubigint refQmd;

	WznmMRelation* rel = NULL;
	WznmMRelation* rel2 = NULL;

	WznmMTable* tbl = NULL;

	WznmMTable* fromtbl = NULL;
	WznmMTable* totbl = NULL;

	WznmMRelation* auxprefrel = NULL;

	bool toNotFr;

	bool makeqco;
	bool makecon;

	unsigned int qmdnum = 1;
	unsigned int qconum = 1;
	unsigned int connum = 1;
	unsigned int qacnum = 1;

	uint opt;

	bool hasgrp;
	bool accgrpreg, accnogoall;

	bool idx;

	string Clause;

	string s;

	bool found;

	// --- applicable table-based preset's according to card activation rule (no specific order)
	if (expr.tokenize(car->Active)) if (expr.parse()) if (expr.root) genPnllist_collectPsts(dbswznm, refWznmMVersion, Prjshort, expr.root, refsPst, refsPsttbl);

	// --- generate panel
	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::LIST, car->ref, pnlnum, VecWznmVMPanelRefTbl::TBL, cartbl->ref, 0, "Pnl" + car->sref.substr(3) + "List", false, "", "");

	// -- basic controls

	// panel caption
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (getCarstrPl(dbswznm, car, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);

			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};

	if (refsPst.size() > 0) {
		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "TxtFor", VecWznmVMControlSubtype::VOID, "for", 0, "", 0, 0, 0, "", "", "");

		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "TxtPre", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

		for (unsigned int i = 0; i < refsPst.size(); i++) {
			refPst = refsPst[i];
			refPsttbl = refsPsttbl[i];

			if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMStub WHERE refWznmMTable = " + to_string(refPsttbl) + " AND refWznmMSubset = 0 AND sref LIKE 'Stub%Std'", ref))
						dbswznm->tblwznmjmcontrol->insertNewRec(NULL, con->ref, 0, refPst, ref, 0);
		};
	};

	// side buttons
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	// header controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButClipboard", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtRecord", VecWznmVMControlSubtype::VOID, "rec;emplong", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButNew", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDelete", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "sel()", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButFilter", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon;onoff");

	// table control
	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TBL, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Tbl", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
	supnum = 1;

	// table order control, associated feed and vector
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TOS, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tos", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmfeed->insertNewRec(&fed, con->ref, VecWznmVMFeedSrcTbl::VEC, 0, "FeedF" + con->sref, "", "", "");

	con->refWznmMFeed = fed->ref;
	dbswznm->tblwznmmcontrol->updateRec(con);

	// hook will be query job, not panel job (taken care of in GenSysvec)
	dbswznm->tblwznmmvector->insertNewRec(&vec, VecWznmVMVectorBasetype::LIN, refWznmMVersion, VecWznmVMVectorHkTbl::JOB, 0, 0, "VecVQry" + pnl->sref.substr(3) + "Ord", "", "noloc;notit;filfed");

	fed->srcUref = vec->ref;
	dbswznm->tblwznmmfeed->updateRec(fed);

	delete vec;
	delete fed;

	// table row selector control
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TRS, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Trs", VecWznmVMControlSubtype::VOID, "goto", 0, "", 0, 0, 0, "", "", "cap;ddd");

	// table scroll bar control
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Tsb", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	// footer controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtShowing", VecWznmVMControlSubtype::VOID, "showlong;emplong", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CSI, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "CsiQst", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VQrystate'", ref);
	dbswznm->tblwznmmfeed->insertNewRec(&fed, con->ref, VecWznmVMFeedSrcTbl::VEC, ref, "FeedF" + con->sref, "mnr.ong;ood.red;slm.yel;utd.grn", "", "");

	con->refWznmMFeed = fed->ref;
	dbswznm->tblwznmmcontrol->updateRec(con);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButRefresh", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	// --- generate query
	dbswznm->tblwznmmquery->insertNewRec(&qry, (refsPst.size() > 0) ? VecWznmVMQueryBasetype::MULTBRA : VecWznmVMQueryBasetype::STD, refWznmMVersion, 0,
				VecWznmVMQuerySupSubrole::VOID, 0, 0, 0, 0, "Qry" + pnl->sref.substr(3), true, 0, "", "");

	dbswznm->tblwznmrmquerymtable->appendNewRecToRst(qryRtbls, &qryRtbl, qry->ref, cartbl->ref, true, "");

	qry->refRTable = qryRtbl->ref;
	qry->refWznmMTable = cartbl->ref;
	dbswznm->tblwznmmquery->updateRec(qry);

	dbswznm->tblwznmrmpanelmquery->insertNewRec(NULL, pnl->ref, qry->ref);

	// -- qref, jref and jnum
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, NULL, VecWznmVMQuerycolBasetype::QIDREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "qref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, NULL, VecWznmVMQuerycolBasetype::QJREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, NULL, VecWznmVMQuerycolBasetype::QJENUM, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jnum", "", 0);

	// -- subset filter
	if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) if (dbswznm->tblwznmmsubset->loadRecByRef(car->refUref, &sbs)) {
		if (expr.tokenize(sbs->Cond)) if (expr.parse()) if (expr.root) {
			dbswznm->tblwznmmtablecol->loadRstBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(cartbl->ref), false, tcos);
			for (unsigned int i = 0; i < tcos.nodes.size(); i++) shortsTcos[tcos.nodes[i]->Short] = tcos.nodes[i];

			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::EQN, genPnllist_getSbsevalsql(dbswznm, cartbl, tcos, shortsTcos, expr.root, true), 0, 0, 0);
		};

		delete sbs;
	};

	// --- query columns, controls, filters and order directives for table columns
	dbswznm->tblwznmmtablecol->loadRstBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(cartbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::IDREF), false, tcos);
	dbswznm->tblwznmmtablecol->loadRstBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(cartbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::GRP), true, tcos);
	dbswznm->tblwznmmtablecol->loadRstBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(cartbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::OWN), true, tcos);
	dbswznm->tblwznmmtablecol->loadRstBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(cartbl->ref) + " AND ixVBasetype <> " + to_string(VecWznmVMTablecolBasetype::IDREF)
				+ " AND ixVBasetype <> " + to_string(VecWznmVMTablecolBasetype::GRP) + " AND ixVBasetype <> " + to_string(VecWznmVMTablecolBasetype::OWN) + " AND Principal = 1 ORDER BY Eponymous DESC, tblNum ASC",
				true, tcos);

	// -- group/owner
	hasgrp = false;
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (tco->ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
			hasgrp = true;
			break;
		};
	};

	if (hasgrp) {
		accgrpreg = false;
		accnogoall = false;

		if (dbswznm->loadUintBySQL("SELECT ixWOption FROM TblWznmMVersion WHERE ref = " + to_string(refWznmMVersion), opt)) {
			accgrpreg = (opt & VecWznmWMVersionOption::ACCGRPREG);
			accnogoall = (opt & VecWznmWMVersionOption::ACCNOGOALL);
		};

		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "QSelect'", ref)) {
			dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, qry->ref, ref, false, "");

			if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Pre" + Prjshort + "JrefSess'", ref)) {
				dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::PRE, "Tbl" + Prjshort + "QSelect.jref = &pre;", ref, 0, 0);

				// PreXxxxNoadm not needed here but for optional query clause below
				ref = 0;
				if (!accgrpreg) dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Pre" + Prjshort + "Noadm'", ref);
				dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::EQN, cartbl->sref + ".grp = Tbl" + Prjshort + "QSelect.ref", ref, 0, 0);
			};
		};

		if (!accgrpreg) {
			if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Pre" + Prjshort + "Owner'", ref)) {
				if (accnogoall) s = "\" + [preNoadm,preOwner](){if (preNoadm) return(\"(" + cartbl->sref + ".own = &pre; OR " + cartbl->sref + ".own = 0)\"); else return(string(\"1\"));}() + \"";
				else s = "\" + [preNoadm,preOwner](){if (preNoadm) return(\"" + cartbl->sref + ".own = &pre;\"); else return(string(\"1\"));}() + \"";

				dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::PRE, s, ref, 0, 0);
			};
		};
	};

	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (tco->refWznmMSubset == 0) sbscond = "";
		else if (!Wznm::getPnlconAvail(dbswznm, refCarsbs, refsSbsainb, refsSbsbina, refsSbsxsec, cartbl, tco->refWznmMSubset, sbscond)) continue;

		if (tco->refWznmMRelation != 0) dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel);

		idx = StrMod::srefInSrefs(tco->srefsKOption, "idx");

		ixWznmWArgtype = 0;

		if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

			ixWznmWArgtype = VecWznmWArgtype::SREF;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
				else genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				if (idx) ixWznmWArgtype = VecWznmWArgtype::SREF;

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
				else genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				if (idx) ixWznmWArgtype = VecWznmWArgtype::SREF;

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTITS, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tits" + StrMod::cap(tco->sref), tco->Short + "2", 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
				else genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				if (idx) ixWznmWArgtype = VecWznmWArgtype::SREF;
			};

		} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && rel) {
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) {
				toNotFr = ( ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) );

				if (toNotFr) makeqco = ((rel->frsRefWznmMSubset == 0) || (refCarsbs == rel->frsRefWznmMSubset));
				else makeqco = ((rel->tosRefWznmMSubset == 0) || (refCarsbs == rel->tosRefWznmMSubset));

				if (makeqco) {
					dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
								qry->ref, qconum++, tco->ref, tco->sref, "", 0);

					makecon = false;

					if (rel->ixVBasetype == VecWznmVMRelationBasetype::_1N) {
						if (rel->supRefWznmMRelation == 0) {
							makecon = true;
							ixWznmWArgtype = VecWznmWArgtype::REF;

						} else {
							// look at super relation
							if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &rel2)) {
								if ((rel2->ixVBasetype == VecWznmVMRelationBasetype::_1N) && ((rel->supIxVSubrole == VecWznmVMRelationSupSubrole::MOD) || (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::SPEC))) {
									makecon = true;
									ixWznmWArgtype = VecWznmWArgtype::REF;
								} else if ((rel2->ixVBasetype == VecWznmVMRelationBasetype::MNPREF) && (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::MN1N)) {
									makecon = true;
									ixWznmWArgtype = VecWznmWArgtype::REF;
								};

								delete rel2;
							};
						};

					} else if ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) || (rel->ixVBasetype == VecWznmVMRelationBasetype::_1NPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::DRVSUB)
								|| (rel->ixVBasetype == VecWznmVMRelationBasetype::H1N) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBINC)
								|| (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) || (rel->ixVBasetype == VecWznmVMRelationBasetype::L1N)) {
						makecon = true;
						ixWznmWArgtype = VecWznmWArgtype::REF;
					};

					if (makecon) {
						tbl = NULL;

						if (toNotFr) dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &tbl);
						else dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl);

						if (tbl) {
							dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
										qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, getStbByReftblsbs(dbswznm, Prjshort, tbl->ref, 0, "Std"));

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
										VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

							genPnltbl_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

							delete tbl;
						};
					};
				};

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) {
				if ((rel->tosRefWznmMSubset == 0) || (refCarsbs == rel->tosRefWznmMSubset)) {
					dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
								qry->ref, qconum++, tco->ref, tco->sref, "", 0);

					dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
								qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, 0);
					
					addQcostbuniv(dbswznm, Prjshort, qco->ref, tcos, tco);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
								VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

					genPnltbl_cjtreluniv(dbswznm, con, tco, refLcl, refsLcl);

					ixWznmWArgtype = VecWznmWArgtype::REF;
				};

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) {
				if (rel->ixVBasetype == VecWznmVMRelationBasetype::AUXPREF) {
					auxprefrel = new WznmMRelation(*rel);
				};

//			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) {
			};

//		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) {
				con = NULL;

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VSREF, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "sref" + StrMod::cap(tco->sref), tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
				else genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				if (dbswznm->loadStringBySQL("SELECT srefsKOption FROM TblWznmMVector WHERE ref = " + to_string(tco->fctUref), s)) {
					if (!StrMod::srefInSrefs(s, "notit")) {
						dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
									qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);

						if (con) {
							con->refUref = qco->ref;
							dbswznm->tblwznmmcontrol->updateRec(con);
						};
					};
				};

				if (idx) ixWznmWArgtype = VecWznmWArgtype::IX;

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VSREFS, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "srefs" + StrMod::cap(tco->sref), tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
				else genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				if (dbswznm->loadStringBySQL("SELECT srefsKOption FROM TblWznmMVector WHERE ref = " + to_string(tco->fctUref), s)) {
					if (!StrMod::srefInSrefs(s, "notit")) {
						dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTITS, VecWznmWMQuerycolOccurrence::XML,
									qry->ref, qconum++, tco->ref, "tits" + StrMod::cap(tco->sref), tco->Short + "2", 0);
					};
				};

				if (idx) ixWznmWArgtype = VecWznmWArgtype::IX;
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

			ixWznmWArgtype = VecWznmWArgtype::SREF;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

			dbswznm->loadRefBySQL("SELECT TblWznmMStub.ref FROM TblWznmMStub, TblWznmMTable WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = "
						+ to_string(refWznmMVersion) + " AND TblWznmMStub.sref = 'Stub" + Prjshort + "Group'", ref);

			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
						qry->ref, qconum++, tco->ref, "stubGrp", tco->Short, ref);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoGrp", VecWznmVMControlSubtype::VOID, "grp", 0, "", 0, 0, 0, "", "", "cap");

			ixWznmWArgtype = VecWznmWArgtype::REF;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

			dbswznm->loadRefBySQL("SELECT TblWznmMStub.ref FROM TblWznmMStub, TblWznmMTable WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = "
						+ to_string(refWznmMVersion) + " AND TblWznmMStub.sref = 'Stub" + Prjshort + "Owner'", ref);

			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
						qry->ref, qconum++, tco->ref, "stubOwn", tco->Short, ref);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoOwn", VecWznmVMControlSubtype::VOID, "own", 0, "", 0, 0, 0, "", "", "cap");

			ixWznmWArgtype = VecWznmWArgtype::REF;

//		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
//		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::LVL) {

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

			if (idx) ixWznmWArgtype = VecWznmWArgtype::INTVAL;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

			if (idx) ixWznmWArgtype = VecWznmWArgtype::DBLVAL;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::YESNO, VecWznmWMQuerycolOccurrence::XML,
						qry->ref, qconum++, tco->ref, "yesno" + StrMod::cap(tco->sref), tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

			if (idx) ixWznmWArgtype = VecWznmWArgtype::BOOLVAL;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
			if ((tco->ixVSubtype == VecWznmVMTablecolSubtype::TXTLONG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::TXTBASE64)) {
			} else {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
				else genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

				if (idx) ixWznmWArgtype = VecWznmWArgtype::TXTVAL;
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMDATE, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMTIME, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMSTAMP, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMUSTAMP, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnltbl_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

			if (idx) ixWznmWArgtype = VecWznmWArgtype::INTVAL;
//		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
		};

		if (ixWznmWArgtype != 0) {
			// - filter preset
			refPst = dbswznm->tblwznmmpreset->insertNewRec(NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL,
						"Pre" + pnl->sref.substr(3) + "." + tco->Short, ixWznmWArgtype, 0, "");

			refQmd = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::FILT, qry->ref, qmdnum++, refPst, VecWznmVMQuerymodRefTbl::TCO, tco->ref, "");

			if (ixWznmWArgtype == VecWznmWArgtype::IX) {
				if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND)) {
					Clause = "(" + cartbl->sref + "." + tco->sref + " & &pre;) <> 0";
				} else {
					Clause = cartbl->sref + "." + tco->sref + " = &pre;";
				};

			} else if (ixWznmWArgtype == VecWznmWArgtype::SREF) {
				if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT)) {
					Clause = cartbl->sref + "." + tco->sref + " LIKE '%&pre;%'";
				} else {
					Clause = cartbl->sref + "." + tco->sref + " = '&pre;'";
				};

			} else if (ixWznmWArgtype == VecWznmWArgtype::TXTVAL) {
				Clause = cartbl->sref + "." + tco->sref + " LIKE '&pre;'";

			} else {
				// REF, INTVAL, DBLVAL, BOOLVAL
				Clause = cartbl->sref + "." + tco->sref + " = &pre;";
			};

			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, refQmd, VecWznmVAMQueryClauseBasetype::PRE, Clause, refPst, 0, 0);

			// - order directive
			genPnltbl_qao(dbswznm, qry, cartbl->sref, tco);
		};

		if (auxprefrel && !rel) {
			delete auxprefrel;
			auxprefrel = NULL;
		} else if (auxprefrel && rel) if (auxprefrel->ref != rel->ref) {
			delete auxprefrel;
			auxprefrel = NULL;
		};

		if (rel) {
			delete rel;
			rel = NULL;
		};
	};

	// -- affiliation paths for each preset
	for (unsigned int i = 0; i < refsPst.size(); i++) {
		refPst = refsPst[i];
		refPsttbl = refsPsttbl[i];

		for (unsigned int j = 0; j < aps.size(); j++) delete aps[j];
		aps.resize(0);

		ap = new Ap();
		aps.push_back(ap);

		ap->step(dbswznm, cartbl->ref, refCarsbs, refPsttbl, aps);

		for (unsigned int j = 0; j < aps.size(); j++) {
			ap = aps[j];

			if (ap->success) {
				// new branch
				refQmd = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::BRA, qry->ref, qmdnum++, refPst, VecWznmVMQuerymodRefTbl::VOID, 0, "");

				// associated tables for branch
				for (unsigned int k=0;(k+1)<ap->rels.nodes.size(); k++) {
					rel = ap->rels.nodes[k];

					found = false;

					// tables to be included
					for (unsigned int l = 0; l < qryRtbls.nodes.size(); l++) {
						qryRtbl = qryRtbls.nodes[l];

						if (qryRtbl->refWznmMTable == rel->frRefWznmMTable) {
							found = true;
							break;
						};
					};

					if (!found) dbswznm->tblwznmrmquerymtable->appendNewRecToRst(qryRtbls, &qryRtbl, qry->ref, rel->frRefWznmMTable, false, "");

					dbswznm->tblwznmtmquerymodmquery->insertNewRec(NULL, refQmd, qryRtbl->ref);
				};

				// query clauses for branch
				for (unsigned int k = 0; k < ap->rels.nodes.size(); k++) {
					rel = ap->rels.nodes[k];

					if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &fromtbl)) {
						if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &totbl)) {

							if ((rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1NSUB) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1NLSUB)) {
								// tco for table of reference (u1n)
								if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(rel->toRefWznmMTable) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF)
											+ " AND refWznmMRelation = " + to_string(rel->supRefWznmMRelation) + " AND sref LIKE '%VTbl'", &tco)) {

									// vit corresponding to rel table
									if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(tco->fctUref) + " AND sref = '" + rel->Prefix + "'", ref)) {
										dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, refQmd, VecWznmVAMQueryClauseBasetype::VIT, totbl->sref + "." + tco->sref + " = &vit;", 0, tco->fctUref, ref);
									};

									delete tco;
								};
							};

							// reference tco
							if ((rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1NSUB) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1NLSUB)) {
								sqlstr = "SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(rel->toRefWznmMTable) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF)
											+ " AND refWznmMRelation = " + to_string(rel->supRefWznmMRelation);
							} else {
								sqlstr = "SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(rel->toRefWznmMTable) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF)
											+ " AND refWznmMRelation = " + to_string(rel->ref);
							};

							if (dbswznm->tblwznmmtablecol->loadRecBySQL(sqlstr, &tco)) {
								if ((k+1) == ap->rels.nodes.size()) {
									// final relation: preset
									dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, refQmd, VecWznmVAMQueryClauseBasetype::PRE, totbl->sref + "." + tco->sref + " = &pre;", refPst, 0, 0);

								} else {
									dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, refQmd, VecWznmVAMQueryClauseBasetype::EQN, totbl->sref + "." + tco->sref + " = " + fromtbl->sref + ".ref", 0, 0, 0);
								};

								delete tco;
							};

							delete totbl;
						};

						delete fromtbl;
					};
				};
			};
		};
	};
	
	delete qry;
	delete pnl;
};

void WznmGenDetui::genPnllist_collectPsts(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, Expr::Node* node
			, vector<ubigint>& refsPst
			, vector<ubigint>& refsPsttbl
		) {
	WznmMPreset* pst = NULL;

	ubigint refPsttbl;

	if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
// MISSING: distinction between "less" and "more"
// e.g. "pre.refPnl() > pre.refDlg() > pre.refCar() > pre.refVer()"
// is interpreted as pre.refPnl() > (pre.refDlg() > (pre.refCar() > pre.refVer()))
// MORE
//  pre.refPnl
//  MORE
//   pre.refDlg
//   MORE
//    pre.refCar
//    pre.refVer
// (result is correct as long as only more's are used)
		if ((node->key.find("pre.") == 0) && (node->key.length() > 4) && (node->key.substr(4).compare("void") != 0)) {

			if (dbswznm->tblwznmmpreset->loadRecBySQL("SELECT * FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Pre" + Prjshort + StrMod::cap(node->key.substr(4)) + "'", &pst)) {
				refPsttbl = 0;

				if (pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) refPsttbl = pst->refUref;
				else if (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS) dbswznm->loadRefBySQL("SELECT refWznmMTable FROM TblWznmMSubset WHERE ref = " + to_string(pst->refUref), refPsttbl);

				if (refPsttbl != 0) {
					refsPst.push_back(pst->ref);
					refsPsttbl.push_back(refPsttbl);
				};

				delete pst;
			};
		};
	};

	for (unsigned int i = 0; i < node->subs.size(); i++) genPnllist_collectPsts(dbswznm, refWznmMVersion, Prjshort, node->subs[i], refsPst, refsPsttbl);
};

string WznmGenDetui::genPnllist_getSbsevalsql(
			DbsWznm* dbswznm
			, WznmMTable* tbl
			, ListWznmMTablecol& tcos
			, map<string,WznmMTablecol*>& shortsTcos
			, Expr::Node* node
			, const bool wrtbl
		) {
	string retval = "0 = 1";

	WznmMTablecol* tco = NULL;
	map<string,WznmMTablecol*>::iterator it;

	string tcosref;

	WznmMVector* vec = NULL;
	WznmMVectoritem* vit = NULL;

	WznmMSubset* sbs2 = NULL;
	WznmMTable* tbl2 = NULL;

	ListWznmMTablecol tcos2;
	map<string,WznmMTablecol*> shortsTcos2;
	
	Expr expr2;

	if (node->logicfct()) {
		// only not, and, or make sense
		if ((node->key == "not") && (node->subs.size() == 1)) {
			retval = "NOT (" + genPnllist_getSbsevalsql(dbswznm, tbl, tcos, shortsTcos, node->subs[0], wrtbl) + ")";
		} else if ((node->key == "and") && (node->subs.size() == 2)) {
			retval = "(" + genPnllist_getSbsevalsql(dbswznm, tbl, tcos, shortsTcos, node->subs[0], wrtbl) + " AND " + genPnllist_getSbsevalsql(dbswznm, tbl, tcos, shortsTcos, node->subs[1], wrtbl) + ")";
		} else if ((node->key == "or") && (node->subs.size() == 2)) {
			retval = "(" + genPnllist_getSbsevalsql(dbswznm, tbl, tcos, shortsTcos, node->subs[0], wrtbl) + " OR " + genPnllist_getSbsevalsql(dbswznm, tbl, tcos, shortsTcos, node->subs[1], wrtbl) + ")";
		};

	} else if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
		// vocabulary:
		// xxxEq() - equivalence of tco
		// xxxIncl() - tco includes (ix for vecor)
		// isLeaf() - record of h1n table is leaf (has no subs)
		// xxx.inSbs() - record referenced by tco is part of subset (different table)

		// no nested functions to be expected here

		if ( (node->key.length() >= 5) && ((node->key.rfind("Eq")+2) == node->key.length()) && (node->subs.size() == 1) ) {
			it = shortsTcos.find(node->key.substr(0, node->key.length()-2));
			if (it != shortsTcos.end()) {
				tco = it->second;
				
				tcosref = tco->sref;
				if (wrtbl) tcosref = tbl->sref + "." + tcosref;

				if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF)) {
					retval = tcosref + " = " + to_string(node->subs[0]->intval);
				} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
					if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
						if (dbswznm->tblwznmmvectoritem->loadRecBySQL("SELECT * FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(vec->ref) + " AND sref = '" + node->subs[0]->key + "'", &vit)) {
							if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) retval = tcosref + " = " + to_string(1 << (vit->vecNum-1));
							else retval = tcosref + " = " + to_string(vit->vecNum);

							delete vit;
						};

						delete vec;
					};
				} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF)) {
					retval = tcosref + " = '" + node->subs[0]->key + "'";
				} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
					retval = tcosref + " = 1";
				};
			};

		} else if ( (node->key.length() >= 7) && ((node->key.rfind("Incl")+4) == node->key.length()) && (node->subs.size() == 1) ) {
			it = shortsTcos.find(node->key.substr(0, node->key.length()-4));
			if (it != shortsTcos.end()) {
				tco = it->second;

				tcosref = tco->sref;
				if (wrtbl) tcosref = tbl->sref + "." + tcosref;

				if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
					if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
						if (dbswznm->tblwznmmvectoritem->loadRecBySQL("SELECT * FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(vec->ref) + " AND sref = '" + node->subs[0]->key + "'", &vit)) {
							if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) retval = "(" + tcosref + " & " + to_string(1 << (vit->vecNum-1)) + ") <> 0";
							else retval = "(" + tcosref + " & " + to_string(vit->vecNum) + ") <> 0";

							delete vit;
						};

						delete vec;
					};
				} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
					retval = "((" + tcosref + " = '" + node->subs[0]->key + "') OR (" + tcosref + " LIKE '" + node->subs[0]->key + ";%') OR (" + tcosref + " LIKE '%;" + node->subs[0]->key + ";%') OR (" + tcosref + " LIKE '%;" + node->subs[0]->key + "'))";
				};
			};

		} else if (node->key == "isLeaf") {
			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.tblRefWznmMTable = " + to_string(tbl->ref) + " AND TblWznmMTablecol.ixVBasetype = "
						+ to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND TblWznmMTablecol.ixVSubtype = " + to_string(VecWznmVMTablecolSubtype::TREFSPEC) + " AND TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMRelation.ixVBasetype = "
						+ to_string(VecWznmVMRelationBasetype::H1N), &tco)) {

				retval = "ref NOT IN (SELECT DISTINCT " + tco->sref + " FROM " + tbl->sref + ")";
				delete tco;
			};

		} else if ( (node->key.length() >= 9) && ((node->key.rfind(".inSbs")+6) == node->key.length()) && (node->subs.size() == 1) ) {
			it = shortsTcos.find(node->key.substr(0, node->key.length()-6));
			if (it != shortsTcos.end()) {
				tco = it->second;

				tcosref = tco->sref;
				if (wrtbl) tcosref = tbl->sref + "." + tcosref;

				if (dbswznm->tblwznmmsubset->loadRecBySQL("SELECT TblWznmMSubset.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.refWznmMVersion = " + to_string(tbl->refWznmMVersion)
							+ " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.Short = '" + node->subs[0]->key + "'", &sbs2)) {

					if (expr2.tokenize(sbs2->Cond)) if (expr2.parse()) if (expr2.root) {
						if (dbswznm->tblwznmmtable->loadRecByRef(sbs2->refWznmMTable, &tbl2)) {
							dbswznm->tblwznmmtablecol->loadRstByTbl(tbl2->ref, false, tcos2);

							shortsTcos2.clear();
							for (unsigned int i = 0; i < tcos2.nodes.size(); i++) shortsTcos2[tcos2.nodes[i]->Short] = tcos2.nodes[i];

							retval = tcosref + " IN (SELECT ref FROM " + tbl2->sref + " WHERE " + genPnllist_getSbsevalsql(dbswznm, tbl2, tcos2, shortsTcos2, expr2.root, false) + ")";

							delete tbl2;
						};
					};
					delete sbs2;
				};
			};
		};
	};

	return retval;
};

void WznmGenDetui::genPnltbl_cjtstd(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnltbl_cjtstdstr(dbswznm, tco, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnltbl_cjtstdstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco short; 2nd try: tco full; 3rd try: tco sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::SHORT, refLcl, s)) {
		if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
			s = tco->sref;
			found = false;
		};
	};

	return found;
};

void WznmGenDetui::genPnltbl_cjtvec(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnltbl_cjtvecstr(dbswznm, tco, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnltbl_cjtvecstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco short; 2nd try: tco full; 3rd try: vec short; 4th try: vec full; 5th try: tco sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::SHORT, refLcl, s)) {
		if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
			if (!dbswznm->tblwznmamvectortitle->loadTitByVecTypLoc(tco->fctUref, VecWznmVAMVectorTitleType::SHORT, refLcl, s)) {
				if (!dbswznm->tblwznmamvectortitle->loadTitByVecTypLoc(tco->fctUref, VecWznmVAMVectorTitleType::FULL, refLcl, s)) {
					s = tco->sref;
					found = false;
				};
			};
		};
	};

	return found;
};

void WznmGenDetui::genPnltbl_cjtrel(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnltbl_cjtrelstr(dbswznm, tco, rel, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnltbl_cjtrelstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	bool toNotFr;

	// 1st try: tco short; 2nd try: tco full; 3rd try: rel from/tosngshort; 4th try: rel from/tosngfull; 5th try: {from/to}tbl short; 6th try: {from/to}tbl full; 7th try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::SHORT, refLcl, s)) {
		if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {

			toNotFr = ( ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) );

			if (toNotFr) {
				if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::TOSNGSHORT, refLcl, s))
					if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::TOSNGFULL, refLcl, s))
						if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->toRefWznmMTable, VecWznmVAMTableTitleType::SNGSHORT, refLcl, s))
							if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->toRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLcl, s)) found = false;

			} else {
				if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGSHORT, refLcl, s))
					if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s))
						if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::SNGSHORT, refLcl, s))
							if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLcl, s)) found = false;
			};

			if (!found) s = tco->sref;
		};
	};

	return found;
};

void WznmGenDetui::genPnltbl_cjtrelpl(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnltbl_cjtrelplstr(dbswznm, tco, rel, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnltbl_cjtrelplstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco short; 2nd try: tco full; 3rd try: rel fromplshort; 4th try: rel fromplfull; 5th try: tbl short; 6th try: tbl full; 7th try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::SHORT, refLcl, s)) {
		if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
			if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMPLSHORT, refLcl, s)) {
				if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMPLFULL, refLcl, s)) {
					if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::SNGSHORT, refLcl, s)) {
						if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLcl, s)) {
							s = tco->sref;
							found = false;
						};
					};
				};
			};
		};
	};

	return found;
};

void WznmGenDetui::genPnltbl_cjtreluniv(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnltbl_cjtrelunivstr(dbswznm, tco, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnltbl_cjtrelunivstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco short; 2nd try: tco full; 3rd try: rel fromsngshort; 4th try: rel fromsngfull; 5th try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::SHORT, refLcl, s)) {
		if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
			if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(tco->refWznmMRelation, VecWznmVAMRelationTitleType::FROMSNGSHORT, refLcl, s)) {
				if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(tco->refWznmMRelation, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s)) {
					s = tco->sref;
					found = false;
				};
			};
		};
	};

	return found;
};

void WznmGenDetui::genPnltbl_cjtrelauxpref(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnltbl_cjtrelauxprefstr(dbswznm, tco, rel, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnltbl_cjtrelauxprefstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1th try: tco short; 2nd try: tco full; 3rd try: rel fromsngfull; 4th try: vitJtit->Title of aux table x1 klst source; 5th try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::SHORT, refLcl, s)) {
		if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
			if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s)) {
				if (!dbswznm->loadStringBySQL("SELECT TblWznmJMVectoritem.Title FROM TblWznmMTablecol, TblWznmMVectoritem, TblWznmJMVectoritem WHERE TblWznmMTablecol.tblRefWznmMTable = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMTablecol.ixVBasetype = "
						+ to_string(VecWznmVMTablecolBasetype::KLREF) + " AND TblWznmMTablecol.fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::VEC) + " AND TblWznmMTablecol.sref LIKE 'x1%' AND TblWznmMVectoritem.vecRefWznmMVector = TblWznmMTablecol.fctUref AND TblWznmMVectoritem.sref = '"
						+ rel->Prefix + "' AND TblWznmJMVectoritem.refWznmMVectoritem = TblWznmMVectoritem.ref AND TblWznmJMVectoritem.x1RefWznmMLocale = " + to_string(refLcl), s)) {
					s = tco->sref;
					found = false;
				};
			};
		};
	};

	return found;
};

void WznmGenDetui::genPnltbl_cjtstrel(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTable* sttbl
			, WznmMTable* tbl
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnltbl_cjtstrelstr(dbswznm, sttbl, tbl, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnltbl_cjtstrelstr(
			DbsWznm* dbswznm
			, WznmMTable* sttbl
			, WznmMTable* tbl
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: sttbl plfull ; 2nd try: tbl plfull ; 3rd try: sttbl->sref

	if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(sttbl->ref, VecWznmVAMTableTitleType::PLFULL, refLcl, s)) {
		if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::PLFULL, refLcl, s)) {
			s = sttbl->sref;
			found = false;
		};
	};

	return found;
};

void WznmGenDetui::genPnl_cjttag(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, const string& srefTag
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	map<ubigint,string> tagTits;

	string s;

	// 1st try: tag title with matching locale; 2nd try: default tag title; 3rd try: tco sref

	Wznm::getTagtits(dbswznm, srefTag, "", "", {}, refLcl, refsLcl, tagTits, false);

	if (!tagTits.empty()) {
		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			s = StrMod::cap(tagTits[refsLcl[i]]);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;

				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};

	} else {
		ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, tco->sref);
		con->refJTitle = ref;
		con->Title = tco->sref;
		dbswznm->tblwznmmcontrol->updateRec(con);
	};
};

void WznmGenDetui::genPnltbl_qao(
			DbsWznm* dbswznm
			, WznmMQuery* qry
			, const string& tblsref
			, WznmMTablecol* tco
		) {
	ubigint ref;

	ref = dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, tco->Short, tblsref + "." + tco->sref);

	if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || ((qry->inoRefAOrder == 0) && tco->Eponymous)) {
		qry->inoRefAOrder = ref;
		qry->inoSrefsWznmMTablecol = tblsref + "." + tco->sref;
		
		dbswznm->tblwznmmquery->updateRec(qry);
	};
};

void WznmGenDetui::genPnlrec(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, WznmMCard* car
			, WznmMTable* tbl
			, WznmMSubset* sbs
			, const uint pnlnum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	ubigint refSbs;

	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	unsigned int connum = 1;

	string s;

	// --- generate panel
	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::REC, car->ref, pnlnum, VecWznmVMPanelRefTbl::TBL, tbl->ref, 0, "Pnl" + car->sref.substr(3) + "Rec", false, "", "");

	// -- basic controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (getCarstrSng(dbswznm, car, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);

			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	refSbs = 0;
	if (sbs) refSbs = sbs->ref;

	if (sbs) s = "pre.ref" + StrMod::cap(sbs->Short) + "()";
	else s = "pre.ref" + StrMod::cap(tbl->Short) + "()";

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButRegularize", VecWznmVMControlSubtype::VOID,
				"", 0, "", 0, 0, 0, "", s, "icon");

	// --- single control that receives record stub
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "TxtRef", VecWznmVMControlSubtype::VOID, "", 0, "", 0, getStbByReftblsbs(dbswznm, Prjshort, tbl->ref, refSbs, "Std"), 0, "", "", "");

	addConstbstd(dbswznm, Prjshort, con, tbl->ref, refSbs);

	delete pnl;
};

void WznmGenDetui::genPnlprerec(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, WznmMCard* car
			, ListWznmMPreset& psts
			, const uint pnlnum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	WznmMPreset* pst;

	unsigned int connum = 1;

	map<ubigint,string> andTits;

	string s, s2;

	// --- generate panel
	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::RECFORM, car->ref, pnlnum, VecWznmVMPanelRefTbl::VOID, 0, 0, "Pnl" + car->sref.substr(3) + "Pre", false, "", "");

	// -- basic controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	Wznm::getTagtits(dbswznm, "and", "", "", {}, refLcl, refsLcl, andTits, false);

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		s = "";

		for (unsigned int j = 0; j < psts.nodes.size(); j++) {
			pst = psts.nodes[j];

			if (j != 0) {
				if ( ((j+1) == psts.nodes.size()) && !andTits.empty() ) s += " " + andTits[refsLcl[i]] + " ";
				else s += ", ";
			};

			if (dbswznm->tblwznmjmpresettitle->loadTitByPstLoc(pst->ref, refsLcl[i], s2)) s += s2;
			else s += pst->sref;
		};

		ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

		if (refsLcl[i] == refLcl) {
			con->refJTitle = ref;
			con->Title = s;
			dbswznm->tblwznmmcontrol->updateRec(con);
		};
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");
};

void WznmGenDetui::genPnldetail(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const vector<string>& sesspsts
			, WznmMCard* car
			, WznmMTable* cartbl
			, const ubigint refCarsbs
			, ListWznmMTable& inctbls
			, map<ubigint,string>& incconds
			, map<ubigint,string>& incsbsconds
			, const vector<string>& carrecpsts
			, const vector<string>& carpsts
			, const uint pnlnum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	WznmMPanel* pnl = NULL;

	string uaccond;

	WznmMTable* tbl = NULL;
	WznmMTable* tbl2 = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;
	WznmMTablecol* tco2 = NULL;
	ubigint refTco;

	set<ubigint> refsSbsainb;
	set<ubigint> refsSbsbina;
	set<ubigint> refsSbsxsec;

	string sbscond;

	WznmMRelation* rel = NULL;

	ListWznmMRelation rel2s;
	WznmMRelation* rel2 = NULL;

	WznmMCard* car2 = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	unsigned int connum = 1;

	WznmMControl* supcon = NULL;
	unsigned int supnum;

	WznmMControl* supcon2 = NULL;
	unsigned int supnum2;

	string inccond;
	string incsbscond;
	string prefix;

	bool epo;

	list<Trg*> trgs;

	WznmMRelation* auxprefrel = NULL;

	ubigint jtblref;
	ubigint jcref;
	ubigint jpupref;
	usmallint jpuplvl;
	uint jpupnum;

	uint ixVBasetype;
	string sref;
	string srefsKOption;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	bool toNotFr;

	bool makecon;

	string s;

	// --- generate panel
	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::RECFORM, car->ref, pnlnum, VecWznmVMPanelRefTbl::TBL, cartbl->ref, 0, "Pnl" + car->sref.substr(3) + "Detail", false, "", "");

	uaccond = "pre.ixCrdacc" + car->sref.substr(3+4) + "Incl(edit)";

	// -- basic controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "detail", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButSave", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "dirty()", "icon");

	// --- table columns and corresponding controls
	dbswznm->tblwznmmtablecol->loadRstBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(cartbl->ref) + " AND ixVBasetype <> " + to_string(VecWznmVMTablecolBasetype::IDREF) + " ORDER BY Eponymous DESC, tblNum ASC", false, tcos);

	for (unsigned int i = 0; i < inctbls.nodes.size(); i++) {
		tbl = inctbls.nodes[i];
		dbswznm->tblwznmmtablecol->loadRstBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND ixVBasetype <> " + to_string(VecWznmVMTablecolBasetype::IDREF) + " ORDER BY Eponymous DESC, tblNum ASC", true, tcos);
	};

	tbl = cartbl;

	Wznm::getSbsrels(dbswznm, cartbl->ref, refCarsbs, refsSbsainb, refsSbsbina, refsSbsxsec);

	inccond = "";
	prefix = "";

	epo = false;

	jtblref = 0;
	jcref = 0;
	jpupref = 0;
	jpuplvl = 0;
	jpupnum = 0;

	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		refTco = tco->ref;

		if (tco->tblRefWznmMTable == tbl->ref) {
			// - same table as before

			if (tbl == cartbl) {
				// separator before non-eponymous tco's of primary table
				if (epo && !tco->Eponymous) {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SEP, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "SepA", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
				};

				epo = tco->Eponymous;
			};

		} else {
			// - different table than before

			for (unsigned int j = 0; j < inctbls.nodes.size(); j++) {
				tbl = inctbls.nodes[j];
				if (tco->tblRefWznmMTable == tbl->ref) break;
			};

			Wznm::getSbsrels(dbswznm, tbl->ref, 0, refsSbsainb, refsSbsbina, refsSbsxsec); // all inc tables are sbs 0

			inccond = incconds[tbl->ref];
			incsbscond = incsbsconds[tbl->ref];
			prefix = StrMod::cap(tbl->Short);

			// separator and heading before each inctbl
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SEP, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TBL, tbl->ref, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Sep" + prefix, VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, incsbscond, "", "");

			// HDG: Hdg {ButNew, ButDelete}
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::HDG, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TBL, tbl->ref, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Hdg" + prefix, VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, incsbscond, "", "cap");
			supnum = 1;

			for (unsigned int j = 0; j < refsLcl.size(); j++) {
				if (dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::SNGFULL, refsLcl[j], s)) {
					ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, supcon->ref, refsLcl[j], StrMod::cap(s));

					if (refsLcl[j] == refLcl) {
						supcon->refJTitle = ref;
						supcon->Title = StrMod::cap(s);
						dbswznm->tblwznmmcontrol->updateRec(supcon);
					};
				};
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + "New", VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, uaccond + "&" + inccond.substr(1), "", "icon");

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + "Delete", VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, uaccond + "&" + inccond, "", "icon");
		};

		// check for affiliation with jump table ; overwrite refTco ; match of tco->refWznmMRelation not needed
		if (jtblref != 0) if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(jtblref) + " AND sref = '" + tco->sref + "'", refTco)) {
			jtblref = 0;
			jcref = 0;
			jpupref = 0;
			jpuplvl = 0;
			jpupnum = 0;
		};

		if (tco->refWznmMSubset == 0) sbscond = "";
		else if (!Wznm::getPnlconAvail(dbswznm, (tbl == cartbl) ? refCarsbs : 0, refsSbsainb, refsSbsbina, refsSbsxsec, tbl, tco->refWznmMSubset, sbscond)) continue;

		if (tco->refWznmMRelation != 0) dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel);

		if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
			// TXT: Txt {Cpt}
			// same for jump override

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "s");
			if (jtblref != 0) jpupnum++;
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnldetail_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
			if ( (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) ) {
				// PUP_TXFALT: Pup {Cpt {ButToggle}, Txf, ButEdit}
				// Txt {Cpt} for jump override

				if (jtblref == 0) {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::PUP, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Pup" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
					supnum = 1;

					ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::VEC, tco->fctUref, "FeedF" + supcon->sref, "", "", "");
					supcon->refWznmMFeed = ref;
					dbswznm->tblwznmmcontrol->updateRec(supcon);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon2, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");
					supnum2 = 1;

					if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, supcon2, tco, auxprefrel, refLcl, refsLcl);
					else genPnldetail_cjtvec(dbswznm, supcon2, tco, refLcl, refsLcl);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Toggle", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "icon");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXF, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Txf" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "Edit", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "pre.adm()", "", "icon");
					dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "dlgopen");

				} else {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum++, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
					supnum = 1;

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");

					genPnldetail_cjtvec(dbswznm, con, tco, refLcl, refsLcl);
				};

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) {
				// LST_TXFALT: Lst {Lsb, Cpt {ButExpand, ButCollapse}, Txf, ButEdit}
				// Txt {Cpt} for jump override
				
				if (jtblref == 0) {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::LST, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Lst" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "multsel");
					supnum = 1;

					ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::VEC, tco->fctUref, "FeedF" + supcon->sref, "", "", "");
					supcon->refWznmMFeed = ref;
					dbswznm->tblwznmmcontrol->updateRec(supcon);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::LSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Lsb" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon2, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");
					supnum2 = 1;

					if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, supcon2, tco, auxprefrel, refLcl, refsLcl);
					else genPnldetail_cjtvec(dbswznm, supcon2, tco, refLcl, refsLcl);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Expand", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "icon");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Collapse", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "icon");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXF, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Txf" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "Edit", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "pre.adm()", "", "icon");
					dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "dlgopen");

				} else {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum++, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
					supnum = 1;

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");

					genPnldetail_cjtvec(dbswznm, con, tco, refLcl, refsLcl);
				};
			};

		} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && rel) {
			toNotFr = ( ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) );

			if (Wznm::getPnlconAvail(dbswznm, (tbl == cartbl) ? refCarsbs : 0, refsSbsainb, refsSbsbina, refsSbsxsec, tbl, (toNotFr) ? rel->frsRefWznmMSubset : rel->tosRefWznmMSubset, sbscond)) {
				if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) {
					// TXT: Txt {Cpt, ButView}

					// control / stub only in selected cases of associated relations
					makecon = false;

					if (rel->ixVBasetype == VecWznmVMRelationBasetype::_1N) {
						if (rel->supRefWznmMRelation == 0) {
							makecon = true;

						} else {
							// look at super relation
							if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &rel2)) {
								if ((rel2->ixVBasetype == VecWznmVMRelationBasetype::_1N) && ((rel->supIxVSubrole == VecWznmVMRelationSupSubrole::MOD) || (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::SPEC))) {
									makecon = true;
								} else if ((rel2->ixVBasetype == VecWznmVMRelationBasetype::MNPREF) && (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::MN1N)) {
									makecon = true;
								};

								delete rel2;
							};
						};

					} else if ( (rel->ixVBasetype == VecWznmVMRelationBasetype::INC) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBINC) ) {
						// covered with inctbl

					} else if ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) || (rel->ixVBasetype == VecWznmVMRelationBasetype::_1NPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::DRVSUB)
								|| (rel->ixVBasetype == VecWznmVMRelationBasetype::H1N) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11)
								|| (rel->ixVBasetype == VecWznmVMRelationBasetype::L1N)) {
						makecon = true;
					};

					if (makecon) {
						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
						supnum = 1;

						if (toNotFr) addConstbstd(dbswznm, Prjshort, supcon, rel->toRefWznmMTable);
						else addConstbstd(dbswznm, Prjshort, supcon, rel->frRefWznmMTable);

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, "", "", "");

						genPnldetail_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

						Wznm::collectTrgs(dbswznm, sesspsts, car, carrecpsts, carpsts, tbl, tco, rel, toNotFr, trgs);
						if (!trgs.empty()) {
							// Avail: concerns access rights and target availability
							// Active: concerns ref != 0
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "View", VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, tbl->Short + "." + tco->Short + "Eq(0)" + "|(" + getAvail(trgs, false) + ")", "!" + tbl->Short + "." + tco->Short + "Eq(0)", "icon");
							dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");
						};
					};

				} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) {
					// TXT_PUP: Txt {Cpt, Pup, ButView}

					makecon = true;

					// no control for uinc cartbl->tbl
					if ( (rel->ixVBasetype == VecWznmVMRelationBasetype::U1N) && (tbl != cartbl) )
								if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->ref) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::U1NSUBINC)
											+ " AND frRefWznmMTable = " + to_string(cartbl->ref) + " AND toRefWznmMTable = " + to_string(tbl->ref), ref)) makecon = false;

					if (makecon) {
						// find table column of vector that corresponds to the universal relation
						for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
							tco2 = tcos.nodes[j];
							if ((tco2->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) && (tco2->refWznmMRelation == tco->refWznmMRelation) && ((tco2->sref.rfind("VTbl")+4) == tco2->sref.length())) break;
						};

						dbswznm->tblwznmmvectoritem->loadRstByVec(tco2->fctUref, false, vits);

						// find sub relations to the universal relation
						dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUB), false, rel2s);
						dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUBL), true, rel2s);

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "s");
						supnum = 1;

						// stubs
						for (unsigned int j = 0; j < rel2s.nodes.size(); j++) {
							rel2 = rel2s.nodes[j];

							// find corresponding vector item
							for (unsigned int k = 0; k < vits.nodes.size(); k++) {
								vit = vits.nodes[k];

								if (vit->sref.compare(rel2->Prefix) == 0) {
									ref = getStbByReftblsbs(dbswznm, Prjshort, rel2->frRefWznmMTable, rel2->frsRefWznmMSubset, "Std");

									if (ref != 0) dbswznm->tblwznmjmcontrol->insertNewRec(NULL, supcon->ref, vit->ref, 0, ref, 0);

									break;
								};
							};
						};

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, "", "", "");

						genPnldetail_cjtreluniv(dbswznm, con, tco, refLcl, refsLcl);

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::PUP, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::TCO, tco2->ref, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Pup" + prefix + StrMod::cap(tco2->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, "", "", "xs");

						ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, con->ref, VecWznmVMFeedSrcTbl::VEC, tco2->fctUref, "FeedF" + con->sref, "", "", "");
						con->refWznmMFeed = ref;
						dbswznm->tblwznmmcontrol->updateRec(con);

						Wznm::collectTrgs(dbswznm, sesspsts, car, carrecpsts, carpsts, tbl, tco, rel, toNotFr, trgs);
						if (!trgs.empty()) {
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "View", VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, tbl->Short + "." + tco->Short + "Eq(0)" + "|(" + getAvail(trgs, false) + ")", "!" + tbl->Short + "." + tco->Short + "Eq(0)", "icon");
							dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");
						};
					};

				} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) {
					// control / stub depends on type of associated relation
					if (rel->ixVBasetype == VecWznmVMRelationBasetype::AU1N) {
						// PUP_PUP: Pup {Cpt, Pup, ButView}

						// find table column of vector that corresponds to the universal relation
						for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
							tco2 = tcos.nodes[j];
							if ((tco2->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) && (tco2->refWznmMRelation == tco->refWznmMRelation) && ((tco2->sref.rfind("VTbl")+4) == tco2->sref.length())) break;
						};

						dbswznm->tblwznmmvectoritem->loadRstByVec(tco2->fctUref, false, vits);

						// find sub relations to the universal relation
						dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUB), false, rel2s);

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::PUP, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Pup" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "s");
						supnum = 1;

						ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::VOID, 0, "FeedF" + supcon->sref, "", "", "");
						supcon->refWznmMFeed = ref;
						dbswznm->tblwznmmcontrol->updateRec(supcon);

						// stubs
						for (unsigned int j = 0; j < rel2s.nodes.size(); j++) {
							rel2 = rel2s.nodes[j];

							// find corresponding vector item
							for (unsigned int k = 0; k < vits.nodes.size(); k++) {
								vit = vits.nodes[k];

								if (vit->sref == rel2->Prefix) {
									ref = vit->ref;
									break;
								};
							};

							dbswznm->tblwznmjmcontrol->insertNewRec(NULL, supcon->ref, ref, getStbByReftblsbs(dbswznm, Prjshort, rel2->frRefWznmMTable, rel2->frsRefWznmMSubset, "Std"), 0);
						};

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, "", "", "");

						genPnldetail_cjtreluniv(dbswznm, con, tco, refLcl, refsLcl);

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::PUP, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::TCO, tco2->ref, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Pup" + prefix + StrMod::cap(tco2->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, "", "", "xs");

						ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, con->ref, VecWznmVMFeedSrcTbl::VEC, tco2->fctUref, "FeedF" + con->sref, "", "", "");
						con->refWznmMFeed = ref;
						dbswznm->tblwznmmcontrol->updateRec(con);

						Wznm::collectTrgs(dbswznm, sesspsts, car, carrecpsts, carpsts, tbl, tco, rel, toNotFr, trgs);
						if (!trgs.empty()) {
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "View", VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, tbl->Short + "." + tco->Short + "Eq(0)" + "|(" + getAvail(trgs, false) + ")", "!" + tbl->Short + "." + tco->Short + "Eq(0)", "icon");
							dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");
						};

					} else {
						if (rel->ixVBasetype == VecWznmVMRelationBasetype::JPREF) {
							// PUP_VBAR: Pup {ButEdit}
							jtblref = rel->frRefWznmMTable;
							jcref = dbswznm->tblwznmccontrol->getNewRef();

							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(jtblref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::IDREF), refTco);

							// standard stub in case of tblref j x1 axis
							ref = 0;
							if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(jtblref) + " AND sref LIKE 'x1%' AND ixVAxisfct = " + to_string(VecWznmVMTablecolAxisfct::PT), &tco2)) {
								if (dbswznm->tblwznmmrelation->loadRecByRef(tco2->refWznmMRelation, &rel2)) {
									ref = getStbByReftblsbs(dbswznm, Prjshort, rel2->frRefWznmMTable, rel2->frsRefWznmMSubset, "Std");
									delete rel2;
								};
								delete tco2;
							};

							jpupref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::PUP, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
											VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Pup" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
											"", 0, "", 0, ref, 0, andConds(inccond, sbscond), uaccond, "s");
							jpuplvl = 1;
							jpupnum = 1;

							ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::VOID, 0, "FeedF" + supcon->sref, "", "", "");
							supcon->refWznmMFeed = ref;
							dbswznm->tblwznmmcontrol->updateRec(supcon);

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl, jpupnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "Edit", VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, uaccond, "", "icon");
							dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "dlgopen");

						} else if (rel->ixVBasetype == VecWznmVMRelationBasetype::AUXPREF) {
							auxprefrel = new WznmMRelation(*rel);

						} else if (rel->ixVBasetype == VecWznmVMRelationBasetype::A1N) {
							// TXT: Txt {Cpt, ButView}
							// Txt {Cpt} for jump override

							if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
								dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
											VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
											"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
								if (jtblref != 0) jpupnum++;
								supnum = 1;

								addConstbstd(dbswznm, Prjshort, supcon, tbl2->ref);

								dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
											VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
											"", 0, "", 0, 0, 0, "", "", "");

								genPnldetail_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

								if (jtblref == 0) {
									Wznm::collectTrgs(dbswznm, sesspsts, car, carrecpsts, carpsts, tbl, tco, rel, toNotFr, trgs);
									if (!trgs.empty()) {
										dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
													VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "View", VecWznmVMControlSubtype::VOID,
													"", 0, "", 0, 0, 0, tbl->Short + "." + tco->Short + "Eq(0)" + "|(" + getAvail(trgs, false) + ")", "!" + tbl->Short + "." + tco->Short + "Eq(0)", "icon");
										dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");
									};
								};

								delete tbl2;
							};
						};
					};

				} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) {
					// LST_TXTALT: Lst {Lsb, Cpt {ButExpand, ButCollapse}, Txt, ButView, ButCluster, ButUncluster}
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::LST, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Lst" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
					supnum = 1;

					ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::TBL, tbl->ref, "FeedF" + supcon->sref, "", "", "");
					supcon->refWznmMFeed = ref;
					dbswznm->tblwznmmcontrol->updateRec(supcon);

					addConstbstd(dbswznm, Prjshort, supcon, tbl->ref, 0, true);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::LSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Lsb" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon2, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"clust", 0, "", 0, 0, 0, "", "", "");
					supnum2 = 1;

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Expand", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "icon");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Collapse", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "icon");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");

/// HERE: revise for subset distinction
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "View", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", supcon->sref + ".sel()", "icon");
					dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "Cluster", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, uaccond + "&" + tbl->Short + "." + tco->Short + "Eq(0)", "", "icon");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "Uncluster", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, uaccond + "&!" + tbl->Short + "." + tco->Short + "Eq(0)", "", "icon");
				};
			};

		} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && rel) {
			if (Wznm::getPnlconAvail(dbswznm, (tbl == cartbl) ? refCarsbs : 0, refsSbsainb, refsSbsbina, refsSbsxsec, tbl, rel->tosRefWznmMSubset, sbscond)) {
				if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
					if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) {
						// as1n relation

						// TXT_TXFALT: Txt {Cpt {ButToggle}, Txf, ButView}
						// Txt {Cpt} for jump override

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
						if (jtblref != 0) jpupnum++;
						supnum = 1;

						addConstbstd(dbswznm, Prjshort, supcon, tbl2->ref);

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon2, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
									VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
									"", 0, "", 0, 0, 0, "", "", "");
						supnum2 = 1;

						genPnldetail_cjtrel(dbswznm, supcon2, tco, rel, refLcl, refsLcl);

						if (jtblref == 0) {
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, jpuplvl+2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Toggle", VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, "", "", "icon");

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXF, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::TCO, refTco, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::SHR, 0, "Txf" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, "", "", "");

							if (dbswznm->tblwznmmcard->loadRecByRef(tbl2->refWznmMCard, &car2)) {
// HERE: needs sref->ref
								// view possible only if there is a corresponding card
								dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
											VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "View", VecWznmVMControlSubtype::VOID,
											"", 0, "", 0, 0, 0, "pre.ixCrdacc" + car2->sref.substr(3+4) + "()", "", "icon");
								dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");

								delete car2;
							};
						};

					} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) {
						// asmn relation
						// LST_TXFALT: Lst {Lsb, Cpt {ButExpand, ButCollapse}, Txf, ButView}
						// Txt {Cpt} for jump override

						if (jtblref == 0) {
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::LST, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Lst" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
							supnum = 1;

							ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::TBL, tbl2->ref, "FeedF" + supcon->sref, "", "", "");
							supcon->refWznmMFeed = ref;
							dbswznm->tblwznmmcontrol->updateRec(supcon);

							addConstbstd(dbswznm, Prjshort, supcon, tbl2->ref);

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::LSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Lsb" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, "", "", "");

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon2, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, "", "", "");
							supnum2 = 1;

							genPnldetail_cjtrelpl(dbswznm, supcon2, tco, rel, refLcl, refsLcl);

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Expand", VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, "", "", "icon");

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Collapse", VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, "", "", "icon");

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXF, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::TCO, refTco, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Txf" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, "", "", "");

							if (dbswznm->tblwznmmcard->loadRecByRef(tbl2->refWznmMCard, &car2)) {
								// view possible only if there is a corresponding card
// HERE: needs sel and sref->ref
								dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
											VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "But" + prefix + StrMod::cap(tco->Short) + "View", VecWznmVMControlSubtype::VOID,
											"", 0, "", 0, 0, 0, "pre.ixCrdacc" + car2->sref.substr(3+4) + "()", supcon->sref + ".sel()", "icon");
								dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");

								delete car2;
							};

						} else {
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum++, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
							supnum = 1;

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
										VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
										"", 0, "", 0, 0, 0, "", "", "");

							genPnldetail_cjtrelpl(dbswznm, con, tco, rel, refLcl, refsLcl);
						};
					};

					delete tbl2;
				};
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {

			if ((tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) && (tco->refWznmMRelation == 0)) {
				// PUP: Pup {Cpt}
				// same for jump override

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::PUP, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
							VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, "Pup" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
				if (jtblref != 0) jpupnum++;
				supnum = 1;

				ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::VEC, tco->fctUref, "FeedF" + supcon->sref, "", "", "");
				supcon->refWznmMFeed = ref;
				dbswznm->tblwznmmcontrol->updateRec(supcon);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
							VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
							"", 0, "", 0, 0, 0, "", "", "");

				if (rel) genPnldetail_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);
				else genPnldetail_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
				else genPnldetail_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) {
				// LST_TXTALT: Lst {Lsb, Cpt {ButExpand, ButCollapse}, Txt}
				// Txt {Cpt} for jump override

				if (jtblref == 0) {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::LST, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Lst" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "multsel");
					supnum = 1;

					ref = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::VEC, tco->fctUref, "FeedF" + supcon->sref, "", "", "");
					supcon->refWznmMFeed = ref;
					dbswznm->tblwznmmcontrol->updateRec(supcon);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::LSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Lsb" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon2, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");
					supnum2 = 1;

					if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, supcon2, tco, auxprefrel, refLcl, refsLcl);
					else genPnldetail_cjtvec(dbswznm, supcon2, tco, refLcl, refsLcl);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Expand", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "icon");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon2->ref, 2, supnum2++, VecWznmVMControlScope::APP, 0, "But" + prefix + StrMod::cap(tco->Short) + "Collapse", VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "icon");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, supcon->ref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");

				} else {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXT, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum++, VecWznmVMControlScope::SHR, 0, "Txt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
					supnum = 1;

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
								VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
								"", 0, "", 0, 0, 0, "", "", "");

					genPnldetail_cjtvec(dbswznm, con, tco, refLcl, refsLcl);
				};
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
			// TXF: Txf {Cpt}
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXF, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TCO, refTco, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Txf" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnldetail_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

//		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
//		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
//		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
//		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::LVL) {

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
			// TXF: Txf {Cpt}
			// Txt {Cpt} for jump override

			if (jtblref == 0) {
				ixVBasetype = VecWznmVMControlBasetype::TXF;
				sref = "Txf" + prefix + StrMod::cap(tco->Short);
			} else {
				ixVBasetype = VecWznmVMControlBasetype::TXT;
				sref = "Txt" + prefix + StrMod::cap(tco->Short);
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, ixVBasetype, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, sref, VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "s");
			if (jtblref != 0) jpupnum++;
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnldetail_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
			// TXF: Txf {Cpt}
			// Txt {Cpt} for jump override

			if (jtblref == 0) {
				ixVBasetype = VecWznmVMControlBasetype::TXF;
				sref = "Txf" + prefix + StrMod::cap(tco->Short);
			} else {
				ixVBasetype = VecWznmVMControlBasetype::TXT;
				sref = "Txt" + prefix + StrMod::cap(tco->Short);
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, ixVBasetype, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, sref, VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "s");
			if (jtblref != 0) jpupnum++;
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnldetail_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
			// CHK: Chk {Cpt}
			// same for jump override

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::CHK, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, "Chk" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "");
			if (jpupnum != 0) jpupnum++;
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnldetail_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
			// TXF: Txf {Cpt}
			// Txt {Cpt} for jump override

			if (jtblref == 0) {
				ixVBasetype = VecWznmVMControlBasetype::TXF;
				sref = "Txf" + prefix + StrMod::cap(tco->Short);
			} else {
				ixVBasetype = VecWznmVMControlBasetype::TXT;
				sref = "Txt" + prefix + StrMod::cap(tco->Short);
			};

			if ((tco->ixVSubtype == VecWznmVMTablecolSubtype::TXTLONG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::TXTBASE64)) srefsKOption = "t";
			else if ( (tco->ixVSubtype == VecWznmVMTablecolSubtype::TXT5) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::TXT10) ) srefsKOption = "xs";
			else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TXT30) srefsKOption = "s";
			else srefsKOption = "";

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, ixVBasetype, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, sref, VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, srefsKOption);
			if (jtblref != 0) jpupnum++;
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnldetail_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
			// TXF: Txf {Cpt}
			// Txt {Cpt} for jump override

			if (jtblref == 0) {
				ixVBasetype = VecWznmVMControlBasetype::TXF;
				sref = "Txf" + prefix + StrMod::cap(tco->Short);
			} else {
				ixVBasetype = VecWznmVMControlBasetype::TXT;
				sref = "Txt" + prefix + StrMod::cap(tco->Short);
			};

			if ( (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) ) srefsKOption = "s";
			else srefsKOption = "";

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, ixVBasetype, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, sref, VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, srefsKOption);
			if (jtblref != 0) jpupnum++;
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnldetail_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
			// TXF: Txf {Cpt}
			// Txt {Cpt} for jump override

			if (jtblref == 0) {
				ixVBasetype = VecWznmVMControlBasetype::TXF;
				sref = "Txf" + prefix + StrMod::cap(tco->Short);
			} else {
				ixVBasetype = VecWznmVMControlBasetype::TXT;
				sref = "Txt" + prefix + StrMod::cap(tco->Short);
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, ixVBasetype, jcref, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::TCO, refTco, jpupref, jpuplvl, jpupnum, VecWznmVMControlScope::SHR, 0, sref, VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, andConds(inccond, sbscond), uaccond, "t");
			if (jtblref != 0) jpupnum++;
			supnum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::CONT,
						VecWznmVMControlRefTbl::VOID, 0, supcon->ref, jpuplvl+1, supnum++, VecWznmVMControlScope::APP, 0, "Cpt" + prefix + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID,
						"", 0, "", 0, 0, 0, "", "", "");

			if (auxprefrel) genPnldetail_cjtrelauxpref(dbswznm, con, tco, auxprefrel, refLcl, refsLcl);
			else genPnldetail_cjtstd(dbswznm, con, tco, refLcl, refsLcl);
		};

		if (auxprefrel && !rel) {
			delete auxprefrel;
			auxprefrel = NULL;
		} else if (auxprefrel && rel) if (auxprefrel->ref != rel->ref) {
			delete auxprefrel;
			auxprefrel = NULL;
		};

		if (rel) {
			delete rel;
			rel = NULL;
		};
	};

	delete pnl;
};

void WznmGenDetui::genPnldetail_cjtstd(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnldetail_cjtstdstr(dbswznm, tco, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnldetail_cjtstdstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco full; 2nd try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
		s = tco->sref;
		found = false;
	};

	return found;
};

void WznmGenDetui::genPnldetail_cjtvec(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnldetail_cjtvecstr(dbswznm, tco, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnldetail_cjtvecstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco full; 2nd try: vec full; 3rd try: tco sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
		if (!dbswznm->tblwznmamvectortitle->loadTitByVecTypLoc(tco->fctUref, VecWznmVAMVectorTitleType::FULL, refLcl, s)) {
			s = tco->sref;
			found = false;
		};
	};

	return found;
};

void WznmGenDetui::genPnldetail_cjtrel(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnldetail_cjtrelstr(dbswznm, tco, rel, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnldetail_cjtrelstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	bool toNotFr;

	// 1st try: tco full; 2nd try: rel {from/to}sngfull; 3rd try: {from/to}tbl full; 4th try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
		toNotFr = ( ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) );

		if (toNotFr) {
			if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::TOSNGFULL, refLcl, s))
				if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->toRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLcl, s)) found = false;

		} else {
			if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s))
				if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLcl, s)) found = false;
		};

		if (!found) s = tco->sref;
	};

	return found;
};

void WznmGenDetui::genPnldetail_cjtrelpl(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnldetail_cjtrelplstr(dbswznm, tco, rel, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnldetail_cjtrelplstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco full; 2nd try: rel fromplfull; 3rd try: tbl plfull; 4th try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
		if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMPLFULL, refLcl, s)) {
			if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::PLFULL, refLcl, s)) {
				s = tco->sref;
				found = false;
			};
		};
	};

	return found;
};

void WznmGenDetui::genPnldetail_cjtreluniv(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnldetail_cjtrelunivstr(dbswznm, tco, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnldetail_cjtrelunivstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco full; 2nd try: rel fromsngfull; 3rd try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
		if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(tco->refWznmMRelation, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s)) {
			s = tco->sref;
			found = false;
		};
	};

	return found;
};

void WznmGenDetui::genPnldetail_cjtrelauxpref(
			DbsWznm* dbswznm
			, WznmMControl* con
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;
	ubigint ref;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnldetail_cjtrelauxprefstr(dbswznm, tco, rel, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};
};

bool WznmGenDetui::genPnldetail_cjtrelauxprefstr(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: tco full; 2nd try: rel fromsngfull; 3rd try: vitJtit->Title of aux table x1 klst source; 4th try: tco->sref

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
		if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s)) {
			if (!dbswznm->loadStringBySQL("SELECT TblWznmJMVectoritem.Title FROM TblWznmMTablecol, TblWznmMVectoritem, TblWznmJMVectoritem WHERE TblWznmMTablecol.tblRefWznmMTable = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMTablecol.ixVBasetype = "
					+ to_string(VecWznmVMTablecolBasetype::KLREF) + " AND TblWznmMTablecol.fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::VEC) + " AND TblWznmMTablecol.sref LIKE 'x1%' AND TblWznmMVectoritem.vecRefWznmMVector = TblWznmMTablecol.fctUref AND TblWznmMVectoritem.sref = '"
					+ rel->Prefix + "' AND TblWznmJMVectoritem.refWznmMVectoritem = TblWznmMVectoritem.ref AND TblWznmJMVectoritem.x1RefWznmMLocale = " + to_string(refLcl), s)) {
				s = tco->sref;
				found = false;
			};
		};
	};

	return found;
};

void WznmGenDetui::genPnlklst(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, WznmMCard* car
			, WznmMTable* mtb
			, const ubigint refPst
			, const string& sbscond
			, const uint pnlnum
			, const string& pnlsref
			, WznmMVector* vec
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	WznmMFeed* fed = NULL;

	ubigint supref;
	unsigned int supnum;

	WznmMQuery* qry = NULL;

	ubigint refTbl;
	ubigint refVec, refVit;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	unsigned int qconum = 1;
	unsigned int connum = 1;

	string s;

	// --- generate panel
	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::RECLIST, car->ref, pnlnum, VecWznmVMPanelRefTbl::VEC, vec->ref, 0, pnlsref, false, sbscond, "");

	// -- basic controls

	// panel caption
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnlklst_cptstr(dbswznm, pnl, vec, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);

			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButClipboard", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtRecord", VecWznmVMControlSubtype::VOID, "rec;emplong", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButUp", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "sel()&!sel.first()", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDown", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "sel()&!sel.last()", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButNew", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDuplicate", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "sel()", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDelete", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "sel()", "icon");

	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TBL, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Tbl", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
	supnum = 1;

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TRS, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Trs", VecWznmVMControlSubtype::VOID, "goto", 0, "", 0, 0, 0, "", "", "cap;ddd");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Tsb", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtShowing", VecWznmVMControlSubtype::VOID, "showshort;empshort", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CSI, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "CsiQst", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VQrystate'", ref);
	dbswznm->tblwznmmfeed->insertNewRec(&fed, con->ref, VecWznmVMFeedSrcTbl::VEC, ref, "FeedF" + con->sref, "mnr.ong;ood.red;slm.yel;utd.grn", "", "");

	con->refWznmMFeed = fed->ref;
	dbswznm->tblwznmmcontrol->updateRec(con);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButRefresh", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	// --- find TblXxxxAVKeylistKey and load its table columns
	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "AVKeylistKey'", refTbl);
	dbswznm->tblwznmmtablecol->loadRstByTbl(refTbl, false, tcos);

	// --- generate query
	dbswznm->tblwznmmquery->insertNewRec(&qry, VecWznmVMQueryBasetype::STD, refWznmMVersion, 0, VecWznmVMQuerySupSubrole::VOID, 0, 0, 0, 0, "Qry" + pnl->sref.substr(3), true, 0, "", "");

	ref = dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, qry->ref, refTbl, true, "");

	qry->refRTable = ref;
	qry->refWznmMTable = refTbl;
	dbswznm->tblwznmmquery->updateRec(qry);

	dbswznm->tblwznmrmpanelmquery->insertNewRec(NULL, pnl->ref, qry->ref);

	// -- query arguments
	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VKeylist'", refVec)) {
		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refVec) + " AND sref = '" + vec->sref + "'", refVit)) {
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, 1, 0, VecWznmVAMQueryClauseBasetype::VIT, "klsIx" + Prjshort + "VKeylist = &vit;", 0, refVec, refVit);
		};
	};

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VMaintable'", refVec)) {
		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refVec) + " AND sref = '" + mtb->sref + "'", refVit)) {
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, 2, 0, VecWznmVAMQueryClauseBasetype::VIT, "x1Ix" + Prjshort + "VMaintable = &vit;", 0, refVec, refVit);
		};
	};

	dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, 3, 0, VecWznmVAMQueryClauseBasetype::PRE, "x1Uref = &pre;", refPst, 0, 0);

	ref = dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, "kln", "Tbl" + Prjshort + "AVKeylistKey.klsNum");

	qry->inoRefAOrder = ref;
	qry->inoSrefsWznmMTablecol = "Tbl" + Prjshort + "AVKeylistKey.klsNum";
	dbswznm->tblwznmmquery->updateRec(qry);

	// --- query columns and corresponding controls

	// -- qref, jref and jnum
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QIDREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "qref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QJREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QJENUM, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jnum", "", 0);

	// query columns
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (tco->sref.compare("ref") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "ref", "", 0);

		} else if (tco->sref.compare("klsNum") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "klsNum", "", 0);

		} else if (tco->sref.compare("Fixed") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "Fixed", "", 0);

			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::YESNO, VecWznmWMQuerycolOccurrence::XML,
						qry->ref, qconum++, tco->ref, "yesnoFixed", "fix", 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoFix", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->sref.compare("sref") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "sref", "srf", 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoSrf", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->sref.compare("Avail") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "Avail", "avl", 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoAvl", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->sref.compare("Implied") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "Implied", "imp", 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoImp", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->sref.compare("refJ") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "refJ", "", 0);

		} else if (tco->sref.compare("Title") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "Title", "tit", 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoTit", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->sref.compare("Comment") == 0) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, "Comment", "cmt", 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoCmt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);
		};
	};

	delete qry;
	delete pnl;
};

bool WznmGenDetui::genPnlklst_cptstr(
			DbsWznm* dbswznm
			, WznmMPanel* pnl
			, WznmMVector* vec
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// so far, there is only short and full ; it might (wrongly) be in singular
	// 1st try: vec full ; 2nd try: pnl->sref

	if (!dbswznm->tblwznmamvectortitle->loadTitByVecTypLoc(vec->ref, VecWznmVAMVectorTitleType::FULL, refLcl, s)) {
		s = pnl->sref;
		found = false;
	};

	return found;
};

void WznmGenDetui::genPnlaux(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, WznmMCard* car
			, const ubigint refPst
			, const string& sbscond
			, const uint pnlnum
			, const string& pnlsref
			, WznmMRelation* pnlrel
			, WznmMTable* reltbl
			, const bool relenum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref, ref2;

	WznmMPanel* pnl = NULL;

	string uaccond;

	ubigint refAuxrel;

	WznmMQuery* qry = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	vector<unsigned int> icsModtcos;

	WznmMTablecol* psttco = NULL;
	WznmMTablecol* enumtco = NULL;
	WznmMTablecol* ordtco = NULL;

	int axis;

	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;
	WznmMRelation* rel2 = NULL;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	WznmMFeed* fed = NULL;

	ubigint supref;
	unsigned int supnum;

	WznmMTable* tbl2 = NULL;

	bool makecon;

	unsigned int qconum = 1;
	unsigned int qmdnum = 1;
	unsigned int qacnum = 1;
	unsigned int connum = 1;

	string s;

	// --- analyze relation
	dbswznm->tblwznmmtablecol->loadRstByTbl(reltbl->ref, false, tcos);

	// - refAuxrel
	if (pnlrel->ixVBasetype == VecWznmVMRelationBasetype::AUX) refAuxrel = pnlrel->ref;
	else refAuxrel = pnlrel->supRefWznmMRelation;

	// - icsModtcos, psttco, enumtco, ordtco
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if ((tco->refWznmMRelation != pnlrel->ref) && (tco->ixVAxisfct != VecWznmVMTablecolAxisfct::VOID)) {
			if (tco->sref.length() > 1) if (atoi(tco->sref.substr(1).c_str()) > 0) icsModtcos.push_back(i);
		} else if (!psttco && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->refWznmMRelation == pnlrel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == pnlrel->frRefWznmMTable)) psttco = tco;
		else if (!enumtco && (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) && (tco->refWznmMRelation == refAuxrel)) enumtco = tco;
		else if (!ordtco && ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || (tco->Eponymous && StrMod::srefInSrefs(tco->srefsKOption, "idx")))) ordtco = tco;
	};

	// --- generate panel
	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::RECLIST, car->ref, pnlnum, VecWznmVMPanelRefTbl::REL, pnlrel->ref, 0, pnlsref, false, sbscond, "");

	uaccond = "pre.ixCrdacc" + car->sref.substr(3+4) + "Incl(edit)";

	// -- basic controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnlaux_cptstr(dbswznm, pnl, pnlrel->ref, refAuxrel, reltbl->ref, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);

			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButClipboard", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtRecord", VecWznmVMControlSubtype::VOID, "rec;emplong", 0, "", 0, 0, 0, "", "", "cap");

	if (relenum) {
		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButUp", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()&!sel.first()", "icon");

		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDown", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()&!sel.last()", "icon");
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButNew", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDuplicate", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDelete", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()", "icon");

	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TBL, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Tbl", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
	supnum = 1;

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TRS, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Trs", VecWznmVMControlSubtype::VOID, "goto", 0, "", 0, 0, 0, "", "", "cap;ddd");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Tsb", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtShowing", VecWznmVMControlSubtype::VOID, "showshort;empshort", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CSI, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "CsiQst", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VQrystate'", ref);
	dbswznm->tblwznmmfeed->insertNewRec(&fed, con->ref, VecWznmVMFeedSrcTbl::VEC, ref, "FeedF" + con->sref, "mnr.ong;ood.red;slm.yel;utd.grn", "", "");

	con->refWznmMFeed = fed->ref;
	dbswznm->tblwznmmcontrol->updateRec(con);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButRefresh", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	// --- generate query
	dbswznm->tblwznmmquery->insertNewRec(&qry, VecWznmVMQueryBasetype::STD, refWznmMVersion, 0, VecWznmVMQuerySupSubrole::VOID, 0, 0, 0, 0, "Qry" + pnl->sref.substr(3), true, 0, "", "");

	ref = dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, qry->ref, reltbl->ref, true, "");

	qry->refRTable = ref;
	qry->refWznmMTable = reltbl->ref;
	dbswznm->tblwznmmquery->updateRec(qry);

	dbswznm->tblwznmrmpanelmquery->insertNewRec(NULL, pnl->ref, qry->ref);

	// -- presetting
	dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::PRE, reltbl->sref + "." + psttco->sref + " = &pre;", refPst, 0, 0);

	// -- axes functionality (including filter controls)
	axis = 0;

	for (unsigned int i = 0; i < icsModtcos.size(); i++) {
		tco = tcos.nodes[icsModtcos[i]];

		if (atoi(tco->sref.substr(1).c_str()) != axis) {
			axis = atoi(tco->sref.substr(1).c_str());

			ref = dbswznm->tblwznmmpreset->insertNewRec(NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL, "Pre" + pnlsref.substr(3) + ".x" + to_string(axis), getTcoArgtype(tco), 0, "");

			// add control here ; all feeds are derived from the items which exist already
			// klref/klrefsng: pup
			// tblref/trefspec: pup
			// vecref/vreflin: pup
			// {intval,dblval,timeval}, pt: pup
			// {intval,dblval,timeval}, spt/ept/span: sld
			
			// ...
		};

		ref2 = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::FILT, qry->ref, qmdnum++, ref, VecWznmVMQuerymodRefTbl::TCO, tco->ref, "");

		s = reltbl->sref + "." + tco->sref;

		if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) s += " = '&pre;'";
		else if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::PT) s += " = &pre;";
		else if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::SPT) s += " <= &pre;";
		else if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::EPT) s += " >= &pre;";

		dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::PRE, s, ref, 0, 0);
	};

	// -- query order
	if (enumtco) dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, enumtco->Short, enumtco->sref);
	else if (ordtco) dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, ordtco->Short, ordtco->sref);

	// --- query columns and corresponding controls

	// -- qref, jref and jnum
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QIDREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "qref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QJREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QJENUM, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jnum", "", 0);

	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTITS, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tits" + StrMod::cap(tco->sref), tco->Short + "2", 0);
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
			if ((tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->refWznmMRelation != pnlrel->ref) && (tco->refWznmMRelation != refAuxrel)) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				// column control / stub only in selected cases of associated relations
				if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
					makecon = false;

					if (rel->ixVBasetype == VecWznmVMRelationBasetype::_1N) {
						if (rel->supRefWznmMRelation == 0) {
							makecon = true;

						} else {
							// look at super relation
							if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &rel2)) {
								if ((rel2->ixVBasetype == VecWznmVMRelationBasetype::_1N) && (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::SPEC)) {
									makecon = true;
								};

								delete rel2;
							};
						};
					};

					if (makecon) {
						if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
							dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
										qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, getStbByReftblsbs(dbswznm, Prjshort, tbl2->ref, 0, "Std"));

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
										VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

							genPnltbl_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

							delete tbl2;
						};
					};

					delete rel;
				};

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, 0);
				
				addQcostbuniv(dbswznm, Prjshort, qco->ref, tcos, tco);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtreluniv(dbswznm, con, tco, refLcl, refsLcl);

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				// column control / stub depends on type of associated relation
				if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
					if (rel->ixVBasetype == VecWznmVMRelationBasetype::AU1N) {
						dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
									qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, 0);

						addQcostbuniv(dbswznm, Prjshort, qco->ref, tcos, tco);

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
									VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

						genPnltbl_cjtreluniv(dbswznm, con, tco, refLcl, refsLcl);

					} else if (rel->ixVBasetype == VecWznmVMRelationBasetype::JPREF) {
					} else if (rel->ixVBasetype == VecWznmVMRelationBasetype::AUXPREF) {
					} else if (rel->ixVBasetype == VecWznmVMRelationBasetype::A1N) {
						if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
							dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
										qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, getStbByReftblsbs(dbswznm, Prjshort, tbl2->ref, 0, "Std"));

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
										VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

							genPnltbl_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

							delete tbl2;
						};
					};

					delete rel;
				};
//			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) {
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) {
					// as1n relation
					genPnltbl_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

				} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) {
					// asmn relation
					genPnltbl_cjtrelpl(dbswznm, con, tco, rel, refLcl, refsLcl);
				};

				delete rel;
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VSREF, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "sref" + StrMod::cap(tco->sref), tco->Short, 0);

				if (tco->refWznmMRelation == 0) {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
								VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

					genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);
				};

				if (dbswznm->loadStringBySQL("SELECT srefsKOption FROM TblWznmMVector WHERE ref = " + to_string(tco->fctUref), s)) {
					if (!StrMod::srefInSrefs(s, "notit")) {
						dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
									qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);
					};
				};

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VSREFS, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "srefs" + StrMod::cap(tco->sref), tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				if (dbswznm->loadStringBySQL("SELECT srefsKOption FROM TblWznmMVector WHERE ref = " + to_string(tco->fctUref), s)) {
					if (!StrMod::srefInSrefs(s, "notit")) {
						dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTITS, VecWznmWMQuerycolOccurrence::XML,
									qry->ref, qconum++, tco->ref, "tits" + StrMod::cap(tco->sref), tco->Short + "2", 0);
					};
				};
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		//} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
		//} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
			if (tco->refWznmMRelation == refAuxrel) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);
			};

		//} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::YESNO, VecWznmWMQuerycolOccurrence::XML,
						qry->ref, qconum++, tco->ref, "yesno" + StrMod::cap(tco->sref), tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMDATE, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMTIME, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMSTAMP, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMUSTAMP, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);
		};
	};

	delete qry;
	delete pnl;
};

bool WznmGenDetui::genPnlaux_cptstr(
			DbsWznm* dbswznm
			, WznmMPanel* pnl
			, const ubigint refRel
			, const ubigint refAuxrel
			, const ubigint refTbl
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: rel toplfull ; 2nd try: auxrel toplfull, 3rd try: reltbl plfull ; 4th try: pnl->sref
	if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(refRel, VecWznmVAMRelationTitleType::TOPLFULL, refLcl, s)) {
		if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(refAuxrel, VecWznmVAMRelationTitleType::TOPLFULL, refLcl, s)) {
			if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(refTbl, VecWznmVAMTableTitleType::PLFULL, refLcl, s)) {
				s = pnl->sref;
				found = false;
			};
		};
	};

	return found;
};

void WznmGenDetui::genPnl1n(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const vector<string>& sesspsts
			, WznmMCard* car
			, const vector<string>& carrecpsts
			, const vector<string>& carpsts
			, const uint pnlnum
			, WznmMRelation* pnlrel
			, const string& pnlsref
			, const ubigint refPst
			, const string& sbscond
			, WznmMTable* reltbl
			, const bool relenum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref, ref2;

	WznmMPanel* pnl = NULL;

	string uaccond;

	WznmMQuery* qry = NULL;
	WznmMQuery* oprqry = NULL;
	WznmMQuery* lrefqry = NULL;
	WznmMQuery* _qry = NULL;

	ListWznmMTable stbls;
	WznmMTable* stbl = NULL;

	WznmMTable* tbl = NULL;

	WznmMRelation* suprel = NULL;

	WznmMRelation* oprel = NULL;

	ubigint refQseltbl = 0;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	vector<unsigned int> icsModtcos;

	WznmMTablecol* reftco = NULL;
	WznmMTablecol* lattco = NULL;

	WznmMTablecol* vittco = NULL;
	ubigint refVit = 0;

	WznmMTablecol* psttco = NULL;
	WznmMTablecol* enumtco = NULL;
	WznmMTablecol* ordtco = NULL;

	WznmMTablecol* oprpsttco = NULL;
	WznmMTablecol* oprmodtco = NULL;

	int axis;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	WznmMFeed* fed = NULL;

	bool affil;

	list<Trg*> trgs;

	ubigint supref;
	unsigned int supnum;

	unsigned int qmdnum = 1;
	unsigned int qacnum = 1;
	unsigned int qconum = 1;
	unsigned int connum = 1;

	string s;
	char c;

	// --- analyze relation and targets
	affil = StrMod::srefInSrefs(pnlrel->srefsKOption, "affil");
	if (!affil && (pnlrel->supRefWznmMRelation != 0)) {
		if (dbswznm->tblwznmmrelation->loadRecByRef(pnlrel->supRefWznmMRelation, &suprel)) {
			affil = StrMod::srefInSrefs(suprel->srefsKOption, "affil");
			delete suprel;
		};
	};

	// - reftco, icsModtcos, vittco, psttco, enumtco, lattco, ordtco
	dbswznm->tblwznmmtablecol->loadRstByTbl(reltbl->ref, false, tcos);

	if (pnlrel->supRefWznmMRelation == 0) {
		ref = pnlrel->ref;
	} else {
		if (pnlrel->supIxVSubrole == VecWznmVMRelationSupSubrole::SPEC) {
			ref = pnlrel->ref;
		} else {
			// u1n
			ref = pnlrel->supRefWznmMRelation;
		};
	};

	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) reftco = tco;
		else if (tco->ixVAxisfct != VecWznmVMTablecolAxisfct::VOID) {
			if (tco->sref.length() > 1) if (atoi(tco->sref.substr(1).c_str()) > 0) icsModtcos.push_back(i);
		} else if (!vittco && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) && (tco->refWznmMRelation == ref) && ((tco->sref.rfind("VTbl")+4) == tco->sref.length())) {
			vittco = tco;
			dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(vittco->fctUref) + " AND sref = '" + pnlrel->Prefix + "'", refVit);
		} else if (!psttco && (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->refWznmMRelation == ref)) psttco = tco; // trefspec or trefuniv
		else if (!enumtco && (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) && (tco->refWznmMRelation == ref)) enumtco = tco;
		else if (!lattco && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) && (tco->refWznmMRelation == ref) && ((tco->sref.rfind("VLat")+4) == tco->sref.length())) lattco = tco;
		else if (!ordtco && ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || (tco->Eponymous && StrMod::srefInSrefs(tco->srefsKOption, "idx")))) ordtco = tco;
	};

	// - oprel
	dbswznm->tblwznmmrelation->loadRecBySQL("SELECT * FROM TblWznmMRelation WHERE TblWznmMRelation.supRefWznmMRelation = " + to_string(pnlrel->ref) + " AND TblWznmMRelation.supIxVSubrole = "
				+ to_string(VecWznmVMRelationSupSubrole::OP), &oprel);

	if (oprel) {
		// - oprpsttco, oprmodtco
		dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMRelation.supRefWznmMRelation = "
					+ to_string(oprel->ref) + " AND TblWznmMRelation.supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N), &oprpsttco);

		dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(oprel->refWznmMTable) + " AND ixVAxisfct = " + to_string(VecWznmVMTablecolAxisfct::PT), &oprmodtco);
	};

	// - "S" (1nsub1n) relation tables
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMRelation WHERE TblWznmMTable.refIxVTbl = " + to_string(VecWznmVMTableRefTbl::REL)
				+ " AND TblWznmMTable.refUref = TblWznmMRelation.ref AND TblWznmMRelation.supRefWznmMRelation = " + to_string(pnlrel->ref) + " AND TblWznmMRelation.supIxVSubrole = "
				+ to_string(VecWznmVMRelationSupSubrole::SUB1N), false, stbls);

	// - target card(s)
	Wznm::collectTrgs(dbswznm, sesspsts, car, carrecpsts, carpsts, reltbl, NULL, pnlrel, true, trgs);

	// --- generate panel
	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::RECLIST, car->ref, pnlnum, VecWznmVMPanelRefTbl::REL, pnlrel->ref, 0, pnlsref, false, sbscond, "");

	uaccond = "pre.ixCrdacc" + car->sref.substr(3+4) + "Incl(edit)";

	// -- basic controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnl1n_cptstr(dbswznm, pnl, pnlrel, reltbl, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);

			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButClipboard", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtRecord", VecWznmVMControlSubtype::VOID, "rec;emplong", 0, "", 0, 0, 0, "", "", "cap");

	if (relenum) {
		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButUp", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()&!sel.first()", "icon");

		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDown", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()&!sel.last()", "icon");
	};

	if (!trgs.empty()) {
		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButView", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "!sel()|(" + getAvail(trgs, false) + ")", "sel()", "icon");
		dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");

		if (affil) {
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
						VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButNew", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, getAvail(trgs, true), "", "icon");
			dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");
		};
	};

	if (affil) {
		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDelete", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()", "icon");
	};

	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TBL, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Tbl", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
	supnum = 1;

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TRS, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Trs", VecWznmVMControlSubtype::VOID, "goto", 0, "", 0, 0, 0, "", "", "cap;ddd");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Tsb", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtShowing", VecWznmVMControlSubtype::VOID, "showshort;empshort", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CSI, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "CsiQst", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VQrystate'", ref);
	dbswznm->tblwznmmfeed->insertNewRec(&fed, con->ref, VecWznmVMFeedSrcTbl::VEC, ref, "FeedF" + con->sref, "mnr.ong;ood.red;slm.yel;utd.grn", "", "");

	con->refWznmMFeed = fed->ref;
	dbswznm->tblwznmmcontrol->updateRec(con);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButRefresh", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	// --- generate query
	dbswznm->tblwznmmquery->insertNewRec(&qry, VecWznmVMQueryBasetype::STD, refWznmMVersion, 0, VecWznmVMQuerySupSubrole::VOID, 0, 0, 0, 0, "Qry" + pnl->sref.substr(3), true, 0, "", "");

	ref = dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, qry->ref, reltbl->ref, true, "");

	qry->refRTable = ref;
	qry->refWznmMTable = reltbl->ref;
	dbswznm->tblwznmmquery->updateRec(qry);

	dbswznm->tblwznmrmpanelmquery->insertNewRec(NULL, pnl->ref, qry->ref);

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "QSelect'", refQseltbl);

	// -- list functionality
	if (oprel) {
		// - adaptations to main query

		// LST: {rmv, ins} operators, OOLIST: {ina, inb, rmv, swp, toa, tob} operators
		if ( StrMod::srefInSrefs(oprel->srefsKOption, "ina") || StrMod::srefInSrefs(oprel->srefsKOption, "inb") || StrMod::srefInSrefs(oprel->srefsKOption, "swp") || StrMod::srefInSrefs(oprel->srefsKOption, "toa")
					|| StrMod::srefInSrefs(oprel->srefsKOption, "tob") ) qry->ixVBasetype = VecWznmVMQueryBasetype::OOLIST;
		else qry->ixVBasetype = VecWznmVMQueryBasetype::LIST;

		dbswznm->tblwznmmquery->updateRec(qry);

		dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, qry->ref, refQseltbl, false, "");

		dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, 1, 0, VecWznmVAMQueryClauseBasetype::JREF, "Tbl" + Prjshort + "QSelect.jref = &jref;", 0, 0, 0);
		dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, 2, 0, VecWznmVAMQueryClauseBasetype::EQN, reltbl->sref + ".ref = Tbl" + Prjshort + "QSelect.ref", 0, 0, 0);

		// - opr sub-query
		dbswznm->tblwznmmquery->insertNewRec(&oprqry, VecWznmVMQueryBasetype::STD, refWznmMVersion, qry->ref, VecWznmVMQuerySupSubrole::OPR, 0, 0, 0, 0, qry->sref + ".opr", false, 0, "", "");

		ref = dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, oprqry->ref, oprel->refWznmMTable, false, "");

		oprqry->refRTable = ref;
		oprqry->refWznmMTable = oprel->refWznmMTable;
		dbswznm->tblwznmmquery->updateRec(oprqry);

		ref = dbswznm->tblwznmmpreset->insertNewRec(NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL, "Pre" + pnlsref.substr(3) + ".opr.x1", getTcoArgtype(oprmodtco), 0, "");

		ref2 = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::FILT, oprqry->ref, qmdnum++, ref, VecWznmVMQuerymodRefTbl::TCO, oprmodtco->ref, "");

		dbswznm->tblwznmamqueryclause->insertNewRec(NULL, oprqry->ref, 1, 0, VecWznmVAMQueryClauseBasetype::PRE, oprpsttco->sref + " = &pre;", refPst, 0, 0);

		if (oprmodtco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) {
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, oprqry->ref, 2, ref2, VecWznmVAMQueryClauseBasetype::PRE, oprmodtco->sref + " = &pre;", ref, 0, 0);
		} else {
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, oprqry->ref, 2, ref2, VecWznmVAMQueryClauseBasetype::PRE, oprmodtco->sref + " >= &pre;", ref, 0, 0);
		};

		// - lref sub-query
		dbswznm->tblwznmmquery->insertNewRec(&lrefqry, VecWznmVMQueryBasetype::STD, refWznmMVersion, qry->ref, VecWznmVMQuerySupSubrole::LREF, 0, 0, 0, 0, qry->sref + ".lref", false, 0, "", "");

		ref = dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, lrefqry->ref, reltbl->ref, false, "");

		lrefqry->refRTable = ref;
		lrefqry->refWznmMTable = reltbl->ref;
		dbswznm->tblwznmmquery->updateRec(lrefqry);
	};

	if (qry->ixVBasetype == VecWznmVMQueryBasetype::STD) _qry = qry;
	else _qry = lrefqry;

	// -- presetting
	if (_qry == lrefqry) dbswznm->tblwznmamqueryclause->insertNewRec(NULL, lrefqry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::LAT, lattco->sref + " = &lat;", 0, 0, 0);
	if (vittco) dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::VIT, reltbl->sref + "." + vittco->sref + " = &vit;", 0, vittco->fctUref, refVit);
	dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::PRE, reltbl->sref + "." + psttco->sref + " = &pre;", refPst, 0, 0);

	// -- axes vs. exclusive branch functionality
	if (icsModtcos.size() > 0) {
		tco = tcos.nodes[icsModtcos[0]];

		if ((icsModtcos.size() == 1) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC)) {
			// exclusive branch
			ref = dbswznm->tblwznmmpreset->insertNewRec(NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL, "Pre" + pnlsref.substr(3) + ".x1", getTcoArgtype(tco), 0, "");

			ref2 = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::EXBRA, _qry->ref, 1, ref, VecWznmVMQuerymodRefTbl::TCO, tco->ref, "");

			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::EQN, reltbl->sref + "." + tco->sref + " = 0", 0, 0, 0);

			if (_qry == lrefqry) dbswznm->tblwznmamqueryclause->insertNewRec(NULL, lrefqry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::LAT, lattco->sref + " = &lat;", 0, 0, 0);
			if (vittco) dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::VIT, reltbl->sref + "." + vittco->sref + " = &vit;", 0, vittco->fctUref, refVit);
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::PRE, reltbl->sref + "." + psttco->sref + " = &pre;", refPst, 0, 0);
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::PRE, reltbl->sref + "." + tco->sref + " = &pre;", ref, 0, 0);

		} else {
			// axes / filter (typ. not used together with list functionality)
			axis = 0;

			for (unsigned int i = 0; i < icsModtcos.size(); i++) {
				tco = tcos.nodes[icsModtcos[i]];

				if (atoi(tco->sref.substr(1).c_str()) != axis) {
					axis = atoi(tco->sref.substr(1).c_str());

					ref = dbswznm->tblwznmmpreset->insertNewRec(NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL, "Pre" + pnlsref.substr(3) + ".x" + to_string(axis), getTcoArgtype(tco), 0, "");
				};

				ref2 = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::FILT, _qry->ref, qmdnum++, ref, VecWznmVMQuerymodRefTbl::TCO, tco->ref, "");

				s = reltbl->sref + "." + tco->sref;

				if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::PT) s += " = &pre;";
				else if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::SPT) s += " <= &pre;";
				else if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::EPT) s += " >= &pre;";

				dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::PRE, s, ref, 0, 0);
			};
		};
	};

	// - "S" (1nsub1n) table overrides
	for (unsigned int i = 0; i < stbls.nodes.size(); i++) {
		stbl = stbls.nodes[i];
		dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::STOVR, qry->ref, qmdnum++, 0, VecWznmVMQuerymodRefTbl::TBL, stbl->ref, "");
	};

	// -- query order
	if (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST) {
		dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, "ool", "Tbl" + Prjshort + "QSelect.jnum");
		dbswznm->tblwznmamqueryorder->insertNewRec(NULL, lrefqry->ref, enumtco->Short, enumtco->sref);
	} else {
		if (enumtco) dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, enumtco->Short, enumtco->sref);
		else if (ordtco) dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, ordtco->Short, ordtco->sref);
	};

	// --- query columns and corresponding controls

	// -- qref, jref and jnum
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QIDREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "qref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QJREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QJENUM, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jnum", "", 0);

	// -- query columns for table columns; here: only (id)ref and potential enum
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
				qry->ref, qconum++, reftco->ref, reftco->sref, "", 0);

	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
				qry->ref, qconum++, reftco->ref, "stub" + StrMod::cap(reftco->sref), reftco->Short, getStbByReftblsbs(dbswznm, Prjshort, reltbl->ref, 0, "Std"));

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(reftco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	// 1st try: reltbl sngshort ; 2nd try: reltbl sngfull ; 3rd try: reltbl->sref

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnl1n_colstr(dbswznm, reltbl, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);

			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};

	if ((qry->ixVBasetype != VecWznmVMQueryBasetype::OOLIST) && enumtco)
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB, qry->ref, qconum++, enumtco->ref, enumtco->sref, "", 0);

	// -- query columns for "S" (1nsub1n) relations
	c = 's';
	for (unsigned int i = 0; i < stbls.nodes.size(); i++) {
		stbl = stbls.nodes[i];

		if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMTablecol.ixVBasetype = "
					+ to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND TblWznmMRelation.supRefWznmMRelation = " + to_string(stbl->refUref) + " AND TblWznmMRelation.supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N), &tco)) {

			if (dbswznm->tblwznmmtable->loadRecByRef(tco->fctUref, &tbl)) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUBS, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "stubs" + StrMod::cap(c + tco->sref), c + tco->Short, getStbByReftblsbs(dbswznm, Prjshort, tbl->ref, 0, "Std"));

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(c + tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtstrel(dbswznm, con, stbl, tbl, refLcl, refsLcl);

				delete tbl;
			};
			delete tco;
		};
		c++;
	};

	delete pnl;
	delete qry;

	if (oprqry) delete oprqry;
	if (lrefqry) delete lrefqry;

	if (oprel) delete oprel;

	if (oprpsttco) delete oprpsttco;
	if (oprmodtco) delete oprmodtco;
};

bool WznmGenDetui::genPnl1n_cptstr(
			DbsWznm* dbswznm
			, WznmMPanel* pnl
			, WznmMRelation* rel
			, WznmMTable* tbl
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: rel toplfull ; 2nd try: suprel toplfull ; 3rd try: reltbl plfull ; 4th try: pnl->sref
	// works for spec as well

	if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::TOPLFULL, refLcl, s)) {
		if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->supRefWznmMRelation, VecWznmVAMRelationTitleType::TOPLFULL, refLcl, s)) {
			if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::PLFULL, refLcl, s)) {
				s = pnl->sref;
				found = false;
			};
		};
	};

	return found;
};

bool WznmGenDetui::genPnl1n_colstr(
			DbsWznm* dbswznm
			, WznmMTable* tbl
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::SNGSHORT, refLcl, s)) {
		if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::SNGFULL, refLcl, s)) {
			s = tbl->sref;
			found = false;
		};
	};

	return found;
};

void WznmGenDetui::genPnlmn(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const vector<string>& sesspsts
			, WznmMCard* car
			, const vector<string>& carrecpsts
			, const vector<string>& carpsts
			, const uint pnlnum
			, WznmMRelation* pnlrel
			, const string& pnlsref
			, const ubigint refPst
			, const string& sbscond
			, WznmMRelation* opprel
			, WznmMTable* reltbl
			, WznmMTable* maintbl
			, const bool relenum
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref, ref2;

	WznmMPanel* pnl = NULL;

	string uaccond;

	WznmMQuery* qry = NULL;
	WznmMQuery* oprqry = NULL;
	WznmMQuery* lrefqry = NULL;
	WznmMQuery* _qry = NULL;

	ListWznmMTable ttbls;
	WznmMTable* ttbl = NULL;

	WznmMTable* tbl = NULL;

	WznmMRelation* oprel = NULL;

	ubigint refQseltbl = 0;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	vector<unsigned int> icsModtcos;

	WznmMTablecol* psttco = NULL;
	WznmMTablecol* mtbtco = NULL;
	WznmMTablecol* enumtco = NULL;
	WznmMTablecol* lattco = NULL;

	WznmMTablecol* oprpsttco = NULL;
	WznmMTablecol* oprmodtco = NULL;

	int axis;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	WznmMFeed* fed = NULL;

	ubigint supref;
	unsigned int supnum;

	WznmMRelation* rel = NULL;
	WznmMRelation* rel2 = NULL;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	WznmMTable* tbl2 = NULL;

	list<Trg*> trgs;

	bool makecon;

	unsigned int qmdnum = 1;
	unsigned int qconum = 1;
	unsigned int qacnum = 1;
	unsigned int connum = 1;

	string s;
	char c;

	// --- analyze relation and targets

	// - icsModtcos, psttco, mtbtco, enumtco, lattco
	dbswznm->tblwznmmtablecol->loadRstByTbl(reltbl->ref, false, tcos);

	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (tco->ixVAxisfct != VecWznmVMTablecolAxisfct::VOID) {
			if (tco->sref.length() > 1) if (atoi(tco->sref.substr(1).c_str()) > 0) icsModtcos.push_back(i);
		} else if (!psttco && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->refWznmMRelation == pnlrel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == pnlrel->frRefWznmMTable)) psttco = tco;
		else if (!mtbtco && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->refWznmMRelation == opprel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == opprel->frRefWznmMTable)) mtbtco = tco;
		else if (!enumtco && (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) && (tco->refWznmMRelation == pnlrel->ref)) enumtco = tco;
		else if (!lattco && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) && (tco->refWznmMRelation == pnlrel->ref) && ((tco->sref.rfind("VLat")+4) == tco->sref.length())) lattco = tco;
	};

	// - oprel
	dbswznm->tblwznmmrelation->loadRecBySQL("SELECT * FROM TblWznmMRelation WHERE TblWznmMRelation.supRefWznmMRelation = " + to_string(pnlrel->supRefWznmMRelation) + " AND TblWznmMRelation.supIxVSubrole = "
				+ to_string(VecWznmVMRelationSupSubrole::OP), &oprel);

	if (!lattco) {
		// list functionality is one-way only ; the other way behaves like a reguler mn
		delete oprel;
		oprel = NULL;
	};

	if (oprel) {
		// - oprpsttco, oprmodtco
		dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMRelation.supRefWznmMRelation = "
					+ to_string(oprel->ref) + " AND TblWznmMRelation.supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N), &oprpsttco);

		dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(oprel->refWznmMTable) + " AND ixVAxisfct = " + to_string(VecWznmVMTablecolAxisfct::PT), &oprmodtco);
	};

	// - "T" (mnsubmn) relation tables
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMRelation WHERE TblWznmMTable.refIxVTbl = " + to_string(VecWznmVMTableRefTbl::REL)
				+ " AND TblWznmMTable.refUref = TblWznmMRelation.ref AND TblWznmMRelation.supRefWznmMRelation = " + to_string(pnlrel->supRefWznmMRelation) + " AND TblWznmMRelation.supIxVSubrole = "
				+ to_string(VecWznmVMRelationSupSubrole::SUBMN), false, ttbls);

	// - target card(s) ; toNotFr is not evaluated
	Wznm::collectTrgs(dbswznm, sesspsts, car, carrecpsts, carpsts, maintbl, NULL, pnlrel, true, trgs);

	// --- generate panel
	dbswznm->tblwznmmpanel->insertNewRec(&pnl, VecWznmVMPanelBasetype::RECLIST, car->ref, pnlnum, VecWznmVMPanelRefTbl::REL, pnlrel->ref, 0, pnlsref, false, sbscond, "");

	uaccond = "pre.ixCrdacc" + car->sref.substr(3+4) + "Incl(edit)";

	// -- basic controls
	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (genPnlmn_cptstr(dbswznm, pnl, pnlrel, maintbl, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
			s = StrMod::cap(s);

			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;
				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::SIDE,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "ButClipboard", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtRecord", VecWznmVMControlSubtype::VOID, "rec;emplong", 0, "", 0, 0, 0, "", "", "cap");

	if (relenum) {
		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButUp", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()&!sel.first()", "icon");

		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButDown", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()&!sel.last()", "icon");
	};

	if (!trgs.empty()) {
		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
					VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButView", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "!sel()|(" + getAvail(trgs, false) + ")", "sel()", "icon");
		dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, con->ref, "action", 0, "crdopen");
	};

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButAdd", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "", "icon");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButSub", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, uaccond, "sel()", "icon");

	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TBL, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "Tbl", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
	supnum = 1;

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TRS, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Trs", VecWznmVMControlSubtype::VOID, "goto", 0, "", 0, 0, 0, "", "", "cap;ddd");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TSB, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, supnum++, VecWznmVMControlScope::APP, 0, "Tsb", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "TxtShowing", VecWznmVMControlSubtype::VOID, "showshort;empshort", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CSI, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::APP, 0, "CsiQst", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "VQrystate'", ref);
	dbswznm->tblwznmmfeed->insertNewRec(&fed, con->ref, VecWznmVMFeedSrcTbl::VEC, ref, "FeedF" + con->sref, "mnr.ong;ood.red;slm.yel;utd.grn", "", "");

	con->refWznmMFeed = fed->ref;
	dbswznm->tblwznmmcontrol->updateRec(con);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "ButRefresh", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

	// --- generate query
	dbswznm->tblwznmmquery->insertNewRec(&qry, VecWznmVMQueryBasetype::STD, refWznmMVersion, 0, VecWznmVMQuerySupSubrole::VOID, 0, 0, 0, 0, "Qry" + pnl->sref.substr(3), true, 0, "", "");

	ref = dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, qry->ref, reltbl->ref, true, "");

	qry->refRTable = ref;
	qry->refWznmMTable = reltbl->ref;
	dbswznm->tblwznmmquery->updateRec(qry);

	dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, qry->ref, maintbl->ref, true, "m");

	dbswznm->tblwznmrmpanelmquery->insertNewRec(NULL, pnl->ref, qry->ref);

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "QSelect'", refQseltbl);

	// -- link to main table
	dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, 1, 0, VecWznmVAMQueryClauseBasetype::EQN, reltbl->sref + "." + mtbtco->sref + " = " + maintbl->sref + ".ref", 0, 0, 0);

	// -- list functionality
	if (oprel) {
		// - adaptations to main query

		// LST: {rmv, ins} operators, OOLIST: {ina, inb, rmv, swp, toa, tob} operators
		if ( StrMod::srefInSrefs(oprel->srefsKOption, "ina") || StrMod::srefInSrefs(oprel->srefsKOption, "inb") || StrMod::srefInSrefs(oprel->srefsKOption, "swp") || StrMod::srefInSrefs(oprel->srefsKOption, "toa")
					|| StrMod::srefInSrefs(oprel->srefsKOption, "tob") ) qry->ixVBasetype = VecWznmVMQueryBasetype::OOLIST;
		else qry->ixVBasetype = VecWznmVMQueryBasetype::LIST;

		dbswznm->tblwznmmquery->updateRec(qry);

		dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, qry->ref, refQseltbl, false, "");

		dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, 2, 0, VecWznmVAMQueryClauseBasetype::JREF, "Tbl" + Prjshort + "QSelect.jref = &jref;", 0, 0, 0);
		dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, 3, 0, VecWznmVAMQueryClauseBasetype::EQN, reltbl->sref + ".ref = Tbl" + Prjshort + "QSelect.ref", 0, 0, 0);

		// - opr sub-query
		dbswznm->tblwznmmquery->insertNewRec(&oprqry, VecWznmVMQueryBasetype::STD, refWznmMVersion, qry->ref, VecWznmVMQuerySupSubrole::OPR, 0, 0, 0, 0, qry->sref + ".opr", false, 0, "", "");

		ref = dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, oprqry->ref, oprel->refWznmMTable, false, "");

		oprqry->refRTable = ref;
		oprqry->refWznmMTable = oprel->refWznmMTable;
		dbswznm->tblwznmmquery->updateRec(oprqry);

		ref = dbswznm->tblwznmmpreset->insertNewRec(NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL, "Pre" + pnlsref.substr(3) + ".opr.x1", getTcoArgtype(oprmodtco), 0, "");

		ref2 = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::FILT, oprqry->ref, qmdnum++, ref, VecWznmVMQuerymodRefTbl::TCO, oprmodtco->ref, "");

		dbswznm->tblwznmamqueryclause->insertNewRec(NULL, oprqry->ref, 1, 0, VecWznmVAMQueryClauseBasetype::PRE, oprpsttco->sref + " = &pre;", refPst, 0, 0);

		if (oprmodtco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) {
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, oprqry->ref, 2, ref2, VecWznmVAMQueryClauseBasetype::PRE, oprmodtco->sref + " = &pre;", ref, 0, 0);
		} else {
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, oprqry->ref, 2, ref2, VecWznmVAMQueryClauseBasetype::PRE, oprmodtco->sref + " <= &pre;", ref, 0, 0);
		};

		// - lref sub-query
		dbswznm->tblwznmmquery->insertNewRec(&lrefqry, VecWznmVMQueryBasetype::STD, refWznmMVersion, qry->ref, VecWznmVMQuerySupSubrole::LREF, 0, 0, 0, 0, qry->sref + ".lref", false, 0, "", "");

		ref = dbswznm->tblwznmrmquerymtable->insertNewRec(NULL, lrefqry->ref, reltbl->ref, false, "");

		lrefqry->refRTable = ref;
		lrefqry->refWznmMTable = reltbl->ref;
		dbswznm->tblwznmmquery->updateRec(lrefqry);
	};

	if (qry->ixVBasetype == VecWznmVMQueryBasetype::STD) {
		_qry = qry;
		qacnum = 2;
	} else _qry = lrefqry;

	// -- presetting
	if (_qry == lrefqry) dbswznm->tblwznmamqueryclause->insertNewRec(NULL, lrefqry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::LAT, lattco->sref + " = &lat;", 0, 0, 0);
	dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::PRE, reltbl->sref + "." + psttco->sref + " = &pre;", refPst, 0, 0);

	// -- axes vs. exclusive branch functionality
	if (icsModtcos.size() > 0) {
		tco = tcos.nodes[icsModtcos[0]];

		if ((icsModtcos.size() == 1) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC)) {
			// exclusive branch
			ref = dbswznm->tblwznmmpreset->insertNewRec(NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL, "Pre" + pnlsref.substr(3) + ".x1", getTcoArgtype(tco), 0, "");

			ref2 = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::EXBRA, _qry->ref, qmdnum++, ref, VecWznmVMQuerymodRefTbl::TCO, tco->ref, "");

			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, 0, VecWznmVAMQueryClauseBasetype::EQN, reltbl->sref + "." + tco->sref + " = 0", 0, 0, 0);

			if (_qry == qry) dbswznm->tblwznmamqueryclause->insertNewRec(NULL, qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::EQN, reltbl->sref + "." + mtbtco->sref + " = " + maintbl->sref + ".ref", 0, 0, 0);
			if (_qry == lrefqry) dbswznm->tblwznmamqueryclause->insertNewRec(NULL, lrefqry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::LAT, lattco->sref + " = &lat;", 0, 0, 0);
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::PRE, reltbl->sref + "." + psttco->sref + " = &pre;", refPst, 0, 0);
			dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::PRE, reltbl->sref + "." + tco->sref + " = &pre;", ref, 0, 0);

		} else {
			// axes / filter (typ. not used together with list functionality)
			axis = 0;

			for (unsigned int i = 0; i < icsModtcos.size(); i++) {
				tco = tcos.nodes[icsModtcos[i]];

				if (atoi(tco->sref.substr(1).c_str()) != axis) {
					axis = atoi(tco->sref.substr(1).c_str());

					ref = dbswznm->tblwznmmpreset->insertNewRec(NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL, "Pre" + pnlsref.substr(3) + ".x" + to_string(axis), getTcoArgtype(tco), 0, "");
				};

				ref2 = dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::FILT, _qry->ref, qmdnum++, ref, VecWznmVMQuerymodRefTbl::TCO, tco->ref, "");

				s = reltbl->sref + "." + tco->sref;

				if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::PT) s += " = &pre;";
				else if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::SPT) s += " <= &pre;";
				else if (tco->ixVAxisfct == VecWznmVMTablecolAxisfct::EPT) s += " >= &pre;";

				dbswznm->tblwznmamqueryclause->insertNewRec(NULL, _qry->ref, qacnum++, ref2, VecWznmVAMQueryClauseBasetype::PRE, s, ref, 0, 0);
			};
		};
	};

	// - "T" (mnsubmn) table overrides
	for (unsigned int i = 0; i < ttbls.nodes.size(); i++) {
		ttbl = ttbls.nodes[i];
		dbswznm->tblwznmmquerymod->insertNewRec(NULL, VecWznmVMQuerymodBasetype::STOVR, qry->ref, qmdnum++, 0, VecWznmVMQuerymodRefTbl::TBL, ttbl->ref, "");
	};

	// -- query order
	if (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST) {
		dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, "ool", "Tbl" + Prjshort + "QSelect.jnum");
		dbswznm->tblwznmamqueryorder->insertNewRec(NULL, lrefqry->ref, enumtco->Short, enumtco->sref);
	} else {
		if (enumtco) dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, enumtco->Short, reltbl->sref + "." + enumtco->sref);
		else {
			// order by first eponymous indexed tco in maintbl
			dbswznm->tblwznmmtablecol->loadRstByTbl(maintbl->ref, false, tcos);
			for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
				tco = tcos.nodes[i];

				if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || (tco->Eponymous && StrMod::srefInSrefs(tco->srefsKOption, "idx")) ) {
					dbswznm->tblwznmamqueryorder->insertNewRec(NULL, qry->ref, tco->Short, maintbl->sref + "." + tco->sref);
					break;
				};
			};
		};
	};

	// -- qref, jref and jnum
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QIDREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "qref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QJREF, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jref", "", 0);
	dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::QJENUM, VecWznmWMQuerycolOccurrence::QTB, qry->ref, qconum++, 0, "jnum", "", 0);

	// -- query columns for main table columns; here: only (id)ref
	if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(maintbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::IDREF), &tco)) {
		dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
					qry->ref, qconum++, tco->ref, "m" + tco->sref, "", 0);

		dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
					qry->ref, qconum++, tco->ref, "stubM" + tco->sref, "m" + tco->Short, getStbByReftblsbs(dbswznm, Prjshort, maintbl->ref, 0, "Std"));

		dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
					VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "TcoM" + tco->Short, VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

		// 1st try: maintbl sngshort ; 2nd try: maintbl sngfull ; 3rd try: maintbl->sref

		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			if (genPnlmn_colstr(dbswznm, maintbl, refsLcl[i], s) || (refsLcl[i] == refLcl)) {
				s = StrMod::cap(s);

				ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

				if (refsLcl[i] == refLcl) {
					con->refJTitle = ref;
					con->Title = s;
					dbswznm->tblwznmmcontrol->updateRec(con);
				};
			};
		};

		delete tco;
	};

	// -- query columns for "T" (mnsubmn) relations
	c = 't';
	for (unsigned int i = 0; i < ttbls.nodes.size(); i++) {
		ttbl = ttbls.nodes[i];

		if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMTablecol.ixVBasetype = "
					+ to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND TblWznmMRelation.supRefWznmMRelation = " + to_string(ttbl->refUref) + " AND TblWznmMRelation.supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N), &tco)) {

			if (dbswznm->tblwznmmtable->loadRecByRef(tco->fctUref, &tbl)) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUBS, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "stubs" + StrMod::cap(c + tco->sref), c + tco->Short, getStbByReftblsbs(dbswznm, Prjshort, tbl->ref, 0, "Std"));

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(c + tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtstrel(dbswznm, con, ttbl, tbl, refLcl, refsLcl);

				delete tbl;
			};
			delete tco;
		};
		c++;
	};

	// -- query columns for relation table columns
	dbswznm->tblwznmmtablecol->loadRstByTbl(reltbl->ref, false, tcos);
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

		//} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTITS, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "tits" + StrMod::cap(tco->sref), tco->Short + "2", 0);
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
			if ((tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->refWznmMRelation != pnlrel->ref) && (tco->refWznmMRelation != opprel->ref)) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				// column control / stub only in selected cases of associated relations
				if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
					makecon = false;

					if (rel->ixVBasetype == VecWznmVMRelationBasetype::_1N) {
						if (rel->supRefWznmMRelation == 0) {
							makecon = true;

						} else {
							// look at super relation
							if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &rel2)) {
								if ((rel2->ixVBasetype == VecWznmVMRelationBasetype::_1N) && (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::SPEC)) {
									makecon = true;
								};

								delete rel2;
							};
						};
					};

					if (makecon) {
						if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
							dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
										qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, getStbByReftblsbs(dbswznm, Prjshort, tbl2->ref, 0, "Std"));

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
										VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

							genPnltbl_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

							delete tbl2;
						};
					};

					delete rel;
				};

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, 0);
				
				addQcostbuniv(dbswznm, Prjshort, qco->ref, tcos, tco);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtreluniv(dbswznm, con, tco, refLcl, refsLcl);

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				// column control / stub depends on type of associated relation
				if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
					if (rel->ixVBasetype == VecWznmVMRelationBasetype::AU1N) {
						dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
									qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, 0);

						addQcostbuniv(dbswznm, Prjshort, qco->ref, tcos, tco);

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
									VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

						genPnltbl_cjtreluniv(dbswznm, con, tco, refLcl, refsLcl);

					} else if (rel->ixVBasetype == VecWznmVMRelationBasetype::JPREF) {
					} else if (rel->ixVBasetype == VecWznmVMRelationBasetype::AUXPREF) {
					} else if (rel->ixVBasetype == VecWznmVMRelationBasetype::A1N) {
						if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
							dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::STUB, VecWznmWMQuerycolOccurrence::XML,
										qry->ref, qconum++, tco->ref, "stub" + StrMod::cap(tco->sref), tco->Short, getStbByReftblsbs(dbswznm, Prjshort, tbl2->ref, 0, "Std"));

							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
										VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

							genPnltbl_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

							delete tbl2;
						};
					};

					delete rel;
				};
//			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) {
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) {
					// as1n relation
					genPnltbl_cjtrel(dbswznm, con, tco, rel, refLcl, refsLcl);

				} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) {
					// asmn relation
					genPnltbl_cjtrelpl(dbswznm, con, tco, rel, refLcl, refsLcl);
				};

				delete rel;
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VSREF, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "sref" + StrMod::cap(tco->sref), tco->Short, 0);

				if (tco->refWznmMRelation == 0) {
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
								VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

					genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);
				};

				if (dbswznm->loadStringBySQL("SELECT srefsKOption FROM TblWznmMVector WHERE ref = " + to_string(tco->fctUref), s)) {
					if (!StrMod::srefInSrefs(s, "notit")) {
						dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTIT, VecWznmWMQuerycolOccurrence::XML,
									qry->ref, qconum++, tco->ref, "tit" + StrMod::cap(tco->sref), tco->Short + "2", 0);
					};
				};

			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);

				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VSREFS, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "srefs" + StrMod::cap(tco->sref), tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtvec(dbswznm, con, tco, refLcl, refsLcl);

				if (dbswznm->loadStringBySQL("SELECT srefsKOption FROM TblWznmMVector WHERE ref = " + to_string(tco->fctUref), s)) {
					if (!StrMod::srefInSrefs(s, "notit")) {
						dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::VTITS, VecWznmWMQuerycolOccurrence::XML,
									qry->ref, qconum++, tco->ref, "tits" + StrMod::cap(tco->sref), tco->Short + "2", 0);
					};
				};
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		//} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
		//} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
			if (tco->refWznmMRelation == pnlrel->ref) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, "", 0);
			};

		//} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::YESNO, VecWznmWMQuerycolOccurrence::XML,
						qry->ref, qconum++, tco->ref, "yesno" + StrMod::cap(tco->sref), tco->Short, 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
			if ((tco->ixVSubtype == VecWznmVMTablecolSubtype::TXTLONG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::TXTBASE64)) {
			} else {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::XML + VecWznmWMQuerycolOccurrence::BTB,
							qry->ref, qconum++, tco->ref, tco->sref, tco->Short, 0);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
							VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

				genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);
			};

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
			dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::TBL, VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB,
						qry->ref, qconum++, tco->ref, tco->sref, "", 0);

			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMDATE, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMTIME, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMSTAMP, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) {
				dbswznm->tblwznmmquerycol->appendNewRecToRst(qcos, &qco, VecWznmVMQuerycolBasetype::FTMUSTAMP, VecWznmWMQuerycolOccurrence::XML,
							qry->ref, qconum++, tco->ref, "ftm" + StrMod::cap(tco->sref), tco->Short, 0);
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TCO, 0, VecWznmVMControlHkTbl::PNL, pnl->ref, connum++, VecWznmVMControlHkSection::TBL,
						VecWznmVMControlRefTbl::QCO, qco->ref, supref, 1, supnum++, VecWznmVMControlScope::SHR, 0, "Tco" + StrMod::cap(tco->Short), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			genPnltbl_cjtstd(dbswznm, con, tco, refLcl, refsLcl);
		//} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
		};
	};

	delete pnl;
	delete qry;

	if (oprqry) delete oprqry;
	if (lrefqry) delete lrefqry;

	if (oprel) delete oprel;

	if (oprpsttco) delete oprpsttco;
	if (oprmodtco) delete oprmodtco;
};

bool WznmGenDetui::genPnlmn_cptstr(
			DbsWznm* dbswznm
			, WznmMPanel* pnl
			, WznmMRelation* rel
			, WznmMTable* tbl
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	// 1st try: rel toplfull ; 2nd try: reltbl plfull ; 3rd try: pnl->sref

	if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::TOPLFULL, refLcl, s)) {
		if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::PLFULL, refLcl, s)) {
			s = pnl->sref;
			found = false;
		};
	};

	return found;
};

bool WznmGenDetui::genPnlmn_colstr(
			DbsWznm* dbswznm
			, WznmMTable* tbl
			, const ubigint refLcl
			, string& s
		) {
	bool found = true;

	if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::SNGSHORT, refLcl, s)) {
		if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::SNGFULL, refLcl, s)) {
			s = tbl->sref;
			found = false;
		};
	};

	return found;
};

void WznmGenDetui::addQcostbuniv(
			DbsWznm* dbswznm
			, const string& Prjshort
			, const ubigint refQco
			, ListWznmMTablecol& tcos
			, WznmMTablecol* tco
		) {
	ubigint ref;

	WznmMTablecol* tco2 = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;

	// find table column of vector that corresponds to the universal relation
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco2 = tcos.nodes[j];
		if ((tco2->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) && (tco2->refWznmMRelation == tco->refWznmMRelation) && ((tco2->sref.rfind("VTbl")+4) == tco2->sref.length())) break;
	};

	dbswznm->tblwznmmvectoritem->loadRstByVec(tco2->fctUref, false, vits);

	// find sub relations to the universal relation
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUB), false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUBL), true, rels);

	// stubs
	for (unsigned int j = 0; j < rels.nodes.size(); j++) {
		rel = rels.nodes[j];

		// find corresponding vector item
		for (unsigned int k = 0; k < vits.nodes.size(); k++) {
			vit = vits.nodes[k];

			if (vit->sref == rel->Prefix) {
				ref = getStbByReftblsbs(dbswznm, Prjshort, rel->frRefWznmMTable, rel->frsRefWznmMSubset, "Std");

				if (ref != 0) dbswznm->tblwznmjmquerycolstub->insertNewRec(NULL, refQco, vit->ref, 0, ref);

				break;
			};
		};
	};
};

void WznmGenDetui::addConstbstd(
			DbsWznm* dbswznm
			, const string& Prjshort
			, WznmMControl* con
			, const ubigint refTbl
			, const ubigint refSbs
			, const bool sho
		) {
	ubigint ref, ref2;

	ref = getStbByReftblsbs(dbswznm, Prjshort, refTbl, refSbs, "Std");
	ref2 = 0;

	if (sho) {
		ref2 = getStbByReftblsbs(dbswznm, Prjshort, refTbl, refSbs, "Short");
		if (ref2 == 0) ref2 = ref;
	};

	if (ref != 0) {
		con->stdRefWznmMStub = ref;
		con->shoRefWznmMStub = ref2;

		dbswznm->tblwznmmcontrol->updateRec(con);
	};
};

bool WznmGenDetui::getCarstrSng(
			DbsWznm* dbswznm
			, WznmMCard* car
			, const ubigint refLcl
			, string& s
		) {
	bool found = false;

	s = car->sref;

	// 1st try: table/subset sngfull ; 2nd try: car sref

	if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) {
		found = dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(car->refUref, VecWznmVAMTableTitleType::SNGFULL, refLcl, s);
	} else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
		found = dbswznm->tblwznmamsubsettitle->loadTitBySbsTypLoc(car->refUref, VecWznmVAMSubsetTitleType::SNGFULL, refLcl, s);
	};

	return found;
};

bool WznmGenDetui::getCarstrPl(
			DbsWznm* dbswznm
			, WznmMCard* car
			, const ubigint refLcl
			, string& s
		) {
	bool found = false;

	s = car->sref;

	// 1st try: table/subset plfull ; 2nd try: car sref

	if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) {
		found = dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(car->refUref, VecWznmVAMTableTitleType::PLFULL, refLcl, s);
	} else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
		found = dbswznm->tblwznmamsubsettitle->loadTitBySbsTypLoc(car->refUref, VecWznmVAMSubsetTitleType::PLFULL, refLcl, s);
	};

	return found;
};

unsigned int WznmGenDetui::getTaglen(
			DbsWznm* dbswznm
			, const string sref
			, const string osrefWznmKTaggrp
			, const ubigint refLcl
		) {
	unsigned int retval = 0;

	WznmMTag* tag = NULL;

	string s;
	
	if (dbswznm->tblwznmmtag->loadRecByCpbSrfGrp(0, sref, osrefWznmKTaggrp, &tag)) {
		retval = StrMod::getCharcnt(tag->Title);
		if (dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(tag->ref, refLcl, s)) retval = StrMod::getCharcnt(s);

		delete tag;
	};

	return retval;
};

ubigint WznmGenDetui::getStbByReftblsbs(
			DbsWznm* dbswznm
			, const string& Prjshort
			, ubigint refTbl
			, const ubigint refSbs
			, const string& Short
		) {
	ubigint refStb = 0;

	if (refSbs != 0) dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMStub WHERE refWznmMSubset = " + to_string(refSbs) + " AND sref LIKE 'Stub" + Prjshort + "%" + Short + "'", refStb);

	if (refStb == 0) {
		if ((refTbl == 0) && (refSbs != 0)) dbswznm->loadRefBySQL("SELECT refWznmMTable FROM TblWznmMSubset WHERE ref = " + to_string(refSbs), refTbl);
		dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMStub WHERE refWznmMTable = " + to_string(refTbl) + " AND refWznmMSubset = 0 AND sref LIKE 'Stub" + Prjshort + "%" + Short + "'", refStb);
	};

	return refStb;
};

uint WznmGenDetui::getTcoArgtype(
			WznmMTablecol* tco
		) {
	uint retval = 0;

	if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG)) retval = VecWznmWArgtype::SREF;
	else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT)) retval = VecWznmWArgtype::SREF;
	else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC)) retval = VecWznmWArgtype::REF;
	else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN)) retval = VecWznmWArgtype::IX;
	else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) retval = VecWznmWArgtype::SREF;
	else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) retval = VecWznmWArgtype::INTVAL;
	else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) retval = VecWznmWArgtype::DBLVAL;
	else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = VecWznmWArgtype::DBLVAL;
		else retval = VecWznmWArgtype::INTVAL;
	};

	return retval;
};

string WznmGenDetui::andConds(
			const string& cond1
			, const string& cond2
			, const string& cond3
			, const string& cond4
			, const string& cond5
			, const string& cond6
		) {
	string retval;

	if (cond1 != "") retval = cond1;
	if (cond2 != "") {
		if (retval != "") retval += "&";
		retval += cond2;
	};
	if (cond3 != "") {
		if (retval != "") retval += "&";
		retval += cond3;
	};
	if (cond4 != "") {
		if (retval != "") retval += "&";
		retval += cond4;
	};
	if (cond5 != "") {
		if (retval != "") retval += "&";
		retval += cond5;
	};
	if (cond6 != "") {
		if (retval != "") retval += "&";
		retval += cond6;
	};

	return retval;
};

string WznmGenDetui::getAvail(
			const list<Trg*>& trgs
			, const bool newNotView
		) {
	// difference for ButNew: require edit rights on target card and cond2 (selection-dependent) can't be evaluated

	string retval;

	Trg* trg = NULL;

	string s;

	for (auto it = trgs.begin(); it != trgs.end(); it++) {
		trg = *it;

		if (newNotView) s = andConds("pre.ixCrdacc" + trg->srefWznmMCard.substr(3+4) + "Incl(edit)", trg->cond1, trg->carrecpstcond, trg->carpstcond, trg->sesspstcond);
		else s = andConds("pre.ixCrdacc" + trg->srefWznmMCard.substr(3+4) + "()", trg->cond1, trg->cond2, trg->carrecpstcond, trg->carpstcond, trg->sesspstcond);

		if (retval == "") retval = s;
		else if (retval[0] == '(') retval = retval + "|(" + s + ")";
		else retval = "(" + retval + ")|(" + s + ")";
	};

	return retval;
};
// IP cust --- IEND
