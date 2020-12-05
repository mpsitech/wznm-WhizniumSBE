/**
	* \file WznmComplBscui.h
	* Wznm operation processor - complement basic user interface (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCOMPLBSCUI_H
#define WZNMCOMPLBSCUI_H

#include "WznmCompl.h"

// IP include.cust --- INSERT

namespace WznmComplBscui {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplBscui* dpchinv);
	// IP cust --- IBEGIN

	void genCarJtits(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void genCaraccPres(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif



