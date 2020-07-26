/**
	* \file WznmQConSup1NControl.h
	* API code for table TblWznmQConSup1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

