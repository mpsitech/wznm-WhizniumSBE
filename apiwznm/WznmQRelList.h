/**
	* \file WznmQRelList.h
	* API code for table TblWznmQRelList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQRELLIST_H
#define WZNMQRELLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRelList
	*/
class WznmQRelList {

public:
	WznmQRelList(const Sbecore::uint jnum = 0, const std::string stubFrRefWznmMTable = "", const std::string stubFrsRefWznmMSubset = "", const std::string stubToRefWznmMTable = "", const std::string stubTosRefWznmMSubset = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "", const std::string stubSupRefWznmMRelation = "", const std::string srefSupIxVSubrole = "", const std::string titSupIxVSubrole = "", const std::string stubRefWznmMTable = "", const std::string Prefix = "");

public:
	Sbecore::uint jnum;
	std::string stubFrRefWznmMTable;
	std::string stubFrsRefWznmMSubset;
	std::string stubToRefWznmMTable;
	std::string stubTosRefWznmMSubset;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMVersion;
	std::string stubSupRefWznmMRelation;
	std::string srefSupIxVSubrole;
	std::string titSupIxVSubrole;
	std::string stubRefWznmMTable;
	std::string Prefix;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRelList
	*/
class ListWznmQRelList {

public:
	ListWznmQRelList();
	ListWznmQRelList(const ListWznmQRelList& src);
	ListWznmQRelList& operator=(const ListWznmQRelList& src);
	~ListWznmQRelList();

	void clear();

public:
	std::vector<WznmQRelList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

