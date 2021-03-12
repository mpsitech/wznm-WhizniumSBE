/**
	* \file WznmCtpGenuiAcv.cpp
	* Wznm operation processor - prettify file card and add upload/download dialogs (implementation)
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

#include "WznmCtpGenuiAcv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenui;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenuiAcv
 ******************************************************************************/

DpchRetWznmCtpGenui* WznmCtpGenuiAcv::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenui* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	bool uld = false;

	if (uld) {
		// add create file dialog DlgXxxxFilNew
		// cf. IexWznmUix_plnr DlgPlnrFilNew
	};

	// add download dialog DlgXxxxFilDownload
	// cf. IexWznmUix_plnr DlgPlnrFilDownload
	// IP run --- IEND

	return(new DpchRetWznmCtpGenui("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
