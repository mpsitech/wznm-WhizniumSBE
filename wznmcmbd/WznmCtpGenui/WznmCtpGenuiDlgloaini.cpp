/**
	* \file WznmCtpGenuiDlgloaini.cpp
	* Wznm operation processor - generate initialization load dialog (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmCtpGenuiDlgloaini.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenui;

/******************************************************************************
 namespace WznmCtpGenuiDlgloaini
 ******************************************************************************/

DpchRetWznmCtpGenui* WznmCtpGenuiDlgloaini::run(
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

