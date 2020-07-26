/**
	* \file WznmAMTableLoadfct_vecs.cpp
	* database access for table TblWznmAMTableLoadfct (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMTableLoadfct::VecVLimtype
 ******************************************************************************/

uint TblWznmAMTableLoadfct::VecVLimtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "first") return FIRST;
	if (s == "limofs") return LIMOFS;

	return(0);
};

string TblWznmAMTableLoadfct::VecVLimtype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == FIRST) return("first");
	if (ix == LIMOFS) return("limofs");

	return("");
};

string TblWznmAMTableLoadfct::VecVLimtype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == FIRST) return("single record");
		if (ix == LIMOFS) return("limit/offset parameters");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMTableLoadfct::VecVLimtype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmAMTableLoadfct::VecVLoadtype
 ******************************************************************************/

uint TblWznmAMTableLoadfct::VecVLoadtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "confirm") return CONFIRM;
	if (s == "count") return COUNT;
	if (s == "ref") return REF;
	if (s == "refs") return REFS;
	if (s == "rec") return REC;
	if (s == "rst") return RST;
	if (s == "string") return STRING;
	if (s == "uint") return UINT;
	if (s == "hrefsup") return HREFSUP;
	if (s == "hrefsdown") return HREFSDOWN;
	if (s == "hrstup") return HRSTUP;
	if (s == "hrstdown") return HRSTDOWN;

	return(0);
};

string TblWznmAMTableLoadfct::VecVLoadtype::getSref(
			const uint ix
		) {
	if (ix == CONFIRM) return("confirm");
	if (ix == COUNT) return("count");
	if (ix == REF) return("ref");
	if (ix == REFS) return("refs");
	if (ix == REC) return("rec");
	if (ix == RST) return("rst");
	if (ix == STRING) return("string");
	if (ix == UINT) return("uint");
	if (ix == HREFSUP) return("hrefsup");
	if (ix == HREFSDOWN) return("hrefsdown");
	if (ix == HRSTUP) return("hrstup");
	if (ix == HRSTDOWN) return("hrstdown");

	return("");
};

string TblWznmAMTableLoadfct::VecVLoadtype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == CONFIRM) return("check presence");
		if (ix == COUNT) return("record count");
		if (ix == REF) return("single ref");
		if (ix == REFS) return("set of refs");
		if (ix == REC) return("single record");
		if (ix == RST) return("record set");
		if (ix == STRING) return("single string value");
		if (ix == UINT) return("single uint value");
		if (ix == HREFSUP) return("set of refs hier. up");
		if (ix == HREFSDOWN) return("set of refs hier. down");
		if (ix == HRSTUP) return("record set hier. up");
		if (ix == HRSTDOWN) return("record set hier. down");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMTableLoadfct::VecVLoadtype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 12; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

