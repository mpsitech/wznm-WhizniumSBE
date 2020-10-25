/**
	* \file WznmWrsrvOp.h
	* Wznm operation processor - write C++ code for operation (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRSRVOP_H
#define WZNMWRSRVOP_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvOp {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvOp* dpchinv);
	// IP cust --- IBEGIN

	void writeOpH(DbsWznm* dbswznm, std::fstream& outfile, WznmMOp* op, WznmMBlock* stgblk, const std::string& Prjshort, const std::string& srefDpchinv, const std::string& srefDpchret);
	void writeOpCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMOp* op, WznmMBlock* stgblk, const std::string& Prjshort, const std::string& srefDpchinv, const std::string& srefDpchret);
	// IP cust --- IEND
};

#endif


