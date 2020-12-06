/**
	* \file WznmQVer1NOppack.h
	* API code for table TblWznmQVer1NOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NOPPACK_H
#define WZNMQVER1NOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NOppack
	*/
class WznmQVer1NOppack {

public:
	WznmQVer1NOppack(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NOppack
	*/
class ListWznmQVer1NOppack {

public:
	ListWznmQVer1NOppack();
	ListWznmQVer1NOppack(const ListWznmQVer1NOppack& src);
	ListWznmQVer1NOppack& operator=(const ListWznmQVer1NOppack& src);
	~ListWznmQVer1NOppack();

	void clear();

public:
	std::vector<WznmQVer1NOppack*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
