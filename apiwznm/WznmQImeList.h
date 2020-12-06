/**
	* \file WznmQImeList.h
	* API code for table TblWznmQImeList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIMELIST_H
#define WZNMQIMELIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQImeList
	*/
class WznmQImeList {

public:
	WznmQImeList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWznmMImpexpcplx = "", const std::string stubSupRefWznmMImpexp = "", const std::string stubRefWznmMTable = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWznmMImpexpcplx;
	std::string stubSupRefWznmMImpexp;
	std::string stubRefWznmMTable;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQImeList
	*/
class ListWznmQImeList {

public:
	ListWznmQImeList();
	ListWznmQImeList(const ListWznmQImeList& src);
	ListWznmQImeList& operator=(const ListWznmQImeList& src);
	~ListWznmQImeList();

	void clear();

public:
	std::vector<WznmQImeList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
