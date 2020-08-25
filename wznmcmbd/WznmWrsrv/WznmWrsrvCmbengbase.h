/**
	* \file WznmWrsrvCmbengbase.h
	* Wznm operation processor - write combined engine C++ code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRSRVCMBENGBASE_H
#define WZNMWRSRVCMBENGBASE_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvCmbengbase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvCmbengbase* dpchinv);
	// IP cust --- IBEGIN

	void writeExeH(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const bool hasdds, const bool hasua);
	void writeExeCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion , const std::string& Prjshort, ListWznmMBlock& stgblks, const bool dbsmy, const bool dbslite, const bool hasdds, const bool hasua);
	void writeAppCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void writeOprcH(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion);
	void writeOprcCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void writeCmbdH(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const std::string& Prjshort, ListWznmMBlock& stgblks, const bool hasdds, const bool hasua);
	void writeCmbdCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const std::string& orgname, const std::string& Prjshort, ListWznmMBlock& stgblks, const bool hasdds, const bool hasua);
	// IP cust --- IEND
};

#endif


