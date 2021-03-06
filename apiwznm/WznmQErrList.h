/**
	* \file WznmQErrList.h
	* API code for table TblWznmQErrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQERRLIST_H
#define WZNMQERRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQErrList
	*/
class WznmQErrList {

public:
	WznmQErrList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubVerRefWznmMVersion = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubVerRefWznmMVersion;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQErrList
	*/
class ListWznmQErrList {

public:
	ListWznmQErrList();
	ListWznmQErrList(const ListWznmQErrList& src);
	ListWznmQErrList& operator=(const ListWznmQErrList& src);
	~ListWznmQErrList();

	void clear();

public:
	std::vector<WznmQErrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
