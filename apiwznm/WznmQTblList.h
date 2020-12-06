/**
	* \file WznmQTblList.h
	* API code for table TblWznmQTblList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLLIST_H
#define WZNMQTBLLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblList
	*/
class WznmQTblList {

public:
	WznmQTblList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Short = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Short;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMVersion;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblList
	*/
class ListWznmQTblList {

public:
	ListWznmQTblList();
	ListWznmQTblList(const ListWznmQTblList& src);
	ListWznmQTblList& operator=(const ListWznmQTblList& src);
	~ListWznmQTblList();

	void clear();

public:
	std::vector<WznmQTblList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
