/**
	* \file WznmQMchList.h
	* API code for table TblWznmQMchList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQMCHLIST_H
#define WZNMQMCHLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMchList
	*/
class WznmQMchList {

public:
	WznmQMchList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWznmMMachtype = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWznmMMachtype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMchList
	*/
class ListWznmQMchList {

public:
	ListWznmQMchList();
	ListWznmQMchList(const ListWznmQMchList& src);
	ListWznmQMchList& operator=(const ListWznmQMchList& src);
	~ListWznmQMchList();

	void clear();

public:
	std::vector<WznmQMchList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

