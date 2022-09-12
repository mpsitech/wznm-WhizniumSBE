/**
	* \file WznmWrpyapiJob.h
	* Wznm operation processor - write Python API code for job (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRPYAPIJOB_H
#define WZNMWRPYAPIJOB_H

#include "WznmWrpyapi.h"

// IP include.cust --- INSERT

namespace WznmWrpyapiJob {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrpyapiJob* dpchinv);
	// IP cust --- INSERT
};

#endif
