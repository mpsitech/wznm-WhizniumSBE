/**
	* \file WznmQPnlHk1NControl.h
	* API code for table TblWznmQPnlHk1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPNLHK1NCONTROL_H
#define WZNMQPNLHK1NCONTROL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPnlHk1NControl
	*/
class WznmQPnlHk1NControl {

public:
	WznmQPnlHk1NControl(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPnlHk1NControl
	*/
class ListWznmQPnlHk1NControl {

public:
	ListWznmQPnlHk1NControl();
	ListWznmQPnlHk1NControl(const ListWznmQPnlHk1NControl& src);
	ListWznmQPnlHk1NControl& operator=(const ListWznmQPnlHk1NControl& src);
	~ListWznmQPnlHk1NControl();

	void clear();

public:
	std::vector<WznmQPnlHk1NControl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

