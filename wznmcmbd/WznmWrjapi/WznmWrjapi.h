/**
	* \file WznmWrjapi.h
	* Wznm operation pack global code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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


