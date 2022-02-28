/**
	* \file SqkWznmWrsapi.h
	* squawk generation for operation pack WznmWrsapi (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRSAPI_H
#define SQKWZNMWRSAPI_H

#include "WznmWrsapi_blks.h"

/**
	* SqkWznmWrsapi
	*/
namespace SqkWznmWrsapi {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrsapiBase* dpchinv);
	std::string getSquawkJob(DbsWznm* dbswznm, DpchInvWznmWrsapiJob* dpchinv);
	std::string getSquawkQtb(DbsWznm* dbswznm, DpchInvWznmWrsapiQtb* dpchinv);
	std::string getSquawkVec(DbsWznm* dbswznm, DpchInvWznmWrsapiVec* dpchinv);
};

#endif
