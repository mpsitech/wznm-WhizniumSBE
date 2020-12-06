/**
	* \file WznmQQryQry1NQuerycol.h
	* API code for table TblWznmQQryQry1NQuerycol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYQRY1NQUERYCOL_H
#define WZNMQQRYQRY1NQUERYCOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQryQry1NQuerycol
	*/
class WznmQQryQry1NQuerycol {

public:
	WznmQQryQry1NQuerycol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQryQry1NQuerycol
	*/
class ListWznmQQryQry1NQuerycol {

public:
	ListWznmQQryQry1NQuerycol();
	ListWznmQQryQry1NQuerycol(const ListWznmQQryQry1NQuerycol& src);
	ListWznmQQryQry1NQuerycol& operator=(const ListWznmQQryQry1NQuerycol& src);
	~ListWznmQQryQry1NQuerycol();

	void clear();

public:
	std::vector<WznmQQryQry1NQuerycol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
