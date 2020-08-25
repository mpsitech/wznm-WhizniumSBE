/**
	* \file WznmPrctreeValidate.h
	* Wznm operation processor - validate file tree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMPRCTREEVALIDATE_H
#define WZNMPRCTREEVALIDATE_H

#include "WznmPrctree.h"

// IP include.cust --- INSERT

namespace WznmPrctreeValidate {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznm* dpchinv);
	// IP cust --- INSERT
};

#endif

