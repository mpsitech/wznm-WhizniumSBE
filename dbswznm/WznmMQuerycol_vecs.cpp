/**
	* \file WznmMQuerycol_vecs.cpp
	* database access for table TblWznmMQuerycol (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMQuerycol::VecVBasetype
 ******************************************************************************/

uint TblWznmMQuerycol::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "tbl") return TBL;
	if (s == "stub") return STUB;
	if (s == "hstub") return HSTUB;
	if (s == "ustub") return USTUB;
	if (s == "stubs") return STUBS;
	if (s == "vsref") return VSREF;
	if (s == "vsrefs") return VSREFS;
	if (s == "vtit") return VTIT;
	if (s == "vtits") return VTITS;
	if (s == "yesno") return YESNO;
	if (s == "ftmdate") return FTMDATE;
	if (s == "ftmtime") return FTMTIME;
	if (s == "ftmstamp") return FTMSTAMP;
	if (s == "ftmustamp") return FTMUSTAMP;
	if (s == "qidref") return QIDREF;
	if (s == "qwr") return QWR;
	if (s == "qjref") return QJREF;
	if (s == "qjenum") return QJENUM;
	if (s == "intval") return INTVAL;
	if (s == "dblval") return DBLVAL;
	if (s == "boolval") return BOOLVAL;
	if (s == "txtval") return TXTVAL;

	return(0);
};

string TblWznmMQuerycol::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == TBL) return("tbl");
	if (ix == STUB) return("stub");
	if (ix == HSTUB) return("hstub");
	if (ix == USTUB) return("ustub");
	if (ix == STUBS) return("stubs");
	if (ix == VSREF) return("vsref");
	if (ix == VSREFS) return("vsrefs");
	if (ix == VTIT) return("vtit");
	if (ix == VTITS) return("vtits");
	if (ix == YESNO) return("yesno");
	if (ix == FTMDATE) return("ftmdate");
	if (ix == FTMTIME) return("ftmtime");
	if (ix == FTMSTAMP) return("ftmstamp");
	if (ix == FTMUSTAMP) return("ftmustamp");
	if (ix == QIDREF) return("qidref");
	if (ix == QWR) return("qwr");
	if (ix == QJREF) return("qjref");
	if (ix == QJENUM) return("qjenum");
	if (ix == INTVAL) return("intval");
	if (ix == DBLVAL) return("dblval");
	if (ix == BOOLVAL) return("boolval");
	if (ix == TXTVAL) return("txtval");

	return("");
};

string TblWznmMQuerycol::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == TBL) return("dual field in table");
		if (ix == STUB) return("stub to record");
		if (ix == HSTUB) return("hierarchical stub to record");
		if (ix == USTUB) return("universal stub to record");
		if (ix == STUBS) return("stub to multi records");
		if (ix == VSREF) return("string ref to vector entry");
		if (ix == VSREFS) return("string ref to multi vec entries");
		if (ix == VTIT) return("title to vector entry");
		if (ix == VTITS) return("titles to multi vector entries");
		if (ix == YESNO) return("yes/no of boolean");
		if (ix == FTMDATE) return("formatted date");
		if (ix == FTMTIME) return("formatted time");
		if (ix == FTMSTAMP) return("formatted time stamp");
		if (ix == FTMUSTAMP) return("formatted time stamp with usecs");
		if (ix == QIDREF) return("query table id ref");
		if (ix == QWR) return("write flag");
		if (ix == QJREF) return("job ref");
		if (ix == QJENUM) return("job enumerator");
		if (ix == INTVAL) return("integer value");
		if (ix == DBLVAL) return("double value");
		if (ix == BOOLVAL) return("boolean value");
		if (ix == TXTVAL) return("text value");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMQuerycol::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 22; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMQuerycol::VecWOccurrence
 ******************************************************************************/

uint TblWznmMQuerycol::VecWOccurrence::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "qtb") ix |= QTB;
		else if (ss[i] == "xml") ix |= XML;
		else if (ss[i] == "btb") ix |= BTB;
	};

	return(ix);
};

void TblWznmMQuerycol::VecWOccurrence::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*BTB); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMQuerycol::VecWOccurrence::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & QTB) ss.push_back("qtb");
	if (ix & XML) ss.push_back("xml");
	if (ix & BTB) ss.push_back("btb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMQuerycol::VecWOccurrence::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == QTB) return("query table");
		if (ix == XML) return("XML");
		if (ix == BTB) return("base table");
		return(getSrefs(ix));
	};

	return("");
};

void TblWznmMQuerycol::VecWOccurrence::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= BTB; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWznmVLocale));
};
