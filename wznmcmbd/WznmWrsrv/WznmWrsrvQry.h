/**
	* \file WznmWrsrvQry.h
	* Wznm operation processor - write specific job C++ code for query (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRSRVQRY_H
#define WZNMWRSRVQRY_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvQry {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvQry* dpchinv);
	// IP cust --- IBEGIN

	void writeQryH(DbsWznm* dbswznm, std::fstream& outfile, WznmMQuery* qry, WznmMTable* qtb, ListWznmMQuerymod& bras, ListWznmMQuerymod& exbras, ListWznmMQuerymod& filts, ListWznmAMQueryOrder& qaos, const std::string& Prjshort);
	void writeQryCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMQuery* qry, WznmMTable* qtb, WznmMQuery* lrefqry, WznmMTable* lreftbl, WznmMQuery* oprqry, WznmMTable* oprtbl, ListWznmMQuerymod& bras, ListWznmMQuerymod& exbras, ListWznmMQuerymod& filts, ListWznmMQuerymod& jovrs, ListWznmMQuerymod& stovrs, ListWznmAMQueryOrder& qaos, WznmAMQueryOrder* lrefqao, WznmAMQueryOrder* oprqao, ListWznmMPreset& psts, const std::string& Prjshort);

	void writeCnt(DbsWznm* dbswznm, std::fstream& outfile, WznmMQuery* qry, WznmMTable* tbl, std::vector<std::string>& bratbls, ListWznmAMQueryClause& qacs, ListWznmMQuerymod& filts, const std::string& Prjshort, const std::string& id);
	void writeLrefqry(DbsWznm* dbswznm, std::fstream& outfile, WznmMQuery* qry, WznmMTable* lreftbl, ListWznmAMQueryClause& qacs, WznmAMQueryOrder* lrefqao, const std::string& Prjshort, const std::string& id);
	void writeQry(DbsWznm* dbswznm, std::fstream& outfile, WznmMQuery* qry, WznmMTable* qtb, ListWznmMQuerymod& filts, ListWznmAMQueryOrder& qaos, ListWznmAMQueryClause& qacs, std::vector<std::string>& bratbls, ListWznmMQuerycol& qcos, ListWznmMTablecol& tcos, const std::string& Prjshort, const std::string& id, const bool hasqwr, const bool hasbras, const bool hasfilts, const unsigned int ixLimofs);
	void writeBaseSQL(std::fstream& outfile, WznmMTable* qtb, ListWznmMQuerycol& qcos, ListWznmMTablecol& tcos, const bool hasqwr);
	void writeQac(DbsWznm* dbswznm, std::fstream& outfile, WznmAMQueryClause* qac, const std::string& Prjshort, const bool latdlo = false);
	void getBratbls(DbsWznm* dbswznm, const Sbecore::ubigint refQmd, ListWznmMTable& tbls, std::vector<std::string>& comtbls, std::vector<std::string>& bratbls);
	void getUnqicsQmdpsts(ListWznmMQuerymod& qmds, std::vector<unsigned int>& ics);
	std::string getPstCppType(const Sbecore::uint ixWznmWArgtype, const bool fct = false, const bool ns = false);
	std::string getPstVar(const std::string sref);
	void showQry(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMQuery, const unsigned int il = 0);
	// IP cust --- IEND
};

#endif


