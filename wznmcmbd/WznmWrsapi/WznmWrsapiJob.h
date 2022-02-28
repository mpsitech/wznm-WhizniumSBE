/**
	* \file WznmWrsapiJob.h
	* Wznm operation processor - write Swift API code for job (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSAPIJOB_H
#define WZNMWRSAPIJOB_H

#include "WznmWrsapi.h"

// IP include.cust --- INSERT

namespace WznmWrsapiJob {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsapiJob* dpchinv);
	// IP cust --- INSERT
};

#endif
