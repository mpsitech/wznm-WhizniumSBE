/**
	* \file WznmQLibMNOppack.h
	* API code for table TblWznmQLibMNOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

