/**
	* \file WznmQDlgMNQuery.h
	* API code for table TblWznmQDlgMNQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQDLGMNQUERY_H
#define WZNMQDLGMNQUERY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQDlgMNQuery
	*/
class WznmQDlgMNQuery {

public:
	WznmQDlgMNQuery(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQDlgMNQuery
	*/
class ListWznmQDlgMNQuery {

public:
	ListWznmQDlgMNQuery();
	ListWznmQDlgMNQuery(const ListWznmQDlgMNQuery& src);
	ListWznmQDlgMNQuery& operator=(const ListWznmQDlgMNQuery& src);
	~ListWznmQDlgMNQuery();

	void clear();

public:
	std::vector<WznmQDlgMNQuery*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
