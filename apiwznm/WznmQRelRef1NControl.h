/**
	* \file WznmQRelRef1NControl.h
	* API code for table TblWznmQRelRef1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRELREF1NCONTROL_H
#define WZNMQRELREF1NCONTROL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRelRef1NControl
	*/
class WznmQRelRef1NControl {

public:
	WznmQRelRef1NControl(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRelRef1NControl
	*/
class ListWznmQRelRef1NControl {

public:
	ListWznmQRelRef1NControl();
	ListWznmQRelRef1NControl(const ListWznmQRelRef1NControl& src);
	ListWznmQRelRef1NControl& operator=(const ListWznmQRelRef1NControl& src);
	~ListWznmQRelRef1NControl();

	void clear();

public:
	std::vector<WznmQRelRef1NControl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
