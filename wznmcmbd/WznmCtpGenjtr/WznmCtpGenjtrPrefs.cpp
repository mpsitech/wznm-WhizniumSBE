/**
	* \file WznmCtpGenjtrPrefs.cpp
	* Wznm operation processor - modify slider limits (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmCtpGenjtrPrefs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenjtr;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenjtrPrefs
 ******************************************************************************/

DpchRetWznmCtpGenjtr* WznmCtpGenjtrPrefs::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenjtr* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	// modify slider limits
	// IP run --- IEND

	return(new DpchRetWznmCtpGenjtr("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
