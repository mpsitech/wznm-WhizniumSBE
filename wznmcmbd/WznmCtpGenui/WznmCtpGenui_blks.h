/**
	* \file WznmCtpGenui_blks.h
	* invocation / return data blocks for operation pack WznmCtpGenui (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMCTPGENUI_BLKS_H
#define WZNMCTPGENUI_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmCtpGenui
	*/
class DpchInvWznmCtpGenui : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREFKCUSTOP = 3;
	static const Sbecore::uint REFWZNMMCAPABILITY = 4;
	static const Sbecore::uint PRJSHORT = 5;

public:
	DpchInvWznmCtpGenui(const Sbecore::ubigint oref = 0, const std::string& srefKCustop = "", const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMCapability = 0, const std::string& Prjshort = "");

public:
	std::string srefKCustop;

	Sbecore::ubigint refWznmMCapability;
	std::string Prjshort;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWznmCtpGenui
	*/
class DpchRetWznmCtpGenui : public DpchRetWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint LOGFILE = 5;

public:
	DpchRetWznmCtpGenui(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& logfile = "");

public:
	std::string logfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

