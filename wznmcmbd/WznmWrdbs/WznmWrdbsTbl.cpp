/**
	* \file WznmWrdbsTbl.cpp
	* Wznm operation processor - write database access library C++ code for table (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrdbsTbl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrdbs;

/******************************************************************************
 namespace WznmWrdbsTbl
 ******************************************************************************/

DpchRetWznm* WznmWrdbsTbl::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrdbsTbl* dpchinv
		) {
	ubigint refWznmMTable = dpchinv->refWznmMTable;
	string Prjshort = dpchinv->Prjshort;
	bool dbsmy = dpchinv->dbsmy;
	bool dbspg = dpchinv->dbspg;
	bool dbslite = dpchinv->dbslite;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMTable* tbl = NULL;

	ListWznmMVector vecs;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	ListWznmAMTableLoadfct lfcs;
	WznmAMTableLoadfct* lfc = NULL;

	WznmMQuery* qry = NULL;
	ListWznmMQuerycol qcos;

	bool hasString = false;

	bool hasRst = false;
	bool hasHrefsup = false;
	bool hasHrefsdown = false;
	bool hasHrstup = false;
	bool hasHrstdown = false;

	fstream hfile;
	fstream veccppfile;
	fstream cppfile;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;

	bool hasvecs;

	string s;

	if (dbswznm->tblwznmmtable->loadRecByRef(refWznmMTable, &tbl)) {
		Wznm::getVerlcls(dbswznm, tbl->refWznmMVersion, refLcl, refsLcl, lcls);

		// load table-specific vectors
		dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::TBL) + " AND hkUref = " + to_string(refWznmMTable) + " AND ((ixVBasetype = "
					+ to_string(VecWznmVMVectorBasetype::LIN) + ") OR (ixVBasetype = " + to_string(VecWznmVMVectorBasetype::OR) + ")) ORDER BY sref ASC", false, vecs);

		hasvecs = (vecs.nodes.size() > 0);

		// create files
		s = xchg->tmppath + "/" + folder + "/" + tbl->sref.substr(3) + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		if (hasvecs) {
			s = xchg->tmppath + "/" + folder + "/" + tbl->sref.substr(3) + "_vecs.cpp.ip";
			veccppfile.open(s.c_str(), ios::out);
		};
		s = xchg->tmppath + "/" + folder + "/" + tbl->sref.substr(3) + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST) {
			// only simple insertion points
			if (dbsmy) hfile << "// IP include.my --- AFFIRM" << endl;
			else hfile << "// IP include.my --- REMOVE" << endl;

			if (dbspg) hfile << "// IP include.pg --- AFFIRM" << endl;
			else hfile << "// IP include.pg --- REMOVE" << endl;

			if (dbslite) hfile << "// IP include.lite --- AFFIRM" << endl;
			else hfile << "// IP include.lite --- REMOVE" << endl;

			if (dbsmy) {
				hfile << "// IP myTbl --- AFFIRM" << endl;
				cppfile << "// IP myTbl --- AFFIRM" << endl;
			} else {
				hfile << "// IP myTbl --- REMOVE" << endl;
				cppfile << "// IP myTbl --- REMOVE" << endl;
			};

			if (dbspg) {
				hfile << "// IP pgTbl --- AFFIRM" << endl;
				cppfile << "// IP pgTbl --- AFFIRM" << endl;
			} else {
				hfile << "// IP pgTbl --- REMOVE" << endl;
				cppfile << "// IP pgTbl --- REMOVE" << endl;
			};

			if (dbslite) {
				hfile << "// IP liteTbl --- AFFIRM" << endl;
				cppfile << "// IP liteTbl --- AFFIRM" << endl;
			} else {
				hfile << "// IP liteTbl --- REMOVE" << endl;
				cppfile << "// IP liteTbl --- REMOVE" << endl;
			};

		} else {
			// load table columns
			dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tcos);

			// check for string fields
			for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
				tco = tcos.nodes[i];

				if (getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false) == "string") {
					hasString = true;
					break;
				};
			};

			if (tbl->ixVBasetype == VecWznmVMTableBasetype::QRY) {

				if (dbswznm->tblwznmmquery->loadRecByRef(tbl->refUref, &qry)) {
					// load actual query columns
					dbswznm->tblwznmmquerycol->loadRstByQry(tbl->refUref, false, qcos);
					delete qry;

				} else {
					// generate dummy query columns
					for (unsigned int i = 0; i < tcos.nodes.size(); i++) qcos.nodes.push_back(new WznmMQuerycol(0, 0, 0, 0, 0, 0, tcos.nodes[i]->sref, tcos.nodes[i]->Short, 0));
				};

				writeQtbH(hfile, tbl, tcos, qcos, dbsmy, dbspg, dbslite);
				writeQtbCpp(cppfile, tbl, tcos, hasString, qcos, dbsmy, dbspg, dbslite);

			} else {
				// load load functions
				dbswznm->tblwznmamtableloadfct->loadRstByTbl(tbl->ref, false, lfcs);

				for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
					lfc = lfcs.nodes[i];

					switch (lfc->ixVLoadtype) {
						case VecWznmVAMTableLoadfctLoadtype::RST:
							hasRst = true;
							break;
						case VecWznmVAMTableLoadfctLoadtype::HREFSUP:
							hasHrefsup = true;
							break;
						case VecWznmVAMTableLoadfctLoadtype::HREFSDOWN:
							hasHrefsdown = true;
							break;
						case VecWznmVAMTableLoadfctLoadtype::HRSTUP:
							hasHrstup = true;
							break;
						case VecWznmVAMTableLoadfctLoadtype::HRSTDOWN:
							hasHrstdown = true;
							break;
					};
				};

				writeTblH(dbswznm, hfile, Prjshort, tbl, vecs, tcos, lfcs, hasRst, hasHrefsup, hasHrefsdown, hasHrstup, hasHrstdown, dbsmy, dbspg, dbslite);
				if (hasvecs) writeTblvecsCpp(dbswznm, veccppfile, Prjshort, tbl, vecs, refLcl, refsLcl);
				writeTblCpp(cppfile, tbl, tcos, hasString, lfcs, hasRst, hasHrefsup, hasHrefsdown, hasHrstup, hasHrstdown, dbsmy, dbspg, dbslite, hasvecs);
			};
		};

		cppfile.close();
		if (hasvecs) veccppfile.close();
		hfile.close();

		delete tbl;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrdbsTbl::writeTblH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, WznmMTable* tbl
			, const ListWznmMVector& vecs
			, const ListWznmMTablecol& tcos
			, const ListWznmAMTableLoadfct& lfcs
			, const bool hasRst
			, const bool hasHrefsup
			, const bool hasHrefsdown
			, const bool hasHrstup
			, const bool hasHrstdown
			, const bool dbsmy
			, const bool dbspg
			, const bool dbslite
		) {
	WznmMVector* vec = NULL;
	WznmMTablecol* tco = NULL;
	WznmAMTableLoadfct* lfc = NULL;

	string subsref;
	size_t ptr;

	// --- include.my*
	if (dbsmy) outfile << "// IP include.my --- AFFIRM" << endl;
	else outfile << "// IP include.my --- REMOVE" << endl;

	// --- include.pg*
	if (dbspg) outfile << "// IP include.pg --- AFFIRM" << endl;
	else outfile << "// IP include.pg --- REMOVE" << endl;

	// --- include.lite*
	if (dbslite) outfile << "// IP include.lite --- AFFIRM" << endl;
	else outfile << "// IP include.lite --- REMOVE" << endl;

	// --- fsrs.vecs
	outfile << "// IP fsrs.vecs --- IBEGIN" << endl;
	if (vecs.nodes.size() > 0) {
		outfile << "#include <sbecore/Xmlio.h>" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			subsref = vec->sref;
			ptr = subsref.find(tbl->sref.substr(3+4));
			if (ptr != string::npos) subsref = subsref.substr(0, 3) + subsref.substr(7, 1) + subsref.substr(ptr+tbl->sref.length()-3-4);

			outfile << "#define " << vec->sref << " " << tbl->sref << "::" << subsref << endl;
		};
	};
	outfile << "// IP fsrs.vecs --- IEND" << endl;

	// --- constructor
	outfile << "// IP constructor --- IBEGIN" << endl;
	outfile << "\t" << tbl->sref.substr(3) << "(";
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << "const " << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, true) << " " << tco->sref << " = " << getTcoCppDefault(tco->ixVBasetype, tco->ixVSubtype);
	};
	outfile << ");" << endl;
	outfile << "// IP constructor --- IEND" << endl;

	// --- tcos
	outfile << "// IP tcos --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		outfile << "\t" << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, true) << " " << tco->sref << ";" << endl;
	};
	outfile << "// IP tcos --- IEND" << endl;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		subsref = vec->sref;
		ptr = subsref.find(tbl->sref.substr(3+4));
		if (ptr != string::npos) subsref = subsref.substr(0, 3) + subsref.substr(7, 1) + subsref.substr(ptr+tbl->sref.length()-3-4);

		writeVecH(dbswznm, Prjshort, outfile, vec, subsref);
	};
	outfile << "// IP vecs --- IEND" << endl;

	// --- insertNewRec
	outfile << "// IP insertNewRec --- IBEGIN" << endl;
	outfile << "\tSbecore::ubigint insertNewRec(" << tbl->sref.substr(3) << "** rec = NULL";
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		outfile << ", const " << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, true) << " " << tco->sref << " = " << getTcoCppDefault(tco->ixVBasetype, tco->ixVSubtype);
	};
	outfile << ");" << endl;
	outfile << "// IP insertNewRec --- IEND" << endl;

	// --- appendNewRecToRst
	outfile << "// IP appendNewRecToRst --- IBEGIN" << endl;
	outfile << "\tSbecore::ubigint appendNewRecToRst(List" << tbl->sref.substr(3) << "& rst, " << tbl->sref.substr(3) << "** rec = NULL";
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		outfile << ", const " << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, true) << " " << tco->sref << " = " << getTcoCppDefault(tco->ixVBasetype, tco->ixVSubtype);
	};
	outfile << ");" << endl;
	outfile << "// IP appendNewRecToRst --- IEND" << endl;

	// --- loadfcts
	// examples by ixVLoadtype:
	// CONFIRM: bool confirmByRef(ubigint ref)
	// COUNT: ubigint countByTyp(uint ixVBasetype);
	// REF: bool loadRefBySrf(string sref, ubigint& ref);
	// REFS: ubigint loadRefsByTyp(uint ixVBasetype, const bool append, vector<ubigint>& refs);
	// REC: bool loadRecByRef(ubigint ref, BrlyMLeg** rec);
	// RST: ubigint loadRstByTyp(uint ixVBasetype, const bool append, ListBrlyMLeg& rst, ubigint limit = 0, ubigint offset = 0);
	// STRING: bool loadSrfByRef(ubigint ref, string& val);
	// REF: bool loadSupByRef(ubigint ref, ubigint& supRefBrlyMRegion);
	// HREFSUP: ubigint loadHrefsup(ubigint ref, vector<ubigint>& refs);
	// HREFSDOWN: ubigint loadHrefsdown(ubigint ref, const bool append, vector<ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	// HRSTUP: ubigint loadHrstup(ubigint ref, ListBrlyMRegion& rst);
	// HRSTDOWN: ubigint loadHrstdown(ubigint ref, const bool append, ListBrlyMRegion& rst, unsigned int firstix = 0, unsigned int lastix = 0);

	outfile << "// IP loadfcts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			outfile << "\tvirtual ";
			writeTblH_lfc(outfile, lfc, tbl->sref, tcos);
		};
	};
	outfile << "// IP loadfcts --- IEND" << endl;

	// --- loadHrefsup*
	if (hasHrefsup) outfile << "// IP loadHrefsup --- AFFIRM" << endl;
	else outfile << "// IP loadHrefsup --- REMOVE" << endl;

	// --- loadHrefsdown*
	if (hasHrefsdown) outfile << "// IP loadHrefsdown --- AFFIRM" << endl;
	else outfile << "// IP loadHrefsdown --- REMOVE" << endl;

	// --- loadHrstup*
	if (hasHrstup) outfile << "// IP loadHrstup --- AFFIRM" << endl;
	else outfile << "// IP loadHrstup --- REMOVE" << endl;

	// --- loadHrstdown*
	if (hasHrstdown) outfile << "// IP loadHrstdown --- AFFIRM" << endl;
	else outfile << "// IP loadHrstdown --- REMOVE" << endl;

	// --- myTbl*
	if (dbsmy) {
		outfile << "// IP myTbl --- AFFIRM" << endl;
		writeTblH_my(outfile, tbl, tcos, lfcs, hasRst);
	} else {
		outfile << "// IP myTbl --- REMOVE" << endl;
	};

	// --- pgTbl*
	if (dbspg) {
		outfile << "// IP pgTbl --- AFFIRM" << endl;
		writeTblH_pg(outfile, tbl, tcos, lfcs, hasRst);
	} else {
		outfile << "// IP pgTbl --- REMOVE" << endl;
	};

	// --- liteTbl*
	if (dbslite) {
		outfile << "// IP liteTbl --- AFFIRM" << endl;
		writeTblH_lite(outfile, tbl, tcos, lfcs, hasRst);
	} else {
		outfile << "// IP liteTbl --- REMOVE" << endl;
	};
};

