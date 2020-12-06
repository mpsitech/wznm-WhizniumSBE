/**
	* \file WznmWrjapi.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRJAPI_H
#define WZNMWRJAPI_H

#include "WznmWrjapi_blks.h"

// IP include.cust --- INSERT

namespace WznmWrjapi {

	// IP cust --- IBEGIN
	void writeVecJ(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const bool subclass, const std::string& supsref, const std::string& subsref);

  std::string getJDefault(const std::string& jtype);
	// IP cust --- IEND
};

#endif
