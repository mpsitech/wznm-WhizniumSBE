/**
	* \file WznmWrappJbase.h
	* Wznm operation processor - write code for Java accessor app (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRAPPJBASE_H
#define WZNMWRAPPJBASE_H

#include "WznmWrapp.h"

// IP include.cust --- INSERT

namespace WznmWrappJbase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrappJbase* dpchinv);
	// IP cust --- IBEGIN

  void writeAppJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, const std::string& Prjshort, ListWznmMRtjob& rtjs, ListWznmMEvent& evts, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs, std::vector<Sbecore::uint>& cntsEnt, std::vector<Sbecore::uint>& cntsReent, std::vector<Sbecore::uint>& cntsLve, const bool ipAllNotSpec);
  void writeDOMJ(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMRtjob& rtjs);
  void writeVecEvtJ(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMEvent& evts);
  void writeVecSteJ(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs);

  std::string getBlknew(DbsWznm* dbswznm, WznmMJob* hostjob, WznmMBlock* blk);
  std::string getBitJType(WznmAMBlockItem* bit);
  std::string getJDefault(const std::string& jtype);
	// IP cust --- IEND
};

#endif


