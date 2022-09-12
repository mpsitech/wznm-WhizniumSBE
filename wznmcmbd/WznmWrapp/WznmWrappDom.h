/**
	* \file WznmWrappDom.h
	* Wznm operation processor - write DOM code for accessor app (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRAPPDOM_H
#define WZNMWRAPPDOM_H

#include "WznmWrapp.h"

// IP include.cust --- INSERT

namespace WznmWrappDom {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrappDom* dpchinv);
	// IP cust --- INSERT
};

#endif
