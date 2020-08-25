/**
	* \file WznmWrdbsSql.h
	* Wznm operation processor - write database create SQL code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRDBSSQL_H
#define WZNMWRDBSSQL_H

#include "WznmWrdbs.h"

// IP include.cust --- INSERT

namespace WznmWrdbsSql {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrdbsSql* dpchinv);
	// IP cust --- IBEGIN

	void writeSqlMy(DbsWznm* dbswznm, std::fstream& outfile, const ListWznmMTable& tbls, const ListWznmMTable& qtbs, const bool mix, const bool ariaIsam, const bool myNotMar);
	void writeSqlPg(DbsWznm* dbswznm, std::fstream& outfile, const ListWznmMTable& tbls, const ListWznmMTable& qtbs);
	void writeSqlLite(DbsWznm* dbswznm, std::fstream& outfile, const ListWznmMTable& tbls, const ListWznmMTable& qtbs);

	bool getTcoIdx(WznmMTablecol* tco);
	std::string getTcoSqlMyType(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype);
	std::string getTcoSqlPgType(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype);
	std::string getTcoSqlLiteType(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype);
	// IP cust --- IEND
};

#endif


