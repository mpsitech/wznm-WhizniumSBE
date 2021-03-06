/**
	* \file WznmQAppList.h
	* API code for table TblWznmQAppList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQAPPLIST_H
#define WZNMQAPPLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQAppList
	*/
class WznmQAppList {

public:
	WznmQAppList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const std::string srefIxWznmVApptarget = "", const std::string titIxWznmVApptarget = "", const std::string stubVerRefWznmMVersion = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Short;
	std::string Title;
	std::string srefIxWznmVApptarget;
	std::string titIxWznmVApptarget;
	std::string stubVerRefWznmMVersion;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQAppList
	*/
class ListWznmQAppList {

public:
	ListWznmQAppList();
	ListWznmQAppList(const ListWznmQAppList& src);
	ListWznmQAppList& operator=(const ListWznmQAppList& src);
	~ListWznmQAppList();

	void clear();

public:
	std::vector<WznmQAppList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
