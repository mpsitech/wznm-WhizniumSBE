/**
	* \file WznmMVector_vecs.cpp
	* database access for table TblWznmMVector (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMVector::VecVBasetype
 ******************************************************************************/

uint TblWznmMVector::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "lin") return LIN;
	if (s == "or") return OR;
	if (s == "klst") return KLST;
	if (s == "vlst") return VLST;

	return(0);
};

string TblWznmMVector::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == LIN) return("lin");
	if (ix == OR) return("or");
	if (ix == KLST) return("klst");
	if (ix == VLST) return("vlst");

	return("");
};

string TblWznmMVector::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == LIN) return("linear");
		if (ix == OR) return("multiple-choice");
		if (ix == KLST) return("key list");
		if (ix == VLST) return("value list");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMVector::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMVector::VecVHkTbl
 ******************************************************************************/

uint TblWznmMVector::VecVHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "iex") return IEX;
	if (s == "ime") return IME;
	if (s == "job") return JOB;
	if (s == "tbl") return TBL;

	return(0);
};

string TblWznmMVector::VecVHkTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == IEX) return("iex");
	if (ix == IME) return("ime");
	if (ix == JOB) return("job");
	if (ix == TBL) return("tbl");

	return("");
};

string TblWznmMVector::VecVHkTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == IEX) return("import/export complex");
		if (ix == IME) return("import/export");
		if (ix == JOB) return("job");
		if (ix == TBL) return("table");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMVector::VecVHkTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMVector::VecWSubset
 ******************************************************************************/

uint TblWznmMVector::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswznmbmvectorkls") ix |= SBSWZNMBMVECTORKLS;
	};

	return(ix);
};

void TblWznmMVector::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWZNMBMVECTORKLS); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMVector::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWZNMBMVECTORKLS) ss.push_back("SbsWznmBMVectorKls");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMVector::VecWSubset::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SBSWZNMBMVECTORKLS) return("key list");
		return(getSrefs(ix));
	};

	return("");
};
