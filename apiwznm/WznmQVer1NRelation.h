/**
	* \file WznmQVer1NRelation.h
	* API code for table TblWznmQVer1NRelation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NRELATION_H
#define WZNMQVER1NRELATION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NRelation
	*/
class WznmQVer1NRelation {

public:
	WznmQVer1NRelation(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NRelation
	*/
class ListWznmQVer1NRelation {

public:
	ListWznmQVer1NRelation();
	ListWznmQVer1NRelation(const ListWznmQVer1NRelation& src);
	ListWznmQVer1NRelation& operator=(const ListWznmQVer1NRelation& src);
	~ListWznmQVer1NRelation();

	void clear();

public:
	std::vector<WznmQVer1NRelation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
