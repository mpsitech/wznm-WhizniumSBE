/**
	* \file WznmWrsrvPref.h
	* Wznm operation processor - write/update preferences file (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRSRVPREF_H
#define WZNMWRSRVPREF_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvPref {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvPref* dpchinv);
	// IP cust --- INSERT
};

#endif

