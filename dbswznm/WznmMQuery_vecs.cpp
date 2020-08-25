/**
	* \file WznmMQuery_vecs.cpp
	* database access for table TblWznmMQuery (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMQuery::VecVBasetype
 ******************************************************************************/

uint TblWznmMQuery::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "std") return STD;
	if (s == "multbra") return MULTBRA;
	if (s == "list") return LIST;
	if (s == "oolist") return OOLIST;

	return(0);
};

string TblWznmMQuery::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == STD) return("std");
	if (ix == MULTBRA) return("multbra");
	if (ix == LIST) return("list");
	if (ix == OOLIST) return("oolist");

	return("");
};

string TblWznmMQuery::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == STD) return("standard");
		if (ix == MULTBRA) return("multi branch");
		if (ix == LIST) return("list");
		if (ix == OOLIST) return("operator ordered list");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMQuery::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMQuery::VecVSupSubrole
 ******************************************************************************/

uint TblWznmMQuery::VecVSupSubrole::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "opr") return OPR;
	if (s == "lref") return LREF;

	return(0);
};

string TblWznmMQuery::VecVSupSubrole::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == OPR) return("opr");
	if (ix == LREF) return("lref");

	return("");
};

string TblWznmMQuery::VecVSupSubrole::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == OPR) return("operator query");
		if (ix == LREF) return("list reference query");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMQuery::VecVSupSubrole::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

