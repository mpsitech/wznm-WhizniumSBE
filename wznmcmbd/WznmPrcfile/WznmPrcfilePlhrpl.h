/**
	* \file WznmPrcfilePlhrpl.h
	* Wznm operation processor - replace placeholders in template file and write into output file (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMPRCFILEPLHRPL_H
#define WZNMPRCFILEPLHRPL_H

#include "WznmPrcfile.h"

// IP include.cust --- INSERT

namespace WznmPrcfilePlhrpl {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmPrcfilePlhrpl* dpchinv);
	// IP cust --- INSERT
};

#endif
