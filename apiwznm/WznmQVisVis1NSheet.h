/**
	* \file WznmQVisVis1NSheet.h
	* API code for table TblWznmQVisVis1NSheet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISVIS1NSHEET_H
#define WZNMQVISVIS1NSHEET_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVisVis1NSheet
	*/
class WznmQVisVis1NSheet {

public:
	WznmQVisVis1NSheet(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVisVis1NSheet
	*/
class ListWznmQVisVis1NSheet {

public:
	ListWznmQVisVis1NSheet();
	ListWznmQVisVis1NSheet(const ListWznmQVisVis1NSheet& src);
	ListWznmQVisVis1NSheet& operator=(const ListWznmQVisVis1NSheet& src);
	~ListWznmQVisVis1NSheet();

	void clear();

public:
	std::vector<WznmQVisVis1NSheet*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
