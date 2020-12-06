/**
	* \file WznmComplIex.h
	* Wznm operation processor - complement import/export structure (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCOMPLIEX_H
#define WZNMCOMPLIEX_H

#include "WznmCompl.h"

// IP include.cust --- INSERT

namespace WznmComplIex {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplIex* dpchinv);
	// IP cust --- INSERT
};

#endif
