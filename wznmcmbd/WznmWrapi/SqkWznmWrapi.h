/**
	* \file SqkWznmWrapi.h
	* squawk generation for operation pack WznmWrapi (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

