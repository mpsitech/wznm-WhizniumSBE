/**
	* \file WznmQVecList.h
	* API code for table TblWznmQVecList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECLIST_H
#define WZNMQVECLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVecList
	*/
class WznmQVecList {

public:
	WznmQVecList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "", const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const std::string stubHkUref = "", const std::string osrefWznmKTaggrp = "", const std::string titOsrefWznmKTaggrp = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMVersion;
	std::string srefHkIxVTbl;
	std::string titHkIxVTbl;
	std::string stubHkUref;
	std::string osrefWznmKTaggrp;
	std::string titOsrefWznmKTaggrp;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVecList
	*/
class ListWznmQVecList {

public:
	ListWznmQVecList();
	ListWznmQVecList(const ListWznmQVecList& src);
	ListWznmQVecList& operator=(const ListWznmQVecList& src);
	~ListWznmQVecList();

	void clear();

public:
	std::vector<WznmQVecList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

