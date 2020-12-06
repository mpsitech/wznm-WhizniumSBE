/**
	* \file WznmMFeed_vecs.cpp
	* database access for table TblWznmMFeed (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
