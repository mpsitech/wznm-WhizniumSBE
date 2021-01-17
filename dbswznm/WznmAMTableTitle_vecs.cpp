/**
	* \file WznmAMTableTitle_vecs.cpp
	* database access for table TblWznmAMTableTitle (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMTableTitle::VecVType
 ******************************************************************************/

uint TblWznmAMTableTitle::VecVType::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "sngshort") return SNGSHORT;
	if (s == "sngfull") return SNGFULL;
	if (s == "plshort") return PLSHORT;
	if (s == "plfull") return PLFULL;

	return(0);
};

string TblWznmAMTableTitle::VecVType::getSref(
			const uint ix
		) {
	if (ix == SNGSHORT) return("sngshort");
	if (ix == SNGFULL) return("sngfull");
	if (ix == PLSHORT) return("plshort");
	if (ix == PLFULL) return("plfull");

	return("");
};

string TblWznmAMTableTitle::VecVType::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SNGSHORT) return("singular short form");
		if (ix == SNGFULL) return("singular full title");
		if (ix == PLSHORT) return("plural short form");
		if (ix == PLFULL) return("plural full title");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMTableTitle::VecVType::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
