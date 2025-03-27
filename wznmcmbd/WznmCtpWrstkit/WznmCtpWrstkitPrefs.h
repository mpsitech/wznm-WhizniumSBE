/**
	* \file WznmCtpWrstkitPrefs.h
	* Wznm operation processor - basic UI (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSTKITPREFS_H
#define WZNMCTPWRSTKITPREFS_H

#include "WznmCtpWrstkit.h"

// IP include.cust --- INSERT

namespace WznmCtpWrstkitPrefs {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrstkit* dpchinv);
	// IP cust --- IBEGIN

	void writeIexBui(DbsWznm* dbswznm, WznmMCapability* cpb, const std::string& Prjshort, const std::string& outfolder, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	// IP cust --- IEND
};

#endif
