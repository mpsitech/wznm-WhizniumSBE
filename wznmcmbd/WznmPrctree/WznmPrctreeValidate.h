/**
	* \file WznmPrctreeValidate.h
	* Wznm operation processor - validate file tree (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMPRCTREEVALIDATE_H
#define WZNMPRCTREEVALIDATE_H

#include "WznmPrctree.h"

// IP include.cust --- INSERT

namespace WznmPrctreeValidate {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznm* dpchinv);
	// IP cust --- INSERT
};

#endif
