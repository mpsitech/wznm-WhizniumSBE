/**
	* \file SqkWznmWrdbs.h
	* squawk generation for operation pack WznmWrdbs (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

