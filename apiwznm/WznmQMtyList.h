/**
	* \file WznmQMtyList.h
	* API code for table TblWznmQMtyList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQMTYLIST_H
#define WZNMQMTYLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMtyList
	*/
class WznmQMtyList {

public:
	WznmQMtyList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVArch = "", const std::string titIxVArch = "", const std::string srefKOs = "", const std::string titSrefKOs = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVArch;
	std::string titIxVArch;
	std::string srefKOs;
	std::string titSrefKOs;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMtyList
	*/
class ListWznmQMtyList {

public:
	ListWznmQMtyList();
	ListWznmQMtyList(const ListWznmQMtyList& src);
	ListWznmQMtyList& operator=(const ListWznmQMtyList& src);
	~ListWznmQMtyList();

	void clear();

public:
	std::vector<WznmQMtyList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

