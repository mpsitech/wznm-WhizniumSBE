/**
	* \file WznmWrcsapiQtb.cpp
	* Wznm operation processor - write C# API code for query table (implementation)
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

#include "WznmWrcsapiQtb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrcsapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrcsapiQtb
 ******************************************************************************/

DpchRetWznm* WznmWrcsapiQtb::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrcsapiQtb* dpchinv
		) {
	ubigint refWznmMTable = dpchinv->refWznmMTable;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
