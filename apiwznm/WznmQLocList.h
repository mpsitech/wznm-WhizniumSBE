/**
	* \file WznmQLocList.h
	* API code for table TblWznmQLocList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQLOCLIST_H
#define WZNMQLOCLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLocList
	*/
class WznmQLocList {

public:
	WznmQLocList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLocList
	*/
class ListWznmQLocList {

public:
	ListWznmQLocList();
	ListWznmQLocList(const ListWznmQLocList& src);
	ListWznmQLocList& operator=(const ListWznmQLocList& src);
	~ListWznmQLocList();

	void clear();

public:
	std::vector<WznmQLocList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

