/**
	* \file WznmWrapp_blks.h
	* invocation / return data blocks for operation pack WznmWrapp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRAPP_BLKS_H
#define WZNMWRAPP_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmWrappBase
	*/
class DpchInvWznmWrappBase : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMAPP = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint IPALLNOTSPEC = 5;

public:
	DpchInvWznmWrappBase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMApp = 0, const std::string& folder = "", const bool ipAllNotSpec = false);

public:
	Sbecore::ubigint refWznmMApp;
	std::string folder;
	bool ipAllNotSpec;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrappJbase
	*/
class DpchInvWznmWrappJbase : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMAPP = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint IPALLNOTSPEC = 5;

public:
	DpchInvWznmWrappJbase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMApp = 0, const std::string& folder = "", const bool ipAllNotSpec = false);

public:
	Sbecore::ubigint refWznmMApp;
	std::string folder;
	bool ipAllNotSpec;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

