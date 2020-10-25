/**
	* \file WznmWrsrvDds.h
	* Wznm operation processor - write C++ code for DDS publisher (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRSRVDDS_H
#define WZNMWRSRVDDS_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvDds {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvDds* dpchinv);
	// IP cust --- IBEGIN
  void writeIdlfileIdl(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, ListWznmMJob& jobs);
  void writeDdspubH(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, ListWznmMJob& jobs);
  void writeDdspubCpp(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const std::string& Cmpsref, ListWznmRMJobMJob& jrjs, ListWznmMJob& jobs);

  std::string getVarIdltype(const Sbecore::uint ixWznmVVartype, const Sbecore::uint Length);
	// IP cust --- IEND
};

#endif


