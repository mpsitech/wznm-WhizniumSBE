/**
	* \file WznmQVer1NQuery.h
	* API code for table TblWznmQVer1NQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NQUERY_H
#define WZNMQVER1NQUERY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NQuery
	*/
class WznmQVer1NQuery {

public:
	WznmQVer1NQuery(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NQuery
	*/
class ListWznmQVer1NQuery {

public:
	ListWznmQVer1NQuery();
	ListWznmQVer1NQuery(const ListWznmQVer1NQuery& src);
	ListWznmQVer1NQuery& operator=(const ListWznmQVer1NQuery& src);
	~ListWznmQVer1NQuery();

	void clear();

public:
	std::vector<WznmQVer1NQuery*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
