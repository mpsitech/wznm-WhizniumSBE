/**
	* \file WznmQVerVer1NError.h
	* API code for table TblWznmQVerVer1NError (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERVER1NERROR_H
#define WZNMQVERVER1NERROR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVerVer1NError
	*/
class WznmQVerVer1NError {

public:
	WznmQVerVer1NError(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVerVer1NError
	*/
class ListWznmQVerVer1NError {

public:
	ListWznmQVerVer1NError();
	ListWznmQVerVer1NError(const ListWznmQVerVer1NError& src);
	ListWznmQVerVer1NError& operator=(const ListWznmQVerVer1NError& src);
	~ListWznmQVerVer1NError();

	void clear();

public:
	std::vector<WznmQVerVer1NError*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

