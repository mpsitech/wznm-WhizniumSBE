/**
	* \file WznmComplBscui.h
	* Wznm operation processor - complement basic user interface (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


