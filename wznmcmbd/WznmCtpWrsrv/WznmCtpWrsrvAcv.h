/**
	* \file WznmCtpWrsrvAcv.h
	* Wznm operation processor - implement upload/download dialogs (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSRVACV_H
#define WZNMCTPWRSRVACV_H

#include "WznmCtpWrsrv.h"

// IP include.cust --- INSERT

namespace WznmCtpWrsrvAcv {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrsrv* dpchinv);
	// IP cust --- INSERT
};

#endif



