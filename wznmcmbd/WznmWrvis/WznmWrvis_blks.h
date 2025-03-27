/**
	* \file WznmWrvis_blks.h
	* invocation / return data blocks for operation pack WznmWrvis (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMWRVIS_BLKS_H
#define WZNMWRVIS_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmWrvisDbstr
	*/
class DpchInvWznmWrvisDbstr : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMSHEET = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;
	static const Sbecore::uint SHTSHORT = 6;
	static const Sbecore::uint JREFBOXCTX = 7;
	static const Sbecore::uint JREFLINKCTX = 8;

public:
	DpchInvWznmWrvisDbstr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMSheet = 0, const std::string& Prjshort = "", const std::string& folder = "", const std::string& Shtshort = "", const Sbecore::ubigint jrefBoxctx = 0, const Sbecore::ubigint jrefLinkctx = 0);

public:
	Sbecore::ubigint refWznmMSheet;
	std::string Prjshort;
	std::string folder;
	std::string Shtshort;
	Sbecore::ubigint jrefBoxctx;
	Sbecore::ubigint jrefLinkctx;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrvisImpexp
	*/
class DpchInvWznmWrvisImpexp : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMSHEET = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;
	static const Sbecore::uint SHTSHORT = 6;
	static const Sbecore::uint JREFBOXCTX = 7;
	static const Sbecore::uint JREFLINKCTX = 8;

public:
	DpchInvWznmWrvisImpexp(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMSheet = 0, const std::string& Prjshort = "", const std::string& folder = "", const std::string& Shtshort = "", const Sbecore::ubigint jrefBoxctx = 0, const Sbecore::ubigint jrefLinkctx = 0);

public:
	Sbecore::ubigint refWznmMSheet;
	std::string Prjshort;
	std::string folder;
	std::string Shtshort;
	Sbecore::ubigint jrefBoxctx;
	Sbecore::ubigint jrefLinkctx;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
