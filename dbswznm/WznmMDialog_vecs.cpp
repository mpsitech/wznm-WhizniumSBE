/**
	* \file WznmMDialog_vecs.cpp
	* database access for table TblWznmMDialog (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMDialog::VecVBasetype
 ******************************************************************************/

uint TblWznmMDialog::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "new") return NEW;
	if (s == "select") return SELECT;
	if (s == "filter") return FILTER;
	if (s == "mnrel") return MNREL;
	if (s == "mnnew") return MNNEW;
	if (s == "import") return IMPORT;
	if (s == "export") return EXPORT;
	if (s == "jump") return JUMP;
	if (s == "rights") return RIGHTS;
	if (s == "report") return REPORT;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmMDialog::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == NEW) return("new");
	if (ix == SELECT) return("select");
	if (ix == FILTER) return("filter");
	if (ix == MNREL) return("mnrel");
	if (ix == MNNEW) return("mnnew");
	if (ix == IMPORT) return("import");
	if (ix == EXPORT) return("export");
	if (ix == JUMP) return("jump");
	if (ix == RIGHTS) return("rights");
	if (ix == REPORT) return("report");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmMDialog::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == NEW) return("new record");
		if (ix == SELECT) return("record select");
		if (ix == FILTER) return("list filter configuration");
		if (ix == MNREL) return("m:n relation");
		if (ix == MNNEW) return("m:n attribute new");
		if (ix == IMPORT) return("data import");
		if (ix == EXPORT) return("data export");
		if (ix == JUMP) return("jump table edit");
		if (ix == RIGHTS) return("user rights");
		if (ix == REPORT) return("report generation");
		if (ix == CUST) return("custom");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMDialog::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 11; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMDialog::VecVRefTbl
 ******************************************************************************/

uint TblWznmMDialog::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tbl") return TBL;
	if (s == "rel") return REL;
	if (s == "iex") return IEX;

	return(0);
};

string TblWznmMDialog::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBL) return("tbl");
	if (ix == REL) return("rel");
	if (ix == IEX) return("iex");

	return("");
};

string TblWznmMDialog::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBL) return("table");
		if (ix == REL) return("relation");
		if (ix == IEX) return("import/export complex");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMDialog::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
