/**
	* \file WznmCtpWrwebDbeterm.cpp
	* Wznm operation processor - modify data text field (implementation)
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

#include "WznmCtpWrwebDbeterm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrweb;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpWrwebDbeterm
 ******************************************************************************/

DpchRetWznm* WznmCtpWrwebDbeterm::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpWrweb* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

	// modify PnlXxxxYyyTerm.js
	// cf. webappwzsk/CrdWzskLlv/PnlWzskLlvTerm.js refreshBD

	// modify PnlXxxxYyyTerm_bcont.xml
	// cf. webappwzsk/CrdWzskLlv/PnlWzskLlvTerm_bcont.xml trDat

	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
