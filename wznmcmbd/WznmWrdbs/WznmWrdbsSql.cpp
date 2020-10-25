/**
	* \file WznmWrdbsSql.cpp
	* Wznm operation processor - write database create SQL code (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrdbsSql.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrdbs;

/******************************************************************************
 namespace WznmWrdbsSql
 ******************************************************************************/

DpchRetWznm* WznmWrdbsSql::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrdbsSql* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ListWznmMTable tbls;
	ListWznmMTable qtbs;

	fstream litefile;
	fstream marfile;
	fstream myfile;
	fstream pgfile;

	string s;

	WznmMVersion* ver = NULL;
	dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver);

	// load non-query tables
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE ixVBasetype <> " + to_string(VecWznmVMTableBasetype::QRY) + " AND refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, tbls);

	// load query tables
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE ixVBasetype = " + to_string(VecWznmVMTableBasetype::QRY) + " AND refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, qtbs);

	// create files
	if ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE) != 0) {
		s = xchg->tmppath + "/" + folder + "/CreateDbs" + Prjshort + "Lite.sql.ip";
		litefile.open(s.c_str(), ios::out);
		writeSqlLite(dbswznm, litefile, tbls, qtbs);
		litefile.close();
	};

	if ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO)) != 0) {
		s = xchg->tmppath + "/" + folder + "/CreateDbs" + Prjshort + "Mar.sql.ip";
		marfile.open(s.c_str(), ios::out);
		writeSqlMy(dbswznm, marfile, tbls, qtbs,
					(ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO)) == (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO),
					(ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO)) == VecWznmWMVersionDbmstype::MARARIA, false);
		marfile.close();
	};

	if ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) != 0) {
		s = xchg->tmppath + "/" + folder + "/CreateDbs" + Prjshort + "My.sql.ip";
		myfile.open(s.c_str(), ios::out);
		writeSqlMy(dbswznm, myfile, tbls, qtbs,
					(ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) == (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM),
					(ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) == VecWznmWMVersionDbmstype::MYISAM, true);
		myfile.close();
	};

	if ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG) != 0) {
		s = xchg->tmppath + "/" + folder + "/CreateDbs" + Prjshort + "Pg.sql.ip";
		pgfile.open(s.c_str(), ios::out);
		writeSqlPg(dbswznm, pgfile, tbls, qtbs);
		pgfile.close();
	};

	delete ver;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrdbsSql::writeSqlMy(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ListWznmMTable& tbls
			, const ListWznmMTable& qtbs
			, const bool mix
			, const bool ariaIsam
			, const bool myNotMar
		) {
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	vector<string> ss;

	// --- sttsDrop
	outfile << "-- IP sttsDrop --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		outfile << "DROP TABLE IF EXISTS " << tbl->sref << ";" << endl;
	};
	outfile << "-- IP sttsDrop --- IEND" << endl;

	// --- qtbsDrop
	outfile << "-- IP qtbsDrop --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
		tbl = qtbs.nodes[i];

		outfile << "DROP TABLE IF EXISTS " << tbl->sref << ";" << endl;
	};
	outfile << "-- IP qtbsDrop --- IEND" << endl;

	// --- tblsCreate
	outfile << "-- IP tblsCreate --- IBEGIN" << endl;
	for (unsigned int i = 0; i < (tbls.nodes.size()+qtbs.nodes.size()); i++) {
		if (i < tbls.nodes.size()) {
			tbl = tbls.nodes[i];
		} else {
			tbl = qtbs.nodes[i-tbls.nodes.size()];
		};

		// CREATE TABLE
		dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tcos);

		outfile << "CREATE TABLE " << tbl->sref << "(";

		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			// col name
			if (j==0)
				outfile << endl << "\t";
			else
				outfile << "," << endl << "\t";
			outfile << tco->sref << " ";

			// col type
			outfile << getTcoSqlMyType(tco->ixVBasetype, tco->ixVSubtype);
		};

		// indices
		if (i < tbls.nodes.size()) {
			// non-qtb
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];

				if (getTcoIdx(tco)) {
					outfile << "," << endl << "\t";
					outfile << "INDEX (" << tco->sref << ")";
				};
			};
		} else {
			// only qjref and qjenum are indexed
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];

				if (StrMod::srefInSrefs(tco->srefsKOption, "idx")) {
					outfile << "," << endl << "\t";
					outfile << "INDEX (" << tco->sref << ")";
				};
			};
		};

		// uniqueness constraint
		if (tbl->unqSrefsWznmMTablecol.length() != 0) {
			outfile << "," << endl << "\t";
			outfile << "CONSTRAINT UNIQUE (";

			StrMod::stringToVector(tbl->unqSrefsWznmMTablecol, ss);
			for (unsigned int j = 0; j < ss.size(); j++) {
				if (j != 0) outfile << ", ";
				outfile << ss[j];
			};

			outfile << ")";
		};

		// close CREATE TABLE (set storage engine according to table type)
		outfile << endl << ")";
		if (ariaIsam || (mix && (tbl->ixVBasetype == VecWznmVMTableBasetype::QRY))) {
			if (myNotMar) outfile << " ENGINE = MYISAM;" << endl;
			else outfile << " ENGINE = ARIA;" << endl;
		} else {
			outfile << " ENGINE = INNODB;" << endl;
		};
		outfile << endl;
	};
	outfile << "-- IP tblsCreate --- IEND" << endl;
};

