/**
	* \file WznmAMQueryClause_vecs.cpp
	* database access for table TblWznmAMQueryClause (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMQueryClause::VecVBasetype
 ******************************************************************************/

uint TblWznmAMQueryClause::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ix") return IX;
	if (s == "ref") return REF;
	if (s == "eqn") return EQN;
	if (s == "pre") return PRE;
	if (s == "vit") return VIT;
	if (s == "jref") return JREF;
	if (s == "lcl") return LCL;
	if (s == "lat") return LAT;

	return(0);
};

string TblWznmAMQueryClause::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == IX) return("ix");
	if (ix == REF) return("ref");
	if (ix == EQN) return("eqn");
	if (ix == PRE) return("pre");
	if (ix == VIT) return("vit");
	if (ix == JREF) return("jref");
	if (ix == LCL) return("lcl");
	if (ix == LAT) return("lat");

	return("");
};

string TblWznmAMQueryClause::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == IX) return("custom index");
		if (ix == REF) return("custom reference");
		if (ix == EQN) return("equation");
		if (ix == PRE) return("presetting");
		if (ix == VIT) return("vector item");
		if (ix == JREF) return("job reference");
		if (ix == LCL) return("locale");
		if (ix == LAT) return("list add type");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMQueryClause::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 8; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

