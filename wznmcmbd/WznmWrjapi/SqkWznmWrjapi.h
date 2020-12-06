/**
	* \file SqkWznmWrjapi.h
	* squawk generation for operation pack WznmWrjapi (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
