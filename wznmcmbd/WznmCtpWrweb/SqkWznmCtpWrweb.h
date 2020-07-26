/**
	* \file SqkWznmCtpWrweb.h
	* squawk generation for operation pack WznmCtpWrweb (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWZNMCTPWRWEB_H
#define SQKWZNMCTPWRWEB_H

#include "WznmCtpWrweb_blks.h"

/**
	* SqkWznmCtpWrweb
	*/
namespace SqkWznmCtpWrweb {
	std::string getSquawk(DbsWznm* dbswznm, DpchInvWznmCtpWrweb* dpchinv);
};

#endif

