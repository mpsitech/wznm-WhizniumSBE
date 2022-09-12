/**
	* \file WznmWrcsapiBase.h
	* Wznm operation processor - write C# API code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRCSAPIBASE_H
#define WZNMWRCSAPIBASE_H

#include "WznmWrcsapi.h"

// IP include.cust --- INSERT

namespace WznmWrcsapiBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrcsapiBase* dpchinv);
	// IP cust --- INSERT
};

#endif
