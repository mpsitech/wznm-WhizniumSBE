/**
	* \file WznmQOpkRef1NBlock.h
	* API code for table TblWznmQOpkRef1NBlock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQOPKREF1NBLOCK_H
#define WZNMQOPKREF1NBLOCK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpkRef1NBlock
	*/
class WznmQOpkRef1NBlock {

public:
	WznmQOpkRef1NBlock(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpkRef1NBlock
	*/
class ListWznmQOpkRef1NBlock {

public:
	ListWznmQOpkRef1NBlock();
	ListWznmQOpkRef1NBlock(const ListWznmQOpkRef1NBlock& src);
	ListWznmQOpkRef1NBlock& operator=(const ListWznmQOpkRef1NBlock& src);
	~ListWznmQOpkRef1NBlock();

	void clear();

public:
	std::vector<WznmQOpkRef1NBlock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

