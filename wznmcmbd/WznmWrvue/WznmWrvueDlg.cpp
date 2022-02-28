/**
	* \file WznmWrvueDlg.cpp
	* Wznm operation processor - write Vue.js UI Vue code for dialog (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrvueDlg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrvue;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvueDlg
 ******************************************************************************/

DpchRetWznm* WznmWrvueDlg::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrvueDlg* dpchinv
		) {
	ubigint refWznmMDialog = dpchinv->refWznmMDialog;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
