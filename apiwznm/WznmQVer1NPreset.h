/**
	* \file WznmQVer1NPreset.h
	* API code for table TblWznmQVer1NPreset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NPRESET_H
#define WZNMQVER1NPRESET_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NPreset
	*/
class WznmQVer1NPreset {

public:
	WznmQVer1NPreset(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NPreset
	*/
class ListWznmQVer1NPreset {

public:
	ListWznmQVer1NPreset();
	ListWznmQVer1NPreset(const ListWznmQVer1NPreset& src);
	ListWznmQVer1NPreset& operator=(const ListWznmQVer1NPreset& src);
	~ListWznmQVer1NPreset();

	void clear();

public:
	std::vector<WznmQVer1NPreset*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

