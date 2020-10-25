/**
	* \file WznmCtpGenjtrDlgimp.h
	* Wznm operation processor - add stages to data import dialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMCTPGENJTRDLGIMP_H
#define WZNMCTPGENJTRDLGIMP_H

#include "WznmCtpGenjtr.h"

// IP include.cust --- INSERT

namespace WznmCtpGenjtrDlgimp {

	DpchRetWznmCtpGenjtr* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenjtr* dpchinv);
	// IP cust --- INSERT
};

#endif

