/**
	* \file WznmAMBlockItem_vecs.cpp
	* database access for table TblWznmAMBlockItem (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMBlockItem::VecVBasetype
 ******************************************************************************/

uint TblWznmAMBlockItem::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "var") return VAR;
	if (s == "conpar") return CONPAR;
	if (s == "contit") return CONTIT;
	if (s == "feed") return FEED;
	if (s == "rst") return RST;
	if (s == "sub") return SUB;

	return(0);
};

string TblWznmAMBlockItem::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == VAR) return("var");
	if (ix == CONPAR) return("conpar");
	if (ix == CONTIT) return("contit");
	if (ix == FEED) return("feed");
	if (ix == RST) return("rst");
	if (ix == SUB) return("sub");

	return("");
};

string TblWznmAMBlockItem::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VAR) return("standard variable");
		if (ix == CONPAR) return("control parameter");
		if (ix == CONTIT) return("control title");
		if (ix == FEED) return("feed");
		if (ix == RST) return("record set of query table");
		if (ix == SUB) return("sub-block");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMBlockItem::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

