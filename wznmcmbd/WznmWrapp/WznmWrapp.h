/**
	* \file WznmWrapp.h
	* Wznm operation pack global code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRAPP_H
#define WZNMWRAPP_H

#include "WznmWrapp_blks.h"

// IP include.cust --- INSERT

namespace WznmWrapp {

	// IP cust --- IBEGIN
	void loadRtjtree(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMApp, ListWznmMRtjob& rtjs);

	void writeRtjtree(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::uint ixVTarget, ListWznmMRtjob& rtjs);
	void writeRtobjs(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::uint ixVTarget, ListWznmMRtjob& rtjs);

  void writeChangeState(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, ListWznmMSequence& seqs);
  void writeEnterSte(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, WznmMApp* app, WznmMState* ste);
  void writeLeaveSte(std::fstream& outfile, const Sbecore::uint ixVTarget, WznmMState* ste);
  void writeMerge(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, WznmMBlock* blk, const std::string& dpchsref, ListWznmMRtblock& rtbs);

  void writeHandleDpchEng(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::uint ixVTarget, const std::string& Appshort, const std::string& Prjshort, WznmMSequence* seq, ListWznmMState& stes);
	std::string writeHandleDpchEng_genSteastpif(DbsWznm* dbswznm, const Sbecore::uint ixVTarget, const std::string& Prjshort, WznmAMStateStep* steAstp, WznmMRtjob* rtj, WznmMJob* job, WznmMVectoritem* vit, WznmMRtdpch* rtd, WznmMBlock* blk);

  void writeDpchEngMerge(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::uint ixVTarget, const std::string& Prjshort, ListWznmMRtjob& rtjs);
  void writeDpchEngHandle(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::uint ixVTarget, const std::string& Appshort, ListWznmMSequence seqs);

  std::string getScrJrefVar(DbsWznm* dbswznm, WznmMRtjob* rtj, WznmMJob* job);
	// IP cust --- IEND
};

#endif


