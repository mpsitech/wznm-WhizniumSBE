/**
	* \file WznmQCarList.h
	* API code for table TblWznmQCarList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCARLIST_H
#define WZNMQCARLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCarList
	*/
class WznmQCarList {

public:
	WznmQCarList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubMdlRefWznmMModule = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubMdlRefWznmMModule;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCarList
	*/
class ListWznmQCarList {

public:
	ListWznmQCarList();
	ListWznmQCarList(const ListWznmQCarList& src);
	ListWznmQCarList& operator=(const ListWznmQCarList& src);
	~ListWznmQCarList();

	void clear();

public:
	std::vector<WznmQCarList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

