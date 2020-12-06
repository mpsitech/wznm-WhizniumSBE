/**
	* \file WznmQVer1NBlock.h
	* API code for table TblWznmQVer1NBlock (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NBLOCK_H
#define WZNMQVER1NBLOCK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NBlock
	*/
class WznmQVer1NBlock {

public:
	WznmQVer1NBlock(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NBlock
	*/
class ListWznmQVer1NBlock {

public:
	ListWznmQVer1NBlock();
	ListWznmQVer1NBlock(const ListWznmQVer1NBlock& src);
	ListWznmQVer1NBlock& operator=(const ListWznmQVer1NBlock& src);
	~ListWznmQVer1NBlock();

	void clear();

public:
	std::vector<WznmQVer1NBlock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
