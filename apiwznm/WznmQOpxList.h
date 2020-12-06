/**
	* \file WznmQOpxList.h
	* API code for table TblWznmQOpxList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPXLIST_H
#define WZNMQOPXLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpxList
	*/
class WznmQOpxList {

public:
	WznmQOpxList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWznmMOppack = "", const std::string yesnoShrdat = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWznmMOppack;
	std::string yesnoShrdat;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpxList
	*/
class ListWznmQOpxList {

public:
	ListWznmQOpxList();
	ListWznmQOpxList(const ListWznmQOpxList& src);
	ListWznmQOpxList& operator=(const ListWznmQOpxList& src);
	~ListWznmQOpxList();

	void clear();

public:
	std::vector<WznmQOpxList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
