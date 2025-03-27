/**
	* \file WznmComplvis_blks.h
	* invocation / return data blocks for operation pack WznmComplvis (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMCOMPLVIS_BLKS_H
#define WZNMCOMPLVIS_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmComplvisDbstr
	*/
class DpchInvWznmComplvisDbstr : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVISUAL = 3;

public:
	DpchInvWznmComplvisDbstr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVisual = 0);

public:
	Sbecore::ubigint refWznmMVisual;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmComplvisImpexp
	*/
class DpchInvWznmComplvisImpexp : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVISUAL = 3;

public:
	DpchInvWznmComplvisImpexp(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVisual = 0);

public:
	Sbecore::ubigint refWznmMVisual;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
