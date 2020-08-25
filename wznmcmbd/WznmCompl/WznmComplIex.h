/**
	* \file WznmComplIex.h
	* Wznm operation processor - complement import/export structure (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMCOMPLIEX_H
#define WZNMCOMPLIEX_H

#include "WznmCompl.h"

// IP include.cust --- INSERT

namespace WznmComplIex {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplIex* dpchinv);
	// IP cust --- INSERT
};

#endif

