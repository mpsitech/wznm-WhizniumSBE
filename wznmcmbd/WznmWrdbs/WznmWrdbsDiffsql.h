/**
	* \file WznmWrdbsDiffsql.h
	* Wznm operation processor - write database SQL code for version migration (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRDBSDIFFSQL_H
#define WZNMWRDBSDIFFSQL_H

#include "WznmWrdbs.h"

// IP include.cust --- INSERT

namespace WznmWrdbsDiffsql {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrdbsDiffsql* dpchinv);
	// IP cust --- INSERT
};

#endif

