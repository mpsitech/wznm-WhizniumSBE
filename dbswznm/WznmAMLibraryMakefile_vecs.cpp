/**
	* \file WznmAMLibraryMakefile_vecs.cpp
	* database access for table TblWznmAMLibraryMakefile (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMLibraryMakefile::VecVRefTbl
 ******************************************************************************/

uint TblWznmAMLibraryMakefile::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "mch") return MCH;
	if (s == "mty") return MTY;

	return(0);
};

string TblWznmAMLibraryMakefile::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == MCH) return("mch");
	if (ix == MTY) return("mty");

	return("");
};

string TblWznmAMLibraryMakefile::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == MCH) return("machine");
		if (ix == MTY) return("machine type");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMLibraryMakefile::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

