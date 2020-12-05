/**
	* \file WznmCtpWrstkitArm.h
	* Wznm operation processor - database, basic UI and import/export (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSTKITARM_H
#define WZNMCTPWRSTKITARM_H

#include "WznmCtpWrstkit.h"

// IP include.cust --- INSERT

namespace WznmCtpWrstkitArm {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrstkit* dpchinv);
	// IP cust --- IBEGIN

	void writeIexBui(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::string& outfolder, const bool adr, const bool org, const bool horg, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void writeIexDbs(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::string& outfolder, const bool adr, const bool org, const bool horg, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void writeIexIex(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::string& outfolder, const bool adr, const bool org, const bool horg, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	// IP cust --- IEND
};

#endif



