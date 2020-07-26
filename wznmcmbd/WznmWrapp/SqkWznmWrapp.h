/**
	* \file SqkWznmWrapp.h
	* squawk generation for operation pack WznmWrapp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWZNMWRAPP_H
#define SQKWZNMWRAPP_H

#include "WznmWrapp_blks.h"

/**
	* SqkWznmWrapp
	*/
namespace SqkWznmWrapp {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrappBase* dpchinv);
	std::string getSquawkJbase(DbsWznm* dbswznm, DpchInvWznmWrappJbase* dpchinv);
};

#endif

