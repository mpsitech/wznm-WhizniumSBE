/**
	* \file WznmQConSup1NControl.h
	* API code for table TblWznmQConSup1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCONSUP1NCONTROL_H
#define WZNMQCONSUP1NCONTROL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQConSup1NControl
	*/
class WznmQConSup1NControl {

public:
	WznmQConSup1NControl(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQConSup1NControl
	*/
class ListWznmQConSup1NControl {

public:
	ListWznmQConSup1NControl();
	ListWznmQConSup1NControl(const ListWznmQConSup1NControl& src);
	ListWznmQConSup1NControl& operator=(const ListWznmQConSup1NControl& src);
	~ListWznmQConSup1NControl();

	void clear();

public:
	std::vector<WznmQConSup1NControl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
