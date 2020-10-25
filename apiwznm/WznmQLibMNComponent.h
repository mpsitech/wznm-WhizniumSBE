/**
	* \file WznmQLibMNComponent.h
	* API code for table TblWznmQLibMNComponent (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQLIBMNCOMPONENT_H
#define WZNMQLIBMNCOMPONENT_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLibMNComponent
	*/
class WznmQLibMNComponent {

public:
	WznmQLibMNComponent(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLibMNComponent
	*/
class ListWznmQLibMNComponent {

public:
	ListWznmQLibMNComponent();
	ListWznmQLibMNComponent(const ListWznmQLibMNComponent& src);
	ListWznmQLibMNComponent& operator=(const ListWznmQLibMNComponent& src);
	~ListWznmQLibMNComponent();

	void clear();

public:
	std::vector<WznmQLibMNComponent*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

