/**
	* \file WznmWrjapiVec.h
	* Wznm operation processor - write Java code for vector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRJAPIVEC_H
#define WZNMWRJAPIVEC_H

#include "WznmWrjapi.h"

// IP include.cust --- INSERT

namespace WznmWrjapiVec {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrjapiVec* dpchinv);
	// IP cust --- IBEGIN

	void writeJobJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, const ListWznmMVector& vecs, const ListWznmMBlock& blks, const std::string& orgweb, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif



