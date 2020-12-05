/**
	* \file WznmQTco1NQuerycol.h
	* API code for table TblWznmQTco1NQuerycol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTCO1NQUERYCOL_H
#define WZNMQTCO1NQUERYCOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTco1NQuerycol
	*/
class WznmQTco1NQuerycol {

public:
	WznmQTco1NQuerycol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTco1NQuerycol
	*/
class ListWznmQTco1NQuerycol {

public:
	ListWznmQTco1NQuerycol();
	ListWznmQTco1NQuerycol(const ListWznmQTco1NQuerycol& src);
	ListWznmQTco1NQuerycol& operator=(const ListWznmQTco1NQuerycol& src);
	~ListWznmQTco1NQuerycol();

	void clear();

public:
	std::vector<WznmQTco1NQuerycol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

