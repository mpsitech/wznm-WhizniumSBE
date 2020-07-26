/**
	* \file WznmCtpWrsrvDlgloaini.h
	* Wznm operation processor - implement initialization load dialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMCTPWRSRVDLGLOAINI_H
#define WZNMCTPWRSRVDLGLOAINI_H

#include "WznmCtpWrsrv.h"

// IP include.cust --- INSERT

namespace WznmCtpWrsrvDlgloaini {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrsrv* dpchinv);
	// IP cust --- INSERT
};

#endif

