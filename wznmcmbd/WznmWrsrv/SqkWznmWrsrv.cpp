/**
	* \file SqkWznmWrsrv.cpp
	* squawk generation for operation pack WznmWrsrv (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWznmWrsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmWrsrv
 ******************************************************************************/

string SqkWznmWrsrv::getSquawkBase(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvBase* dpchinv
		) {
	// example: "write server C++ code basics for version 'BeamRelay 0.1'"
	return("write server C++ code basics for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkBase --- RLINE
};

string SqkWznmWrsrv::getSquawkCmbengbase(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvCmbengbase* dpchinv
		) {
	// example: "write combined engine C++ code basics for version 'BeamRelay 0.1'"
	return("write combined engine C++ code basics for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkCmbengbase --- RLINE
};

string SqkWznmWrsrv::getSquawkCrd(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvCrd* dpchinv
		) {
	// example: "write specific job C++ code for card 'CrdBrlyLoc'"
	return("write C++ code for card '" + StubWznm::getStubJobStd(dbswznm, dpchinv->refWznmMJob) + "'"); // IP getSquawkCrd --- RLINE
};

string SqkWznmWrsrv::getSquawkDds(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvDds* dpchinv
		) {
	// example: "write C++ code for DDS publisher for component 'BeamRelay 0.1 combined engine'"
	return(""); // IP getSquawkDds --- LINE
};

string SqkWznmWrsrv::getSquawkDeploy(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvDeploy* dpchinv
		) {
	// example: "write server deployment scripts for release 'Brlyopd_genio'"
	return("write server deployment scripts for release '" + StubWznm::getStubRlsStd(dbswznm, dpchinv->refWznmMRelease) + "'"); // IP getSquawkDeploy --- RLINE
};

string SqkWznmWrsrv::getSquawkDlg(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvDlg* dpchinv
		) {
	// example: "write specific job C++ code for dialog 'DlgBrlyNavLoaini'"
	return(""); // IP getSquawkDlg --- LINE
};

string SqkWznmWrsrv::getSquawkEngbase(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvEngbase* dpchinv
		) {
	// example: "write main engine C++ code basics for version 'BeamRelay 0.1'"
	return("write main engine C++ code basics for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkEngbase --- RLINE
};

string SqkWznmWrsrv::getSquawkIex(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvIex* dpchinv
		) {
	// example: "write C++ code for import/export complex 'IexBrlyIni'"
	return("write C++ code for individual import/export complex '" + StubWznm::getStubJobStd(dbswznm, dpchinv->refWznmMJob) + "'"); // IP getSquawkIex --- RLINE
};

string SqkWznmWrsrv::getSquawkInixml(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvInixml* dpchinv
		) {
	// example: "write initialization XML file for version 'BeamRelay 0.1'"
	return(""); // IP getSquawkInixml --- LINE
};

string SqkWznmWrsrv::getSquawkJob(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvJob* dpchinv
		) {
	// example: "write C++ code for job 'JobBrlyLocCalc'"
	return("write C++ code for job '" + StubWznm::getStubJobStd(dbswznm, dpchinv->refWznmMJob) + "'"); // IP getSquawkJob --- RLINE
};

string SqkWznmWrsrv::getSquawkOp(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvOp* dpchinv
		) {
	// example: "write C++ code for operation 'BrlyBaseLocloc'"
	return("write C++ code for operation '" + StubWznm::getStubOpxStd(dbswznm, dpchinv->refWznmMOp) + "'"); // IP getSquawkOp --- RLINE
};

string SqkWznmWrsrv::getSquawkOpengbase(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvOpengbase* dpchinv
		) {
	// example: "write operation engine C++ code basics for component 'Brlyopd2'"
	return("write operation engine C++ code basics for component '" + StubWznm::getStubCmpStd(dbswznm, dpchinv->refWznmMComponent) + "'"); // IP getSquawkOpengbase --- RLINE
};

string SqkWznmWrsrv::getSquawkOpk(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvOpk* dpchinv
		) {
	// example: "write C++ code for operation pack 'BrlyBase' basics"
	return("write C++ code for operation pack '" + StubWznm::getStubOpkStd(dbswznm, dpchinv->refWznmMOppack) + "' basics"); // IP getSquawkOpk --- RLINE
};

string SqkWznmWrsrv::getSquawkPnl(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvPnl* dpchinv
		) {
	// example: "write specific job C++ code for panel 'PnlBrlyLocMap'"
	return("write C++ code for panel '" + StubWznm::getStubJobStd(dbswznm, dpchinv->refWznmMJob) + "'"); // IP getSquawkPnl --- RLINE
};

string SqkWznmWrsrv::getSquawkPref(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvPref* dpchinv
		) {
	// example: "write/update preferences file for release 'Brlyopd_genio'"
	return(""); // IP getSquawkPref --- LINE
};

string SqkWznmWrsrv::getSquawkQry(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvQry* dpchinv
		) {
	// example: "write specific job C++ code for query 'QryBrlyLocRec'"
	return("write C++ code for query '" + StubWznm::getStubJobStd(dbswznm, dpchinv->refWznmMJob) + "'"); // IP getSquawkQry --- RLINE
};

string SqkWznmWrsrv::getSquawkRootsess(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvRootsess* dpchinv
		) {
	// example: "write specific job C++ code for root and session for version 'BeamRelay 0.1'"
	return("write C++ code for root and session jobs for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkRootsess --- RLINE
};

string SqkWznmWrsrv::getSquawkUa(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvUa* dpchinv
		) {
	// example: "write C++ code for OPC UA server for version 'BeamRelay 0.1'"
	return(""); // IP getSquawkUa --- LINE
};

string SqkWznmWrsrv::getSquawkVec(
			DbsWznm* dbswznm
			, DpchInvWznmWrsrvVec* dpchinv
		) {
	// example: "write C++ code for vector 'VecBrlyVMLocationBasetype'"
	return(""); // IP getSquawkVec --- LINE
};
