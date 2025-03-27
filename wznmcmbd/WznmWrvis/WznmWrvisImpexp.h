/**
	* \file WznmWrvisImpexp.h
	* Wznm operation processor - write SVG code for sheet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMWRVISIMPEXP_H
#define WZNMWRVISIMPEXP_H

#include "WznmWrvis.h"

// IP include.cust --- INSERT

namespace WznmWrvisImpexp {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrvisImpexp* dpchinv);
	// IP cust --- IBEGIN
	void getIelContext(DbsWznm* dbswznm, WznmMImpexp* ime, WznmMImpexpcol* iel, WznmMTablecol* tco, WznmMRelation* rel, WznmMRelation* auxprefrel, const Sbecore::ubigint refLcl, std::string& Header, std::string& Subheader, std::string& Content);
	// IP cust --- IEND
};

#endif
