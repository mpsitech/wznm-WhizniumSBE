/**
	* \file WznmWrdbsDiffsql.cpp
	* Wznm operation processor - write database SQL code for version migration (implementation)
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

#include "WznmWrdbsDiffsql.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrdbs;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrdbsDiffsql
 ******************************************************************************/

DpchRetWznm* WznmWrdbsDiffsql::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrdbsDiffsql* dpchinv
		) {
	ubigint frRefWznmMVersion = dpchinv->frRefWznmMVersion;
	ubigint toRefWznmMVersion = dpchinv->toRefWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

/// determine base version elements: GenDbsdelta

/// write C++ code to transition e.g. to correct vit's: WrdbsMigrate

/// write delta SQL script: WrdbsDeltasql


	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