void WznmWrdbsTbl::writeTblH_my(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmAMTableLoadfct& lfcs
			, const bool hasRst
		) {
	WznmAMTableLoadfct* lfc = NULL;

	// --- myLoadfcts
	outfile << "// IP myLoadfcts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			outfile << "\t";
			writeTblH_lfc(outfile, lfc, tbl->sref, tcos);
		};
	};
	outfile << "// IP myLoadfcts --- IEND" << endl;
};

void WznmWrdbsTbl::writeTblH_pg(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmAMTableLoadfct& lfcs
			, const bool hasRst
		) {
	WznmAMTableLoadfct* lfc = NULL;

	// --- pgLoadRstByStmt*
	if (hasRst) outfile << "// IP pgLoadRstByStmt --- AFFIRM" << endl;
	else outfile << "// IP pgLoadRstByStmt --- REMOVE" << endl;

	// --- pgLoadfcts
	outfile << "// IP pgLoadfcts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			outfile << "\t";
			writeTblH_lfc(outfile, lfc, tbl->sref, tcos);
		};
	};
	outfile << "// IP pgLoadfcts --- IEND" << endl;
};

void WznmWrdbsTbl::writeTblH_lite(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmAMTableLoadfct& lfcs
			, const bool hasRst
		) {
	WznmAMTableLoadfct* lfc = NULL;

	// --- liteStmts
	outfile << "// IP liteStmts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			outfile << "\tsqlite3_stmt* stmt";
			outfile << StrMod::cap(lfc->Fctname) << ";" << endl;
		};
	};
	outfile << "// IP liteStmts --- IEND" << endl;

	// --- liteLoadRstByStmt*
	if (hasRst) outfile << "// IP liteLoadRstByStmt --- AFFIRM" << endl;
	else outfile << "// IP liteLoadRstByStmt --- REMOVE" << endl;

	// --- liteLoadfcts
	outfile << "// IP liteLoadfcts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			outfile << "\t";
			writeTblH_lfc(outfile, lfc, tbl->sref, tcos);
		};
	};
	outfile << "// IP liteLoadfcts --- IEND" << endl;
};

void WznmWrdbsTbl::writeTblH_lfc(
			fstream& outfile
			, WznmAMTableLoadfct* lfc
			, const string& tblsref
			, const ListWznmMTablecol& tcos
		) {
	vector<string> lbys;
	string lby;

	WznmMTablecol* tco = NULL;

	bool first;
	string resvar;

	size_t ptr;

	// extract "load by" table columns
	StrMod::stringToVector(lfc->lbySrefsWznmMTablecol, lbys);

	outfile << getLfcRetType(lfc->ixVLoadtype, true) << " " << lfc->Fctname << "(";

	// parameters
	first = true;
	for (unsigned int j = 0; j < lbys.size(); j++) {
		lby = lbys[j];
		ptr = lby.find('.');
		if (ptr != string::npos) lby = lby.substr(0, ptr);

		// find in tco's
		tco = getLbyTco(lby, tcos);

		if (tco) {
			if (first) first = false;
			else outfile << ", ";

			outfile << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, true) << " " << tco->sref;
		};
	};

	// append flag
	if (getLfcAppend(lfc->ixVLoadtype)) {
		if (first) first = false;
		else outfile << ", ";

		outfile << "const bool append";
	};

	// result variable
	tco = getLdTco(lfc->ldSrefWznmMTablecol, tcos);

	if (tco) resvar = getLfcRes(tblsref, lfc->ixVLoadtype, tco->sref, true);
	else resvar = getLfcRes(tblsref, lfc->ixVLoadtype, "", true);

	if (resvar != "") {
		if (first) first = false;
		else outfile << ", ";

		outfile << resvar;
	};

	// limit / offset clause
	if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) outfile << ", Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0";

	outfile << ");" << endl;
};

void WznmWrdbsTbl::writeTblvecsCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, WznmMTable* tbl
			, const ListWznmMVector& vecs
			, ubigint& refLcl
			, vector<ubigint>& refsLcl
		) {
	WznmMVector* vec = NULL;

	string subsref;
	size_t ptr;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		// subsref rule
		// VecBrlyVRMXyzMAbcBla => VecVBla
		//  TblBrlyRMXyz

		subsref = vec->sref;
		ptr = subsref.find(tbl->sref.substr(3+4));
		if (ptr != string::npos) subsref = subsref.substr(0, 3) + subsref.substr(7, 1) + subsref.substr(ptr+tbl->sref.length()-3-4);

		writeVecCpp(dbswznm, Prjshort, outfile, vec, tbl->sref, subsref, refLcl, refsLcl);
	};
	outfile << "// IP vecs --- IEND" << endl;
};

void WznmWrdbsTbl::writeTblCpp(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const bool hasString
			, const ListWznmAMTableLoadfct& lfcs
			, const bool hasRst
			, const bool hasHrefsup
			, const bool hasHrefsdown
			, const bool hasHrstup
			, const bool hasHrstdown
			, const bool dbsmy
			, const bool dbspg
			, const bool dbslite
			, const bool hasvecs
		) {
	WznmMTablecol* tco = NULL;
	WznmAMTableLoadfct* lfc = NULL;

	string tcotype;

	// --- include.vecs*
	if (hasvecs) outfile << "// IP include.vecs --- AFFIRM" << endl;
	else outfile << "// IP include.vecs --- REMOVE" << endl;

	// --- constructor.hdr
	outfile << "// IP constructor.hdr --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		outfile << "\t\t\t";
		if (i != 0) outfile << ", ";
		outfile << "const " << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false) << " " << tco->sref << endl;
	};
	outfile << "// IP constructor.hdr --- IEND" << endl;

	// --- constructor
	outfile << "// IP constructor --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		outfile << "\tthis->" << tco->sref << " = " << tco->sref << ";" << endl;
	};
	outfile << "// IP constructor --- IEND" << endl;

	// --- insertNewRec.hdr
	outfile << "// IP insertNewRec.hdr --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		outfile << "\t\t\t, const " << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false) << " " << tco->sref << endl;
	};
	outfile << "// IP insertNewRec.hdr --- IEND" << endl;

	// --- insertNewRec.new
	outfile << "// IP insertNewRec.new --- IBEGIN" << endl;
	outfile << "\t_rec = new " << tbl->sref.substr(3) << "(0";
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		outfile << ", " << tco->sref;
	};
	outfile << ");" << endl;
	outfile << "// IP insertNewRec.new --- IEND" << endl;

	// --- appendNewRecToRst.hdr
	outfile << "// IP appendNewRecToRst.hdr --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		outfile << "\t\t\t, const " << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false) << " " << tco->sref << endl;
	};
	outfile << "// IP appendNewRecToRst.hdr --- IEND" << endl;

	// --- appendNewRecToRst.insert
	outfile << "// IP appendNewRecToRst.insert --- IBEGIN" << endl;
	outfile << "\tretval = insertNewRec(&_rec";
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		outfile << ", " << tco->sref;
	};
	outfile << ");" << endl;
	outfile << "// IP appendNewRecToRst.insert --- IEND" << endl;

	// --- loadfcts
	outfile << "// IP loadfcts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			writeTblCpp_lfchdr(outfile, lfc, tbl->sref, tcos, "");

			if (getLfcRetType(lfc->ixVLoadtype, false) == "bool") {
				outfile << "\treturn false;" << endl;
			} else {
				outfile << "\treturn 0;" << endl;
			};

			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP loadfcts --- IEND" << endl;

	// --- loadHrefsup*
	if (hasHrefsup) outfile << "// IP loadHrefsup --- AFFIRM" << endl;
	else outfile << "// IP loadHrefsup --- REMOVE" << endl;

	// --- loadHrefsdown*
	if (hasHrefsdown) outfile << "// IP loadHrefsdown --- AFFIRM" << endl;
	else outfile << "// IP loadHrefsdown --- REMOVE" << endl;

	// --- loadHrstup*
	if (hasHrstup) outfile << "// IP loadHrstup --- AFFIRM" << endl;
	else outfile << "// IP loadHrstup --- REMOVE" << endl;

	// --- loadHrstdown*
	if (hasHrstdown) outfile << "// IP loadHrstdown --- AFFIRM" << endl;
	else outfile << "// IP loadHrstdown --- REMOVE" << endl;

	// --- myTbl*
	if (dbsmy) {
		outfile << "// IP myTbl --- AFFIRM" << endl;
		writeTblCpp_my(outfile, tbl, tcos, hasString, lfcs, hasRst);
	} else {
		outfile << "// IP myTbl --- REMOVE" << endl;
	};

	// --- pgTbl*
	if (dbspg) {
		outfile << "// IP pgTbl --- AFFIRM" << endl;
		writeTblCpp_pg(outfile, tbl, tcos, lfcs, hasRst);
	} else {
		outfile << "// IP pgTbl --- REMOVE" << endl;
	};

	// --- liteTbl*
	if (dbslite) {
		outfile << "// IP liteTbl --- AFFIRM" << endl;
		writeTblCpp_lite(outfile, tbl, tcos, lfcs, hasRst);
	} else {
		outfile << "// IP liteTbl --- REMOVE" << endl;
	};
};

