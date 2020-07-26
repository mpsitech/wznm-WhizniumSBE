/**
	* \file WznmWrwebDlg.h
	* Wznm operation processor - write web UI JS/HTML code for dialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRWEBDLG_H
#define WZNMWRWEBDLG_H

#include "WznmWrweb.h"

// IP include.cust --- INSERT

namespace WznmWrwebDlg {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrwebDlg* dpchinv);
	// IP cust --- IBEGIN

	void writeDlgfHtfile(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMDialog, ListWznmMControl& ftrcons, const bool hasdse); // DlgXxxxYyyZzzzz_ftr.html
	void writeDlghXmfile(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMDialog, ListWznmMControl& dits); // DlgXxxxYyyZzzzz_hdr.xml
	void writeDlgaXmfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMDialog* dlg, WznmMControl* dit, const std::string& Prjshort); // DlgXxxxYyyZzzzzAaa.xml
	void writeDlgHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMDialog* dlg, const bool hasdse); // DlgXxxxYyyZzzzz.html
	void writeDlgJsfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMDialog* dlg, ListWznmMControl& dits, ListWznmMControl& ftrcons, const std::string& Prjshort); // DlgXxxxYyyZzzzz.js
	void writeDlgndJsfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMDialog* dlg, ListWznmMControl& ftrcons, const std::string& Prjshort); // DlgXxxxYyyZzzzz_Nodse.js
	// IP cust --- IEND
};

#endif


