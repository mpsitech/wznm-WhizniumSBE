/**
	* \file WznmWrsrvIex.h
	* Wznm operation processor - write C++ code for import/export complex (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRSRVIEX_H
#define WZNMWRSRVIEX_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvIex {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvIex* dpchinv);
	// IP cust --- IBEGIN

	void writeIexH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMImpexpcplx* iex, const std::string& Prjshort);
	void writeIexH_imefsrsDef(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMImpexpcplx* iex, WznmMImpexp* ime);
	void writeIexH_imeDecl(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMImpexpcplx* iex, WznmMImpexp* ime, const std::string& Prjshort);

	void writeIexCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMImpexpcplx* iex, const std::string& Prjshort, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl);
	void writeIexCpp_ime(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMImpexpcplx* iex, WznmMImpexp* ime, const std::string& Prjshort, const Sbecore::ubigint refLcl, std::vector<Sbecore::ubigint>& refsLcl);

	void writeIexjobH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMImpexpcplx* iex, const std::string& Prjshort);

	void writeIexjobCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMImpexpcplx* iex, const std::string& Prjshort);
	std::string writeIexjobCpp_getImeshort(DbsWznm* dbswznm, WznmMImpexp* ime);
	void writeIexjobCpp_imptraverse(DbsWznm* dbswznm, std::fstream& outfile, WznmMImpexpcplx* iex, WznmMImpexp* supime, WznmMTable* suptbl, ListWznmMImpexpcol& supiels, WznmMImpexp* ime, const std::string& Prjshort);
	void writeIexjobCpp_rvrtraverse(DbsWznm* dbswznm, std::fstream& outfile, WznmMImpexpcplx* iex, WznmMImpexp* supime, WznmMImpexp* ime, const std::string& Prjshort);
	void writeIexjobCpp_coltraverse(DbsWznm* dbswznm, std::fstream& outfile, WznmMImpexpcplx* iex, WznmMImpexp* supime, WznmMImpexp* ime, const std::string& Prjshort);

	void wrIelEmpty(DbsWznm* dbswznm, std::fstream& outfile, WznmMImpexpcol* iel, WznmMTablecol* tco = NULL);
	// IP cust --- IEND
};

#endif


