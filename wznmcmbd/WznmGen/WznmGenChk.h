/**
	* \file WznmGenChk.h
	* Wznm operation processor - generate feature checks (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMGENCHK_H
#define WZNMGENCHK_H

#include "WznmGen.h"

// IP include.cust --- INSERT

namespace WznmGenChk {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenChk* dpchinv);
	// IP cust --- INSERT
};

#endif



