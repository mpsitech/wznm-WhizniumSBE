/**
	* \file WznmQBlkList.h
	* API code for table TblWznmQBlkList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQBLKLIST_H
#define WZNMQBLKLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQBlkList
	*/
class WznmQBlkList {

public:
	WznmQBlkList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "");

public:
	Sbecore::uint jnum;
	std::string sref;
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
	* ListWznmQBlkList
	*/
class ListWznmQBlkList {

public:
	ListWznmQBlkList();
	ListWznmQBlkList(const ListWznmQBlkList& src);
	ListWznmQBlkList& operator=(const ListWznmQBlkList& src);
	~ListWznmQBlkList();

	void clear();

public:
	std::vector<WznmQBlkList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
