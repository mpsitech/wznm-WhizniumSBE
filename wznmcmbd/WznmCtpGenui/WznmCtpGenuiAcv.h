/**
	* \file WznmCtpGenuiAcv.h
	* Wznm operation processor - prettify file card and add upload/download dialogs (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMCTPGENUIACV_H
#define WZNMCTPGENUIACV_H

#include "WznmCtpGenui.h"

// IP include.cust --- INSERT

namespace WznmCtpGenuiAcv {

	DpchRetWznmCtpGenui* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenui* dpchinv);
	// IP cust --- INSERT
};

#endif

