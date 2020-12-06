/**
	* \file WznmAMRelationTitle_vecs.cpp
	* database access for table TblWznmAMRelationTitle (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMRelationTitle::VecVType
 ******************************************************************************/

uint TblWznmAMRelationTitle::VecVType::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fromsngshort") return FROMSNGSHORT;
	if (s == "fromsngfull") return FROMSNGFULL;
	if (s == "tosngshort") return TOSNGSHORT;
	if (s == "tosngfull") return TOSNGFULL;
	if (s == "fromplshort") return FROMPLSHORT;
	if (s == "fromplfull") return FROMPLFULL;
	if (s == "toplshort") return TOPLSHORT;
	if (s == "toplfull") return TOPLFULL;

	return(0);
};

string TblWznmAMRelationTitle::VecVType::getSref(
			const uint ix
		) {
	if (ix == FROMSNGSHORT) return("fromsngshort");
	if (ix == FROMSNGFULL) return("fromsngfull");
	if (ix == TOSNGSHORT) return("tosngshort");
	if (ix == TOSNGFULL) return("tosngfull");
	if (ix == FROMPLSHORT) return("fromplshort");
	if (ix == FROMPLFULL) return("fromplfull");
	if (ix == TOPLSHORT) return("toplshort");
	if (ix == TOPLFULL) return("toplfull");

	return("");
};

string TblWznmAMRelationTitle::VecVType::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == FROMSNGSHORT) return("from singular short form");
		if (ix == FROMSNGFULL) return("from singular full title");
		if (ix == TOSNGSHORT) return("to singular short form");
		if (ix == TOSNGFULL) return("to singular full title");
		if (ix == FROMPLSHORT) return("from plural short form");
		if (ix == FROMPLFULL) return("from plural full title");
		if (ix == TOPLSHORT) return("to plural short form");
		if (ix == TOPLFULL) return("to plural full title");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMRelationTitle::VecVType::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 8; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
