/**
	* \file WznmQIexHk1NVector.h
	* API code for table TblWznmQIexHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIEXHK1NVECTOR_H
#define WZNMQIEXHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQIexHk1NVector
	*/
class WznmQIexHk1NVector {

public:
	WznmQIexHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQIexHk1NVector
	*/
class ListWznmQIexHk1NVector {

public:
	ListWznmQIexHk1NVector();
	ListWznmQIexHk1NVector(const ListWznmQIexHk1NVector& src);
	ListWznmQIexHk1NVector& operator=(const ListWznmQIexHk1NVector& src);
	~ListWznmQIexHk1NVector();

	void clear();

public:
	std::vector<WznmQIexHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
