/**
	* \file WznmWrsrvPref.h
	* Wznm operation processor - write/update preferences file (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRSRVPREF_H
#define WZNMWRSRVPREF_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvPref {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvPref* dpchinv);
	// IP cust --- INSERT
};

#endif



