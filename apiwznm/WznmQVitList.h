/**
	* \file WznmQVitList.h
	* API code for table TblWznmQVitList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVITLIST_H
#define WZNMQVITLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVitList
	*/
class WznmQVitList {

public:
	WznmQVitList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubVecRefWznmMVector = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubVecRefWznmMVector;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVitList
	*/
class ListWznmQVitList {

public:
	ListWznmQVitList();
	ListWznmQVitList(const ListWznmQVitList& src);
	ListWznmQVitList& operator=(const ListWznmQVitList& src);
	~ListWznmQVitList();

	void clear();

public:
	std::vector<WznmQVitList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

