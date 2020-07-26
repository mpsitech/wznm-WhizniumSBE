/**
	* \file WznmMTable_vecs.cpp
	* database access for table TblWznmMTable (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMTable::VecVBasetype
 ******************************************************************************/

uint TblWznmMTable::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "main") return MAIN;
	if (s == "aux") return AUX;
	if (s == "rel") return REL;
	if (s == "jump") return JUMP;
	if (s == "clust") return CLUST;
	if (s == "list") return LIST;
	if (s == "opr") return OPR;
	if (s == "sub1n") return SUB1N;
	if (s == "submn") return SUBMN;
	if (s == "qry") return QRY;

	return(0);
};

string TblWznmMTable::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == MAIN) return("main");
	if (ix == AUX) return("aux");
	if (ix == REL) return("rel");
	if (ix == JUMP) return("jump");
	if (ix == CLUST) return("clust");
	if (ix == LIST) return("list");
	if (ix == OPR) return("opr");
	if (ix == SUB1N) return("sub1n");
	if (ix == SUBMN) return("submn");
	if (ix == QRY) return("qry");

	return("");
};

string TblWznmMTable::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == MAIN) return("main");
		if (ix == AUX) return("auxiliary");
		if (ix == REL) return("m:n");
		if (ix == JUMP) return("jump");
		if (ix == CLUST) return("cluster");
		if (ix == LIST) return("list");
		if (ix == OPR) return("list operator");
		if (ix == SUB1N) return("sub 1:n for 1:n");
		if (ix == SUBMN) return("sub 1:n for m:n");
		if (ix == QRY) return("query");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMTable::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 10; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMTable::VecVRefTbl
 ******************************************************************************/

uint TblWznmMTable::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "qry") return QRY;
	if (s == "rel") return REL;

	return(0);
};

string TblWznmMTable::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == QRY) return("qry");
	if (ix == REL) return("rel");

	return("");
};

string TblWznmMTable::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == QRY) return("query");
		if (ix == REL) return("relation");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMTable::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMTable::VecWSubset
 ******************************************************************************/

uint TblWznmMTable::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswznmbmtablemtb") ix |= SBSWZNMBMTABLEMTB;
		else if (ss[i] == "sbswznmbmtableqtb") ix |= SBSWZNMBMTABLEQTB;
		else if (ss[i] == "sbswznmbmtablerlt") ix |= SBSWZNMBMTABLERLT;
		else if (ss[i] == "sbswznmbmtablestt") ix |= SBSWZNMBMTABLESTT;
	};

	return(ix);
};

void TblWznmMTable::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWZNMBMTABLESTT); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMTable::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWZNMBMTABLEMTB) ss.push_back("SbsWznmBMTableMtb");
	if (ix & SBSWZNMBMTABLEQTB) ss.push_back("SbsWznmBMTableQtb");
	if (ix & SBSWZNMBMTABLERLT) ss.push_back("SbsWznmBMTableRlt");
	if (ix & SBSWZNMBMTABLESTT) ss.push_back("SbsWznmBMTableStt");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMTable::VecWSubset::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SBSWZNMBMTABLEMTB) return("main table");
		if (ix == SBSWZNMBMTABLEQTB) return("query table");
		if (ix == SBSWZNMBMTABLERLT) return("relation table");
		if (ix == SBSWZNMBMTABLESTT) return("storage table");
		return(getSrefs(ix));
	};

	return("");
};

