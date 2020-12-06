/**
	* \file WznmMRelation_vecs.cpp
	* database access for table TblWznmMRelation (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMRelation::VecVBasetype
 ******************************************************************************/

uint TblWznmMRelation::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "grp") return GRP;
	if (s == "own") return OWN;
	if (s == "_11") return _11;
	if (s == "_1n") return _1N;
	if (s == "_1npref") return _1NPREF;
	if (s == "_1nsub1n") return _1NSUB1N;
	if (s == "mn") return MN;
	if (s == "mnsubmn") return MNSUBMN;
	if (s == "mnpref") return MNPREF;
	if (s == "drv") return DRV;
	if (s == "drvsub") return DRVSUB;
	if (s == "drvusub") return DRVUSUB;
	if (s == "inc") return INC;
	if (s == "j") return J;
	if (s == "jpref") return JPREF;
	if (s == "clust") return CLUST;
	if (s == "aux") return AUX;
	if (s == "auxpref") return AUXPREF;
	if (s == "h1n") return H1N;
	if (s == "u1n") return U1N;
	if (s == "u1nsub") return U1NSUB;
	if (s == "u1nsubpref") return U1NSUBPREF;
	if (s == "u1nsubinc") return U1NSUBINC;
	if (s == "u1nsub11") return U1NSUB11;
	if (s == "umn") return UMN;
	if (s == "um1n") return UM1N;
	if (s == "a1n") return A1N;
	if (s == "au1n") return AU1N;
	if (s == "au1nsub") return AU1NSUB;
	if (s == "as1n") return AS1N;
	if (s == "asmn") return ASMN;
	if (s == "lu1n") return LU1N;
	if (s == "lu1nsub") return LU1NSUB;
	if (s == "lu1nlsub") return LU1NLSUB;
	if (s == "l1nop") return L1NOP;
	if (s == "l1noppr") return L1NOPPR;
	if (s == "l1n") return L1N;
	if (s == "lmn") return LMN;
	if (s == "lmnop") return LMNOP;
	if (s == "lmnoppr") return LMNOPPR;

	return(0);
};

string TblWznmMRelation::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == GRP) return("grp");
	if (ix == OWN) return("own");
	if (ix == _11) return("_11");
	if (ix == _1N) return("_1n");
	if (ix == _1NPREF) return("_1npref");
	if (ix == _1NSUB1N) return("_1nsub1n");
	if (ix == MN) return("mn");
	if (ix == MNSUBMN) return("mnsubmn");
	if (ix == MNPREF) return("mnpref");
	if (ix == DRV) return("drv");
	if (ix == DRVSUB) return("drvsub");
	if (ix == DRVUSUB) return("drvusub");
	if (ix == INC) return("inc");
	if (ix == J) return("j");
	if (ix == JPREF) return("jpref");
	if (ix == CLUST) return("clust");
	if (ix == AUX) return("aux");
	if (ix == AUXPREF) return("auxpref");
	if (ix == H1N) return("h1n");
	if (ix == U1N) return("u1n");
	if (ix == U1NSUB) return("u1nsub");
	if (ix == U1NSUBPREF) return("u1nsubpref");
	if (ix == U1NSUBINC) return("u1nsubinc");
	if (ix == U1NSUB11) return("u1nsub11");
	if (ix == UMN) return("umn");
	if (ix == UM1N) return("um1n");
	if (ix == A1N) return("a1n");
	if (ix == AU1N) return("au1n");
	if (ix == AU1NSUB) return("au1nsub");
	if (ix == AS1N) return("as1n");
	if (ix == ASMN) return("asmn");
	if (ix == LU1N) return("lu1n");
	if (ix == LU1NSUB) return("lu1nsub");
	if (ix == LU1NLSUB) return("lu1nlsub");
	if (ix == L1NOP) return("l1nop");
	if (ix == L1NOPPR) return("l1noppr");
	if (ix == L1N) return("l1n");
	if (ix == LMN) return("lmn");
	if (ix == LMNOP) return("lmnop");
	if (ix == LMNOPPR) return("lmnoppr");

	return("");
};

