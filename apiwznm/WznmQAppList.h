/**
	* \file WznmQAppList.h
	* API code for table TblWznmQAppList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQAPPLIST_H
#define WZNMQAPPLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQAppList
	*/
class WznmQAppList {

public:
	WznmQAppList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const std::string srefIxVTarget = "", const std::string titIxVTarget = "", const std::string stubVerRefWznmMVersion = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Short;
	std::string Title;
	std::string srefIxVTarget;
	std::string titIxVTarget;
	std::string stubVerRefWznmMVersion;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQAppList
	*/
class ListWznmQAppList {

public:
	ListWznmQAppList();
	ListWznmQAppList(const ListWznmQAppList& src);
	ListWznmQAppList& operator=(const ListWznmQAppList& src);
	~ListWznmQAppList();

	void clear();

public:
	std::vector<WznmQAppList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
