/**
	* \file WznmMPreset_vecs.cpp
	* database access for table TblWznmMPreset (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMPreset::VecVRefTbl
 ******************************************************************************/

uint TblWznmMPreset::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tbl") return TBL;
	if (s == "sbs") return SBS;
	if (s == "vec") return VEC;

	return(0);
};

string TblWznmMPreset::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBL) return("tbl");
	if (ix == SBS) return("sbs");
	if (ix == VEC) return("vec");

	return("");
};

string TblWznmMPreset::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBL) return("table");
		if (ix == SBS) return("subset");
		if (ix == VEC) return("vector");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMPreset::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMPreset::VecVScope
 ******************************************************************************/

uint TblWznmMPreset::VecVScope::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "sys") return SYS;
	if (s == "sess") return SESS;
	if (s == "car") return CAR;
	if (s == "pnlrec") return PNLREC;
	if (s == "pnl") return PNL;

	return(0);
};

string TblWznmMPreset::VecVScope::getSref(
			const uint ix
		) {
	if (ix == SYS) return("sys");
	if (ix == SESS) return("sess");
	if (ix == CAR) return("car");
	if (ix == PNLREC) return("pnlrec");
	if (ix == PNL) return("pnl");

	return("");
};

string TblWznmMPreset::VecVScope::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SYS) return("system");
		if (ix == SESS) return("session");
		if (ix == CAR) return("card");
		if (ix == PNLREC) return("record panel");
		if (ix == PNL) return("panel");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMPreset::VecVScope::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

