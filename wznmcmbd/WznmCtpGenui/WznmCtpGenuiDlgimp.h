/**
	* \file WznmCtpGenuiDlgimp.h
	* Wznm operation processor - generate data import dialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMCTPGENUIDLGIMP_H
#define WZNMCTPGENUIDLGIMP_H

#include "WznmCtpGenui.h"

// IP include.cust --- INSERT

namespace WznmCtpGenuiDlgimp {

	DpchRetWznmCtpGenui* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenui* dpchinv);
	// IP cust --- INSERT
};

#endif

