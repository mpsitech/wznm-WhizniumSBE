/**
	* \file WznmWrdbsDbs.cpp
	* Wznm operation processor - write database access library C++ code (implementation)
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

#include "WznmWrdbsDbs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrdbs;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrdbsDbs
 ******************************************************************************/

DpchRetWznm* WznmWrdbsDbs::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrdbsDbs* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ListWznmMTable tbls;
	ListWznmMTable qtbs;
	ListWznmMVector vecs;

	fstream hfile;
	fstream veccppfile;
	fstream cppfile;

	WznmMVersion* ver = NULL;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;

	bool marMy;
	bool pg;
	bool lite;
	vector<string> dbss;

	bool hasvecs;

	string s;

	dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver);

	Wznm::getVerlcls(dbswznm, refWznmMVersion, refLcl, refsLcl, lcls);

	marMy = ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO + VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) != 0);
	pg = ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG) != 0);
	lite = ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE) != 0);
	if (marMy) dbss.push_back("My");
	if (pg) dbss.push_back("Pg");
	if (lite) dbss.push_back("Lite");

	// load storage tables
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE ixVBasetype <> " + to_string(VecWznmVMTableBasetype::QRY) + " AND refWznmMVersion = "
				+ to_string(refWznmMVersion) + " ORDER BY sref ASC", false, tbls);

	// load query tables
	dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::QRY, refWznmMVersion, false, qtbs);

	// load database-specific vectors
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ((ixVBasetype = " + to_string(VecWznmVMVectorBasetype::LIN) + ") OR (ixVBasetype = "
				+ to_string(VecWznmVMVectorBasetype::OR) + ")) AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::TBL) + " AND hkUref = 0 ORDER BY sref ASC", false, vecs);

	hasvecs = (vecs.nodes.size() > 0);

	// create files
	s = xchg->tmppath + "/" + folder + "/Dbs" + Prjshort + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	if (hasvecs) {
		s = xchg->tmppath + "/" + folder + "/Dbs" + Prjshort + "_vecs.cpp.ip";
		veccppfile.open(s.c_str(), ios::out);
	};
	s = xchg->tmppath + "/" + folder + "/Dbs" + Prjshort + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeDbsH(dbswznm, hfile, tbls, qtbs, vecs, Prjshort, marMy, pg, lite, dbss);
	if (hasvecs) writeDbsvecsCpp(dbswznm, veccppfile, vecs, Prjshort, refLcl, refsLcl);
	writeDbsCpp(dbswznm, cppfile, tbls, qtbs, Prjshort, marMy, pg, lite, dbss, hasvecs);

	cppfile.close();
	if (hasvecs) veccppfile.close();
	hfile.close();

	delete ver;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrdbsDbs::writeDbsH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ListWznmMTable& tbls
			, const ListWznmMTable& qtbs
			, const ListWznmMVector& vecs
			, const string& Prjshort
			, const bool my
			, const bool pg
			, const bool lite
			, const vector<string>& dbss
		) {
	WznmMVector* vec = NULL;
	WznmMTable* tbl = NULL;

	uint cnt;

	// --- include.my*
	if (my) outfile << "// IP include.my --- AFFIRM" << endl;
	else outfile << "// IP include.my --- REMOVE" << endl;

	// --- include.pg*
	if (pg) outfile << "// IP include.pg --- AFFIRM" << endl;
	else outfile << "// IP include.pg --- REMOVE" << endl;

	// --- include.lite*
	if (lite) outfile << "// IP include.lite --- AFFIRM" << endl;
	else outfile << "// IP include.lite --- REMOVE" << endl;

	// --- include.stts
	outfile << "// IP include.stts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		outfile << "#include \"" << tbl->sref.substr(3) << ".h\"" << endl;
	};
	outfile << "// IP include.stts --- IEND" << endl;

	// --- include.qtbs
	outfile << "// IP include.qtbs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
		tbl = qtbs.nodes[i];

		outfile << "#include \"" << tbl->sref.substr(3) << ".h\"" << endl;
	};
	outfile << "// IP include.qtbs --- IEND" << endl;

	// --- fsrs.vecs
	outfile << "// IP fsrs.vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		outfile << "#define " << vec->sref << " Dbs" << Prjshort << "::Vec" << vec->sref.substr(3+4) << endl;
	};
	outfile << "// IP fsrs.vecs --- IEND" << endl;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		writeVecH(dbswznm, Prjshort, outfile, vec, "Vec" + vec->sref.substr(3+4));
	};
	outfile << "// IP vecs --- IEND" << endl;

	// --- inittermMy*
	if (my) outfile << "// IP inittermMy --- AFFIRM" << endl;
	else outfile << "// IP inittermMy --- REMOVE" << endl;

	// --- inittermPg*
	if (pg) outfile << "// IP inittermPg --- AFFIRM" << endl;
	else outfile << "// IP inittermPg --- REMOVE" << endl;

	// --- inittermLite*
	if (lite) outfile << "// IP inittermLite --- AFFIRM" << endl;
	else outfile << "// IP inittermLite --- REMOVE" << endl;

	// --- dbsMy*
	if (my) outfile << "// IP dbsMy --- AFFIRM" << endl;
	else outfile << "// IP dbsMy --- REMOVE" << endl;

	// --- dbsPg*
	if (pg) outfile << "// IP dbsPg --- AFFIRM" << endl;
	else outfile << "// IP dbsPg --- REMOVE" << endl;

	// --- dbsLite*
	if (lite) outfile << "// IP dbsLite --- AFFIRM" << endl;
	else outfile << "// IP dbsLite --- REMOVE" << endl;

	// --- transactMy*
	if (my) outfile << "// IP transactMy --- AFFIRM" << endl;
	else outfile << "// IP transactMy --- REMOVE" << endl;

	// --- transactPg*
	if (pg) outfile << "// IP transactPg --- AFFIRM" << endl;
	else outfile << "// IP transactPg --- REMOVE" << endl;

	// --- transactLite*
	if (lite) outfile << "// IP transactLite --- AFFIRM" << endl;
	else outfile << "// IP transactLite --- REMOVE" << endl;

	// --- loadfctsMy*
	if (my) outfile << "// IP loadfctsMy --- AFFIRM" << endl;
	else outfile << "// IP loadfctsMy --- REMOVE" << endl;

	// --- loadfctsPg*
	if (pg) outfile << "// IP loadfctsPg --- AFFIRM" << endl;
	else outfile << "// IP loadfctsPg --- REMOVE" << endl;

	// --- loadfctsLite*
	if (lite) outfile << "// IP loadfctsLite --- AFFIRM" << endl;
	else outfile << "// IP loadfctsLite --- REMOVE" << endl;

	// --- executeQueryDiv
	outfile << "// IP executeQueryDiv --- IBEGIN" << endl;
	outfile << "\tvoid executeQueryDiv(";
	for (unsigned int i = 0; i < dbss.size(); i++) {
		if (i != 0) outfile << ", ";
		outfile << "const std::string& sqlstr" << StrMod::lc(dbss[i]);
	};
	outfile << ");" << endl;
	outfile << "// IP executeQueryDiv --- IEND" << endl;

	// --- getIxWSubsets
	outfile << "// IP getIxWSubsets --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(tbl->ref), cnt);
		if (cnt > 0) {
			outfile << "\tSbecore::uint getIxWSubsetByRef" << tbl->sref.substr(3) << "(const Sbecore::ubigint ref);" << endl;
			outfile << "\tSbecore::uint getIxWSubsetBy" << tbl->sref.substr(3) << "(" << tbl->sref.substr(3) << "* rec);" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP getIxWSubsets --- IEND" << endl;

	// --- stts
	outfile << "// IP stts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		outfile << "\t" << tbl->sref << "* " << StrMod::lc(tbl->sref) << ";" << endl;
	};
	outfile << "// IP stts --- IEND" << endl;

	// --- qtbs
	outfile << "// IP qtbs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
		tbl = qtbs.nodes[i];

		outfile << "\t" << tbl->sref << "* " << StrMod::lc(tbl->sref) << ";" << endl;
	};
	outfile << "// IP qtbs --- IEND" << endl;
};

void WznmWrdbsDbs::writeDbsvecsCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ListWznmMVector& vecs
			, const string& Prjshort
			, ubigint& refLcl
			, vector<ubigint>& refsLcl
		) {
	WznmMVector* vec = NULL;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		writeVecCpp(dbswznm, Prjshort, outfile, vec, "Dbs" + Prjshort, "Vec" + vec->sref.substr(3+4), refLcl, refsLcl);
	};
	outfile << "// IP vecs --- IEND" << endl;
};

void WznmWrdbsDbs::writeDbsCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ListWznmMTable& tbls
			, const ListWznmMTable& qtbs
			, const string& Prjshort
			, const bool my
			, const bool pg
			, const bool lite
			, const vector<string>& dbss
			, const bool hasvecs
		) {
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	map<string,WznmMTablecol*> shortsTcos;

	ListWznmMSubset sbss;
	WznmMSubset* sbs = NULL;
	WznmMSubset* sbs2 = NULL;

	ListWznmRMSubsetMSubset srss;
	WznmRMSubsetMSubset* srs = NULL;

	Expr expr;

	// --- include.vecs*
	if (hasvecs) outfile << "// IP include.vecs --- AFFIRM" << endl;
	else outfile << "// IP include.vecs --- REMOVE" << endl;

	// --- constructorMy*
	if (my) outfile << "// IP constructorMy --- AFFIRM" << endl;
	else outfile << "// IP constructorMy --- REMOVE" << endl;

	// --- constructorPg*
	if (pg) outfile << "// IP constructorPg --- AFFIRM" << endl;
	else outfile << "// IP constructorPg --- REMOVE" << endl;

	// --- constructorLite*
	if (lite) outfile << "// IP constructorLite --- AFFIRM" << endl;
	else outfile << "// IP constructorLite --- REMOVE" << endl;

	// --- initMy*
	if (my) outfile << "// IP initMy --- AFFIRM" << endl;
	else outfile << "// IP initMy --- REMOVE" << endl;

	// --- initPg*
	if (pg) outfile << "// IP initPg --- AFFIRM" << endl;
	else outfile << "// IP initPg --- REMOVE" << endl;

	// --- initLite*
	if (lite) outfile << "// IP initLite --- AFFIRM" << endl;
	else outfile << "// IP initLite --- REMOVE" << endl;

	// --- termMy*
	if (my) outfile << "// IP termMy --- AFFIRM" << endl;
	else outfile << "// IP termMy --- REMOVE" << endl;

	// --- termPg*
	if (pg) outfile << "// IP termPg --- AFFIRM" << endl;
	else outfile << "// IP termPg --- REMOVE" << endl;

	// --- termLite*
	if (lite) outfile << "// IP termLite --- AFFIRM" << endl;
	else outfile << "// IP termLite --- REMOVE" << endl;

	if (my) {
		outfile << "// IP inittermMy --- AFFIRM" << endl;

		// --- initMy.stts
		outfile << "// IP initMy.stts --- IBEGIN" << endl;
		for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
			tbl = tbls.nodes[i];

			outfile << "\t" << StrMod::lc(tbl->sref) << " = new My" << tbl->sref << "();" << endl;
			outfile << "\t((My" << tbl->sref << "*) " << StrMod::lc(tbl->sref) << ")->init(dbsMy);" << endl;
		};
		outfile << "// IP initMy.stts --- IEND" << endl;

		// --- initMy.qtbs
		outfile << "// IP initMy.qtbs --- IBEGIN" << endl;
		for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
			tbl = qtbs.nodes[i];

			outfile << "\t" << StrMod::lc(tbl->sref) << " = new My" << tbl->sref << "();" << endl;
			outfile << "\t((My" << tbl->sref << "*) " << StrMod::lc(tbl->sref) << ")->init(dbsMy);" << endl;
		};
		outfile << "// IP initMy.qtbs --- IEND" << endl;

	} else {
		outfile << "// IP inittermMy --- REMOVE" << endl;
	};

	if (pg) {
		outfile << "// IP inittermPg --- AFFIRM" << endl;

		// --- initPg.stts
		outfile << "// IP initPg.stts --- IBEGIN" << endl;
		for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
			tbl = tbls.nodes[i];

			outfile << "\t" << StrMod::lc(tbl->sref) << " = new Pg" << tbl->sref << "();" << endl;
			outfile << "\t((Pg" << tbl->sref << "*) " << StrMod::lc(tbl->sref) << ")->init(dbsPg);" << endl;
		};
		outfile << "// IP initPg.stts --- IEND" << endl;

		// --- initPg.qtbs
		outfile << "// IP initPg.qtbs --- IBEGIN" << endl;
		for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
			tbl = qtbs.nodes[i];

			outfile << "\t" << StrMod::lc(tbl->sref) << " = new Pg" << tbl->sref << "();" << endl;
			outfile << "\t((Pg" << tbl->sref << "*) " << StrMod::lc(tbl->sref) << ")->init(dbsPg);" << endl;
		};
		outfile << "// IP initPg.qtbs --- IEND" << endl;

	} else {
		outfile << "// IP inittermPg --- REMOVE" << endl;
	};

	if (lite) {
		outfile << "// IP inittermLite --- AFFIRM" << endl;

		// --- initLite.stts
		outfile << "// IP initLite.stts --- IBEGIN" << endl;
		for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
			tbl = tbls.nodes[i];

			outfile << "\t" << StrMod::lc(tbl->sref) << " = new Lite" << tbl->sref << "();" << endl;
			outfile << "\t((Lite" << tbl->sref << "*) " << StrMod::lc(tbl->sref) << ")->init(dbsLite);" << endl;
		};
		outfile << "// IP initLite.stts --- IEND" << endl;

		// --- initLite.qtbs
		outfile << "// IP initLite.qtbs --- IBEGIN" << endl;
		for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
			tbl = qtbs.nodes[i];

			outfile << "\t" << StrMod::lc(tbl->sref) << " = new Lite" << tbl->sref << "();" << endl;
			outfile << "\t((Lite" << tbl->sref << "*) " << StrMod::lc(tbl->sref) << ")->init(dbsLite);" << endl;
		};
		outfile << "// IP initLite.qtbs --- IEND" << endl;

	} else {
		outfile << "// IP inittermLite --- REMOVE" << endl;
	};

	// --- beginMy*
	if (my) outfile << "// IP beginMy --- AFFIRM" << endl;
	else outfile << "// IP beginMy --- REMOVE" << endl;

	// --- beginPg*
	if (pg) outfile << "// IP beginPg --- AFFIRM" << endl;
	else outfile << "// IP beginPg --- REMOVE" << endl;

	// --- beginLite*
	if (lite) outfile << "// IP beginLite --- AFFIRM" << endl;
	else outfile << "// IP beginLite --- REMOVE" << endl;

	// --- commitMy*
	if (my) outfile << "// IP commitMy --- AFFIRM" << endl;
	else outfile << "// IP commitMy --- REMOVE" << endl;

	// --- commitPg*
	if (pg) outfile << "// IP commitPg --- AFFIRM" << endl;
	else outfile << "// IP commitPg --- REMOVE" << endl;

	// --- commitLite*
	if (lite) outfile << "// IP commitLite --- AFFIRM" << endl;
	else outfile << "// IP commitLite --- REMOVE" << endl;

	// --- rollbackMy*
	if (my) outfile << "// IP rollbackMy --- AFFIRM" << endl;
	else outfile << "// IP rollbackMy --- REMOVE" << endl;

	// --- rollbackPg*
	if (pg) outfile << "// IP rollbackPg --- AFFIRM" << endl;
	else outfile << "// IP rollbackPg --- REMOVE" << endl;

	// --- rollbackLite*
	if (lite) outfile << "// IP rollbackLite --- AFFIRM" << endl;
	else outfile << "// IP rollbackLite --- REMOVE" << endl;

	// --- transactMy*
	if (my) outfile << "// IP transactMy --- AFFIRM" << endl;
	else outfile << "// IP transactMy --- REMOVE" << endl;

	// --- transactPg*
	if (pg) outfile << "// IP transactPg --- AFFIRM" << endl;
	else outfile << "// IP transactPg --- REMOVE" << endl;

	// --- transactLite*
	if (lite) outfile << "// IP transactLite --- AFFIRM" << endl;
	else outfile << "// IP transactLite --- REMOVE" << endl;

	// --- loadUintBySQLMy*
	if (my) outfile << "// IP loadUintBySQLMy --- AFFIRM" << endl;
	else outfile << "// IP loadUintBySQLMy --- REMOVE" << endl;

	// --- loadUintBySQLPg*
	if (pg) outfile << "// IP loadUintBySQLPg --- AFFIRM" << endl;
	else outfile << "// IP loadUintBySQLPg --- REMOVE" << endl;

	// --- loadUintBySQLLite*
	if (lite) outfile << "// IP loadUintBySQLLite --- AFFIRM" << endl;
	else outfile << "// IP loadUintBySQLLite --- REMOVE" << endl;

	// --- loadStringBySQLMy*
	if (my) outfile << "// IP loadStringBySQLMy --- AFFIRM" << endl;
	else outfile << "// IP loadStringBySQLMy --- REMOVE" << endl;

	// --- loadStringBySQLPg*
	if (pg) outfile << "// IP loadStringBySQLPg --- AFFIRM" << endl;
	else outfile << "// IP loadStringBySQLPg --- REMOVE" << endl;

	// --- loadStringBySQLLite*
	if (lite) outfile << "// IP loadStringBySQLLite --- AFFIRM" << endl;
	else outfile << "// IP loadStringBySQLLite --- REMOVE" << endl;

	// --- loadRefBySQLMy*
	if (my) outfile << "// IP loadRefBySQLMy --- AFFIRM" << endl;
	else outfile << "// IP loadRefBySQLMy --- REMOVE" << endl;

	// --- loadRefBySQLPg*
	if (pg) outfile << "// IP loadRefBySQLPg --- AFFIRM" << endl;
	else outfile << "// IP loadRefBySQLPg --- REMOVE" << endl;

	// --- loadRefBySQLLite*
	if (lite) outfile << "// IP loadRefBySQLLite --- AFFIRM" << endl;
	else outfile << "// IP loadRefBySQLLite --- REMOVE" << endl;

	// --- loadRefsBySQLMy*
	if (my) outfile << "// IP loadRefsBySQLMy --- AFFIRM" << endl;
	else outfile << "// IP loadRefsBySQLMy --- REMOVE" << endl;

	// --- loadRefsBySQLPg*
	if (pg) outfile << "// IP loadRefsBySQLPg --- AFFIRM" << endl;
	else outfile << "// IP loadRefsBySQLPg --- REMOVE" << endl;

	// --- loadRefsBySQLLite*
	if (lite) outfile << "// IP loadRefsBySQLLite --- AFFIRM" << endl;
	else outfile << "// IP loadRefsBySQLLite --- REMOVE" << endl;

	// --- loadfctsMy*
	if (my) outfile << "// IP loadfctsMy --- AFFIRM" << endl;
	else outfile << "// IP loadfctsMy --- REMOVE" << endl;

	// --- loadfctsPg*
	if (pg) outfile << "// IP loadfctsPg --- AFFIRM" << endl;
	else outfile << "// IP loadfctsPg --- REMOVE" << endl;

	// --- loadfctsLite*
	if (lite) outfile << "// IP loadfctsLite --- AFFIRM" << endl;
	else outfile << "// IP loadfctsLite --- REMOVE" << endl;

	// --- executeQueryMy*
	if (my) outfile << "// IP executeQueryMy --- AFFIRM" << endl;
	else outfile << "// IP executeQueryMy --- REMOVE" << endl;

	// --- executeQueryPg*
	if (pg) outfile << "// IP executeQueryPg --- AFFIRM" << endl;
	else outfile << "// IP executeQueryPg --- REMOVE" << endl;

	// --- executeQueryLite*
	if (lite) outfile << "// IP executeQueryLite --- AFFIRM" << endl;
	else outfile << "// IP executeQueryLite --- REMOVE" << endl;

	// --- executeQueryDiv
	outfile << "// IP executeQueryDiv --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dbss.size(); i++) {
		outfile << "\t\t\t";
		if (i != 0) outfile << ", ";
		outfile << "const string& sqlstr" << StrMod::lc(dbss[i]) << endl;
	};
	outfile << "// IP executeQueryDiv --- IEND" << endl;

	// --- executeQueryDivMy*
	if (my) outfile << "// IP executeQueryDivMy --- AFFIRM" << endl;
	else outfile << "// IP executeQueryDivMy --- REMOVE" << endl;

	// --- executeQueryDivPg*
	if (pg) outfile << "// IP executeQueryDivPg --- AFFIRM" << endl;
	else outfile << "// IP executeQueryDivPg --- REMOVE" << endl;

	// --- executeQueryDivLite*
	if (lite) outfile << "// IP executeQueryDivLite --- AFFIRM" << endl;
	else outfile << "// IP executeQueryDivLite --- REMOVE" << endl;

	// --- getIxWSubsets
	outfile << "// IP getIxWSubsets --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		dbswznm->tblwznmmsubset->loadRstBySQL("SELECT * FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(tbl->ref) + " ORDER BY sref ASC", false, sbss);

		if (sbss.nodes.size() > 0) {
			dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tcos);

			shortsTcos.clear();
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) shortsTcos[tcos.nodes[j]->Short] = tcos.nodes[j];

			outfile << "uint Dbs" << Prjshort << "::getIxWSubsetByRef" << tbl->sref.substr(3) << "(" << endl;
			outfile << "\t\t\tconst ubigint ref" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tuint ixWSubset = 0;" << endl;
			outfile << "\t" << tbl->sref.substr(3) << "* rec = NULL;" << endl;
			outfile << endl;
			
			outfile << "\tif (" << StrMod::lc(tbl->sref) << "->loadRecByRef(ref, &rec)) {" << endl;
			outfile << "\t\tixWSubset = getIxWSubsetBy" << tbl->sref.substr(3) << "(rec);" << endl;
			outfile << "\t\tdelete rec;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\treturn ixWSubset;" << endl;
			outfile << "};" << endl;
			outfile << endl;

			outfile << "uint Dbs" << Prjshort << "::getIxWSubsetBy" << tbl->sref.substr(3) << "(" << endl;
			outfile << "\t\t\t" << tbl->sref.substr(3) << "* rec" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tuint ixWSubset = 0;" << endl;
			outfile << "\tuint dneIxWSubset = 0;" << endl;
			outfile << endl;

			outfile << "\tvector<bool> args;" << endl;
			outfile << "\tbool a, b;" << endl;
			outfile << endl;
			for (unsigned int j = 0; j < sbss.nodes.size(); j++) {
				sbs = sbss.nodes[j];

				dbswznm->tblwznmrmsubsetmsubset->loadRstByAsb(sbs->ref, false, srss);

				if (expr.tokenize(sbs->Cond)) if (expr.parse()) if (expr.root) {
					outfile << "\tif ((dneIxWSubset & " << tbl->sref << "::VecWSubset::" << StrMod::uc(sbs->sref) << ") == 0) {" << endl;

					writeDbsCpp_sbseval(dbswznm, outfile, tbl, tcos, shortsTcos, expr.root);

					outfile << "\t\tif (args.back()) {" << endl;
					outfile << "\t\t\tixWSubset |= " << tbl->sref << "::VecWSubset::" << StrMod::uc(sbs->sref) << ";" << endl;

					for (unsigned int k = 0; k < srss.nodes.size(); k++) {
						srs = srss.nodes[k];

						if ((srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::AINB) || (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::DISJ)) {
							if (dbswznm->tblwznmmsubset->loadRecByRef(srs->bsbRefWznmMSubset, &sbs2)) {
								if (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::AINB) outfile << "\t\t\tixWSubset |= " << tbl->sref << "::VecWSubset::" << StrMod::uc(sbs2->sref) << ";" << endl;
								outfile << "\t\t\tdneIxWSubset |= " << tbl->sref << "::VecWSubset::" << StrMod::uc(sbs2->sref) << ";" << endl;
								
								delete sbs2;
							};
						};
					};

					outfile << "\t\t} else {" << endl;

					for (unsigned int k = 0; k < srss.nodes.size(); k++) {
						srs = srss.nodes[k];

						if ((srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::BINA) || (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::COMPL)) {
							if (dbswznm->tblwznmmsubset->loadRecByRef(srs->bsbRefWznmMSubset, &sbs2)) {
								if (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::BINA) outfile << "\t\t\tdneIxWSubset |= " << tbl->sref << "::VecWSubset::" << StrMod::uc(sbs2->sref) << ";" << endl;
								else if (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::COMPL) outfile << "\t\t\tixWSubset |= " << tbl->sref << "::VecWSubset::" << StrMod::uc(sbs2->sref) << ";" << endl;
								
								delete sbs2;
							};
						};
					};

					outfile << "\t\t};" << endl;
					outfile << endl;

					outfile << "\t\tdneIxWSubset |= " << tbl->sref << "::VecWSubset::" << StrMod::uc(sbs->sref) << ";" << endl;

					for (unsigned int k = 0; k < srss.nodes.size(); k++) {
						srs = srss.nodes[k];

						if (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::COMPL) {
							if (dbswznm->tblwznmmsubset->loadRecByRef(srs->bsbRefWznmMSubset, &sbs2)) {
								outfile << "\t\tdneIxWSubset |= " << tbl->sref << "::VecWSubset::" << StrMod::uc(sbs2->sref) << ";" << endl;
								delete sbs2;
							};
						};
					};

					outfile << "\t\targs.clear();" << endl;
					outfile << "\t};" << endl;
					outfile << endl;
				};
			};

			outfile << "\treturn ixWSubset;" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP getIxWSubsets --- IEND" << endl;
};

