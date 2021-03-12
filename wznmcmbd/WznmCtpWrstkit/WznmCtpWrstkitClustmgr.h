/**
	* \file WznmCtpWrstkitClustmgr.h
	* Wznm operation processor - basic UI (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSTKITCLUSTMGR_H
#define WZNMCTPWRSTKITCLUSTMGR_H

#include "WznmCtpWrstkit.h"

// IP include.cust --- INSERT

namespace WznmCtpWrstkitClustmgr {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrstkit* dpchinv);
	// IP cust --- INSERT
};

#endif
