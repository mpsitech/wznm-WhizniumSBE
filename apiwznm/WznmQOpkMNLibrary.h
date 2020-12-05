/**
	* \file WznmQOpkMNLibrary.h
	* API code for table TblWznmQOpkMNLibrary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKMNLIBRARY_H
#define WZNMQOPKMNLIBRARY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpkMNLibrary
	*/
class WznmQOpkMNLibrary {

public:
	WznmQOpkMNLibrary(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpkMNLibrary
	*/
class ListWznmQOpkMNLibrary {

public:
	ListWznmQOpkMNLibrary();
	ListWznmQOpkMNLibrary(const ListWznmQOpkMNLibrary& src);
	ListWznmQOpkMNLibrary& operator=(const ListWznmQOpkMNLibrary& src);
	~ListWznmQOpkMNLibrary();

	void clear();

public:
	std::vector<WznmQOpkMNLibrary*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

