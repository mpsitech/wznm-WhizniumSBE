/**
	* \file WznmWrapi.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRAPI_H
#define WZNMWRAPI_H

#include "WznmWrapi_blks.h"

// IP include.cust --- INSERT

namespace WznmWrapi {

	// IP cust --- IBEGIN
	void writeVecH(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const bool subclass, const std::string& subsref);
	void writeVecCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const bool subclass, const std::string& supsref, const std::string& subsref);
	// IP cust --- IEND
};

#endif



