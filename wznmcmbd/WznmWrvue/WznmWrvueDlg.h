/**
	* \file WznmWrvueDlg.h
	* Wznm operation processor - write Vue.js UI Vue code for dialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRVUEDLG_H
#define WZNMWRVUEDLG_H

#include "WznmWrvue.h"

// IP include.cust --- INSERT

namespace WznmWrvueDlg {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrvueDlg* dpchinv);
	// IP cust --- IBEGIN

	void writeDlgVue(DbsWznm* dbswznm, std::fstream& outfile, WznmMDialog* dlg, ListWznmMControl& dits, ListWznmMControl& ftrcons, const std::string& Prjshort);
	// IP cust --- IEND
};

#endif
