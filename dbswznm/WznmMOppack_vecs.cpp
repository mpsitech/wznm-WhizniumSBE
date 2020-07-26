/**
	* \file WznmMOppack_vecs.cpp
	* database access for table TblWznmMOppack (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMOppack::VecVBasetype
 ******************************************************************************/

uint TblWznmMOppack::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cust") return CUST;
	if (s == "stat") return STAT;

	return(0);
};

string TblWznmMOppack::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == CUST) return("cust");
	if (ix == STAT) return("stat");

	return("");
};

string TblWznmMOppack::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == CUST) return("customizable");
		if (ix == STAT) return("static");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMOppack::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

