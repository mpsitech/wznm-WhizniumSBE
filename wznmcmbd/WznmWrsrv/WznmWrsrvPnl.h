/**
	* \file WznmWrsrvPnl.h
	* Wznm operation processor - write specific job C++ code for panel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRSRVPNL_H
#define WZNMWRSRVPNL_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvPnl {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvPnl* dpchinv);
	// IP cust --- IBEGIN

	void writePnlH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, WznmMCard* car, WznmMPanel* pnl, ListWznmMTable& rectbls, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const std::string& Prjshort);
	void writePnlCpp(DbsWznm* dbswznm, std::fstream& outfile, const std::vector<std::string>& sesspsts, WznmMJob* job, WznmMCard* car, const std::vector<std::string>& carrecpsts, const std::vector<std::string>& carsesspsts, const std::vector<std::string>& carpsts, WznmMPanel* pnl, ListWznmMTable& rectbls, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, std::vector<std::string>& bitsEval, std::vector<std::string>& rulesEval, std::vector<std::string>& exprsEval, const std::string& Prjshort);
	void writePnlCpp_butnewview(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMTable& rectbls, WznmMControl* con, const std::string& baseconsref, std::list<Trg*>& trgs, WznmMTable* reftbl, WznmMTablecol* reftco, const bool newNotView);
	void writePnlCpp_evals(std::fstream& outfile, ListWznmMControl& cons, const unsigned int ix0, const unsigned int ix1, std::vector<std::string>& bitsEval, std::vector<std::string>& rulesEval, std::vector<std::string>& exprsEval, std::vector<bool>& oksEval, const std::string& prjshort);

	std::string getCondeval(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMTable& rectbls, const std::string& cond);
	std::string pstcondToShort(const std::string& pstcond);
	// IP cust --- IEND
};

#endif


