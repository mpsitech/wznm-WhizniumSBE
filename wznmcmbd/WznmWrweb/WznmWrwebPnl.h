/**
	* \file WznmWrwebPnl.h
	* Wznm operation processor - write web UI JS/HTML code for panel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMWRWEBPNL_H
#define WZNMWRWEBPNL_H

#include "WznmWrweb.h"

// IP include.cust --- INSERT

namespace WznmWrwebPnl {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrwebPnl* dpchinv);
	// IP cust --- IBEGIN

	// headbar panel
	void writePhcXmfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl); // PnlXxxxYyyHeadbar_cont.xml
	void writePhJsfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl); // PnlXxxxYyyHeadbar.js

	// headline panel
	void writePhlcXmfile(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons); // PnlXxxxYyyZzzzz_cont_Headline.xml
	void writePhlJsfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons); // PnlXxxxYyyZzzzz_Headline.js

	// form / recform panel
	void writePfbHtfile(std::fstream& outfile, const bool hashdr, const bool hasftr); // PnlXxxxYyyZzzzz_b_Form/Recform.html
	void writePfbcXmfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const std::string& Prjshort); // PnlXxxxYyyZzzzz_bcont_Form/Recform.xml
	void writePfbfHtfile(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons, const std::string& Prjshort); // PnlXxxxYyyZzzzz_bftr_Form/Recform.html
	void writePfbhHtfile(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons, const std::string& Prjshort); // PnlXxxxYyyZzzzz_bhdr_Form/Recform.html
	void writePfHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl); // PnlXxxxYyyZzzzz_Form/Recform.html
	void writePfJsfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const bool hashdr, const bool hasftr, const bool estapp, const std::string& Prjshort); // PnlXxxxYyyZzzzz_Form/Recform.js

	// list panel
	void writePlaHtfile(std::fstream& outfile, const bool haspst); // PnlXxxxYyyList_a.html
	void writePlbfXmfile(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons); // PnlXxxxYyyList_bftr.xml
	void writePlbhHtfile(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons, const bool haspst); // PnlXxxxYyyList_bhdr.html
	void writePlbtXmfile(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons); // PnlXxxxYyyList_btbl.xml
	void writePlJsfile(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons, const bool haspst); // PnlXxxxYyyList.js

	// rec panel
	void writePrlhHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl, const std::string& Prjshort); // PnlXxxxYyyRec_lhs.html
	void writePrrhHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl, const std::string& Prjshort); // PnlXxxxYyyRec_rhs.html
	void writePrJsfile(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons); //  PnlXxxxYyyRec.js

	// reclist panel
	void writePnlasHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl); // PnlXxxxYyyZzzzz_aside.html
	void writePnlbfXmfile(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons); // PnlXxxxYyyZzzzz_bftr.xml
	void writePnlbhHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons, const uint ixReltype); // PnlXxxxYyyZzzzz_bhdr.html
	void writePnlbsHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMPanel* pnl); // PnlXxxxYyyZzzzz_bside.html
	void writePnlbtXmfile(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons); // PnlXxxxYyyZzzzz_btbl.xml
	void writePnlJsfile(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, WznmMPanel* pnl, ListWznmMControl& cons, const bool estapp); // PnlXxxxYyyZzzzz.js
	// IP cust --- IEND
};

#endif


