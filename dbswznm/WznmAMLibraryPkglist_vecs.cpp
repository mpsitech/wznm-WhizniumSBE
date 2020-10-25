/**
	* \file WznmAMLibraryPkglist_vecs.cpp
	* database access for table TblWznmAMLibraryPkglist (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMLibraryPkglist::VecVRefTbl
 ******************************************************************************/

uint TblWznmAMLibraryPkglist::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mch") return MCH;
	if (s == "mty") return MTY;

	return(0);
};

string TblWznmAMLibraryPkglist::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == MCH) return("mch");
	if (ix == MTY) return("mty");

	return("");
};

string TblWznmAMLibraryPkglist::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == MCH) return("machine");
		if (ix == MTY) return("machine type");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMLibraryPkglist::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

