/**
	* \file WznmWrsrvUa.h
	* Wznm operation processor - write C++ code for OPC UA server (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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



