/**
	* \file WznmQVer1NTable.h
	* API code for table TblWznmQVer1NTable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NTABLE_H
#define WZNMQVER1NTABLE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NTable
	*/
class WznmQVer1NTable {

public:
	WznmQVer1NTable(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NTable
	*/
class ListWznmQVer1NTable {

public:
	ListWznmQVer1NTable();
	ListWznmQVer1NTable(const ListWznmQVer1NTable& src);
	ListWznmQVer1NTable& operator=(const ListWznmQVer1NTable& src);
	~ListWznmQVer1NTable();

	void clear();

public:
	std::vector<WznmQVer1NTable*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
