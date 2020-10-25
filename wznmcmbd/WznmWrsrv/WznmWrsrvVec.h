/**
	* \file WznmWrsrvVec.h
	* Wznm operation processor - write C++ code for vector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRSRVVEC_H
#define WZNMWRSRVVEC_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvVec {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvVec* dpchinv);
	// IP cust --- INSERT
};

#endif

