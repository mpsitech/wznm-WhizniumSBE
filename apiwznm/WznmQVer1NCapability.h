/**
	* \file WznmQVer1NCapability.h
	* API code for table TblWznmQVer1NCapability (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQVER1NCAPABILITY_H
#define WZNMQVER1NCAPABILITY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NCapability
	*/
class WznmQVer1NCapability {

public:
	WznmQVer1NCapability(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NCapability
	*/
class ListWznmQVer1NCapability {

public:
	ListWznmQVer1NCapability();
	ListWznmQVer1NCapability(const ListWznmQVer1NCapability& src);
	ListWznmQVer1NCapability& operator=(const ListWznmQVer1NCapability& src);
	~ListWznmQVer1NCapability();

	void clear();

public:
	std::vector<WznmQVer1NCapability*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

