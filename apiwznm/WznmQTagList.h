/**
	* \file WznmQTagList.h
	* API code for table TblWznmQTagList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTAGLIST_H
#define WZNMQTAGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTagList
	*/
class WznmQTagList {

public:
	WznmQTagList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubRefWznmMCapability = "", const std::string osrefWznmKTaggrp = "", const std::string titOsrefWznmKTaggrp = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubRefWznmMCapability;
	std::string osrefWznmKTaggrp;
	std::string titOsrefWznmKTaggrp;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTagList
	*/
class ListWznmQTagList {

public:
	ListWznmQTagList();
	ListWznmQTagList(const ListWznmQTagList& src);
	ListWznmQTagList& operator=(const ListWznmQTagList& src);
	~ListWznmQTagList();

	void clear();

public:
	std::vector<WznmQTagList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

