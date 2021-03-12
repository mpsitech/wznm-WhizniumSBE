/**
	* \file WznmCtpGenuiClustmgr.cpp
	* Wznm operation processor - add system control panels and launch dialogs (implementation)
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

#include "WznmCtpGenuiClustmgr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenui;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenuiClustmgr
 ******************************************************************************/

DpchRetWznmCtpGenui* WznmCtpGenuiClustmgr::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenui* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	bool aws = false;
	bool azure = false;

	// add monitoring panel PnlXxxxCmgMonitor
	// cf. IexWznmUix_plnr PnlPlnrSctMonitor

	// add formation panel PnlXxxxCmgForm
	// cf. IexWznmUix_plnr PnlPlnrSctForm

	// add cluster panel PnlXxxxCmgClust
	// cf. IexWznmUix_plnr PnlPlnrSctClust

	if (aws) {
		// add Amazon aws panel PnlXxxxCmgAws
		// cf. IexWznmUix_plnr PnlPlnrSctAws

		// add aws instance launch dialog DlgXxxxCmgAwslaunch
		// cf. IexWznmUix_plnr DlgPlnrSctAwslaunch

		// add aws spot instance launch dialog DlgXxxxCmgAwsspot
		// cf. IexWznmUix_plnr DlgPlnrSctAwsspot
	};

	if (azure) {
		// add Microsoft Azure panel PnlXxxxCmgAzure
		// cf. IexWznmUix_plnr PnlPlnrSctAzure

		// add Azure instance launch dialog DlgXxxxCmgAzlaunch
		// no example so far
	};
	// IP run --- IEND

	return(new DpchRetWznmCtpGenui("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
