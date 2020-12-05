/**
	* \file WznmQCarHk1NControl.h
	* API code for table TblWznmQCarHk1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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

