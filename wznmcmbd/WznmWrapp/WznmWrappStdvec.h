/**
	* \file WznmWrappStdvec.h
	* Wznm operation processor - write standard vector code for accessor app (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRAPPSTDVEC_H
#define WZNMWRAPPSTDVEC_H

#include "WznmWrapp.h"

// IP include.cust --- INSERT

namespace WznmWrappStdvec {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrappStdvec* dpchinv);
	// IP cust --- INSERT
};

#endif
