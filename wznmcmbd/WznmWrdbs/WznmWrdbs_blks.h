/**
	* \file WznmWrdbs_blks.h
	* invocation / return data blocks for operation pack WznmWrdbs (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRDBS_BLKS_H
#define WZNMWRDBS_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmWrdbsDbs
	*/
class DpchInvWznmWrdbsDbs : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrdbsDbs(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrdbsDeploy
	*/
class DpchInvWznmWrdbsDeploy : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMRELEASE = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWznmWrdbsDeploy(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMRelease = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMRelease;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrdbsDiffsql
	*/
class DpchInvWznmWrdbsDiffsql : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint FRREFWZNMMVERSION = 3;
	static const Sbecore::uint TOREFWZNMMVERSION = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint FOLDER = 6;

public:
	DpchInvWznmWrdbsDiffsql(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint frRefWznmMVersion = 0, const Sbecore::ubigint toRefWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint frRefWznmMVersion;
	Sbecore::ubigint toRefWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrdbsSql
	*/
class DpchInvWznmWrdbsSql : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrdbsSql(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrdbsTbl
	*/
class DpchInvWznmWrdbsTbl : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMTABLE = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint DBSMY = 5;
	static const Sbecore::uint DBSPG = 6;
	static const Sbecore::uint DBSLITE = 7;
	static const Sbecore::uint FOLDER = 8;

public:
	DpchInvWznmWrdbsTbl(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMTable = 0, const std::string& Prjshort = "", const bool dbsmy = false, const bool dbspg = false, const bool dbslite = false, const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMTable;
	std::string Prjshort;
	bool dbsmy;
	bool dbspg;
	bool dbslite;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