void WznmWrdbsTbl::writeTblCpp_my(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const bool hasString
			, const ListWznmAMTableLoadfct& lfcs
			, const bool hasRst
		) {
	WznmMTablecol* tco = NULL;
	string tcotype;

	WznmAMTableLoadfct* lfc = NULL;

	string s;

	// --- myInitStatements.stmtInsertRec
	outfile << "// IP myInitStatements.stmtInsertRec --- IBEGIN" << endl;
	outfile << "\tstmtInsertRec = createStatement(\"INSERT INTO " << tbl->sref << " (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref;
	};

	outfile << ") VALUES (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		if (i != 1) outfile << ",";
		outfile << "?";
	};

	outfile << ")\", false);" << endl;
	outfile << "// IP myInitStatements.stmtInsertRec --- IEND" << endl;

	// --- myInitStatements.stmtUpdateRec
	outfile << "// IP myInitStatements.stmtUpdateRec --- IBEGIN" << endl;
	outfile << "\tstmtUpdateRec = createStatement(\"UPDATE " << tbl->sref << " SET ";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref << " = ?";
	};

	outfile << " WHERE " << tcos.nodes[0]->sref << " = ?\", false);" << endl;
	outfile << "// IP myInitStatements.stmtUpdateRec --- IEND" << endl;

	// --- myLoadRecBySQL.dblengths*
	if (hasString) outfile << "// IP myLoadRecBySQL.dblengths --- AFFIRM" << endl;
	else outfile << "// IP myLoadRecBySQL.dblengths --- REMOVE" << endl;

	// --- myLoadRecBySQL.extract
	outfile << "// IP myLoadRecBySQL.extract --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\tif (dbrow[" << i << "]) _rec->" << tco->sref;

		if (tcotype == "tinyint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "utinyint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "smallint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "usmallint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "int") {
			outfile << " = atol((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "uint") {
			outfile << " = atol((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "bigint") {
			outfile << " = atoll((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "ubigint") {
			outfile << " = atoll((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "string") {
			outfile << ".assign(dbrow[" << i << "], dblengths[" << i << "]); else _rec->" << tco->sref << " = \"\"";
		} else if (tcotype == "double") {
			outfile << " = atof((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0.0";
		} else if (tcotype == "bool") {
			outfile << " = (atoi((char*) dbrow[" << i << "]) != 0); else _rec->" << tco->sref << " = false";
		};

		outfile << ";" << endl;
	};
	outfile << "// IP myLoadRecBySQL.extract --- IEND" << endl;

	// --- myLoadRstBySQL.dblengths*
	if (hasString) outfile << "// IP myLoadRstBySQL.dblengths --- AFFIRM" << endl;
	else outfile << "// IP myLoadRstBySQL.dblengths --- REMOVE" << endl;

	// --- myLoadRstBySQL.extract
	outfile << "// IP myLoadRstBySQL.extract --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\t\tif (dbrow[" << i << "]) rec->" << tco->sref;

		if (tcotype == "tinyint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "utinyint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "smallint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "usmallint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "int") {
			outfile << " = atol((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "uint") {
			outfile << " = atol((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "bigint") {
			outfile << " = atoll((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "ubigint") {
			outfile << " = atoll((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "string") {
			outfile << ".assign(dbrow[" << i << "], dblengths[" << i << "]); else rec->" << tco->sref << " = \"\"";
		} else if (tcotype == "double") {
			outfile << " = atof((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0.0";
		} else if (tcotype == "bool") {
			outfile << " = (atoi((char*) dbrow[" << i << "]) != 0); else rec->" << tco->sref << " = false";
		};

		outfile << ";" << endl;
	};
	outfile << "// IP myLoadRstBySQL.extract --- IEND" << endl;

	// --- myInsertRec.lne
	outfile << "// IP myInsertRec.lne --- IBEGIN" << endl;
	outfile << "\tunsigned long l[" << (tcos.nodes.size()-1) << "]; my_bool n[" << (tcos.nodes.size()-1) << "]; my_bool e[" << (tcos.nodes.size()-1) << "];" << endl;
	outfile << "// IP myInsertRec.lne --- IEND" << endl;

	// --- myInsertRec.strL
	outfile << "// IP myInsertRec.strL --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		if (tcotype == "string") {
			outfile << "\tl[" << (i-1) << "] = rec->" << tco->sref << ".length();" << endl;
		} else if (tcotype == "bool") {
			outfile << "\ttinyint " << tco->sref << " = rec->" << tco->sref << ";" << endl;
		};
	};
	outfile << "// IP myInsertRec.strL --- IEND" << endl;

	// --- myInsertRec.bind
	outfile << "// IP myInsertRec.bind --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\t" << getTcoMybind(tco, "rec->", (i-1));
		if (i != (tcos.nodes.size()-1)) outfile << ",";
		outfile << endl;
	};
	outfile << "// IP myInsertRec.bind --- IEND" << endl;

	// --- myInsertRec.execUnq*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP myInsertRec.execUnq --- AFFIRM" << endl;
	else outfile << "// IP myInsertRec.execUnq --- REMOVE" << endl;

	// --- myInsertRec.execNounq*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP myInsertRec.execNounq --- AFFIRM" << endl;
	else outfile << "// IP myInsertRec.execNounq --- REMOVE" << endl;

	// --- myInsertRst.transact*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP myInsertRst.transact --- AFFIRM" << endl;
	else outfile << "// IP myInsertRst.transact --- REMOVE" << endl;

	// --- myInsertRst.notransact*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP myInsertRst.notransact --- AFFIRM" << endl;
	else outfile << "// IP myInsertRst.notransact --- REMOVE" << endl;

	// --- myUpdateRec.lne
	outfile << "// IP myUpdateRec.lne --- IBEGIN" << endl;
	outfile << "\tunsigned long l[" << tcos.nodes.size() << "]; my_bool n[" << tcos.nodes.size() << "]; my_bool e[" << tcos.nodes.size() << "];" << endl;
	outfile << "// IP myUpdateRec.lne --- IEND" << endl;

	// --- myUpdateRec.strL
	outfile << "// IP myUpdateRec.strL --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		if (tcotype == "string") {
			outfile << "\tl[" << (i-1) << "] = rec->" << tco->sref << ".length();" << endl;
		} else if (tcotype == "bool") {
			outfile << "\ttinyint " << tco->sref << " = rec->" << tco->sref << ";" << endl;
		};
	};
	outfile << "// IP myUpdateRec.strL --- IEND" << endl;

	// --- myUpdateRec.bind
	outfile << "// IP myUpdateRec.bind --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		outfile << "\t\t" << getTcoMybind(tco, "rec->", (i-1)) << "," << endl;
	};
	outfile << "\t\t" << getTcoMybind(tcos.nodes[0], "rec->", (tcos.nodes.size()-1)) << endl;
	outfile << "// IP myUpdateRec.bind --- IEND" << endl;

	// --- myUpdateRst.transact*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP myUpdateRst.transact --- AFFIRM" << endl;
	else outfile << "// IP myUpdateRst.transact --- REMOVE" << endl;

	// --- myUpdateRst.notransact*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP myUpdateRst.notransact --- AFFIRM" << endl;
	else outfile << "// IP myUpdateRst.notransact --- REMOVE" << endl;

	// --- myLoadfcts
	outfile << "// IP myLoadfcts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			writeTblCpp_lfchdr(outfile, lfc, tbl->sref, tcos, "My");

			if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
				outfile << "\tif ((limit == 0) && (offset == 0)) limit--;" << endl;
				outfile << endl;
			};

			tco = getLdTco(lfc->ldSrefWznmMTablecol, tcos);
			if (tco) s = tco->sref;
			else s = "";

			// -- SQL is embedded in return statement
			if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::CONFIRM) {
				outfile << "\tubigint val;" << endl;
				outfile << "\treturn loadRefBySQL(";
				getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, false);
				outfile << ", val);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::COUNT) {
				outfile << "\tuint cnt;" << endl;
				outfile << "\tloadUintBySQL(";
				getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, false);
				outfile << ", cnt);" << endl;
				outfile << "\treturn cnt;" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REF) {
				outfile << "\treturn loadRefBySQL(";
				getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, false);
				outfile << ", " << s << ");" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REFS) {
				outfile << "\treturn loadRefsBySQL(";
				getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, false);
				outfile << ", append, " << s << "s);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REC) {
				outfile << "\treturn loadRecBySQL(";
				getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, false);
				outfile << ", rec);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::RST) {
				outfile << "\treturn loadRstBySQL(";
				getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, false);
				outfile << ", append, rst);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::STRING) {
				outfile << "\treturn loadStringBySQL(";
				getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, false);
				outfile << ", " << s << ");" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::UINT) {
				outfile << "\treturn loadUintBySQL(";
				getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, false);
				outfile << ", " << s << ");" << endl;
			};

			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP myLoadfcts --- IEND" << endl;
};

