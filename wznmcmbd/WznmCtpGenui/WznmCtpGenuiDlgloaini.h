/**
	* \file WznmCtpGenuiDlgloaini.h
	* Wznm operation processor - generate initialization load dialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMCTPGENUIDLGLOAINI_H
#define WZNMCTPGENUIDLGLOAINI_H

#include "WznmCtpGenui.h"

// IP include.cust --- INSERT

namespace WznmCtpGenuiDlgloaini {

	DpchRetWznmCtpGenui* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenui* dpchinv);
	// IP cust --- INSERT
};

#endif

