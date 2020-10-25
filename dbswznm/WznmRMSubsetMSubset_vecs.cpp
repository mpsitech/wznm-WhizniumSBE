/**
	* \file WznmRMSubsetMSubset_vecs.cpp
	* database access for table TblWznmRMSubsetMSubset (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmRMSubsetMSubset::VecVReltype
 ******************************************************************************/

uint TblWznmRMSubsetMSubset::VecVReltype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ainb") return AINB;
	if (s == "bina") return BINA;
	if (s == "compl") return COMPL;
	if (s == "disj") return DISJ;
	if (s == "xsec") return XSEC;

	return(0);
};

string TblWznmRMSubsetMSubset::VecVReltype::getSref(
			const uint ix
		) {
	if (ix == AINB) return("ainb");
	if (ix == BINA) return("bina");
	if (ix == COMPL) return("compl");
	if (ix == DISJ) return("disj");
	if (ix == XSEC) return("xsec");

	return("");
};

string TblWznmRMSubsetMSubset::VecVReltype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == AINB) return("a includes b");
		if (ix == BINA) return("b includes a");
		if (ix == COMPL) return("complement");
		if (ix == DISJ) return("disjointedness");
		if (ix == XSEC) return("intersection");
		return(getSref(ix));
	};

	return("");
};

void TblWznmRMSubsetMSubset::VecVReltype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

