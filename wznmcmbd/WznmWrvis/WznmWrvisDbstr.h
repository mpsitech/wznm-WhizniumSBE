/**
	* \file WznmWrvisDbstr.h
	* Wznm operation processor - write SVG code for database structure sheet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMWRVISDBSTR_H
#define WZNMWRVISDBSTR_H

#include "WznmWrvis.h"

// IP include.cust --- INSERT

namespace WznmWrvisDbstr {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrvisDbstr* dpchinv);
	// IP cust --- INSERT
};

#endif
