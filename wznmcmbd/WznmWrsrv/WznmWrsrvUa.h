/**
	* \file WznmWrsrvUa.h
	* Wznm operation processor - write C++ code for OPC UA server (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRSRVUA_H
#define WZNMWRSRVUA_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvUa {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvUa* dpchinv);
	// IP cust --- IBEGIN
  void writeUasrvCpp(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const std::string& Cmpsref, ListWznmRMJobMJob& jrjs, ListWznmMJob& jobs);

  std::string getVartypeSDKtype(const uint ixWznmVVartype);
  std::string getVartypeSDKitemtype(const uint ixWznmVVartype);
  std::string getVartypeOpcUaId(const uint ixWznmVVartype);
  // IP cust --- IEND
};

#endif


