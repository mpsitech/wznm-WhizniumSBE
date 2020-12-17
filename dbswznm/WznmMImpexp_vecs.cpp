/**
	* \file WznmMImpexp_vecs.cpp
	* database access for table TblWznmMImpexp (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMImpexp::VecWIop
 ******************************************************************************/

uint TblWznmMImpexp::VecWIop::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "ins") ix |= INS;
		else if (ss[i] == "retr") ix |= RETR;
		else if (ss[i] == "retrupd") ix |= RETRUPD;
		else if (ss[i] == "retrins") ix |= RETRINS;
		else if (ss[i] == "retrupdins") ix |= RETRUPDINS;
		else if (ss[i] == "rmv") ix |= RMV;
		else if (ss[i] == "cust") ix |= CUST;
	};

	return(ix);
};

void TblWznmMImpexp::VecWIop::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*CUST); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMImpexp::VecWIop::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & INS) ss.push_back("ins");
	if (ix & RETR) ss.push_back("retr");
	if (ix & RETRUPD) ss.push_back("retrupd");
	if (ix & RETRINS) ss.push_back("retrins");
	if (ix & RETRUPDINS) ss.push_back("retrupdins");
	if (ix & RMV) ss.push_back("rmv");
	if (ix & CUST) ss.push_back("cust");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMImpexp::VecWIop::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == INS) return("insert");
		if (ix == RETR) return("retrieve");
		if (ix == RETRUPD) return("retrieve and update");
		if (ix == RETRINS) return("retrieve, else insert");
		if (ix == RETRUPDINS) return("retrieve and update, else insert");
		if (ix == RMV) return("remove");
		if (ix == CUST) return("custom");
		return(getSrefs(ix));
	};

	return("");
};

void TblWznmMImpexp::VecWIop::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= CUST; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWznmVLocale));
};
