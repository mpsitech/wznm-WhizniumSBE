/**
	* \file WznmQVitList.h
	* API code for table TblWznmQVitList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

