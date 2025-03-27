/**
	* \file WznmComplvisImpexp.h
	* Wznm operation processor - complement visualization features (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMCOMPLVISIMPEXP_H
#define WZNMCOMPLVISIMPEXP_H

#include "WznmComplvis.h"

// IP include.cust --- INSERT

namespace WznmComplvisImpexp {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplvisImpexp* dpchinv);
	// IP cust --- INSERT
};

#endif
