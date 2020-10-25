/**
	* \file WznmQVerVer1NApp.h
	* API code for table TblWznmQVerVer1NApp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

