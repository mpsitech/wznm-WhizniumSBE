/**
	* \file WznmQConList.h
	* API code for table TblWznmQConList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCONLIST_H
#define WZNMQCONLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQConList
	*/
class WznmQConList {

public:
	WznmQConList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const std::string stubHkUref = "", const std::string srefHkIxVSection = "", const std::string titHkIxVSection = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string stubSupRefWznmMControl = "", const std::string srefIxVSubtype = "", const std::string titIxVSubtype = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string srefHkIxVTbl;
	std::string titHkIxVTbl;
	std::string stubHkUref;
	std::string srefHkIxVSection;
	std::string titHkIxVSection;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string stubSupRefWznmMControl;
	std::string srefIxVSubtype;
	std::string titIxVSubtype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQConList
	*/
class ListWznmQConList {

public:
	ListWznmQConList();
	ListWznmQConList(const ListWznmQConList& src);
	ListWznmQConList& operator=(const ListWznmQConList& src);
	~ListWznmQConList();

	void clear();

public:
	std::vector<WznmQConList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
