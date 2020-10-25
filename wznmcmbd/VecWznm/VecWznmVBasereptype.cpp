/**
	* \file VecWznmVBasereptype.cpp
	* vector VecWznmVBasereptype (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "VecWznmVBasereptype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWznmVBasereptype
 ******************************************************************************/

uint VecWznmVBasereptype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "prjgit") return PRJGIT;
	if (s == "custgit") return CUSTGIT;
	if (s == "uld") return ULD;

	return(0);
};

string VecWznmVBasereptype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PRJGIT) return("prjgit");
	if (ix == CUSTGIT) return("custgit");
	if (ix == ULD) return("uld");

	return("");
};

string VecWznmVBasereptype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("empty");
		if (ix == PRJGIT) return("project Git");
		if (ix == CUSTGIT) return("custom Git");
		if (ix == ULD) return("upload");
		return(getSref(ix));
	};

	return("");
};

void VecWznmVBasereptype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

