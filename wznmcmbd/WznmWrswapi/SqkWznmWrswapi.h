/**
	* \file SqkWznmWrswapi.h
	* squawk generation for operation pack WznmWrswapi (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRSWAPI_H
#define SQKWZNMWRSWAPI_H

#include "WznmWrswapi_blks.h"

/**
	* SqkWznmWrswapi
	*/
namespace SqkWznmWrswapi {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrswapiBase* dpchinv);
	std::string getSquawkJob(DbsWznm* dbswznm, DpchInvWznmWrswapiJob* dpchinv);
	std::string getSquawkQtb(DbsWznm* dbswznm, DpchInvWznmWrswapiQtb* dpchinv);
	std::string getSquawkVec(DbsWznm* dbswznm, DpchInvWznmWrswapiVec* dpchinv);
};

#endif