void WznmWrdbsTbl::writeTblCpp_pg(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmAMTableLoadfct& lfcs
			, const bool hasRst
		) {
	WznmMTablecol* tco = NULL;
	string tcotype;

	WznmAMTableLoadfct* lfc = NULL;
	vector<string> lbys;
	string lby;

	string s;
	size_t ptr;

	// --- pgInitStatements.stmtInsertRec
	outfile << "// IP pgInitStatements.stmtInsertRec --- IBEGIN" << endl;
	outfile << "\tcreateStatement(\"" << tbl->sref << "_insertRec\", \"INSERT INTO " << tbl->sref << " (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref;
	};

	outfile << ") VALUES (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		if (i != 1) outfile << ",";
		outfile << "$" << i;
	};

	outfile << ") RETURNING " << tcos.nodes[0]->sref << "\", " << (tcos.nodes.size()-1) << ");" << endl;
	outfile << "// IP pgInitStatements.stmtInsertRec --- IEND" << endl;


	// --- pgInitStatements.stmtUpdateRec
	outfile << "// IP pgInitStatements.stmtUpdateRec --- IBEGIN" << endl;
	outfile << "\tcreateStatement(\"" << tbl->sref << "_updateRec\", \"UPDATE " << tbl->sref << " SET ";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref << " = $" << i;
	};

	outfile << " WHERE " << tcos.nodes[0]->sref << " = $" << tcos.nodes.size() << "\", " << tcos.nodes.size() << ");" << endl;
	outfile << "// IP pgInitStatements.stmtUpdateRec --- IEND" << endl;

	// --- pgInitStatements.stmtLoadRecByRef
	outfile << "// IP pgInitStatements.stmtLoadRecByRef --- IBEGIN" << endl;
	outfile << "\tcreateStatement(\"" << tbl->sref << "_loadRecByRef\", \"SELECT ";
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << tco->sref;
	};
	outfile << " FROM " << tbl->sref << " WHERE ref = $1\", 1);" << endl;
	outfile << "// IP pgInitStatements.stmtLoadRecByRef --- IEND" << endl;

	// --- pgInitStatements.stmts
	outfile << "// IP pgInitStatements.stmts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			StrMod::stringToVector(lfc->lbySrefsWznmMTablecol, lbys);

			outfile << "\tcreateStatement(\"" << tbl->sref << "_" << lfc->Fctname << "\", ";
			getLfcSql(outfile, lfc, tcos, tbl->sref, false, true, false);
			outfile << ", ";
			if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
				outfile << (lbys.size()+2) << ");" << endl;
			} else {
				outfile << lbys.size() << ");" << endl;
			};
		};
	};
	outfile << "// IP pgInitStatements.stmts --- IEND" << endl;

	// --- pgLoadRec.fnum
	outfile << "// IP pgLoadRec.fnum --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
	
		if (j != 0) outfile << "," << endl;

		outfile << "\t\t\tPQfnumber(res, \"" << StrMod::lc(tco->sref) << "\")";
	};
	outfile << endl;
	outfile << "// IP pgLoadRec.fnum --- IEND" << endl;

	// --- pgLoadRec.assign
	outfile << "// IP pgLoadRec.assign --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\tptr = PQgetvalue(res, 0, fnum[" << j << "]); _rec->" << tco->sref;
		if (tcotype == "tinyint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "utinyint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "smallint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "usmallint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "int") {
			outfile << " = atol(ptr);" << endl;
		} else if (tcotype == "uint") {
			outfile << " = atol(ptr);" << endl;
		} else if (tcotype == "bigint") {
			outfile << " = atoll(ptr);" << endl;
		} else if (tcotype == "ubigint") {
			outfile << " = atoll(ptr);" << endl;
		} else if (tcotype == "string") {
			outfile << ".assign(ptr, PQgetlength(res, 0, fnum[" << j << "]));" << endl;
		} else if (tcotype == "double") {
			outfile << " = atof(ptr);" << endl;
		} else if (tcotype == "bool") {
			outfile << " = (atoi(ptr) != 0);" << endl;
		};
	};
	outfile << "// IP pgLoadRec.assign --- IEND" << endl;

	// --- pgLoadRst.fnum
	outfile << "// IP pgLoadRst.fnum --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
	
		if (j != 0) outfile << "," << endl;

		outfile << "\t\t\tPQfnumber(res, \"" << StrMod::lc(tco->sref) << "\")";
	};
	outfile << endl;
	outfile << "// IP pgLoadRst.fnum --- IEND" << endl;

	// --- pgLoadRst.assign
	outfile << "// IP pgLoadRst.assign --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\t\tptr = PQgetvalue(res, numread, fnum[" << j << "]); rec->" << tco->sref;
		if (tcotype == "tinyint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "utinyint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "smallint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "usmallint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "int") {
			outfile << " = atol(ptr);" << endl;
		} else if (tcotype == "uint") {
			outfile << " = atol(ptr);" << endl;
		} else if (tcotype == "bigint") {
			outfile << " = atoll(ptr);" << endl;
		} else if (tcotype == "ubigint") {
			outfile << " = atoll(ptr);" << endl;
		} else if (tcotype == "string") {
			outfile << ".assign(ptr, PQgetlength(res, numread, fnum[" << j << "]));" << endl;
		} else if (tcotype == "double") {
			outfile << " = atof(ptr);" << endl;
		} else if (tcotype == "bool") {
			outfile << " = (atoi(ptr) != 0);" << endl;
		};
	};
	outfile << "// IP pgLoadRst.assign --- IEND" << endl;

	// --- pgLoadRstByStmt*
	if (hasRst) outfile << "// IP pgLoadRstByStmt --- AFFIRM" << endl;
	else outfile << "// IP pgLoadRstByStmt --- REMOVE" << endl;

	// --- pgInsertRec.strvecDecl
	outfile << "// IP pgInsertRec.strvecDecl --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		getTcoPgstrvec(outfile, tco, "rec->");
	};
	outfile << "// IP pgInsertRec.strvecDecl --- IEND" << endl;

	// --- pgInsertRec.vals
	outfile << "// IP pgInsertRec.vals --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << "\t\t" << getTcoPgvals(tco, "rec->");
		if (j != (tcos.nodes.size()-1)) outfile << ",";
		outfile << endl;
	};
	outfile << "// IP pgInsertRec.vals --- IEND" << endl;

	// --- pgInsertRec.l
	outfile << "// IP pgInsertRec.l --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << "\t\t" << getTcoPgl(tco);
		if (j != (tcos.nodes.size()-1)) outfile << ",";
		outfile << endl;
	};
	outfile << "// IP pgInsertRec.l --- IEND" << endl;

	// --- pgInsertRec.f
	outfile << "// IP pgInsertRec.f --- IBEGIN" << endl;
	outfile << "\tconst int f[] = {";
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << getTcoPgf(tco);
		if (j != (tcos.nodes.size()-1)) outfile << ", ";
	};
	outfile << "};" << endl;
	outfile << "// IP pgInsertRec.f --- IEND" << endl;

	// --- pgInsertRec.exec
	outfile << "// IP pgInsertRec.exec --- IBEGIN" << endl;
	outfile << "\tres = PQexecPrepared(dbs, \"" << tbl->sref << "_insertRec\", " << (tcos.nodes.size()-1) << ", vals, l, f, 0);" << endl;
	outfile << "// IP pgInsertRec.exec --- IEND" << endl;

	// --- pgInsertRec.execUnq*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP pgInsertRec.execUnq --- AFFIRM" << endl;
	else outfile << "// IP pgInsertRec.execUnq --- REMOVE" << endl;

	// --- pgInsertRec.execNounq*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP pgInsertRec.execNounq --- AFFIRM" << endl;
	else outfile << "// IP pgInsertRec.execNounq --- REMOVE" << endl;

	// --- pgInsertRst.transact*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP pgInsertRst.transact --- AFFIRM" << endl;
	else outfile << "// IP pgInsertRst.transact --- REMOVE" << endl;

	// --- pgInsertRst.notransact*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP pgInsertRst.notransact --- AFFIRM" << endl;
	else outfile << "// IP pgInsertRst.notransact --- REMOVE" << endl;

	// --- pgUpdateRec.strvecDecl
	outfile << "// IP pgUpdateRec.strvecDecl --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		getTcoPgstrvec(outfile, tco, "rec->");
	};
	getTcoPgstrvec(outfile, tcos.nodes[0], "rec->");
	outfile << "// IP pgUpdateRec.strvecDecl --- IEND" << endl;

	// --- pgUpdateRec.vals
	outfile << "// IP pgUpdateRec.vals --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << "\t\t" << getTcoPgvals(tco, "rec->") << "," << endl;
	};
	outfile << "\t\t" << getTcoPgvals(tcos.nodes[0], "rec->") << endl;
	outfile << "// IP pgUpdateRec.vals --- IEND" << endl;

	// --- pgUpdateRec.l
	outfile << "// IP pgUpdateRec.l --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << "\t\t" << getTcoPgl(tco) << "," << endl;
	};
	outfile << "\t\t" << getTcoPgl(tcos.nodes[0]) << endl;
	outfile << "// IP pgUpdateRec.l --- IEND" << endl;

	// --- pgUpdateRec.f
	outfile << "// IP pgUpdateRec.f --- IBEGIN" << endl;
	outfile << "\tconst int f[] = {";
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << getTcoPgf(tco) << ", ";
	};
	outfile << getTcoPgf(tcos.nodes[0]) << "};" << endl;
	outfile << "// IP pgUpdateRec.f --- IEND" << endl;

	// --- pgUpdateRec.exec
	outfile << "// IP pgUpdateRec.exec --- IBEGIN" << endl;
	outfile << "\tres = PQexecPrepared(dbs, \"" << tbl->sref << "_updateRec\", " << tcos.nodes.size() << ", vals, l, f, 0);" << endl;
	outfile << "// IP pgUpdateRec.exec --- IEND" << endl;

	// --- pgUpdateRst.transact*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP pgUpdateRst.transact --- AFFIRM" << endl;
	else outfile << "// IP pgUpdateRst.transact --- REMOVE" << endl;

	// --- pgUpdateRst.notransact*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP pgUpdateRst.notransact --- AFFIRM" << endl;
	else outfile << "// IP pgUpdateRst.notransact --- REMOVE" << endl;

	// --- pgLoadfcts
	outfile << "// IP pgLoadfcts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			StrMod::stringToVector(lfc->lbySrefsWznmMTablecol, lbys);

			writeTblCpp_lfchdr(outfile, lfc, tbl->sref, tcos, "Pg");

			// -- statement preparation
			// - strvec
			for (unsigned int j = 0; j < lbys.size(); j++) {
				lby = lbys[j];
				ptr = lby.find('.');
				if (ptr != string::npos) lby = lby.substr(0, ptr);

				tco = getLbyTco(lby, tcos);
				if (tco) getTcoPgstrvec(outfile, tco, "");
			};
			if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
				outfile << "\tubigint _offset = htonl64(offset);" << endl;
				outfile << endl;
				outfile << "\tubigint _limit = htonl64(limit);" << endl;
				outfile << "\tchar* _limitptr = NULL;" << endl;
				outfile << "\tint _limitl = 0;" << endl;
				outfile << endl;
				outfile << "\tif (limit != 0) {" << endl;
				outfile << "\t\t_limitptr = (char*) &_limit;" << endl;
				outfile << "\t\t_limitl = sizeof(ubigint);" << endl;
				outfile << "\t};" << endl;
			};
			outfile << endl;

			// - vals
			outfile << "\tconst char* vals[] = {" << endl;
			for (unsigned int j = 0; j < lbys.size(); j++) {
				lby = lbys[j];
				ptr = lby.find('.');
				if (ptr != string::npos) lby = lby.substr(0, ptr);

				tco = getLbyTco(lby, tcos);
				if (tco) {
					outfile << "\t\t" << getTcoPgvals(tco, "");
					if (! ((lfc->ixVLimtype != VecWznmVAMTableLoadfctLimtype::LIMOFS) && (j == (lbys.size()-1)))) outfile << ",";
					outfile << endl;
				};
			};
			if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
				outfile << "\t\t(char*) &_offset," << endl;
				outfile << "\t\t_limitptr" << endl;
			};
			outfile << "\t};" << endl;

			// - l
			outfile << "\tconst int l[] = {" << endl;
			for (unsigned int j = 0; j < lbys.size(); j++) {
				lby = lbys[j];
				ptr = lby.find('.');
				if (ptr != string::npos) lby = lby.substr(0, ptr);

				tco = getLbyTco(lby, tcos);
				if (tco) {
					outfile << "\t\t" << getTcoPgl(tco);
					if (! ((lfc->ixVLimtype != VecWznmVAMTableLoadfctLimtype::LIMOFS) && (j == (lbys.size()-1)))) outfile << ",";
					outfile << endl;
				};
			};
			if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
				outfile << "\t\tsizeof(ubigint)," << endl;
				outfile << "\t\t_limitl" << endl;
			};
			outfile << "\t};" << endl;

			// - f
			outfile << "\tconst int f[] = {";
			for (unsigned int j = 0; j < lbys.size(); j++) {
				lby = lbys[j];
				ptr = lby.find('.');
				if (ptr != string::npos) lby = lby.substr(0, ptr);

				tco = getLbyTco(lby, tcos);
				if (tco) {
					outfile << getTcoPgf(tco);
					if (! ((lfc->ixVLimtype != VecWznmVAMTableLoadfctLimtype::LIMOFS) && (j == (lbys.size()-1)))) outfile << ",";
				};
			};
			if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) outfile << "1,1";
			outfile << "};" << endl;
			outfile << endl;

			// -- return behaviour
			tco = getLdTco(lfc->ldSrefWznmMTablecol, tcos);
			if (tco) s = tco->sref;
			else s = "";

			if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::CONFIRM) {
				lby = lbys[0];
				ptr = lby.find('.');
				if (ptr != string::npos) lby = lby.substr(0, ptr);
				outfile << "\treturn loadRefByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", 1, vals, l, f, _" << lby << ");" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::COUNT) {
				outfile << "\tuint cnt;" << endl;
				outfile << "\tloadUintByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", " << lbys.size() << ", vals, l, f, cnt);" << endl;
				outfile << "\treturn cnt;" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REF) {
				outfile << "\treturn loadRefByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", " << lbys.size() << ", vals, l, f, " << s << ");" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REFS) {
				outfile << "\treturn loadRefsByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", " << lbys.size() << ", vals, l, f, append, " << s << "s);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REC) {
				outfile << "\treturn loadRecByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", " << lbys.size() << ", vals, l, f, rec);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::RST) {
				if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
					outfile << "\treturn loadRstByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", " << (lbys.size()+2) << ", vals, l, f, append, rst);" << endl;
				} else {
					outfile << "\treturn loadRstByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", " << lbys.size() << ", vals, l, f, append, rst);" << endl;
				};
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::STRING) {
				outfile << "\treturn loadStringByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", " << lbys.size() << ", vals, l, f, " << s << ");" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::UINT) {
				outfile << "\treturn loadUintByStmt(\"" << tbl->sref << "_" << lfc->Fctname << "\", " << lbys.size() << ", vals, l, f, " << s << ");" << endl;
			};
			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP pgLoadfcts --- IEND" << endl;
};

void WznmWrdbsTbl::writeTblCpp_lite(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmAMTableLoadfct& lfcs
			, const bool hasRst
		) {
	WznmMTablecol* tco = NULL;
	string tcotype;

	WznmAMTableLoadfct* lfc = NULL;
	vector<string> lbys;
	string lby;

	string s;
	size_t ptr;

	// --- liteConstructor.stmts
	outfile << "// IP liteConstructor.stmts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) outfile << "\tstmt" << StrMod::cap(lfc->Fctname) << " = NULL;" << endl;
	};
	outfile << "// IP liteConstructor.stmts --- IEND" << endl;

	// --- liteDestructor.stmts
	outfile << "// IP liteDestructor.stmts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) outfile << "\tif (stmt" << StrMod::cap(lfc->Fctname) << ") sqlite3_finalize(stmt" << StrMod::cap(lfc->Fctname) << ");" << endl;
	};
	outfile << "// IP liteDestructor.stmts --- IEND" << endl;

	// --- liteInitStatements.stmtInsertRec
	outfile << "// IP liteInitStatements.stmtInsertRec --- IBEGIN" << endl;
	outfile << "\tstmtInsertRec = createStatement(\"INSERT INTO " << tbl->sref << " (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref;
	};

	outfile << ") VALUES (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		if (i != 1) outfile << ",";
		outfile << "?" << i;
	};

	outfile << ")\");" << endl;
	outfile << "// IP liteInitStatements.stmtInsertRec --- IEND" << endl;

	// --- liteInitStatements.stmtUpdateRec
	outfile << "// IP liteInitStatements.stmtUpdateRec --- IBEGIN" << endl;
	outfile << "\tstmtUpdateRec = createStatement(\"UPDATE " << tbl->sref << " SET ";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref << " = ?" << i;
	};

	outfile << " WHERE " << tcos.nodes[0]->sref << " = ?" << tcos.nodes.size() << "\");" << endl;
	outfile << "// IP liteInitStatements.stmtUpdateRec --- IEND" << endl;

	// --- liteInitStatements.stmtLoadRecByRef
	outfile << "// IP liteInitStatements.stmtLoadRecByRef --- IBEGIN" << endl;
	outfile << "\tstmtLoadRecByRef = createStatement(\"SELECT ";
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << tco->sref;
	};
	outfile << " FROM " << tbl->sref << " WHERE ref = ?1\");" << endl;
	outfile << "// IP liteInitStatements.stmtLoadRecByRef --- IEND" << endl;

	// --- liteInitStatements.stmts
	outfile << "// IP liteInitStatements.stmts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			outfile << "\tstmt" << StrMod::cap(lfc->Fctname) << " = createStatement(";
			getLfcSql(outfile, lfc, tcos, tbl->sref, false, false, true);
			outfile << ");" << endl;
		};
	};
	outfile << "// IP liteInitStatements.stmts --- IEND" << endl;

	// --- liteLoadRec.assign
	outfile << "// IP liteLoadRec.assign --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\t_rec->" << tco->sref;
		if (tcotype == "tinyint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "utinyint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "smallint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "usmallint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "int") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "uint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "bigint") {
			outfile << " = sqlite3_column_int64(stmt, " << j << ");" << endl;
		} else if (tcotype == "ubigint") {
			outfile << " = sqlite3_column_int64(stmt, " << j << ");" << endl;
		} else if (tcotype == "string") {
			outfile << ".assign((const char*) sqlite3_column_text(stmt, " << j << "));" << endl;
		} else if (tcotype == "double") {
			outfile << " = sqlite3_column_double(stmt, " << j << ");" << endl;
		} else if (tcotype == "bool") {
			outfile << " = (sqlite3_column_int(stmt, " << j << ") != 0);" << endl;
		};
	};
	outfile << "// IP liteLoadRec.assign --- IEND" << endl;

	// --- liteLoadRst.assign
	outfile << "// IP liteLoadRst.assign --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\trec->" << tco->sref;
		if (tcotype == "tinyint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "utinyint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "smallint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "usmallint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "int") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "uint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "bigint") {
			outfile << " = sqlite3_column_int64(stmt, " << j << ");" << endl;
		} else if (tcotype == "ubigint") {
			outfile << " = sqlite3_column_int64(stmt, " << j << ");" << endl;
		} else if (tcotype == "string") {
			outfile << ".assign((const char*) sqlite3_column_text(stmt, " << j << "));" << endl;
		} else if (tcotype == "double") {
			outfile << " = sqlite3_column_double(stmt, " << j << ");" << endl;
		} else if (tcotype == "bool") {
			outfile << " = (sqlite3_column_int(stmt, " << j << ") != 0);" << endl;
		};
	};
	outfile << "// IP liteLoadRst.assign --- IEND" << endl;

	// --- liteLoadRstByStmt*
	if (hasRst) outfile << "// IP liteLoadRstByStmt --- AFFIRM" << endl;
	else outfile << "// IP liteLoadRstByStmt --- REMOVE" << endl;

	// --- liteInsertRec.bind
	outfile << "// IP liteInsertRec.bind --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t" << getTcoLitebind(tco, "rec->", "stmtInsertRec", i) << ";" << endl;
	};
	outfile << "// IP liteInsertRec.bind --- IEND" << endl;

	// --- liteInsertRec.execUnq*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP liteInsertRec.execUnq --- AFFIRM" << endl;
	else outfile << "// IP liteInsertRec.execUnq --- REMOVE" << endl;

	// --- liteInsertRec.execNounq*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP liteInsertRec.execNounq --- AFFIRM" << endl;
	else outfile << "// IP liteInsertRec.execNounq --- REMOVE" << endl;

	// --- liteInsertRst.transact*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP liteInsertRst.transact --- AFFIRM" << endl;
	else outfile << "// IP liteInsertRst.transact --- REMOVE" << endl;

	// --- liteInsertRst.notransact*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP liteInsertRst.notransact --- AFFIRM" << endl;
	else outfile << "// IP liteInsertRst.notransact --- REMOVE" << endl;

	// --- liteUpdateRec.bind
	outfile << "// IP liteUpdateRec.bind --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t" << getTcoLitebind(tco, "rec->", "stmtUpdateRec", i) << ";" << endl;
	};
	outfile << "\t" << getTcoLitebind(tcos.nodes[0], "rec->", "stmtUpdateRec", tcos.nodes.size()) << ";" << endl;
	outfile << "// IP liteUpdateRec.bind --- IEND" << endl;

	// --- liteUpdateRst.transact*
	if (tbl->unqSrefsWznmMTablecol == "") outfile << "// IP liteUpdateRst.transact --- AFFIRM" << endl;
	else outfile << "// IP liteUpdateRst.transact --- REMOVE" << endl;

	// --- liteUpdateRst.notransact*
	if (tbl->unqSrefsWznmMTablecol != "") outfile << "// IP liteUpdateRst.notransact --- AFFIRM" << endl;
	else outfile << "// IP liteUpdateRst.notransact --- REMOVE" << endl;

	// --- liteLoadfcts
	outfile << "// IP liteLoadfcts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < lfcs.nodes.size(); i++) {
		lfc = lfcs.nodes[i];

		if (getLfc(lfc->ixVLoadtype)) {
			StrMod::stringToVector(lfc->lbySrefsWznmMTablecol, lbys);

			writeTblCpp_lfchdr(outfile, lfc, tbl->sref, tcos, "Lite");

			// -- statement preparation
			for (unsigned int j = 0; j < lbys.size(); j++) {
				lby = lbys[j];
				ptr = lby.find('.');
				if (ptr != string::npos) lby = lby.substr(0, ptr);

				tco = getLbyTco(lby, tcos);
				if (tco) outfile << "\t" << getTcoLitebind(tco, "", "stmt" + StrMod::cap(lfc->Fctname), (j+1)) << ";" << endl;
			};

			if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
				outfile << "\tsqlite3_bind_int64(stmt" << StrMod::cap(lfc->Fctname) << ", " << (lbys.size()+1) << ", offset);" << endl;
				outfile << "\tif (limit == 0) sqlite3_bind_int64(stmt" << StrMod::cap(lfc->Fctname) << ", " << (lbys.size()+2) << ", -1); else sqlite3_bind_int64(stmt" << StrMod::cap(lfc->Fctname) << ", " << (lbys.size()+2) << ", limit);" << endl;
			};
			outfile << endl;

			// -- return behaviour
			tco = getLdTco(lfc->ldSrefWznmMTablecol, tcos);
			if (tco) s = tco->sref;
			else s = "";

			if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::CONFIRM) {
				outfile << "\tubigint val;" << endl;
				outfile << "\treturn loadRefByStmt(stmt" << StrMod::cap(lfc->Fctname) << ", val);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::COUNT) {
				outfile << "\tuint cnt;" << endl;
				outfile << "\tloadUintByStmt(stmt" << StrMod::cap(lfc->Fctname) << ", cnt);" << endl;
				outfile << "\treturn cnt;" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REF) {
				outfile << "\treturn loadRefByStmt(stmt" << StrMod::cap(lfc->Fctname) << ", " << s << ");" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REFS) {
				outfile << "\treturn loadRefsByStmt(stmt" << StrMod::cap(lfc->Fctname) << ", append, " << s << "s);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REC) {
				outfile << "\treturn loadRecByStmt(stmt" << StrMod::cap(lfc->Fctname) << ", rec);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::RST) {
				outfile << "\treturn loadRstByStmt(stmt" << StrMod::cap(lfc->Fctname) << ", append, rst);" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::STRING) {
				outfile << "\treturn loadStringByStmt(stmt" << StrMod::cap(lfc->Fctname) << ", " << s << ");" << endl;
			} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::UINT) {
				outfile << "\treturn loadUintByStmt(stmt" << StrMod::cap(lfc->Fctname) << ", " << s << ");" << endl;
			};

			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP liteLoadfcts --- IEND" << endl;
};

