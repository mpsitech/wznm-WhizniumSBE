/**
	* \file WznmAMTableTitle_vecs.cpp
	* database access for table TblWznmAMTableTitle (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
	if (s == "plfull") return PLFULL;

	return(0);
};

string TblWznmAMTableTitle::VecVType::getSref(
			const uint ix
		) {
	if (ix == SNGSHORT) return("sngshort");
	if (ix == SNGFULL) return("sngfull");
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

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

