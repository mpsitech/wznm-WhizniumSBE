/**
	* \file WznmMSensitivity_vecs.cpp
	* database access for table TblWznmMSensitivity (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMSensitivity::VecVAction
 ******************************************************************************/

uint TblWznmMSensitivity::VecVAction::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "chgsge") return CHGSGE;
	if (s == "chgsgesnx") return CHGSGESNX;
	if (s == "chgsgefnx") return CHGSGEFNX;
	if (s == "updmon") return UPDMON;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmMSensitivity::VecVAction::getSref(
			const uint ix
		) {
	if (ix == CHGSGE) return("chgsge");
	if (ix == CHGSGESNX) return("chgsgesnx");
	if (ix == CHGSGEFNX) return("chgsgefnx");
	if (ix == UPDMON) return("updmon");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmMSensitivity::VecVAction::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == CHGSGE) return("change stage");
		if (ix == CHGSGESNX) return("change to on-success next stage");
		if (ix == CHGSGEFNX) return("change to on-failure next stage");
		if (ix == UPDMON) return("update monitor");
		if (ix == CUST) return("custom");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMSensitivity::VecVAction::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMSensitivity::VecVBasetype
 ******************************************************************************/

uint TblWznmMSensitivity::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cal") return CAL;
	if (s == "con") return CON;
	if (s == "uld") return ULD;
	if (s == "dld") return DLD;
	if (s == "tmr") return TMR;

	return(0);
};

string TblWznmMSensitivity::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == CAL) return("cal");
	if (ix == CON) return("con");
	if (ix == ULD) return("uld");
	if (ix == DLD) return("dld");
	if (ix == TMR) return("tmr");

	return("");
};

string TblWznmMSensitivity::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == CAL) return("on call");
		if (ix == CON) return("on control action");
		if (ix == ULD) return("on file upload");
		if (ix == DLD) return("on file download");
		if (ix == TMR) return("on timer");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMSensitivity::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMSensitivity::VecVJactype
 ******************************************************************************/

uint TblWznmMSensitivity::VecVJactype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "lock") return LOCK;
	if (s == "try") return TRY;
	if (s == "weak") return WEAK;

	return(0);
};

string TblWznmMSensitivity::VecVJactype::getSref(
			const uint ix
		) {
	if (ix == LOCK) return("lock");
	if (ix == TRY) return("try");
	if (ix == WEAK) return("weak");

	return("");
};

string TblWznmMSensitivity::VecVJactype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == LOCK) return("mutex lock");
		if (ix == TRY) return("try mutex lock");
		if (ix == WEAK) return("no mutex lock");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMSensitivity::VecVJactype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMSensitivity::VecVJobmask
 ******************************************************************************/

uint TblWznmMSensitivity::VecVJobmask::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "all") return ALL;
	if (s == "imm") return IMM;
	if (s == "self") return SELF;
	if (s == "spec") return SPEC;
	if (s == "tree") return TREE;

	return(0);
};

string TblWznmMSensitivity::VecVJobmask::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == ALL) return("all");
	if (ix == IMM) return("imm");
	if (ix == SELF) return("self");
	if (ix == SPEC) return("spec");
	if (ix == TREE) return("tree");

	return("");
};

string TblWznmMSensitivity::VecVJobmask::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("not applicable");
		if (ix == ALL) return("all jobs");
		if (ix == IMM) return("immediate sub-jobs");
		if (ix == SELF) return("same job");
		if (ix == SPEC) return("specific job");
		if (ix == TREE) return("tree of sub-jobs");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMSensitivity::VecVJobmask::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

