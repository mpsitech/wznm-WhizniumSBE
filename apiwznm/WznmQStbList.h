/**
	* \file WznmQStbList.h
	* API code for table TblWznmQStbList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQSTBLIST_H
#define WZNMQSTBLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQStbList
	*/
class WznmQStbList {

public:
	WznmQStbList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMTable = "", const std::string stubRefWznmMSubset = "", const std::string Example = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMTable;
	std::string stubRefWznmMSubset;
	std::string Example;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQStbList
	*/
class ListWznmQStbList {

public:
	ListWznmQStbList();
	ListWznmQStbList(const ListWznmQStbList& src);
	ListWznmQStbList& operator=(const ListWznmQStbList& src);
	~ListWznmQStbList();

	void clear();

public:
	std::vector<WznmQStbList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

