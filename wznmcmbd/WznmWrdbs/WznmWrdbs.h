/**
	* \file WznmWrdbs.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRDBS_H
#define WZNMWRDBS_H

#include "WznmWrdbs_blks.h"

// IP include.cust --- INSERT

namespace WznmWrdbs {

	// IP cust --- IBEGIN
	void writeVecH(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const std::string& subsref);
	void writeVecCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const std::string& supsref, const std::string& subsref, Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	// IP cust --- IEND
};

#endif
