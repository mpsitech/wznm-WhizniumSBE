/**
	* \file WznmCtpGenuiClustmgr.h
	* Wznm operation processor - add system control panels and launch dialogs (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPGENUICLUSTMGR_H
#define WZNMCTPGENUICLUSTMGR_H

#include "WznmCtpGenui.h"

// IP include.cust --- INSERT

namespace WznmCtpGenuiClustmgr {

	DpchRetWznmCtpGenui* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenui* dpchinv);
	// IP cust --- INSERT
};

#endif
