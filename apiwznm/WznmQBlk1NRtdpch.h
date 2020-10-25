/**
	* \file WznmQBlk1NRtdpch.h
	* API code for table TblWznmQBlk1NRtdpch (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

