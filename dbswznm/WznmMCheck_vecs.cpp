/**
	* \file WznmMCheck_vecs.cpp
	* database access for table TblWznmMCheck (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMCheck::VecVBasetype
 ******************************************************************************/

uint TblWznmMCheck::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "eq") return EQ;
	if (s == "incl") return INCL;
	if (s == "leaf") return LEAF;
	if (s == "sbs") return SBS;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmMCheck::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == EQ) return("eq");
	if (ix == INCL) return("incl");
	if (ix == LEAF) return("leaf");
	if (ix == SBS) return("sbs");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmMCheck::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == EQ) return("table column equals");
		if (ix == INCL) return("table column includes");
		if (ix == LEAF) return("leaf of hierarchical table");
		if (ix == SBS) return("part of subsets");
		if (ix == CUST) return("custom check");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMCheck::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
