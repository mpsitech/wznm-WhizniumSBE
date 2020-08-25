/**
	* \file WznmMTablecol_vecs.cpp
	* database access for table TblWznmMTablecol (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMTablecol::VecVAxisfct
 ******************************************************************************/

uint TblWznmMTablecol::VecVAxisfct::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "pt") return PT;
	if (s == "spt") return SPT;
	if (s == "ept") return EPT;

	return(0);
};

string TblWznmMTablecol::VecVAxisfct::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PT) return("pt");
	if (ix == SPT) return("spt");
	if (ix == EPT) return("ept");

	return("");
};

string TblWznmMTablecol::VecVAxisfct::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("not applicable");
		if (ix == PT) return("point");
		if (ix == SPT) return("starting point");
		if (ix == EPT) return("end point");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMTablecol::VecVAxisfct::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMTablecol::VecVBasetype
 ******************************************************************************/

uint TblWznmMTablecol::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idref") return IDREF;
	if (s == "idsref") return IDSREF;
	if (s == "klref") return KLREF;
	if (s == "tblref") return TBLREF;
	if (s == "tblsref") return TBLSREF;
	if (s == "vecref") return VECREF;
	if (s == "uvsref") return UVSREF;
	if (s == "grp") return GRP;
	if (s == "own") return OWN;
	if (s == "enum") return ENUM;
	if (s == "lvl") return LVL;
	if (s == "intval") return INTVAL;
	if (s == "dblval") return DBLVAL;
	if (s == "boolval") return BOOLVAL;
	if (s == "txtval") return TXTVAL;
	if (s == "timeval") return TIMEVAL;
	if (s == "expr") return EXPR;

	return(0);
};

string TblWznmMTablecol::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == IDREF) return("idref");
	if (ix == IDSREF) return("idsref");
	if (ix == KLREF) return("klref");
	if (ix == TBLREF) return("tblref");
	if (ix == TBLSREF) return("tblsref");
	if (ix == VECREF) return("vecref");
	if (ix == UVSREF) return("uvsref");
	if (ix == GRP) return("grp");
	if (ix == OWN) return("own");
	if (ix == ENUM) return("enum");
	if (ix == LVL) return("lvl");
	if (ix == INTVAL) return("intval");
	if (ix == DBLVAL) return("dblval");
	if (ix == BOOLVAL) return("boolval");
	if (ix == TXTVAL) return("txtval");
	if (ix == TIMEVAL) return("timeval");
	if (ix == EXPR) return("expr");

	return("");
};

string TblWznmMTablecol::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == IDREF) return("identifying reference");
		if (ix == IDSREF) return("identidying string reference");
		if (ix == KLREF) return("key list reference");
		if (ix == TBLREF) return("table reference");
		if (ix == TBLSREF) return("table string reference");
		if (ix == VECREF) return("vector reference");
		if (ix == UVSREF) return("universal vector string reference");
		if (ix == GRP) return("owning user group reference");
		if (ix == OWN) return("owner reference");
		if (ix == ENUM) return("enumerator");
		if (ix == LVL) return("level in hierarchy");
		if (ix == INTVAL) return("integer value");
		if (ix == DBLVAL) return("double value");
		if (ix == BOOLVAL) return("boolean value");
		if (ix == TXTVAL) return("text value");
		if (ix == TIMEVAL) return("time value");
		if (ix == EXPR) return("code expression");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMTablecol::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 17; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMTablecol::VecVFctTbl
 ******************************************************************************/

uint TblWznmMTablecol::VecVFctTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tbl") return TBL;
	if (s == "vec") return VEC;

	return(0);
};

string TblWznmMTablecol::VecVFctTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBL) return("tbl");
	if (ix == VEC) return("vec");

	return("");
};

string TblWznmMTablecol::VecVFctTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBL) return("table");
		if (ix == VEC) return("vector");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMTablecol::VecVFctTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMTablecol::VecVSubtype
 ******************************************************************************/

uint TblWznmMTablecol::VecVSubtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "klrefopt") return KLREFOPT;
	if (s == "klrefsng") return KLREFSNG;
	if (s == "klrefmult") return KLREFMULT;
	if (s == "trefspec") return TREFSPEC;
	if (s == "trefuniv") return TREFUNIV;
	if (s == "trefmin") return TREFMIN;
	if (s == "trefclu") return TREFCLU;
	if (s == "tsrefsng") return TSREFSNG;
	if (s == "tsrefmult") return TSREFMULT;
	if (s == "vreflin") return VREFLIN;
	if (s == "vrefand") return VREFAND;
	if (s == "enauto") return ENAUTO;
	if (s == "enspec") return ENSPEC;
	if (s == "tinyint") return TINYINT;
	if (s == "utinyint") return UTINYINT;
	if (s == "smallint") return SMALLINT;
	if (s == "usmallint") return USMALLINT;
	if (s == "int") return INT;
	if (s == "uint") return UINT;
	if (s == "bigint") return BIGINT;
	if (s == "ubigint") return UBIGINT;
	if (s == "txt5") return TXT5;
	if (s == "txt10") return TXT10;
	if (s == "txt30") return TXT30;
	if (s == "txt50") return TXT50;
	if (s == "txt100") return TXT100;
	if (s == "txt192") return TXT192;
	if (s == "txtlong") return TXTLONG;
	if (s == "txtbase64") return TXTBASE64;
	if (s == "tmdate") return TMDATE;
	if (s == "tmtime") return TMTIME;
	if (s == "tmstamp") return TMSTAMP;
	if (s == "tmustamp") return TMUSTAMP;

	return(0);
};

