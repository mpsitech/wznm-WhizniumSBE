/**
	* \file WznmQDlgMNQuery.h
	* API code for table TblWznmQDlgMNQuery (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

