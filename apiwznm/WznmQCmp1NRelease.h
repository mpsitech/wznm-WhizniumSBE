/**
	* \file WznmQCmp1NRelease.h
	* API code for table TblWznmQCmp1NRelease (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCMP1NRELEASE_H
#define WZNMQCMP1NRELEASE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCmp1NRelease
	*/
class WznmQCmp1NRelease {

public:
	WznmQCmp1NRelease(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCmp1NRelease
	*/
class ListWznmQCmp1NRelease {

public:
	ListWznmQCmp1NRelease();
	ListWznmQCmp1NRelease(const ListWznmQCmp1NRelease& src);
	ListWznmQCmp1NRelease& operator=(const ListWznmQCmp1NRelease& src);
	~ListWznmQCmp1NRelease();

	void clear();

public:
	std::vector<WznmQCmp1NRelease*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
