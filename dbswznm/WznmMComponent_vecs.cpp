/**
	* \file WznmMComponent_vecs.cpp
	* database access for table TblWznmMComponent (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMComponent::VecVBasetype
 ******************************************************************************/

uint TblWznmMComponent::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "eng") return ENG;
	if (s == "openg") return OPENG;
	if (s == "cmbeng") return CMBENG;
	if (s == "dbs") return DBS;
	if (s == "webapp") return WEBAPP;
	if (s == "api") return API;
	if (s == "japi") return JAPI;

	return(0);
};

string TblWznmMComponent::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == ENG) return("eng");
	if (ix == OPENG) return("openg");
	if (ix == CMBENG) return("cmbeng");
	if (ix == DBS) return("dbs");
	if (ix == WEBAPP) return("webapp");
	if (ix == API) return("api");
	if (ix == JAPI) return("japi");

	return("");
};

string TblWznmMComponent::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ENG) return("main engine");
		if (ix == OPENG) return("operation engine");
		if (ix == CMBENG) return("combined engine");
		if (ix == DBS) return("database access library");
		if (ix == WEBAPP) return("web app user interface files");
		if (ix == API) return("API library");
		if (ix == JAPI) return("Java API package");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMComponent::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMComponent::VecWSubset
 ******************************************************************************/

uint TblWznmMComponent::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswznmbmcomponentccp") ix |= SBSWZNMBMCOMPONENTCCP;
		else if (ss[i] == "sbswznmbmcomponentoen") ix |= SBSWZNMBMCOMPONENTOEN;
	};

	return(ix);
};

void TblWznmMComponent::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWZNMBMCOMPONENTOEN); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMComponent::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWZNMBMCOMPONENTCCP) ss.push_back("SbsWznmBMComponentCcp");
	if (ix & SBSWZNMBMCOMPONENTOEN) ss.push_back("SbsWznmBMComponentOen");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMComponent::VecWSubset::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SBSWZNMBMCOMPONENTCCP) return("compileable component");
		if (ix == SBSWZNMBMCOMPONENTOEN) return("operation engine");
		return(getSrefs(ix));
	};

	return("");
};

