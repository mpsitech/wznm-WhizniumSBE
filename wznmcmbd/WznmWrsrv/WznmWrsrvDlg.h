/**
	* \file WznmWrsrvDlg.h
	* Wznm operation processor - write specific job C++ code for dialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRSRVDLG_H
#define WZNMWRSRVDLG_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvDlg {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvDlg* dpchinv);
	// IP cust --- IBEGIN

	void writeDlgH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMDialog* dlg, ListWznmMControl& dits, const std::string& Prjshort);

	void writeDlgCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMDialog* dlg, ListWznmMControl& dits, const std::string& Prjshort);
	void writeDlgCpp_refresh(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, ListWznmMBlock& jobblks, const std::string& ditshort, std::vector<std::string>& bitsEval, std::vector<std::string>& rulesEval, std::vector<std::string>& exprsEval, const std::string& Prjshort, const bool hasdse, const bool hassge);

	void getDitblks(WznmMJob* job, ListWznmMBlock& blks, const std::string& ditshort, std::vector<unsigned int>& icsDitblks);
	// IP cust --- IEND
};

#endif



