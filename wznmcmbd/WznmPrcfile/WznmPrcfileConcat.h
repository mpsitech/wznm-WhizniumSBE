/**
	* \file WznmPrcfileConcat.h
	* Wznm operation processor - concatenate text from multiple input files into output file (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMPRCFILECONCAT_H
#define WZNMPRCFILECONCAT_H

#include "WznmPrcfile.h"

// IP include.cust --- INSERT

namespace WznmPrcfileConcat {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmPrcfileConcat* dpchinv);
	// IP cust --- INSERT
};

#endif



