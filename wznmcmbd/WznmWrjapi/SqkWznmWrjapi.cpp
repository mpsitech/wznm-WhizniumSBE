/**
	* \file SqkWznmWrjapi.cpp
	* squawk generation for operation pack WznmWrjapi (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "SqkWznmWrjapi.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmWrjapi
 ******************************************************************************/

string SqkWznmWrjapi::getSquawkBase(
			DbsWznm* dbswznm
			, DpchInvWznmWrjapiBase* dpchinv
		) {
	// example: "write Java API code basics for version 'BeamRelay 0.1'"
	return(""); // IP getSquawkBase --- LINE
};

string SqkWznmWrjapi::getSquawkJob(
			DbsWznm* dbswznm
			, DpchInvWznmWrjapiJob* dpchinv
		) {
	// example: "write Java API code for job 'JobBrlyLocCalc'"
	return(""); // IP getSquawkJob --- LINE
};

string SqkWznmWrjapi::getSquawkQtb(
			DbsWznm* dbswznm
			, DpchInvWznmWrjapiQtb* dpchinv
		) {
	// example: "write Java API code for query table 'TblBrlyQLocList'"
	return(""); // IP getSquawkQtb --- LINE
};

string SqkWznmWrjapi::getSquawkVec(
			DbsWznm* dbswznm
			, DpchInvWznmWrjapiVec* dpchinv
		) {
	// example: "write Java code for vector 'VecBrlyVMLocationBasetype'"
	return(""); // IP getSquawkVec --- LINE
};

