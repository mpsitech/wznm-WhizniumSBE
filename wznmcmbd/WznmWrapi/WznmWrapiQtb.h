/**
	* \file WznmWrapiQtb.h
	* Wznm operation processor - write API code for query table (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRAPIQTB_H
#define WZNMWRAPIQTB_H

#include "WznmWrapi.h"

// IP include.cust --- INSERT

namespace WznmWrapiQtb {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrapiQtb* dpchinv);
	// IP cust --- IBEGIN

	void writeQtbH(DbsWznm* dbswznm, std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmMQuerycol& qcos);
	void writeQtbCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmMQuerycol& qcos);

	std::string getTcoCppType(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype, const bool ns);
	std::string getQcoCppType(const Sbecore::uint ixVBasetype, const bool ns);
	std::string getQcoCppDefault(const std::string& qcotype);
	// IP cust --- IEND
};

#endif



