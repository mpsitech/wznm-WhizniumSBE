/**
	* \file WznmQTblRef1NPanel.h
	* API code for table TblWznmQTblRef1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTBLREF1NPANEL_H
#define WZNMQTBLREF1NPANEL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblRef1NPanel
	*/
class WznmQTblRef1NPanel {

public:
	WznmQTblRef1NPanel(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblRef1NPanel
	*/
class ListWznmQTblRef1NPanel {

public:
	ListWznmQTblRef1NPanel();
	ListWznmQTblRef1NPanel(const ListWznmQTblRef1NPanel& src);
	ListWznmQTblRef1NPanel& operator=(const ListWznmQTblRef1NPanel& src);
	~ListWznmQTblRef1NPanel();

	void clear();

public:
	std::vector<WznmQTblRef1NPanel*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

