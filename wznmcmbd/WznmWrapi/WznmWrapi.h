/**
	* \file WznmWrapi.h
	* Wznm operation pack global code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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


