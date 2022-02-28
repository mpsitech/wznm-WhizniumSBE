/**
	* \file WznmWrsapiQtb.cpp
	* Wznm operation processor - write Swift API code for query table (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsapiQtb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsapiQtb
 ******************************************************************************/

DpchRetWznm* WznmWrsapiQtb::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsapiQtb* dpchinv
		) {
	ubigint refWznmMTable = dpchinv->refWznmMTable;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
