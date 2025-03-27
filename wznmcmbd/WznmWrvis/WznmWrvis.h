/**
	* \file WznmWrvis.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMWRVIS_H
#define WZNMWRVIS_H

#include "WznmWrvis_blks.h"

// IP include.cust --- IBEGIN
#include <cmath>
// IP include.cust --- IEND

namespace WznmWrvis {

	// IP cust --- IBEGIN
	void getTcoContext(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, WznmMRelation* auxprefrel, const Sbecore::ubigint refLcl, std::string& Header, std::string& Subheader, std::string& Content);

	std::string getTcoContext_hdrstd(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl);
	std::string getTcoContext_hdrtag(DbsWznm* dbswznm, const std::string& srefTag, const Sbecore::ubigint refLcl);
	std::string getTcoContext_hdrvec(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl);
	std::string getTcoContext_hdrrel(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl);
	std::string getTcoContext_hdrrelpl(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl);
	std::string getTcoContext_hdrreluniv(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl);
	std::string getTcoContext_hdrrelauxpref(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl);

	void clkToXy(const int xctr, const int yctr, const int w, const int h, const int clk, int& x, int& y);
	// IP cust --- IEND
};

#endif
