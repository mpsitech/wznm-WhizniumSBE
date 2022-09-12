/**
	* \file SqkWznmWrpyapi.h
	* squawk generation for operation pack WznmWrpyapi (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRPYAPI_H
#define SQKWZNMWRPYAPI_H

#include "WznmWrpyapi_blks.h"

/**
	* SqkWznmWrpyapi
	*/
namespace SqkWznmWrpyapi {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrpyapiBase* dpchinv);
	std::string getSquawkJob(DbsWznm* dbswznm, DpchInvWznmWrpyapiJob* dpchinv);
	std::string getSquawkQtb(DbsWznm* dbswznm, DpchInvWznmWrpyapiQtb* dpchinv);
	std::string getSquawkVec(DbsWznm* dbswznm, DpchInvWznmWrpyapiVec* dpchinv);
};

#endif
