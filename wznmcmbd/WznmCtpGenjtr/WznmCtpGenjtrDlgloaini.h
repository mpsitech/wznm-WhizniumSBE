/**
	* \file WznmCtpGenjtrDlgloaini.h
	* Wznm operation processor - add stages to initialization load dialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMCTPGENJTRDLGLOAINI_H
#define WZNMCTPGENJTRDLGLOAINI_H

#include "WznmCtpGenjtr.h"

// IP include.cust --- INSERT

namespace WznmCtpGenjtrDlgloaini {

	DpchRetWznmCtpGenjtr* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenjtr* dpchinv);
	// IP cust --- INSERT
};

#endif