void WznmWrdbsSql::writeSqlPg(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ListWznmMTable& tbls
			, const ListWznmMTable& qtbs
		) {
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	vector<string> ss;

	// --- sttsDrop
	outfile << "-- IP sttsDrop --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST)
			outfile << "DROP SEQUENCE IF EXISTS " << tbl->sref << ";" << endl;
		else
			outfile << "DROP TABLE IF EXISTS " << tbl->sref << ";" << endl;
	};
	outfile << "-- IP sttsDrop --- IEND" << endl;

	// --- qtbsDrop
	outfile << "-- IP qtbsDrop --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
		tbl = qtbs.nodes[i];

		if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST)
			outfile << "DROP SEQUENCE IF EXISTS " << tbl->sref << ";" << endl;
		else
			outfile << "DROP TABLE IF EXISTS " << tbl->sref << ";" << endl;
	};
	outfile << "-- IP qtbsDrop --- IEND" << endl;

	// --- tblsCreate
	outfile << "-- IP tblsCreate --- IBEGIN" << endl;
	for (unsigned int i = 0; i < (tbls.nodes.size()+qtbs.nodes.size()); i++) {
		if (i < tbls.nodes.size()) {
			tbl = tbls.nodes[i];
		} else {
			tbl = qtbs.nodes[i-tbls.nodes.size()];
		};

		// CREATE TABLE
		dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tcos);

		if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST)
			outfile << "CREATE SEQUENCE " << tbl->sref << " INCREMENT 1 MINVALUE 1 START 1 CACHE 1;" << endl;
		else
			outfile << "CREATE TABLE " << tbl->sref << "(";

		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			if (tbl->ixVBasetype != VecWznmVMTableBasetype::CLUST) {
				// col name
				if (j==0)
					outfile << endl << "\t";
				else
					outfile << "," << endl << "\t";
				outfile << tco->sref << " ";

				// col type
				outfile << getTcoSqlPgType(tco->ixVBasetype, tco->ixVSubtype);
			};
		};

		// uniqueness constraint
		if (tbl->unqSrefsWznmMTablecol.length() != 0) {
			outfile << "," << endl << "\t";
			outfile << "UNIQUE (";

			StrMod::stringToVector(tbl->unqSrefsWznmMTablecol, ss);
			for (unsigned int j = 0; j < ss.size(); j++) {
				if (j != 0) outfile << ", ";
				outfile << ss[j];
			};

			outfile << ")";
		};

		// close CREATE TABLE
		if (tbl->ixVBasetype != VecWznmVMTableBasetype::CLUST) outfile << endl << ");" << endl;

		// owner
		outfile << "ALTER TABLE " << tbl->sref << " OWNER TO epsi;" << endl;

		if (tbl->ixVBasetype != VecWznmVMTableBasetype::CLUST) {
			// indices
			if (i < tbls.nodes.size()) {
				// non-qtb
				for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
					tco = tcos.nodes[j];

					if (getTcoIdx(tco)) {
						outfile << "CREATE INDEX " << tbl->sref << "_" << tco->sref << " ON " << tbl->sref << " (" << tco->sref << ");" << endl;
					};
				};
			} else {
				// only qjref and qjenum are indexed
				for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
					tco = tcos.nodes[j];

					if (StrMod::srefInSrefs(tco->srefsKOption, "idx")) {
						outfile << "CREATE INDEX " << tbl->sref << "_" << tco->sref << " ON " << tbl->sref << " (" << tco->sref << ");" << endl;
					};
				};
			};
		};

		outfile << endl;
	};
	outfile << "-- IP tblsCreate --- IEND" << endl;
};

