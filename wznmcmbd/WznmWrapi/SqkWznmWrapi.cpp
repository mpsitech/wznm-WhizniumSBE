/**
	* \file SqkWznmWrapi.cpp
	* squawk generation for operation pack WznmWrapi (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWznmWrapi.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmWrapi
 ******************************************************************************/

string SqkWznmWrapi::getSquawkBase(
			DbsWznm* dbswznm
			, DpchInvWznmWrapiBase* dpchinv
		) {
	// example: "write API code basics for version 'BeamRelay 0.1'"
	return("write C++ API code basics for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkBase --- RLINE
};

string SqkWznmWrapi::getSquawkDeploy(
			DbsWznm* dbswznm
			, DpchInvWznmWrapiDeploy* dpchinv
		) {
	// example: "write API code deployment scripts for release 'AppBrly_genio'"
	return("write API library scripts for release '" + StubWznm::getStubRlsStd(dbswznm, dpchinv->refWznmMRelease) + "'"); // IP getSquawkDeploy --- RLINE
};

string SqkWznmWrapi::getSquawkJob(
			DbsWznm* dbswznm
			, DpchInvWznmWrapiJob* dpchinv
		) {
	// example: "write API code for job 'JobBrlyLocCalc'"
	return("write C++ API code for job '" + StubWznm::getStubJobStd(dbswznm, dpchinv->refWznmMJob) + "'"); // IP getSquawkJob --- RLINE
};

string SqkWznmWrapi::getSquawkQtb(
			DbsWznm* dbswznm
			, DpchInvWznmWrapiQtb* dpchinv
		) {
	// example: "write API code for query table 'TblBrlyQLocList'"
	return("write C++ API code for query table '" + StubWznm::getStubTblStd(dbswznm, dpchinv->refWznmMTable) + "'"); // IP getSquawkQtb --- RLINE
};
