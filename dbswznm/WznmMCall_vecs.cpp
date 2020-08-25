/**
	* \file WznmMCall_vecs.cpp
	* database access for table TblWznmMCall (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMCall::VecVBasetype
 ******************************************************************************/

uint TblWznmMCall::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "chk") return CHK;
	if (s == "evt") return EVT;
	if (s == "pstset") return PSTSET;
	if (s == "recupd") return RECUPD;
	if (s == "tblmod") return TBLMOD;
	if (s == "other") return OTHER;

	return(0);
};

string TblWznmMCall::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == CHK) return("chk");
	if (ix == EVT) return("evt");
	if (ix == PSTSET) return("pstset");
	if (ix == RECUPD) return("recupd");
	if (ix == TBLMOD) return("tblmod");
	if (ix == OTHER) return("other");

	return("");
};

string TblWznmMCall::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == CHK) return("record feature check");
		if (ix == EVT) return("other event");
		if (ix == PSTSET) return("presetting set request");
		if (ix == RECUPD) return("record update event");
		if (ix == TBLMOD) return("table modification event");
		if (ix == OTHER) return("other");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMCall::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMCall::VecVRefTbl
 ******************************************************************************/

uint TblWznmMCall::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "chk") return CHK;
	if (s == "tbl") return TBL;

	return(0);
};

string TblWznmMCall::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == CHK) return("chk");
	if (ix == TBL) return("tbl");

	return("");
};

string TblWznmMCall::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == CHK) return("check");
		if (ix == TBL) return("table");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMCall::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMCall::VecWSubset
 ******************************************************************************/

uint TblWznmMCall::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswznmbmcallcdc") ix |= SBSWZNMBMCALLCDC;
	};

	return(ix);
};

void TblWznmMCall::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWZNMBMCALLCDC); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMCall::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWZNMBMCALLCDC) ss.push_back("SbsWznmBMCallCdc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMCall::VecWSubset::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SBSWZNMBMCALLCDC) return("data change call");
		return(getSrefs(ix));
	};

	return("");
};

