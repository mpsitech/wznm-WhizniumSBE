/**
	* \file SqkWznmCompl.h
	* squawk generation for operation pack WznmCompl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef SQKWZNMCOMPL_H
#define SQKWZNMCOMPL_H

#include "WznmCompl_blks.h"

/**
	* SqkWznmCompl
	*/
namespace SqkWznmCompl {
	std::string getSquawkBscui(DbsWznm* dbswznm, DpchInvWznmComplBscui* dpchinv);
	std::string getSquawkDbs(DbsWznm* dbswznm, DpchInvWznmComplDbs* dpchinv);
	std::string getSquawkIex(DbsWznm* dbswznm, DpchInvWznmComplIex* dpchinv);
	std::string getSquawkJtr(DbsWznm* dbswznm, DpchInvWznmComplJtr* dpchinv);
};

#endif

