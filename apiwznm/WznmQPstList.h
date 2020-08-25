/**
	* \file WznmQPstList.h
	* API code for table TblWznmQPstList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQPSTLIST_H
#define WZNMQPSTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPstList
	*/
class WznmQPstList {

public:
	WznmQPstList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubRefWznmMVersion = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string srefIxWznmWArgtype = "", const std::string titIxWznmWArgtype = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubRefWznmMVersion;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string srefIxWznmWArgtype;
	std::string titIxWznmWArgtype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPstList
	*/
class ListWznmQPstList {

public:
	ListWznmQPstList();
	ListWznmQPstList(const ListWznmQPstList& src);
	ListWznmQPstList& operator=(const ListWznmQPstList& src);
	~ListWznmQPstList();

	void clear();

public:
	std::vector<WznmQPstList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

