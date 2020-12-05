/**
	* \file WznmQUsr1NSession.h
	* API code for table TblWznmQUsr1NSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSR1NSESSION_H
#define WZNMQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQUsr1NSession
	*/
class WznmQUsr1NSession {

public:
	WznmQUsr1NSession(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQUsr1NSession
	*/
class ListWznmQUsr1NSession {

public:
	ListWznmQUsr1NSession();
	ListWznmQUsr1NSession(const ListWznmQUsr1NSession& src);
	ListWznmQUsr1NSession& operator=(const ListWznmQUsr1NSession& src);
	~ListWznmQUsr1NSession();

	void clear();

public:
	std::vector<WznmQUsr1NSession*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

