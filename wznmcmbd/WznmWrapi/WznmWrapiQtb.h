/**
	* \file WznmWrapiQtb.h
	* Wznm operation processor - write API code for query table (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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


