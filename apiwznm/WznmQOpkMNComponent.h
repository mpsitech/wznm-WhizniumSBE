/**
	* \file WznmQOpkMNComponent.h
	* API code for table TblWznmQOpkMNComponent (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQOPKMNCOMPONENT_H
#define WZNMQOPKMNCOMPONENT_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpkMNComponent
	*/
class WznmQOpkMNComponent {

public:
	WznmQOpkMNComponent(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpkMNComponent
	*/
class ListWznmQOpkMNComponent {

public:
	ListWznmQOpkMNComponent();
	ListWznmQOpkMNComponent(const ListWznmQOpkMNComponent& src);
	ListWznmQOpkMNComponent& operator=(const ListWznmQOpkMNComponent& src);
	~ListWznmQOpkMNComponent();

	void clear();

public:
	std::vector<WznmQOpkMNComponent*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

