/**
	* \file WznmQUsgList.h
	* API code for table TblWznmQUsgList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSGLIST_H
#define WZNMQUSGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQUsgList
	*/
class WznmQUsgList {

public:
	WznmQUsgList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string sref = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string sref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQUsgList
	*/
class ListWznmQUsgList {

public:
	ListWznmQUsgList();
	ListWznmQUsgList(const ListWznmQUsgList& src);
	ListWznmQUsgList& operator=(const ListWznmQUsgList& src);
	~ListWznmQUsgList();

	void clear();

public:
	std::vector<WznmQUsgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

