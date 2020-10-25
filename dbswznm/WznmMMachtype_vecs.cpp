/**
	* \file WznmMMachtype_vecs.cpp
	* database access for table TblWznmMMachtype (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMMachtype::VecVArch
 ******************************************************************************/

uint TblWznmMMachtype::VecVArch::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "armv7") return ARMV7;
	if (s == "armv8") return ARMV8;
	if (s == "x86_64") return X86_64;

	return(0);
};

string TblWznmMMachtype::VecVArch::getSref(
			const uint ix
		) {
	if (ix == ARMV7) return("armv7");
	if (ix == ARMV8) return("armv8");
	if (ix == X86_64) return("x86_64");

	return("");
};

string TblWznmMMachtype::VecVArch::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ARMV7) return("ARM 32bit");
		if (ix == ARMV8) return("ARM 64bit");
		if (ix == X86_64) return("Intel x86 64bit");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMMachtype::VecVArch::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

