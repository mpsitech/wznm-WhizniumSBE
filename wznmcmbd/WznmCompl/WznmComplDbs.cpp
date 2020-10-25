/**
	* \file WznmComplDbs.cpp
	* Wznm operation processor - complement database structure (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmComplDbs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCompl;

/******************************************************************************
 namespace WznmComplDbs
 ******************************************************************************/

DpchRetWznm* WznmComplDbs::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmComplDbs* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint refTbl, refTco;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmAVKeylistKey klks;
	WznmAVKeylistKey* klk = NULL;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	Wznm::getVerlclrefs(dbswznm, refWznmMVersion, refLcl, refsLcl);

	// --- generate StubXxxxGroup and StubXxxxOwner
	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "MUsergroup'", refTbl))
				if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(refTbl) + " AND sref = 'sref'", refTco))
							dbswznm->tblwznmmstub->insertNewRec(NULL, VecWznmVMStubBasetype::TCO, refTbl, 0, "Stub" + Prjshort + "Group", false, refTco, false, "agroup");

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "MUser'", refTbl))
				if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(refTbl) + " AND sref = 'sref'", refTco))
							dbswznm->tblwznmmstub->insertNewRec(NULL, VecWznmVMStubBasetype::TCO, refTbl, 0, "Stub" + Prjshort + "Owner", false, refTco, false, "auser");

	// --- fill standard vectors
	fillVecKeylist(dbswznm, refWznmMVersion, Prjshort, refLcl);
	fillVecMaintable(dbswznm, refWznmMVersion, Prjshort, refLcl, refsLcl);
	fillVecValuelist(dbswznm, refWznmMVersion, Prjshort, refLcl);

	// --- fill vectors from tag groups
	dbswznm->tblwznmavkeylistkey->loadRstByKls(VecWznmVKeylist::KLSTWZNMKTAGGRP, false, klks);

	for (unsigned int i = 0; i < klks.nodes.size(); i++) {
		klk = klks.nodes[i];

		// standard vectors have already been filled in WznmGenBase
		if ( (klk->sref == "access") || (klk->sref == "error") || (klk->sref == "expstate") || (klk->sref == "iop") || (klk->sref == "lat") || (klk->sref == "lop") || (klk->sref == "oolop")
					|| (klk->sref == "qrystate") || (klk->sref == "recaccess") || (klk->sref == "reqitmode") || (klk->sref == "userlevel") ) continue;

		dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND osrefWznmKTaggrp = '" + klk->sref + "'" , false, vecs);

		for (unsigned int j = 0; j < vecs.nodes.size(); j++) {
			vec = vecs.nodes[j];

			Wznm::fillVecFromTaggrp(dbswznm, vec, klk->sref, refLcl, refsLcl);
		};
	};

	// --- generate presettings for main tables
	genMtbPres(dbswznm, refWznmMVersion, Prjshort, refLcl);

	// --- generate subset vectors for main tables
	genMtbSbsvecs(dbswznm, refWznmMVersion, Prjshort, refLcl, refsLcl);

	// --- generate checks based on subset rules of main tables
	genMtbSbschks(dbswznm, refWznmMVersion);

	// --- generate standard load functions based on relations
	genRelLoadfcts(dbswznm, refWznmMVersion);

	// --- generate load functions for tco-based stubs
	genStbLoadfcts(dbswznm, refWznmMVersion);
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmComplDbs::fillVecKeylist(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
		) {
	ubigint refVec;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	ListWznmMVector vecs2;
	WznmMVector* vec2 = NULL;

	ListWznmAMVectorTitle vats2;
	WznmAMVectorTitle* vat2 = NULL;

	// find VecXxxxVKeylist
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VKeylist", refVec)) {

		dbswznm->tblwznmmvector->loadRstByTypVer(VecWznmVMVectorBasetype::KLST, refWznmMVersion, false, vecs2);

		for (unsigned int i = 0; i < vecs2.nodes.size(); i++) {
			vec2 = vecs2.nodes[i];

			vit = new WznmMVectoritem();

			vit->vecRefWznmMVector = refVec;
			vit->vecNum = (i+1);
			vit->sref = vec2->sref;

			dbswznm->tblwznmmvectoritem->insertRec(vit);

			vits.nodes.push_back(vit);

			dbswznm->tblwznmamvectortitle->loadRstBySQL("SELECT * FROM TblWznmAMVectorTitle WHERE refWznmMVector = " + to_string(vec2->ref) + " AND x1IxVType = " + to_string(VecWznmVAMVectorTitleType::FULL), false, vats2);

			for (unsigned int j = 0; j < vats2.nodes.size(); j++) {
				vat2 = vats2.nodes[j];

				vitj = new WznmJMVectoritem(0, vit->ref, vat2->x2RefWznmMLocale, vat2->Title, "");

				dbswznm->tblwznmjmvectoritem->insertRec(vitj);
				vitjs.nodes.push_back(vitj);

				if (vat2->x2RefWznmMLocale == refLcl) {
					vit->refJ = vitj->ref;
					vit->Title = vitj->Title;

					dbswznm->tblwznmmvectoritem->updateRec(vit);
				};
			};
		};
	};
};

