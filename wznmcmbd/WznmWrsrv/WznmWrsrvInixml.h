/**
	* \file WznmWrsrvInixml.h
	* Wznm operation processor - write initialization XML file (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRSRVINIXML_H
#define WZNMWRSRVINIXML_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvInixml {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvInixml* dpchinv);
	// IP cust --- INSERT
};

#endif



