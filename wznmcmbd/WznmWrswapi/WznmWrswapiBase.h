/**
	* \file WznmWrswapiBase.h
	* Wznm operation processor - write Swift API code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSWAPIBASE_H
#define WZNMWRSWAPIBASE_H

#include "WznmWrswapi.h"

// IP include.cust --- INSERT

namespace WznmWrswapiBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrswapiBase* dpchinv);
	// IP cust --- IBEGIN

	void writeApiSw(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion);
	void writeVecdpchSw(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMBlock& blks);
	// IP cust --- IEND
};

#endif
