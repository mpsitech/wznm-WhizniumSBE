/**
	* \file WznmQCarHk1NControl.h
	* API code for table TblWznmQCarHk1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQCARHK1NCONTROL_H
#define WZNMQCARHK1NCONTROL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCarHk1NControl
	*/
class WznmQCarHk1NControl {

public:
	WznmQCarHk1NControl(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCarHk1NControl
	*/
class ListWznmQCarHk1NControl {

public:
	ListWznmQCarHk1NControl();
	ListWznmQCarHk1NControl(const ListWznmQCarHk1NControl& src);
	ListWznmQCarHk1NControl& operator=(const ListWznmQCarHk1NControl& src);
	~ListWznmQCarHk1NControl();

	void clear();

public:
	std::vector<WznmQCarHk1NControl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

