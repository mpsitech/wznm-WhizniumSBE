/**
	* \file WznmQBlk1NRtdpch.h
	* API code for table TblWznmQBlk1NRtdpch (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQBLK1NRTDPCH_H
#define WZNMQBLK1NRTDPCH_H

#include <sbecore/Xmlio.h>

/**
	* WznmQBlk1NRtdpch
	*/
class WznmQBlk1NRtdpch {

public:
	WznmQBlk1NRtdpch(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQBlk1NRtdpch
	*/
class ListWznmQBlk1NRtdpch {

public:
	ListWznmQBlk1NRtdpch();
	ListWznmQBlk1NRtdpch(const ListWznmQBlk1NRtdpch& src);
	ListWznmQBlk1NRtdpch& operator=(const ListWznmQBlk1NRtdpch& src);
	~ListWznmQBlk1NRtdpch();

	void clear();

public:
	std::vector<WznmQBlk1NRtdpch*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

