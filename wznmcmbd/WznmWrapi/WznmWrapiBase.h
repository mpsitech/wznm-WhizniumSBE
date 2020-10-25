/**
	* \file WznmWrapiBase.h
	* Wznm operation processor - write API code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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


