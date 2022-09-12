/**
	* \file WznmWrcsapiBase.cpp
	* Wznm operation processor - write C# API code basics (implementation)
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

#include "WznmWrcsapiBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrcsapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrcsapiBase
 ******************************************************************************/

DpchRetWznm* WznmWrcsapiBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrcsapiBase* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
