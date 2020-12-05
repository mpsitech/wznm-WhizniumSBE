/**
	* \file WznmWrwebDeploy.h
	* Wznm operation processor - write web UI deployment scripts (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRWEBDEPLOY_H
#define WZNMWRWEBDEPLOY_H

#include "WznmWrweb.h"

// IP include.cust --- INSERT

namespace WznmWrwebDeploy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrwebDeploy* dpchinv);
	// IP cust --- INSERT
};

#endif