void WznmComplDbs::fillVecMaintable(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint refVec;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	ListWznmAMTableTitle tats;
	WznmAMTableTitle* tat = NULL;

	// find VecXxxxVMaintable
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VMaintable", refVec)) {

		// one vector item for each main table
		dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::MAIN, refWznmMVersion, false, tbls);

		for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
			tbl = tbls.nodes[i];

			// num +2 due to pre-existing "void" item
			vit = new WznmMVectoritem(0, refVec, i+2, tbl->sref, "", "", 0, "", "");
			
			dbswznm->tblwznmmvectoritem->insertRec(vit);
			vits.nodes.push_back(vit);

			dbswznm->tblwznmamtabletitle->loadRstBySQL("SELECT * FROM TblWznmAMTableTitle WHERE refWznmMTable = " + to_string(tbl->ref) + " AND x1IxVType = " + to_string(VecWznmVAMTableTitleType::SNGFULL), false, tats);

			for (unsigned int j = 0; j < tats.nodes.size(); j++) {
				tat = tats.nodes[j];

				vitj = new WznmJMVectoritem(0, vit->ref, tat->x2RefWznmMLocale, tat->Title, "");
				dbswznm->tblwznmjmvectoritem->insertRec(vitj); vitjs.nodes.push_back(vitj);

				if (tat->x2RefWznmMLocale == refLcl) {
					vit->refJ = vitj->ref;
					vit->Title = vitj->Title;
					dbswznm->tblwznmmvectoritem->updateRec(vit);
				};
			};
		};
	};
};

void WznmComplDbs::fillVecValuelist(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
		) {
	ubigint refVec;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	ListWznmMVector vecs2;
	WznmMVector* vec2 = NULL;

	ListWznmAMVectorTitle vats2;
	WznmAMVectorTitle* vat2 = NULL;

	// find VecXxxxVValuelist
	if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, "Vec" + Prjshort + "VValuelist", refVec)) {

		dbswznm->tblwznmmvector->loadRstByTypVer(VecWznmVMVectorBasetype::VLST, refWznmMVersion, false, vecs2);

		for (unsigned int i = 0; i < vecs2.nodes.size(); i++) {
			vec2 = vecs2.nodes[i];

			vit = new WznmMVectoritem();

			vit->vecRefWznmMVector = refVec;
			vit->vecNum = (i+1);
			vit->sref = vec2->sref;

			dbswznm->tblwznmmvectoritem->insertRec(vit);

			vits.nodes.push_back(vit);

			dbswznm->tblwznmamvectortitle->loadRstBySQL("SELECT * FROM TblWznmAMVectorTitle WHERE refWznmMVector = " + to_string(vec2->ref) + " AND x1IxVType = " + to_string(VecWznmVAMVectorTitleType::FULL), false, vats2);

			for (unsigned int j = 0; j < vats2.nodes.size(); j++) {
				vat2 = vats2.nodes[j];

				vitj = new WznmJMVectoritem(0, vit->ref, vat2->x2RefWznmMLocale, vat2->Title, "");

				dbswznm->tblwznmjmvectoritem->insertRec(vitj);
				vitjs.nodes.push_back(vitj);

				if (vat2->x2RefWznmMLocale == refLcl) {
					vit->refJ = vitj->ref;
					vit->Title = vitj->Title;

					dbswznm->tblwznmmvectoritem->updateRec(vit);
				};
			};
		};
	};
};

