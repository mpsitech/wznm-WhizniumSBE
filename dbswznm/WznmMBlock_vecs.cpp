/**
	* \file WznmMBlock_vecs.cpp
	* database access for table TblWznmMBlock (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMBlock::VecVBasetype
 ******************************************************************************/

uint TblWznmMBlock::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cont") return CONT;
	if (s == "dpch") return DPCH;
	if (s == "stat") return STAT;
	if (s == "stg") return STG;
	if (s == "tag") return TAG;

	return(0);
};

string TblWznmMBlock::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == CONT) return("cont");
	if (ix == DPCH) return("dpch");
	if (ix == STAT) return("stat");
	if (ix == STG) return("stg");
	if (ix == TAG) return("tag");

	return("");
};

string TblWznmMBlock::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == CONT) return("form content");
		if (ix == DPCH) return("dispatch");
		if (ix == STAT) return("state list");
		if (ix == STG) return("setting list");
		if (ix == TAG) return("tag list");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMBlock::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMBlock::VecVRefTbl
 ******************************************************************************/

uint TblWznmMBlock::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "job") return JOB;
	if (s == "opx") return OPX;
	if (s == "opk") return OPK;

	return(0);
};

string TblWznmMBlock::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == JOB) return("job");
	if (ix == OPX) return("opx");
	if (ix == OPK) return("opk");

	return("");
};

string TblWznmMBlock::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == JOB) return("job");
		if (ix == OPX) return("operation");
		if (ix == OPK) return("operation pack");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMBlock::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