void WznmWrdbsSql::writeSqlLite(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ListWznmMTable& tbls
			, const ListWznmMTable& qtbs
		) {
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	vector<string> ss;

	// --- sttsDrop
	outfile << "-- IP sttsDrop --- IBEGIN" << endl;
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		outfile << "DROP TABLE IF EXISTS " << tbl->sref << ";" << endl;
	};
	outfile << "-- IP sttsDrop --- IEND" << endl;

	// --- qtbsDrop
	outfile << "-- IP qtbsDrop --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
		tbl = qtbs.nodes[i];

		outfile << "DROP TABLE IF EXISTS " << tbl->sref << ";" << endl;
	};
	outfile << "-- IP qtbsDrop --- IEND" << endl;

	// --- tblsCreate
	outfile << "-- IP tblsCreate --- IBEGIN" << endl;
	for (unsigned int i = 0; i < (tbls.nodes.size()+qtbs.nodes.size()); i++) {
		if (i < tbls.nodes.size()) {
			tbl = tbls.nodes[i];
		} else {
			tbl = qtbs.nodes[i-tbls.nodes.size()];
		};

		// CREATE TABLE
		dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tcos);

		outfile << "CREATE TABLE " << tbl->sref << "(";

		for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
			tco = tcos.nodes[j];

			// col name
			if (j==0)
				outfile << endl << "\t";
			else
				outfile << "," << endl << "\t";
			outfile << tco->sref << " ";

			// col type
			outfile << getTcoSqlLiteType(tco->ixVBasetype, tco->ixVSubtype);
		};

		// void column for cluster tables
		if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST) {
			outfile << "," << endl << "\tvoid SMALLINT" << endl;
		};

		// uniqueness constraint
		if (tbl->unqSrefsWznmMTablecol.length() != 0) {
			outfile << "," << endl << "\t";
			outfile << "UNIQUE (";

			StrMod::stringToVector(tbl->unqSrefsWznmMTablecol, ss);
			for (unsigned int j = 0; j < ss.size(); j++) {
				if (j != 0) outfile << ", ";
				outfile << ss[j];
			};

			outfile << ")";
		};

		// close CREATE TABLE
		outfile << endl << ");" << endl;

		// indices
		if (i < tbls.nodes.size()) {
			// non-qtb
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];

				if (getTcoIdx(tco)) {
					outfile << "CREATE INDEX " << tbl->sref << "_" << tco->sref << " ON " << tbl->sref << " (" << tco->sref << ");" << endl;
				};
			};
		} else {
			// only qjref and qjenum are indexed
			for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
				tco = tcos.nodes[j];

				if (StrMod::srefInSrefs(tco->srefsKOption, "idx")) {
					outfile << "CREATE INDEX " << tbl->sref << "_" << tco->sref << " ON " << tbl->sref << " (" << tco->sref << ");" << endl;
				};
			};
		};

		outfile << endl;
	};
	outfile << "-- IP tblsCreate --- IEND" << endl;
};

bool WznmWrdbsSql::getTcoIdx(
			WznmMTablecol* tco
		) {
	bool retval = false;

	if (StrMod::srefInSrefs(tco->srefsKOption, "idx")) {
		retval = true;
	
	} else {
		if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
			retval = true;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) retval = true;
			else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) retval = true;
			else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) retval = true;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
			retval = true;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
			retval = true;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
			retval = true;

		} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
			retval = true;
		};
	};

	return retval;
};

