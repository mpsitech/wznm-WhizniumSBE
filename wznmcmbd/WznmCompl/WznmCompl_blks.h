/**
	* \file WznmCompl_blks.h
	* invocation / return data blocks for operation pack WznmCompl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCOMPL_BLKS_H
#define WZNMCOMPL_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmComplBscui
	*/
class DpchInvWznmComplBscui : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;

public:
	DpchInvWznmComplBscui(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmComplDbs
	*/
class DpchInvWznmComplDbs : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;

public:
	DpchInvWznmComplDbs(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmComplDeploy
	*/
class DpchInvWznmComplDeploy : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint ORGWEB = 5;

public:
	DpchInvWznmComplDeploy(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& orgweb = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string orgweb;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmComplIex
	*/
class DpchInvWznmComplIex : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;

public:
	DpchInvWznmComplIex(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0);

public:
	Sbecore::ubigint refWznmMVersion;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmComplJtr
	*/
class DpchInvWznmComplJtr : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;

public:
	DpchInvWznmComplJtr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif



