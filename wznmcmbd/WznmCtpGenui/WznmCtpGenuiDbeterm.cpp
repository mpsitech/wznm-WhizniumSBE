/**
	* \file WznmCtpGenuiDbeterm.cpp
	* Wznm operation processor - add terminal panel (implementation)
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

#include "WznmCtpGenuiDbeterm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenui;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenuiDbeterm
 ******************************************************************************/

DpchRetWznmCtpGenui* WznmCtpGenuiDbeterm::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenui* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	// add terminal panel PnlXxxxYyyTerm
	// cf. IexWznmUix_wzsk PnlWzskLlvTerm
	// IP run --- IEND

	return(new DpchRetWznmCtpGenui("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
