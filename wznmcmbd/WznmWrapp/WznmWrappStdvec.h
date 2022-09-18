/**
	* \file WznmWrappStdvec.h
	* Wznm operation processor - write standard vector code for accessor app (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRAPPSTDVEC_H
#define WZNMWRAPPSTDVEC_H

#include "WznmWrapp.h"

// IP include.cust --- INSERT

namespace WznmWrappStdvec {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrappStdvec* dpchinv);
	// IP cust --- IBEGIN

	//void writeVecEvtH(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMEvent& evts);
	//void writeVecEvtCpp(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMEvent& evts);
	//void writeVecEvtJ(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMEvent& evts);

	//void writeVecSteH(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs);
	//void writeVecSteCpp(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs, ListWznmMState& stes);
	//void writeVecSteJ(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs);
	// IP cust --- IEND
};

#endif
