/**
	* \file WznmQTcoRef1NControl.h
	* API code for table TblWznmQTcoRef1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTCOREF1NCONTROL_H
#define WZNMQTCOREF1NCONTROL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTcoRef1NControl
	*/
class WznmQTcoRef1NControl {

public:
	WznmQTcoRef1NControl(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTcoRef1NControl
	*/
class ListWznmQTcoRef1NControl {

public:
	ListWznmQTcoRef1NControl();
	ListWznmQTcoRef1NControl(const ListWznmQTcoRef1NControl& src);
	ListWznmQTcoRef1NControl& operator=(const ListWznmQTcoRef1NControl& src);
	~ListWznmQTcoRef1NControl();

	void clear();

public:
	std::vector<WznmQTcoRef1NControl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
