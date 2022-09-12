/**
	* \file WznmWrpyapiJob.cpp
	* Wznm operation processor - write Python API code for job (implementation)
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

#include "WznmWrpyapiJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrpyapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrpyapiJob
 ******************************************************************************/

DpchRetWznm* WznmWrpyapiJob::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrpyapiJob* dpchinv
		) {
	ubigint refWznmMComponent = dpchinv->refWznmMComponent;
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string orgweb = dpchinv->orgweb;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
