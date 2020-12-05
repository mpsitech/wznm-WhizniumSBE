/**
	* \file WznmQQryMNTable.h
	* API code for table TblWznmQQryMNTable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYMNTABLE_H
#define WZNMQQRYMNTABLE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQryMNTable
	*/
class WznmQQryMNTable {

public:
	WznmQQryMNTable(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string stubsTrefWznmMQuerymod = "", const std::string yesnoSource = "", const std::string Prefix = "");

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
	* ListWznmQQryMNTable
	*/
class ListWznmQQryMNTable {

public:
	ListWznmQQryMNTable();
	ListWznmQQryMNTable(const ListWznmQQryMNTable& src);
	ListWznmQQryMNTable& operator=(const ListWznmQQryMNTable& src);
	~ListWznmQQryMNTable();

	void clear();

public:
	std::vector<WznmQQryMNTable*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

