/**
	* \file WznmCtpWrstkitAcv.h
	* Wznm operation processor - database and basic UI (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSTKITACV_H
#define WZNMCTPWRSTKITACV_H

#include "WznmCtpWrstkit.h"

// IP include.cust --- INSERT

namespace WznmCtpWrstkitAcv {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrstkit* dpchinv);
	// IP cust --- IBEGIN

	void writeIexBui(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::string& outfolder, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void writeIexDbs(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::string& outfolder, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void writeIexIex(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::string& outfolder, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	// IP cust --- IEND
};

#endif
