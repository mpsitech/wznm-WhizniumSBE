/**
	* \file WznmQTblHk1NVector.h
	* API code for table TblWznmQTblHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLHK1NVECTOR_H
#define WZNMQTBLHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblHk1NVector
	*/
class WznmQTblHk1NVector {

public:
	WznmQTblHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblHk1NVector
	*/
class ListWznmQTblHk1NVector {

public:
	ListWznmQTblHk1NVector();
	ListWznmQTblHk1NVector(const ListWznmQTblHk1NVector& src);
	ListWznmQTblHk1NVector& operator=(const ListWznmQTblHk1NVector& src);
	~ListWznmQTblHk1NVector();

	void clear();

public:
	std::vector<WznmQTblHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
