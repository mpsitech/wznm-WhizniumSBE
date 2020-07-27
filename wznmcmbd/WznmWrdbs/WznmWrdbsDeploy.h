/**
	* \file WznmWrdbsDeploy.h
	* Wznm operation processor - write database access library deployment scripts (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRDBSDEPLOY_H
#define WZNMWRDBSDEPLOY_H

#include "WznmWrdbs.h"

// IP include.cust --- INSERT

namespace WznmWrdbsDeploy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrdbsDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeMake(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const Sbecore::ubigint refMty, WznmMRelease* rls, std::set<std::string>& incpaths);

	void addLibBySref(DbsWznm* dbswznm, const std::string& srefLib, const Sbecore::ubigint refMty, const Sbecore::ubigint refMch, std::set<std::string>& incpaths);
	std::string getLibAMkfTagVal(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMLibrary, const Sbecore::ubigint refMty, const Sbecore::ubigint refMch, const std::string& tag);
	std::string pathToPathstr(const std::string& path, const std::string& inclibeq);
	// IP cust --- IEND
};

#endif

