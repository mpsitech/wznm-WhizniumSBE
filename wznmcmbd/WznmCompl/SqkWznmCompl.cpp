/**
	* \file SqkWznmCompl.cpp
	* squawk generation for operation pack WznmCompl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWznmCompl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmCompl
 ******************************************************************************/

string SqkWznmCompl::getSquawkBscui(
			DbsWznm* dbswznm
			, DpchInvWznmComplBscui* dpchinv
		) {
	// example: "complement basic user interface for version 'BeamRelay 0.1'"
	return("complement basic user interface for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkBscui --- RLINE
};

string SqkWznmCompl::getSquawkDbs(
			DbsWznm* dbswznm
			, DpchInvWznmComplDbs* dpchinv
		) {
	// example: "complement database structure for version 'BeamRelay 0.1'"
	return("complement database structure for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkDbs --- RLINE
};

string SqkWznmCompl::getSquawkDeploy(
			DbsWznm* dbswznm
			, DpchInvWznmComplDeploy* dpchinv
		) {
	// example: "complement deployment information for version 'BeamRelay 0.1'"
	return(""); // IP getSquawkDeploy --- LINE
};

string SqkWznmCompl::getSquawkIex(
			DbsWznm* dbswznm
			, DpchInvWznmComplIex* dpchinv
		) {
	// example: "complement import/export structure for version 'BeamRelay 0.1'"
	return("complement import/export structure for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkIex --- RLINE
};

string SqkWznmCompl::getSquawkJtr(
			DbsWznm* dbswznm
			, DpchInvWznmComplJtr* dpchinv
		) {
	// example: "complement job tree for version 'BeamRelay 0.1'"
	return(""); // IP getSquawkJtr --- LINE
};



