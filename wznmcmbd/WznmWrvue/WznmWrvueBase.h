/**
	* \file WznmWrvueBase.h
	* Wznm operation processor - write Vue.js UI Vue code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRVUEBASE_H
#define WZNMWRVUEBASE_H

#include "WznmWrvue.h"

// IP include.cust --- INSERT

namespace WznmWrvueBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrvueBase* dpchinv);
	// IP cust --- IBEGIN

	void writeCsVue(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void writeSessVue(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars);
	void writeCrdnavVue(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars);

	void writeChkoutSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars);
	// IP cust --- IEND
};

#endif
