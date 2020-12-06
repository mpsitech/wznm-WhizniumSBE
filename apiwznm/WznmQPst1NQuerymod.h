/**
	* \file WznmQPst1NQuerymod.h
	* API code for table TblWznmQPst1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPST1NQUERYMOD_H
#define WZNMQPST1NQUERYMOD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPst1NQuerymod
	*/
class WznmQPst1NQuerymod {

public:
	WznmQPst1NQuerymod(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPst1NQuerymod
	*/
class ListWznmQPst1NQuerymod {

public:
	ListWznmQPst1NQuerymod();
	ListWznmQPst1NQuerymod(const ListWznmQPst1NQuerymod& src);
	ListWznmQPst1NQuerymod& operator=(const ListWznmQPst1NQuerymod& src);
	~ListWznmQPst1NQuerymod();

	void clear();

public:
	std::vector<WznmQPst1NQuerymod*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
