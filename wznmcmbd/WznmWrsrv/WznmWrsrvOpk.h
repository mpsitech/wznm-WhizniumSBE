/**
	* \file WznmWrsrvOpk.h
	* Wznm operation processor - write C++ code for operation pack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRSRVOPK_H
#define WZNMWRSRVOPK_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvOpk {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvOpk* dpchinv);
	// IP cust --- IBEGIN

	void writeOpkH(DbsWznm* dbswznm, std::fstream& outfile, WznmMOppack* opk, WznmMBlock* stgblk, const std::string& Prjshort);
	void writeOpkCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMOppack* opk, WznmMBlock* stgblk, const std::string& Prjshort);
	void writeOpkblksH(DbsWznm* dbswznm, std::fstream& outfile, WznmMOppack* opk, const std::string& Prjshort);
	void writeOpkblksCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMOppack* opk, const std::string& orgweb, const std::string& Prjshort);
	void writeSqkH(DbsWznm* dbswznm, std::fstream& outfile, WznmMOppack* opk, const std::string& Prjshort);
	void writeSqkCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMOppack* opk, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif


