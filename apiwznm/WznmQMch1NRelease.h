/**
	* \file WznmQMch1NRelease.h
	* API code for table TblWznmQMch1NRelease (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMCH1NRELEASE_H
#define WZNMQMCH1NRELEASE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMch1NRelease
	*/
class WznmQMch1NRelease {

public:
	WznmQMch1NRelease(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMch1NRelease
	*/
class ListWznmQMch1NRelease {

public:
	ListWznmQMch1NRelease();
	ListWznmQMch1NRelease(const ListWznmQMch1NRelease& src);
	ListWznmQMch1NRelease& operator=(const ListWznmQMch1NRelease& src);
	~ListWznmQMch1NRelease();

	void clear();

public:
	std::vector<WznmQMch1NRelease*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

