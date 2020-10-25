/**
	* \file SqkWznmCtpWrstkit.h
	* squawk generation for operation pack WznmCtpWrstkit (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef SQKWZNMCTPWRSTKIT_H
#define SQKWZNMCTPWRSTKIT_H

#include "WznmCtpWrstkit_blks.h"

/**
	* SqkWznmCtpWrstkit
	*/
namespace SqkWznmCtpWrstkit {
	std::string getSquawk(DbsWznm* dbswznm, DpchInvWznmCtpWrstkit* dpchinv);
};

#endif

