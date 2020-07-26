/**
	* \file WznmWrsrvEngbase.h
	* Wznm operation processor - write main engine C++ code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRSRVENGBASE_H
#define WZNMWRSRVENGBASE_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvEngbase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvEngbase* dpchinv);
	// IP cust --- IBEGIN

	void writeExeH(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const bool hasdds, const bool hasua);
	void writeExeCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMBlock& stgblks, const bool dbsmy, const bool dbslite, const bool hasdds, const bool hasua);
	void writeAppCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void writeOprcCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void writeDH(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const std::string& Prjshort, ListWznmMBlock& stgblks, const bool hasdds, const bool hasua);
	void writeDCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const std::string& orgname, const std::string& Prjshort, ListWznmMBlock& stgblks, const bool hasdds, const bool hasua);
	// IP cust --- IEND
};

#endif