string TblWznmMRelation::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == GRP) return("owning user group 1:n");
		if (ix == OWN) return("owner 1:n");
		if (ix == _11) return("1:1");
		if (ix == _1N) return("1:n");
		if (ix == _1NPREF) return("pref sub to 1:n");
		if (ix == _1NSUB1N) return("1:n sub to 1:n");
		if (ix == MN) return("m:n");
		if (ix == MNSUBMN) return("m:n sub to m:n");
		if (ix == MNPREF) return("pref sub to m:n");
		if (ix == DRV) return("univ derivate");
		if (ix == DRVSUB) return("fixed sub to univ derivate");
		if (ix == DRVUSUB) return("univ sub to univ derivate");
		if (ix == INC) return("inclusion");
		if (ix == J) return("jump table 1:n");
		if (ix == JPREF) return("pref sub to jump table 1:n");
		if (ix == CLUST) return("cluster 1:n");
		if (ix == AUX) return("aux 1:n");
		if (ix == AUXPREF) return("pref aux to aux 1:n");
		if (ix == H1N) return("hierarchical 1:n");
		if (ix == U1N) return("universal 1:n");
		if (ix == U1NSUB) return("1:n sub to universal 1:n");
		if (ix == U1NSUBPREF) return("pref sub to universal 1:n");
		if (ix == U1NSUBINC) return("inclusion sub to univ 1:n");
		if (ix == U1NSUB11) return("1:1 sub to universal 1:n");
		if (ix == UMN) return("universal m:n");
		if (ix == UM1N) return("any main table 1:n");
		if (ix == A1N) return("attribute 1:n");
		if (ix == AU1N) return("attr universal 1:n");
		if (ix == AU1NSUB) return("spec sub to attr univ 1:n");
		if (ix == AS1N) return("attr string ref 1:n");
		if (ix == ASMN) return("attr string refs m:n");
		if (ix == LU1N) return("list fct univ 1:n");
		if (ix == LU1NSUB) return("sub to list fct univ 1:n");
		if (ix == LU1NLSUB) return("list fct sub to lu1n");
		if (ix == L1NOP) return("operator sub to l1n/lu1n");
		if (ix == L1NOPPR) return("partner sub 1:n to l1nop");
		if (ix == L1N) return("list fct 1:n");
		if (ix == LMN) return("list fct m:n");
		if (ix == LMNOP) return("operator sub to lmn");
		if (ix == LMNOPPR) return("partner sub 1:n to lmnop");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMRelation::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 40; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMRelation::VecVSupSubrole
 ******************************************************************************/

uint TblWznmMRelation::VecVSupSubrole::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "from1n") return FROM1N;
	if (s == "to1n") return TO1N;
	if (s == "submn") return SUBMN;
	if (s == "pref") return PREF;
	if (s == "frompref") return FROMPREF;
	if (s == "topref") return TOPREF;
	if (s == "r1n") return R1N;
	if (s == "mn1n") return MN1N;
	if (s == "mod") return MOD;
	if (s == "sub") return SUB;
	if (s == "subl") return SUBL;
	if (s == "subinc") return SUBINC;
	if (s == "sub11") return SUB11;
	if (s == "sub1n") return SUB1N;
	if (s == "pr1") return PR1;
	if (s == "pr2") return PR2;
	if (s == "op") return OP;
	if (s == "toum1n") return TOUM1N;
	if (s == "spec") return SPEC;

	return(0);
};

string TblWznmMRelation::VecVSupSubrole::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == FROM1N) return("from1n");
	if (ix == TO1N) return("to1n");
	if (ix == SUBMN) return("submn");
	if (ix == PREF) return("pref");
	if (ix == FROMPREF) return("frompref");
	if (ix == TOPREF) return("topref");
	if (ix == R1N) return("r1n");
	if (ix == MN1N) return("mn1n");
	if (ix == MOD) return("mod");
	if (ix == SUB) return("sub");
	if (ix == SUBL) return("subl");
	if (ix == SUBINC) return("subinc");
	if (ix == SUB11) return("sub11");
	if (ix == SUB1N) return("sub1n");
	if (ix == PR1) return("pr1");
	if (ix == PR2) return("pr2");
	if (ix == OP) return("op");
	if (ix == TOUM1N) return("toum1n");
	if (ix == SPEC) return("spec");

	return("");
};

string TblWznmMRelation::VecVSupSubrole::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == FROM1N) return("from table");
		if (ix == TO1N) return("to table");
		if (ix == SUBMN) return("T table");
		if (ix == PREF) return("preferred");
		if (ix == FROMPREF) return("preferred in from table");
		if (ix == TOPREF) return("preferred in to table");
		if (ix == R1N) return("rel table");
		if (ix == MN1N) return("m:n rel table");
		if (ix == MOD) return("modifier");
		if (ix == SUB) return("1:n sub");
		if (ix == SUBL) return("1:n sub with list fct");
		if (ix == SUBINC) return("inclusion sub");
		if (ix == SUB11) return("1:1 sub");
		if (ix == SUB1N) return("S table");
		if (ix == PR1) return("partner 1");
		if (ix == PR2) return("partner 2");
		if (ix == OP) return("list operator");
		if (ix == TOUM1N) return("to any main table");
		if (ix == SPEC) return("specification");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMRelation::VecVSupSubrole::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 20; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};
