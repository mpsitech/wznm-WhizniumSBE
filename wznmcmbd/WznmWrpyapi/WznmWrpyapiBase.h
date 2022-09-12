/**
	* \file WznmWrpyapiBase.h
	* Wznm operation processor - write Python API code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRPYAPIBASE_H
#define WZNMWRPYAPIBASE_H

#include "WznmWrpyapi.h"

// IP include.cust --- INSERT

namespace WznmWrpyapiBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrpyapiBase* dpchinv);
	// IP cust --- INSERT
};

#endif
