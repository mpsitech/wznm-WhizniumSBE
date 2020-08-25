/**
	* \file WznmPrcfileConcat.h
	* Wznm operation processor - concatenate text from multiple input files into output file (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMPRCFILECONCAT_H
#define WZNMPRCFILECONCAT_H

#include "WznmPrcfile.h"

// IP include.cust --- INSERT

namespace WznmPrcfileConcat {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmPrcfileConcat* dpchinv);
	// IP cust --- INSERT
};

#endif

