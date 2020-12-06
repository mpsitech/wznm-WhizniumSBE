/**
	* \file WznmQMchList.h
	* API code for table TblWznmQMchList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMCHLIST_H
#define WZNMQMCHLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMchList
	*/
class WznmQMchList {

public:
	WznmQMchList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubSupRefWznmMMachine = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubSupRefWznmMMachine;

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
