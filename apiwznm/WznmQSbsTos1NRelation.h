/**
	* \file WznmQSbsTos1NRelation.h
	* API code for table TblWznmQSbsTos1NRelation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSBSTOS1NRELATION_H
#define WZNMQSBSTOS1NRELATION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbsTos1NRelation
	*/
class WznmQSbsTos1NRelation {

public:
	WznmQSbsTos1NRelation(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbsTos1NRelation
	*/
class ListWznmQSbsTos1NRelation {

public:
	ListWznmQSbsTos1NRelation();
	ListWznmQSbsTos1NRelation(const ListWznmQSbsTos1NRelation& src);
	ListWznmQSbsTos1NRelation& operator=(const ListWznmQSbsTos1NRelation& src);
	~ListWznmQSbsTos1NRelation();

	void clear();

public:
	std::vector<WznmQSbsTos1NRelation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
