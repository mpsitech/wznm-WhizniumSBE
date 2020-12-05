/**
	* \file WznmQJobRef1NBlock.h
	* API code for table TblWznmQJobRef1NBlock (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBREF1NBLOCK_H
#define WZNMQJOBREF1NBLOCK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobRef1NBlock
	*/
class WznmQJobRef1NBlock {

public:
	WznmQJobRef1NBlock(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobRef1NBlock
	*/
class ListWznmQJobRef1NBlock {

public:
	ListWznmQJobRef1NBlock();
	ListWznmQJobRef1NBlock(const ListWznmQJobRef1NBlock& src);
	ListWznmQJobRef1NBlock& operator=(const ListWznmQJobRef1NBlock& src);
	~ListWznmQJobRef1NBlock();

	void clear();

public:
	std::vector<WznmQJobRef1NBlock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

