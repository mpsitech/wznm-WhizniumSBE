/**
	* \file WznmCtpWrwebDbeterm.h
	* Wznm operation processor - modify data text field (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRWEBDBETERM_H
#define WZNMCTPWRWEBDBETERM_H

#include "WznmCtpWrweb.h"

// IP include.cust --- INSERT

namespace WznmCtpWrwebDbeterm {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrweb* dpchinv);
	// IP cust --- INSERT
};

#endif
