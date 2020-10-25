/**
	* \file WznmCtpGenuiDlgimp.cpp
	* Wznm operation processor - generate data import dialog (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmCtpGenuiDlgimp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenui;

/******************************************************************************
 namespace WznmCtpGenuiDlgimp
 ******************************************************************************/

DpchRetWznmCtpGenui* WznmCtpGenuiDlgimp::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenui* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- INSERT

	return(new DpchRetWznmCtpGenui("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT

