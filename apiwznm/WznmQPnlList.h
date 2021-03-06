/**
	* \file WznmQPnlList.h
	* API code for table TblWznmQPnlList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPNLLIST_H
#define WZNMQPNLLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPnlList
	*/
class WznmQPnlList {

public:
	WznmQPnlList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubCarRefWznmMCard = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubCarRefWznmMCard;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPnlList
	*/
class ListWznmQPnlList {

public:
	ListWznmQPnlList();
	ListWznmQPnlList(const ListWznmQPnlList& src);
	ListWznmQPnlList& operator=(const ListWznmQPnlList& src);
	~ListWznmQPnlList();

	void clear();

public:
	std::vector<WznmQPnlList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
