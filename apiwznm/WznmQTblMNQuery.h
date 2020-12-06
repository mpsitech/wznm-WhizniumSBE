/**
	* \file WznmQTblMNQuery.h
	* API code for table TblWznmQTblMNQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLMNQUERY_H
#define WZNMQTBLMNQUERY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblMNQuery
	*/
class WznmQTblMNQuery {

public:
	WznmQTblMNQuery(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string stubsTrefWznmMQuerymod = "", const std::string yesnoSource = "", const std::string Prefix = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string stubsTrefWznmMQuerymod;
	std::string yesnoSource;
	std::string Prefix;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblMNQuery
	*/
class ListWznmQTblMNQuery {

public:
	ListWznmQTblMNQuery();
	ListWznmQTblMNQuery(const ListWznmQTblMNQuery& src);
	ListWznmQTblMNQuery& operator=(const ListWznmQTblMNQuery& src);
	~ListWznmQTblMNQuery();

	void clear();

public:
	std::vector<WznmQTblMNQuery*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
