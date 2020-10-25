/**
	* \file WznmCtpWrsrvAcv.h
	* Wznm operation processor - implement upload/download dialogs (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMCTPWRSRVACV_H
#define WZNMCTPWRSRVACV_H

#include "WznmCtpWrsrv.h"

// IP include.cust --- INSERT

namespace WznmCtpWrsrvAcv {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrsrv* dpchinv);
	// IP cust --- INSERT
};

#endif

