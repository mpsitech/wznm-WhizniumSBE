/**
	* \file WznmMPerson_vecs.cpp
	* database access for table TblWznmMPerson (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMPerson::VecVSex
 ******************************************************************************/

uint TblWznmMPerson::VecVSex::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "f") return F;
	if (s == "m") return M;

	return(0);
};

string TblWznmMPerson::VecVSex::getSref(
			const uint ix
		) {
	if (ix == F) return("f");
	if (ix == M) return("m");

	return("");
};

string TblWznmMPerson::VecVSex::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == F) return("female");
		if (ix == M) return("male");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMPerson::VecVSex::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMPerson::VecWDerivate
 ******************************************************************************/

uint TblWznmMPerson::VecWDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "usr") ix |= USR;
	};

	return(ix);
};

void TblWznmMPerson::VecWDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*USR); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMPerson::VecWDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & USR) ss.push_back("usr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMPerson::VecWDerivate::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == USR) return("user");
		return(getSrefs(ix));
	};

	return("");
};

void TblWznmMPerson::VecWDerivate::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= USR; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWznmVLocale));
};

