/**
	* \file WznmGenBase.h
	* Wznm operation processor - generate version basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMGENBASE_H
#define WZNMGENBASE_H

#include "WznmGen.h"

// IP include.cust --- INSERT

namespace WznmGenBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenBase* dpchinv);
	// IP cust --- IBEGIN

	void genCrdnav(DbsWznm* dbswznm, WznmMVersion* ver, const std::string& Prjshort, const std::vector<Sbecore::ubigint>& refsLcl);

	void genStdAlrs(DbsWznm* dbswznm, WznmMVersion* ver, const std::string& Prjshort, const Sbecore::ubigint refLcl);

	void genStdVecs(DbsWznm* dbswznm, WznmMVersion* ver, const std::string& Prjshort, const std::vector<Sbecore::ubigint>& refsLcl);
	WznmMVector* genStdvecEmpty(DbsWznm* dbswznm, const Sbecore::uint ixVBasetype, WznmMVersion* ver, const Sbecore::uint hkIxVTbl, const std::string& Prjshort, const std::string& osrefWznmKTaggrp, const std::string& srefsKOption, const std::vector<Sbecore::ubigint>& refsLcl);
	void fillVecLocale(DbsWznm* dbswznm, const Sbecore::ubigint vecRefWznmMVector, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genStdPres(DbsWznm* dbswznm, WznmMVersion* ver, const std::string& Prjshort);

	void genStdQtbs(DbsWznm* dbswznm, WznmMVersion* ver, const std::string& Prjshort);
	void genStdBlks(DbsWznm* dbswznm, WznmMVersion* ver, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif


