/**
	* \file WznmCtpGenjtrAcv.h
	* Wznm operation processor - add stages to upload dialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMCTPGENJTRACV_H
#define WZNMCTPGENJTRACV_H

#include "WznmCtpGenjtr.h"

// IP include.cust --- INSERT

namespace WznmCtpGenjtrAcv {

	DpchRetWznmCtpGenjtr* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenjtr* dpchinv);
	// IP cust --- INSERT
};

#endif

