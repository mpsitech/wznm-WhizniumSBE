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

	// --- modify PnlXxxxYyyTerm.js
/*
	outfile << "// IP refreshBD --- RBEGIN" << endl;
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvTerm", "ButClaimOn") == "true");
	refreshTxt(contcontdoc, "TxtCst", retrieveCi(srcdoc, "ContInfWzskLlvTerm", "TxtCst"));

	refreshPup(contcontdoc, srcdoc, "PupCmd", "", "FeedFPupCmd", retrieveCi(srcdoc, "ContIacWzskLlvTerm", "numFPupCmd"), true, false);

	var myelem;

	myelem = contcontdoc.getElementById("TxtDat");
	refreshTxtt(contcontdoc, "TxtDat", retrieveCi(srcdoc, "ContInfWzskLlvTerm", "TxtDatLog"));
	myelem.scrollTop = myelem.scrollHeight;
	
	refreshTxft(contcontdoc, "TxfCsq", retrieveCi(srcdoc, "ContIacWzskLlvTerm", "TxfCsq"), true, false, true);

	refreshBut(contcontdoc, "ButSmt", ButSmtActive, false);
	outfile << "// IP refreshBD --- REND" << endl;
*/

	// --- modify PnlXxxxYyyTerm_bcont.xml
/*
	outfile << "<!-- IP trDat - RBEGIN -->" << endl;
					<td height="200"></td>
					<td id="tdDat" colspan="10" height="200">
						<textarea id="TxtDat" style="resitze:none;font-size:10px;font-family:Monospace;font-weight:normal;width:685px;background-color:#000000;color:#ffffff;border-width:0px;" rows="16" cols="120" type="text" value="TxtDatLog" readonly="readonly"/>
					</td>
	outfile << "<!-- IP trDat - REND -->" << endl;
*/

	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
