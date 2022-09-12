/**
	* \file WznmWrvue.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRVUE_H
#define WZNMWRVUE_H

#include "WznmWrvue_blks.h"

// IP include.cust --- INSERT

namespace WznmWrvue {

	// IP cust --- IBEGIN
	void wrIp(std::fstream& outfile, const int indent, const std::string& tag, const std::string& type);
	void wrIbegin(std::fstream& outfile, const int indent, const std::string& tag, const bool addbegin = false);
	void wrIend(std::fstream& outfile, const int indent, const std::string& tag, const bool addend = false);

	void wrBasecon(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const std::string& hksref, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const unsigned int ixIcsBasecons, const std::string& ditshort);

	void wrMergedpcheng(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const Sbecore::ubigint refWznmMJob, std::string sub = "", const bool postprc = true);
	void wrData(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const Sbecore::ubigint refWznmMJob);

	std::string getButmdi(DbsWznm* dbswznm, const std::string& Prjshort, WznmMControl* con);
	// IP cust --- IEND
};

#endif
