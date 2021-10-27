/**
	* \file WznmComplCtpcpy.h
	* Wznm operation processor - copy dependencies and parameters from template (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
  */
// IP header --- ABOVE

#ifndef WZNMCOMPLCTPCPY_H
#define WZNMCOMPLCTPCPY_H

#include "WznmCompl.h"

// IP include.cust --- INSERT

namespace WznmComplCtpcpy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplCtpcpy* dpchinv);
	// IP cust --- INSERT
};

#endif
