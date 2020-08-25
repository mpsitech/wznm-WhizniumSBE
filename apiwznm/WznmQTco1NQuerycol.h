/**
	* \file WznmQTco1NQuerycol.h
	* API code for table TblWznmQTco1NQuerycol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

