/**
	* \file WznmQVerVer1NModule.h
	* API code for table TblWznmQVerVer1NModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

