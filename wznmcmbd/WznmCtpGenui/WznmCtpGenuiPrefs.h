/**
	* \file WznmCtpGenuiPrefs.h
	* Wznm operation processor - add preferences panels (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPGENUIPREFS_H
#define WZNMCTPGENUIPREFS_H

#include "WznmCtpGenui.h"

// IP include.cust --- INSERT

namespace WznmCtpGenuiPrefs {

	DpchRetWznmCtpGenui* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenui* dpchinv);
	// IP cust --- IBEGIN

void addBitcons(DbsWznm* dbswznm, ListWznmAMBlockItem& bits, ListWznmMControl& cons, const Sbecore::ubigint refWznmMPanel, Sbecore::uint& hkNum, const std::string& Avail, Sbecore::uint& pnlsectNum, const Sbecore::ubigint refLcl);
	// IP cust --- IEND
};

#endif
