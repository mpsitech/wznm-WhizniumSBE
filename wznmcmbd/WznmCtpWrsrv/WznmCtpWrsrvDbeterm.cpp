/**
	* \file WznmCtpWrsrvDbeterm.cpp
	* Wznm operation processor - implement terminal panel (implementation)
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

#include "WznmCtpWrsrvDbeterm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpWrsrvDbeterm
 ******************************************************************************/

DpchRetWznm* WznmCtpWrsrvDbeterm::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpWrsrv* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

	// modify PnlXxxxYyyTerm.h
	// cf. wzskcmbd/CrdWzskLlv/PnlWzskLlvTerm.h vars.cust, cust

	// modify PnlXxxxYyyTerm.cpp
	// cf. wzskcmbd/CrdWzskLlv/PnlWzskLlvTerm.h ns.cust, constructor.cust2, cust, refresh, handleDpchAppDataContiac, handleDpchAppDoButApdClick, handleDpchAppDoButSmtClick

	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
