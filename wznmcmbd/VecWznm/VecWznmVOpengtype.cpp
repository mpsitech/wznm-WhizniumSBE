/**
	* \file VecWznmVOpengtype.cpp
	* vector VecWznmVOpengtype (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWznmVOpengtype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWznmVOpengtype
 ******************************************************************************/

uint VecWznmVOpengtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "wznmopd1") return WZNMOPD1;
	if (s == "wznmopd2") return WZNMOPD2;

	return(0);
};

string VecWznmVOpengtype::getSref(
			const uint ix
		) {
	if (ix == WZNMOPD1) return("wznmopd1");
	if (ix == WZNMOPD2) return("wznmopd2");

	return("");
};

string VecWznmVOpengtype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == WZNMOPD1) return("wznmopd1 with WznmCompl/WznmComplvis/WznmGen/WznmPrcfile/WznmPrctree/WznmWrapi/WznmWrapp/WznmWrcsapi/WznmWrdbs/WznmWrjapi/WznmWrpyapi/WznmWrsrv/WznmWrswapi/WznmWrvis/WznmWrvue/WznmWrweb");
		if (ix == WZNMOPD2) return("wznmopd2 with WznmCtpGenjtr/WznmCtpGenui/WznmCtpWrsrv/WznmCtpWrstkit/WznmCtpWrweb");
		return(getSref(ix));
	};

	return("");
};

void VecWznmVOpengtype::appendToFeed(
			const uint ix
			, const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixWznmVLocale));
};

void VecWznmVOpengtype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
