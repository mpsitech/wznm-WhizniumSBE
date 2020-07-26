/**
	* \file WznmWrappBase.h
	* Wznm operation processor - write code for accessor app (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRAPPBASE_H
#define WZNMWRAPPBASE_H

#include "WznmWrapp.h"

// IP include.cust --- INSERT

namespace WznmWrappBase {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrappBase* dpchinv);
	// IP cust --- IBEGIN

  void writeAppHcxx(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, const std::string& Prjshort, ListWznmMRtjob& rtjs, ListWznmMSequence& seqs);
  void writeAppCxx(DbsWznm* dbswznm, std::fstream& outfile, WznmMApp* app, const std::string& Prjshort, ListWznmMRtjob& rtjs, ListWznmMSequence& seqs);

  void writeVecSteH(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs);
  void writeVecSteCpp(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMSequence& seqs);
	// IP cust --- IEND
};

#endif


