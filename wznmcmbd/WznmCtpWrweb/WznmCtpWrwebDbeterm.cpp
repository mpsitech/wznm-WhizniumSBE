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
	fstream outfile;

	WznmMCapability* cpb = NULL;

	string hkroot;

	string s;

	if (dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb)) {
		hkroot = cpb->sref.substr(3);

		// --- CrdXxxxYyy/PnlXxxxYyyTerm.js
		s = xchg->tmppath + "/" + folder + "/Crd" + hkroot.substr(0, 4+3) + "/Pnl" + hkroot + ".js.ip";
		outfile.open(s.c_str(), ios::out);

		outfile << "// IP refreshBD --- RBEGIN" << endl;
		outfile << "// IP refreshBD --- BEGIN" << endl;

		outfile << "\trefreshButicon(hdrdoc, \"ButClaim\", \"icon/claim\", ButClaimActive, retrieveCi(srcdoc, \"ContInf" << hkroot << "\", \"ButClaimOn\") == \"true\");" << endl;
		outfile << "\trefreshTxt(contcontdoc, \"TxtCst\", retrieveCi(srcdoc, \"ContInf" << hkroot << "\", \"TxtCst\"));" << endl;
		outfile << endl;

		outfile << "\trefreshPup(contcontdoc, srcdoc, \"PupCmd\", \"\", \"FeedFPupCmd\", retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numFPupCmd\"), true, false);" << endl;
		outfile << endl;

		outfile << "\tvar myelem;" << endl;
		outfile << endl;

		outfile << "\tmyelem = contcontdoc.getElementById(\"TxtDat\");" << endl;
		outfile << "\trefreshTxtt(contcontdoc, \"TxtDat\", retrieveCi(srcdoc, \"ContInf" << hkroot << "\", \"TxtDatLog\"));" << endl;
		outfile << "\tmyelem.scrollTop = myelem.scrollHeight;" << endl;
		outfile << endl;
		
		outfile << "\trefreshTxft(contcontdoc, \"TxfCsq\", retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"TxfCsq\"), true, false, true);" << endl;
		outfile << endl;

		outfile << "\trefreshBut(contcontdoc, \"ButSmt\", ButSmtActive, false);" << endl;

		outfile << "// IP refreshBD --- END" << endl;
		outfile << "// IP refreshBD --- REND" << endl;

		outfile.close();

		// --- CrdXxxxYyy/PnlXxxxYyyTerm_bcont.xml
		s = xchg->tmppath + "/" + folder + "/Crd" + hkroot.substr(0, 4+3) + "/Pnl" + hkroot + "_bcont.xml.ip";
		outfile.open(s.c_str(), ios::out);

		outfile << "<!-- IP trDat - RBEGIN -->" << endl;
		outfile << "<!-- IP trDat - BEGIN -->" << endl;

		outfile << "\t\t\t\t\t<td height=\"200\"></td>" << endl;
		outfile << "\t\t\t\t\t<td id=\"tdDat\" colspan=\"10\" height=\"200\">" << endl;
		outfile << "\t\t\t\t\t\t<textarea id=\"TxtDat\" style=\"resitze:none;font-size:10px;font-family:Monospace;font-weight:normal;width:685px;background-color:#000000;color:#ffffff;border-width:0px;\" rows=\"16\" cols=\"120\" type=\"text\" value=\"TxtDatLog\" readonly=\"readonly\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "<!-- IP trDat - END -->" << endl;
		outfile << "<!-- IP trDat - REND -->" << endl;

		outfile.close();
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
