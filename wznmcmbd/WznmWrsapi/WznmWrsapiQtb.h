/**
	* \file WznmWrsapiQtb.h
	* Wznm operation processor - write Swift API code for query table (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSAPIQTB_H
#define WZNMWRSAPIQTB_H

#include "WznmWrsapi.h"

// IP include.cust --- INSERT

namespace WznmWrsapiQtb {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsapiQtb* dpchinv);
	// IP cust --- IBEGIN

	void writeQtbSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmMQuerycol& qcos);

	std::string getTcoSwType(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype);
	std::string getQcoSwType(const Sbecore::uint ixVBasetype);
	std::string getQcoTcoSwType(WznmMQuerycol* qco, const ListWznmMTablecol& tcos);
	std::string getQcoSwDefault(const std::string& qcotype);
	// IP cust --- IEND
};

#endif
