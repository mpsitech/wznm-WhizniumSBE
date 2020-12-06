/**
	* \file WznmCtpGenuiAcv.h
	* Wznm operation processor - prettify file card and add upload/download dialogs (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCTPGENUIACV_H
#define WZNMCTPGENUIACV_H

#include "WznmCtpGenui.h"

// IP include.cust --- INSERT

namespace WznmCtpGenuiAcv {

	DpchRetWznmCtpGenui* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenui* dpchinv);
	// IP cust --- INSERT
};

#endif
