/**
	* \file WznmMSquawk_vecs.cpp
	* database access for table TblWznmMSquawk (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMSquawk::VecVRefTbl
 ******************************************************************************/

uint TblWznmMSquawk::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "opk") return OPK;
	if (s == "opx") return OPX;
	if (s == "sge") return SGE;

	return(0);
};

string TblWznmMSquawk::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == OPK) return("opk");
	if (ix == OPX) return("opx");
	if (ix == SGE) return("sge");

	return("");
};

string TblWznmMSquawk::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == OPK) return("operation pack");
		if (ix == OPX) return("operation");
		if (ix == SGE) return("stage");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMSquawk::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

