/**
	* \file WznmWrjapiQtb.h
	* Wznm operation processor - write Java API code for query table (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRJAPIQTB_H
#define WZNMWRJAPIQTB_H

#include "WznmWrjapi.h"

// IP include.cust --- INSERT

namespace WznmWrjapiQtb {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrjapiQtb* dpchinv);
	// IP cust --- IBEGIN

	void writeQtbJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmMQuerycol& qcos);
	void writeLqtbJ(DbsWznm* dbswznm, std::fstream& outfile, WznmMTable* tbl, const ListWznmMTablecol& tcos, const ListWznmMQuerycol& qcos);

	std::string getTcoJType(const Sbecore::uint ixVBasetype, const Sbecore::uint ixVSubtype);
	std::string getQcoJType(const Sbecore::uint ixVBasetype);
	std::string getQcoTcoJType(WznmMQuerycol* qco, const ListWznmMTablecol& tcos);
	std::string getQcoTcoXMLType(WznmMQuerycol* qco, const ListWznmMTablecol& tcos);
	// IP cust --- IEND
};

#endif


