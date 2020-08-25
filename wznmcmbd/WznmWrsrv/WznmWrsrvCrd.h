/**
	* \file WznmWrsrvCrd.h
	* Wznm operation processor - write specific job C++ code for card (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRSRVCRD_H
#define WZNMWRSRVCRD_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvCrd {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvCrd* dpchinv);
	// IP cust --- IBEGIN

	void writeCrdH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMCard* car, const std::string& Prjshort);
	void writeCrdCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMCard* car, std::vector<std::string>& bitsEval, std::vector<std::string>& rulesEval, std::vector<std::string>& exprsEval, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif


