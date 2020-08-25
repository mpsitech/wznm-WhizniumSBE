/**
	* \file WznmAMSubsetTitle_vecs.cpp
	* database access for table TblWznmAMSubsetTitle (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMSubsetTitle::VecVType
 ******************************************************************************/

uint TblWznmAMSubsetTitle::VecVType::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "sngshort") return SNGSHORT;
	if (s == "sngfull") return SNGFULL;
	if (s == "plfull") return PLFULL;

	return(0);
};

string TblWznmAMSubsetTitle::VecVType::getSref(
			const uint ix
		) {
	if (ix == SNGSHORT) return("sngshort");
	if (ix == SNGFULL) return("sngfull");
	if (ix == PLFULL) return("plfull");

	return("");
};

string TblWznmAMSubsetTitle::VecVType::getTitle(
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

void TblWznmAMSubsetTitle::VecVType::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

