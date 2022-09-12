/**
	* \file SqkWznmWrcsapi.h
	* squawk generation for operation pack WznmWrcsapi (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRCSAPI_H
#define SQKWZNMWRCSAPI_H

#include "WznmWrcsapi_blks.h"

/**
	* SqkWznmWrcsapi
	*/
namespace SqkWznmWrcsapi {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrcsapiBase* dpchinv);
	std::string getSquawkJob(DbsWznm* dbswznm, DpchInvWznmWrcsapiJob* dpchinv);
	std::string getSquawkQtb(DbsWznm* dbswznm, DpchInvWznmWrcsapiQtb* dpchinv);
	std::string getSquawkVec(DbsWznm* dbswznm, DpchInvWznmWrcsapiVec* dpchinv);
};

#endif
