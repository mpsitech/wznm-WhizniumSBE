/**
	* \file WznmQApp1NEvent.h
	* API code for table TblWznmQApp1NEvent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQAPP1NEVENT_H
#define WZNMQAPP1NEVENT_H

#include <sbecore/Xmlio.h>

/**
	* WznmQApp1NEvent
	*/
class WznmQApp1NEvent {

public:
	WznmQApp1NEvent(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQApp1NEvent
	*/
class ListWznmQApp1NEvent {

public:
	ListWznmQApp1NEvent();
	ListWznmQApp1NEvent(const ListWznmQApp1NEvent& src);
	ListWznmQApp1NEvent& operator=(const ListWznmQApp1NEvent& src);
	~ListWznmQApp1NEvent();

	void clear();

public:
	std::vector<WznmQApp1NEvent*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
