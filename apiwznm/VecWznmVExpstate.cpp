/**
	* \file VecWznmVExpstate.cpp
	* vector VecWznmVExpstate (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "VecWznmVExpstate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWznmVExpstate
 ******************************************************************************/

uint VecWznmVExpstate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detd") return DETD;
	if (s == "maxd") return MAXD;
	if (s == "mind") return MIND;
	if (s == "regd") return REGD;

	return(0);
};

string VecWznmVExpstate::getSref(
			const uint ix
		) {
	if (ix == DETD) return("detd");
	if (ix == MAXD) return("maxd");
	if (ix == MIND) return("mind");
	if (ix == REGD) return("regd");

	return("");
};

