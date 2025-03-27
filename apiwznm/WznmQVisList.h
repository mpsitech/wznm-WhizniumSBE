/**
	* \file WznmQVisList.h
	* API code for table TblWznmQVisList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISLIST_H
#define WZNMQVISLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVisList
	*/
class WznmQVisList {

public:
	WznmQVisList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubVerRefWznmMVersion = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubVerRefWznmMVersion;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVisList
	*/
class ListWznmQVisList {

public:
	ListWznmQVisList();
	ListWznmQVisList(const ListWznmQVisList& src);
	ListWznmQVisList& operator=(const ListWznmQVisList& src);
	~ListWznmQVisList();

	void clear();

public:
	std::vector<WznmQVisList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
