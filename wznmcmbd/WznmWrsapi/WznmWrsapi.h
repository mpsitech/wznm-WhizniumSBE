/**
	* \file WznmWrsapi.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSAPI_H
#define WZNMWRSAPI_H

#include "WznmWrsapi_blks.h"

// IP include.cust --- INSERT

namespace WznmWrsapi {

	// IP cust --- IBEGIN
	void writeVecSw(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const bool subclass, const std::string& supsref, const std::string& subsref);

  std::string getSwDefault(const std::string& swtype);
	// IP cust --- IEND
};

#endif
