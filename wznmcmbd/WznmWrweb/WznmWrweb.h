/**
	* \file WznmWrweb.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRWEB_H
#define WZNMWRWEB_H

#include "WznmWrweb_blks.h"

// IP include.cust --- INSERT

namespace WznmWrweb {

	// IP cust --- IBEGIN
	void writeLstXmfile(std::fstream& outfile, WznmMControl* con, const bool large);

	void wrEvthdlsXml(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons, const std::set<Sbecore::uint>& hkIcsVSection, const std::string& ditshort, const unsigned int pl, const bool ditempty = false);
	std::string wrEvthdlsXml_ditshort(const std::string& ditshort, const bool ditempty);
	std::string wrEvthdlsXml_altbconsref(ListWznmMControl& cons, WznmMControl* con, const std::string& ditshort, const std::string& consref);

	void wrBaseconXml(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const std::string& hksref, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const unsigned int ixIcsBasecons, const std::string& ditshort, const bool large);
	void wrBaseconXml_buts(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, ListWznmMControl& cons, std::vector<unsigned int>& icsButs, const std::string& ditshort);

	void wrBconiniJs(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const unsigned int ixIcsBasecons, const std::string& hkroot, const std::string& ditshort);
	void wrBconiniJs_buts(std::fstream& outfile, ListWznmMControl& cons, std::vector<unsigned int>& icsButs, const std::string& hkroot, const std::string& ditshort, const std::string& doc);
	void wrBconiniJs_cpt(std::fstream& outfile, ListWznmMControl& cons, const unsigned int ixCpt, const std::string& hkroot, const std::string& ditshort, const std::string& doc);
	void wrBconiniJs_pup(DbsWznm* dbswznm, std::fstream& outfile, WznmMControl* con, const std::string& hkroot, const std::string& ditshort, const std::string& doc);
	void wrBconiniJs_rbu(DbsWznm* dbswznm, std::fstream& outfile, WznmMControl* con, const std::string& hkroot, const std::string& ditshort, const std::string& doc);

	bool wrBconvarsJs(DbsWznm* dbswznm, std::fstream& outfile, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const unsigned int ixIcsBasecons, const std::string& hkroot, const std::string& ditshort);

	void wrBconrefrJs(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, const std::string& hksref, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const unsigned int ixIcsBasecons, const std::string& hkroot, const std::string& ditshort, const bool _large);
	void wrBconrefrJs_buts(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, ListWznmMControl& cons, const unsigned int ixHdg, const unsigned int ixButView, std::vector<unsigned int>& icsButs, const std::string& hkroot, const std::string& ditshort, const std::string& baseconsref, const std::string& baseconshort, const bool alt, const std::string& doc, const bool dyn, const bool rdyn, std::string indent);
	void wrBconrefrJs_pup(DbsWznm* dbswznm, std::fstream& outfile, WznmMControl* con, const std::string& hkroot, const std::string& ditshort, const std::string& doc, const std::string& active, const std::string& indent);
	void wrBconrefrJs_rbu(DbsWznm* dbswznm, std::fstream& outfile, WznmMControl* con, const std::string& hkroot, const std::string& ditshort, const std::string& doc, const std::string& active, const std::string& indent);

	void wrEvthdlsJs(DbsWznm* dbswznm, const std::string& Prjshort, std::fstream& outfile, ListWznmMControl& cons, const std::string& hkroot, const bool pnllist, const bool _large);
	void wrSrcblksJs(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMJob, const std::string& srefDpcheng);

	bool getJobvecio(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMJob);
	std::string getCondoc(WznmMControl* con);
	std::string getConsize(WznmMControl* con);
	std::string getButicon(DbsWznm* dbswznm, const std::string& Prjshort, WznmMControl* con);
	std::string getLstncol(WznmMControl* con);
	bool hasAction(DbsWznm* dbswznm, const Sbecore::uint hkIxVTbl, const Sbecore::ubigint hkUref, const std::string& action);
	bool hasStfeed(DbsWznm* dbswznm, WznmMControl* con);
	// IP cust --- IEND
};

#endif



