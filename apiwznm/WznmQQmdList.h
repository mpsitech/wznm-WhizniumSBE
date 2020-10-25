/**
	* \file WznmQQmdList.h
	* API code for table TblWznmQQmdList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQQMDLIST_H
#define WZNMQQMDLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQmdList
	*/
class WznmQQmdList {

public:
	WznmQQmdList(const Sbecore::uint jnum = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubQryRefWznmMQuery = "", const std::string stubRefWznmMPreset = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "");

public:
	Sbecore::uint jnum;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubQryRefWznmMQuery;
	std::string stubRefWznmMPreset;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQmdList
	*/
class ListWznmQQmdList {

public:
	ListWznmQQmdList();
	ListWznmQQmdList(const ListWznmQQmdList& src);
	ListWznmQQmdList& operator=(const ListWznmQQmdList& src);
	~ListWznmQQmdList();

	void clear();

public:
	std::vector<WznmQQmdList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

