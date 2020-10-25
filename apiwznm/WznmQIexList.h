/**
	* \file WznmQIexList.h
	* API code for table TblWznmQIexList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQIEXLIST_H
#define WZNMQIEXLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQIexList
	*/
class WznmQIexList {

public:
	WznmQIexList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Short = "", const std::string Title = "", const std::string stubRefWznmMVersion = "", const std::string Minversion = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Short;
	std::string Title;
	std::string stubRefWznmMVersion;
	std::string Minversion;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQIexList
	*/
class ListWznmQIexList {

public:
	ListWznmQIexList();
	ListWznmQIexList(const ListWznmQIexList& src);
	ListWznmQIexList& operator=(const ListWznmQIexList& src);
	~ListWznmQIexList();

	void clear();

public:
	std::vector<WznmQIexList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

