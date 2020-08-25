/**
	* \file WznmWrappBase.h
	* Wznm operation processor - write code for accessor app (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRAPPBASE_H
#define WZNMWRAPPBASE_H

#include "WznmWrapp.h"

// IP include.cust --- INSERT

namespace WznmWrappBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrappBase* dpchinv);
	// IP cust --- IBEGIN

  void writeAppHcxx(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, const std::string& Prjshort, ListWznmMRtjob& rtjs, ListWznmMEvent& evts, ListWznmMState& stes, std::vector<Sbecore::uint>& cntsEnt, std::vector<Sbecore::uint>& cntsReent, std::vector<Sbecore::uint>& cntsLve, const bool ipAllNotSpec);
  void writeAppCxx(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, const std::string& Prjshort, ListWznmMRtjob& rtjs, ListWznmMEvent& evts, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs, std::vector<Sbecore::uint>& cntsEnt, std::vector<Sbecore::uint>& cntsReent, std::vector<Sbecore::uint>& cntsLve, const bool ipAllNotSpec);

  void writeVecEvtH(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMEvent& evts);
  void writeVecEvtCpp(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMEvent& evts);

  void writeVecSteH(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs);
  void writeVecSteCpp(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs, ListWznmMState& stes);
	// IP cust --- IEND
};

#endif


