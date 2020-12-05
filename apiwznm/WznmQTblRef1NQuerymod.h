/**
	* \file WznmQTblRef1NQuerymod.h
	* API code for table TblWznmQTblRef1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLREF1NQUERYMOD_H
#define WZNMQTBLREF1NQUERYMOD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblRef1NQuerymod
	*/
class WznmQTblRef1NQuerymod {

public:
	WznmQTblRef1NQuerymod(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblRef1NQuerymod
	*/
class ListWznmQTblRef1NQuerymod {

public:
	ListWznmQTblRef1NQuerymod();
	ListWznmQTblRef1NQuerymod(const ListWznmQTblRef1NQuerymod& src);
	ListWznmQTblRef1NQuerymod& operator=(const ListWznmQTblRef1NQuerymod& src);
	~ListWznmQTblRef1NQuerymod();

	void clear();

public:
	std::vector<WznmQTblRef1NQuerymod*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

