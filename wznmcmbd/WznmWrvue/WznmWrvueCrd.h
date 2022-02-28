/**
	* \file WznmWrvueCrd.h
	* Wznm operation processor - write Vue.js UI Vue code for card (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRVUECRD_H
#define WZNMWRVUECRD_H

#include "WznmWrvue.h"

// IP include.cust --- INSERT

namespace WznmWrvueCrd {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrvueCrd* dpchinv);
	// IP cust --- IBEGIN

	void writeCrdVue(DbsWznm* dbswznm, std::fstream& outfile, WznmMCard* car, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif
