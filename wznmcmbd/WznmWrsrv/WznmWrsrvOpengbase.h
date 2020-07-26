/**
	* \file WznmWrsrvOpengbase.h
	* Wznm operation processor - write operation engine C++ code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRSRVOPENGBASE_H
#define WZNMWRSRVOPENGBASE_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvOpengbase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvOpengbase* dpchinv);
	// IP cust --- IBEGIN

	void writeExeCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMOppack& opks, ListWznmMBlock& stgblks, const bool dbsmy, const bool dbslite);
	void writeEsrvH(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, ListWznmMOppack& opks);
	void writeEsrvCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMOppack& opks);
	void writeOprcH(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, ListWznmMOppack& opks);
	void writeOprcCpp(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMOppack& opks);
	void writeOpdH(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, ListWznmMBlock& stgblks);
	void writeOpdCpp(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, ListWznmMBlock& stgblks);
	// IP cust --- IEND
};

#endif


