/**
	* \file WznmGenQtb.h
	* Wznm operation processor - generate query tables (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMGENQTB_H
#define WZNMGENQTB_H

#include "WznmGen.h"

// IP include.cust --- INSERT

namespace WznmGenQtb {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenQtb* dpchinv);
	// IP cust --- INSERT
};

#endif

