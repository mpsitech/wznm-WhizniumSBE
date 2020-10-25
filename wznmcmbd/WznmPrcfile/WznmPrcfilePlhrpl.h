/**
	* \file WznmPrcfilePlhrpl.h
	* Wznm operation processor - replace placeholders in template file and write into output file (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMPRCFILEPLHRPL_H
#define WZNMPRCFILEPLHRPL_H

#include "WznmPrcfile.h"

// IP include.cust --- INSERT

namespace WznmPrcfilePlhrpl {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmPrcfilePlhrpl* dpchinv);
	// IP cust --- INSERT
};

#endif

