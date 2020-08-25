/**
	* \file WznmQVecRef1NPanel.h
	* API code for table TblWznmQVecRef1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQVECREF1NPANEL_H
#define WZNMQVECREF1NPANEL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVecRef1NPanel
	*/
class WznmQVecRef1NPanel {

public:
	WznmQVecRef1NPanel(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVecRef1NPanel
	*/
class ListWznmQVecRef1NPanel {

public:
	ListWznmQVecRef1NPanel();
	ListWznmQVecRef1NPanel(const ListWznmQVecRef1NPanel& src);
	ListWznmQVecRef1NPanel& operator=(const ListWznmQVecRef1NPanel& src);
	~ListWznmQVecRef1NPanel();

	void clear();

public:
	std::vector<WznmQVecRef1NPanel*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

