/**
	* \file WznmQTblFr1NRelation.h
	* API code for table TblWznmQTblFr1NRelation (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLFR1NRELATION_H
#define WZNMQTBLFR1NRELATION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblFr1NRelation
	*/
class WznmQTblFr1NRelation {

public:
	WznmQTblFr1NRelation(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblFr1NRelation
	*/
class ListWznmQTblFr1NRelation {

public:
	ListWznmQTblFr1NRelation();
	ListWznmQTblFr1NRelation(const ListWznmQTblFr1NRelation& src);
	ListWznmQTblFr1NRelation& operator=(const ListWznmQTblFr1NRelation& src);
	~ListWznmQTblFr1NRelation();

	void clear();

public:
	std::vector<WznmQTblFr1NRelation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

