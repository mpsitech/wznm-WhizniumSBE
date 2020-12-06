/**
	* \file WznmQQcoList.h
	* API code for table TblWznmQQcoList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQCOLIST_H
#define WZNMQQCOLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQcoList
	*/
class WznmQQcoList {

public:
	WznmQQcoList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Short = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubQryRefWznmMQuery = "", const std::string stubRefWznmMTablecol = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Short;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubQryRefWznmMQuery;
	std::string stubRefWznmMTablecol;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQcoList
	*/
class ListWznmQQcoList {

public:
	ListWznmQQcoList();
	ListWznmQQcoList(const ListWznmQQcoList& src);
	ListWznmQQcoList& operator=(const ListWznmQQcoList& src);
	~ListWznmQQcoList();

	void clear();

public:
	std::vector<WznmQQcoList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
