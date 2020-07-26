/**
	* \file SqkWznmWrdbs.cpp
	* squawk generation for operation pack WznmWrdbs (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "SqkWznmWrdbs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmWrdbs
 ******************************************************************************/

string SqkWznmWrdbs::getSquawkDbs(
			DbsWznm* dbswznm
			, DpchInvWznmWrdbsDbs* dpchinv
		) {
	// example: "write database access library C++ code for version 'BeamRelay 0.1'"
	return("write database access library C++ code for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkDbs --- RLINE
};

string SqkWznmWrdbs::getSquawkDeploy(
			DbsWznm* dbswznm
			, DpchInvWznmWrdbsDeploy* dpchinv
		) {
	// example: "write database access library deployment scripts for release 'DbsBrly_genio'"
	return("write database access library deployment scripts for release '" + StubWznm::getStubRlsStd(dbswznm, dpchinv->refWznmMRelease) + "'"); // IP getSquawkDeploy --- RLINE
};

string SqkWznmWrdbs::getSquawkDiffsql(
			DbsWznm* dbswznm
			, DpchInvWznmWrdbsDiffsql* dpchinv
		) {
	// example: "write database SQL code for migration from version 'BeamRelay 0.1' to version 'BeamRelay 0.2'"
	return(""); // IP getSquawkDiffsql --- LINE
};

string SqkWznmWrdbs::getSquawkSql(
			DbsWznm* dbswznm
			, DpchInvWznmWrdbsSql* dpchinv
		) {
	// example: "write database create SQL code for version 'BeamRelay 0.1'"
	return("write database create SQL code for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkSql --- RLINE
};

string SqkWznmWrdbs::getSquawkTbl(
			DbsWznm* dbswznm
			, DpchInvWznmWrdbsTbl* dpchinv
		) {
	// example: "write database access library C++ code for table 'TblBrlyMLocation'"
	return("write database access library C++ code for table '" + StubWznm::getStubTblStd(dbswznm, dpchinv->refWznmMTable) + "'"); // IP getSquawkTbl --- RLINE
};


