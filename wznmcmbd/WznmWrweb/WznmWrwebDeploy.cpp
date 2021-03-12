/**
	* \file WznmWrwebDeploy.cpp
	* Wznm operation processor - write web UI deployment scripts (implementation)
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

#include "WznmWrwebDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrweb;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrwebDeploy
 ******************************************************************************/

DpchRetWznm* WznmWrwebDeploy::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrwebDeploy* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	// copy_Web.sh
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
