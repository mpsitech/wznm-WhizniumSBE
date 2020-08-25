/**
	* \file WznmQLibAPkglist.h
	* API code for table TblWznmQLibAPkglist (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQLIBAPKGLIST_H
#define WZNMQLIBAPKGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLibAPkglist
	*/
class WznmQLibAPkglist {

public:
	WznmQLibAPkglist(const Sbecore::uint jnum = 0, const std::string srefX1RefIxVTbl = "", const std::string titX1RefIxVTbl = "", const std::string stubX1RefUref = "", const std::string Pkglist = "");

public:
	Sbecore::uint jnum;
	std::string srefX1RefIxVTbl;
	std::string titX1RefIxVTbl;
	std::string stubX1RefUref;
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

