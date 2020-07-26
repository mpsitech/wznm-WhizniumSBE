/**
	* \file WznmQBlkRef1NRtblock.h
	* API code for table TblWznmQBlkRef1NRtblock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQBLKREF1NRTBLOCK_H
#define WZNMQBLKREF1NRTBLOCK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQBlkRef1NRtblock
	*/
class WznmQBlkRef1NRtblock {

public:
	WznmQBlkRef1NRtblock(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQBlkRef1NRtblock
	*/
class ListWznmQBlkRef1NRtblock {

public:
	ListWznmQBlkRef1NRtblock();
	ListWznmQBlkRef1NRtblock(const ListWznmQBlkRef1NRtblock& src);
	ListWznmQBlkRef1NRtblock& operator=(const ListWznmQBlkRef1NRtblock& src);
	~ListWznmQBlkRef1NRtblock();

	void clear();

public:
	std::vector<WznmQBlkRef1NRtblock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