void WznmComplDbs::genMtbPres(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
		) {
	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	ListWznmMSubset sbss;
	WznmMSubset* sbs = NULL;

	ListWznmMPreset pres;
	WznmMPreset* pre = NULL;

	ListWznmAMTableTitle tblAtits;
	WznmAMTableTitle* tblAtit = NULL;

	ListWznmAMSubsetTitle sbsAtits;
	WznmAMSubsetTitle* sbsAtit = NULL;

	WznmJMPresetTitle* pjt = NULL;

	dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::MAIN, refWznmMVersion, false, tbls);

	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		// the scope may be changed to SESS in IexWznmBui
		dbswznm->tblwznmmpreset->appendNewRecToRst(pres, &pre, refWznmMVersion, VecWznmVMPresetRefTbl::TBL, tbl->ref, VecWznmVMPresetScope::CAR,
					"Pre" + Prjshort + "Ref" + StrMod::cap(tbl->Short), VecWznmWArgtype::REF, 0, "");

		tbl->refWznmMPreset = pre->ref;
		dbswznm->tblwznmmtable->updateRec(tbl);

		// tables have (multiple) localized titles
		dbswznm->tblwznmamtabletitle->loadRstByTbl(tbl->ref, false, tblAtits);

		for (unsigned int j = 0; j < tblAtits.nodes.size(); j++) {
			tblAtit = tblAtits.nodes[j];

			if (tblAtit->x1IxVType == VecWznmVAMTableTitleType::SNGFULL) {
				dbswznm->tblwznmjmpresettitle->insertNewRec(&pjt, pre->ref, tblAtit->x2RefWznmMLocale, tblAtit->Title);

				if (pjt->x1RefWznmMLocale == refLcl) {
					pre->refJTitle = pjt->ref;
					pre->Title = pjt->Title;

					dbswznm->tblwznmmpreset->updateRec(pre);
				};
			};
		};

		// each subset gets its own presetting
		dbswznm->tblwznmmsubset->loadRstBySQL("SELECT * FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(tbl->ref) + " ORDER BY sref ASC", false, sbss);

		for (unsigned int j = 0; j < sbss.nodes.size(); j++) {
			sbs = sbss.nodes[j];

			dbswznm->tblwznmmpreset->appendNewRecToRst(pres, &pre, refWznmMVersion, VecWznmVMPresetRefTbl::SBS, sbs->ref, VecWznmVMPresetScope::CAR,
						"Pre" + Prjshort + "Ref" + StrMod::cap(sbs->Short), VecWznmWArgtype::REF, 0, "");

			sbs->refWznmMPreset = pre->ref;
			dbswznm->tblwznmmsubset->updateRec(sbs);

			// subsets have (multiple) localized titles
			dbswznm->tblwznmamsubsettitle->loadRstBySbs(sbs->ref, false, sbsAtits);

			for (unsigned int k = 0; k < sbsAtits.nodes.size(); k++) {
				sbsAtit = sbsAtits.nodes[k];

				if (sbsAtit->x1IxVType == VecWznmVAMSubsetTitleType::SNGFULL) {
					dbswznm->tblwznmjmpresettitle->insertNewRec(&pjt, pre->ref, sbsAtit->x2RefWznmMLocale, sbsAtit->Title);

					if (pjt->x1RefWznmMLocale == refLcl) {
						pre->refJTitle = pjt->ref;
						pre->Title = pjt->Title;

						dbswznm->tblwznmmpreset->updateRec(pre);
					};
				};
			};
		};
	};
};

