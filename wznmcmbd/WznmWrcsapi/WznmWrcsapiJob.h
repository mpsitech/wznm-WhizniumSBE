/**
	* \file WznmWrcsapiJob.h
	* Wznm operation processor - write C# API code for job (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRCSAPIJOB_H
#define WZNMWRCSAPIJOB_H

#include "WznmWrcsapi.h"

// IP include.cust --- INSERT

namespace WznmWrcsapiJob {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrcsapiJob* dpchinv);
	// IP cust --- INSERT
};

#endif
