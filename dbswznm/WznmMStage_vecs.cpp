/**
	* \file WznmMStage_vecs.cpp
	* database access for table TblWznmMStage (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMStage::VecVBasetype
 ******************************************************************************/

uint TblWznmMStage::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "alr") return ALR;
	if (s == "err") return ERR;
	if (s == "immcb") return IMMCB;
	if (s == "opp") return OPP;
	if (s == "opiw") return OPIW;
	if (s == "oppiw") return OPPIW;
	if (s == "other") return OTHER;
	if (s == "othwc") return OTHWC;

	return(0);
};

string TblWznmMStage::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == ALR) return("alr");
	if (ix == ERR) return("err");
	if (ix == IMMCB) return("immcb");
	if (ix == OPP) return("opp");
	if (ix == OPIW) return("opiw");
	if (ix == OPPIW) return("oppiw");
	if (ix == OTHER) return("other");
	if (ix == OTHWC) return("othwc");

	return("");
};

string TblWznmMStage::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ALR) return("alert");
		if (ix == ERR) return("error");
		if (ix == IMMCB) return("immediate callback");
		if (ix == OPP) return("ops prepare");
		if (ix == OPIW) return("ops invoke and wait");
		if (ix == OPPIW) return("ops prepare, invoke and wait");
		if (ix == OTHER) return("other");
		if (ix == OTHWC) return("other with wakeup call");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMStage::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 8; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

