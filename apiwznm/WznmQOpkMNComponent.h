/**
	* \file WznmQOpkMNComponent.h
	* API code for table TblWznmQOpkMNComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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

