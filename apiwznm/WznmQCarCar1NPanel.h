/**
	* \file WznmQCarCar1NPanel.h
	* API code for table TblWznmQCarCar1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

