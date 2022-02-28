/**
	* \file WznmWrsapiVec.h
	* Wznm operation processor - write Swift code for vector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSAPIVEC_H
#define WZNMWRSAPIVEC_H

#include "WznmWrsapi.h"

// IP include.cust --- INSERT

namespace WznmWrsapiVec {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsapiVec* dpchinv);
	// IP cust --- INSERT
};

#endif
