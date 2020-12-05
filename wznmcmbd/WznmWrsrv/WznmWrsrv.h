/**
	* \file WznmWrsrv.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRSRV_H
#define WZNMWRSRV_H

#include "WznmWrsrv_blks.h"

// IP include.cust --- INSERT

namespace WznmWrsrv {

	// IP cust --- IBEGIN
	void writeBlkcontH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkcontCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkdpchH(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkdpchCpp(DbsWznm* dbswznm, const std::string& orgweb, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkstatH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkstatCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkstgH(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const bool subclass, const std::string& subsref);
	void writeBlkstgCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const bool subclass, const std::string& supsref, const std::string& subsref);
	void writeBlktagH(const std::string& Prjshort, std::fstream& outfile, WznmMBlock* blk, const std::string& subsref);
	void writeBlktagCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeVecH(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const bool subclass, const std::string& subsref, const unsigned int subil = 1);
	void writeVecCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMVector* vec, const bool subclass, const std::string& supsref, const std::string& subsref, Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void wrBitvarConstrH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit, const bool scrsimple = false);
	void wrVarDeclH(std::fstream& outfile, const Sbecore::uint ixWznmVVartype, const std::string& sref, const unsigned int il);
	void wrBitvarConstrhdrCpp(std::fstream& outfile, WznmAMBlockItem* bit, const bool scrsimple = false);
	void wrBitvarConstrCpp(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarReadxmlCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit, const bool attr, const std::string& shorttag, const bool scrsimple = false);
	void wrBitvarWritexmlH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit);
	void wrBitvarWritexmlhdrCpp(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarWritexmlCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit, const bool mask, const bool attr, const bool scrsimple = false);
	void wrBitvarCompareCpp(std::fstream& outfile, WznmAMBlockItem* bit);

	void writePreeval(const std::string& Prjshort, std::fstream& outfile, Sbecore::Expr::Node* node);
	void writeBooleval(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, ListWznmMTable& rectbls, Sbecore::Expr::Node* node, const std::string& chkaltjref = "");
	void writeEvalstatshr(std::fstream& outfile, const std::string& bit, const std::string& rule, const std::string& expr, const std::string& prjshort);

	std::string getCaleval(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMTable& rectbls, Sbecore::Expr::Node* node, const bool reta, const std::string& chkaltjref = "");
	std::string getChkeval(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMTable& rectbls, Sbecore::Expr::Node* node, WznmMCall* cal, const bool reta, const std::string& altjref = "");

	void wrGetnewdpchengCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, ListWznmAMBlockItem& bits, WznmMJob* job, ListWznmMBlock& jobblks, ListWznmRMJobMJob& jrjs);

	void wrAlrCpp(DbsWznm* dbswznm, const std::string& orgname, const std::string& Prjshort, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, WznmMControl* alrcon, std::set<std::string>& plhs);
	std::string wrAlrCpp_abtver(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& version, const std::string& rlsdate);
	void wrAlrCpp_abtctbini(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, std::set<Sbecore::ubigint>& refsCtb, std::set<Sbecore::ubigint>& refsPctb);
	std::string wrAlrCpp_abtctb(DbsWznm* dbswznm, std::set<Sbecore::ubigint>& refsCtb, const std::string& _and, const std::string& ctbs);
	void wrAlrCpp_abtlibini(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, std::set<Sbecore::ubigint>& refsLib);
	std::string wrAlrCpp_abtlib(DbsWznm* dbswznm, std::set<Sbecore::ubigint>& refsLib, const std::string& _and, const std::string& libs);
	void wrAlrCpp_abt123(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const Sbecore::ubigint refLcl, std::string& abt1, std::string& abt2, std::string& abt3);

	void getAlrplhs(DbsWznm* dbswznm, const Sbecore::ubigint refAlr, std::set<std::string>& plhs);
	std::string getBlkclass(DbsWznm* dbswznm, WznmMJob* job, WznmMBlock* blk);
	std::string getBlkvar(WznmMJob* job, ListWznmMBlock& jobblks, ListWznmRMJobMJob& jrjs, const std::string sref);
	std::string getIparpaCppType(const Sbecore::uint ixWznmVVartype);
	std::string getVecclass(DbsWznm* dbswznm, WznmMJob* job, WznmMVector* vec);
	bool hasScrref(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMBlock);
	bool isStatic(WznmMBlock* blk);
	// IP cust --- IEND
};

#endif



