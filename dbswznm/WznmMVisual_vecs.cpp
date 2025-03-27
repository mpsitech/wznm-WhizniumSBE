/**
	* \file WznmMVisual_vecs.cpp
	* database access for table TblWznmMVisual (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMVisual::VecVBasetype
 ******************************************************************************/

uint TblWznmMVisual::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dbstr") return DBSTR;
	if (s == "impexp") return IMPEXP;

	return(0);
};

string TblWznmMVisual::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == DBSTR) return("dbstr");
	if (ix == IMPEXP) return("impexp");

	return("");
};

string TblWznmMVisual::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == DBSTR) return("database structure");
		if (ix == IMPEXP) return("import/export structure");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMVisual::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
