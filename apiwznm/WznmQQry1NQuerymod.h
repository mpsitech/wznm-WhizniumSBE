/**
	* \file WznmQQry1NQuerymod.h
	* API code for table TblWznmQQry1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRY1NQUERYMOD_H
#define WZNMQQRY1NQUERYMOD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQry1NQuerymod
	*/
class WznmQQry1NQuerymod {

public:
	WznmQQry1NQuerymod(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQry1NQuerymod
	*/
class ListWznmQQry1NQuerymod {

public:
	ListWznmQQry1NQuerymod();
	ListWznmQQry1NQuerymod(const ListWznmQQry1NQuerymod& src);
	ListWznmQQry1NQuerymod& operator=(const ListWznmQQry1NQuerymod& src);
	~ListWznmQQry1NQuerymod();

	void clear();

public:
	std::vector<WznmQQry1NQuerymod*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

