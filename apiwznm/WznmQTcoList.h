/**
	* \file WznmQTcoList.h
	* API code for table TblWznmQTcoList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTCOLIST_H
#define WZNMQTCOLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTcoList
	*/
class WznmQTcoList {

public:
	WznmQTcoList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Short = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubTblRefWznmMTable = "", const std::string srefFctIxVTbl = "", const std::string titFctIxVTbl = "", const std::string srefIxVSubtype = "", const std::string titIxVSubtype = "", const std::string srefIxVAxisfct = "", const std::string titIxVAxisfct = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Short;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubTblRefWznmMTable;
	std::string srefFctIxVTbl;
	std::string titFctIxVTbl;
	std::string srefIxVSubtype;
	std::string titIxVSubtype;
	std::string srefIxVAxisfct;
	std::string titIxVAxisfct;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTcoList
	*/
class ListWznmQTcoList {

public:
	ListWznmQTcoList();
	ListWznmQTcoList(const ListWznmQTcoList& src);
	ListWznmQTcoList& operator=(const ListWznmQTcoList& src);
	~ListWznmQTcoList();

	void clear();

public:
	std::vector<WznmQTcoList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

