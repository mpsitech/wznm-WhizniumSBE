/**
	* \file WznmMCard_vecs.cpp
	* database access for table TblWznmMCard (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMCard::VecVRefTbl
 ******************************************************************************/

uint TblWznmMCard::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tbl") return TBL;
	if (s == "sbs") return SBS;

	return(0);
};

string TblWznmMCard::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBL) return("tbl");
	if (ix == SBS) return("sbs");

	return("");
};

string TblWznmMCard::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBL) return("table");
		if (ix == SBS) return("subset");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMCard::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

