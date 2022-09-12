/**
	* \file WznmWrswapiJob.h
	* Wznm operation processor - write Swift API code for job (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSWAPIJOB_H
#define WZNMWRSWAPIJOB_H

#include "WznmWrswapi.h"

// IP include.cust --- INSERT

namespace WznmWrswapiJob {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrswapiJob* dpchinv);
	// IP cust --- IBEGIN

	void writeJobSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, const ListWznmMVector& vecs, const ListWznmMBlock& blks, const std::string& orgweb, const std::string& Prjshort);
  void writeBlkcontSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);
  void writeBlkdpchSw(DbsWznm* dbswznm, const std::string& orgweb, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);
  void writeBlkstatSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);
  void writeBlkstgSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);
  void writeBlktagSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);

	void wrBitvarConstrhdrSw(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarConstrSw(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarReadxmlSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, const std::string& subsref, WznmAMBlockItem* bit, const bool attr, const std::string& shorttag);
	void wrBitvarWritexmlSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, const std::string& subsref, WznmAMBlockItem* bit, const bool mask, const bool attr);
	void wrBitvarCompareSw(std::fstream& outfile, const std::string& subsref, WznmAMBlockItem* bit);
	std::string getBlkclass(DbsWznm* dbswznm, WznmMJob* job, WznmMBlock* blk);
  std::string getBlknew(DbsWznm* dbswznm, WznmMJob* job, WznmMBlock* blk);
	std::string getBitSwType(WznmAMBlockItem* bit);
	std::string getBitXMLType(WznmAMBlockItem* bit);
	std::string getVecclass(DbsWznm* dbswznm, WznmMJob* job, WznmMVector* vec);
	// IP cust --- IEND
};

#endif
