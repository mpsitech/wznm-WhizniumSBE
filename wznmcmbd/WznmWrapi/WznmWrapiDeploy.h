/**
	* \file WznmWrapiDeploy.h
	* Wznm operation processor - write API code deployment scripts (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRAPIDEPLOY_H
#define WZNMWRAPIDEPLOY_H

#include "WznmWrapi.h"

// IP include.cust --- INSERT

namespace WznmWrapiDeploy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrapiDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeMake(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refMty, WznmMRelease* rls, std::set<std::string>& incpaths);

	void addLibBySref(DbsWznm* dbswznm, const std::string& srefLib, const Sbecore::ubigint refMty, const Sbecore::ubigint refMch, std::set<std::string>& incpaths);
	std::string getLibAMkfTagVal(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMLibrary, const Sbecore::ubigint refMty, const Sbecore::ubigint refMch, const std::string& tag);
	std::string pathToPathstr(const std::string& path, const std::string& inclibeq);
	// IP cust --- IEND
};

#endif


