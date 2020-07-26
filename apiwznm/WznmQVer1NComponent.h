/**
	* \file WznmQVer1NComponent.h
	* API code for table TblWznmQVer1NComponent (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQVER1NCOMPONENT_H
#define WZNMQVER1NCOMPONENT_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NComponent
	*/
class WznmQVer1NComponent {

public:
	WznmQVer1NComponent(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NComponent
	*/
class ListWznmQVer1NComponent {

public:
	ListWznmQVer1NComponent();
	ListWznmQVer1NComponent(const ListWznmQVer1NComponent& src);
	ListWznmQVer1NComponent& operator=(const ListWznmQVer1NComponent& src);
	~ListWznmQVer1NComponent();

	void clear();

public:
	std::vector<WznmQVer1NComponent*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

