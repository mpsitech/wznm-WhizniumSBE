/**
	* \file WznmWrsrvVec.h
	* Wznm operation processor - write C++ code for vector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRSRVVEC_H
#define WZNMWRSRVVEC_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvVec {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvVec* dpchinv);
	// IP cust --- INSERT
};

#endif
