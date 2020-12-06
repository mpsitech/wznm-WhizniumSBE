/**
	* \file WznmMCapability_vecs.cpp
	* database access for table TblWznmMCapability (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMCapability::VecWArtefact
 ******************************************************************************/

uint TblWznmMCapability::VecWArtefact::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "dbs") ix |= DBS;
		else if (ss[i] == "bui") ix |= BUI;
		else if (ss[i] == "iex") ix |= IEX;
		else if (ss[i] == "srvgblcode") ix |= SRVGBLCODE;
		else if (ss[i] == "srvjobcode") ix |= SRVJOBCODE;
		else if (ss[i] == "webgblcode") ix |= WEBGBLCODE;
		else if (ss[i] == "webjobcode") ix |= WEBJOBCODE;
	};

	return(ix);
};

void TblWznmMCapability::VecWArtefact::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*WEBJOBCODE); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMCapability::VecWArtefact::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & DBS) ss.push_back("dbs");
	if (ix & BUI) ss.push_back("bui");
	if (ix & IEX) ss.push_back("iex");
	if (ix & SRVGBLCODE) ss.push_back("srvgblcode");
	if (ix & SRVJOBCODE) ss.push_back("srvjobcode");
	if (ix & WEBGBLCODE) ss.push_back("webgblcode");
	if (ix & WEBJOBCODE) ss.push_back("webjobcode");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMCapability::VecWArtefact::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == DBS) return("database structure");
		if (ix == BUI) return("basic user interface structure");
		if (ix == IEX) return("import/export structure");
		if (ix == SRVGBLCODE) return("server global code");
		if (ix == SRVJOBCODE) return("server job code");
		if (ix == WEBGBLCODE) return("web UI global code");
		if (ix == WEBJOBCODE) return("web UI job code");
		return(getSrefs(ix));
	};

	return("");
};

void TblWznmMCapability::VecWArtefact::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= WEBJOBCODE; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMCapability::VecWSubset
 ******************************************************************************/

uint TblWznmMCapability::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswznmbmcapabilitycap") ix |= SBSWZNMBMCAPABILITYCAP;
		else if (ss[i] == "sbswznmbmcapabilityctp") ix |= SBSWZNMBMCAPABILITYCTP;
	};

	return(ix);
};

void TblWznmMCapability::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWZNMBMCAPABILITYCTP); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMCapability::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWZNMBMCAPABILITYCAP) ss.push_back("SbsWznmBMCapabilityCap");
	if (ix & SBSWZNMBMCAPABILITYCTP) ss.push_back("SbsWznmBMCapabilityCtp");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMCapability::VecWSubset::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SBSWZNMBMCAPABILITYCAP) return("capability");
		if (ix == SBSWZNMBMCAPABILITYCTP) return("capability template");
		return(getSrefs(ix));
	};

	return("");
};
