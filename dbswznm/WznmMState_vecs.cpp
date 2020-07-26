/**
	* \file WznmMState_vecs.cpp
	* database access for table TblWznmMState (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMState::VecVAction
 ******************************************************************************/

uint TblWznmMState::VecVAction::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "login") return LOGIN;
	if (s == "init") return INIT;
	if (s == "do") return DO;
	if (s == "step") return STEP;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmMState::VecVAction::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == LOGIN) return("login");
	if (ix == INIT) return("init");
	if (ix == DO) return("do");
	if (ix == STEP) return("step");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmMState::VecVAction::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == LOGIN) return("start session");
		if (ix == INIT) return("initialize UI job");
		if (ix == DO) return("trigger UI action");
		if (ix == STEP) return("step to next state");
		if (ix == CUST) return("custom code");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMState::VecVAction::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