void WznmWrdbsDbs::writeDbsCpp_sbseval(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMTable* tbl
			, ListWznmMTablecol& tcos
			, map<string,WznmMTablecol*>& shortsTcos
			, Expr::Node* node
		) {
	WznmMTablecol* tco = NULL;
	map<string,WznmMTablecol*>::iterator it;

	WznmMVector* vec = NULL;

	WznmMSubset* sbs2 = NULL;
	WznmMTable* tbl2 = NULL;

	if (node->logicfct()) {
		// only not, and, or make sense
		if ((node->key == "not") && (node->subs.size() == 1)) {
			writeDbsCpp_sbseval(dbswznm, outfile, tbl, tcos, shortsTcos, node->subs[0]);

			outfile << "\t\ta = args.back(); args.pop_back();" << endl;
			outfile << "\t\targs.push_back(!a);" << endl;

		} else if ((node->key == "and") && (node->subs.size() == 2)) {
			writeDbsCpp_sbseval(dbswznm, outfile, tbl, tcos, shortsTcos, node->subs[0]);
			writeDbsCpp_sbseval(dbswznm, outfile, tbl, tcos, shortsTcos, node->subs[1]);

			outfile << "\t\tb = args.back(); args.pop_back();" << endl;
			outfile << "\t\ta = args.back(); args.pop_back();" << endl;
			outfile << "\t\targs.push_back(a && b);" << endl;

		} else if ((node->key == "or") && (node->subs.size() == 2)) {
			writeDbsCpp_sbseval(dbswznm, outfile, tbl, tcos, shortsTcos, node->subs[0]);
			writeDbsCpp_sbseval(dbswznm, outfile, tbl, tcos, shortsTcos, node->subs[1]);

			outfile << "\t\tb = args.back(); args.pop_back();" << endl;
			outfile << "\t\ta = args.back(); args.pop_back();" << endl;
			outfile << "\t\targs.push_back(a || b);" << endl;

		} else {
			outfile << "\t\targs.push_back(false);" << endl;
		};

	} else if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
		// vocabulary:
		// xxxEq() - equivalence of tco
		// xxxIncl() - tco includes (ix for vecor)
		// isLeaf() - record of h1n table is leaf (has no subs)
		// xxx.inSbs() - record referenced by tco is part of subset (different table)

		// no nested functions to be expected here

		outfile << "\t\ta = false;";

		if ( (node->key.length() >= 5) && ((node->key.rfind("Eq")+2) == node->key.length()) && (node->subs.size() == 1) ) {
			it = shortsTcos.find(node->key.substr(0, node->key.length()-2));
			if (it != shortsTcos.end()) {
				tco = it->second;

				if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF)) {
					outfile << " a = (rec->" << tco->sref << " == " << to_string(node->subs[0]->intval) << ");";
				} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
					if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
						outfile << " a = (rec->" << tco->sref << " == " << vec->sref << "::" << StrMod::uc(node->subs[0]->key) << ");";
						delete vec;
					};
				} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF)) {
					outfile << " a = (rec->" << tco->sref << " == \"" << node->subs[0]->key << "\");";
				} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
					outfile << " a = rec->"  << tco->sref << ";";
				};
			};

		} else if ( (node->key.length() >= 7) && ((node->key.rfind("Incl")+4) == node->key.length()) && (node->subs.size() == 1) ) {
			it = shortsTcos.find(node->key.substr(0, node->key.length()-4));
			if (it != shortsTcos.end()) {
				tco = it->second;

				if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
					if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
						outfile << " a = ((rec->" << tco->sref << " & " << vec->sref << "::" << StrMod::uc(node->subs[0]->key) << ") != 0);";
						delete vec;
					};
				} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
					outfile << " a = StrMod::srefInSrefs(rec->" << tco->sref << ", \"" << node->subs[0]->key << "\");";
				};
			};

		} else if (node->key == "isLeaf") {
			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.tblRefWznmMTable = " + to_string(tbl->ref) + " AND TblWznmMTablecol.ixVBasetype = "
						+ to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND TblWznmMTablecol.ixVSubtype = " + to_string(VecWznmVMTablecolSubtype::TREFSPEC) + " AND TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMRelation.ixVBasetype = "
						+ to_string(VecWznmVMRelationBasetype::H1N), &tco)) {

				outfile << " {uint cnt = 0; loadUintBySQL(\"SELECT COUNT(ref) FROM " << tbl->sref << " WHERE " << tco->sref << " = \" + to_string(rec->ref), cnt); a = (cnt == 0);}";
				delete tco;
			};

		} else if ( (node->key.length() >= 9) && ((node->key.rfind(".inSbs")+6) == node->key.length()) && (node->subs.size() == 1) ) {
			it = shortsTcos.find(node->key.substr(0, node->key.length()-6));
			if (it != shortsTcos.end()) {
				tco = it->second;

				if (dbswznm->tblwznmmsubset->loadRecBySQL("SELECT TblWznmMSubset.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.refWznmMVersion = " + to_string(tbl->refWznmMVersion)
							+ " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.Short = '" + node->subs[0]->key + "'", &sbs2)) {

					if (dbswznm->tblwznmmtable->loadRecByRef(sbs2->refWznmMTable, &tbl2)) {
						outfile << " a = ((getIxWSubsetByRef" << tbl2->sref.substr(3) << "(rec->" << tco->sref << ") & " << tbl2->sref << "::VecWSubset::" << StrMod::uc(sbs2->sref) << ") != 0);";
						delete tbl2;
					};
					
					delete sbs2;
				};
			};
		};

		outfile << endl;
		outfile << "\t\targs.push_back(a);" << endl;

	} else {
		outfile << "\t\targs.push_back(false);" << endl;
	};
};
// IP cust --- IEND