string WznmWrdbsSql::getTcoSqlMyType(
			const uint ixVBasetype
			, const uint ixVSubtype
		) {
	string retval;

	if (ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
		retval = "BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
		retval = "VARCHAR(50)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) retval = "VARCHAR(192)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) retval = "BIGINT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) retval = "BIGINT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) retval = "BIGINT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) retval = "BIGINT UNSIGNED";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) retval = "VARCHAR(192)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) retval = "INT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) retval = "INT UNSIGNED";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
		retval = "VARCHAR(50)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
		retval = "BIGINT UNSIGNED";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
		retval = "BIGINT UNSIGNED";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
		retval = "INT UNSIGNED";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
		retval = "SMALLINT UNSIGNED";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TINYINT) retval = "TINYINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UTINYINT) retval = "TINYINT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::SMALLINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::USMALLINT) retval = "SMALLINT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::INT) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UINT) retval = "INT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::BIGINT) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UBIGINT) retval = "BIGINT UNSIGNED";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
		retval = "DOUBLE";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
		retval = "TINYINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TXT5) retval = "VARCHAR(5)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT10) retval = "VARCHAR(10)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT30) retval = "VARCHAR(30)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT50) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT100) retval = "VARCHAR(100)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT192) retval = "VARCHAR(192)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXTLONG) retval = "TEXT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXTBASE64) retval = "TEXT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) retval = "INT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) retval = "INT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) retval = "INT UNSIGNED";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = "DOUBLE";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
		retval = "VARCHAR(1024)";
	};

	return retval;
};

string WznmWrdbsSql::getTcoSqlPgType(
			const uint ixVBasetype
			, const uint ixVSubtype
		) {
	string retval;

	if (ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
		retval = "BIGSERIAL PRIMARY KEY";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
		retval = "VARCHAR(50)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) retval = "VARCHAR(192)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) retval = "BIGINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) retval = "VARCHAR(192)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) retval = "INT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
		retval = "VARCHAR(50)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
		retval = "BIGINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
		retval = "BIGINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
		retval = "INT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
		retval = "SMALLINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TINYINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UTINYINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::SMALLINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::USMALLINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::INT) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UINT) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::BIGINT) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UBIGINT) retval = "BIGINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
		retval = "DOUBLE PRECISION";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
		retval = "SMALLINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TXT5) retval = "VARCHAR(5)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT10) retval = "VARCHAR(10)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT30) retval = "VARCHAR(30)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT50) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT100) retval = "VARCHAR(100)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT192) retval = "VARCHAR(192)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXTLONG) retval = "TEXT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXTBASE64) retval = "TEXT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = "DOUBLE PRECISION";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
		retval = "VARCHAR(1024)";
	};

	return retval;
};

string WznmWrdbsSql::getTcoSqlLiteType(
			const uint ixVBasetype
			, const uint ixVSubtype
		) {
	string retval;

	if (ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
		retval = "INTEGER PRIMARY KEY AUTOINCREMENT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
		retval = "VARCHAR(50)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) retval = "VARCHAR(192)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) retval = "BIGINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) retval = "VARCHAR(192)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) retval = "INT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
		retval = "VARCHAR(50)";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
		retval = "BIGINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
		retval = "BIGINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
		retval = "INT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
		retval = "SMALLINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TINYINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UTINYINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::SMALLINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::USMALLINT) retval = "SMALLINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::INT) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UINT) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::BIGINT) retval = "BIGINT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UBIGINT) retval = "BIGINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
		retval = "DOUBLE PRECISION";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
		retval = "SMALLINT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TXT5) retval = "VARCHAR(5)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT10) retval = "VARCHAR(10)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT30) retval = "VARCHAR(30)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT50) retval = "VARCHAR(50)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT100) retval = "VARCHAR(100)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXT192) retval = "VARCHAR(192)";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXTLONG) retval = "TEXT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TXTBASE64) retval = "TEXT";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) retval = "INT";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = "DOUBLE PRECISION";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
		retval = "VARCHAR(1024)";
	};

	return retval;
};
// IP cust --- IEND


