/**
	* \file SqkWznmComplvis.h
	* squawk generation for operation pack WznmComplvis (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef SQKWZNMCOMPLVIS_H
#define SQKWZNMCOMPLVIS_H

#include "WznmComplvis_blks.h"

/**
	* SqkWznmComplvis
	*/
namespace SqkWznmComplvis {
	std::string getSquawkDbstr(DbsWznm* dbswznm, DpchInvWznmComplvisDbstr* dpchinv);
	std::string getSquawkImpexp(DbsWznm* dbswznm, DpchInvWznmComplvisImpexp* dpchinv);
};

#endif
