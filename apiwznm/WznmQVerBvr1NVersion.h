/**
	* \file WznmQVerBvr1NVersion.h
	* API code for table TblWznmQVerBvr1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERBVR1NVERSION_H
#define WZNMQVERBVR1NVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVerBvr1NVersion
	*/
class WznmQVerBvr1NVersion {

public:
	WznmQVerBvr1NVersion(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVerBvr1NVersion
	*/
class ListWznmQVerBvr1NVersion {

public:
	ListWznmQVerBvr1NVersion();
	ListWznmQVerBvr1NVersion(const ListWznmQVerBvr1NVersion& src);
	ListWznmQVerBvr1NVersion& operator=(const ListWznmQVerBvr1NVersion& src);
	~ListWznmQVerBvr1NVersion();

	void clear();

public:
	std::vector<WznmQVerBvr1NVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

