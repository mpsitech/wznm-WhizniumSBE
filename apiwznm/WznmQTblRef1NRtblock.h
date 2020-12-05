/**
	* \file WznmQTblRef1NRtblock.h
	* API code for table TblWznmQTblRef1NRtblock (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLREF1NRTBLOCK_H
#define WZNMQTBLREF1NRTBLOCK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblRef1NRtblock
	*/
class WznmQTblRef1NRtblock {

public:
	WznmQTblRef1NRtblock(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblRef1NRtblock
	*/
class ListWznmQTblRef1NRtblock {

public:
	ListWznmQTblRef1NRtblock();
	ListWznmQTblRef1NRtblock(const ListWznmQTblRef1NRtblock& src);
	ListWznmQTblRef1NRtblock& operator=(const ListWznmQTblRef1NRtblock& src);
	~ListWznmQTblRef1NRtblock();

	void clear();

public:
	std::vector<WznmQTblRef1NRtblock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

