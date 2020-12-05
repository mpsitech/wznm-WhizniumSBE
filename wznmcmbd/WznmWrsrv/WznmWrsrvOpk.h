/**
	* \file WznmWrsrvOpk.h
	* Wznm operation processor - write C++ code for operation pack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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



