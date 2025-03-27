/**
	* \file WznmCtpWrsrvDbeterm.h
	* Wznm operation processor - implement terminal panel (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSRVDBETERM_H
#define WZNMCTPWRSRVDBETERM_H

#include "WznmCtpWrsrv.h"

// IP include.cust --- INSERT

namespace WznmCtpWrsrvDbeterm {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrsrv* dpchinv);
	// IP cust --- IBEGIN
	void writeCpbH(std::fstream& outfile, const std::string& Untsref);
	void writeCpbCpp(std::fstream& outfile, const std::string& Prjshort, const std::string& Cpbsref, const std::string& Untsref, const std::string& srcjobshort);
	// IP cust --- IEND
};

#endif
