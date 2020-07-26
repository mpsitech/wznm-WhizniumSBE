/**
	* \file WznmWrsrvInixml.h
	* Wznm operation processor - write initialization XML file (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRSRVINIXML_H
#define WZNMWRSRVINIXML_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvInixml {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvInixml* dpchinv);
	// IP cust --- INSERT
};

#endif

