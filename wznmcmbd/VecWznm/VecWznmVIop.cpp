/**
	* \file VecWznmVIop.cpp
	* vector VecWznmVIop (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWznmVIop.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWznmVIop
 ******************************************************************************/

uint VecWznmVIop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "retr") return RETR;
	if (s == "retrins") return RETRINS;
	if (s == "retrupd") return RETRUPD;
	if (s == "retrupdins") return RETRUPDINS;
	if (s == "rmv") return RMV;

	return(0);
};

string VecWznmVIop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RETR) return("retr");
	if (ix == RETRINS) return("retrins");
	if (ix == RETRUPD) return("retrupd");
	if (ix == RETRUPDINS) return("retrupdins");
	if (ix == RMV) return("rmv");

	return("");
};

string VecWznmVIop::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == INS) return("insert");
		if (ix == RETR) return("retrieve");
		if (ix == RETRINS) return("retrieve, else insert");
		if (ix == RETRUPD) return("retrieve and update");
		if (ix == RETRUPDINS) return("retrieve and update, else insert");
		if (ix == RMV) return("remove");
		return(getSref(ix));
	};

	return("");
};

void VecWznmVIop::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};



