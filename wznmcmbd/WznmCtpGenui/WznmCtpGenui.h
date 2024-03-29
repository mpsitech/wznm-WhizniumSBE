/**
	* \file WznmCtpGenui.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCTPGENUI_H
#define WZNMCTPGENUI_H

#include "WznmCtpGenui_blks.h"

// IP include.cust --- INSERT

namespace WznmCtpGenui {

	// IP cust --- IBEGIN
	void addCjttag(DbsWznm* dbswznm, WznmMControl* con, const Sbecore::ubigint refWznmMCapability, const std::string& sref, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, const bool esc = true);
	// IP cust --- IEND
};

#endif
