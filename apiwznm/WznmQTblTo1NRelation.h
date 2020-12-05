/**
	* \file WznmQTblTo1NRelation.h
	* API code for table TblWznmQTblTo1NRelation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLTO1NRELATION_H
#define WZNMQTBLTO1NRELATION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblTo1NRelation
	*/
class WznmQTblTo1NRelation {

public:
	WznmQTblTo1NRelation(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblTo1NRelation
	*/
class ListWznmQTblTo1NRelation {

public:
	ListWznmQTblTo1NRelation();
	ListWznmQTblTo1NRelation(const ListWznmQTblTo1NRelation& src);
	ListWznmQTblTo1NRelation& operator=(const ListWznmQTblTo1NRelation& src);
	~ListWznmQTblTo1NRelation();

	void clear();

public:
	std::vector<WznmQTblTo1NRelation*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

