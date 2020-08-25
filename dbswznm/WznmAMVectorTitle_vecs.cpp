/**
	* \file WznmAMVectorTitle_vecs.cpp
	* database access for table TblWznmAMVectorTitle (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMVectorTitle::VecVType
 ******************************************************************************/

uint TblWznmAMVectorTitle::VecVType::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "short") return SHORT;
	if (s == "full") return FULL;

	return(0);
};

string TblWznmAMVectorTitle::VecVType::getSref(
			const uint ix
		) {
	if (ix == SHORT) return("short");
	if (ix == FULL) return("full");

	return("");
};

string TblWznmAMVectorTitle::VecVType::getTitle(
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

void TblWznmAMVectorTitle::VecVType::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