void WznmWrdbsTbl::writeTblCpp_lfchdr(
			fstream& outfile
			, WznmAMTableLoadfct* lfc
			, const string& tblsref
			, const ListWznmMTablecol& tcos
			, const string& prefix
		) {
	vector<string> lbys;
	string lby;

	WznmMTablecol* tco = NULL;

	bool found, first;
	string resvar;

	size_t ptr;

	// extract "load by" table columns
	StrMod::stringToVector(lfc->lbySrefsWznmMTablecol, lbys);

	outfile << getLfcRetType(lfc->ixVLoadtype, false) << " " << prefix << tblsref << "::" << lfc->Fctname << "(" << endl;

	// parameters
	first = true;
	for (unsigned int j = 0; j < lbys.size(); j++) {
		lby = lbys[j];
		ptr = lby.find('.');
		if (ptr != string::npos) lby = lby.substr(0, ptr);

		// find in tco's
		found = false;
		for (unsigned int k = 0; k < tcos.nodes.size(); k++) {
			tco = tcos.nodes[k];

			if (tco->sref == lby) {
				found = true;
				break;
			};
		};

		if (found) {
			outfile << "\t\t\t";
			if (first) first = false;
			else outfile << ", ";

			outfile << getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false) << " " << tco->sref << endl;
		};
	};

	// append flag
	if (getLfcAppend(lfc->ixVLoadtype)) {
		outfile << "\t\t\t";
		if (first) first = false;
		else outfile << ", ";

		outfile << "const bool append" << endl;
	};

	// result variable
	tco = getLdTco(lfc->ldSrefWznmMTablecol, tcos);

	if (tco) resvar = getLfcRes(tblsref, lfc->ixVLoadtype, tco->sref, false);
	else resvar = getLfcRes(tblsref, lfc->ixVLoadtype, "", false);

	if (resvar != "") {
		outfile << "\t\t\t";
		if (first) first = false;
		else outfile << ", ";

		outfile << resvar << endl;
	};

	// limit / offset clause
	if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
		outfile << "\t\t\t, ubigint limit" << endl;
		outfile << "\t\t\t, ubigint offset" << endl;
	};

	outfile << "\t\t) {" << endl;
};

void WznmWrdbsTbl::writeQtbH(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmMQuerycol& qcos
			, const bool dbsmy
			, const bool dbspg
			, const bool dbslite
		) {
	WznmMQuerycol* qco = NULL;

	string qcotype;

	// --- include.my*
	if (dbsmy) outfile << "// IP include.my --- AFFIRM" << endl;
	else outfile << "// IP include.my --- REMOVE" << endl;

	// --- include.pg*
	if (dbspg) outfile << "// IP include.pg --- AFFIRM" << endl;
	else outfile << "// IP include.pg --- REMOVE" << endl;

	// --- include.lite*
	if (dbslite) outfile << "// IP include.lite --- AFFIRM" << endl;
	else outfile << "// IP include.lite --- REMOVE" << endl;

	// --- constructor
	outfile << "// IP constructor --- IBEGIN" << endl;
	outfile << "\t" << tbl->sref.substr(3) << "(";
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		qcotype = getQcoCppType(qco->ixVBasetype, true);
		if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, true);

		if (i != 0) outfile << ", ";
		outfile << "const " << qcotype << " " << qco->sref << " = " << getQcoCppDefault(qcotype);
	};
	outfile << ");" << endl;
	outfile << "// IP constructor --- IEND" << endl;

	// --- tcos
	outfile << "// IP tcos --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		qcotype = getQcoCppType(qco->ixVBasetype, true);
		if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, true);

		outfile << "\t" << qcotype << " " << qco->sref << ";" << endl;
	};
	outfile << "// IP tcos --- IEND" << endl;

	// --- insertNewRec
	outfile << "// IP insertNewRec --- IBEGIN" << endl;
	outfile << "\tSbecore::ubigint insertNewRec(" << tbl->sref.substr(3) << "** rec = NULL";
	for (unsigned int i=1;i<qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		qcotype = getQcoCppType(qco->ixVBasetype, true);
		if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, true);

		outfile << ", const " << qcotype << " " << qco->sref << " = " << getQcoCppDefault(qcotype);
	};
	outfile << ");" << endl;
	outfile << "// IP insertNewRec --- IEND" << endl;

	// --- appendNewRecToRst
	outfile << "// IP appendNewRecToRst --- IBEGIN" << endl;
	outfile << "\tSbecore::ubigint appendNewRecToRst(List" << tbl->sref.substr(3) << "& rst, " << tbl->sref.substr(3) << "** rec = NULL";
	for (unsigned int i=1;i<qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		qcotype = getQcoCppType(qco->ixVBasetype, true);
		if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, true);

		outfile << ", const " << qcotype << " " << qco->sref << " = " << getQcoCppDefault(qcotype);
	};
	outfile << ");" << endl;
	outfile << "// IP appendNewRecToRst --- IEND" << endl;

	// --- myTbl*
	if (dbsmy) outfile << "// IP myTbl --- AFFIRM" << endl;
	else outfile << "// IP myTbl --- REMOVE" << endl;

	// --- pgTbl*
	if (dbspg) outfile << "// IP pgTbl --- AFFIRM" << endl;
	else outfile << "// IP pgTbl --- REMOVE" << endl;

	// --- liteTbl*
	if (dbslite) outfile << "// IP liteTbl --- AFFIRM" << endl;
	else outfile << "// IP liteTbl --- REMOVE" << endl;
};

void WznmWrdbsTbl::writeQtbCpp(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const bool hasString
			, const ListWznmMQuerycol& qcos
			, const bool dbsmy
			, const bool dbspg
			, const bool dbslite
		) {
	WznmMQuerycol* qco = NULL;

	string tcotype;
	string qcotype;

	bool hasqwr = false;

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QWR) {
			hasqwr = true;
			break;
		};
	};

	// --- constructor.hdr
	outfile << "// IP constructor.hdr --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		qcotype = getQcoCppType(qco->ixVBasetype, false);
		if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, false);

		outfile << "\t\t\t";
		if (i != 0) outfile << ", ";
		outfile << "const " << qcotype << " " << qco->sref << endl;
	};
	outfile << "// IP constructor.hdr --- IEND" << endl;

	// --- constructor
	outfile << "// IP constructor --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		outfile << "\tthis->" << qco->sref << " = " << qco->sref << ";" << endl;
	};
	outfile << "// IP constructor --- IEND" << endl;

	// --- writeXML.shorttags
	outfile << "// IP writeXML.shorttags --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
			qcotype = getQcoCppType(qco->ixVBasetype, false);
			if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, false);

			outfile << "\t\t" << getQcoWrite(qcotype) << "(wr, \"" << qco->Short << "\", " << qco->sref << ");" << endl;
		};
	};
	outfile << "// IP writeXML.shorttags --- IEND" << endl;

	// --- writeXML.nonshorttags
	outfile << "// IP writeXML.nonshorttags --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
			qcotype = getQcoCppType(qco->ixVBasetype, false);
			if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, false);

			outfile << "\t\t" << getQcoWrite(qcotype) << "(wr, \"" << qco->sref << "\", " << qco->sref << ");" << endl;
		};
	};
	outfile << "// IP writeXML.nonshorttags --- IEND" << endl;

	// --- listWriteXML.qwr
	if (hasqwr) outfile << "// IP listWriteXML.qwr --- AFFIRM" << endl;
	else outfile << "// IP listWriteXML.qwr --- REMOVE" << endl;

	// --- listWriteXML.noqwr
	if (!hasqwr) outfile << "// IP listWriteXML.noqwr --- AFFIRM" << endl;
	else outfile << "// IP listWriteXML.noqwr --- REMOVE" << endl;

	// --- insertNewRec.hdr
	outfile << "// IP insertNewRec.hdr --- IBEGIN" << endl;
	for (unsigned int i=1;i<qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		qcotype = getQcoCppType(qco->ixVBasetype, false);
		if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, false);

		outfile << "\t\t\t, const " << qcotype << " " << qco->sref << endl;
	};
	outfile << "// IP insertNewRec.hdr --- IEND" << endl;

	// --- insertNewRec.new
	outfile << "// IP insertNewRec.new --- IBEGIN" << endl;
	outfile << "\t_rec = new " << tbl->sref.substr(3) << "(0";
	for (unsigned int i=1;i<qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		outfile << ", " << qco->sref;
	};
	outfile << ");" << endl;
	outfile << "// IP insertNewRec.new --- IEND" << endl;

	// --- appendNewRecToRst.hdr
	outfile << "// IP appendNewRecToRst.hdr --- IBEGIN" << endl;
	for (unsigned int i=1;i<qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		qcotype = getQcoCppType(qco->ixVBasetype, false);
		if (qcotype == "") for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, false);

		outfile << "\t\t\t, const " << qcotype << " " << qco->sref << endl;
	};
	outfile << "// IP appendNewRecToRst.hdr --- IEND" << endl;

	// --- appendNewRecToRst.insert
	outfile << "// IP appendNewRecToRst.insert --- IBEGIN" << endl;
	outfile << "\tretval = insertNewRec(&_rec";
	for (unsigned int i=1;i<qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		outfile << ", " << qco->sref;
	};
	outfile << ");" << endl;
	outfile << "// IP appendNewRecToRst.insert --- IEND" << endl;

	// --- myTbl*
	if (dbsmy) {
		outfile << "// IP myTbl --- AFFIRM" << endl;
		writeQtbCpp_my(outfile, tbl, tcos, hasString);
	} else {
		outfile << "// IP myTbl --- REMOVE" << endl;
	};

	// --- pgTbl*
	if (dbspg) {
		outfile << "// IP pgTbl --- AFFIRM" << endl;
		writeQtbCpp_pg(outfile, tbl, tcos);
	} else {
		outfile << "// IP pgTbl --- REMOVE" << endl;
	};

	// --- liteTbl*
	if (dbslite) {
		outfile << "// IP liteTbl --- AFFIRM" << endl;
		writeQtbCpp_lite(outfile, tbl, tcos);
	} else {
		outfile << "// IP liteTbl --- REMOVE" << endl;
	};
};

