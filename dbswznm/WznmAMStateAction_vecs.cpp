/**
	* \file WznmAMStateAction_vecs.cpp
	* database access for table TblWznmAMStateAction (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMStateAction::VecVSection
 ******************************************************************************/

uint TblWznmAMStateAction::VecVSection::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ent") return ENT;
	if (s == "reent") return REENT;
	if (s == "lve") return LVE;

	return(0);
};

string TblWznmAMStateAction::VecVSection::getSref(
			const uint ix
		) {
	if (ix == ENT) return("ent");
	if (ix == REENT) return("reent");
	if (ix == LVE) return("lve");

	return("");
};

string TblWznmAMStateAction::VecVSection::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ENT) return("enter for the first time");
		if (ix == REENT) return("re-enter");
		if (ix == LVE) return("leave");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMStateAction::VecVSection::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmAMStateAction::VecVType
 ******************************************************************************/

uint TblWznmAMStateAction::VecVType::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "login") return LOGIN;
	if (s == "init") return INIT;
	if (s == "do") return DO;
	if (s == "step") return STEP;
	if (s == "csjstep") return CSJSTEP;
	if (s == "stepseq") return STEPSEQ;
	if (s == "subseq") return SUBSEQ;
	if (s == "retseq") return RETSEQ;
	if (s == "break") return BREAK;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmAMStateAction::VecVType::getSref(
			const uint ix
		) {
	if (ix == LOGIN) return("login");
	if (ix == INIT) return("init");
	if (ix == DO) return("do");
	if (ix == STEP) return("step");
	if (ix == CSJSTEP) return("csjstep");
	if (ix == STEPSEQ) return("stepseq");
	if (ix == SUBSEQ) return("subseq");
	if (ix == RETSEQ) return("retseq");
	if (ix == BREAK) return("break");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmAMStateAction::VecVType::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == LOGIN) return("start session");
		if (ix == INIT) return("initialize UI job");
		if (ix == DO) return("trigger UI action");
		if (ix == STEP) return("step to next state");
		if (ix == CSJSTEP) return("copy scr. job ref. then step to next state");
		if (ix == STEPSEQ) return("step to next sequence");
		if (ix == SUBSEQ) return("perform sub-sequence");
		if (ix == RETSEQ) return("return from sequence");
		if (ix == BREAK) return("interrupt state update loop");
		if (ix == CUST) return("custom code");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMStateAction::VecVType::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 10; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
