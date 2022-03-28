/**
	* \file WznmWrsapiBase.h
	* Wznm operation processor - write Swift API code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSAPIBASE_H
#define WZNMWRSAPIBASE_H

#include "WznmWrsapi.h"

// IP include.cust --- INSERT

namespace WznmWrsapiBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsapiBase* dpchinv);
	// IP cust --- IBEGIN

	void writeApiSw(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion);
	void writeVecdpchSw(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMBlock& blks);
	// IP cust --- IEND
};

#endif
