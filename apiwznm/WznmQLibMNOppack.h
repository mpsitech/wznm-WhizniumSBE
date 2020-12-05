/**
	* \file WznmQLibMNOppack.h
	* API code for table TblWznmQLibMNOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQLIBMNOPPACK_H
#define WZNMQLIBMNOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLibMNOppack
	*/
class WznmQLibMNOppack {

public:
	WznmQLibMNOppack(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLibMNOppack
	*/
class ListWznmQLibMNOppack {

public:
	ListWznmQLibMNOppack();
	ListWznmQLibMNOppack(const ListWznmQLibMNOppack& src);
	ListWznmQLibMNOppack& operator=(const ListWznmQLibMNOppack& src);
	~ListWznmQLibMNOppack();

	void clear();

public:
	std::vector<WznmQLibMNOppack*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

