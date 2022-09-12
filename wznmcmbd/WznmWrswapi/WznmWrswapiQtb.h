/**
	* \file WznmWrswapiQtb.h
	* Wznm operation processor - write Swift API code for query table (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSWAPIQTB_H
#define WZNMWRSWAPIQTB_H

#include "WznmWrswapi.h"

// IP include.cust --- INSERT

namespace WznmWrswapiQtb {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrswapiQtb* dpchinv);
	// IP cust --- IBEGIN

	void writeQtbSw(DbsWznm* dbswznm, std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmMQuerycol& qcos);

	std::string getTcoSwType(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype);
	std::string getQcoSwType(const Sbecore::uint ixVBasetype);
	std::string getQcoTcoSwType(WznmMQuerycol* qco, const ListWznmMTablecol& tcos);
	std::string getQcoSwDefault(const std::string& qcotype);
	// IP cust --- IEND
};

#endif
