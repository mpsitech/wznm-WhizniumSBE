/**
	* \file WznmQQryList.h
	* API code for table TblWznmQQryList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYLIST_H
#define WZNMQQRYLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQryList
	*/
class WznmQQryList {

public:
	WznmQQryList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "", const std::string stubSupRefWznmMQuery = "", const std::string srefSupIxVSubrole = "", const std::string titSupIxVSubrole = "", const std::string stubRefWznmMTable = "", const std::string stubQtbRefWznmMTable = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMVersion;
	std::string stubSupRefWznmMQuery;
	std::string srefSupIxVSubrole;
	std::string titSupIxVSubrole;
	std::string stubRefWznmMTable;
	std::string stubQtbRefWznmMTable;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQryList
	*/
class ListWznmQQryList {

public:
	ListWznmQQryList();
	ListWznmQQryList(const ListWznmQQryList& src);
	ListWznmQQryList& operator=(const ListWznmQQryList& src);
	~ListWznmQQryList();

	void clear();

public:
	std::vector<WznmQQryList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
