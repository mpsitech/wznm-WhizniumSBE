/**
	* \file WznmMRtblock_vecs.cpp
	* database access for table TblWznmMRtblock (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMRtblock::VecVRefTbl
 ******************************************************************************/

uint TblWznmMRtblock::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "blk") return BLK;
	if (s == "fed") return FED;
	if (s == "tbl") return TBL;

	return(0);
};

string TblWznmMRtblock::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == BLK) return("blk");
	if (ix == FED) return("fed");
	if (ix == TBL) return("tbl");

	return("");
};

string TblWznmMRtblock::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == BLK) return("block");
		if (ix == FED) return("feed");
		if (ix == TBL) return("table");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMRtblock::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

