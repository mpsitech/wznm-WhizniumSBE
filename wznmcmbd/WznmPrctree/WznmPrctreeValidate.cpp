/**
	* \file WznmPrctreeValidate.cpp
	* Wznm operation processor - validate file tree (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmPrctreeValidate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmPrctree;

/******************************************************************************
 namespace WznmPrctreeValidate
 ******************************************************************************/

DpchRetWznm* WznmPrctreeValidate::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznm* dpchinv
		) {
	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
/*
void xyz() {
	// general test: check if all opening IP's have closing IP's and vv.
};

void xyz() {
	// equivalent trees: check if diff only within IP's
};

void xyz() {
	// merge / tpl and ext trees: check if for each ext file & ip there is a tpl file & ip
};
*/
// IP cust --- IEND



