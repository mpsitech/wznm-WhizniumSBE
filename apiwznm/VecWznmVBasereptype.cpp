/**
	* \file VecWznmVBasereptype.cpp
	* vector VecWznmVBasereptype (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
