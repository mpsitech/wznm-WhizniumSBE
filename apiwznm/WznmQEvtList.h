/**
	* \file WznmQEvtList.h
	* API code for table TblWznmQEvtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQEVTLIST_H
#define WZNMQEVTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQEvtList
	*/
class WznmQEvtList {

public:
	WznmQEvtList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWznmMApp = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWznmMApp;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQEvtList
	*/
class ListWznmQEvtList {

public:
	ListWznmQEvtList();
	ListWznmQEvtList(const ListWznmQEvtList& src);
	ListWznmQEvtList& operator=(const ListWznmQEvtList& src);
	~ListWznmQEvtList();

	void clear();

public:
	std::vector<WznmQEvtList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

