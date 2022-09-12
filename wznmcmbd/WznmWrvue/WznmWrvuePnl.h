/**
	* \file WznmWrvuePnl.h
	* Wznm operation processor - write Vue.js UI Vue code for panel (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRVUEPNL_H
#define WZNMWRVUEPNL_H

#include "WznmWrvue.h"

// IP include.cust --- INSERT

namespace WznmWrvuePnl {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrvuePnl* dpchinv);
	// IP cust --- IBEGIN

	// form / recform panel
	void writePfVuefile(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const std::string& estblk, const bool hashdr, const bool hasftr); // PnlXxxxYyyZzzzz_Form.vue

	// list / reclist panel
	void writePlVuefile(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons, const std::string& estblk, const bool haspst); // PnlXxxxYyyZzzzz.vue

	// rec panel
	void writePrVuefile(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons); // PnlXxxxYyyRec.vue

	void wrButs(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, ListWznmMControl& cons, const std::set<Sbecore::uint>& hkIcsVSection, const std::string& estblk);
	// IP cust --- IEND
};

#endif
