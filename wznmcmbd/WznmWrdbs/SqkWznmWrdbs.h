/**
	* \file SqkWznmWrdbs.h
	* squawk generation for operation pack WznmWrdbs (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRDBS_H
#define SQKWZNMWRDBS_H

#include "WznmWrdbs_blks.h"

/**
	* SqkWznmWrdbs
	*/
namespace SqkWznmWrdbs {
	std::string getSquawkDbs(DbsWznm* dbswznm, DpchInvWznmWrdbsDbs* dpchinv);
	std::string getSquawkDeploy(DbsWznm* dbswznm, DpchInvWznmWrdbsDeploy* dpchinv);
	std::string getSquawkDiffsql(DbsWznm* dbswznm, DpchInvWznmWrdbsDiffsql* dpchinv);
	std::string getSquawkSql(DbsWznm* dbswznm, DpchInvWznmWrdbsSql* dpchinv);
	std::string getSquawkTbl(DbsWznm* dbswznm, DpchInvWznmWrdbsTbl* dpchinv);
};

#endif
