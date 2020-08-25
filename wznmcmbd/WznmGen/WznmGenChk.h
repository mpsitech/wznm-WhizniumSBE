/**
	* \file WznmGenChk.h
	* Wznm operation processor - generate feature checks (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMGENCHK_H
#define WZNMGENCHK_H

#include "WznmGen.h"

// IP include.cust --- INSERT

namespace WznmGenChk {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenChk* dpchinv);
	// IP cust --- INSERT
};

#endif

