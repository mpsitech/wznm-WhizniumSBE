/**
	* \file WznmQImeHk1NVector.h
	* API code for table TblWznmQImeHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIMEHK1NVECTOR_H
#define WZNMQIMEHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQImeHk1NVector
	*/
class WznmQImeHk1NVector {

public:
	WznmQImeHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQImeHk1NVector
	*/
class ListWznmQImeHk1NVector {

public:
	ListWznmQImeHk1NVector();
	ListWznmQImeHk1NVector(const ListWznmQImeHk1NVector& src);
	ListWznmQImeHk1NVector& operator=(const ListWznmQImeHk1NVector& src);
	~ListWznmQImeHk1NVector();

	void clear();

public:
	std::vector<WznmQImeHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

