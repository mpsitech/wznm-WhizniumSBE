/**
	* \file WznmCtpGenjtrDbeterm.h
	* Wznm operation processor - connect source job to terminal panel (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPGENJTRDBETERM_H
#define WZNMCTPGENJTRDBETERM_H

#include "WznmCtpGenjtr.h"

// IP include.cust --- INSERT

namespace WznmCtpGenjtrDbeterm {

	DpchRetWznmCtpGenjtr* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenjtr* dpchinv);
	// IP cust --- INSERT
};

#endif
