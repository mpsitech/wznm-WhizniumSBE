/**
	* \file SqkWznmGen.cpp
	* squawk generation for operation pack WznmGen (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "SqkWznmGen.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmGen
 ******************************************************************************/

string SqkWznmGen::getSquawkBase(
			DbsWznm* dbswznm
			, DpchInvWznmGenBase* dpchinv
		) {
	// example: "generate version basics for version 'BeamRelay 0.1'"
	return("generate version basics for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkBase --- RLINE
};

string SqkWznmGen::getSquawkCal(
			DbsWznm* dbswznm
			, DpchInvWznmGenCal* dpchinv
		) {
	// example: "generate calls for version 'BeamRelay 0.1'"
	return(""); // IP getSquawkCal --- LINE
};

string SqkWznmGen::getSquawkChk(
			DbsWznm* dbswznm
			, DpchInvWznmGenChk* dpchinv
		) {
	// example: "generate feature checks for version 'BeamRelay 0.1'"
	return(""); // IP getSquawkChk --- LINE
};

string SqkWznmGen::getSquawkDetui(
			DbsWznm* dbswznm
			, DpchInvWznmGenDetui* dpchinv
		) {
	// example: "generate detailed user interface for version 'BeamRelay 0.1'"
	return("generate detailed user interface for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkDetui --- RLINE
};

string SqkWznmGen::getSquawkJob(
			DbsWznm* dbswznm
			, DpchInvWznmGenJob* dpchinv
		) {
	// example: "generate job tree for version 'BeamRelay 0.1'"
	return(""); // IP getSquawkJob --- LINE
};

string SqkWznmGen::getSquawkQtb(
			DbsWznm* dbswznm
			, DpchInvWznmGenQtb* dpchinv
		) {
	// example: "generate query tables for version 'BeamRelay 0.1'"
	return("generate query tables for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkQtb --- RLINE
};

string SqkWznmGen::getSquawkSysvec(
			DbsWznm* dbswznm
			, DpchInvWznmGenSysvec* dpchinv
		) {
	// example: "fill system vectors for version 'BeamRelay 0.1'"
	return("fill system vectors for version '" + StubWznm::getStubVerStd(dbswznm, dpchinv->refWznmMVersion) + "'"); // IP getSquawkSysvec --- RLINE
};


