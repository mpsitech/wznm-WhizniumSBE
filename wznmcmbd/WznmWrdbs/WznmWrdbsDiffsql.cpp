/**
	* \file WznmWrdbsDiffsql.cpp
	* Wznm operation processor - write database SQL code for version migration (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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


