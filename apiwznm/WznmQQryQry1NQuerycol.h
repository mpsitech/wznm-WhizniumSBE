/**
	* \file WznmQQryQry1NQuerycol.h
	* API code for table TblWznmQQryQry1NQuerycol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

