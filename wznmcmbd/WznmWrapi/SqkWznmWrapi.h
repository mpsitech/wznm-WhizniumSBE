/**
	* \file SqkWznmWrapi.h
	* squawk generation for operation pack WznmWrapi (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRAPI_H
#define SQKWZNMWRAPI_H

#include "WznmWrapi_blks.h"

/**
	* SqkWznmWrapi
	*/
namespace SqkWznmWrapi {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrapiBase* dpchinv);
	std::string getSquawkDeploy(DbsWznm* dbswznm, DpchInvWznmWrapiDeploy* dpchinv);
	std::string getSquawkJob(DbsWznm* dbswznm, DpchInvWznmWrapiJob* dpchinv);
	std::string getSquawkQtb(DbsWznm* dbswznm, DpchInvWznmWrapiQtb* dpchinv);
};

#endif
