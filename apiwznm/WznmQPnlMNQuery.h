/**
	* \file WznmQPnlMNQuery.h
	* API code for table TblWznmQPnlMNQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPNLMNQUERY_H
#define WZNMQPNLMNQUERY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPnlMNQuery
	*/
class WznmQPnlMNQuery {

public:
	WznmQPnlMNQuery(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPnlMNQuery
	*/
class ListWznmQPnlMNQuery {

public:
	ListWznmQPnlMNQuery();
	ListWznmQPnlMNQuery(const ListWznmQPnlMNQuery& src);
	ListWznmQPnlMNQuery& operator=(const ListWznmQPnlMNQuery& src);
	~ListWznmQPnlMNQuery();

	void clear();

public:
	std::vector<WznmQPnlMNQuery*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
