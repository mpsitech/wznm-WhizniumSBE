/**
	* \file WznmMFile_vecs.cpp
	* database access for table TblWznmMFile (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMFile::VecVRefTbl
 ******************************************************************************/

uint TblWznmMFile::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "app") return APP;
	if (s == "lib") return LIB;
	if (s == "ver") return VER;

	return(0);
};

string TblWznmMFile::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == APP) return("app");
	if (ix == LIB) return("lib");
	if (ix == VER) return("ver");

	return("");
};

string TblWznmMFile::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == APP) return("accessor app");
		if (ix == LIB) return("library");
		if (ix == VER) return("version");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMFile::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

