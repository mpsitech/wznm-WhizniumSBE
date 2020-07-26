/**
	* \file WznmWrjapiVec.h
	* Wznm operation processor - write Java code for vector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


