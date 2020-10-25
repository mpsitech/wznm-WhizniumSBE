/**
	* \file WznmWrwebBase.h
	* Wznm operation processor - write web UI JS/HTML code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRWEBBASE_H
#define WZNMWRWEBBASE_H

#include "WznmWrweb.h"

// IP include.cust --- INSERT

namespace WznmWrwebBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrwebBase* dpchinv);
	// IP cust --- IBEGIN

	void writeCssrcXmfile(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	// IP cust --- IEND
};

#endif


