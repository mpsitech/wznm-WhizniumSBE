/**
	* \file WznmMStub_vecs.cpp
	* database access for table TblWznmMStub (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMStub::VecVBasetype
 ******************************************************************************/

uint TblWznmMStub::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "tco") return TCO;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmMStub::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == TCO) return("tco");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmMStub::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == TCO) return("single table column");
		if (ix == CUST) return("custom implementation");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMStub::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
