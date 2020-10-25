/**
	* \file WznmQSbsTos1NRelation.h
	* API code for table TblWznmQSbsTos1NRelation (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

