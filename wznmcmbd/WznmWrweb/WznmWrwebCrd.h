/**
	* \file WznmWrwebCrd.h
	* Wznm operation processor - write web UI JS/HTML code for card (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRWEBCRD_H
#define WZNMWRWEBCRD_H

#include "WznmWrweb.h"

// IP include.cust --- INSERT

namespace WznmWrwebCrd {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrwebCrd* dpchinv);
	// IP cust --- IBEGIN

	void writeCrdHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMCard* car, ListWznmMPanel& pnls); // CrdXxxxYyy_Refvoid.html, CrdXxxxYyy.html
	void writeCrdJsfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMCard* car, ListWznmMPanel& pnls); // CrdXxxxYyy.js
	void writeMenHtfile(DbsWznm* dbswznm, std::fstream& outfile, WznmMCard* crd, const Sbecore::ubigint refMen); // MenXxx.html
	// IP cust --- IEND
};

#endif


