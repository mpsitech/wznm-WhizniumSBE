/**
	* \file WznmQShtList.h
	* API code for table TblWznmQShtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQSHTLIST_H
#define WZNMQSHTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQShtList
	*/
class WznmQShtList {

public:
	WznmQShtList(const Sbecore::uint jnum = 0, const std::string Title = "", const std::string stubVisRefWznmMVisual = "");

public:
	Sbecore::uint jnum;
	std::string Title;
	std::string stubVisRefWznmMVisual;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQShtList
	*/
class ListWznmQShtList {

public:
	ListWznmQShtList();
	ListWznmQShtList(const ListWznmQShtList& src);
	ListWznmQShtList& operator=(const ListWznmQShtList& src);
	~ListWznmQShtList();

	void clear();

public:
	std::vector<WznmQShtList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
