/**
	* \file WznmQRelSup1NRelation.h
	* API code for table TblWznmQRelSup1NRelation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRELSUP1NRELATION_H
#define WZNMQRELSUP1NRELATION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRelSup1NRelation
	*/
class WznmQRelSup1NRelation {

public:
	WznmQRelSup1NRelation(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRelSup1NRelation
	*/
class ListWznmQRelSup1NRelation {

public:
	ListWznmQRelSup1NRelation();
	ListWznmQRelSup1NRelation(const ListWznmQRelSup1NRelation& src);
	ListWznmQRelSup1NRelation& operator=(const ListWznmQRelSup1NRelation& src);
	~ListWznmQRelSup1NRelation();

	void clear();

public:
	std::vector<WznmQRelSup1NRelation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

