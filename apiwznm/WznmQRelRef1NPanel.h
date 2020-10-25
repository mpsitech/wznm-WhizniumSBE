/**
	* \file WznmQRelRef1NPanel.h
	* API code for table TblWznmQRelRef1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQRELREF1NPANEL_H
#define WZNMQRELREF1NPANEL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRelRef1NPanel
	*/
class WznmQRelRef1NPanel {

public:
	WznmQRelRef1NPanel(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRelRef1NPanel
	*/
class ListWznmQRelRef1NPanel {

public:
	ListWznmQRelRef1NPanel();
	ListWznmQRelRef1NPanel(const ListWznmQRelRef1NPanel& src);
	ListWznmQRelRef1NPanel& operator=(const ListWznmQRelRef1NPanel& src);
	~ListWznmQRelRef1NPanel();

	void clear();

public:
	std::vector<WznmQRelRef1NPanel*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

