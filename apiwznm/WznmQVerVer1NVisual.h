/**
	* \file WznmQVerVer1NVisual.h
	* API code for table TblWznmQVerVer1NVisual (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVERVER1NVISUAL_H
#define WZNMQVERVER1NVISUAL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVerVer1NVisual
	*/
class WznmQVerVer1NVisual {

public:
	WznmQVerVer1NVisual(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVerVer1NVisual
	*/
class ListWznmQVerVer1NVisual {

public:
	ListWznmQVerVer1NVisual();
	ListWznmQVerVer1NVisual(const ListWznmQVerVer1NVisual& src);
	ListWznmQVerVer1NVisual& operator=(const ListWznmQVerVer1NVisual& src);
	~ListWznmQVerVer1NVisual();

	void clear();

public:
	std::vector<WznmQVerVer1NVisual*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