void WznmComplDbs::genMtbSbsvecs(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	ListWznmMSubset sbss;
	WznmMSubset* sbs = NULL;

	WznmMVector* vec = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitjs;
	WznmJMVectoritem* vitj = NULL;

	ListWznmAMSubsetTitle sats;
	WznmAMSubsetTitle* sat = NULL;

	dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::MAIN, refWznmMVersion, false, tbls);
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		dbswznm->tblwznmmsubset->loadRstBySQL("SELECT * FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(tbl->ref) + " ORDER BY sref ASC", false, sbss);
		if (sbss.nodes.size() > 0) {
			dbswznm->tblwznmmvector->insertNewRec(&vec, VecWznmVMVectorBasetype::OR, refWznmMVersion, VecWznmVMVectorHkTbl::TBL, tbl->ref, 0, "Vec" + Prjshort + "W" + tbl->sref.substr(3+4) + "Subset", "", "");

			for (unsigned int j = 0; j < sbss.nodes.size(); j++) {
				sbs = sbss.nodes[j];

				dbswznm->tblwznmmvectoritem->appendNewRecToRst(vits, &vit, vec->ref, (j+1), sbs->sref, "", "", 0, "", "");

				dbswznm->tblwznmamsubsettitle->loadRstBySQL("SELECT * FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = " + to_string(sbs->ref) + " AND x1IxVType = " + to_string(VecWznmVAMSubsetTitleType::SNGFULL), false, sats);

				for (unsigned int k = 0; k < sats.nodes.size(); k++) {
					sat = sats.nodes[k];

					dbswznm->tblwznmjmvectoritem->appendNewRecToRst(vitjs, &vitj, vit->ref, sat->x2RefWznmMLocale, sat->Title, "");

					if (sat->x2RefWznmMLocale == refLcl) {
						vit->refJ = vitj->ref;
						vit->Title = vitj->Title;
						dbswznm->tblwznmmvectoritem->updateRec(vit);
					};
				};
			};

			delete vec;
		};
	};
};

void WznmComplDbs::genMtbSbschks(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
		) {
	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;
	map<string,ubigint> tcorefs;

	ListWznmMCheck tblchks;

	ListWznmMSubset sbss;
	WznmMSubset* sbs = NULL;

	set<string> skipchks;
	set<string> chks;

	Expr expr;

	uint ixVBasetype;
	string tcoshort;

	string s;
	size_t ptr;

	dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::MAIN, refWznmMVersion, false, tbls);
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		dbswznm->tblwznmmsubset->loadRstBySQL("SELECT * FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(tbl->ref) + " ORDER BY sref ASC", false, sbss);

		if (sbss.nodes.size() > 0) {
			tcorefs.clear();

			dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tcos);
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];
				if (tco->Short != "") tcorefs[tco->Short] = tco->ref;
			};

			skipchks.clear();
			chks.clear();

			dbswznm->tblwznmmcheck->loadRstBySQL("SELECT * FROM TblWznmMCheck WHERE refWznmMTable = " + to_string(tbl->ref), false, tblchks);
			for (unsigned int j = 0; j < tblchks.nodes.size(); j++) skipchks.insert(tblchks.nodes[j]->sref);

			for (unsigned int j = 0; j < sbss.nodes.size(); j++) {
				sbs = sbss.nodes[j];
				if (sbs->Cond != "") if (expr.tokenize(sbs->Cond)) if (expr.parse()) genMtbSbschks_collect(expr.root, chks);
			};

			for (auto it = chks.begin(); it != chks.end(); it++) {
				s = *it;

				if (skipchks.find(s) == skipchks.end()) {
					if ((s.rfind("Eq")+2) == s.length()) {
						ixVBasetype = VecWznmVMCheckBasetype::EQ;
						tcoshort = s.substr(0, s.length()-2);

					} else if ((s.rfind("Incl")+4) == s.length()) {
						ixVBasetype = VecWznmVMCheckBasetype::INCL;
						tcoshort = s.substr(0, s.length()-4);

					} else if (s == "isLeaf") {
						ixVBasetype = VecWznmVMCheckBasetype::LEAF;
						tcoshort = "sup";

					} else if ((s.rfind("inSbs")+5) == s.length()) {
						ptr = s.find('.');

						if (ptr != string::npos) {
							ixVBasetype = VecWznmVMCheckBasetype::SBS;
							tcoshort = s.substr(0, ptr);
						} else continue;

					} else continue;

					auto it2 = tcorefs.find(tcoshort);
					if (it2 != tcorefs.end()) dbswznm->tblwznmmcheck->insertNewRec(NULL, ixVBasetype, tbl->ref, it2->second, 0, s, "");
				};
			};
		};
	};
};

