/**
	* \file SqkWznmWrjapi.h
	* squawk generation for operation pack WznmWrjapi (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWZNMWRJAPI_H
#define SQKWZNMWRJAPI_H

#include "WznmWrjapi_blks.h"

/**
	* SqkWznmWrjapi
	*/
namespace SqkWznmWrjapi {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrjapiBase* dpchinv);
	std::string getSquawkJob(DbsWznm* dbswznm, DpchInvWznmWrjapiJob* dpchinv);
	std::string getSquawkQtb(DbsWznm* dbswznm, DpchInvWznmWrjapiQtb* dpchinv);
	std::string getSquawkVec(DbsWznm* dbswznm, DpchInvWznmWrjapiVec* dpchinv);
};

#endif

