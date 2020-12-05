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

	// IP run --- INSERT

	return(new DpchRetWznmCtpGenjtr("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT



