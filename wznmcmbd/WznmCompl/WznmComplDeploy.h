/**
	* \file WznmComplDeploy.h
	* Wznm operation processor - complement deployment information (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMCOMPLDEPLOY_H
#define WZNMCOMPLDEPLOY_H

#include "WznmCompl.h"

// IP include.cust --- INSERT

namespace WznmComplDeploy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplDeploy* dpchinv);
	// IP cust --- IBEGIN
	std::string getMchparAny(DbsWznm* dbswznm, const Sbecore::ubigint refMchAny, const std::string& x1SrefKKey);
	void addBitJ(DbsWznm* dbswznm, WznmMRelease* rls, WznmAMBlockItem* bit, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& x1SrefKKey, const std::string& post = "");
	// IP cust --- IEND
};

#endif



