/**
	* \file WznmQConFedRef1NRtblock.h
	* API code for table TblWznmQConFedRef1NRtblock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQCONFEDREF1NRTBLOCK_H
#define WZNMQCONFEDREF1NRTBLOCK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQConFedRef1NRtblock
	*/
class WznmQConFedRef1NRtblock {

public:
	WznmQConFedRef1NRtblock(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQConFedRef1NRtblock
	*/
class ListWznmQConFedRef1NRtblock {

public:
	ListWznmQConFedRef1NRtblock();
	ListWznmQConFedRef1NRtblock(const ListWznmQConFedRef1NRtblock& src);
	ListWznmQConFedRef1NRtblock& operator=(const ListWznmQConFedRef1NRtblock& src);
	~ListWznmQConFedRef1NRtblock();

	void clear();

public:
	std::vector<WznmQConFedRef1NRtblock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

