/**
	* \file WznmWrdbsDiffsql.h
	* Wznm operation processor - write database SQL code for version migration (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRDBSDIFFSQL_H
#define WZNMWRDBSDIFFSQL_H

#include "WznmWrdbs.h"

// IP include.cust --- INSERT

namespace WznmWrdbsDiffsql {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrdbsDiffsql* dpchinv);
	// IP cust --- INSERT
};

#endif
