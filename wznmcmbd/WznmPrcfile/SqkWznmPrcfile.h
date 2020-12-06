/**
	* \file SqkWznmPrcfile.h
	* squawk generation for operation pack WznmPrcfile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWZNMPRCFILE_H
#define SQKWZNMPRCFILE_H

#include "WznmPrcfile_blks.h"

/**
	* SqkWznmPrcfile
	*/
namespace SqkWznmPrcfile {
	std::string getSquawkConcat(DbsWznm* dbswznm, DpchInvWznmPrcfileConcat* dpchinv);
	std::string getSquawkPlhrpl(DbsWznm* dbswznm, DpchInvWznmPrcfilePlhrpl* dpchinv);
};

#endif
