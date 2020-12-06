/**
	* \file WznmCtpWrsrvDlgimp.h
	* Wznm operation processor - implement data import dialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSRVDLGIMP_H
#define WZNMCTPWRSRVDLGIMP_H

#include "WznmCtpWrsrv.h"

// IP include.cust --- INSERT

namespace WznmCtpWrsrvDlgimp {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrsrv* dpchinv);
	// IP cust --- INSERT
};

#endif
