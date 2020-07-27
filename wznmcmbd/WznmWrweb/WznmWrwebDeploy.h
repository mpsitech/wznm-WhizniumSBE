/**
	* \file WznmWrwebDeploy.h
	* Wznm operation processor - write web UI deployment scripts (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRWEBDEPLOY_H
#define WZNMWRWEBDEPLOY_H

#include "WznmWrweb.h"

// IP include.cust --- INSERT

namespace WznmWrwebDeploy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrwebDeploy* dpchinv);
	// IP cust --- INSERT
};

#endif
