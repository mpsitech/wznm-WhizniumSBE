/**
	* \file WznmQTcoRef1NQuerymod.h
	* API code for table TblWznmQTcoRef1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTCOREF1NQUERYMOD_H
#define WZNMQTCOREF1NQUERYMOD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTcoRef1NQuerymod
	*/
class WznmQTcoRef1NQuerymod {

public:
	WznmQTcoRef1NQuerymod(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTcoRef1NQuerymod
	*/
class ListWznmQTcoRef1NQuerymod {

public:
	ListWznmQTcoRef1NQuerymod();
	ListWznmQTcoRef1NQuerymod(const ListWznmQTcoRef1NQuerymod& src);
	ListWznmQTcoRef1NQuerymod& operator=(const ListWznmQTcoRef1NQuerymod& src);
	~ListWznmQTcoRef1NQuerymod();

	void clear();

public:
	std::vector<WznmQTcoRef1NQuerymod*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
