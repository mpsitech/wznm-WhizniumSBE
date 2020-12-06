/**
	* \file WznmQVerVer1NApp.h
	* API code for table TblWznmQVerVer1NApp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERVER1NAPP_H
#define WZNMQVERVER1NAPP_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVerVer1NApp
	*/
class WznmQVerVer1NApp {

public:
	WznmQVerVer1NApp(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVerVer1NApp
	*/
class ListWznmQVerVer1NApp {

public:
	ListWznmQVerVer1NApp();
	ListWznmQVerVer1NApp(const ListWznmQVerVer1NApp& src);
	ListWznmQVerVer1NApp& operator=(const ListWznmQVerVer1NApp& src);
	~ListWznmQVerVer1NApp();

	void clear();

public:
	std::vector<WznmQVerVer1NApp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
