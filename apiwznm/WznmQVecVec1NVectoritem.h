/**
	* \file WznmQVecVec1NVectoritem.h
	* API code for table TblWznmQVecVec1NVectoritem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQVECVEC1NVECTORITEM_H
#define WZNMQVECVEC1NVECTORITEM_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVecVec1NVectoritem
	*/
class WznmQVecVec1NVectoritem {

public:
	WznmQVecVec1NVectoritem(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVecVec1NVectoritem
	*/
class ListWznmQVecVec1NVectoritem {

public:
	ListWznmQVecVec1NVectoritem();
	ListWznmQVecVec1NVectoritem(const ListWznmQVecVec1NVectoritem& src);
	ListWznmQVecVec1NVectoritem& operator=(const ListWznmQVecVec1NVectoritem& src);
	~ListWznmQVecVec1NVectoritem();

	void clear();

public:
	std::vector<WznmQVecVec1NVectoritem*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

