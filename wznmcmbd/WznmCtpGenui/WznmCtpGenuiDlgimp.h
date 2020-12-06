/**
	* \file WznmCtpGenuiDlgimp.h
	* Wznm operation processor - generate data import dialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCTPGENUIDLGIMP_H
#define WZNMCTPGENUIDLGIMP_H

#include "WznmCtpGenui.h"

// IP include.cust --- INSERT

namespace WznmCtpGenuiDlgimp {

	DpchRetWznmCtpGenui* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenui* dpchinv);
	// IP cust --- INSERT
};

#endif
