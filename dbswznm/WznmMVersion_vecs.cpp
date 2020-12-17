/**
	* \file WznmMVersion_vecs.cpp
	* database access for table TblWznmMVersion (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMVersion::VecVState
 ******************************************************************************/

uint TblWznmMVersion::VecVState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "newcre") return NEWCRE;
	if (s == "newimp") return NEWIMP;
	if (s == "dsndeploy") return DSNDEPLOY;
	if (s == "dsnglobal") return DSNGLOBAL;
	if (s == "dsndbstr") return DSNDBSTR;
	if (s == "dsnbscui") return DSNBSCUI;
	if (s == "dsnimpexp") return DSNIMPEXP;
	if (s == "dsnoppack") return DSNOPPACK;
	if (s == "dsncustjob") return DSNCUSTJOB;
	if (s == "dsngenui") return DSNGENUI;
	if (s == "dsncustui") return DSNCUSTUI;
	if (s == "dsngenjtr") return DSNGENJTR;
	if (s == "dsncustjtr") return DSNCUSTJTR;
	if (s == "ready") return READY;
	if (s == "abandon") return ABANDON;

	return(0);
};

string TblWznmMVersion::VecVState::getSref(
			const uint ix
		) {
	if (ix == NEWCRE) return("newcre");
	if (ix == NEWIMP) return("newimp");
	if (ix == DSNDEPLOY) return("dsndeploy");
	if (ix == DSNGLOBAL) return("dsnglobal");
	if (ix == DSNDBSTR) return("dsndbstr");
	if (ix == DSNBSCUI) return("dsnbscui");
	if (ix == DSNIMPEXP) return("dsnimpexp");
	if (ix == DSNOPPACK) return("dsnoppack");
	if (ix == DSNCUSTJOB) return("dsncustjob");
	if (ix == DSNGENUI) return("dsngenui");
	if (ix == DSNCUSTUI) return("dsncustui");
	if (ix == DSNGENJTR) return("dsngenjtr");
	if (ix == DSNCUSTJTR) return("dsncustjtr");
	if (ix == READY) return("ready");
	if (ix == ABANDON) return("abandon");

	return("");
};

string TblWznmMVersion::VecVState::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == NEWCRE) return("newly created");
		if (ix == NEWIMP) return("newly imported");
		if (ix == DSNDEPLOY) return("design phase, deployment information imported");
		if (ix == DSNGLOBAL) return("design phase, global features imported");
		if (ix == DSNDBSTR) return("design phase, database structure imported");
		if (ix == DSNBSCUI) return("design phase, basic user interface structure imported");
		if (ix == DSNIMPEXP) return("design phase, import/export structure imported");
		if (ix == DSNOPPACK) return("design phase, operation pack structure imported");
		if (ix == DSNCUSTJOB) return("design phase, custom jobs imported");
		if (ix == DSNGENUI) return("design phase, user interface generated");
		if (ix == DSNCUSTUI) return("design phase, custom user interface features applied");
		if (ix == DSNGENJTR) return("design phase, job tree generated");
		if (ix == DSNCUSTJTR) return("design phase, custom job tree features applied");
		if (ix == READY) return("build-ready");
		if (ix == ABANDON) return("abandonned");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMVersion::VecVState::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 15; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMVersion::VecWDbmstype
 ******************************************************************************/

uint TblWznmMVersion::VecWDbmstype::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "mararia") ix |= MARARIA;
		else if (ss[i] == "marinno") ix |= MARINNO;
		else if (ss[i] == "myinno") ix |= MYINNO;
		else if (ss[i] == "myisam") ix |= MYISAM;
		else if (ss[i] == "pg") ix |= PG;
		else if (ss[i] == "lite") ix |= LITE;
	};

	return(ix);
};

void TblWznmMVersion::VecWDbmstype::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LITE); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMVersion::VecWDbmstype::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & MARARIA) ss.push_back("mararia");
	if (ix & MARINNO) ss.push_back("marinno");
	if (ix & MYINNO) ss.push_back("myinno");
	if (ix & MYISAM) ss.push_back("myisam");
	if (ix & PG) ss.push_back("pg");
	if (ix & LITE) ss.push_back("lite");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMVersion::VecWDbmstype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == MARARIA) return("MariaDB Aria");
		if (ix == MARINNO) return("MariaDB InnoDB");
		if (ix == MYINNO) return("MySQL InnoDB");
		if (ix == MYISAM) return("MySQL MyISAM");
		if (ix == PG) return("PostgreSQL");
		if (ix == LITE) return("SQLite");
		return(getSrefs(ix));
	};

	return("");
};

void TblWznmMVersion::VecWDbmstype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= LITE; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMVersion::VecWOption
 ******************************************************************************/

uint TblWznmMVersion::VecWOption::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "accgrpreg") ix |= ACCGRPREG;
		else if (ss[i] == "accnogoall") ix |= ACCNOGOALL;
		else if (ss[i] == "apimon") ix |= APIMON;
		else if (ss[i] == "dbsmon") ix |= DBSMON;
		else if (ss[i] == "ddspub") ix |= DDSPUB;
		else if (ss[i] == "uasrv") ix |= UASRV;
	};

	return(ix);
};

void TblWznmMVersion::VecWOption::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*UASRV); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMVersion::VecWOption::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & ACCGRPREG) ss.push_back("accgrpreg");
	if (ix & ACCNOGOALL) ss.push_back("accnogoall");
	if (ix & APIMON) ss.push_back("apimon");
	if (ix & DBSMON) ss.push_back("dbsmon");
	if (ix & DDSPUB) ss.push_back("ddspub");
	if (ix & UASRV) ss.push_back("uasrv");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMVersion::VecWOption::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ACCGRPREG) return("view access for regular users to all grp records");
		if (ix == ACCNOGOALL) return("access for all users to no-grp/own records");
		if (ix == APIMON) return("monitoring via API");
		if (ix == DBSMON) return("monitoring to database");
		if (ix == DDSPUB) return("DDS publisher");
		if (ix == UASRV) return("OPC UA server");
		return(getSrefs(ix));
	};

	return("");
};

void TblWznmMVersion::VecWOption::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= UASRV; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWznmVLocale));
};
