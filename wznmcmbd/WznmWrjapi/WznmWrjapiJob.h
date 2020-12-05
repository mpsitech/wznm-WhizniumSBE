/**
	* \file WznmWrjapiJob.h
	* Wznm operation processor - write Java API code for job (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRJAPIJOB_H
#define WZNMWRJAPIJOB_H

#include "WznmWrjapi.h"

// IP include.cust --- INSERT

namespace WznmWrjapiJob {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrjapiJob* dpchinv);
	// IP cust --- IBEGIN

	void writeJobJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, const ListWznmMVector& vecs, const ListWznmMBlock& blks, const std::string& orgweb, const std::string& Prjshort);
  void writeBlkcontJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);
  void writeBlkdpchJ(DbsWznm* dbswznm, const std::string& orgweb, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);
  void writeBlkstatJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);
  void writeBlkstgJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);
  void writeBlktagJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref, ListWznmAMBlockItem bits);

	void wrBitvarConstrhdrJ(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarConstrJ(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarReadxmlJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit, const bool attr, const std::string& shorttag);
	void wrBitvarWritexmlJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit, const bool mask, const bool attr);
	void wrBitvarCompareJ(std::fstream& outfile, WznmAMBlockItem* bit);
	std::string getBlkclass(DbsWznm* dbswznm, WznmMJob* job, WznmMBlock* blk);
  std::string getBlknew(DbsWznm* dbswznm, WznmMJob* job, WznmMBlock* blk);
	std::string getBitJType(WznmAMBlockItem* bit);
	std::string getBitXMLType(WznmAMBlockItem* bit);
	std::string getVecclass(DbsWznm* dbswznm, WznmMJob* job, WznmMVector* vec);
	// IP cust --- IEND
};

#endif



