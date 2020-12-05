/**
	* \file WznmWrapiJob.h
	* Wznm operation processor - write API code for job (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRAPIJOB_H
#define WZNMWRAPIJOB_H

#include "WznmWrapi.h"

// IP include.cust --- INSERT

namespace WznmWrapiJob {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrapiJob* dpchinv);
	// IP cust --- IBEGIN

	void writeJobH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, const ListWznmMVector& vecs, const ListWznmMBlock& blks, const std::string& Prjshort);
	void writeJobCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, const ListWznmMVector& vecs, const ListWznmMBlock& blks, const std::string& orgweb, const std::string& Prjshort);

	void writeBlkcontH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkcontCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkdpchH(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkdpchCpp(DbsWznm* dbswznm, const std::string& orgweb, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkstatH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkstatCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkstgH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlkstgCpp(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlktagH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);
	void writeBlktagCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMBlock* blk, const std::string& subsref);

	void wrBitvarConstrH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit);
	void wrVarDeclH(std::fstream& outfile, const Sbecore::uint ixWznmVVartype, const std::string& sref, const unsigned int il);
	void wrBitvarConstrhdrCpp(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarConstrCpp(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarReadxmlCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit, const bool attr, const std::string& shorttag);
	void wrBitvarWritexmlH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit);
	void wrBitvarWritexmlhdrCpp(std::fstream& outfile, WznmAMBlockItem* bit);
	void wrBitvarWritexmlCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmAMBlockItem* bit, const bool mask, const bool attr);
	void wrBitvarCompareCpp(std::fstream& outfile, WznmAMBlockItem* bit);
	std::string getBlkclass(DbsWznm* dbswznm, WznmMJob* job, WznmMBlock* blk);
	std::string getVecclass(DbsWznm* dbswznm, WznmMJob* job, WznmMVector* vec);
	// IP cust --- IEND
};

#endif



