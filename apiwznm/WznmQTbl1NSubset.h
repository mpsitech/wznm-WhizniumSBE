/**
	* \file WznmQTbl1NSubset.h
	* API code for table TblWznmQTbl1NSubset (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTBL1NSUBSET_H
#define WZNMQTBL1NSUBSET_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTbl1NSubset
	*/
class WznmQTbl1NSubset {

public:
	WznmQTbl1NSubset(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTbl1NSubset
	*/
class ListWznmQTbl1NSubset {

public:
	ListWznmQTbl1NSubset();
	ListWznmQTbl1NSubset(const ListWznmQTbl1NSubset& src);
	ListWznmQTbl1NSubset& operator=(const ListWznmQTbl1NSubset& src);
	~ListWznmQTbl1NSubset();

	void clear();

public:
	std::vector<WznmQTbl1NSubset*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

