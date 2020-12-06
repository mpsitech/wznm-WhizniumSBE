/**
	* \file WznmQSteList.h
	* API code for table TblWznmQSteList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSTELIST_H
#define WZNMQSTELIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSteList
	*/
class WznmQSteList {

public:
	WznmQSteList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubSeqRefWznmMSequence = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubSeqRefWznmMSequence;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSteList
	*/
class ListWznmQSteList {

public:
	ListWznmQSteList();
	ListWznmQSteList(const ListWznmQSteList& src);
	ListWznmQSteList& operator=(const ListWznmQSteList& src);
	~ListWznmQSteList();

	void clear();

public:
	std::vector<WznmQSteList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
