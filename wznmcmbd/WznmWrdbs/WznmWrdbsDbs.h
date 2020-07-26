/**
	* \file WznmWrdbsDbs.h
	* Wznm operation processor - write database access library C++ code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRDBSDBS_H
#define WZNMWRDBSDBS_H

#include "WznmWrdbs.h"

// IP include.cust --- INSERT

namespace WznmWrdbsDbs {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrdbsDbs* dpchinv);
	// IP cust --- IBEGIN

	void writeDbsH(DbsWznm* dbswznm, std::fstream& outfile, const ListWznmMTable& tbls, const ListWznmMTable& qtbs, const ListWznmMVector& vecs, const std::string& Prjshort, const bool my, const bool pg, const bool lite, const std::vector<std::string>& dbss);
	void writeDbsvecsCpp(DbsWznm* dbswznm, std::fstream& outfile, const ListWznmMVector& vecs, const std::string& Prjshort, Sbecore::ubigint& refLcl, std::vector<Sbecore::ubigint>& refsLcl);

	void writeDbsCpp(DbsWznm* dbswznm, std::fstream& outfile, const ListWznmMTable& tbls, const ListWznmMTable& qtbs, const std::string& Prjshort, const bool my, const bool pg, const bool lite, const std::vector<std::string>& dbss, const bool hasvecs);
	void writeDbsCpp_sbseval(DbsWznm* dbswznm, std::fstream& outfile, WznmMTable* tbl, ListWznmMTablecol& tcos, std::map<std::string,WznmMTablecol*>& shortsTcos, Sbecore::Expr::Node* node);
	// IP cust --- IEND
};

#endif


