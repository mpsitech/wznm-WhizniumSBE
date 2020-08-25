/**
	* \file WznmQRtj1NRtdpch.h
	* API code for table TblWznmQRtj1NRtdpch (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQRTJ1NRTDPCH_H
#define WZNMQRTJ1NRTDPCH_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRtj1NRtdpch
	*/
class WznmQRtj1NRtdpch {

public:
	WznmQRtj1NRtdpch(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRtj1NRtdpch
	*/
class ListWznmQRtj1NRtdpch {

public:
	ListWznmQRtj1NRtdpch();
	ListWznmQRtj1NRtdpch(const ListWznmQRtj1NRtdpch& src);
	ListWznmQRtj1NRtdpch& operator=(const ListWznmQRtj1NRtdpch& src);
	~ListWznmQRtj1NRtdpch();

	void clear();

public:
	std::vector<WznmQRtj1NRtdpch*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

