/**
	* \file WznmCtpGenjtrClustmgr.cpp
	* Wznm operation processor - add state machines to launch dialogs (implementation)
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

#include "WznmCtpGenjtrClustmgr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenjtr;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenjtrClustmgr
 ******************************************************************************/

DpchRetWznmCtpGenjtr* WznmCtpGenjtrClustmgr::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenjtr* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	bool aws = false;
	bool azure = false;

	if (aws) {
		// add state machine to DlgXxxxCmgAwslaunch
		// cf. IexWznmJtr_plnr DlgPlnrSctAwslaunch

		// add state machine to DlgXxxxCmgAwsspot
		// cf. IexWznmJtr_plnr DlgPlnrSctAwsspot
	};

	if (azure) {
		// add state machine to DlgXxxxCmgAzlaunch
		// no example so far
	};
	// IP run --- IEND

	return(new DpchRetWznmCtpGenjtr("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
