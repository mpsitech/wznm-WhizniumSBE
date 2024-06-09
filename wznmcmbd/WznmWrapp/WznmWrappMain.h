/**
	* \file WznmWrappMain.h
	* Wznm operation processor - write main state machine code for accessor app (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRAPPMAIN_H
#define WZNMWRAPPMAIN_H

#include "WznmWrapp.h"

// IP include.cust --- INSERT

namespace WznmWrappMain {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrappMain* dpchinv);
	// IP cust --- IBEGIN

	// preliminary, still with Objective-C heritage
	void writeAppHcxx(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, const std::string& Prjshort, ListWznmMRtjob& rtjs, ListWznmMEvent& evts, ListWznmMState& stes, std::vector<Sbecore::uint>& cntsEnt, std::vector<Sbecore::uint>& cntsReent, std::vector<Sbecore::uint>& cntsLve, const bool ipAllNotSpec);
	void writeAppCxx(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, const std::string& Prjshort, ListWznmMRtjob& rtjs, ListWznmMEvent& evts, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs, std::vector<Sbecore::uint>& cntsEnt, std::vector<Sbecore::uint>& cntsReent, std::vector<Sbecore::uint>& cntsLve, const bool ipAllNotSpec);
	void writeAppJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, const std::string& Prjshort, ListWznmMRtjob& rtjs, ListWznmMEvent& evts, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs, std::vector<Sbecore::uint>& cntsEnt, std::vector<Sbecore::uint>& cntsReent, std::vector<Sbecore::uint>& cntsLve, const bool ipAllNotSpec);

	void writeHandleTrigger(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs, std::vector<Sbecore::uint>& cntsEnt, std::vector<Sbecore::uint>& cntsReent, std::vector<Sbecore::uint>& cntsLve, const bool ipAllNotSpec);

	void writeState(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const std::string& Appshort, const Sbecore::uint ixWznmVApptarget, const std::string& dom, const std::string& indent, const std::string& subdlm, const std::string& dpchjref, WznmMState* ste, std::map<std::string,std::string>& trigs, const Sbecore::uint ixVSection);
	std::string writeState_action(DbsWznm* dbswznm, const std::string& Prjshort, const std::string& Appshort, const Sbecore::uint ixWznmVApptarget, const std::string& dom, const std::string& subdlm, const std::string& dpchjref, WznmAMStateAction* steAact);

	void writeMerge(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::uint ixWznmVApptarget, WznmMBlock* blk, const std::string& dpchsref, ListWznmMRtblock& rtbs);

	void writeDpchEngMerge(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const Sbecore::uint ixWznmVApptarget, ListWznmMRtjob& rtjs);
	// IP cust --- IEND
};

#endif
