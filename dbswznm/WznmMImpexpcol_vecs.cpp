/**
	* \file WznmMImpexpcol_vecs.cpp
	* database access for table TblWznmMImpexpcol (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMImpexpcol::VecVBasetype
 ******************************************************************************/

uint TblWznmMImpexpcol::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "iop") return IOP;
	if (s == "idiref") return IDIREF;
	if (s == "iref") return IREF;
	if (s == "tbl") return TBL;
	if (s == "tsref") return TSREF;
	if (s == "thsref") return THSREF;
	if (s == "thint") return THINT;
	if (s == "vsref") return VSREF;
	if (s == "ftm") return FTM;
	if (s == "iarg") return IARG;

	return(0);
};

string TblWznmMImpexpcol::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == IOP) return("iop");
	if (ix == IDIREF) return("idiref");
	if (ix == IREF) return("iref");
	if (ix == TBL) return("tbl");
	if (ix == TSREF) return("tsref");
	if (ix == THSREF) return("thsref");
	if (ix == THINT) return("thint");
	if (ix == VSREF) return("vsref");
	if (ix == FTM) return("ftm");
	if (ix == IARG) return("iarg");

	return("");
};

string TblWznmMImpexpcol::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == IOP) return("import/export operation");
		if (ix == IDIREF) return("identifying integer reference");
		if (ix == IREF) return("int ref to import/export item");
		if (ix == TBL) return("dual field in table");
		if (ix == TSREF) return("string ref to table");
		if (ix == THSREF) return("hierarchical string ref to table");
		if (ix == THINT) return("textual hint for table ref");
		if (ix == VSREF) return("string ref to vector item");
		if (ix == FTM) return("formatted time stamp/date/time");
		if (ix == IARG) return("argument for custom import");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMImpexpcol::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 10; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMImpexpcol::VecVConvtype
 ******************************************************************************/

uint TblWznmMImpexpcol::VecVConvtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "previmp") return PREVIMP;
	if (s == "cust") return CUST;
	if (s == "custsql") return CUSTSQL;
	if (s == "rst") return RST;
	if (s == "imppp") return IMPPP;
	if (s == "custsqlpp") return CUSTSQLPP;
	if (s == "ixsref") return IXSREF;
	if (s == "incr") return INCR;
	if (s == "invftm") return INVFTM;
	if (s == "sup") return SUP;
	if (s == "sub") return SUB;
	if (s == "preset") return PRESET;

	return(0);
};

string TblWznmMImpexpcol::VecVConvtype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PREVIMP) return("previmp");
	if (ix == CUST) return("cust");
	if (ix == CUSTSQL) return("custsql");
	if (ix == RST) return("rst");
	if (ix == IMPPP) return("imppp");
	if (ix == CUSTSQLPP) return("custsqlpp");
	if (ix == IXSREF) return("ixsref");
	if (ix == INCR) return("incr");
	if (ix == INVFTM) return("invftm");
	if (ix == SUP) return("sup");
	if (ix == SUB) return("sub");
	if (ix == PRESET) return("preset");

	return("");
};

string TblWznmMImpexpcol::VecVConvtype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("not applicable");
		if (ix == PREVIMP) return("find in previous import");
		if (ix == CUST) return("custom");
		if (ix == CUSTSQL) return("custom SQL query");
		if (ix == RST) return("find in recordset");
		if (ix == IMPPP) return("previous import post-proc.");
		if (ix == CUSTSQLPP) return("custom SQL post-proc.");
		if (ix == IXSREF) return("vector item index vs. string ref");
		if (ix == INCR) return("increment");
		if (ix == INVFTM) return("invert formatted time");
		if (ix == SUP) return("reference to super imp./exp.");
		if (ix == SUB) return("first in sub imp./exp.");
		if (ix == PRESET) return("presetting");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMImpexpcol::VecVConvtype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 13; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMImpexpcol::VecWOccurrence
 ******************************************************************************/

uint TblWznmMImpexpcol::VecWOccurrence::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "fil") ix |= FIL;
		else if (ss[i] == "tbl") ix |= TBL;
	};

	return(ix);
};

void TblWznmMImpexpcol::VecWOccurrence::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TBL); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMImpexpcol::VecWOccurrence::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FIL) ss.push_back("fil");
	if (ix & TBL) ss.push_back("tbl");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMImpexpcol::VecWOccurrence::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == FIL) return("import/export file");
		if (ix == TBL) return("base table");
		return(getSrefs(ix));
	};

	return("");
};

void TblWznmMImpexpcol::VecWOccurrence::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= TBL; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWznmVLocale));
};
