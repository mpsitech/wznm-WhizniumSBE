/**
	* \file WznmQVer1NVector.h
	* API code for table TblWznmQVer1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NVECTOR_H
#define WZNMQVER1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NVector
	*/
class WznmQVer1NVector {

public:
	WznmQVer1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NVector
	*/
class ListWznmQVer1NVector {

public:
	ListWznmQVer1NVector();
	ListWznmQVer1NVector(const ListWznmQVer1NVector& src);
	ListWznmQVer1NVector& operator=(const ListWznmQVer1NVector& src);
	~ListWznmQVer1NVector();

	void clear();

public:
	std::vector<WznmQVer1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
