/**
	* \file WznmWrappMain.h
	* Wznm operation processor - write main state machine code for accessor app (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRAPPMAIN_H
#define WZNMWRAPPMAIN_H

#include "WznmWrapp.h"

// IP include.cust --- INSERT

namespace WznmWrappMain {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrappMain* dpchinv);
	// IP cust --- INSERT
};

#endif