void WznmComplDbs::genMtbSbschks_collect(
			Expr::Node* node
			, set<string>& chks
		) {
	size_t ptr;

	if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
		if ( ((node->key.rfind("Eq")+2) == node->key.length()) || ((node->key.rfind("Incl")+4) == node->key.length()) || (node->key == "isLeaf") ) chks.insert(node->key);
		else {
			ptr = node->key.find('.');
			if (ptr != string::npos) if (node->key.substr(ptr+1) == "inSbs") chks.insert(node->key);
		};
	};

	for (unsigned int i = 0; i < node->subs.size(); i++) genMtbSbschks_collect(node->subs[i], chks);
};

void WznmComplDbs::genRelLoadfcts(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
		) {
	ubigint ref, ref2;

	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;
	WznmMTablecol* tco2 = NULL;
	WznmMTablecol* tco3 = NULL;

	WznmMTablecol* spttco = NULL;
	WznmMTablecol* epttco = NULL;

	WznmAMTableLoadfct lfc;

	string ord;
	string lat;
	bool attr;

	uint cnt;

	bool found;

	// -- inc/11/u1nsubinc/u1nsub11 relations: rec two-way
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::INC), false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_11), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::U1NSUBINC), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::U1NSUB11), true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		// - load to by from
		dbswznm->tblwznmmtablecol->loadRstByTbl(rel->toRefWznmMTable, false, tcos);
		
		found = false;
		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			if ( ((tco->refWznmMRelation == rel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == rel->frRefWznmMTable))
						|| ((tco->refWznmMRelation == rel->supRefWznmMRelation) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) ) {
				found = true;
				break;
			};
		};

		tco2 = NULL;

		if (found && ((rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBINC) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11))) {
			// find table vector tco
			found = false;

			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco2 = tcos.nodes[j];

				if ((tco2->refWznmMRelation == rel->supRefWznmMRelation) && (tco2->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) && ((tco2->sref.rfind("VTbl")+4) == tco2->sref.length())) {
					found = true;
					break;
				};
			};
		};
		
		if (found) {
			if (tco2) lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REC, "loadRecBy" + StrMod::cap(tco2->Short) + StrMod::cap(tco->Short), "", tco2->sref + ";" + tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
			else lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REC, "loadRecBy" + StrMod::cap(tco->Short), "", tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);

			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
		};

		// - load from by to
		dbswznm->tblwznmmtablecol->loadRstByTbl(rel->frRefWznmMTable, false, tcos);

		found = false;
		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			if ( (tco->refWznmMRelation == rel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == rel->toRefWznmMTable) ) {
				found = true;
				break;
			};
		};

		if (found) {
			lfc = WznmAMTableLoadfct(0, rel->frRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REC, "loadRecBy" + StrMod::cap(tco->Short), "", tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
		};
	};

	// -- 1n/l1n/u1n/lu1n relations with affil: rst ; u1n/lu1n: requires at least one u1nsub sub-relation
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1N), false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::L1N), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::U1N), true, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::LU1N), true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];
		
		if (StrMod::srefInSrefs(rel->srefsKOption, "affil")) {
			dbswznm->tblwznmmtablecol->loadRstByTbl(rel->toRefWznmMTable, false, tcos);

			found = false;
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];

				if ( (tco->refWznmMRelation == rel->ref) && (((tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == rel->frRefWznmMTable)) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) ) {
					found = true;
					break;
				};
			};

			tco2 = NULL;

			if ((rel->ixVBasetype == VecWznmVMRelationBasetype::U1N) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1N)) {
				if (found) {
					// find sub-relation
					found = false;

					dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::SUB), cnt);
					if (cnt > 0) found = true;
				};

				if (found) {
					// find table vector tco
					found = false;

					for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
						tco2 = tcos.nodes[j];

						if ((tco2->refWznmMRelation == rel->ref) && (tco2->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) && ((tco2->sref.rfind("VTbl")+4) == tco2->sref.length())) {
							found = true;
							break;
						};
					};
				};
			};

			if (found) {
				if (tco2) lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstBy" + StrMod::cap(tco2->Short) + StrMod::cap(tco->Short), "", tco2->sref + ";" + tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
				else lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstBy" + StrMod::cap(tco->Short), "", tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
				
				for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
					tco = tcos.nodes[j];

					if ( ((tco->refWznmMRelation == rel->ref) && (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM)) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF)
								|| ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) && tco->Eponymous && StrMod::srefInSrefs(tco->srefsKOption, "idx")) ) {
						lfc.ordSrefsWznmMTablecol = tco->sref;
						break;
					};
				};

				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
			};
		};
	};

	// -- h1n relations: special
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::H1N), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		dbswznm->tblwznmmtablecol->loadRstByTbl(rel->toRefWznmMTable, false, tcos);

		found = false;
		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			if ((tco->refWznmMRelation == rel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == rel->frRefWznmMTable)) {
				found = true;
				break;
			};
		};

		if (found) {
			ord = "";
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco2 = tcos.nodes[j];

				if ( ((tco2->refWznmMRelation == rel->ref) && (tco2->ixVBasetype == VecWznmVMTablecolBasetype::ENUM)) || (tco2->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF)
							|| ((tco2->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) && tco2->Eponymous && StrMod::srefInSrefs(tco2->srefsKOption, "idx")) ) {
					ord = tco2->sref;
					break;
				};
			};

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::CONFIRM, "confirmByRef", "", "ref", "", VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REF, "loadSupByRef", tco->sref, "ref", "", VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REFS, "loadRefsBySup", "ref", tco->sref, ord, VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstBySup", "", tco->sref, ord, VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::HREFSUP, "loadHrefsup", "ref", tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::HRSTUP, "loadHrstup", "", tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::HREFSDOWN, "loadHrefsdown", "ref", "ref", "", VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::HRSTDOWN, "loadHrstdown", "", "ref", "", VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
		};
	};

	// -- mn/lmn relations: opposite refs if no attributes, rst else ; refs on side of lat
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::MN), false, rels);
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::LMN), true, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		found = dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N), ref);
		if (found) found = dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::TO1N), ref2);

		if (found) {
			dbswznm->tblwznmmtablecol->loadRstByTbl(rel->refWznmMTable, false, tcos);

			// check for attributes
			attr = false;
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];

				if ((tco->refWznmMRelation != ref) && (tco->refWznmMRelation != ref2) && (tco->ixVBasetype != VecWznmVMTablecolBasetype::IDREF)) {
					attr = true;
					break;
				};
			};

			// find from1n/to1n tco/tco2
			found = false;
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];

				if ((tco->refWznmMRelation == ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == rel->frRefWznmMTable)) {
					found = true;
					break;
				};
			};

			if (found) {
				found = false;
				for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
					tco2 = tcos.nodes[j];

					if ((tco2->refWznmMRelation == ref2) && (tco2->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco2->fctUref == rel->toRefWznmMTable)) {
						found = true;
						break;
					};
				};
			};

			if (found) {
				// - from1n -> to1n
				ord = "";
				lat = "";
				for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
					tco3 = tcos.nodes[j];

					if ((tco3->refWznmMRelation == tco->refWznmMRelation) && (tco3->ixVBasetype == VecWznmVMTablecolBasetype::ENUM)) {
						ord = tco3->sref;
					} else if ((tco3->refWznmMRelation == tco->refWznmMRelation) && (tco3->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) && ((tco3->sref.rfind("VLat")+4) == tco3->sref.length())) {
						lat = tco3->sref;
					};
				};

				if (attr) lfc = WznmAMTableLoadfct(0, rel->refWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstBy" + StrMod::cap(tco->Short), "", tco->sref, ord, VecWznmVAMTableLoadfctLimtype::VOID);
				else lfc = WznmAMTableLoadfct(0, rel->refWznmMTable, VecWznmVAMTableLoadfctLoadtype::REFS, "load" + StrMod::cap(tco2->Short) + "sBy" + StrMod::cap(tco->Short), tco2->sref, tco->sref, ord, VecWznmVAMTableLoadfctLimtype::VOID);

				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

				if (lat != "") {
					lfc = WznmAMTableLoadfct(0, rel->refWznmMTable, VecWznmVAMTableLoadfctLoadtype::REFS, "loadRefsBy" + StrMod::cap(tco->Short) + "Lat", "ref", tco->sref + ";" + lat, ord, VecWznmVAMTableLoadfctLimtype::VOID);
					if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
				};

				// - to1n -> from1n
				ord = "";
				lat = "";
				for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
					tco3 = tcos.nodes[j];

					if ((tco3->refWznmMRelation == tco2->refWznmMRelation) && (tco3->ixVBasetype == VecWznmVMTablecolBasetype::ENUM)) {
						ord = tco3->sref;
					} else if ((tco3->refWznmMRelation == tco2->refWznmMRelation) && (tco3->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) && ((tco3->sref.rfind("VLat")+4) == tco3->sref.length())) {
						lat = tco3->sref;
					};
				};

				if (attr) lfc = WznmAMTableLoadfct(0, rel->refWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstBy" + StrMod::cap(tco2->Short), "", tco2->sref, ord, VecWznmVAMTableLoadfctLimtype::VOID);
				else lfc = WznmAMTableLoadfct(0, rel->refWznmMTable, VecWznmVAMTableLoadfctLoadtype::REFS, "load" + StrMod::cap(tco->Short) + "sBy" + StrMod::cap(tco2->Short), tco->sref, tco2->sref, ord, VecWznmVAMTableLoadfctLimtype::VOID);

				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

				if (lat != "") {
					lfc = WznmAMTableLoadfct(0, rel->refWznmMTable, VecWznmVAMTableLoadfctLoadtype::REFS, "loadRefsBy" + StrMod::cap(tco2->Short) + "Lat", "ref", tco2->sref + ";" + lat, ord, VecWznmVAMTableLoadfctLimtype::VOID);
					if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
				};
			};
		};
	};

	// -- 1nsub1n: loadRstByM
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1NSUB1N), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMRelation, TblWznmMTablecol WHERE TblWznmMRelation.supRefWznmMRelation = " + to_string(rel->ref) + " AND TblWznmMRelation.supIxVSubrole = "
					+ to_string(VecWznmVMRelationSupSubrole::TO1N) + " AND TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMTablecol.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF), &tco)) {

			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMRelation, TblWznmMTablecol WHERE TblWznmMRelation.supRefWznmMRelation = " + to_string(rel->ref) + " AND TblWznmMRelation.supIxVSubrole = "
						+ to_string(VecWznmVMRelationSupSubrole::FROM1N) + " AND TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMTablecol.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF), &tco2)) {

				lfc = WznmAMTableLoadfct(0, rel->refWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstByM", "", tco->sref, tco2->sref, VecWznmVAMTableLoadfctLimtype::VOID);
				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

				delete tco2;
			};

			delete tco;
		};
	};

	// -- mnsubmn: loadRstByR
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::MNSUBMN), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];

		if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMRelation, TblWznmMTablecol WHERE TblWznmMRelation.supRefWznmMRelation = " + to_string(rel->ref) + " AND TblWznmMRelation.supIxVSubrole = "
					+ to_string(VecWznmVMRelationSupSubrole::MN1N) + " AND TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMTablecol.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF), &tco)) {

			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMRelation, TblWznmMTablecol WHERE TblWznmMRelation.supRefWznmMRelation = " + to_string(rel->ref) + " AND TblWznmMRelation.supIxVSubrole = "
						+ to_string(VecWznmVMRelationSupSubrole::FROM1N) + " AND TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMTablecol.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF), &tco2)) {

				lfc = WznmAMTableLoadfct(0, rel->refWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstByR", "", tco->sref, tco2->sref, VecWznmVAMTableLoadfctLimtype::VOID);
				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

				delete tco2;
			};

			delete tco;
		};
	};

	// -- aux relations: rst
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::AUX), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];
		
		dbswznm->tblwznmmtablecol->loadRstByTbl(rel->toRefWznmMTable, false, tcos);

		found = false;
		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			if ((tco->refWznmMRelation == rel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == rel->frRefWznmMTable)) {
				found = true;
				break;
			};
		};

		if (found) {
			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstBy" + StrMod::cap(tco->Short), "", tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);

			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];

				if ((tco->refWznmMRelation == rel->ref) && (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM)) {
					lfc.ordSrefsWznmMTablecol = tco->sref;
					break;

				} else if ( (tco->refWznmMRelation != rel->ref) && ((tco->ixVAxisfct != VecWznmVMTablecolAxisfct::VOID) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF)
							|| ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) && tco->Eponymous && StrMod::srefInSrefs(tco->srefsKOption, "idx"))) ) {
					if (lfc.ordSrefsWznmMTablecol == "") lfc.ordSrefsWznmMTablecol = tco->sref;
					else lfc.ordSrefsWznmMTablecol += ";" + tco->sref;
				};
			};

			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
		};
	};

	// -- j relations: rst, rec
	// behavior in line with WznmWrsrvQry
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::J), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];
		
		dbswznm->tblwznmmtablecol->loadRstByTbl(rel->toRefWznmMTable, false, tcos);

		found = false;
		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			if ((tco->refWznmMRelation == rel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == rel->frRefWznmMTable)) {
				found = true;
				break;
			};
		};

		if (found) {
			spttco = NULL;
			epttco = NULL;

			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco2 = tcos.nodes[j];

				if (tco2->ixVAxisfct != VecWznmVMTablecolAxisfct::VOID) {
					if (tco2->sref.find("x1") != 0) break;

					if (!spttco) spttco = tco2;
					else {
						epttco = tco2;
						break;
					};
				};
			};

			if (spttco) {
				if (spttco->ixVAxisfct == VecWznmVMTablecolAxisfct::PT) {
					lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REC, "loadRecBy" + StrMod::cap(tco->Short) + StrMod::cap(spttco->Short), "", tco->sref + ";" + spttco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
					if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
				};
				
				lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstBy" + StrMod::cap(tco->Short), "", tco->sref, spttco->sref, VecWznmVAMTableLoadfctLimtype::VOID);
				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
			};
		};
	};

	// -- clust relations: refs, rst
	dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::CLUST), false, rels);

	for (unsigned int i = 0; i < rels.nodes.size(); i++) {
		rel = rels.nodes[i];
		
		dbswznm->tblwznmmtablecol->loadRstByTbl(rel->toRefWznmMTable, false, tcos);

		found = false;
		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			if ((tco->refWznmMRelation == rel->ref) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) && (tco->fctUref == rel->frRefWznmMTable)) {
				found = true;
				break;
			};
		};

		if (found) {
			ord = "";
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco2 = tcos.nodes[j];

				if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) && tco->Eponymous && StrMod::srefInSrefs(tco->srefsKOption, "idx")) ) {
					ord = tco->sref;
					break;
				};
			};

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REFS, "loadRefsBy" + StrMod::cap(tco->Short), "ref", tco->sref, ord, VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);

			lfc = WznmAMTableLoadfct(0, rel->toRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::RST, "loadRstBy" + StrMod::cap(tco->Short), "", tco->sref, ord, VecWznmVAMTableLoadfctLimtype::VOID);
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(lfc.refWznmMTable) + " AND Fctname = '" + lfc.Fctname + "'", ref)) dbswznm->tblwznmamtableloadfct->insertRec(&lfc);
		};
	};
};

