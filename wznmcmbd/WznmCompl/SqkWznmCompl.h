/**
	* \file SqkWznmCompl.h
	* squawk generation for operation pack WznmCompl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWZNMCOMPL_H
#define SQKWZNMCOMPL_H

#include "WznmCompl_blks.h"

/**
	* SqkWznmCompl
	*/
namespace SqkWznmCompl {
	std::string getSquawkBscui(DbsWznm* dbswznm, DpchInvWznmComplBscui* dpchinv);
	std::string getSquawkDbs(DbsWznm* dbswznm, DpchInvWznmComplDbs* dpchinv);
	std::string getSquawkDeploy(DbsWznm* dbswznm, DpchInvWznmComplDeploy* dpchinv);
	std::string getSquawkIex(DbsWznm* dbswznm, DpchInvWznmComplIex* dpchinv);
	std::string getSquawkJtr(DbsWznm* dbswznm, DpchInvWznmComplJtr* dpchinv);
};

#endif



