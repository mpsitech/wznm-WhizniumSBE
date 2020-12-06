/**
	* \file VecWznmVReqitmode.cpp
	* vector VecWznmVReqitmode (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "VecWznmVReqitmode.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWznmVReqitmode
 ******************************************************************************/

uint VecWznmVReqitmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "notify") return NOTIFY;
	if (s == "poll") return POLL;

	return(0);
};

string VecWznmVReqitmode::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == NOTIFY) return("notify");
	if (ix == POLL) return("poll");

	return("");
};
