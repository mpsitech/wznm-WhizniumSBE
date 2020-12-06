/**
	* \file WznmWrsrvBase.h
	* Wznm operation processor - write server C++ code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRSRVBASE_H
#define WZNMWRSRVBASE_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvBase* dpchinv);
	// IP cust --- IBEGIN

	void writeGblH(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const std::string& Prjshort);
	void writeGblCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const std::string& Prjshort, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void writeVecappH(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, WznmMVector* vec);
	void writeVecappCpp(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, WznmMVector* vec, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl);
	// IP cust --- IEND
};

#endif
