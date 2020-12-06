/**
	* \file WznmQOpxRef1NBlock.h
	* API code for table TblWznmQOpxRef1NBlock (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPXREF1NBLOCK_H
#define WZNMQOPXREF1NBLOCK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpxRef1NBlock
	*/
class WznmQOpxRef1NBlock {

public:
	WznmQOpxRef1NBlock(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpxRef1NBlock
	*/
class ListWznmQOpxRef1NBlock {

public:
	ListWznmQOpxRef1NBlock();
	ListWznmQOpxRef1NBlock(const ListWznmQOpxRef1NBlock& src);
	ListWznmQOpxRef1NBlock& operator=(const ListWznmQOpxRef1NBlock& src);
	~ListWznmQOpxRef1NBlock();

	void clear();

public:
	std::vector<WznmQOpxRef1NBlock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
