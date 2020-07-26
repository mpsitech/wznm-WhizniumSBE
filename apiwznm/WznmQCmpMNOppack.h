/**
	* \file WznmQCmpMNOppack.h
	* API code for table TblWznmQCmpMNOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCMPMNOPPACK_H
#define WZNMQCMPMNOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCmpMNOppack
	*/
class WznmQCmpMNOppack {

public:
	WznmQCmpMNOppack(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCmpMNOppack
	*/
class ListWznmQCmpMNOppack {

public:
	ListWznmQCmpMNOppack();
	ListWznmQCmpMNOppack(const ListWznmQCmpMNOppack& src);
	ListWznmQCmpMNOppack& operator=(const ListWznmQCmpMNOppack& src);
	~ListWznmQCmpMNOppack();

	void clear();

public:
	std::vector<WznmQCmpMNOppack*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

