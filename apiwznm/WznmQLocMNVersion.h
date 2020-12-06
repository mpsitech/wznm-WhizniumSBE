/**
	* \file WznmQLocMNVersion.h
	* API code for table TblWznmQLocMNVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQLOCMNVERSION_H
#define WZNMQLOCMNVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLocMNVersion
	*/
class WznmQLocMNVersion {

public:
	WznmQLocMNVersion(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLocMNVersion
	*/
class ListWznmQLocMNVersion {

public:
	ListWznmQLocMNVersion();
	ListWznmQLocMNVersion(const ListWznmQLocMNVersion& src);
	ListWznmQLocMNVersion& operator=(const ListWznmQLocMNVersion& src);
	~ListWznmQLocMNVersion();

	void clear();

public:
	std::vector<WznmQLocMNVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
