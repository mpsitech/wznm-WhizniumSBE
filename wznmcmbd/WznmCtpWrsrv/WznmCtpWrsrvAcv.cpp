/**
	* \file WznmCtpWrsrvAcv.cpp
	* Wznm operation processor - implement upload/download dialogs (implementation)
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

#include "WznmCtpWrsrvAcv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpWrsrvAcv
 ******************************************************************************/

DpchRetWznm* WznmCtpWrsrvAcv::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpWrsrv* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	bool uld = false;

	if (uld) {
		// modify DlgXxxxFilNew.h
		// cf. wznmcmbd/CrdWznmFil/DlgWznmFilNew.h vars.cust

		// modify DlgXxxxFilNew.cpp
		// cf. wznmcmbd/CrdWznmFil/DlgWznmFilNew.cpp handleDpchAppDataContiacdet, handleDpchAppDoButDneClick, enterSgeCreate, enterSgeDone
	};

	// modify DlgXxxxFilDownload.cpp
	// cf. wznmcmbd/CrdWznmFil/DlgWznmFilDownload.cpp refresh, handleDpchAppDoButDneClick, handleDownload

	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
