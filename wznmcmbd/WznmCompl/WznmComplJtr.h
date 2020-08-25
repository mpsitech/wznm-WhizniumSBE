/**
	* \file WznmComplJtr.h
	* Wznm operation processor - complement job tree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMCOMPLJTR_H
#define WZNMCOMPLJTR_H

#include "WznmCompl.h"

// IP include.cust --- INSERT

namespace WznmComplJtr {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplJtr* dpchinv);
	// IP cust --- IBEGIN

	void addImmcbUpdmonSnss(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion);
	void addUldDldSnss(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion);
	void addUldDldSnss_jobrefs(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const Sbecore::uint refIxVTbl, const Sbecore::uint hkIxVTbl, const Sbecore::uint ixVBasetype, const bool append, std::vector<Sbecore::ubigint>& refs);

	void addRootJrjs(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void addM2msessJrjs(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif


