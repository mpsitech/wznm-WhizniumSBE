/**
	* \file WznmCtpGenjtrAcv.cpp
	* Wznm operation processor - add stages to upload dialog (implementation)
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

#include "WznmCtpGenjtrAcv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenjtr;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenjtrAcv
 ******************************************************************************/

DpchRetWznmCtpGenjtr* WznmCtpGenjtrAcv::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenjtr* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	bool uld = false;

	// prettify file list PnlXxxxFilList
	// cf. IexWznmJtr_plnr PnlPlnrFilList

	if (uld) {
		// add state machine to DlgXxxxFilNew
		// cf. IexWznmJtr_plnr DlgPlnrFilNew
	};
	// IP run --- IEND

	return(new DpchRetWznmCtpGenjtr("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