void WznmWrdbsTbl::writeQtbCpp_my(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const bool hasString
		) {
	WznmMTablecol* tco = NULL;
	string tcotype;

	// --- myInitStatements.stmtInsertRec (exact copy of writeTblCpp)
	outfile << "// IP myInitStatements.stmtInsertRec --- IBEGIN" << endl;
	outfile << "\tstmtInsertRec = createStatement(\"INSERT INTO " << tbl->sref << " (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref;
	};

	outfile << ") VALUES (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		if (i != 1) outfile << ",";
		outfile << "?";
	};

	outfile << ")\", false);" << endl;
	outfile << "// IP myInitStatements.stmtInsertRec --- IEND" << endl;

	// --- myInitStatements.stmtUpdateRec (exact copy of writeTblCpp)
	outfile << "// IP myInitStatements.stmtUpdateRec --- IBEGIN" << endl;
	outfile << "\tstmtUpdateRec = createStatement(\"UPDATE " << tbl->sref << " SET ";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref << " = ?";
	};

	outfile << " WHERE " << tcos.nodes[0]->sref << " = ?\", false);" << endl;
	outfile << "// IP myInitStatements.stmtUpdateRec --- IEND" << endl;

	// --- myLoadRecBySQL.dblengths* (exact copy of writeTblCpp)
	if (hasString) outfile << "// IP myLoadRecBySQL.dblengths --- AFFIRM" << endl;
	else outfile << "// IP myLoadRecBySQL.dblengths --- REMOVE" << endl;

	// --- myLoadRecBySQL.extract (exact copy of writeTblCpp)
	outfile << "// IP myLoadRecBySQL.extract --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\tif (dbrow[" << i << "]) _rec->" << tco->sref;

		if (tcotype == "tinyint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "utinyint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "smallint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "usmallint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "int") {
			outfile << " = atol((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "uint") {
			outfile << " = atol((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "bigint") {
			outfile << " = atoll((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "ubigint") {
			outfile << " = atoll((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0";
		} else if (tcotype == "string") {
			outfile << ".assign(dbrow[" << i << "], dblengths[" << i << "]); else _rec->" << tco->sref << " = \"\"";
		} else if (tcotype == "double") {
			outfile << " = atof((char*) dbrow[" << i << "]); else _rec->" << tco->sref << " = 0.0";
		} else if (tcotype == "bool") {
			outfile << " = (atoi((char*) dbrow[" << i << "]) != 0); else _rec->" << tco->sref << " = false";
		};

		outfile << ";" << endl;
	};
	outfile << "// IP myLoadRecBySQL.extract --- IEND" << endl;

	// --- myLoadRstBySQL.dblengths* (exact copy of writeTblCpp)
	if (hasString) outfile << "// IP myLoadRstBySQL.dblengths --- AFFIRM" << endl;
	else outfile << "// IP myLoadRstBySQL.dblengths --- REMOVE" << endl;

	// --- myLoadRstBySQL.extract (exact copy of writeTblCpp)
	outfile << "// IP myLoadRstBySQL.extract --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\t\tif (dbrow[" << i << "]) rec->" << tco->sref;

		if (tcotype == "tinyint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "utinyint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "smallint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "usmallint") {
			outfile << " = atoi((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "int") {
			outfile << " = atol((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "uint") {
			outfile << " = atol((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "bigint") {
			outfile << " = atoll((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "ubigint") {
			outfile << " = atoll((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0";
		} else if (tcotype == "string") {
			outfile << ".assign(dbrow[" << i << "], dblengths[" << i << "]); else rec->" << tco->sref << " = \"\"";
		} else if (tcotype == "double") {
			outfile << " = atof((char*) dbrow[" << i << "]); else rec->" << tco->sref << " = 0.0";
		} else if (tcotype == "bool") {
			outfile << " = (atoi((char*) dbrow[" << i << "]) != 0); else rec->" << tco->sref << " = false";
		};

		outfile << ";" << endl;
	};
	outfile << "// IP myLoadRstBySQL.extract --- IEND" << endl;

	// --- myInsertRec.lne (exact copy of writeTblCpp)
	outfile << "// IP myInsertRec.lne --- IBEGIN" << endl;
	outfile << "\tunsigned long l[" << (tcos.nodes.size()-1) << "]; my_bool n[" << (tcos.nodes.size()-1) << "]; my_bool e[" << (tcos.nodes.size()-1) << "];" << endl;
	outfile << "// IP myInsertRec.lne --- IEND" << endl;

	// --- myInsertRec.strL (exact copy of writeTblCpp)
	outfile << "// IP myInsertRec.strL --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		if (tcotype == "string") {
			outfile << "\tl[" << (i-1) << "] = rec->" << tco->sref << ".length();" << endl;
		} else if (tcotype == "bool") {
			outfile << "\ttinyint " << tco->sref << " = rec->" << tco->sref << ";" << endl;
		};
	};
	outfile << "// IP myInsertRec.strL --- IEND" << endl;

	// --- myInsertRec.bind (exact copy of writeTblCpp)
	outfile << "// IP myInsertRec.bind --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\t" << getTcoMybind(tco, "rec->", (i-1));
		if (i != (tcos.nodes.size()-1)) outfile << ",";
		outfile << endl;
	};
	outfile << "// IP myInsertRec.bind --- IEND" << endl;

	// --- myUpdateRec.lne (exact copy of writeTblCpp)
	outfile << "// IP myUpdateRec.lne --- IBEGIN" << endl;
	outfile << "\tunsigned long l[" << tcos.nodes.size() << "]; my_bool n[" << tcos.nodes.size() << "]; my_bool e[" << tcos.nodes.size() << "];" << endl;
	outfile << "// IP myUpdateRec.lne --- IEND" << endl;

	// --- myUpdateRec.strL (exact copy of writeTblCpp)
	outfile << "// IP myUpdateRec.strL --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		if (tcotype == "string") {
			outfile << "\tl[" << (i-1) << "] = rec->" << tco->sref << ".length();" << endl;
		} else if (tcotype == "bool") {
			outfile << "\ttinyint " << tco->sref << " = rec->" << tco->sref << ";" << endl;
		};
	};
	outfile << "// IP myUpdateRec.strL --- IEND" << endl;

	// --- myUpdateRec.bind (exact copy of writeTblCpp)
	outfile << "// IP myUpdateRec.bind --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		outfile << "\t\t" << getTcoMybind(tco, "rec->", (i-1)) << "," << endl;
	};
	outfile << "\t\t" << getTcoMybind(tcos.nodes[0], "rec->", (tcos.nodes.size()-1)) << endl;
	outfile << "// IP myUpdateRec.bind --- IEND" << endl;
};

