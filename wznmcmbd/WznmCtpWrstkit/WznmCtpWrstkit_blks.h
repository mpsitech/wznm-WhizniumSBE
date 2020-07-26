/**
	* \file WznmCtpWrstkit_blks.h
	* invocation / return data blocks for operation pack WznmCtpWrstkit (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMCTPWRSTKIT_BLKS_H
#define WZNMCTPWRSTKIT_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmCtpWrstkit
	*/
class DpchInvWznmCtpWrstkit : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREFKCUSTOP = 3;
	static const Sbecore::uint REFWZNMMCAPABILITY = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint FOLDER = 6;

public:
	DpchInvWznmCtpWrstkit(const Sbecore::ubigint oref = 0, const std::string& srefKCustop = "", const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMCapability = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	std::string srefKCustop;

	Sbecore::ubigint refWznmMCapability;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

