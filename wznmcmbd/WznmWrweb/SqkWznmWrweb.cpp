/**
	* \file SqkWznmWrweb.cpp
	* squawk generation for operation pack WznmWrweb (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWznmWrweb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmWrweb
 ******************************************************************************/

string SqkWznmWrweb::getSquawkBase(
			DbsWznm* dbswznm
			, DpchInvWznmWrwebBase* dpchinv
		) {
	// example: "write web UI JS/HTML code basics for version 'BeamRelay 0.1'"
	return("write web UI JS/HTML code basics for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkBase --- RLINE
};

string SqkWznmWrweb::getSquawkCrd(
			DbsWznm* dbswznm
			, DpchInvWznmWrwebCrd* dpchinv
		) {
	// example: "write web UI JS/HTML code for card 'CrdBrlyLoc'"
	return("write web UI JS/HTML code for card '" + StubWznm::getStubCarStd(dbswznm, dpchinv->refWznmMCard) + "'"); // IP getSquawkCrd --- RLINE
};

string SqkWznmWrweb::getSquawkDeploy(
			DbsWznm* dbswznm
			, DpchInvWznmWrwebDeploy* dpchinv
		) {
	// example: "write web UI deployment scripts for version 'BeamRelay 0.1'"
	return("write web UI deployment scripts for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkDeploy --- RLINE
};

string SqkWznmWrweb::getSquawkDlg(
			DbsWznm* dbswznm
			, DpchInvWznmWrwebDlg* dpchinv
		) {
	// example: "write web UI JS/HTML code for dialog 'DlgBrlyNavLoaini'"
	return(""); // IP getSquawkDlg --- LINE
};

string SqkWznmWrweb::getSquawkPnl(
			DbsWznm* dbswznm
			, DpchInvWznmWrwebPnl* dpchinv
		) {
	// example: "write web UI JS/HTML code for panel 'PnlBrlyLocMap'"
	return("write web UI JS/HTML code for panel '" + StubWznm::getStubPnlStd(dbswznm, dpchinv->refWznmMPanel) + "'"); // IP getSquawkPnl --- RLINE
};