void WznmWrdbsTbl::writeQtbCpp_pg(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
		) {
	WznmMTablecol* tco = NULL;
	string tcotype;

	// --- pgInitStatements.stmtInsertRec (exact copy of writeTblCpp)
	outfile << "// IP pgInitStatements.stmtInsertRec --- IBEGIN" << endl;
	outfile << "\tcreateStatement(\"" << tbl->sref << "_insertRec\", \"INSERT INTO " << tbl->sref << " (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref;
	};

	outfile << ") VALUES (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		if (i != 1) outfile << ",";
		outfile << "$" << i;
	};

	outfile << ") RETURNING " << tcos.nodes[0]->sref << "\", " << (tcos.nodes.size()-1) << ");" << endl;
	outfile << "// IP pgInitStatements.stmtInsertRec --- IEND" << endl;

	// --- pgInitStatements.stmtUpdateRec (exact copy of writeTblCpp)
	outfile << "// IP pgInitStatements.stmtUpdateRec --- IBEGIN" << endl;
	outfile << "\tcreateStatement(\"" << tbl->sref << "_updateRec\", \"UPDATE " << tbl->sref << " SET ";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref << " = $" << i;
	};

	outfile << " WHERE " << tcos.nodes[0]->sref << " = $" << tcos.nodes.size() << "\", " << tcos.nodes.size() << ");" << endl;
	outfile << "// IP pgInitStatements.stmtUpdateRec --- IEND" << endl;

	// --- pgInitStatements.stmtLoadRecByQref
	outfile << "// IP pgInitStatements.stmtLoadRecByQref --- IBEGIN" << endl;
	outfile << "\tcreateStatement(\"" << tbl->sref << "_loadRecByQref\", \"SELECT ";
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << tco->sref;
	};
	outfile << " FROM " << tbl->sref << " WHERE qref = $1\", 1);" << endl;
	outfile << "// IP pgInitStatements.stmtLoadRecByQref --- IEND" << endl;

	// --- pgInitStatements.stmtLoadRstByJref
	outfile << "// IP pgInitStatements.stmtLoadRstByJref --- IBEGIN" << endl;
	outfile << "\tcreateStatement(\"" << tbl->sref << "_loadRstByJref\", \"SELECT ";
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << tco->sref;
	};
	outfile << " FROM " << tbl->sref << " WHERE jref = $1 ORDER BY jnum ASC\", 1);" << endl;
	outfile << "// IP pgInitStatements.stmtLoadRstByJref --- IEND" << endl;

	// --- pgLoadRec.fnum (exact copy of writeTblCpp)
	outfile << "// IP pgLoadRec.fnum --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
	
		if (j != 0) outfile << "," << endl;

		outfile << "\t\t\tPQfnumber(res, \"" << StrMod::lc(tco->sref) << "\")";
	};
	outfile << endl;
	outfile << "// IP pgLoadRec.fnum --- IEND" << endl;

	// --- pgLoadRec.assign (exact copy of writeTblCpp)
	outfile << "// IP pgLoadRec.assign --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\tptr = PQgetvalue(res, 0, fnum[" << j << "]); _rec->" << tco->sref;
		if (tcotype == "tinyint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "utinyint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "smallint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "usmallint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "int") {
			outfile << " = atol(ptr);" << endl;
		} else if (tcotype == "uint") {
			outfile << " = atol(ptr);" << endl;
		} else if (tcotype == "bigint") {
			outfile << " = atoll(ptr);" << endl;
		} else if (tcotype == "ubigint") {
			outfile << " = atoll(ptr);" << endl;
		} else if (tcotype == "string") {
			outfile << ".assign(ptr, PQgetlength(res, 0, fnum[" << j << "]));" << endl;
		} else if (tcotype == "double") {
			outfile << " = atof(ptr);" << endl;
		} else if (tcotype == "bool") {
			outfile << " = (atoi(ptr) != 0);" << endl;
		};
	};
	outfile << "// IP pgLoadRec.assign --- IEND" << endl;

	// --- pgLoadRst.fnum (exact copy of writeTblCpp)
	outfile << "// IP pgLoadRst.fnum --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
	
		if (j != 0) outfile << "," << endl;

		outfile << "\t\t\tPQfnumber(res, \"" << StrMod::lc(tco->sref) << "\")";
	};
	outfile << endl;
	outfile << "// IP pgLoadRst.fnum --- IEND" << endl;

	// --- pgLoadRst.assign (exact copy of writeTblCpp)
	outfile << "// IP pgLoadRst.assign --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\t\tptr = PQgetvalue(res, numread, fnum[" << j << "]); rec->" << tco->sref;
		if (tcotype == "tinyint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "utinyint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "smallint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "usmallint") {
			outfile << " = atoi(ptr);" << endl;
		} else if (tcotype == "int") {
			outfile << " = atol(ptr);" << endl;
		} else if (tcotype == "uint") {
			outfile << " = atol(ptr);" << endl;
		} else if (tcotype == "bigint") {
			outfile << " = atoll(ptr);" << endl;
		} else if (tcotype == "ubigint") {
			outfile << " = atoll(ptr);" << endl;
		} else if (tcotype == "string") {
			outfile << ".assign(ptr, PQgetlength(res, numread, fnum[" << j << "]));" << endl;
		} else if (tcotype == "double") {
			outfile << " = atof(ptr);" << endl;
		} else if (tcotype == "bool") {
			outfile << " = (atoi(ptr) != 0);" << endl;
		};
	};
	outfile << "// IP pgLoadRst.assign --- IEND" << endl;

	// --- pgInsertRec.strvecDecl (exact copy of writeTblCpp)
	outfile << "// IP pgInsertRec.strvecDecl --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		getTcoPgstrvec(outfile, tco, "rec->");
	};
	outfile << "// IP pgInsertRec.strvecDecl --- IEND" << endl;

	// --- pgInsertRec.vals (exact copy of writeTblCpp)
	outfile << "// IP pgInsertRec.vals --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << "\t\t" << getTcoPgvals(tco, "rec->");
		if (j != (tcos.nodes.size()-1)) outfile << ",";
		outfile << endl;
	};
	outfile << "// IP pgInsertRec.vals --- IEND" << endl;

	// --- pgInsertRec.l (exact copy of writeTblCpp)
	outfile << "// IP pgInsertRec.l --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << "\t\t" << getTcoPgl(tco);
		if (j != (tcos.nodes.size()-1)) outfile << ",";
		outfile << endl;
	};
	outfile << "// IP pgInsertRec.l --- IEND" << endl;

	// --- pgInsertRec.f (exact copy of writeTblCpp)
	outfile << "// IP pgInsertRec.f --- IBEGIN" << endl;
	outfile << "\tconst int f[] = {";
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << getTcoPgf(tco);
		if (j != (tcos.nodes.size()-1)) outfile << ", ";
	};
	outfile << "};" << endl;
	outfile << "// IP pgInsertRec.f --- IEND" << endl;

	// --- pgInsertRec.exec (exact copy of writeTblCpp)
	outfile << "// IP pgInsertRec.exec --- IBEGIN" << endl;
	outfile << "\tres = PQexecPrepared(dbs, \"" << tbl->sref << "_insertRec\", " << (tcos.nodes.size()-1) << ", vals, l, f, 0);" << endl;
	outfile << "// IP pgInsertRec.exec --- IEND" << endl;

	// --- pgUpdateRec.strvecDecl (exact copy of writeTblCpp)
	outfile << "// IP pgUpdateRec.strvecDecl --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		getTcoPgstrvec(outfile, tco, "rec->");
	};
	getTcoPgstrvec(outfile, tcos.nodes[0], "rec->");
	outfile << "// IP pgUpdateRec.strvecDecl --- IEND" << endl;

	// --- pgUpdateRec.vals (exact copy of writeTblCpp)
	outfile << "// IP pgUpdateRec.vals --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << "\t\t" << getTcoPgvals(tco, "rec->") << "," << endl;
	};
	outfile << "\t\t" << getTcoPgvals(tcos.nodes[0], "rec->") << endl;
	outfile << "// IP pgUpdateRec.vals --- IEND" << endl;

	// --- pgUpdateRec.l (exact copy of writeTblCpp)
	outfile << "// IP pgUpdateRec.l --- IBEGIN" << endl;
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << "\t\t" << getTcoPgl(tco) << "," << endl;
	};
	outfile << "\t\t" << getTcoPgl(tcos.nodes[0]) << endl;
	outfile << "// IP pgUpdateRec.l --- IEND" << endl;

	// --- pgUpdateRec.f (exact copy of writeTblCpp)
	outfile << "// IP pgUpdateRec.f --- IBEGIN" << endl;
	outfile << "\tconst int f[] = {";
	for (unsigned int j=1;j<tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];

		outfile << getTcoPgf(tco) << ", ";
	};
	outfile << getTcoPgf(tcos.nodes[0]) << "};" << endl;
	outfile << "// IP pgUpdateRec.f --- IEND" << endl;

	// --- pgUpdateRec.exec (exact copy of writeTblCpp)
	outfile << "// IP pgUpdateRec.exec --- IBEGIN" << endl;
	outfile << "\tres = PQexecPrepared(dbs, \"" << tbl->sref << "_updateRec\", " << tcos.nodes.size() << ", vals, l, f, 0);" << endl;
	outfile << "// IP pgUpdateRec.exec --- IEND" << endl;
};

void WznmWrdbsTbl::writeQtbCpp_lite(
			fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
		) {
	WznmMTablecol* tco = NULL;
	string tcotype;

	// --- liteInitStatements.stmtInsertRec (exact copy of writeTblCpp)
	outfile << "// IP liteInitStatements.stmtInsertRec --- IBEGIN" << endl;
	outfile << "\tstmtInsertRec = createStatement(\"INSERT INTO " << tbl->sref << " (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref;
	};

	outfile << ") VALUES (";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		if (i != 1) outfile << ",";
		outfile << "?" << i;
	};

	outfile << ")\");" << endl;
	outfile << "// IP liteInitStatements.stmtInsertRec --- IEND" << endl;

	// --- liteInitStatements.stmtUpdateRec (exact copy of writeTblCpp)
	outfile << "// IP liteInitStatements.stmtUpdateRec --- IBEGIN" << endl;
	outfile << "\tstmtUpdateRec = createStatement(\"UPDATE " << tbl->sref << " SET ";

	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 1) outfile << ", ";
		outfile << tco->sref << " = ?" << i;
	};

	outfile << " WHERE " << tcos.nodes[0]->sref << " = ?" << tcos.nodes.size() << "\");" << endl;
	outfile << "// IP liteInitStatements.stmtUpdateRec --- IEND" << endl;

	// --- liteInitStatements.stmtLoadRecByQref
	outfile << "// IP liteInitStatements.stmtLoadRecByQref --- IBEGIN" << endl;
	outfile << "\tstmtLoadRecByQref = createStatement(\"SELECT ";
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << tco->sref;
	};
	outfile << " FROM " << tbl->sref << " WHERE qref = ?1\");" << endl;
	outfile << "// IP liteInitStatements.stmtLoadRecByQref --- IEND" << endl;

	// --- liteInitStatements.stmtLoadRstByJref
	outfile << "// IP liteInitStatements.stmtLoadRstByJref --- IBEGIN" << endl;
	outfile << "\tstmtLoadRstByJref = createStatement(\"SELECT ";
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << tco->sref;
	};
	outfile << " FROM " << tbl->sref << " WHERE jref = ?1 ORDER BY jnum ASC\");" << endl;
	outfile << "// IP liteInitStatements.stmtLoadRstByJref --- IEND" << endl;

	// --- liteLoadRec.assign (exact copy of writeTblCpp)
	outfile << "// IP liteLoadRec.assign --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\t_rec->" << tco->sref;
		if (tcotype == "tinyint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "utinyint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "smallint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "usmallint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "int") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "uint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "bigint") {
			outfile << " = sqlite3_column_int64(stmt, " << j << ");" << endl;
		} else if (tcotype == "ubigint") {
			outfile << " = sqlite3_column_int64(stmt, " << j << ");" << endl;
		} else if (tcotype == "string") {
			outfile << ".assign((const char*) sqlite3_column_text(stmt, " << j << "));" << endl;
		} else if (tcotype == "double") {
			outfile << " = sqlite3_column_double(stmt, " << j << ");" << endl;
		} else if (tcotype == "bool") {
			outfile << " = (sqlite3_column_int(stmt, " << j << ") != 0);" << endl;
		};
	};
	outfile << "// IP liteLoadRec.assign --- IEND" << endl;

	// --- liteLoadRst.assign (exact copy of writeTblCpp)
	outfile << "// IP liteLoadRst.assign --- IBEGIN" << endl;
	for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
		tco = tcos.nodes[j];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t\trec->" << tco->sref;
		if (tcotype == "tinyint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "utinyint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "smallint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "usmallint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "int") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "uint") {
			outfile << " = sqlite3_column_int(stmt, " << j << ");" << endl;
		} else if (tcotype == "bigint") {
			outfile << " = sqlite3_column_int64(stmt, " << j << ");" << endl;
		} else if (tcotype == "ubigint") {
			outfile << " = sqlite3_column_int64(stmt, " << j << ");" << endl;
		} else if (tcotype == "string") {
			outfile << ".assign((const char*) sqlite3_column_text(stmt, " << j << "));" << endl;
		} else if (tcotype == "double") {
			outfile << " = sqlite3_column_double(stmt, " << j << ");" << endl;
		} else if (tcotype == "bool") {
			outfile << " = (sqlite3_column_int(stmt, " << j << ") != 0);" << endl;
		};
	};
	outfile << "// IP liteLoadRst.assign --- IEND" << endl;

	// --- liteInsertRec.bind (exact copy of writeTblCpp)
	outfile << "// IP liteInsertRec.bind --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t" << getTcoLitebind(tco, "rec->", "stmtInsertRec", i) << ";" << endl;
	};
	outfile << "// IP liteInsertRec.bind --- IEND" << endl;

	// --- liteUpdateRec.bind (exact copy of writeTblCpp)
	outfile << "// IP liteUpdateRec.bind --- IBEGIN" << endl;
	for (unsigned int i=1;i<tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

		outfile << "\t" << getTcoLitebind(tco, "rec->", "stmtUpdateRec", i) << ";" << endl;
	};
	outfile << "\t" << getTcoLitebind(tcos.nodes[0], "rec->", "stmtUpdateRec", tcos.nodes.size()) << ";" << endl;
	outfile << "// IP liteUpdateRec.bind --- IEND" << endl;
};

string WznmWrdbsTbl::getTcoCppType(
			const uint ixVBasetype
			, const uint ixVSubtype
			, const bool ns
		) {
	string retval;

	if (ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
		retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
		retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
		retval = "uint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
		retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
		retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
		retval = "uint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
		retval = "usmallint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TINYINT) retval = "tinyint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UTINYINT) retval = "utinyint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::SMALLINT) retval = "smallint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::USMALLINT) retval = "usmallint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::INT) retval = "int";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UINT) retval = "uint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::BIGINT) retval = "bigint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UBIGINT) retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
		retval = "double";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
		retval = "bool";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = "double";
		else retval = "uint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
		retval = "string";
	};

	if (ns) {
		if (retval == "string") retval = "std::string";
		else if ((retval != "int") && (retval != "double") && (retval != "bool")) retval = "Sbecore::" + retval;
	};

	return retval;
};

string WznmWrdbsTbl::getTcoCppDefault(
			const uint ixVBasetype
			, const uint ixVSubtype
		) {
	string retval;

	if (ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
		retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
		retval = "\"\"";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
		retval = "\"\"";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
		retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
		retval = "\"\"";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
		retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
		retval = "\"\"";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
		retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
		retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
		retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
		retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
		retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
		retval = "0.0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
		retval = "false";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
		retval = "\"\"";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = "0.0";
		else retval = "0";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
		retval = "\"\"";
	};

	return retval;
};

string WznmWrdbsTbl::getTcoMybind(
			WznmMTablecol* tco
			, const string& recstr
			, const unsigned int i
		) {
	string s;

	string tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

	if (tcotype == "tinyint") {
		s = "bindTinyint(&" + recstr + tco->sref;
	} else if (tcotype == "utinyint") {
		s = "bindUtinyint(&" + recstr + tco->sref;
	} else if (tcotype == "smallint") {
		s = "bindSmallint(&" + recstr + tco->sref;
	} else if (tcotype == "usmallint") {
		s = "bindUsmallint(&" + recstr + tco->sref;
	} else if (tcotype == "int") {
		s = "bindInt(&" + recstr + tco->sref;
	} else if (tcotype == "uint") {
		s = "bindUint(&" + recstr + tco->sref;
	} else if (tcotype == "bigint") {
		s = "bindBigint(&" + recstr + tco->sref;
	} else if (tcotype == "ubigint") {
		s = "bindUbigint(&" + recstr + tco->sref;
	} else if (tcotype == "string") {
		s = "bindCstring((char*) (" + recstr + tco->sref + ".c_str())";
	} else if (tcotype == "double") {
		s = "bindDouble(&" + recstr + tco->sref;
	} else if (tcotype == "bool") {
		s = "bindTinyint(&" + tco->sref;
	};

	s += ",&(l[" + to_string(i) + "]),&(n[" + to_string(i) + "]),&(e[" + to_string(i) + "]))";

	return s;
};

