/**
	* \file WznmMPanel_vecs.cpp
	* database access for table TblWznmMPanel (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMPanel::VecVBasetype
 ******************************************************************************/

uint TblWznmMPanel::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "headbar") return HEADBAR;
	if (s == "headline") return HEADLINE;
	if (s == "form") return FORM;
	if (s == "list") return LIST;
	if (s == "rec") return REC;
	if (s == "recform") return RECFORM;
	if (s == "reclist") return RECLIST;

	return(0);
};

string TblWznmMPanel::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == HEADBAR) return("headbar");
	if (ix == HEADLINE) return("headline");
	if (ix == FORM) return("form");
	if (ix == LIST) return("list");
	if (ix == REC) return("rec");
	if (ix == RECFORM) return("recform");
	if (ix == RECLIST) return("reclist");

	return("");
};

string TblWznmMPanel::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == HEADBAR) return("head bar");
		if (ix == HEADLINE) return("headling line");
		if (ix == FORM) return("form");
		if (ix == LIST) return("list");
		if (ix == REC) return("record");
		if (ix == RECFORM) return("form for record");
		if (ix == RECLIST) return("list for record");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMPanel::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMPanel::VecVRefTbl
 ******************************************************************************/

uint TblWznmMPanel::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "mdl") return MDL;
	if (s == "tbl") return TBL;
	if (s == "rel") return REL;
	if (s == "vec") return VEC;

	return(0);
};

string TblWznmMPanel::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == MDL) return("mdl");
	if (ix == TBL) return("tbl");
	if (ix == REL) return("rel");
	if (ix == VEC) return("vec");

	return("");
};

string TblWznmMPanel::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == MDL) return("module");
		if (ix == TBL) return("table");
		if (ix == REL) return("relation");
		if (ix == VEC) return("vector");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMPanel::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

