/**
	* \file WznmWrsapi_blks.h
	* invocation / return data blocks for operation pack WznmWrsapi (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef WZNMWRSAPI_BLKS_H
#define WZNMWRSAPI_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmWrsapiBase
	*/
class DpchInvWznmWrsapiBase : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsapiBase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsapiJob
	*/
class DpchInvWznmWrsapiJob : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMCOMPONENT = 3;
	static const Sbecore::uint REFWZNMMJOB = 4;
	static const Sbecore::uint ORGWEB = 5;
	static const Sbecore::uint PRJSHORT = 6;
	static const Sbecore::uint FOLDER = 7;

public:
	DpchInvWznmWrsapiJob(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string& orgweb = "", const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMComponent;
	Sbecore::ubigint refWznmMJob;
	std::string orgweb;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsapiQtb
	*/
class DpchInvWznmWrsapiQtb : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMTABLE = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWznmWrsapiQtb(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMTable = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMTable;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsapiVec
	*/
class DpchInvWznmWrsapiVec : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVECTOR = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsapiVec(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVector;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
