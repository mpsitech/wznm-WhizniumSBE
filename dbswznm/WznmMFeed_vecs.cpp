/**
	* \file WznmMFeed_vecs.cpp
	* database access for table TblWznmMFeed (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMFeed::VecVSrcTbl
 ******************************************************************************/

uint TblWznmMFeed::VecVSrcTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "vec") return VEC;
	if (s == "tbl") return TBL;

	return(0);
};

string TblWznmMFeed::VecVSrcTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == VEC) return("vec");
	if (ix == TBL) return("tbl");

	return("");
};

string TblWznmMFeed::VecVSrcTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == VEC) return("vector");
		if (ix == TBL) return("table");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMFeed::VecVSrcTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
