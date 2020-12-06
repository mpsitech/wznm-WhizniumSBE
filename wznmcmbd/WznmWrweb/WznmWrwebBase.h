/**
	* \file WznmWrwebBase.h
	* Wznm operation processor - write web UI JS/HTML code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
