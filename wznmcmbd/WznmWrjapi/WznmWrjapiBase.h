/**
	* \file WznmWrjapiBase.h
	* Wznm operation processor - write Java API code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRJAPIBASE_H
#define WZNMWRJAPIBASE_H

#include "WznmWrjapi.h"

// IP include.cust --- INSERT

namespace WznmWrjapiBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrjapiBase* dpchinv);
	// IP cust --- IBEGIN

	void writeApiJ(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion);
	void writeVecdpchJ(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMBlock& blks);
	// IP cust --- IEND
};

#endif


