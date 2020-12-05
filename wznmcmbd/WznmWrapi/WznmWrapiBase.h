/**
	* \file WznmWrapiBase.h
	* Wznm operation processor - write API code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRAPIBASE_H
#define WZNMWRAPIBASE_H

#include "WznmWrapi.h"

// IP include.cust --- INSERT

namespace WznmWrapiBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrapiBase* dpchinv);
	// IP cust --- IBEGIN

	void writeApiH(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion);
	void writeApiCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion);
	void writeApiblksH(std::fstream& outfile, ListWznmMVector& vecs);
	void writeVecdpchH(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMBlock& blks);
	void writeVecdpchCpp(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMBlock& blks);
	// IP cust --- IEND
};

#endif



