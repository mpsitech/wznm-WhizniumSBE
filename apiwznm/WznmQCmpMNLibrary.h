/**
	* \file WznmQCmpMNLibrary.h
	* API code for table TblWznmQCmpMNLibrary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCMPMNLIBRARY_H
#define WZNMQCMPMNLIBRARY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCmpMNLibrary
	*/
class WznmQCmpMNLibrary {

public:
	WznmQCmpMNLibrary(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCmpMNLibrary
	*/
class ListWznmQCmpMNLibrary {

public:
	ListWznmQCmpMNLibrary();
	ListWznmQCmpMNLibrary(const ListWznmQCmpMNLibrary& src);
	ListWznmQCmpMNLibrary& operator=(const ListWznmQCmpMNLibrary& src);
	~ListWznmQCmpMNLibrary();

	void clear();

public:
	std::vector<WznmQCmpMNLibrary*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
