/**
	* \file WznmQQcoRef1NControl.h
	* API code for table TblWznmQQcoRef1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQQCOREF1NCONTROL_H
#define WZNMQQCOREF1NCONTROL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQcoRef1NControl
	*/
class WznmQQcoRef1NControl {

public:
	WznmQQcoRef1NControl(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQcoRef1NControl
	*/
class ListWznmQQcoRef1NControl {

public:
	ListWznmQQcoRef1NControl();
	ListWznmQQcoRef1NControl(const ListWznmQQcoRef1NControl& src);
	ListWznmQQcoRef1NControl& operator=(const ListWznmQQcoRef1NControl& src);
	~ListWznmQQcoRef1NControl();

	void clear();

public:
	std::vector<WznmQQcoRef1NControl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