string TblWznmMTablecol::VecVSubtype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == KLREFOPT) return("klrefopt");
	if (ix == KLREFSNG) return("klrefsng");
	if (ix == KLREFMULT) return("klrefmult");
	if (ix == TREFSPEC) return("trefspec");
	if (ix == TREFUNIV) return("trefuniv");
	if (ix == TREFMIN) return("trefmin");
	if (ix == TREFCLU) return("trefclu");
	if (ix == TSREFSNG) return("tsrefsng");
	if (ix == TSREFMULT) return("tsrefmult");
	if (ix == VREFLIN) return("vreflin");
	if (ix == VREFAND) return("vrefand");
	if (ix == ENAUTO) return("enauto");
	if (ix == ENSPEC) return("enspec");
	if (ix == TINYINT) return("tinyint");
	if (ix == UTINYINT) return("utinyint");
	if (ix == SMALLINT) return("smallint");
	if (ix == USMALLINT) return("usmallint");
	if (ix == INT) return("int");
	if (ix == UINT) return("uint");
	if (ix == BIGINT) return("bigint");
	if (ix == UBIGINT) return("ubigint");
	if (ix == TXT5) return("txt5");
	if (ix == TXT10) return("txt10");
	if (ix == TXT30) return("txt30");
	if (ix == TXT50) return("txt50");
	if (ix == TXT100) return("txt100");
	if (ix == TXT192) return("txt192");
	if (ix == TXTLONG) return("txtlong");
	if (ix == TXTBASE64) return("txtbase64");
	if (ix == TMDATE) return("tmdate");
	if (ix == TMTIME) return("tmtime");
	if (ix == TMSTAMP) return("tmstamp");
	if (ix == TMUSTAMP) return("tmustamp");

	return("");
};

string TblWznmMTablecol::VecVSubtype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == KLREFOPT) return("optional");
		if (ix == KLREFSNG) return("single");
		if (ix == KLREFMULT) return("multi");
		if (ix == TREFSPEC) return("specific table");
		if (ix == TREFUNIV) return("universal table");
		if (ix == TREFMIN) return("minor reference");
		if (ix == TREFCLU) return("cluster table");
		if (ix == TSREFSNG) return("single");
		if (ix == TSREFMULT) return("multi");
		if (ix == VREFLIN) return("linear vector index");
		if (ix == VREFAND) return("AND mask for mc vector");
		if (ix == ENAUTO) return("automatic increment");
		if (ix == ENSPEC) return("specific numbering");
		if (ix == TINYINT) return("integer / byte (8bit)");
		if (ix == UTINYINT) return("unsigned integer / byte (8bit)");
		if (ix == SMALLINT) return("integer (16bit)");
		if (ix == USMALLINT) return("unsigned integer (16bit)");
		if (ix == INT) return("integer (32bit)");
		if (ix == UINT) return("unsigned integer (32bit)");
		if (ix == BIGINT) return("integer (64bit)");
		if (ix == UBIGINT) return("unsigned integer (64bit)");
		if (ix == TXT5) return("max. 5 characters");
		if (ix == TXT10) return("max. 10 characters");
		if (ix == TXT30) return("max. 30 characters");
		if (ix == TXT50) return("max. 50 characters");
		if (ix == TXT100) return("max. 100 characters");
		if (ix == TXT192) return("max. 192 characters");
		if (ix == TXTLONG) return("text field (unlimited)");
		if (ix == TXTBASE64) return("Base64 encoded binary (unlimited)");
		if (ix == TMDATE) return("date");
		if (ix == TMTIME) return("time");
		if (ix == TMSTAMP) return("time stamp");
		if (ix == TMUSTAMP) return("time stamp with usecs");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMTablecol::VecVSubtype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 34; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMTablecol::VecWSubset
 ******************************************************************************/

uint TblWznmMTablecol::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswznmbmtablecolstc") ix |= SBSWZNMBMTABLECOLSTC;
	};

	return(ix);
};

void TblWznmMTablecol::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWZNMBMTABLECOLSTC); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMTablecol::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWZNMBMTABLECOLSTC) ss.push_back("SbsWznmBMTablecolStc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMTablecol::VecWSubset::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SBSWZNMBMTABLECOLSTC) return("storage table column");
		return(getSrefs(ix));
	};

	return("");
};

