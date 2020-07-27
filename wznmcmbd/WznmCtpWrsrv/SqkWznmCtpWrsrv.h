/**
	* \file SqkWznmCtpWrsrv.h
	* squawk generation for operation pack WznmCtpWrsrv (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWZNMCTPWRSRV_H
#define SQKWZNMCTPWRSRV_H

#include "WznmCtpWrsrv_blks.h"

/**
	* SqkWznmCtpWrsrv
	*/
namespace SqkWznmCtpWrsrv {
	std::string getSquawk(DbsWznm* dbswznm, DpchInvWznmCtpWrsrv* dpchinv);
};

#endif
