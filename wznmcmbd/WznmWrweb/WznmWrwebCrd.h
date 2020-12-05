/**
	* \file WznmWrwebCrd.h
	* Wznm operation processor - write web UI JS/HTML code for card (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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



