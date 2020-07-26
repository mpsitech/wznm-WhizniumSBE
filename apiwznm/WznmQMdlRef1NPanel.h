/**
	* \file WznmQMdlRef1NPanel.h
	* API code for table TblWznmQMdlRef1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQMDLREF1NPANEL_H
#define WZNMQMDLREF1NPANEL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMdlRef1NPanel
	*/
class WznmQMdlRef1NPanel {

public:
	WznmQMdlRef1NPanel(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMdlRef1NPanel
	*/
class ListWznmQMdlRef1NPanel {

public:
	ListWznmQMdlRef1NPanel();
	ListWznmQMdlRef1NPanel(const ListWznmQMdlRef1NPanel& src);
	ListWznmQMdlRef1NPanel& operator=(const ListWznmQMdlRef1NPanel& src);
	~ListWznmQMdlRef1NPanel();

	void clear();

public:
	std::vector<WznmQMdlRef1NPanel*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

