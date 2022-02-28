/**
	* \file WznmWrvuePnl.h
	* Wznm operation processor - write Vue.js UI Vue code for panel (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRVUEPNL_H
#define WZNMWRVUEPNL_H

#include "WznmWrvue.h"

// IP include.cust --- INSERT

namespace WznmWrvuePnl {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrvuePnl* dpchinv);
	// IP cust --- IBEGIN

	void writePnlVue(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif
