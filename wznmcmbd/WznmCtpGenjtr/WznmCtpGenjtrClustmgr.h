/**
	* \file WznmCtpGenjtrClustmgr.h
	* Wznm operation processor - add state machines to launch dialogs (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPGENJTRCLUSTMGR_H
#define WZNMCTPGENJTRCLUSTMGR_H

#include "WznmCtpGenjtr.h"

// IP include.cust --- INSERT

namespace WznmCtpGenjtrClustmgr {

	DpchRetWznmCtpGenjtr* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpGenjtr* dpchinv);
	// IP cust --- INSERT
};

#endif
