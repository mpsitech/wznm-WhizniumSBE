/**
	* \file WznmQCmpList.h
	* API code for table TblWznmQCmpList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCMPLIST_H
#define WZNMQCMPLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCmpList
	*/
class WznmQCmpList {

public:
	WznmQCmpList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMVersion;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCmpList
	*/
class ListWznmQCmpList {

public:
	ListWznmQCmpList();
	ListWznmQCmpList(const ListWznmQCmpList& src);
	ListWznmQCmpList& operator=(const ListWznmQCmpList& src);
	~ListWznmQCmpList();

	void clear();

public:
	std::vector<WznmQCmpList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
