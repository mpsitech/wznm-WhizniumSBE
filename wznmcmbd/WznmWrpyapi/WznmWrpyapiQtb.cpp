/**
	* \file WznmWrpyapiQtb.cpp
	* Wznm operation processor - write Python API code for query table (implementation)
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

#include "WznmWrpyapiQtb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrpyapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrpyapiQtb
 ******************************************************************************/

DpchRetWznm* WznmWrpyapiQtb::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrpyapiQtb* dpchinv
		) {
	ubigint refWznmMTable = dpchinv->refWznmMTable;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