void WznmComplDbs::genStbLoadfcts(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
		) {
	ubigint ref;

	ListWznmMStub stbs;
	WznmMStub* stb = NULL;

	WznmMTablecol* tco = NULL;

	dbswznm->tblwznmmstub->loadRstBySQL("SELECT TblWznmMStub.* FROM TblWznmMStub, TblWznmMTable WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = "
				+ to_string(refWznmMVersion) + " AND TblWznmMStub.ixVBasetype = " + to_string(VecWznmVMStubBasetype::TCO), false, stbs);

	for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
		stb = stbs.nodes[i];

		if ((stb->ixVBasetype == VecWznmVMStubBasetype::TCO) && !stb->Hierarch) {
			if (dbswznm->tblwznmmtablecol->loadRecByRef(stb->refWznmMTablecol, &tco)) {
				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(tco->tblRefWznmMTable) + " AND Fctname = 'load" + StrMod::cap(tco->Short) + "ByRef'", ref)) {
					dbswznm->tblwznmamtableloadfct->insertNewRec(NULL, tco->tblRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::STRING, "load" + StrMod::cap(tco->Short) + "ByRef", tco->sref, "ref", "", VecWznmVAMTableLoadfctLimtype::VOID);
				};
				delete tco;
			};
		};
	};
};
// IP cust --- IEND


