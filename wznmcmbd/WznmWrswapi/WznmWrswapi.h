/**
	* \file WznmWrswapi.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSWAPI_H
#define WZNMWRSWAPI_H

#include "WznmWrswapi_blks.h"

// IP include.cust --- INSERT

namespace WznmWrswapi {

	// IP cust --- IBEGIN
	void writeVecSw(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const bool subclass, const std::string& supsref, const std::string& subsref);

  std::string getSwDefault(const std::string& swtype);
	// IP cust --- IEND
};

#endif
