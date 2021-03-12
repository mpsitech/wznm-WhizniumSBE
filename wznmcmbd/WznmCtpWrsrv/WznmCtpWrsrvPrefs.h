/**
	* \file WznmCtpWrsrvPrefs.h
	* Wznm operation processor - implement preferences panels (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSRVPREFS_H
#define WZNMCTPWRSRVPREFS_H

#include "WznmCtpWrsrv.h"

// IP include.cust --- INSERT

namespace WznmCtpWrsrvPrefs {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrsrv* dpchinv);
	// IP cust --- INSERT
};

#endif
