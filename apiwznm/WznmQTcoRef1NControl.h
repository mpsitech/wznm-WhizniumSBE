/**
	* \file WznmQTcoRef1NControl.h
	* API code for table TblWznmQTcoRef1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

