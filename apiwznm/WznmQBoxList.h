/**
	* \file WznmQBoxList.h
	* API code for table TblWznmQBoxList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQBOXLIST_H
#define WZNMQBOXLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQBoxList
	*/
class WznmQBoxList {

public:
	WznmQBoxList(const Sbecore::uint jnum = 0, const std::string stubRefWznmMSheet = "", const std::string srefUnvIxWznmVMaintable = "", const std::string titUnvIxWznmVMaintable = "", const std::string stubUnvUref = "");

public:
	Sbecore::uint jnum;
	std::string stubRefWznmMSheet;
	std::string srefUnvIxWznmVMaintable;
	std::string titUnvIxWznmVMaintable;
	std::string stubUnvUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQBoxList
	*/
class ListWznmQBoxList {

public:
	ListWznmQBoxList();
	ListWznmQBoxList(const ListWznmQBoxList& src);
	ListWznmQBoxList& operator=(const ListWznmQBoxList& src);
	~ListWznmQBoxList();

	void clear();

public:
	std::vector<WznmQBoxList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
