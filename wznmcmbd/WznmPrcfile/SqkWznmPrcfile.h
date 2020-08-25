/**
	* \file SqkWznmPrcfile.h
	* squawk generation for operation pack WznmPrcfile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef SQKWZNMPRCFILE_H
#define SQKWZNMPRCFILE_H

#include "WznmPrcfile_blks.h"

/**
	* SqkWznmPrcfile
	*/
namespace SqkWznmPrcfile {
	std::string getSquawkConcat(DbsWznm* dbswznm, DpchInvWznmPrcfileConcat* dpchinv);
	std::string getSquawkIexconv(DbsWznm* dbswznm, DpchInvWznmPrcfileIexconv* dpchinv);
	std::string getSquawkPlhrpl(DbsWznm* dbswznm, DpchInvWznmPrcfilePlhrpl* dpchinv);
};

#endif

