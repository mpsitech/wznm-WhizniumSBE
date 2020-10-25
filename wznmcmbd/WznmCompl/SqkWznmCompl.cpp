/**
	* \file SqkWznmCompl.cpp
	* squawk generation for operation pack WznmCompl (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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


