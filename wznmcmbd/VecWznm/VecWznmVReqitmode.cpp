/**
	* \file VecWznmVReqitmode.cpp
	* vector VecWznmVReqitmode (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
