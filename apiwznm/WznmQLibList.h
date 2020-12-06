/**
	* \file WznmQLibList.h
	* API code for table TblWznmQLibList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQLIBLIST_H
#define WZNMQLIBLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLibList
	*/
class WznmQLibList {

public:
	WznmQLibList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string srefKLictype = "", const std::string titSrefKLictype = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string Version;
	std::string srefKLictype;
	std::string titSrefKLictype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLibList
	*/
class ListWznmQLibList {

public:
	ListWznmQLibList();
	ListWznmQLibList(const ListWznmQLibList& src);
	ListWznmQLibList& operator=(const ListWznmQLibList& src);
	~ListWznmQLibList();

	void clear();

public:
	std::vector<WznmQLibList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
