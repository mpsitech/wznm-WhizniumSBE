/**
	* \file WznmQSbsFrs1NRelation.h
	* API code for table TblWznmQSbsFrs1NRelation (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBSFRS1NRELATION_H
#define WZNMQSBSFRS1NRELATION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbsFrs1NRelation
	*/
class WznmQSbsFrs1NRelation {

public:
	WznmQSbsFrs1NRelation(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbsFrs1NRelation
	*/
class ListWznmQSbsFrs1NRelation {

public:
	ListWznmQSbsFrs1NRelation();
	ListWznmQSbsFrs1NRelation(const ListWznmQSbsFrs1NRelation& src);
	ListWznmQSbsFrs1NRelation& operator=(const ListWznmQSbsFrs1NRelation& src);
	~ListWznmQSbsFrs1NRelation();

	void clear();

public:
	std::vector<WznmQSbsFrs1NRelation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

