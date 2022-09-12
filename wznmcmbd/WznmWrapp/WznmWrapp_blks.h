/**
	* \file WznmWrapp_blks.h
	* invocation / return data blocks for operation pack WznmWrapp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRAPP_BLKS_H
#define WZNMWRAPP_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmWrappDom
	*/
class DpchInvWznmWrappDom : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMAPP = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWznmWrappDom(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMApp = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMApp;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrappMain
	*/
class DpchInvWznmWrappMain : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMAPP = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint IPALLNOTSPEC = 5;

public:
	DpchInvWznmWrappMain(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMApp = 0, const std::string& folder = "", const bool ipAllNotSpec = false);

public:
	Sbecore::ubigint refWznmMApp;
	std::string folder;
	bool ipAllNotSpec;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrappStdvec
	*/
class DpchInvWznmWrappStdvec : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMAPP = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWznmWrappStdvec(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMApp = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMApp;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
