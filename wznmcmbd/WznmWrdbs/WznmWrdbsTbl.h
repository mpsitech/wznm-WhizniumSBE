/**
	* \file WznmWrdbsTbl.h
	* Wznm operation processor - write database access library C++ code for table (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRDBSTBL_H
#define WZNMWRDBSTBL_H

#include "WznmWrdbs.h"

// IP include.cust --- INSERT

namespace WznmWrdbsTbl {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrdbsTbl* dpchinv);
	// IP cust --- IBEGIN

	void writeTblH(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, WznmMTable* tbl, const ListWznmMVector& vecs, const ListWznmMTablecol& tcos, const ListWznmAMTableLoadfct& lfcs, const bool hasRst, const bool hasHrefsup, const bool hasHrefsdown, const bool hasHrstup, const bool hasHrstdown, const bool dbsmy, const bool dbspg, const bool dbslite);
	void writeTblH_my(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmAMTableLoadfct& lfcs, const bool hasRst);
	void writeTblH_pg(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmAMTableLoadfct& lfcs, const bool hasRst);
	void writeTblH_lite(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmAMTableLoadfct& lfcs, const bool hasRst);
	void writeTblH_lfc(std::fstream& outfile, WznmAMTableLoadfct* lfc, const std::string& tblsref, const ListWznmMTablecol& tcos);

	void writeTblvecsCpp(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, WznmMTable* tbl, const ListWznmMVector& vecs, Sbecore::ubigint& refLcl, std::vector<Sbecore::ubigint>& refsLcl);

	void writeTblCpp(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const bool hasString, const ListWznmAMTableLoadfct& lfcs, const bool hasRst, const bool hasHrefsup, const bool hasHrefsdown, const bool hasHrstup, const bool hasHrstdown, const bool dbsmy, const bool dbspg, const bool dbslite, const bool hasvecs);
	void writeTblCpp_my(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const bool hasString, const ListWznmAMTableLoadfct& lfcs, const bool hasRst);
	void writeTblCpp_pg(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmAMTableLoadfct& lfcs, const bool hasRst);
	void writeTblCpp_lite(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmAMTableLoadfct& lfcs, const bool hasRst);
	void writeTblCpp_lfchdr(std::fstream& outfile, WznmAMTableLoadfct* lfc, const std::string& tblsref, const ListWznmMTablecol& tcos, const std::string& prefix);

	void writeQtbH(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmMQuerycol& qcos, const bool dbsmy, const bool dbspg, const bool dbslite);
	void writeQtbCpp(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const bool hasString, const ListWznmMQuerycol& qcos, const bool dbsmy, const bool dbspg, const bool dbslite);
	void writeQtbCpp_my(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const bool hasString);
	void writeQtbCpp_pg(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos);
	void writeQtbCpp_lite(std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos);

	std::string getTcoCppType(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype, const bool ns);
	std::string getTcoCppDefault(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype);
	std::string getTcoMybind(WznmMTablecol* tco, const std::string& recstr, const unsigned int i);
	void getTcoPgstrvec(std::fstream& outfile, WznmMTablecol* tco, const std::string& recstr);
	std::string getTcoPgvals(WznmMTablecol* tco, const std::string recstr);
	std::string getTcoPgl(WznmMTablecol* tco);
	int getTcoPgf(WznmMTablecol* tco);
	std::string getTcoLitebind(WznmMTablecol* tco, const std::string& recstr, const std::string& stmt, const unsigned int i);

	bool getLfc(const Sbecore::uint ixVLoadtype);
	std::string getLfcRetType(const Sbecore::uint ixVLoadtype, const bool ns);
	bool getLfcAppend(const Sbecore::uint ixVLoadtype);
	std::string getLfcRes(const std::string& tblsref, const Sbecore::uint ixVLoadtype, const std::string& ldsref, const bool ns);
	void getLfcSql(std::fstream& outfile, WznmAMTableLoadfct* lfc, const ListWznmMTablecol& tcos, const std::string& tblsref, const bool mystmt, const bool pgstmt, const bool litestmt);
	WznmMTablecol* getLdTco(const std::string& ld, const ListWznmMTablecol& tcos);
	WznmMTablecol* getLbyTco(const std::string& lby, const ListWznmMTablecol& tcos);

	std::string getQcoCppType(const Sbecore::uint ixVBasetype, const bool ns);
	std::string getQcoCppDefault(const std::string& qcotype);
	std::string getQcoWrite(const std::string& qcotype);
	// IP cust --- IEND
};

#endif


