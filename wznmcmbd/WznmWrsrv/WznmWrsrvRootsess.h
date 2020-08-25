/**
	* \file WznmWrsrvRootsess.h
	* Wznm operation processor - write specific job C++ code for root and session (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRSRVROOTSESS_H
#define WZNMWRSRVROOTSESS_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvRootsess {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvRootsess* dpchinv);
	// IP cust --- IBEGIN

	void writeRtH(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort);
	void writeRtCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const bool hasm2m);
	void writeSessH(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void writeSessCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void writeM2msessH(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort);
	void writeM2msessCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif


