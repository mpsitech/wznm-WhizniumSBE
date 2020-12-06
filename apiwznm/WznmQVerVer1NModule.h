/**
	* \file WznmQVerVer1NModule.h
	* API code for table TblWznmQVerVer1NModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERVER1NMODULE_H
#define WZNMQVERVER1NMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVerVer1NModule
	*/
class WznmQVerVer1NModule {

public:
	WznmQVerVer1NModule(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVerVer1NModule
	*/
class ListWznmQVerVer1NModule {

public:
	ListWznmQVerVer1NModule();
	ListWznmQVerVer1NModule(const ListWznmQVerVer1NModule& src);
	ListWznmQVerVer1NModule& operator=(const ListWznmQVerVer1NModule& src);
	~ListWznmQVerVer1NModule();

	void clear();

public:
	std::vector<WznmQVerVer1NModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
