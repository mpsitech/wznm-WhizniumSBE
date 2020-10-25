/**
	* \file WznmQSbsPst1NQuerymod.h
	* API code for table TblWznmQSbsPst1NQuerymod (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBSPST1NQUERYMOD_H
#define WZNMQSBSPST1NQUERYMOD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbsPst1NQuerymod
	*/
class WznmQSbsPst1NQuerymod {

public:
	WznmQSbsPst1NQuerymod(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbsPst1NQuerymod
	*/
class ListWznmQSbsPst1NQuerymod {

public:
	ListWznmQSbsPst1NQuerymod();
	ListWznmQSbsPst1NQuerymod(const ListWznmQSbsPst1NQuerymod& src);
	ListWznmQSbsPst1NQuerymod& operator=(const ListWznmQSbsPst1NQuerymod& src);
	~ListWznmQSbsPst1NQuerymod();

	void clear();

public:
	std::vector<WznmQSbsPst1NQuerymod*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

