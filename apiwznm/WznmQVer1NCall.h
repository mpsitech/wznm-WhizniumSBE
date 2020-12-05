/**
	* \file WznmQVer1NCall.h
	* API code for table TblWznmQVer1NCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NCALL_H
#define WZNMQVER1NCALL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NCall
	*/
class WznmQVer1NCall {

public:
	WznmQVer1NCall(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NCall
	*/
class ListWznmQVer1NCall {

public:
	ListWznmQVer1NCall();
	ListWznmQVer1NCall(const ListWznmQVer1NCall& src);
	ListWznmQVer1NCall& operator=(const ListWznmQVer1NCall& src);
	~ListWznmQVer1NCall();

	void clear();

public:
	std::vector<WznmQVer1NCall*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

