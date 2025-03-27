/**
	* \file WznmComplvisDbstr.h
	* Wznm operation processor - complement visualization features (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMCOMPLVISDBSTR_H
#define WZNMCOMPLVISDBSTR_H

#include "WznmComplvis.h"

// IP include.cust --- INSERT

namespace WznmComplvisDbstr {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplvisDbstr* dpchinv);
	// IP cust --- INSERT
};

#endif
