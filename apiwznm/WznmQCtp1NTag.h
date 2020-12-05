/**
	* \file WznmQCtp1NTag.h
	* API code for table TblWznmQCtp1NTag (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCTP1NTAG_H
#define WZNMQCTP1NTAG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCtp1NTag
	*/
class WznmQCtp1NTag {

public:
	WznmQCtp1NTag(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCtp1NTag
	*/
class ListWznmQCtp1NTag {

public:
	ListWznmQCtp1NTag();
	ListWznmQCtp1NTag(const ListWznmQCtp1NTag& src);
	ListWznmQCtp1NTag& operator=(const ListWznmQCtp1NTag& src);
	~ListWznmQCtp1NTag();

	void clear();

public:
	std::vector<WznmQCtp1NTag*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

