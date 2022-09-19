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

	void writeVecEvtIpVec(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMEvent& evts, const Sbecore::uint ixWznmVApptarget);
	void writeVecEvtIpGetSref(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMEvent& evts, const Sbecore::uint ixWznmVApptarget);

	void writeVecSteIpVec(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs, const Sbecore::uint ixWznmVApptarget);
	void writeVecSteIpGetSref(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs, ListWznmMState& stes, const Sbecore::uint ixWznmVApptarget);

	std::string wrConst(const unsigned int num, const std::string& sref, const Sbecore::uint ixWznmVApptarget);
	std::string wrGetSref(const std::string& sref, const Sbecore::uint ixWznmVApptarget);
	// IP cust --- IEND
};

#endif
