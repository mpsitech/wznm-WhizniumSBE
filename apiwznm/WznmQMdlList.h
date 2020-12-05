/**
	* \file WznmQMdlList.h
	* API code for table TblWznmQMdlList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMDLLIST_H
#define WZNMQMDLLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMdlList
	*/
class WznmQMdlList {

public:
	WznmQMdlList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubVerRefWznmMVersion = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubVerRefWznmMVersion;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMdlList
	*/
class ListWznmQMdlList {

public:
	ListWznmQMdlList();
	ListWznmQMdlList(const ListWznmQMdlList& src);
	ListWznmQMdlList& operator=(const ListWznmQMdlList& src);
	~ListWznmQMdlList();

	void clear();

public:
	std::vector<WznmQMdlList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

