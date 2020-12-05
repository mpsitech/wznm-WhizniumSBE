/**
	* \file WznmGenCal.h
	* Wznm operation processor - generate calls (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMGENCAL_H
#define WZNMGENCAL_H

#include "WznmGen.h"

// IP include.cust --- INSERT

namespace WznmGenCal {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenCal* dpchinv);
	// IP cust --- IBEGIN

	void getRefsCarByTbl(DbsWznm* dbswznm, ListWznmMCard& cars, const Sbecore::ubigint refTbl, std::vector<Sbecore::ubigint>& refsCar);
	void getRefsQrylistjobByTbl(DbsWznm* dbswznm, const Sbecore::ubigint refTbl, std::vector<Sbecore::ubigint>& refsQryjob);
	void getRefsPnlrecjobByCars(DbsWznm* dbswznm, std::vector<Sbecore::ubigint>& refsCar, std::vector<Sbecore::ubigint>& refsPnljob);
	void getRefsPnldetailjobByCars(DbsWznm* dbswznm, std::vector<Sbecore::ubigint>& refsCar, std::vector<Sbecore::ubigint>& refsPnljob);
	void getRefsQryjobByRel(DbsWznm* dbswznm, const Sbecore::ubigint refTbl, const Sbecore::ubigint refRel, std::vector<Sbecore::ubigint>& refsQryjob);
	void getRefsQryjobBySuprel(DbsWznm* dbswznm, const Sbecore::ubigint refTbl, const Sbecore::ubigint refSuprel, std::vector<Sbecore::ubigint>& refsQryjob);
	// IP cust --- IEND
};

#endif



