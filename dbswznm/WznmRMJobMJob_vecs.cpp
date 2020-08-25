/**
	* \file WznmRMJobMJob_vecs.cpp
	* database access for table TblWznmRMJobMJob (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmRMJobMJob::VecVConstract
 ******************************************************************************/

uint TblWznmRMJobMJob::VecVConstract::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "cre") return CRE;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmRMJobMJob::VecVConstract::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == CRE) return("cre");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmRMJobMJob::VecVConstract::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == CRE) return("create");
		if (ix == CUST) return("custom");
		return(getSref(ix));
	};

	return("");
};

void TblWznmRMJobMJob::VecVConstract::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

