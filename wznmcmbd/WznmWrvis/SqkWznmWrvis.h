/**
	* \file SqkWznmWrvis.h
	* squawk generation for operation pack WznmWrvis (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRVIS_H
#define SQKWZNMWRVIS_H

#include "WznmWrvis_blks.h"

/**
	* SqkWznmWrvis
	*/
namespace SqkWznmWrvis {
	std::string getSquawkDbstr(DbsWznm* dbswznm, DpchInvWznmWrvisDbstr* dpchinv);
	std::string getSquawkImpexp(DbsWznm* dbswznm, DpchInvWznmWrvisImpexp* dpchinv);
};

#endif
