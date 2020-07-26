/**
	* \file WznmQCmpMNLibrary.h
	* API code for table TblWznmQCmpMNLibrary (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

