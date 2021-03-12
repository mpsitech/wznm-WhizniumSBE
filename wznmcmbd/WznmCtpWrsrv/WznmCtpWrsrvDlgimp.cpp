/**
	* \file WznmCtpWrsrvDlgimp.cpp
	* Wznm operation processor - implement data import dialog (implementation)
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

#include "WznmCtpWrsrvDlgimp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpWrsrvDlgimp
 ******************************************************************************/

DpchRetWznm* WznmCtpWrsrvDlgimp::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpWrsrv* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	// modify DlgXxxxYyyZzzzz.h
	// ...

	// modify DlgXxxxYyyZzzzz.cpp
	// ...
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
