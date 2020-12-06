/**
	* \file WznmComplDbs.h
	* Wznm operation processor - complement database structure (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCOMPLDBS_H
#define WZNMCOMPLDBS_H

#include "WznmCompl.h"

// IP include.cust --- INSERT

namespace WznmComplDbs {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmComplDbs* dpchinv);
	// IP cust --- IBEGIN

	void fillVecKeylist(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl);
	void fillVecMaintable(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void fillVecValuelist(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl);

	void genMtbPres(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl);
	void genMtbSbsvecs(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genMtbSbschks(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion);
	void genMtbSbschks_collect(Sbecore::Expr::Node* node, std::set<std::string>& chks);

	void genRelLoadfcts(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion);
	void genStbLoadfcts(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion);
	// IP cust --- IEND
};

#endif
