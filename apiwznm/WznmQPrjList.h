/**
	* \file WznmQPrjList.h
	* API code for table TblWznmQPrjList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQPRJLIST_H
#define WZNMQPRJLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPrjList
	*/
class WznmQPrjList {

public:
	WznmQPrjList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const std::string stubRefWznmMVersion = "", const std::string Giturl = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Short;
	std::string Title;
	std::string stubRefWznmMVersion;
	std::string Giturl;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPrjList
	*/
class ListWznmQPrjList {

public:
	ListWznmQPrjList();
	ListWznmQPrjList(const ListWznmQPrjList& src);
	ListWznmQPrjList& operator=(const ListWznmQPrjList& src);
	~ListWznmQPrjList();

	void clear();

public:
	std::vector<WznmQPrjList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