void WznmWrdbsTbl::getTcoPgstrvec(
			fstream& outfile
			, WznmMTablecol* tco
			, const string& recstr
		) {
	string tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

	if (tcotype == "tinyint") {
		outfile << "\tsmallint _" << tco->sref << " = htons(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "utinyint") {
		outfile << "\tusmallint _" << tco->sref << " = htons(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "smallint") {
		outfile << "\tsmallint _" << tco->sref << " = htons(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "usmallint") {
		outfile << "\tusmallint _" << tco->sref << " = htons(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "int") {
		outfile << "\tint _" << tco->sref << " = htonl(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "uint") {
		outfile << "\tuint _" << tco->sref << " = htonl(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "bigint") {
		outfile << "\tbigint _" << tco->sref << " = htonl64(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "ubigint") {
		outfile << "\tubigint _" << tco->sref << " = htonl64(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "double") {
		outfile << "\tstring _" << tco->sref << " = to_string(" << recstr << tco->sref << ");" << endl;
	} else if (tcotype == "bool") {
		outfile << "\tsmallint _" << tco->sref << " = htons((smallint) " << recstr << tco->sref << ");" << endl;
	};
};

string WznmWrdbsTbl::getTcoPgvals(
			WznmMTablecol* tco
			, const string recstr
		) {
	string s;

	string tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

	if (tcotype == "string") {
		s = recstr + tco->sref + ".c_str()";
	} else if (tcotype == "double") {
		s = "_" + tco->sref + ".c_str()";
	} else {
		s = "(char*) &_" + tco->sref;
	};

	return s;
};

string WznmWrdbsTbl::getTcoPgl(
			WznmMTablecol* tco
		) {
	string retval;

	string tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

	if (tcotype == "tinyint") {
		retval = "sizeof(smallint)";
	} else if (tcotype == "utinyint") {
		retval = "sizeof(usmallint)";
	} else if (tcotype == "smallint") {
		retval = "sizeof(smallint)";
	} else if (tcotype == "usmallint") {
		retval = "sizeof(usmallint)";
	} else if (tcotype == "int") {
		retval = "sizeof(int)";
	} else if (tcotype == "uint") {
		retval = "sizeof(uint)";
	} else if (tcotype == "bigint") {
		retval = "sizeof(bigint)";
	} else if (tcotype == "ubigint") {
		retval = "sizeof(ubigint)";
	} else if (tcotype == "string") {
		retval = "0";
	} else if (tcotype == "double") {
		retval = "0";
	} else if (tcotype == "bool") {
		retval = "sizeof(smallint)";
	};

	return retval;
};

int WznmWrdbsTbl::getTcoPgf(
			WznmMTablecol* tco
		) {
	int retval = 1;

	string tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

	if ((tcotype == "string") || (tcotype == "double")) retval = 0;

	return retval;
};

string WznmWrdbsTbl::getTcoLitebind(
			WznmMTablecol* tco
			, const string& recstr
			, const string& stmt
			, const unsigned int i
		) {
	string s;

	string tcotype = getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false);

	if (tcotype == "string") {
		s = "sqlite3_bind_text(" + stmt + ", " + to_string(i) + ", " + recstr + tco->sref + ".c_str(), " + recstr + tco->sref + ".length(), SQLITE_STATIC)";
	} else if (tcotype == "double") {
		s = "sqlite3_bind_double(" + stmt + ", " + to_string(i) + ", " + recstr + tco->sref + ")";
	} else if (tcotype == "bigint") {
		s = "sqlite3_bind_int64(" + stmt + ", " + to_string(i) + ", "  + recstr + tco->sref + ")";
	} else if (tcotype == "ubigint") {
		s = "sqlite3_bind_int64(" + stmt + ", " + to_string(i) + ", " + recstr + tco->sref + ")";
	} else {
		s = "sqlite3_bind_int(" + stmt + ", " + to_string(i) + ", " + recstr + tco->sref + ")";
	};

	return s;
};

bool WznmWrdbsTbl::getLfc(
			const uint ixVLoadtype
		) {
	return ((ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::CONFIRM) || (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::COUNT)
			|| (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REF) || (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REFS)
			|| (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REC) || (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::RST)
			|| (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::STRING) || (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::UINT));
};

string WznmWrdbsTbl::getLfcRetType(
			const uint ixVLoadtype
			, const bool ns
		) {
	string retval;

	if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::CONFIRM) {
		retval = "bool";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::COUNT) {
		if (!ns) retval = "uint";
		else retval = "Sbecore::uint";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REF) {
		retval = "bool";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REFS) {
		if (!ns) retval = "ubigint";
		else retval = "Sbecore::ubigint";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REC) {
		retval = "bool";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::RST) {
		if (!ns) retval = "ubigint";
		else retval = "Sbecore::ubigint";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::STRING) {
		retval = "bool";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::UINT) {
		retval = "bool";
	};

	return retval;
};

bool WznmWrdbsTbl::getLfcAppend(
			const uint ixVLoadtype
		) {
	return ((ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REFS) || (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::RST));
};

string WznmWrdbsTbl::getLfcRes(
			const string& tblsref
			, const uint ixVLoadtype
			, const string& ldsref
			, const bool ns
		) {
	string retval;

	if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::CONFIRM) {
	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::COUNT) {

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REF) {
		if (!ns) retval = "ubigint& " + ldsref;
		else retval = "Sbecore::ubigint& " + ldsref;		

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REFS) {
		if (!ns) retval = "vector<ubigint>& " + ldsref + "s";
		else retval = "std::vector<Sbecore::ubigint>& " + ldsref + "s";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REC) {
		retval = tblsref.substr(3) + "** rec";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::RST) {
		retval = "List" + tblsref.substr(3) + "& rst";

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::STRING) {
		if (!ns) retval = "string& " + ldsref;
		else retval = "std::string& " + ldsref;

	} else if (ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::UINT) {
		if (!ns) retval = "uint& " + ldsref;
		else retval = "Sbecore::uint& " + ldsref;
	};

	return retval;
};

void WznmWrdbsTbl::getLfcSql(
			fstream& outfile
			, WznmAMTableLoadfct* lfc
			, const ListWznmMTablecol& tcos
			, const string& tblsref
			, const bool mystmt
			, const bool pgstmt
			, const bool litestmt
		) {
	WznmMTablecol* tco = NULL;

	vector<string> lbys;
	string lby;

	vector<string> ords;
	string ord;

	bool found;

	size_t ptr;
	string postfix;

	StrMod::stringToVector(lfc->lbySrefsWznmMTablecol, lbys);
	StrMod::stringToVector(lfc->ordSrefsWznmMTablecol, ords);

	outfile << "\"SELECT ";

	if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::CONFIRM) {
		outfile << tcos.nodes[0]->sref;

	} else if (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::COUNT) {
		outfile << "COUNT(" << tcos.nodes[0]->sref << ")";

	} else if ((lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REC) || (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::RST)) {
		for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
			tco = tcos.nodes[i];

			if (i != 0) outfile << ", ";
			outfile << tco->sref;
		};

	} else if ((lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REF) || (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::REFS) || (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::STRING)
				|| (lfc->ixVLoadtype == VecWznmVAMTableLoadfctLoadtype::UINT)) {
		outfile << lfc->ldSrefWznmMTablecol;
	};

	outfile << " FROM " << tblsref;

	if (lbys.size() > 0) {
		outfile << " WHERE ";
		
		for (unsigned int j = 0; j < lbys.size(); j++) {
			lby = lbys[j];
			ptr = lby.find('.');
			if (ptr != string::npos) {
				postfix = lby.substr(ptr+1);
				lby = lby.substr(0, ptr);
			} else postfix = "eq";

			if (j != 0) outfile << " AND ";

			if (postfix == "incl") outfile << "(";

			outfile << lby;

			if (postfix == "eq") outfile << " = ";
			else if (postfix == "gt") outfile << " > ";
			else if (postfix == "lt") outfile << " < ";
			else if (postfix == "geq") outfile << " >= ";
			else if (postfix == "leq") outfile << " <= ";
			else if (postfix == "incl") outfile << " & ";

			if (mystmt) {
				outfile << "?";

			} else if (pgstmt) {
				outfile << "$" << (j+1);

			} else if (litestmt) {
				outfile << "?" << (j+1);

			} else {
				// find lby in tcos to determine type
				found = false;
				for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
					tco = tcos.nodes[i];

					if (tco->sref == lby) {
						found = true;
						break;
					};
				};

				if (found) {
					if (getTcoCppType(tco->ixVBasetype, tco->ixVSubtype, false) == "string") {
						outfile << "'\" + " << lby << " + \"'";
					} else {
						outfile << "\" + to_string(" << lby << ") + \"";
					};
				};
			};

			if (postfix == "incl") outfile << ") <> 0";
		};
	};

	if (ords.size() > 0) {
		outfile << " ORDER BY ";

		for (unsigned int j = 0; j < ords.size(); j++) {
			ord = ords[j];
			ptr = ord.find('.');
			if (ptr != string::npos) {
				postfix = ord.substr(ptr+1);
				ord = ord.substr(0, ptr);
			} else postfix = "asc";

			if (j != 0) outfile << ", ";
			outfile << ord << " " << StrMod::uc(postfix);
		};
	};

	if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::FIRST) {
		if (pgstmt) outfile << " OFFSET 0 LIMIT 1";
		else outfile << " LIMIT 0,1";

	} else if (lfc->ixVLimtype == VecWznmVAMTableLoadfctLimtype::LIMOFS) {
		if (mystmt) {
			outfile << " LIMIT ?,?";
		} else if (pgstmt) {
			outfile << " OFFSET $" << (lbys.size()+1) << " LIMIT $" << (lbys.size()+2);
		} else if (litestmt) {
			outfile << " LIMIT ?,?";
		} else {
			outfile << " LIMIT \" + to_string(offset) + \",\" + to_string(limit) + \"";
		};
	};

	outfile << "\"";
};

WznmMTablecol* WznmWrdbsTbl::getLdTco(
			const string& ld
			, const ListWznmMTablecol& tcos
		) {
	WznmMTablecol* tco;

	bool found = false;

	for (unsigned int k = 0; k < tcos.nodes.size(); k++) {
		tco = tcos.nodes[k];

		if (tco->sref == ld) {
			found = true;
			break;
		};
	};

	if (!found) tco = NULL;

	return tco;
};

WznmMTablecol* WznmWrdbsTbl::getLbyTco(
			const string& lby
			, const ListWznmMTablecol& tcos
		) {
	WznmMTablecol* tco;

	bool found = false;

	for (unsigned int k = 0; k < tcos.nodes.size(); k++) {
		tco = tcos.nodes[k];

		if (tco->sref == lby) {
			found = true;
			break;
		};
	};

	if (!found) tco = NULL;

	return tco;
};

string WznmWrdbsTbl::getQcoCppType(
			const uint ixVBasetype
			, const bool ns
		) {
	string retval;

	if (ixVBasetype == VecWznmVMQuerycolBasetype::STUB) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::HSTUB) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::USTUB) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::STUBS) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::VSREF) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::VSREFS) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::VTIT) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::VTITS) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::YESNO) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMDATE) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMTIME) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMSTAMP) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMUSTAMP) retval = "string";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::QIDREF) retval = "ubigint";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::QWR) retval = "bool";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::QJREF) retval = "ubigint";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::QJENUM) retval = "uint";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::INTVAL) retval = "int";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::DBLVAL) retval = "double";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::BOOLVAL) retval = "bool";
	else if (ixVBasetype == VecWznmVMQuerycolBasetype::TXTVAL) retval = "string";

	if (ns && (retval != "")) {
		if (retval == "string") retval = "std::string";
		else if ((retval != "int") && (retval != "double") && (retval != "bool")) retval = "Sbecore::" + retval;
	};

	return retval;
};

string WznmWrdbsTbl::getQcoCppDefault(
			const string& qcotype
		) {
	// used in .h file only

	if (qcotype == "std::string") return("\"\"");
	if (qcotype == "bool") return("false");
	if (qcotype == "double") return("0.0");

	return("0");
};

string WznmWrdbsTbl::getQcoWrite(
			const string& qcotype
		) {
	// used in .cpp file only

	if (qcotype == "tinyint") return("writeInt");
	if (qcotype == "utinyint") return("writeUint");
	if (qcotype == "smallint") return("writeInt");
	if (qcotype == "usmallint") return("writeUint");
	if (qcotype == "int") return("writeInt");
	if (qcotype == "uint") return("writeUint");
	if (qcotype == "bigint") return("writeInt");
	if (qcotype == "ubigint") return("writeUbigint");
	if (qcotype == "string") return("writeString");
	if (qcotype == "double") return("writeDouble");
	if (qcotype == "bool") return("writeBool");

	return("");
};
// IP cust --- IEND


