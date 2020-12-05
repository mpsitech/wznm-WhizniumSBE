/**
	* \file WznmQLibAPkglist.h
	* API code for table TblWznmQLibAPkglist (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQLIBAPKGLIST_H
#define WZNMQLIBAPKGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLibAPkglist
	*/
class WznmQLibAPkglist {

public:
	WznmQLibAPkglist(const Sbecore::uint jnum = 0, const std::string stubX1RefWznmMMachine = "", const std::string Pkglist = "");

public:
	Sbecore::uint jnum;
	std::string stubX1RefWznmMMachine;
	std::string Pkglist;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLibAPkglist
	*/
class ListWznmQLibAPkglist {

public:
	ListWznmQLibAPkglist();
	ListWznmQLibAPkglist(const ListWznmQLibAPkglist& src);
	ListWznmQLibAPkglist& operator=(const ListWznmQLibAPkglist& src);
	~ListWznmQLibAPkglist();

	void clear();

public:
	std::vector<WznmQLibAPkglist*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

