/**
	* \file SqkWznmWrapp.h
	* squawk generation for operation pack WznmWrapp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRAPP_H
#define SQKWZNMWRAPP_H

#include "WznmWrapp_blks.h"

/**
	* SqkWznmWrapp
	*/
namespace SqkWznmWrapp {
	std::string getSquawkDom(DbsWznm* dbswznm, DpchInvWznmWrappDom* dpchinv);
	std::string getSquawkMain(DbsWznm* dbswznm, DpchInvWznmWrappMain* dpchinv);
	std::string getSquawkStdvec(DbsWznm* dbswznm, DpchInvWznmWrappStdvec* dpchinv);
};

#endif
