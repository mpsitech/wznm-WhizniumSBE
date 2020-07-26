/**
	* \file WznmAMTablecolTitle_vecs.cpp
	* database access for table TblWznmAMTablecolTitle (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMTablecolTitle::VecVType
 ******************************************************************************/

uint TblWznmAMTablecolTitle::VecVType::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "short") return SHORT;
	if (s == "full") return FULL;

	return(0);
};

string TblWznmAMTablecolTitle::VecVType::getSref(
			const uint ix
		) {
	if (ix == SHORT) return("short");
	if (ix == FULL) return("full");

	return("");
};

string TblWznmAMTablecolTitle::VecVType::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SHORT) return("short form");
		if (ix == FULL) return("full title");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMTablecolTitle::VecVType::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

