/**
	* \file WznmQCarCar1NPanel.h
	* API code for table TblWznmQCarCar1NPanel (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCARCAR1NPANEL_H
#define WZNMQCARCAR1NPANEL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCarCar1NPanel
	*/
class WznmQCarCar1NPanel {

public:
	WznmQCarCar1NPanel(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCarCar1NPanel
	*/
class ListWznmQCarCar1NPanel {

public:
	ListWznmQCarCar1NPanel();
	ListWznmQCarCar1NPanel(const ListWznmQCarCar1NPanel& src);
	ListWznmQCarCar1NPanel& operator=(const ListWznmQCarCar1NPanel& src);
	~ListWznmQCarCar1NPanel();

	void clear();

public:
	std::vector<WznmQCarCar1NPanel*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
