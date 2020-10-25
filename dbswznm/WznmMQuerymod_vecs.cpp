/**
	* \file WznmMQuerymod_vecs.cpp
	* database access for table TblWznmMQuerymod (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMQuerymod::VecVBasetype
 ******************************************************************************/

uint TblWznmMQuerymod::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bra") return BRA;
	if (s == "exbra") return EXBRA;
	if (s == "filt") return FILT;
	if (s == "jovr") return JOVR;
	if (s == "stovr") return STOVR;

	return(0);
};

string TblWznmMQuerymod::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == BRA) return("bra");
	if (ix == EXBRA) return("exbra");
	if (ix == FILT) return("filt");
	if (ix == JOVR) return("jovr");
	if (ix == STOVR) return("stovr");

	return("");
};

string TblWznmMQuerymod::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == BRA) return("branch");
		if (ix == EXBRA) return("exclusive branch");
		if (ix == FILT) return("filter");
		if (ix == JOVR) return("jump table override");
		if (ix == STOVR) return("sub1n/submn table override");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMQuerymod::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMQuerymod::VecVRefTbl
 ******************************************************************************/

uint TblWznmMQuerymod::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tco") return TCO;
	if (s == "tbl") return TBL;

	return(0);
};

string TblWznmMQuerymod::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TCO) return("tco");
	if (ix == TBL) return("tbl");

	return("");
};

string TblWznmMQuerymod::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TCO) return("table column");
		if (ix == TBL) return("table");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMQuerymod::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

