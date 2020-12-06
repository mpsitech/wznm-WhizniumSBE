/**
	* \file WznmQRtj1NRtblock.h
	* API code for table TblWznmQRtj1NRtblock (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRTJ1NRTBLOCK_H
#define WZNMQRTJ1NRTBLOCK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRtj1NRtblock
	*/
class WznmQRtj1NRtblock {

public:
	WznmQRtj1NRtblock(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRtj1NRtblock
	*/
class ListWznmQRtj1NRtblock {

public:
	ListWznmQRtj1NRtblock();
	ListWznmQRtj1NRtblock(const ListWznmQRtj1NRtblock& src);
	ListWznmQRtj1NRtblock& operator=(const ListWznmQRtj1NRtblock& src);
	~ListWznmQRtj1NRtblock();

	void clear();

public:
	std::vector<WznmQRtj1NRtblock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
