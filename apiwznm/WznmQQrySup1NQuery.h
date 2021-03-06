/**
	* \file WznmQQrySup1NQuery.h
	* API code for table TblWznmQQrySup1NQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYSUP1NQUERY_H
#define WZNMQQRYSUP1NQUERY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQrySup1NQuery
	*/
class WznmQQrySup1NQuery {

public:
	WznmQQrySup1NQuery(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQrySup1NQuery
	*/
class ListWznmQQrySup1NQuery {

public:
	ListWznmQQrySup1NQuery();
	ListWznmQQrySup1NQuery(const ListWznmQQrySup1NQuery& src);
	ListWznmQQrySup1NQuery& operator=(const ListWznmQQrySup1NQuery& src);
	~ListWznmQQrySup1NQuery();

	void clear();

public:
	std::vector<WznmQQrySup1NQuery*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
