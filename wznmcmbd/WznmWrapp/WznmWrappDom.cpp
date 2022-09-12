/**
	* \file WznmWrappDom.cpp
	* Wznm operation processor - write DOM code for accessor app (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrappDom.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapp;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrappDom
 ******************************************************************************/

DpchRetWznm* WznmWrappDom::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrappDom* dpchinv
		) {
	ubigint refWznmMApp = dpchinv->refWznmMApp;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
