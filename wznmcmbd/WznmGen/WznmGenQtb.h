/**
	* \file WznmGenQtb.h
	* Wznm operation processor - generate query tables (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMGENQTB_H
#define WZNMGENQTB_H

#include "WznmGen.h"

// IP include.cust --- INSERT

namespace WznmGenQtb {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenQtb* dpchinv);
	// IP cust --- INSERT
};

#endif
