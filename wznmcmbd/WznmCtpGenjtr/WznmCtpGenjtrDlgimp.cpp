/**
	* \file WznmCtpGenjtrDlgimp.cpp
	* Wznm operation processor - add stages to data import dialog (implementation)
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

#include "WznmCtpGenjtrDlgimp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenjtr;

/******************************************************************************
 namespace WznmCtpGenjtrDlgimp
 ******************************************************************************/

DpchRetWznmCtpGenjtr* WznmCtpGenjtrDlgimp::run(
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



