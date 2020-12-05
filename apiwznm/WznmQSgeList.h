/**
	* \file WznmQSgeList.h
	* API code for table TblWznmQSgeList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSGELIST_H
#define WZNMQSGELIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSgeList
	*/
class WznmQSgeList {

public:
	WznmQSgeList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubJobRefWznmMJob = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubJobRefWznmMJob;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSgeList
	*/
class ListWznmQSgeList {

public:
	ListWznmQSgeList();
	ListWznmQSgeList(const ListWznmQSgeList& src);
	ListWznmQSgeList& operator=(const ListWznmQSgeList& src);
	~ListWznmQSgeList();

	void clear();

public:
	std::vector<WznmQSgeList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

