/**
	* \file WznmWrapiDeploy.h
	* Wznm operation processor - write API code deployment scripts (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRAPIDEPLOY_H
#define WZNMWRAPIDEPLOY_H

#include "WznmWrapi.h"

// IP include.cust --- INSERT

namespace WznmWrapiDeploy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrapiDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeMake(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMRelease* rls, std::vector<Sbecore::ubigint>& hrefsMch, std::set<std::string>& incpaths);

	void addLibBySref(DbsWznm* dbswznm, const std::string& srefLib, const Sbecore::ubigint refMch, std::vector<Sbecore::ubigint>& hrefsMch, std::set<std::string>& incpaths);
	std::string pathToPathstr(const std::string& path, const std::string& inclibeq);
	// IP cust --- IEND
};

#endif



